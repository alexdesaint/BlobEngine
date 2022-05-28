#include <Blob/Collision/Forms.hpp>
#include <Blob/Color.hpp>
#include <Blob/Controls.hpp>
#include <Blob/Window.hpp>
#include <cstddef>
#include <list>
#include <nanovg.h>
#include <vector>

#define STB_TRUETYPE_IMPLEMENTATION 1
#include <stb/stb_truetype.h>

using namespace Blob;

class PointShape {
public:
    float rayon = 2;
    Point position;
    Color color;

    PointShape(const Point &position, Color color = X11::White) :
        position(position), color(color) {}

    void draw(NVGcontext *nvgContext) const {
        nvgFillColor(nvgContext, nvgRGBAf(color.R, color.G, color.B, 255));
        nvgBeginPath(nvgContext);
        nvgCircle(nvgContext, position.x, position.y, rayon);
        nvgFill(nvgContext);
    }
};

class RectangleShape {
public:
    Box box;
    Color color;

    RectangleShape(const Box &box, Color color = X11::White) : box(box), color(color) {}

    void draw(NVGcontext *nvgContext) const {
        nvgFillColor(nvgContext, nvgRGBAf(color.R, color.G, color.B, 255));
        nvgBeginPath(nvgContext);
        nvgRect(nvgContext, box.p1.x, box.p1.y, box.p2.x - box.p1.x, box.p2.y - box.p1.y);
        nvgFill(nvgContext);
    }
};

class LineShape {
public:
    Segment segment;
    Color color;

    LineShape(const Segment &segment, Color color = X11::White) : segment(segment), color(color) {}

    void draw(NVGcontext *nvgContext) const {
        nvgStrokeWidth(nvgContext, 2.f);
        nvgStrokeColor(nvgContext, nvgRGBAf(color.R, color.G, color.B, 255));
        nvgBeginPath(nvgContext);
        nvgMoveTo(nvgContext, segment.p1.x, segment.p1.y);
        nvgLineTo(nvgContext, segment.p2.x, segment.p2.y);
        nvgStroke(nvgContext);
    }
};

class PointCursor : public PointShape {
public:
    explicit PointCursor(const Point &position = {}) : PointShape(position) {}

    void setPosition(const Point &p) { position = p; }

    void hitStart() { color = X11::Red; }
    void hitEnd() { color = X11::Green; }
};

class RectangleCursor : public RectangleShape {
public:
    RectangleCursor(const Box &box = {}, Color fillColor = X11::White) :
        RectangleShape(box, fillColor) {}

    void setPosition(const Box &p) { box = p; }

    void hitStart() { color = X11::Red; }
    void hitEnd() { color = X11::Green; }
};

class LineCursor : public LineShape {
public:
    LineCursor(const Segment &seg = {}) : LineShape(seg) {}

    void setPosition(const Segment &seg) { segment = seg; }

    void hitStart() { color = X11::Red; }
    void hitEnd() { color = X11::Green; }
};

class Cursor : public MouseEvents {
private:
    void mouseButtonUpdate(int button, bool pressed) final {
        if (pressed)
            return;
        state++;
        if (state > 2)
            state = 0;
    }

    void cursorPosUpdate(double xpos, double ypos) final {
        rectangleCursor.setPosition(Box(Point(xpos, ypos), 20, 20));
        pointCursor.setPosition(Point(xpos, ypos));
        lineCursor.setPosition(Segment(Point(xpos + (20 * std::cos(mouseOrientation / 20.f)),
                                             ypos + (20 * std::sin(mouseOrientation / 20.f))),
                                       Point(xpos - (20 * std::cos(mouseOrientation / 20.f)),
                                             ypos - (20 * std::sin(mouseOrientation / 20.f)))));
    }

    void scrollUpdate(double xoffset, double yoffset) final { mouseOrientation += yoffset; }

public:
    uint32_t state = 0;
    float mouseOrientation = 0;

    RectangleCursor &rectangleCursor;
    PointCursor &pointCursor;
    LineCursor &lineCursor;

    Cursor(RectangleCursor &rectangleCursor, PointCursor &pointCursor, LineCursor &lineCursor) :
        rectangleCursor(rectangleCursor), pointCursor(pointCursor), lineCursor(lineCursor) {}

    void update(NVGcontext *nvgContext) {
        switch (state) {
        case 0:
            rectangleCursor.draw(nvgContext);
            break;
        case 1:
            pointCursor.draw(nvgContext);
            break;
        case 2:
            lineCursor.draw(nvgContext);
            break;
        }
    }
};

int main(int argc, char *args[]) {
    Window window;
    Blob::Camera camera;

    NVGcontext *nvgContext = nvgCreate(1, 0);
    bgfx::setViewMode(0, bgfx::ViewMode::Sequential);

    std::list<RectangleShape> rectangles;
    std::list<PointShape> points;
    std::list<LineShape> lines;
    RectangleCursor rectangleCursor;
    PointCursor pointCursor;
    LineCursor lineCursor;

    Cursor cursor{rectangleCursor, pointCursor, lineCursor};

    rectangles.emplace_back(Box{Point{100, 300}, 20, 200});
    rectangles.emplace_back(Box{Point{300, 300}, 40, 40});
    rectangles.emplace_back(Box{Point{500, 300}, 100, 60});
    rectangles.emplace_back(Box{Point{700, 300}, 60, 100});
    points.emplace_back(Point{100, 500});
    points.emplace_back(Point{300, 500});
    points.emplace_back(Point{500, 500});
    points.emplace_back(Point{700, 500});
    lines.emplace_back(Segment{Point{100, 690}, Point{100, 710}});
    lines.emplace_back(Segment{Point{280, 700}, Point{320, 700}});
    lines.emplace_back(Segment{Point{470, 670}, Point{530, 730}});
    lines.emplace_back(Segment{Point{720, 680}, Point{680, 720}});

    while (window.isOpen) {
        nvgBeginFrame(nvgContext, window.windowSize.x, window.windowSize.y, 1.0f);

        bool hit = false;

        for (const auto &shape : rectangles)
            shape.draw(nvgContext);
        for (const auto &shape : points)
            shape.draw(nvgContext);
        for (const auto &shape : lines)
            shape.draw(nvgContext);

        switch (cursor.state) {
        case 0:
            for (const auto &shape : rectangles)
                if (overlap(shape.box, rectangleCursor.box))
                    hit = true;
            for (const auto &shape : points)
                if (overlap(shape.position, rectangleCursor.box))
                    hit = true;
            for (const auto &shape : lines)
                if (overlap(shape.segment, rectangleCursor.box))
                    hit = true;
            if (hit)
                rectangleCursor.hitStart();
            else
                rectangleCursor.hitEnd();
            rectangleCursor.draw(nvgContext);
            break;
        case 1:
            for (const auto &shape : rectangles)
                if (overlap(shape.box, pointCursor.position))
                    hit = true;
            for (const auto &shape : points)
                if (overlap(shape.position, pointCursor.position))
                    hit = true;
            for (const auto &shape : lines)
                if (overlap(shape.segment, pointCursor.position))
                    hit = true;
            if (hit)
                pointCursor.hitStart();
            else
                pointCursor.hitEnd();
            pointCursor.draw(nvgContext);
            break;
        case 2:
            for (const auto &shape : rectangles)
                if (overlap(shape.box, lineCursor.segment))
                    hit = true;
            for (const auto &shape : points)
                if (overlap(shape.position, lineCursor.segment))
                    hit = true;
            for (const auto &shape : lines)
                if (overlap(shape.segment, lineCursor.segment))
                    hit = true;
            if (hit)
                lineCursor.hitStart();
            else
                lineCursor.hitEnd();
            lineCursor.draw(nvgContext);
            break;
        }

        nvgEndFrame(nvgContext);
        window.display(camera);
    }

    nvgDelete(nvgContext);

    return 0;
}
#include <Blob/Collision/CollisionDetector.hpp>
#include <Blob/Color.hpp>
#include <Blob/Controls.hpp>
#include <Blob/Window.hpp>
#include <cstddef>
#include <list>
#include <nanovg.h>
#include <vector>

#define STB_TRUETYPE_IMPLEMENTATION 1
#include <stb/stb_truetype.h>

HAS_FUNCTION(draw, void(NVGcontext *nvgContext))

using namespace Blob;

class PointShape : public Collider<Point> {
public:
    float rayon = 2;
    Point position;
    Color color;

    PointShape(const Point &position, Color color = X11::White) :
        position(position), color(color) {}

    void draw(NVGcontext *nvgContext) const {
        if (!enabled)
            return;
        nvgFillColor(nvgContext, nvgRGBAf(color.R, color.G, color.B, 255));
        nvgBeginPath(nvgContext);
        nvgCircle(nvgContext, position.x, position.y, rayon);
        nvgFill(nvgContext);
    }

    void enableStatic() { enableStaticCollision(Point{position}); }
};

class RectangleShape : public Collider<Box> {
public:
    Box box;
    Color color;

    RectangleShape(const Box &box, Color color = X11::White) : box(box), color(color) {}

    void draw(NVGcontext *nvgContext) const {
        if (!enabled)
            return;
        nvgFillColor(nvgContext, nvgRGBAf(color.R, color.G, color.B, 255));
        nvgBeginPath(nvgContext);
        nvgRect(nvgContext, box.p1.x, box.p1.y, box.p2.x - box.p1.x, box.p2.y - box.p1.y);
        nvgFill(nvgContext);
    }

    void enableStatic() { enableStaticCollision(Box{box}); }
};

class LineShape : public Collider<Segment> {
public:
    Segment segment;
    Color color;

    LineShape(const Segment &segment, Color color = X11::White) : segment(segment), color(color) {}

    void draw(NVGcontext *nvgContext) const {
        if (!enabled)
            return;
        nvgStrokeWidth(nvgContext, 2.f);
        nvgStrokeColor(nvgContext, nvgRGBAf(color.R, color.G, color.B, 255));
        nvgBeginPath(nvgContext);
        nvgMoveTo(nvgContext, segment.p1.x, segment.p1.y);
        nvgLineTo(nvgContext, segment.p2.x, segment.p2.y);
        nvgStroke(nvgContext);
    }

    void enableStatic() { enableStaticCollision(Segment{segment}); }
};

class PolygonShape {
public:
    std::vector<Point> points;
    Color color;

    PolygonShape(const std::vector<Point> &points, Color color = X11::White) :
        points(points), color(color) {}

    void draw(NVGcontext *nvgContext) const {}
};

class PointCursor : public PointShape {
public:
    explicit PointCursor(const Point &position = {}) : PointShape(position) {}

    Point preCollisionUpdate(Point currentForm, double timeFlow) final {
        currentForm = position;
        return currentForm;
    }

    void setPosition(const Point &p) { position = p; }

    void hitStart(RectangleShape *object) { color = X11::Blue; }
    void hitStart(PointShape *object) { color = X11::Yellow; }
    void hitStart(LineShape *object) { color = X11::Orange; }

    template<class Collider>
    void hitEnd(Collider *object) {
        color = X11::Green;
    }
};

class RectangleCursor : public RectangleShape {
public:
    RectangleCursor(const Box &box = {}, Color fillColor = X11::White) :
        RectangleShape(box, fillColor) {}

    Box preCollisionUpdate(Box currentForm, double timeFlow) final {
        currentForm = box;
        return currentForm;
    }

    void setPosition(const Box &p) { box = p; }

    void hitStart(RectangleShape *object) { color = X11::Blue; }
    void hitStart(PointShape *object) { color = X11::Yellow; }
    void hitStart(LineShape *object) { color = X11::Orange; }

    template<class Collider>
    void hitEnd(Collider *object) {
        color = X11::Green;
    }
};

class LineCursor : public LineShape {
public:
    LineCursor(const Segment &seg = {}) : LineShape(seg) {}

    Segment preCollisionUpdate(Segment currentForm, double timeFlow) final {
        currentForm = segment;
        return currentForm;
    }

    void setPosition(const Segment &seg) { segment = seg; }

    void hitStart(RectangleShape *object) { color = X11::Blue; }
    void hitStart(PointShape *object) { color = X11::Yellow; }
    void hitStart(LineShape *object) { color = X11::Orange; }

    template<class Collider>
    void hitEnd(Collider *object) {
        color = X11::Green;
    }
};

// class PolygonObject : public Collider<Polygon>, public PolygonShape {
// public:
//   PolygonObject(const std::vector<Point> &points, Color fillColor =
//   X11::White)
//       : Collider(Polygon(points)), PolygonShape(points, fillColor) {}
// };

class Cursor : public Blob::MouseEvents {
private:
    void mouseButtonUpdate(int button, bool pressed) final {
        if (pressed)
            return;
        state++;
        if (state > 2)
            state = 0;
        switch (state) {
        case 0:
            lineCursor.disableDynamicCollision();
            rectangleCursor.enableDynamicCollision(Box(rectangleCursor.box));
            break;
        case 1:
            rectangleCursor.disableDynamicCollision();
            pointCursor.enableDynamicCollision(Point(pointCursor.position));
            break;
        case 2:
            pointCursor.disableDynamicCollision();
            lineCursor.enableDynamicCollision(Segment(lineCursor.segment));
            break;
        }
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
        rectangleCursor(rectangleCursor), pointCursor(pointCursor), lineCursor(lineCursor) {
        rectangleCursor.enableDynamicCollision(Box(rectangleCursor.box));
    }
};

int main(int argc, char *args[]) {
    Blob::Window window;
    Blob::Camera camera;

    NVGcontext *nvgContext = nvgCreate(1, 0);
    bgfx::setViewMode(0, bgfx::ViewMode::Sequential);

    CollisionDetector<PointShape,
                      PointCursor,
                      LineShape,
                      LineCursor,
                      RectangleShape,
                      RectangleCursor>
        collisionDetector;

    RectangleCursor &rectangleCursor = collisionDetector.emplace<RectangleCursor>();
    PointCursor &pointCursor = collisionDetector.emplace<PointCursor>();
    LineCursor &lineCursor = collisionDetector.emplace<LineCursor>();

    Cursor cursor{rectangleCursor, pointCursor, lineCursor};

    collisionDetector.emplace<RectangleShape>(Box{Point{100, 300}, 20, 200}).enableStatic();
    collisionDetector.emplace<RectangleShape>(Box{Point{300, 300}, 40, 40}).enableStatic();
    collisionDetector.emplace<RectangleShape>(Box{Point{500, 300}, 100, 60}).enableStatic();
    collisionDetector.emplace<RectangleShape>(Box{Point{700, 300}, 60, 100}).enableStatic();
    collisionDetector.emplace<PointShape>(Point{100, 500}).enableStatic();
    collisionDetector.emplace<PointShape>(Point{300, 500}).enableStatic();
    collisionDetector.emplace<PointShape>(Point{500, 500}).enableStatic();
    collisionDetector.emplace<PointShape>(Point{700, 500}).enableStatic();
    collisionDetector.emplace<LineShape>(Segment{Point{100, 690}, Point{100, 710}}).enableStatic();
    collisionDetector.emplace<LineShape>(Segment{Point{280, 700}, Point{320, 700}}).enableStatic();
    collisionDetector.emplace<LineShape>(Segment{Point{470, 670}, Point{530, 730}}).enableStatic();
    collisionDetector.emplace<LineShape>(Segment{Point{720, 680}, Point{680, 720}}).enableStatic();

    // polygones.emplace_back(std::vector<Point>{{{860, 880}, {940, 880}, {930, 920}, {870, 920}}});

    // for (auto &c : polygones)
    //     collisionDetector.enableCollision(c);

    while (window.isOpen) {
        nvgBeginFrame(nvgContext, float(window.windowSize.x), float(window.windowSize.y), 1.0f);
        collisionDetector.template callAll<has::draw>(nvgContext);
        auto deltaTime = window.getTime();
        collisionDetector.update(deltaTime);
        nvgEndFrame(nvgContext);
        window.display(camera);
    }

    nvgDelete(nvgContext);

    return 0;
}

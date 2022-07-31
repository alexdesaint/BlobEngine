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

class PointShape : public Blob::Collider<Blob::Point> {
public:
    float rayon = 2;
    Blob::Point position;
    Blob::Color color;

    PointShape(const Blob::Point &position, Blob::Color color = Blob::X11::White) :
        position(position), color(color) {}

    void draw(NVGcontext *nvgContext) const {
        if (!enabled)
            return;
        nvgFillColor(nvgContext, nvgRGBAf(color.R, color.G, color.B, 255));
        nvgBeginPath(nvgContext);
        nvgCircle(nvgContext, position.x, position.y, rayon);
        nvgFill(nvgContext);
    }

    void enableStatic() { enableStaticCollision(Blob::Point{position}); }
};

class RectangleShape : public Blob::Collider<Blob::Box> {
public:
    Blob::Box box;
    Blob::Color color;

    RectangleShape(const Blob::Box &box, Blob::Color color = Blob::X11::White) :
        box(box), color(color) {}

    void draw(NVGcontext *nvgContext) const {
        if (!enabled)
            return;
        nvgFillColor(nvgContext, nvgRGBAf(color.R, color.G, color.B, 255));
        nvgBeginPath(nvgContext);
        nvgRect(nvgContext, box.p1.x, box.p1.y, box.p2.x - box.p1.x, box.p2.y - box.p1.y);
        nvgFill(nvgContext);
    }

    void enableStatic() { enableStaticCollision(Blob::Box{box}); }
};

class LineShape : public Blob::Collider<Blob::Segment> {
public:
    Blob::Segment segment;
    Blob::Color color;

    LineShape(const Blob::Segment &segment, Blob::Color color = Blob::X11::White) :
        segment(segment), color(color) {}

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

    void enableStatic() { enableStaticCollision(Blob::Segment{segment}); }
};

class PolygonShape {
public:
    std::vector<Blob::Point> points;
    Blob::Color color;

    PolygonShape(const std::vector<Blob::Point> &points, Blob::Color color = Blob::X11::White) :
        points(points), color(color) {}

    void draw(NVGcontext *nvgContext) const {}
};

class PointCursor : public PointShape {
public:
    explicit PointCursor(const Blob::Point &position = {}) : PointShape(position) {}

    Blob::Point preCollisionUpdate(Blob::Point currentForm, double timeFlow) final {
        currentForm = position;
        return currentForm;
    }

    void setPosition(const Blob::Point &p) { position = p; }

    void hitStart(RectangleShape *object) { color = Blob::X11::Blue; }
    void hitStart(PointShape *object) { color = Blob::X11::Yellow; }
    void hitStart(LineShape *object) { color = Blob::X11::Orange; }

    template<class Collider>
    void hitEnd(Collider *object) {
        color = Blob::X11::Green;
    }
};

class RectangleCursor : public RectangleShape {
public:
    RectangleCursor(const Blob::Box &box = {}, Blob::Color fillColor = Blob::X11::White) :
        RectangleShape(box, fillColor) {}

    Blob::Box preCollisionUpdate(Blob::Box currentForm, double timeFlow) final {
        currentForm = box;
        return currentForm;
    }

    void setPosition(const Blob::Box &p) { box = p; }

    void hitStart(RectangleShape *object) { color = Blob::X11::Blue; }
    void hitStart(PointShape *object) { color = Blob::X11::Yellow; }
    void hitStart(LineShape *object) { color = Blob::X11::Orange; }

    template<class Collider>
    void hitEnd(Collider *object) {
        color = Blob::X11::Green;
    }
};

class LineCursor : public LineShape {
public:
    LineCursor(const Blob::Segment &seg = {}) : LineShape(seg) {}

    Blob::Segment preCollisionUpdate(Blob::Segment currentForm, double timeFlow) final {
        currentForm = segment;
        return currentForm;
    }

    void setPosition(const Blob::Segment &seg) { segment = seg; }

    void hitStart(RectangleShape *object) { color = Blob::X11::Blue; }
    void hitStart(PointShape *object) { color = Blob::X11::Yellow; }
    void hitStart(LineShape *object) { color = Blob::X11::Orange; }

    template<class Collider>
    void hitEnd(Collider *object) {
        color = Blob::X11::Green;
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
            rectangleCursor.enableDynamicCollision(Blob::Box(rectangleCursor.box));
            break;
        case 1:
            rectangleCursor.disableDynamicCollision();
            pointCursor.enableDynamicCollision(Blob::Point(pointCursor.position));
            break;
        case 2:
            pointCursor.disableDynamicCollision();
            lineCursor.enableDynamicCollision(Blob::Segment(lineCursor.segment));
            break;
        }
    }

    void cursorPosUpdate(const Blob::Vec2<> &screenPosition,
                         const Blob::Vec2<> &cameraPosition) final {
        rectangleCursor.setPosition(Blob::Box(Blob::Point(screenPosition), 20, 20));
        pointCursor.setPosition(Blob::Point(screenPosition));
        lineCursor.setPosition(Blob::Segment(
            Blob::Point(screenPosition.x + (20 * std::cos(mouseOrientation / 20.f)),
                        screenPosition.y + (20 * std::sin(mouseOrientation / 20.f))),
            Blob::Point(screenPosition.x - (20 * std::cos(mouseOrientation / 20.f)),
                        screenPosition.y - (20 * std::sin(mouseOrientation / 20.f)))));
    }

    void scrollUpdate(double xoffset, double yoffset) final { mouseOrientation += yoffset; }

public:
    uint32_t state = 0;
    float mouseOrientation = 0;

    RectangleCursor &rectangleCursor;
    PointCursor &pointCursor;
    LineCursor &lineCursor;

    Cursor(Blob::Context &context,
           RectangleCursor &rectangleCursor,
           PointCursor &pointCursor,
           LineCursor &lineCursor) :
        Blob::MouseEvents(context),
        rectangleCursor(rectangleCursor),
        pointCursor(pointCursor),
        lineCursor(lineCursor) {
        rectangleCursor.enableDynamicCollision(Blob::Box(rectangleCursor.box));
    }
};

int main(int argc, char *args[]) {
    Blob::Window window;
    Blob::Camera camera{window.context};

    NVGcontext *nvgContext = nvgCreate(1, 0);
    bgfx::setViewMode(0, bgfx::ViewMode::Sequential);

    Blob::CollisionDetector<PointShape,
                            PointCursor,
                            LineShape,
                            LineCursor,
                            RectangleShape,
                            RectangleCursor>
        collisionDetector;

    RectangleCursor &rectangleCursor = collisionDetector.emplace<RectangleCursor>();
    PointCursor &pointCursor = collisionDetector.emplace<PointCursor>();
    LineCursor &lineCursor = collisionDetector.emplace<LineCursor>();

    Cursor cursor{window.context, rectangleCursor, pointCursor, lineCursor};

    collisionDetector.emplace<RectangleShape>(Blob::Box{Blob::Point{100, 300}, 20, 200})
        .enableStatic();
    collisionDetector.emplace<RectangleShape>(Blob::Box{Blob::Point{300, 300}, 40, 40})
        .enableStatic();
    collisionDetector.emplace<RectangleShape>(Blob::Box{Blob::Point{500, 300}, 100, 60})
        .enableStatic();
    collisionDetector.emplace<RectangleShape>(Blob::Box{Blob::Point{700, 300}, 60, 100})
        .enableStatic();
    collisionDetector.emplace<PointShape>(Blob::Point{100, 500}).enableStatic();
    collisionDetector.emplace<PointShape>(Blob::Point{300, 500}).enableStatic();
    collisionDetector.emplace<PointShape>(Blob::Point{500, 500}).enableStatic();
    collisionDetector.emplace<PointShape>(Blob::Point{700, 500}).enableStatic();
    collisionDetector
        .emplace<LineShape>(Blob::Segment{Blob::Point{100, 690}, Blob::Point{100, 710}})
        .enableStatic();
    collisionDetector
        .emplace<LineShape>(Blob::Segment{Blob::Point{280, 700}, Blob::Point{320, 700}})
        .enableStatic();
    collisionDetector
        .emplace<LineShape>(Blob::Segment{Blob::Point{470, 670}, Blob::Point{530, 730}})
        .enableStatic();
    collisionDetector
        .emplace<LineShape>(Blob::Segment{Blob::Point{720, 680}, Blob::Point{680, 720}})
        .enableStatic();

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

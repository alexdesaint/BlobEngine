#include "Blob/Collision/Forms.hpp"
#include "polygon_triangulate/polygon_triangulate.hpp"

#include <SDL.h>
#include <SDL_render.h>
#include <SDL_stdinc.h>
#include <cstddef>
#include <list>

#include <Blob/Collision/CollisionDetector.hpp>
#include <Blob/Color.hpp>
#include <vector>

using namespace Blob;

using CollisionDetector = GeneralCollisionDetector<class CircleObject,
                                                   class CircleCursor,
                                                   class PointObject,
                                                   class PointCursor,
                                                   class LineObject,
                                                   class LineCursor,
                                                   class RectangleObject,
                                                   class RectangleCursor,
                                                   class PolygonObject>;

class CircleShape {
public:
    float rayon;
    Point position;
    Color::RGB color;

    CircleShape(float rayon,
                const Point &position,
                Color::RGB color = Color::White) :
        rayon(rayon), position(position), color(color) {}
};

class RectangleShape {
public:
    Point position, size;
    Color::RGB color;

    RectangleShape(const Point &size,
                   const Point &position,
                   Color::RGB color = Color::White) :
        position(position), size(size), color(color) {}
};

class LineShape {
public:
    Point position1, position2;
    Color::RGB color;

    LineShape(const Point &position1,
              const Point &position2,
              Color::RGB color = Color::White) :
        position1(position1), position2(position2), color(color) {}
};

class PolygonShape {
public:
    std::vector<Point> points;
    Color::RGB color;

    PolygonShape(const std::vector<Point> &points,
                 Color::RGB color = Color::White) :
        points(points), color(color) {}
};

class CircleObject : public StaticCollider<Circle>, public CircleShape {
public:
    CircleObject(const Point &position, float rayon) :
        StaticCollider(Circle(position, rayon)), CircleShape(rayon, position) {}
};

class CircleCursor : public DynamicCollider<Circle>, public CircleShape {
public:
    CircleCursor(const Point &position, float rayon) :
        DynamicCollider(Circle(position, rayon)),
        CircleShape(rayon, position) {}

    Circle preCollisionUpdate(Circle currentForm, double timeFlow) final {
        currentForm.position = position;
        return currentForm;
    }

    void setPosition(const Point &p) { position = p; }

    template<class Collider>
    void hitStart(Collider *object) {
        color = Color::Red;
    }

    void hitStart(CircleObject *object) { color = Color::Blue; }

    template<class Collider>
    void hitEnd(Collider *object) {
        color = Color::Green;
    }
};

class PointObject : public StaticCollider<Point>, public CircleShape {
public:
    explicit PointObject(const Point &position) :
        StaticCollider(Point(position)), CircleShape(2, position) {}
};

class PointCursor : public DynamicCollider<Point>, public CircleShape {
public:
    explicit PointCursor(const Point &position) :
        DynamicCollider(Point(position)), CircleShape(2, position) {}

    Point preCollisionUpdate(Point currentForm, double timeFlow) final {
        currentForm = position;
        return currentForm;
    }

    void setPosition(const Point &p) { position = p; }

    template<class Collider>
    void hitStart(Collider *object) {
        color = Color::Red;
    }

    template<class Collider>
    void hitEnd(Collider *object) {
        color = Color::Green;
    }
};

class RectangleObject :
    public StaticCollider<Rectangle>,
    public RectangleShape {
public:
    RectangleObject(const Point &position,
                    const Point &size,
                    Color::RGB fillColor = Color::White) :
        StaticCollider(Rectangle(position, size)),
        RectangleShape(size, position, fillColor) {}
};

class RectangleCursor :
    public DynamicCollider<Rectangle>,
    public RectangleShape {
public:
    RectangleCursor(const Point &position,
                    const Point &size,
                    Color::RGB fillColor = Color::White) :
        DynamicCollider(Rectangle(position, size)),
        RectangleShape(size, position, fillColor) {}

    Rectangle preCollisionUpdate(Rectangle currentForm, double timeFlow) final {
        currentForm.position = position;
        return currentForm;
    }

    void setPosition(const Point &p) { position = p; }

    template<class Collider>
    void hitStart(Collider *object) {
        color = Color::Red;
    }

    template<class Collider>
    void hitEnd(Collider *object) {
        color = Color::Green;
    }
};

class LineObject : public StaticCollider<Line>, public LineShape {
public:
    LineObject(Point position1, Point position2) :
        StaticCollider<Line>(Line(position1, position2)),
        LineShape(position1, position2) {}
};

class LineCursor : public DynamicCollider<Line>, public LineShape {
public:
    LineCursor(Point position1, Point position2) :
        DynamicCollider(Line(position1, position2)),
        LineShape(position1, position2) {}

    Line preCollisionUpdate(Line currentForm, double timeFlow) final {
        currentForm.positionA = position1;
        currentForm.positionB = position2;
        return currentForm;
    }

    void setPosition(const Point &position1, const Point &position2) {
        LineShape::position1 = position1;
        LineShape::position2 = position2;
    }

    template<class Collider>
    void hitStart(Collider *object) {
        color = Color::Red;
    }

    template<class Collider>
    void hitEnd(Collider *object) {
        color = Color::Green;
    }
};

class PolygonObject : public StaticCollider<Polygon>, public PolygonShape {
public:
    PolygonObject(const std::vector<Point> &points,
                  Color::RGB fillColor = Color::White) :
        StaticCollider(Polygon(points)), PolygonShape(points, fillColor) {}
};

class Window {
private:
    SDL_Window *window = nullptr;
    SDL_Surface *screenSurface = nullptr;
    SDL_Renderer *renderer = nullptr;
    int64_t NOW = SDL_GetPerformanceCounter();
    int64_t LAST = 0;

public:
    Window() {
        window = SDL_CreateWindow("hello_sdl2",
                                  SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED,
                                  1000,
                                  1000,
                                  SDL_WINDOW_SHOWN);
        if (window == nullptr) {
            fprintf(stderr, "could not create window: %s\n", SDL_GetError());
            return;
        }
        screenSurface = SDL_GetWindowSurface(window);
        if (screenSurface == nullptr) {
            fprintf(stderr,
                    "could not create screenSurface: %s\n",
                    SDL_GetError());
            return;
        }
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    }

    void draw(const RectangleShape &rectangleShape) {
        SDL_SetRenderDrawColor(renderer,
                               (Uint8) (rectangleShape.color.R * 255.f),
                               (Uint8) (rectangleShape.color.G * 255.f),
                               (Uint8) (rectangleShape.color.B * 255.f),
                               255);
        SDL_Rect rect{
            (int) (rectangleShape.position.x - rectangleShape.size.x / 2),
            (int) (rectangleShape.position.y - rectangleShape.size.y / 2),
            (int) rectangleShape.size.x,
            (int) rectangleShape.size.y};
        SDL_RenderFillRect(renderer, &rect);
    }

    void draw(const LineShape &lineShape) {
        SDL_SetRenderDrawColor(renderer,
                               (Uint8) (lineShape.color.R * 255.f),
                               (Uint8) (lineShape.color.G * 255.f),
                               (Uint8) (lineShape.color.B * 255.f),
                               255);
        SDL_RenderDrawLine(renderer,
                           (int) lineShape.position1.x,
                           (int) lineShape.position1.y,
                           (int) lineShape.position2.x,
                           (int) lineShape.position2.y);
    }

    void draw(const CircleShape &circleShape) {
        SDL_SetRenderDrawColor(renderer,
                               (Uint8) (circleShape.color.R * 255.f),
                               (Uint8) (circleShape.color.G * 255.f),
                               (Uint8) (circleShape.color.B * 255.f),
                               255);
        int offsetx, offsety, d;
        int status;

        offsetx = 0;
        offsety = (int) circleShape.rayon;
        d = (int) circleShape.rayon - 1;
        status = 0;

        while (offsety >= offsetx) {

            status +=
                SDL_RenderDrawLine(renderer,
                                   (int) circleShape.position.x - offsety,
                                   (int) circleShape.position.y + offsetx,
                                   (int) circleShape.position.x + offsety,
                                   (int) circleShape.position.y + offsetx);
            status +=
                SDL_RenderDrawLine(renderer,
                                   (int) circleShape.position.x - offsetx,
                                   (int) circleShape.position.y + offsety,
                                   (int) circleShape.position.x + offsetx,
                                   (int) circleShape.position.y + offsety);
            status +=
                SDL_RenderDrawLine(renderer,
                                   (int) circleShape.position.x - offsetx,
                                   (int) circleShape.position.y - offsety,
                                   (int) circleShape.position.x + offsetx,
                                   (int) circleShape.position.y - offsety);
            status +=
                SDL_RenderDrawLine(renderer,
                                   (int) circleShape.position.x - offsety,
                                   (int) circleShape.position.y - offsetx,
                                   (int) circleShape.position.x + offsety,
                                   (int) circleShape.position.y - offsetx);

            if (status < 0) {
                status = -1;
                break;
            }

            if (d >= 2 * offsetx) {
                d -= 2 * offsetx + 1;
                offsetx += 1;
            } else if (d < 2 * (circleShape.rayon - offsety)) {
                d += 2 * offsety - 1;
                offsety -= 1;
            } else {
                d += 2 * (offsety - offsetx - 1);
                offsety -= 1;
                offsetx += 1;
            }
        }
    }

    void draw(const PolygonShape &polygonShape) {
        auto size = polygonShape.points.size();

        if (size < 3)
            return;

        std::vector<double> x(size), y(size);
        SDL_Vertex vertex[size];

        for (size_t it = 0; it < size; it++) {
            vertex[it].position.x = x[it] = polygonShape.points[it].x;
            vertex[it].position.y = y[it] = polygonShape.points[it].y;
            vertex[it].color.r = (Uint8) (polygonShape.color.R * 255.f);
            vertex[it].color.g = (Uint8) (polygonShape.color.G * 255.f);
            vertex[it].color.b = (Uint8) (polygonShape.color.B * 255.f);
            vertex[it].color.a = 255;
        }

        int *triangles = polygon_triangulate(size, x.data(), y.data());

        SDL_RenderGeometry(renderer,
                           NULL,
                           vertex,
                           size,
                           triangles,
                           3 * (size - 2));
        delete[] triangles;
    }

    void setTitle(const char *title) { SDL_SetWindowTitle(window, title); }

    void display() { SDL_RenderPresent(renderer); }

    float getFrameTime() {
        LAST = NOW;
        NOW = SDL_GetPerformanceCounter();
        return (float) (NOW - LAST) / SDL_GetPerformanceFrequency();
    }

    void clear() {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
    }
};

int main(int argc, char *args[]) {
    unsigned int tick;
    Window window;
    std::list<CircleObject> circles;
    std::list<RectangleObject> rectangles;
    std::list<PointObject> points;
    std::list<LineObject> lines;
    std::list<PolygonObject> polygones;

    CollisionDetector collisionDetector;

    CircleCursor circleCursor(Point{0, 0}, 20);
    collisionDetector.enableCollision(circleCursor);
    RectangleCursor rectangleCursor({0, 0}, {40, 40});
    PointCursor pointCursor({0, 0});
    LineCursor lineCursor({-20, 0}, {20, 0});

    circles.emplace_back(Point{100, 100}, 10);
    circles.emplace_back(Point{300, 100}, 20);
    circles.emplace_back(Point{500, 100}, 30);
    circles.emplace_back(Point{700, 100}, 40);

    for (auto &c : circles)
        collisionDetector.enableCollision(c);

    rectangles.emplace_back(Point{100, 300}, Point{20, 200});
    rectangles.emplace_back(Point{300, 300}, Point{40, 40});
    rectangles.emplace_back(Point{500, 300}, Point{100, 60});
    rectangles.emplace_back(Point{700, 300}, Point{60, 100});

    for (auto &c : rectangles)
        collisionDetector.enableCollision(c);

    points.emplace_back(Point{100, 500});
    points.emplace_back(Point{300, 500});
    points.emplace_back(Point{500, 500});
    points.emplace_back(Point{700, 500});

    for (auto &c : points)
        collisionDetector.enableCollision(c);

    lines.emplace_back(Point{100, 690}, Point{100, 710});
    lines.emplace_back(Point{280, 700}, Point{320, 700});
    lines.emplace_back(Point{470, 670}, Point{530, 730});
    lines.emplace_back(Point{720, 680}, Point{680, 720});

    for (auto &c : lines)
        collisionDetector.enableCollision(c);

    polygones.emplace_back(
        std::vector<Point>{{{860, 880}, {940, 880}, {930, 920}, {870, 920}}});

    for (auto &c : polygones)
        collisionDetector.enableCollision(c);

    SDL_Event e;
    bool quit = false;
    SDL_ShowCursor(false);
    uint32_t state = 0;
    float mouseOrientation = 0;

    while (!quit) {

        for (const auto &c : circles)
            window.draw(c);
        for (const auto &r : rectangles)
            window.draw(r);
        for (const auto &c : points)
            window.draw(c);
        for (const auto &r : lines)
            window.draw(r);
        for (const auto &r : polygones)
            window.draw(r);

        Vec2<int> cursorPosition;
        SDL_GetMouseState(&cursorPosition.x, &cursorPosition.y);
        switch (state) {
        case 0:
            circleCursor.setPosition(cursorPosition.cast<float>());
            window.draw(circleCursor);
            break;
        case 1:
            rectangleCursor.setPosition(cursorPosition.cast<float>());
            window.draw(rectangleCursor);
            break;
        case 2:
            pointCursor.setPosition(cursorPosition.cast<float>());
            window.draw(pointCursor);
            break;
        case 3:
            lineCursor.setPosition(
                {(float) cursorPosition.x +
                     (20 * std::cos(mouseOrientation / 20.f)),
                 (float) cursorPosition.y +
                     (20 * std::sin(mouseOrientation / 20.f))},
                {(float) cursorPosition.x -
                     (20 * std::cos(mouseOrientation / 20.f)),
                 (float) cursorPosition.y -
                     (20 * std::sin(mouseOrientation / 20.f))});
            window.draw(lineCursor);
            break;
        }

        while (SDL_PollEvent(&e) != 0) {
            switch (e.type) {
            case SDL_QUIT:
                quit = true;
                break;
            case SDL_MOUSEBUTTONDOWN:
                state++;
                if (state > 3)
                    state = 0;
                switch (state) {
                case 0:
                    collisionDetector.disableCollision(lineCursor);
                    collisionDetector.enableCollision(circleCursor);
                    break;
                case 1:
                    collisionDetector.disableCollision(circleCursor);
                    collisionDetector.enableCollision(rectangleCursor);
                    break;
                case 2:
                    collisionDetector.disableCollision(rectangleCursor);
                    collisionDetector.enableCollision(pointCursor);
                    break;
                case 3:
                    collisionDetector.disableCollision(pointCursor);
                    collisionDetector.enableCollision(lineCursor);
                    break;
                }
                break;
            case SDL_MOUSEWHEEL:
                mouseOrientation += e.wheel.y;
                break;
            default:
                break;
            }
        }

        tick++;

        auto deltaTime = window.getFrameTime();
        if (tick >= 60) {
            char szFps[200];
            sprintf(szFps, "%s : %f FPS", "Test Collision", 1 / deltaTime);
            tick = 0;
            window.setTitle(szFps);
        }
        collisionDetector.update(deltaTime);
        window.display();
        window.clear();
    }

    return 0;
}
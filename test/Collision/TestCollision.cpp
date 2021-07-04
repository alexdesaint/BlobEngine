#include "SDL_stdinc.h"
#include <SDL.h>
#include <list>

#include <Blob/Collision/CollisionDetector.hpp>
#include <Blob/Color.hpp>

using namespace Blob;

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

    void setTitle(const char *title) { SDL_SetWindowTitle(window, title); }

    void display() { SDL_RenderPresent(renderer); }

    float getFrameTime() {
        LAST = NOW;
        NOW = SDL_GetPerformanceCounter();
        return ((NOW - LAST) * 1000.f / (float) SDL_GetPerformanceFrequency());
    }

    void clear() {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
    }
};

class CircleObject : public StaticCollider<Circle>, public CircleShape {
public:
    CircleObject(const Point &position, float rayon) :
        StaticCollider<Circle>(typeid(Circle), Circle(position, rayon)),
        CircleShape(rayon, position) {}
};

class CircleCursor : public DynamicCollider<Circle>, public CircleShape {
public:
    CircleCursor(const Point &position, float rayon) :
        DynamicCollider<Circle>(typeid(CircleCursor), Circle(position, rayon)),
        CircleShape(rayon, position) {}

    Circle preCollisionUpdate(Circle currentForm, float timeFlow) final {
        currentForm.position = position;
        return currentForm;
    }

    void setPosition(const Point &p) { position = p; }

    void hitStart(PhysicalObject *object) final { color = Color::Red; }

    void hitEnd(PhysicalObject *object) final { color = Color::Green; }
};

class PointObject : public StaticCollider<Point>, public CircleShape {
public:
    explicit PointObject(const Point &position) :
        StaticCollider<Point>(typeid(Point), Point(position)),
        CircleShape(2, position) {}
};

class PointCursor : public DynamicCollider<Point>, public CircleShape {
public:
    explicit PointCursor(const Point &position) :
        DynamicCollider<Point>(typeid(PointCursor), Point(position)),
        CircleShape(2, position) {}

    Point preCollisionUpdate(Point currentForm, float timeFlow) final {
        currentForm = position;
        return currentForm;
    }

    void setPosition(const Point &p) { position = p; }

    void hitStart(PhysicalObject *object) final { color = Color::Red; }

    void hitEnd(PhysicalObject *object) final { color = Color::Green; }
};

class RectangleObject :
    public StaticCollider<Rectangle>,
    public RectangleShape {
public:
    RectangleObject(const Point &position,
                    const Point &size,
                    Color::RGB fillColor = Color::White) :
        StaticCollider<Rectangle>(typeid(Rectangle), Rectangle(position, size)),
        RectangleShape(size, position, fillColor) {}
};

class RectangleCursor :
    public DynamicCollider<Rectangle>,
    public RectangleShape {
public:
    RectangleCursor(const Point &position,
                    const Point &size,
                    Color::RGB fillColor = Color::White) :
        DynamicCollider<Rectangle>(typeid(CircleCursor),
                                   Rectangle(position, size)),
        RectangleShape(size, position, fillColor) {}

    Rectangle preCollisionUpdate(Rectangle currentForm, float timeFlow) final {
        currentForm.position = position;
        return currentForm;
    }

    void setPosition(const Point &p) { position = p; }

    void hitStart(PhysicalObject *object) final { color = Color::Red; }

    void hitEnd(PhysicalObject *object) final { color = Color::Green; }
};

class LineObject : public StaticCollider<Line>, public LineShape {
public:
    LineObject(Point position1, Point position2) :
        StaticCollider<Line>(typeid(Line), Line(position1, position2)),
        LineShape(position1, position2) {}
};

class LineCursor : public DynamicCollider<Line>, public LineShape {
public:
    LineCursor(Point position1, Point position2) :
        DynamicCollider<Line>(typeid(LineCursor), Line(position1, position2)),
        LineShape(position1, position2) {}

    Line preCollisionUpdate(Line currentForm, float timeFlow) final {
        currentForm.positionA = position1;
        currentForm.positionB = position2;
        return currentForm;
    }

    void setPosition(const Point &position1, const Point &position2) {
        LineShape::position1 = position1;
        LineShape::position2 = position2;
    }

    void hitStart(PhysicalObject *object) final { color = Color::Red; }

    void hitEnd(PhysicalObject *object) final { color = Color::Green; }
};

class Game {
private:
    unsigned int tick;
    // std::list<sf::Sprite *> ModelList;
    Window window;
    // sf::View view;
    std::list<CircleObject> circles;
    std::list<RectangleObject> rectangles;
    std::list<PointObject> points;
    std::list<LineObject> lines;

public:
    Game() // :
    // view(sf::FloatRect(0.f, 0.f, 100.f, 100.f)),
    {

        CollisionDetector collisionDetector;

        CircleCursor circleCursor(Point{0, 0}, 20);
        collisionDetector.enableCollision(circleCursor);
        RectangleCursor rectangleCursor({0, 0}, {40, 40});
        PointCursor pointCursor({0, 0});
        LineCursor lineCursor({-20, 0}, {20, 0});

        circles.emplace_back(Point{200, 200}, 10);
        circles.emplace_back(Point{400, 200}, 20);
        circles.emplace_back(Point{600, 200}, 30);
        circles.emplace_back(Point{800, 200}, 40);

        for (auto &c : circles)
            collisionDetector.enableCollision(c);

        rectangles.emplace_back(Point{205, 405}, Point{20, 200});
        rectangles.emplace_back(Point{400, 400}, Point{40, 40});
        rectangles.emplace_back(Point{600, 400}, Point{100, 60});
        rectangles.emplace_back(Point{800, 400}, Point{60, 100});

        for (auto &c : rectangles)
            collisionDetector.enableCollision(c);

        points.emplace_back(Point{200, 600});
        points.emplace_back(Point{400, 600});
        points.emplace_back(Point{600, 600});
        points.emplace_back(Point{800, 600});

        for (auto &c : points)
            collisionDetector.enableCollision(c);

        lines.emplace_back(Point{200, 790}, Point{200, 810});
        lines.emplace_back(Point{380, 800}, Point{420, 800});
        lines.emplace_back(Point{570, 770}, Point{630, 830});
        lines.emplace_back(Point{820, 780}, Point{780, 820});

        for (auto &c : lines)
            collisionDetector.enableCollision(c);

        SDL_Event e;
        bool quit = false;
        // window.setMouseCursorVisible(false);
        SDL_ShowCursor(false);
        uint32_t state = 0;
        float mouseOrientation = 0;
        // sf::Clock clock;

        while (!quit) {
            for (const auto &c : circles)
                window.draw(c);
            for (const auto &r : rectangles)
                window.draw(r);
            for (const auto &c : points)
                window.draw(c);
            for (const auto &r : lines)
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
                sprintf(szFps, "%s : %f FPS", "Game Title", 1 / deltaTime);
                tick = 0;
                window.setTitle(szFps);
            }
            collisionDetector.update(deltaTime);
            window.display();
            window.clear();
        }
    }
};

int main(int argc, char *args[]) {
    Game game;

    return 0;
}
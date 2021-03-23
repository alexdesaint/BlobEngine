#include <SDL.h>
#include <list>

#include <Blob/Collision/CollisionDetector.hpp>
#include <Blob/Color.hpp>

using namespace Blob;

class CircleShape {
public:
    float rayon;
    Collision::Point position;
    Color::RGB color;

    CircleShape(float rayon, const Collision::Point &position, Color::RGB color = Color::White) : rayon(rayon), position(position), color(color) {}
};

class RectangleShape {
public:
    Collision::Point position, size;
    Color::RGB color;

    RectangleShape(const Collision::Point &size, const Collision::Point &position, Color::RGB color = Color::White) :
        position(position), size(size), color(color) {}
};

class LineShape {
public:
    Collision::Point position1, position2;
    Color::RGB color;

    LineShape(const Collision::Point &position1, const Collision::Point &position2, Color::RGB color = Color::White) :
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
        window = SDL_CreateWindow("hello_sdl2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1000, 1000, SDL_WINDOW_SHOWN);
        if (window == nullptr) {
            fprintf(stderr, "could not create window: %s\n", SDL_GetError());
            return;
        }
        screenSurface = SDL_GetWindowSurface(window);
        if (screenSurface == nullptr) {
            fprintf(stderr, "could not create screenSurface: %s\n", SDL_GetError());
            return;
        }
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    }

    void draw(const RectangleShape &rectangleShape) {
        SDL_SetRenderDrawColor(renderer, rectangleShape.color.R * 255, rectangleShape.color.G * 255, rectangleShape.color.B * 255, 255);
        SDL_Rect rect{(int) (rectangleShape.position.x - rectangleShape.size.x / 2), (int) (rectangleShape.position.y - rectangleShape.size.y / 2),
                      (int) rectangleShape.size.x, (int) rectangleShape.size.y};
        SDL_RenderFillRect(renderer, &rect);
    }

    void draw(const LineShape &lineShape) {
        SDL_SetRenderDrawColor(renderer, lineShape.color.R * 255, lineShape.color.G * 255, lineShape.color.B * 255, 255);
        SDL_RenderDrawLine(renderer, lineShape.position1.x, lineShape.position1.y, lineShape.position2.x, lineShape.position2.y);
    }

    void draw(const CircleShape &circleShape) {
        SDL_SetRenderDrawColor(renderer, circleShape.color.R * 255, circleShape.color.G * 255, circleShape.color.B * 255, 255);
        int offsetx, offsety, d;
        int status;

        offsetx = 0;
        offsety = circleShape.rayon;
        d = circleShape.rayon - 1;
        status = 0;

        while (offsety >= offsetx) {

            status += SDL_RenderDrawLine(renderer, circleShape.position.x - offsety, circleShape.position.y + offsetx,
                                         circleShape.position.x + offsety, circleShape.position.y + offsetx);
            status += SDL_RenderDrawLine(renderer, circleShape.position.x - offsetx, circleShape.position.y + offsety,
                                         circleShape.position.x + offsetx, circleShape.position.y + offsety);
            status += SDL_RenderDrawLine(renderer, circleShape.position.x - offsetx, circleShape.position.y - offsety,
                                         circleShape.position.x + offsetx, circleShape.position.y - offsety);
            status += SDL_RenderDrawLine(renderer, circleShape.position.x - offsety, circleShape.position.y - offsetx,
                                         circleShape.position.x + offsety, circleShape.position.y - offsetx);

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

class Circle : public Collision::Collider<Collision::Circle>, public CircleShape {
public:
    Collision::Circle circle;

    Circle(const Collision::Point &position, float rayon) :
        Collision::Collider<Collision::Circle>(typeid(Circle), circle), circle(position, rayon), CircleShape(rayon, position) {}

    void setPosition(const Collision::Point &p) {
        position = p;
        circle.position = p;
    }
};

class CircleCursor : public Collision::DynamicCollider<Collision::Circle>, public CircleShape {
public:
    Collision::Circle circle;

    CircleCursor(const Collision::Point &position, float rayon) :
        Collision::DynamicCollider<Collision::Circle>(typeid(CircleCursor), circle), circle(position, rayon), CircleShape(rayon, position) {}

    void setPosition(const Collision::Point &p) {
        position = p;
        circle.position = p;
    }

    void hitStart(PhysicalObject *object) final { color = Color::Red; }

    void hitEnd(PhysicalObject *object) final { color = Color::Green; }
};

class Point : public Collision::Collider<Collision::Point>, public CircleShape {
public:
    Collision::Point point;

    explicit Point(const Collision::Point &position) :
        Collision::Collider<Collision::Point>(typeid(Point), point), point(position), CircleShape(2, position) {}

    void setPosition(const Collision::Point &p) {
        position = p;
        point = p;
    }
};

class PointCursor : public Collision::DynamicCollider<Collision::Point>, public CircleShape {
public:
    Collision::Point point;

    explicit PointCursor(const Collision::Point &position) :
        Collision::DynamicCollider<Collision::Point>(typeid(PointCursor), point), point(position), CircleShape(2, position) {}

    void setPosition(const Collision::Point &p) {
        position = p;
        point = p;
    }

    void hitStart(PhysicalObject *object) final { color = Color::Red; }

    void hitEnd(PhysicalObject *object) final { color = Color::Green; }
};

class Rectangle : public Collision::Collider<Collision::Rectangle>, public RectangleShape {
public:
    Collision::Rectangle rectangle;

    Rectangle(const Collision::Point &position, const Collision::Point &size, Color::RGB fillColor = Color::White) :
        rectangle(position, size),
        Collision::Collider<Collision::Rectangle>(typeid(Rectangle), rectangle),
        RectangleShape(size, position, fillColor) {}

    void setPosition(const Collision::Point &p) {
        position = p;
        rectangle.position = p;
    }
};

class RectangleCursor : public Collision::DynamicCollider<Collision::Rectangle>, public RectangleShape {
public:
    Collision::Rectangle rectangle;

    RectangleCursor(const Collision::Point &position, const Collision::Point &size, Color::RGB fillColor = Color::White) :
        rectangle(position, size),
        Collision::DynamicCollider<Collision::Rectangle>(typeid(CircleCursor), rectangle),
        RectangleShape(size, position, fillColor) {}

    void setPosition(const Collision::Point &p) {
        position = p;
        rectangle.position = p;
    }

    void hitStart(PhysicalObject *object) final { color = Color::Red; }

    void hitEnd(PhysicalObject *object) final { color = Color::Green; }
};

class Line : public Collision::Collider<Collision::Line>, public LineShape {
public:
    Collision::Line line;

    Line(Collision::Point position1, Collision::Point position2) :
        line(position1, position2), Collision::Collider<Collision::Line>(typeid(Line), line), LineShape(position1, position2) {
    }

    void setPosition(const Collision::Point &position1, const Collision::Point &position2) {
        LineShape::position1 = position1;
        LineShape::position2 = position2;
        line.positionA = position1;
        line.positionB = position2;
    }
};

class LineCursor : public Collision::DynamicCollider<Collision::Line>, public LineShape {
public:
    Collision::Line line;

    LineCursor(Collision::Point position1, Collision::Point position2) :
        line(position1, position2), Collision::DynamicCollider<Collision::Line>(typeid(LineCursor), line), LineShape(position1, position2) {
        // auto vector = position1 - position2;
        // setOrigin(0.1, (position1 - position2).length() / 2);
        // sf::RectangleShape::setPosition(position.x, position.y);
        // sf::RectangleShape::setRotation(-std::atan2(vector.x, vector.y) * 180 / PI);
    }

    void setPosition(const Collision::Point &position1, const Collision::Point &position2) {
        // auto vector = position1 - position2;
        // auto position = (position1 + position2) / 2;
        // sf::RectangleShape::setPosition(position.x, position.y);
        // sf::RectangleShape::setRotation(-std::atan2(vector.x, vector.y) * 180 / PI);
        // sf::RectangleShape::setSize({0.2, (position1 - position2).length()});
        // setOrigin(0.1, (position1 - position2).length() / 2);
        LineShape::position1 = position1;
        LineShape::position2 = position2;
        line.positionA = position1;
        line.positionB = position2;
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
    std::list<Circle> circles;
    std::list<Rectangle> rectangles;
    std::list<Point> points;
    std::list<Line> lines;

public:
    Game() // :
    // view(sf::FloatRect(0.f, 0.f, 100.f, 100.f)),
    {

        Collision::CollisionDetector collisionDetector;

        CircleCursor circleCursor(Collision::Point{0, 0}, 20);
        collisionDetector.enableCollision(circleCursor);
        RectangleCursor rectangleCursor({0, 0}, {40, 40});
        PointCursor pointCursor({0, 0});
        LineCursor lineCursor({-20, 0}, {20, 0});

        circles.emplace_back(Collision::Point{200, 200}, 10);
        circles.emplace_back(Collision::Point{400, 200}, 20);
        circles.emplace_back(Collision::Point{600, 200}, 30);
        circles.emplace_back(Collision::Point{800, 200}, 40);

        for (auto &c : circles)
            collisionDetector.enableCollision(c);

        rectangles.emplace_back(Collision::Point{205, 405}, Collision::Point{20, 200});
        rectangles.emplace_back(Collision::Point{400, 400}, Collision::Point{40, 40});
        rectangles.emplace_back(Collision::Point{600, 400}, Collision::Point{100, 60});
        rectangles.emplace_back(Collision::Point{800, 400}, Collision::Point{60, 100});

        for (auto &c : rectangles)
            collisionDetector.enableCollision(c);

        points.emplace_back(Collision::Point{200, 600});
        points.emplace_back(Collision::Point{400, 600});
        points.emplace_back(Collision::Point{600, 600});
        points.emplace_back(Collision::Point{800, 600});

        for (auto &c : points)
            collisionDetector.enableCollision(c);

        lines.emplace_back(Collision::Point{200, 790}, Collision::Point{200, 810});
        lines.emplace_back(Collision::Point{380, 800}, Collision::Point{420, 800});
        lines.emplace_back(Collision::Point{570, 770}, Collision::Point{630, 830});
        lines.emplace_back(Collision::Point{820, 780}, Collision::Point{780, 820});

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

            Maths::Vec2<int> cursorPosition;
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
                lineCursor.setPosition({(float) cursorPosition.x + (20 * std::cos(mouseOrientation / 20.f)),
                                        (float) cursorPosition.y + (20 * std::sin(mouseOrientation / 20.f))},
                                       {(float) cursorPosition.x - (20 * std::cos(mouseOrientation / 20.f)),
                                        (float) cursorPosition.y - (20 * std::sin(mouseOrientation / 20.f))});
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
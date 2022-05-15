#include <iostream>
#include <list>

#include <Blob/Collision/Forms.hpp>
#include <Blob/Color.hpp>

using namespace Blob;

class CircleShape {
public:
    float rayon;
    Point position;
    Color color;

    CircleShape(float rayon, const Point &position, Color color = X11::White) :
        rayon(rayon), position(position), color(color) {}
};

class RectangleShape {
public:
    Point position, size;
    Color color;

    RectangleShape(const Point &size,
                   const Point &position,
                   Color color = X11::White) :
        position(position), size(size), color(color) {}
};

class LineShape {
public:
    Point position1, position2;
    Color color;

    LineShape(const Point &position1,
              const Point &position2,
              Color color = X11::White) :
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
                               rectangleShape.color.R * 255,
                               rectangleShape.color.G * 255,
                               rectangleShape.color.B * 255,
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
                               lineShape.color.R * 255,
                               lineShape.color.G * 255,
                               lineShape.color.B * 255,
                               255);
        SDL_RenderDrawLine(renderer,
                           lineShape.position1.x,
                           lineShape.position1.y,
                           lineShape.position2.x,
                           lineShape.position2.y);
    }

    void draw(const CircleShape &circleShape) {
        SDL_SetRenderDrawColor(renderer,
                               circleShape.color.R * 255,
                               circleShape.color.G * 255,
                               circleShape.color.B * 255,
                               255);
        int offsetx, offsety, d;
        int status;

        offsetx = 0;
        offsety = circleShape.rayon;
        d = circleShape.rayon - 1;
        status = 0;

        while (offsety >= offsetx) {

            status += SDL_RenderDrawLine(renderer,
                                         circleShape.position.x - offsety,
                                         circleShape.position.y + offsetx,
                                         circleShape.position.x + offsety,
                                         circleShape.position.y + offsetx);
            status += SDL_RenderDrawLine(renderer,
                                         circleShape.position.x - offsetx,
                                         circleShape.position.y + offsety,
                                         circleShape.position.x + offsetx,
                                         circleShape.position.y + offsety);
            status += SDL_RenderDrawLine(renderer,
                                         circleShape.position.x - offsetx,
                                         circleShape.position.y - offsety,
                                         circleShape.position.x + offsetx,
                                         circleShape.position.y - offsety);
            status += SDL_RenderDrawLine(renderer,
                                         circleShape.position.x - offsety,
                                         circleShape.position.y - offsetx,
                                         circleShape.position.x + offsety,
                                         circleShape.position.y - offsetx);

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

class CircleObject : public Circle, public CircleShape {
public:
    CircleObject(Point position, float rayon) :
        Circle(position, rayon), CircleShape(rayon, position) {}

    void setPosition(Point p) {
        CircleShape::position = p;
        Circle::position = p;
    }
};

class PointObject : public Point, public CircleShape {
public:
    PointObject(Point position) : Point(position), CircleShape(0.2, position) {}

    void setPosition(Point p) {
        CircleShape::position = p;
        operator=(p);
    }
};

class RectangleObject : public Rectangle, public RectangleShape {
public:
    RectangleObject(Point position, Point size, Color fillColor = X11::White) :
        Rectangle(position, size), RectangleShape(size, position, fillColor) {}

    void setPosition(Point p) {
        Rectangle::position = p;
        RectangleShape::position = p;
    }
};

class LineObject : public Line, public LineShape {
public:
    LineObject(Point position1, Point position2) :
        Line(position1, position2), LineShape(position1, position2) {}

    void setPosition(Point position1, Point position2) {
        Line::positionA = position1;
        Line::positionB = position2;
        LineShape::position1 = position1;
        LineShape::position2 = position2;
    }
};

class Game {
private:
    unsigned int tick;
    Window window;
    std::list<CircleObject> circles;
    std::list<RectangleObject> rectangles;
    std::list<PointObject> points;
    std::list<LineObject> lines;

public:
    Game() {

        CircleObject circleCursor(Point{0, 0}, 20);
        RectangleObject rectangleCursor({0, 0}, {40, 40});
        PointObject pointCursor({0, 0});
        LineObject lineCursor({-20, 0}, {20, 0});

        circles.emplace_back(Point{200, 200}, 10);
        circles.emplace_back(Point{400, 200}, 20);
        circles.emplace_back(Point{600, 200}, 30);
        circles.emplace_back(Point{800, 200}, 40);

        rectangles.emplace_back(Point{205, 405}, Point{20, 20});
        rectangles.emplace_back(Point{400, 400}, Point{40, 40});
        rectangles.emplace_back(Point{600, 400}, Point{100, 60});
        rectangles.emplace_back(Point{800, 400}, Point{60, 10});

        points.emplace_back(Point{200, 600});
        points.emplace_back(Point{400, 600});
        points.emplace_back(Point{600, 600});
        points.emplace_back(Point{800, 600});

        lines.emplace_back(Point{200, 790}, Point{200, 810});
        lines.emplace_back(Point{380, 800}, Point{420, 800});
        lines.emplace_back(Point{570, 770}, Point{630, 830});
        lines.emplace_back(Point{820, 780}, Point{780, 820});

        SDL_Event e{};
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

            Vec2<int> cursorPosition;
            SDL_GetMouseState(&cursorPosition.x, &cursorPosition.y);
            bool hit = false;
            switch (state) {
            case 0:
                circleCursor.setPosition(cursorPosition.cast<float>());
                for (const auto &c : circles)
                    if (circleCursor.overlap(c))
                        hit = true;
                for (const auto &c : rectangles)
                    if (circleCursor.overlap(c))
                        hit = true;
                for (const auto &c : lines)
                    if (circleCursor.overlap(c))
                        hit = true;
                for (const auto &c : points)
                    if (circleCursor.overlap(c))
                        hit = true;
                if (hit)
                    circleCursor.color = X11::Red;
                else
                    circleCursor.color = X11::Green;
                for (auto &r : circleCursor.rasterize())
                    window.draw(RectangleShape(Point{1, 1},
                                               r.cast<float>() + 0.5f,
                                               X11::Blue));
                window.draw(circleCursor);
                break;
            case 1:
                rectangleCursor.setPosition(cursorPosition.cast<float>());
                for (const auto &c : circles)
                    if (rectangleCursor.overlap(c))
                        hit = true;
                for (const auto &c : rectangles)
                    if (rectangleCursor.overlap(c))
                        hit = true;
                for (const auto &c : lines)
                    if (rectangleCursor.overlap(c))
                        hit = true;
                for (const auto &c : points)
                    if (rectangleCursor.overlap(c))
                        hit = true;
                if (hit)
                    rectangleCursor.color = X11::Red;
                else
                    rectangleCursor.color = X11::Green;
                for (auto &r : rectangleCursor.rasterize())
                    window.draw(RectangleShape(Point{1, 1},
                                               r.cast<float>() + 0.5f,
                                               X11::Blue));
                window.draw(rectangleCursor);
                break;
            case 2:
                pointCursor.setPosition(cursorPosition.cast<float>());
                for (const auto &c : circles)
                    if (pointCursor.overlap(c))
                        hit = true;
                for (const auto &c : rectangles)
                    if (pointCursor.overlap(c))
                        hit = true;
                for (const auto &c : lines)
                    if (pointCursor.overlap(c))
                        hit = true;
                for (const auto &c : points)
                    if (pointCursor.overlap(c))
                        hit = true;
                if (hit)
                    pointCursor.color = X11::Red;
                else
                    pointCursor.color = X11::Green;
                for (auto &r : pointCursor.rasterize())
                    window.draw(RectangleShape(Point{1, 1},
                                               r.cast<float>() + 0.5f,
                                               X11::Blue));
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
                for (const auto &c : circles)
                    if (lineCursor.overlap(c))
                        hit = true;
                for (const auto &c : rectangles)
                    if (lineCursor.overlap(c))
                        hit = true;
                for (const auto &c : lines)
                    if (lineCursor.overlap(c))
                        hit = true;
                for (const auto &c : points)
                    if (lineCursor.overlap(c))
                        hit = true;
                if (hit)
                    lineCursor.color = X11::Red;
                else
                    lineCursor.color = X11::Green;
                for (auto &r : lineCursor.rasterize())
                    window.draw(RectangleShape(Point{1, 1},
                                               r.cast<float>() + 0.5f,
                                               X11::Blue));
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
                    break;
                case SDL_MOUSEWHEEL:
                    mouseOrientation += e.wheel.y;
                    break;
                default:
                    break;
                }
            }

            tick++;

            if (tick >= 60) {
                char szFps[200];
                sprintf(szFps,
                        "%s : %f FPS",
                        "Game Title",
                        tick / window.getFrameTime());
                tick = 0;
                window.setTitle(szFps);
            }
            window.display();
            window.clear();
        }
    }
};

int main(int argc, char *args[]) {
    Game game;

    return 0;
}
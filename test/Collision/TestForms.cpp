#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>

#include <Blob/Collision/Forms.hpp>

using namespace Blob;

class Circle : public Collision::Circle, public sf::CircleShape {
public:
    Circle(Collision::Point position, float rayon) : Collision::Circle(position, rayon), sf::CircleShape(rayon) {
        sf::CircleShape::setPosition(position.x, position.y);
        setOrigin(rayon, rayon);
    }

    void setPosition(Collision::Point p) {
        sf::CircleShape::setPosition(p.x, p.y);
        position = p;
    }
};

class Point : public Collision::Point, public sf::CircleShape {
public:
    Point(Collision::Point position) : Collision::Point(position), sf::CircleShape(0.2) {
        sf::CircleShape::setPosition(position.x, position.y);
        setOrigin(0.2, 0.2);
    }

    void setPosition(Collision::Point p) {
        sf::CircleShape::setPosition(p.x, p.y);
        operator=(p);
    }
};

class Rectangle : public Collision::Rectangle, public sf::RectangleShape {
public:
    Rectangle(Collision::Point position, Collision::Point size, sf::Color fillColor = sf::Color::White) :
            Collision::Rectangle(position, size),
            sf::RectangleShape({size.x, size.y}) {
        sf::RectangleShape::setPosition(position.x, position.y);
        setOrigin(size.x / 2, size.y / 2);
        setFillColor(fillColor);
    }

    void setPosition(Collision::Point p) {
        sf::RectangleShape::setPosition(p.x, p.y);
        position = p;
    }
};

class Line : public Collision::Line, public sf::RectangleShape {
public:
    Line(Collision::Point position1, Collision::Point position2) : Collision::Line(position1, position2),
                                                                 sf::RectangleShape(
                                                                         {0.2, (position1 - position2).length()}) {
        auto vector = position1 - position2;
        auto position = (position1 + position2) / 2;
        setOrigin(0.1, (position1 - position2).length() / 2);
        sf::RectangleShape::setPosition(position.x, position.y);
        sf::RectangleShape::setRotation(-std::atan2(vector.x, vector.y) * 180 / PI);
    }

    void setPosition(Collision::Point position1, Collision::Point position2) {
        auto vector = position1 - position2;
        auto position = (position1 + position2) / 2;
        sf::RectangleShape::setPosition(position.x, position.y);
        sf::RectangleShape::setRotation(-std::atan2(vector.x, vector.y) * 180 / PI);
        sf::RectangleShape::setSize({0.2, (position1 - position2).length()});
        setOrigin(0.1, (position1 - position2).length() / 2);
        positionA = position1;
        positionB = position2;
    }
};

class Game {
private:
    unsigned int tick;
    std::list<sf::Sprite *> ModelList;
    sf::RenderWindow window;
    sf::View view;
    std::map<sf::Keyboard::Key, bool> KeysState;
    sf::Clock clock;
    std::list<Circle> circles;
    std::list<Rectangle> rectangles;
    std::list<Point> points;
    std::list<Line> lines;

public:
    Game() : view(sf::FloatRect(0.f, 0.f, 100.f, 100.f)), window(sf::VideoMode(1000, 1000), "SFML works!") {

        window.setKeyRepeatEnabled(false);
        window.setVerticalSyncEnabled(true);
        window.setView(view);

        Circle circleCursor(Collision::Point{0, 0}, 2);
        Rectangle rectangleCursor({0, 0}, {4, 4});
        Point pointCursor({0, 0});
        Line lineCursor({-2, 0}, {2, 0});

        circles.emplace_back(Collision::Point{20, 20}, 1);
        circles.emplace_back(Collision::Point{40, 20}, 2);
        circles.emplace_back(Collision::Point{60, 20}, 3);
        circles.emplace_back(Collision::Point{80, 20}, 4);

        rectangles.emplace_back(Collision::Point{20.5, 40.5}, Collision::Point{2, 20});
        rectangles.emplace_back(Collision::Point{40, 40}, Collision::Point{4, 4});
        rectangles.emplace_back(Collision::Point{60, 40}, Collision::Point{10, 6});
        rectangles.emplace_back(Collision::Point{80, 40}, Collision::Point{6, 10});

        points.emplace_back(Collision::Point{20, 60});
        points.emplace_back(Collision::Point{40, 60});
        points.emplace_back(Collision::Point{60, 60});
        points.emplace_back(Collision::Point{80, 60});

        lines.emplace_back(Collision::Point{20, 79}, Collision::Point{20, 81});
        lines.emplace_back(Collision::Point{38, 80}, Collision::Point{42, 80});
        lines.emplace_back(Collision::Point{57, 77}, Collision::Point{63, 83});
        lines.emplace_back(Collision::Point{82, 78}, Collision::Point{78, 82});

        sf::Event e{};
        bool quit = false;
        window.setMouseCursorVisible(false);
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

            sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
            sf::Vector2f p = window.mapPixelToCoords(pixelPos);
            bool hit = false;
            switch (state) {
                case 0:
                    circleCursor.setPosition({(float) p.x, (float) p.y});
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
                        circleCursor.setFillColor(sf::Color::Red);
                    else
                        circleCursor.setFillColor(sf::Color::Green);
                    for (auto &r : circleCursor.rasterize())
                        window.draw(Rectangle(Collision::Point(r.x + 0.5f, r.y + 0.5f), Collision::Point{1, 1}, sf::Color::Blue));
                    window.draw(circleCursor);
                    break;
                case 1:
                    rectangleCursor.setPosition({(float) p.x, (float) p.y});
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
                        rectangleCursor.setFillColor(sf::Color::Red);
                    else
                        rectangleCursor.setFillColor(sf::Color::Green);
                    for (auto &r : rectangleCursor.rasterize())
                        window.draw(Rectangle(Collision::Point(r.x + 0.5f, r.y + 0.5f), Collision::Point{1, 1}, sf::Color::Blue));
                    window.draw(rectangleCursor);
                    break;
                case 2:
                    pointCursor.setPosition({(float) p.x, (float) p.y});
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
                        pointCursor.setFillColor(sf::Color::Red);
                    else
                        pointCursor.setFillColor(sf::Color::Green);
                    for (auto &r : pointCursor.rasterize())
                        window.draw(Rectangle(Collision::Point(r.x + 0.5f, r.y + 0.5f), Collision::Point{1, 1}, sf::Color::Blue));
                    window.draw(pointCursor);
                    break;
                case 3:
                    lineCursor.setPosition({(float) p.x + (2 * std::cos(mouseOrientation / 20.f)),
                                            (float) p.y + (2 * std::sin(mouseOrientation / 20.f))},
                                           {(float) p.x - (2 * std::cos(mouseOrientation / 20.f)),
                                            (float) p.y - (2 * std::sin(mouseOrientation / 20.f))});
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
                        lineCursor.setFillColor(sf::Color::Red);
                    else
                        lineCursor.setFillColor(sf::Color::Green);
                    for (auto &r : lineCursor.rasterize())
                        window.draw(Rectangle(Collision::Point(r.x + 0.5f, r.y + 0.5f), Collision::Point{1, 1}, sf::Color::Blue));
                    window.draw(lineCursor);
                    break;
            }

            while (window.pollEvent(e)) {
                switch (e.type) {
                    case sf::Event::Closed:
                        quit = true;
                        break;
                    case sf::Event::KeyPressed:
                        KeysState[e.key.code] = true;
                        break;
                    case sf::Event::KeyReleased:
                        KeysState[e.key.code] = false;
                        break;
                    case sf::Event::MouseButtonPressed:
                        state++;
                        if (state > 3)
                            state = 0;
                        break;
                    case sf::Event::MouseWheelScrolled:
                        mouseOrientation += e.mouseWheelScroll.delta;
                        break;
                    default:
                        break;
                }
            }

            tick++;

            if (tick >= 60) {
                char szFps[200];
                sprintf(szFps, "%s : %f FPS", "Game Title", tick / clock.restart().asSeconds());
                tick = 0;
                window.setTitle(szFps);
            }
            window.display();
            window.clear(sf::Color(0, 0, 0, 255));
        }
    }
};

int main() {
    Game game;

    return 0;
}
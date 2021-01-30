#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>

#include <Blob/Collision/CollisionDetector.hpp>

using namespace Blob;

class Circle : public Collision::Collider<Collision::Circle>, public sf::CircleShape {
public:
    Collision::Circle circle;

    Circle(Collision::Point position, float rayon) : Collision::Collider<Collision::Circle>(typeid(Circle), circle),
                                                     circle(position, rayon), sf::CircleShape(rayon) {
        sf::CircleShape::setPosition(position.x, position.y);
        setOrigin(rayon, rayon);
    }

    void setPosition(Collision::Point p) {
        sf::CircleShape::setPosition(p.x, p.y);
        circle.position = p;
    }
};

class CircleCursor : public Collision::DynamicCollider<Collision::Circle>, public sf::CircleShape {
public:
    Collision::Circle circle;

    CircleCursor(Collision::Point position, float rayon) : Collision::DynamicCollider<Collision::Circle>(
            typeid(CircleCursor), circle), circle(position, rayon), sf::CircleShape(rayon) {
        sf::CircleShape::setPosition(position.x, position.y);
        setOrigin(rayon, rayon);
    }

    void setPosition(Collision::Point p) {
        sf::CircleShape::setPosition(p.x, p.y);
        circle.position = p;
    }

    void hitStart(PhysicalObject *object) final {
        setFillColor(sf::Color::Red);
    }

    void hitEnd(PhysicalObject *object) final {
        setFillColor(sf::Color::Green);
    }
};

class Point : public Collision::Collider<Collision::Point>, public sf::CircleShape {
public:
    Collision::Point point;

    Point(Collision::Point position) : Collision::Collider<Collision::Point>(typeid(Point), point), point(position),
                                       sf::CircleShape(0.2) {
        sf::CircleShape::setPosition(position.x, position.y);
        setOrigin(0.2, 0.2);
    }

    void setPosition(Collision::Point p) {
        sf::CircleShape::setPosition(p.x, p.y);
        point = p;
    }
};

class PointCursor : public Collision::DynamicCollider<Collision::Point>, public sf::CircleShape {
public:
    Collision::Point point;

    PointCursor(Collision::Point position) : Collision::DynamicCollider<Collision::Point>(typeid(PointCursor), point),
                                             point(position), sf::CircleShape(0.2) {
        sf::CircleShape::setPosition(position.x, position.y);
        setOrigin(0.2, 0.2);
    }

    void setPosition(Collision::Point p) {
        sf::CircleShape::setPosition(p.x, p.y);
        point = p;
    }

    void hitStart(PhysicalObject *object) final {
        setFillColor(sf::Color::Red);
    }

    void hitEnd(PhysicalObject *object) final {
        setFillColor(sf::Color::Green);
    }
};

class Rectangle : public Collision::Collider<Collision::Rectangle>, public sf::RectangleShape {
public:
    Collision::Rectangle rectangle;

    Rectangle(Collision::Point position, Collision::Point size, sf::Color fillColor = sf::Color::White) :
            rectangle(position, size), Collision::Collider<Collision::Rectangle>(typeid(Rectangle), rectangle),
            sf::RectangleShape({size.x, size.y}) {
        sf::RectangleShape::setPosition(position.x, position.y);
        setOrigin(size.x / 2, size.y / 2);
        setFillColor(fillColor);
    }

    void setPosition(Collision::Point p) {
        sf::RectangleShape::setPosition(p.x, p.y);
        rectangle.position = p;
    }
};

class RectangleCursor : public Collision::DynamicCollider<Collision::Rectangle>, public sf::RectangleShape {
public:
    Collision::Rectangle rectangle;

    RectangleCursor(Collision::Point position, Collision::Point size, sf::Color fillColor = sf::Color::White) :
            rectangle(position, size),
            Collision::DynamicCollider<Collision::Rectangle>(typeid(CircleCursor), rectangle),
            sf::RectangleShape({size.x, size.y}) {
        sf::RectangleShape::setPosition(position.x, position.y);
        setOrigin(size.x / 2, size.y / 2);
        setFillColor(fillColor);
    }

    void setPosition(Collision::Point p) {
        sf::RectangleShape::setPosition(p.x, p.y);
        rectangle.position = p;
    }

    void hitStart(PhysicalObject *object) final {
        setFillColor(sf::Color::Red);
    }

    void hitEnd(PhysicalObject *object) final {
        setFillColor(sf::Color::Green);
    }
};

class Line : public Collision::Collider<Collision::Line>, public sf::RectangleShape {
public:
    Collision::Line line;

    Line(Collision::Point position1, Collision::Point position2) : line(position1, position2),
                                                                   Collision::Collider<Collision::Line>(typeid(Line), line),
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
        line.positionA = position1;
        line.positionB = position2;
    }
};

class LineCursor : public Collision::DynamicCollider<Collision::Line>, public sf::RectangleShape {
public:
    Collision::Line line;

    LineCursor(Collision::Point position1, Collision::Point position2) : line(position1, position2),
                                                                         Collision::DynamicCollider<Collision::Line>(typeid(LineCursor),
                                                                                                                     line),
                                                                         sf::RectangleShape(
                                                                                 {0.2,
                                                                                  (position1 - position2).length()}) {
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
        line.positionA = position1;
        line.positionB = position2;
    }

    void hitStart(PhysicalObject *object) final {
        setFillColor(sf::Color::Red);
    }

    void hitEnd(PhysicalObject *object) final {
        setFillColor(sf::Color::Green);
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

        Collision::CollisionDetector collisionDetector;

        window.setKeyRepeatEnabled(false);
        window.setVerticalSyncEnabled(true);
        window.setView(view);

        CircleCursor circleCursor(Collision::Point{0, 0}, 2);
        collisionDetector.enableCollision(circleCursor);
        RectangleCursor rectangleCursor({0, 0}, {4, 4});
        PointCursor pointCursor({0, 0});
        LineCursor lineCursor({-2, 0}, {2, 0});

        circles.emplace_back(Collision::Point{20, 20}, 1);
        circles.emplace_back(Collision::Point{40, 20}, 2);
        circles.emplace_back(Collision::Point{60, 20}, 3);
        circles.emplace_back(Collision::Point{80, 20}, 4);

        for (auto &c : circles)
            collisionDetector.enableCollision(c);

        rectangles.emplace_back(Collision::Point{20.5, 40.5}, Collision::Point{2, 20});
        rectangles.emplace_back(Collision::Point{40, 40}, Collision::Point{4, 4});
        rectangles.emplace_back(Collision::Point{60, 40}, Collision::Point{10, 6});
        rectangles.emplace_back(Collision::Point{80, 40}, Collision::Point{6, 10});

        for (auto &c : rectangles)
            collisionDetector.enableCollision(c);

        points.emplace_back(Collision::Point{20, 60});
        points.emplace_back(Collision::Point{40, 60});
        points.emplace_back(Collision::Point{60, 60});
        points.emplace_back(Collision::Point{80, 60});

        for (auto &c : points)
            collisionDetector.enableCollision(c);

        lines.emplace_back(Collision::Point{20, 79}, Collision::Point{20, 81});
        lines.emplace_back(Collision::Point{38, 80}, Collision::Point{42, 80});
        lines.emplace_back(Collision::Point{57, 77}, Collision::Point{63, 83});
        lines.emplace_back(Collision::Point{82, 78}, Collision::Point{78, 82});

        for (auto &c : lines)
            collisionDetector.enableCollision(c);

        sf::Event e{};
        bool quit = false;
        window.setMouseCursorVisible(false);
        uint32_t state = 0;
        float mouseOrientation = 0;
        sf::Clock clock;

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
            switch (state) {
                case 0:
                    circleCursor.setPosition({(float) p.x, (float) p.y});
                    window.draw(circleCursor);
                    break;
                case 1:
                    rectangleCursor.setPosition({(float) p.x, (float) p.y});
                    window.draw(rectangleCursor);
                    break;
                case 2:
                    pointCursor.setPosition({(float) p.x, (float) p.y});
                    window.draw(pointCursor);
                    break;
                case 3:
                    lineCursor.setPosition({(float) p.x + (2 * std::cos(mouseOrientation / 20.f)),
                                            (float) p.y + (2 * std::sin(mouseOrientation / 20.f))},
                                           {(float) p.x - (2 * std::cos(mouseOrientation / 20.f)),
                                            (float) p.y - (2 * std::sin(mouseOrientation / 20.f))});
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
            collisionDetector.update(clock.restart().asSeconds());
            window.display();
            window.clear(sf::Color(0, 0, 0, 255));
        }
    }
};

int main() {
    Game game;

    return 0;
}
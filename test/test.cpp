#include <iostream>
#include <SFML/Graphics.hpp>
#include "../src/CollisionClass.hpp"

using namespace BlobEngine;

class CircleObject{
private:
	Circle circle;
	sf::CircleShape circleShape;
	Line move;
	sf::RectangleShape line;

public:

	explicit CircleObject(int x, int y, int r) {
		circle.position.x = x;
		circle.position.y = y;
		circle.rayon = r;

		circleShape.setRadius(r);
		circleShape.setOrigin(circle.rayon, circle.rayon);
		circleShape.setPosition(circle.position.x, circle.position.y);
		circleShape.setFillColor(sf::Color::Green);
	}

	explicit CircleObject(Point2f p, float r) {
		circle.position = p;
		circle.rayon = r;

		circleShape.setRadius(r);
		circleShape.setOrigin(circle.rayon, circle.rayon);
		circleShape.setPosition(circle.position.x, circle.position.y);
		circleShape.setFillColor(sf::Color::Green);
	}

	explicit CircleObject(int x, int y, int r, int mx, int my) : move(Point2f(x, y), Point2f(mx, my)) {

		line.setPosition(x, y);
		line.setSize(sf::Vector2f(move.Length(), 4));
		line.setOrigin(0, 2);
		line.setFillColor(sf::Color::Blue);
		line.setRotation(move.getOrientation() * 180 / PI);

		circle.position.x = x;
		circle.position.y = y;
		circle.rayon = r;

		circleShape.setRadius(r);
		circleShape.setOrigin(circle.rayon, circle.rayon);
		circleShape.setPosition(circle.position.x, circle.position.y);
		circleShape.setFillColor(sf::Color::White);
	}

	void draw(sf::RenderWindow *window) {
		window->draw(circleShape);
		window->draw(line);
	}

	Circle getCircle() {
		return circle;
	}

	Vec2f getMove() {
		return move.getVector();
	}

	void setDestination(int x, int y) {
		move.pointB.x = x;
		move.pointB.y = y;
		line.setSize(sf::Vector2f(move.Length(), 4));
		line.setRotation(move.getOrientation() * 180 / PI);
		//std::cout << move.getVector().x << ":" << move.getVector().y << " --> " << move.getOrientation() * 180 / PI << std::endl;
	}

	void setColor(sf::Color c){
		circleShape.setFillColor(c);
	}
};

class LineObject {
private:
	Line line;
	sf::RectangleShape rectangleShape;

public:

	explicit LineObject(int ax, int ay, int bx, int by) {
		line.pointA.x = ax;
		line.pointA.y = ay;
		line.pointB.x = bx;
		line.pointB.y = by;

		rectangleShape.setSize(sf::Vector2f(line.Length(), line.Length()));
		rectangleShape.setPosition(ax, ay);
		rectangleShape.setFillColor(sf::Color::Green);
	}

	void draw(sf::RenderWindow *window){
		window->draw(rectangleShape);
	}

	void setColor(sf::Color c){
		rectangleShape.setFillColor(c);
	}

	Line getLine() {
		return line;
	}
};
//Collosion D test

enum directions{
	UP = 0,
	DOWN = 1,
	LEFT = 2,
	RIGHT = 3
};

class Box : LineStatic{
private:
	sf::RectangleShape shape;

public:
	explicit Box(Point2f position) : LineStatic(0) {

		shape.setSize(sf::Vector2f(20, 20));
		shape.setOrigin(10, 10);
		shape.setPosition(sf::Vector2f(position.x, position.y));
		shape.setFillColor(sf::Color(255, 150, 0));

		Point2f a = position + Point2f(10, 10);
		Point2f b = position + Point2f(10, -10);
		Point2f c = position + Point2f(-10, -10);
		Point2f d = position + Point2f(-10, 10);

		lines.emplace_back(a, b);
		lines.emplace_back(b, c);
		lines.emplace_back(c, d);
		lines.emplace_back(d, a);
	}

	void draw(sf::RenderWindow *window) {
		window->draw(shape);
	}
};

class Box2 : CircleStatic{
private:
	sf::CircleShape shape;

public:
	explicit Box2(Point2f position) : CircleStatic(0) {

		mainCircle.position = position;
		mainCircle.rayon = 20;

		shape.setOrigin(mainCircle.rayon, mainCircle.rayon);
		shape.setPosition(sf::Vector2f(position.x, position.y));
		shape.setFillColor(sf::Color(255, 150, 0));
		shape.setRadius(mainCircle.rayon);
	}

	void draw(sf::RenderWindow *window) {
		window->draw(shape);
	}
};

class Player : CircleDynamic{
private:
	float maxSpeed, orientation;
	sf::CircleShape shape;
	sf::Clock clock;

	std::array<bool, 4> command = {false, false, false, false};

	Reaction hit(const BlobEngine::PhysicalObject& from) override {
		return ROLL;
	}

	void update() {
		float TimeFlow = clock.restart().asSeconds();
		Vec2f Acceleration;

		if (command[directions::LEFT]) {
			Acceleration.x -= 1;
		}
		if (command[directions::RIGHT]) {
			Acceleration.x += 1;
		}
		if (command[directions::UP]) {
			Acceleration.y -= 1;
		}
		if (command[directions::DOWN]) {
			Acceleration.y += 1;
		}

		if (Acceleration.x != 0 || Acceleration.y != 0) {
			orientation = Acceleration.getOrientation();
			speed = Acceleration.setLength(maxSpeed);
			CheckCollision();
		}
		else {
			speed = Vec2f();
		}
	}
public:

	explicit Player() : CircleDynamic(0) {
		mainCircle.position.x = 50;
		mainCircle.position.y = 500;
		mainCircle.rayon = 10;
		orientation = 0;

		shape.setRadius(mainCircle.rayon);
		shape.setOrigin(10, 10);
		shape.setPosition(sf::Vector2f(mainCircle.position.x, mainCircle.position.y));
		maxSpeed = 200;
	}

	void draw(sf::RenderWindow *window) {
		update();

		shape.setPosition(sf::Vector2f(mainCircle.position.x, mainCircle.position.y));
		window->draw(shape);
	}

	void keyPress(directions d) {
		command[d] = true;
	}

	void keyReleased(directions d) {
		command[d] = false;
	}
};

int main() {

	try {

		sf::ContextSettings settings;
		settings.antialiasingLevel = 8;

		unsigned int width = 620, height = 620;

		sf::RenderWindow window(sf::VideoMode(width, height), "BlobEngine test", sf::Style::Close, settings);

		CollisionDetector collisionDetector;

		CircleObject object(50, 50, 25, 20, 20), target(300, 300, 50);

		LineObject line(300, 50, 300, 150);

		std::list<Box> boxs;

		Player player;

		Box2 box2(Point2f(500, 500));

		for (int i = 0; i < width; i += 20) {
			boxs.emplace_back(Point2f(10 + i, 410));
			boxs.emplace_back(Point2f(10 + i, height - 10));
		}

		for (int i = 420; i < height - 20; i += 20) {
			boxs.emplace_back(Point2f(10, 10 + i));
			boxs.emplace_back(Point2f(width - 10, 10 + i));
		}

		bool left = false;

		while (window.isOpen()) {
			window.clear();

			sf::Keyboard::Key Key;
			sf::Event event;
			sf::Mouse::Button mouseButton;

			while (window.pollEvent(event)) {
				switch (event.type) {
					case sf::Event::Closed :
						window.close();
						break;
					case sf::Event::MouseButtonPressed :
						mouseButton = event.mouseButton.button;
						switch (mouseButton) {
							case sf::Mouse::Left :
								left = true;
								break;
						}
						break;
					case sf::Event::MouseButtonReleased :
						mouseButton = event.mouseButton.button;
						switch (mouseButton) {
							case sf::Mouse::Left :
								left = false;
								break;
						}
						break;
					case sf::Event::KeyPressed :
						Key = event.key.code;

						switch (Key) {
							case sf::Keyboard::Left :
								player.keyPress(directions::LEFT);
								break;
							case sf::Keyboard::Right :
								player.keyPress(directions::RIGHT);
								break;
							case sf::Keyboard::Up :
								player.keyPress(directions::UP);
								break;
							case sf::Keyboard::Down :
								player.keyPress(directions::DOWN);
								break;
							default:
								break;
						}
						break;
					case sf::Event::KeyReleased :
						Key = event.key.code;

						switch (Key) {
							case sf::Keyboard::Left :
								player.keyReleased(directions::LEFT);
								break;
							case sf::Keyboard::Right :
								player.keyReleased(directions::RIGHT);
								break;
							case sf::Keyboard::Up :
								player.keyReleased(directions::UP);
								break;
							case sf::Keyboard::Down :
								player.keyReleased(directions::DOWN);
								break;
							default:
								break;
						}
						break;
				}
			}

			if (left)
				object.setDestination(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);

			Collision c(object.getCircle(), target.getCircle(), object.getMove());

			if (c.hitTarget()) {
				target.setColor(sf::Color::Red);

				CircleObject hitPoint(object.getCircle().position + c.vecAF, object.getCircle().rayon);
				hitPoint.setColor(sf::Color::Yellow);
				hitPoint.draw(&window);

				Vec2f useless;

				CircleObject rollPoint(object.getCircle().position + c.getRoll(&useless), object.getCircle().rayon);
				rollPoint.setColor(sf::Color::Yellow);
				rollPoint.draw(&window);
			} else {
				target.setColor(sf::Color::Green);
			}

			Collision c2(object.getCircle(), line.getLine(), object.getMove());

			if (c2.hitTarget()) {
				line.setColor(sf::Color::Red);

				CircleObject hitPoint(object.getCircle().position + c2.vecAF, object.getCircle().rayon);
				hitPoint.setColor(sf::Color::Yellow);
				hitPoint.draw(&window);

				Vec2f useless;

				CircleObject rollPoint(object.getCircle().position + c2.getRoll(&useless), object.getCircle().rayon);
				rollPoint.setColor(sf::Color::Yellow);
				rollPoint.draw(&window);
			} else {
				line.setColor(sf::Color::Green);
			}

			line.draw(&window);
			object.draw(&window);
			target.draw(&window);

			//test cd
			collisionDetector.update();

			for(Box box : boxs)
				box.draw(&window);

			player.draw(&window);

			box2.draw(&window);

			window.display();
		}
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	return 0;
}
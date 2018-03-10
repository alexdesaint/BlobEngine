#include <iostream>
#include <SFML/Graphics.hpp>
#include "../src/CollisionClass.hpp"

using namespace Geometrie;
using namespace Physics;

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

int main() {

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(600, 600), "BlobEngine test", sf::Style::Close, settings);

	CircleObject object(50, 50, 25, 20, 20), target(300, 300, 50);

	LineObject line(300, 50, 300, 150);

	bool left = false;

	while (window.isOpen()) {
		window.clear();

		sf::Event event;
		sf::Mouse::Button mouseButton;

		while (window.pollEvent(event))
		{
			switch (event.type){
				case sf::Event::Closed :
					window.close();
					break;
				case sf::Event::MouseButtonPressed :
					mouseButton = event.mouseButton.button;
					switch(mouseButton){
						case sf::Mouse::Left :
							left = true;
							break;
					}
					break;
				case sf::Event::MouseButtonReleased :
					mouseButton = event.mouseButton.button;
					switch(mouseButton){
						case sf::Mouse::Left :
							left = false;
							break;
					}
					break;
			}
		}

		if(left)
			object.setDestination(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);

		Collision c(object.getCircle(), target.getCircle(), object.getMove());

		if(c.hitTarget()) {
			target.setColor(sf::Color::Red);

			CircleObject hitPoint(object.getCircle().position + c.vecAF, object.getCircle().rayon);
			hitPoint.setColor(sf::Color::Yellow);
			hitPoint.draw(&window);

			Vec2f useless;

			CircleObject rollPoint(object.getCircle().position + c.getRoll(&useless), object.getCircle().rayon);
			rollPoint.setColor(sf::Color::Yellow);
			rollPoint.draw(&window);
		}
		else{
			target.setColor(sf::Color::Green);
		}

		Collision c2(object.getCircle(), line.getLine(), object.getMove());

		if(c2.hitTarget()) {
			line.setColor(sf::Color::Red);

			CircleObject hitPoint(object.getCircle().position + c2.vecAF, object.getCircle().rayon);
			hitPoint.setColor(sf::Color::Yellow);
			hitPoint.draw(&window);

			Vec2f useless;

			CircleObject rollPoint(object.getCircle().position + c2.getRoll(&useless), object.getCircle().rayon);
			rollPoint.setColor(sf::Color::Yellow);
			rollPoint.draw(&window);
		}
		else{
			line.setColor(sf::Color::Green);
		}

		line.draw(&window);
		object.draw(&window);
		target.draw(&window);
		window.display();
	}

	return 0;
}
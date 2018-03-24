#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>
#include <BlobEngine/Hit.hpp>

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

		rectangleShape.setSize(sf::Vector2f(4, line.Length()));
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

	try {
		sf::ContextSettings settings;
		settings.antialiasingLevel = 8;

		unsigned int width = 600, height = 600;

		sf::RenderWindow window(sf::VideoMode(width, height), "BlobEngine test", sf::Style::Close, settings);
		window.setFramerateLimit(60);

		CircleObject object(300, 300, 25, 40, 300);
		
		std::list<CircleObject> circleList;
		
		for(int i = 40; i < width/2; i += 80){
			circleList.emplace_back(i, 40, 30);
		}
		
		for(int i = 120; i < height; i += 80){
			circleList.emplace_back(40, i, 30);
		}

		LineObject line(500, 450, 500, 550);

		bool left = false;

		while (window.isOpen()) {
			window.clear();

			sf::Event event{};
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
							default:
								break;
						}
						break;
					case sf::Event::MouseButtonReleased :
						mouseButton = event.mouseButton.button;
						switch (mouseButton) {
							case sf::Mouse::Left :
								left = false;
								break;
							default:
								break;
						}
						break;
					default:
						break;
				}
			}

			if (left)
				object.setDestination(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
			
			Vec2f useless;
			
			Hit lastHit;
			CircleObject *lastHitCircle = nullptr;
			
			for(auto &circle : circleList){
				circle.setColor(sf::Color::Green);
				
				Hit c(object.getCircle(), circle.getCircle(), object.getMove());
				
				if (c.hitTarget()) {
					
					if (lastHitCircle == nullptr) {
						lastHit = c;
						lastHitCircle = &circle;
					} else if (c.isCloserObstacle(lastHit)) {
						lastHit = c;
						lastHitCircle = &circle;
					}
				}
			}
			
			if(lastHitCircle != nullptr) {
				lastHitCircle->setColor(sf::Color::Red);
				
				Vec2f vecToHitPoint = object.getCircle().position + lastHit.getHitPoint();
				float rayon = object.getCircle().rayon;
				
				CircleObject hitPoint(vecToHitPoint, rayon);
				hitPoint.setColor(sf::Color::Yellow);
				hitPoint.draw(&window);
				
				CircleObject rollPoint(vecToHitPoint + lastHit.getRoll(&useless), rayon);
				rollPoint.setColor(sf::Color::Yellow);
				rollPoint.draw(&window);
				
				CircleObject bouncePoint(vecToHitPoint + lastHit.getBounce(&useless), rayon);
				bouncePoint.setColor(sf::Color::Magenta);
				bouncePoint.draw(&window);
			}

			Hit c2(object.getCircle(), line.getLine(), object.getMove());

			if (c2.hitTarget()) {
				line.setColor(sf::Color::Red);

				CircleObject hitPoint(object.getCircle().position + c2.getHitPoint(), object.getCircle().rayon);
				hitPoint.setColor(sf::Color::Yellow);
				hitPoint.draw(&window);

				CircleObject rollPoint(object.getCircle().position + c2.getHitPoint() + c2.getRoll(&useless), object.getCircle().rayon);
				rollPoint.setColor(sf::Color::Yellow);
				rollPoint.draw(&window);

				CircleObject bouncePoint(object.getCircle().position + c2.getHitPoint() + c2.getBounce(&useless), object.getCircle().rayon);
				bouncePoint.setColor(sf::Color::Magenta);
				bouncePoint.draw(&window);
			} else {
				line.setColor(sf::Color::Green);
			}

			for(auto &c : circleList){
				c.draw(&window);
			}
			
			line.draw(&window);
			object.draw(&window);

			window.display();
		}
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
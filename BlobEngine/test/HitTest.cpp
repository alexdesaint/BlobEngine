#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>
#include <BlobEngine/Collision/Hit.hpp>
#include <BlobEngine/Collision/CollisionDetector.hpp>

using namespace BlobEngine;

enum directions{
	UP = 0,
	DOWN = 1,
	LEFT = 2,
	RIGHT = 3
};

class StaticLine {
private:
	sf::RectangleShape line;
	sf::CircleShape base;
public:
	explicit StaticLine(int x, int y, int mx, int my, sf::Color color) {
		Vec2f speed = Vec2f(Point2f(x, y), Point2f(mx, my));

		line.setFillColor(color);
		line.setPosition(x, y);
		line.setSize(sf::Vector2f(speed.length(), 4));
		line.setOrigin(0, 2);
		line.setRotation(speed.getOrientationDeg());

		base.setFillColor(color);
		base.setPosition(x, y);
		base.setRadius(2);
		base.setOrigin(2, 2);
	}

	explicit StaticLine(Point2f o, Point2f d, sf::Color color) {
		Vec2f speed = Vec2f(o, d);

		line.setFillColor(color);

		line.setPosition(o.x, o.y);
		line.setSize(sf::Vector2f(speed.length(), 4));
		line.setOrigin(0, 2);
		line.setRotation(speed.getOrientationDeg());

		base.setFillColor(color);
		base.setPosition(o.x, o.y);
		base.setRadius(2);
		base.setOrigin(2, 2);
	}

	void draw(sf::RenderWindow *window) {
		window->draw(line);
		window->draw(base);
	}

	void update(float length, float orient) {
		line.setSize(sf::Vector2f(length, 4));
		line.setRotation(orient);
	}
};

class MainRect : public CircleDynamic {
private:
	sf::CircleShape circleShape;
	std::array<bool, 4> command = {false, false, false, false};
	sf::Clock clock;
	
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
		
		if (!Acceleration.isNull()) {
			mainCircle.position = mainCircle.position + Acceleration.setLength(100) * TimeFlow;
		}
		
		circleShape.setPosition(mainCircle.position.x, mainCircle.position.y);
	}
	
public:

	Reaction hit(const BlobEngine::PhysicalObject &from) override {
		return ROLL;
	}

	explicit MainRect(int x, int y, int r, int mx, int my) : CircleDynamic(0) {

		disableCollision();
		
		speed = Vec2f(Point2f(x, y), Point2f(mx, my));

		mainCircle.position.x = x;
		mainCircle.position.y = y;
		mainCircle.rayon = r;

		circleShape.setRadius(r);
		circleShape.setOrigin(mainCircle.rayon, mainCircle.rayon);
		circleShape.setPosition(mainCircle.position.x, mainCircle.position.y);
		circleShape.setFillColor(sf::Color::White);
	}

	void draw(sf::RenderWindow *window) {
		update();
		
		window->draw(circleShape);
	}

	Circle getCircle() {
		return mainCircle;
	}

	Vec2f getMove() {
		return speed;
	}

	void setDestination(int x, int y) {
		speed = Vec2f(mainCircle.position, Point2f(x, y));
	}

	void setColor(sf::Color c) {
		circleShape.setFillColor(c);
	}
	
	void keyPress(directions d) {
		command[d] = true;
	}
	
	void keyReleased(directions d) {
		command[d] = false;
	}
};

class StaticCircle : public CircleStatic {
private:
	sf::CircleShape circleShape;

	Reaction hit(const BlobEngine::PhysicalObject &from) override {
		circleShape.setFillColor(sf::Color::Red);

		return IGNORE;
	}

public:

	explicit StaticCircle(int x, int y, float r) : CircleStatic(0) {
		mainCircle.position.x = x;
		mainCircle.position.y = y;
		mainCircle.rayon = r;

		circleShape.setRadius(r);
		circleShape.setOrigin(mainCircle.rayon, mainCircle.rayon);
		circleShape.setPosition(mainCircle.position.x, mainCircle.position.y);
		circleShape.setFillColor(sf::Color::Green);
	}

	explicit StaticCircle(Vec2f position, float r) : CircleStatic(0) {
		mainCircle.position = position;
		mainCircle.rayon = r;

		circleShape.setRadius(r);
		circleShape.setOrigin(mainCircle.rayon, mainCircle.rayon);
		circleShape.setPosition(mainCircle.position.x, mainCircle.position.y);
		circleShape.setFillColor(sf::Color::Green);
	}

	void draw(sf::RenderWindow *window) {
		window->draw(circleShape);
	}

	Circle getCircle() {
		return mainCircle;
	}

	void setColor(sf::Color c){
		circleShape.setFillColor(c);
	}
};

class StaticRect : LineStatic {
private:
	sf::RectangleShape shape;

	Reaction hit(const BlobEngine::PhysicalObject &from) override {
		shape.setFillColor(sf::Color::Red);

		return IGNORE;
	}

public:

	explicit StaticRect(int x, int y, int r) : LineStatic(0) {

		shape.setSize(sf::Vector2f(r * 2, r * 2));
		shape.setOrigin(r, r);
		shape.setPosition(sf::Vector2f(x, y));
		shape.setFillColor(sf::Color(255, 0, 0));

		Vec2f position(x, y);

		Point2f a = position + Point2f(r, r);
		Point2f b = position + Point2f(r, -r);
		Point2f c = position + Point2f(-r, -r);
		Point2f d = position + Point2f(-r, r);

		lines.emplace_back(a);
		lines.emplace_back(b);
		lines.emplace_back(c);
		lines.emplace_back(d);
	}

	void draw(sf::RenderWindow *window){
		window->draw(shape);
	}

	void setColor(sf::Color c){
		shape.setFillColor(c);
	}
};

int main() {

	try {
		sf::ContextSettings settings;
		settings.antialiasingLevel = 8;

		unsigned int windowWidth = 600, windowHeight = 600, width = 440, height = 440, widthOff =
				(windowWidth - width) / 2, heightOff = (windowHeight - height) / 2;

		sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "BlobEngine test", sf::Style::Close,
								settings);
		window.setFramerateLimit(60);

		sf::Font font;
		font.loadFromFile("../data/FFFFORWA.TTF");

		CollisionDetector collisionDetector;
		
		MainRect object(500, 380, 20, 300, 300);

		std::list<StaticCircle> circleList;
		std::list<StaticRect> rectList;
		
		bool simpleDemo = 1;
		
		if (simpleDemo == false) {
			//circleList.emplace_back(400, 200, 20);
			rectList.emplace_back(300, 300, 20);
		} else {
			
			for (int i = 20; i < width; i += 80) {
				circleList.emplace_back(i + widthOff, 20 + heightOff, 20);
			}
			
			for (int i = 100; i < height - 80; i += 80) {
				circleList.emplace_back(20 + widthOff, i + heightOff, 20);
			}
			
			for (int i = 20; i < width; i += 80) {
				rectList.emplace_back(i + widthOff, height - 20 + heightOff, 20);
			}
			
			rectList.emplace_back(width - 20 + widthOff, height / 2 + heightOff - 80, 20);
			rectList.emplace_back(width - 20 + widthOff, height / 2 + heightOff, 20);
			
			for (int i = 100; i < height - 80; i += 80) {
				rectList.emplace_back(width - 20 + widthOff, i + heightOff, 20);
			}
		}

		bool left = false;

		while (window.isOpen()) {
			window.clear();

			sf::Event event{};
			sf::Mouse::Button mouseButton;
			sf::Keyboard::Key Key;

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
					case sf::Event::KeyPressed :
						Key = event.key.code;
						
						switch (Key) {
							case sf::Keyboard::Left :
								object.keyPress(directions::LEFT);
								break;
							case sf::Keyboard::Right :
								object.keyPress(directions::RIGHT);
								break;
							case sf::Keyboard::Up :
								object.keyPress(directions::UP);
								break;
							case sf::Keyboard::Down :
								object.keyPress(directions::DOWN);
								break;
							default:
								break;
						}
						break;
					case sf::Event::KeyReleased :
						Key = event.key.code;
						
						switch (Key) {
							case sf::Keyboard::Left :
								object.keyReleased(directions::LEFT);
								break;
							case sf::Keyboard::Right :
								object.keyReleased(directions::RIGHT);
								break;
							case sf::Keyboard::Up :
								object.keyReleased(directions::UP);
								break;
							case sf::Keyboard::Down :
								object.keyReleased(directions::DOWN);
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

			for (auto &circle : circleList) {
				circle.setColor(sf::Color::Green);
			}
			for (auto &r : rectList) {
				r.setColor(sf::Color::Green);
			}

			Vec2f useless;

			int count = 0;
			PhysicalObject *target;
			Vec2f frameMove = object.getMove();
			Circle nextCircle = object.getCircle();
			Hit hit;

			do {
				target = collisionDetector.getClosetObject(nextCircle, frameMove, hit);

				if (target != nullptr) {

					target->hit(object);

					frameMove = hit.getReactionVec(object.hit(*target), useless);

					StaticLine line(nextCircle.position, nextCircle.position + hit.getVecToTarget(), sf::Color::Red);

					nextCircle.position = nextCircle.position + hit.getVecToTarget();

					sf::CircleShape circleShape;
					circleShape.setRadius(nextCircle.rayon);
					circleShape.setOrigin(nextCircle.rayon, nextCircle.rayon);
					circleShape.setPosition(nextCircle.position.x, nextCircle.position.y);
					circleShape.setFillColor(sf::Color::Yellow);

					window.draw(circleShape);

					line.draw(&window);
				}else{
					sf::CircleShape circleShape;
					circleShape.setRadius(nextCircle.rayon);
					circleShape.setOrigin(nextCircle.rayon, nextCircle.rayon);
					circleShape.setPosition(nextCircle.position.x + frameMove.x, nextCircle.position.y + frameMove.y);
					circleShape.setFillColor(sf::Color::Magenta);

					window.draw(circleShape);

					StaticLine line(nextCircle.position, nextCircle.position + frameMove, sf::Color::Red);
					line.draw(&window);
				}

				count++;
			} while (target != nullptr && count < 500);

			for (auto &r : rectList) {
				r.draw(&window);
			}

			for(auto &c : circleList){
				c.draw(&window);
			}

			object.draw(&window);

			sf::Text text(std::to_string(count), font);
			text.setCharacterSize(30);
			text.setStyle(sf::Text::Bold);
			text.setFillColor(sf::Color::Red);

			window.draw(text);
			
			window.display();
		}
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>
#include <BlobEngine/Hit.hpp>

#include <BlobEngine/CollisionDetector.hpp>

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

class MainCircle {
private:
	sf::CircleShape circleShape;
	std::array<bool, 4> command = {false, false, false, false};
	sf::Clock clock;
	Circle mainCircle;
	Vec2f speed;
	
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
			mainCircle.position = mainCircle.position + Acceleration.setLength(200) * TimeFlow;
		}
		
		circleShape.setPosition(mainCircle.position.x, mainCircle.position.y);
	}
	
public:

	explicit MainCircle(int x, int y, int r, int mx, int my) {
		
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
	
	explicit StaticCircle(int x, int y, int r) : CircleStatic(0) {
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
		font.loadFromFile("FFFFORWA.TTF");

		CollisionDetector collisionDetector;

		MainCircle object(300, 300, 20, 300, 300);

		std::list<StaticCircle> circleList;
		std::list<StaticRect> rectList;

		bool simpleDemo = true;

		if (simpleDemo == true) {
			circleList.emplace_back(400, 200, 20);
			//rectList.emplace_back(340, 300, 20);
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
							case sf::Keyboard::Q :
								object.keyPress(directions::LEFT);
								break;
							case sf::Keyboard::Right :
							case sf::Keyboard::D :
								object.keyPress(directions::RIGHT);
								break;
							case sf::Keyboard::Up :
							case sf::Keyboard::Z :
								object.keyPress(directions::UP);
								break;
							case sf::Keyboard::Down :
							case sf::Keyboard::S :
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
							case sf::Keyboard::Q :
								object.keyReleased(directions::LEFT);
								break;
							case sf::Keyboard::Right :
							case sf::Keyboard::D :
								object.keyReleased(directions::RIGHT);
								break;
							case sf::Keyboard::Up :
							case sf::Keyboard::Z :
								object.keyReleased(directions::UP);
								break;
							case sf::Keyboard::Down :
							case sf::Keyboard::S :
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

			std::list<Point2f> posHist;

			PhysicalObject *target;
			Vec2f frameMove = object.getMove();
			Circle nextCircle = object.getCircle();
			Hit hit;

			do {
				target = collisionDetector.getClosetObject(nextCircle, frameMove, hit);

				if (target != nullptr) {
					
					if (!hit.superpositionOnTarget()) {
						frameMove = hit.getReactionVec(ROLL, useless);

						StaticLine line(nextCircle.position, hit.getHitPoint(), sf::Color::Red);

						nextCircle.position = hit.getHitPoint();
						posHist.push_back(hit.getHitPoint());

						sf::CircleShape circleShape;
						circleShape.setRadius(nextCircle.rayon);
						circleShape.setOrigin(nextCircle.rayon, nextCircle.rayon);
						circleShape.setPosition(nextCircle.position.x, nextCircle.position.y);
						circleShape.setFillColor(sf::Color::Yellow);
						
						window.draw(circleShape);
						
						line.draw(&window);
					} else {
						StaticLine line(nextCircle.position, hit.getRectificationPosition(), sf::Color::Red);
						
						nextCircle.position = hit.getRectificationPosition();
						
						sf::CircleShape circleShape;
						circleShape.setRadius(nextCircle.rayon);
						circleShape.setOrigin(nextCircle.rayon, nextCircle.rayon);
						circleShape.setPosition(nextCircle.position.x, nextCircle.position.y);
						circleShape.setFillColor(sf::Color::Yellow);
						
						window.draw(circleShape);
						
						line.draw(&window);
					}
					
				}else{
					sf::CircleShape circleShape;
					circleShape.setRadius(nextCircle.rayon);
					circleShape.setOrigin(nextCircle.rayon, nextCircle.rayon);
					circleShape.setPosition((nextCircle.position.x + frameMove.x),
											(nextCircle.position.y + frameMove.y));
					circleShape.setFillColor(sf::Color::Magenta);

					window.draw(circleShape);

					StaticLine line(nextCircle.position, nextCircle.position + frameMove, sf::Color::Red);
					line.draw(&window);
				}

				count++;
			} while (target != nullptr && count < 30);

			for (auto &r : rectList) {
				r.draw(&window);
			}

			for(auto &c : circleList){
				c.draw(&window);
			}

			object.draw(&window);

			sf::Text text("Number of hit : " + std::to_string(count), font);
			text.setCharacterSize(30);
			text.setStyle(sf::Text::Bold);
			text.setFillColor(sf::Color::Red);
			text.setPosition(10, 10);
			window.draw(text);

			text.setString("(coorX, coorY)");
			text.setCharacterSize(12);
			text.setStyle(sf::Text::Regular);
			text.setFillColor(sf::Color::White);

			int num = 0;
			for (Point2f pos : posHist) {
				text.setString("(" + std::to_string(pos.x) + ", " + std::to_string(pos.y) + ")");
				text.setPosition(10, 50 + num * 20);
				window.draw(text);
				num++;
			}

			text.setString(std::to_string(object.getCircle().position.x) + ":" +
						   std::to_string(object.getCircle().position.y));
			text.setCharacterSize(10);
			text.setFillColor(sf::Color::Blue);
			text.setStyle(sf::Text::Regular);
			text.setPosition(object.getCircle().position.x, object.getCircle().position.y);
			window.draw(text);
			
			window.display();

			if (count == 500) {

			}
		}
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
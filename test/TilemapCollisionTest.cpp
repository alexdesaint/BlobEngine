#include <iostream>
#include <list>
#include <deque>
#include <SFML/Graphics.hpp>
#include <BlobEngine/Geometrie.hpp>
#include <BlobEngine/Collision/CollisionDetector.hpp>

using namespace BlobEngine;

enum directions{
	UP = 0,
	DOWN = 1,
	LEFT = 2,
	RIGHT = 3
};

class MainRect : public RectDynamic {
private:
	sf::RectangleShape shape;
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
			speed = Acceleration.setLength(100);
		} else
			speed.reset();

		shape.setPosition(position.x, position.y);
	}

public:

	explicit MainRect(int x, int y, int r) : RectDynamic(0) {
		position = {(float)x, (float)y};
		size = {(float)r, (float)r};

		shape.setSize(sf::Vector2f(r, r));
		//shape.setOrigin(r, r);
		shape.setPosition(sf::Vector2f(x, y));
		shape.setFillColor(sf::Color(255, 0, 0));
	}

	void draw(sf::RenderWindow *window) {
		update();

		window->draw(shape);
	}

	//void setDestination(int x, int y) {
	//	speed = Vec2f(mainCircle.position, Point2f(x, y));
	//}

	void setColor(sf::Color c) {
		shape.setFillColor(c);
	}

	void keyPress(directions d) {
		command[d] = true;
	}

	void keyReleased(directions d) {
		command[d] = false;
	}
};


class Box : public RectStatic {
private:
	sf::RectangleShape shape;

public:
	explicit Box(int x, int y, int r) : RectStatic(0) {
		position = {(float)x, (float)y};
		size = {(float)r, (float)r};

		shape.setSize(sf::Vector2f(r, r));
		//shape.setOrigin(r, r);
		shape.setPosition(sf::Vector2f(x, y));
		shape.setFillColor(sf::Color(255, 0, 0));
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

		MainRect object(200, 200, 20);

		std::list<Box> rectanges;

		rectanges.emplace_back(110, 100, 10);
		rectanges.emplace_back(100, 110, 10);
		rectanges.emplace_back(100, 100, 10);
		rectanges.emplace_back(100, 120, 10);

		CollisionDetector collisionDetector;

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

			for(auto &rect : rectanges) {
				rect.draw(&window);
			}

			object.draw(&window);

			char buff[100];
			snprintf(buff, sizeof(buff), "%0.2f : %0.2f", object.position.x , object.position.y);

			collisionDetector.update();

			sf::Text text(buff, font);
			text.setPosition(0, 20);
			text.setCharacterSize(12);
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
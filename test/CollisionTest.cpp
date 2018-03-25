#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>
#include <BlobEngine/CollisionDetector.hpp>

using namespace BlobEngine;

enum directions{
	UP = 0,
	DOWN = 1,
	LEFT = 2,
	RIGHT = 3
};

class Box : public LineStatic {
private:
	sf::RectangleShape shape;

	int colorState = 0;

	Reaction hit(const BlobEngine::PhysicalObject& from) {

		sf::Color c = shape.getFillColor();

		switch (colorState){
			case 0 :
				c.r-=15;
				c.g+=15;

				if(c.g == 255)
					colorState = 1;
				break;
			case 1 :
				c.g-=15;
				c.b+=15;

				if(c.b == 255)
					colorState = 2;
				break;
			case 2 :
				c.b-=15;
				c.r+=15;

				if(c.r == 255)
					colorState = 0;
				break;
		}

		shape.setFillColor(c);

		return IGNORE;
	}

public:
	explicit Box(Point2f position) : LineStatic(0) {

		shape.setSize(sf::Vector2f(20, 20));
		shape.setOrigin(10, 10);
		shape.setPosition(sf::Vector2f(position.x, position.y));
		shape.setFillColor(sf::Color(255, 0, 0));

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

class Box2 : public CircleStatic{
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

class BounceBall : public CircleDynamic{
private:
	float maxSpeed, orientation;
	sf::CircleShape shape;

	Reaction hit(const BlobEngine::PhysicalObject& from) override {
		return BOUNCE;
	}
public:

	explicit BounceBall(int x, int y, int r) : CircleDynamic(0) {

		speed.x = 400;
		speed.y = 400;

		mainCircle.position.x = x;
		mainCircle.position.y = y;
		mainCircle.rayon = r;
		orientation = 0;

		shape.setRadius(mainCircle.rayon);
		shape.setOrigin(10, 10);
		shape.setPosition(sf::Vector2f(mainCircle.position.x, mainCircle.position.y));
		maxSpeed = 200;
	}

	void draw(sf::RenderWindow *window) {
		shape.setPosition(sf::Vector2f(mainCircle.position.x, mainCircle.position.y));
		window->draw(shape);
	}
};

class Player : public CircleDynamic{
private:
	float maxSpeed;
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
			speed = Acceleration.setLength(maxSpeed);
		}
		else {
			speed = Vec2f();
		}
	}
public:

	explicit Player(int x, int y, int r) : CircleDynamic(0) {
		mainCircle.position.x = x;
		mainCircle.position.y = y;
		mainCircle.rayon = r;

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

		unsigned int width = 620, height = 220;

		sf::RenderWindow window(sf::VideoMode(width, height), "BlobEngine test", sf::Style::Close, settings);
		window.setFramerateLimit(60);

		CollisionDetector collisionDetector;

		std::list<Box> boxs;

		Player player(width/2, height/4, 10);

		BounceBall bounceBall(width/2, 3*height/4, 10);

		Box2 box1(Point2f(width/4, height/2));

		Box2 box2(Point2f(width/2, height/2));

		Box2 box3(Point2f(3*width/4, height/2));

		for (int i = 0; i < width; i += 20) {
			boxs.emplace_back(Point2f(10 + i, 10));
			boxs.emplace_back(Point2f(10 + i, height - 10));
		}

		for (int i = 20; i < height - 20; i += 20) {
			boxs.emplace_back(Point2f(10, 10 + i));
			boxs.emplace_back(Point2f(width - 10, 10 + i));
		}
		
		for (int i = 40; i < height - 40; i += 40) {
			boxs.emplace_back(Point2f(50, 10 + i));
			boxs.emplace_back(Point2f(width - 50, 10 + i));
		}

		int count = 0;

		while (window.isOpen()) {
			window.clear();

			sf::Keyboard::Key Key;
			sf::Event event{};
			sf::Mouse::Button mouseButton;

			while (window.pollEvent(event)) {
				switch (event.type) {
					case sf::Event::Closed :
						window.close();
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
					default:
						break;
				}
			}

			collisionDetector.update();

			if(count == 60){
				window.setTitle(sf::String(std::to_string(collisionDetector.getFPS())));
				count = 0;
			}
			count++;

			for (auto &box : boxs) {
				box.draw(&window);
			}

			player.draw(&window);

			bounceBall.draw(&window);

			box1.draw(&window);
			box2.draw(&window);
			box3.draw(&window);

			window.display();
		}
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
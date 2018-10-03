#include <Box2D/Box2D.h>
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <BlobEngine/Geometrie.hpp>

using namespace BlobEngine;

enum directions{
	UP = 0,
	DOWN = 1,
	LEFT = 2,
	RIGHT = 3
};

class StaticCircle {
private:
	sf::CircleShape circleShape;

	b2BodyDef bodyDef;
	b2Body* body;
	b2CircleShape b2Shape;

	Vec2f position;
	float rayon;

public:

	StaticCircle(int x, int y, float r, b2World &world) {
		position.x = x;
		position.y = y;
		rayon = r;

		circleShape.setRadius(r);
		circleShape.setOrigin(rayon, rayon);
		circleShape.setPosition(position.x, position.y);
		circleShape.setFillColor(sf::Color::Green);

		bodyDef.position.Set(x, y);
		body = world.CreateBody(&bodyDef);
		b2Shape.m_radius = r;
		body->CreateFixture(&b2Shape, 0.0f);
	}

	void draw(sf::RenderWindow *window) {
		window->draw(circleShape);
	}

	void setColor(sf::Color c){
		circleShape.setFillColor(c);
	}
};

class StaticRect {
private:
	sf::RectangleShape shape;

	b2BodyDef groundBodyDef;
	b2Body* body;
	b2PolygonShape b2Shape;

public:

	StaticRect(int x, int y, int w, int h, b2World &world) {

		shape.setSize(sf::Vector2f(2 * w, 2 * h));
		shape.setOrigin(w, h);
		shape.setPosition(sf::Vector2f(x, y));
		shape.setFillColor(sf::Color(255, 0, 0));

		groundBodyDef.position.Set(x, y);
		body = world.CreateBody(&groundBodyDef);
		b2Shape.SetAsBox(w, h);
		body->CreateFixture(&b2Shape, 0.0f);
	}

	void draw(sf::RenderWindow *window){
		window->draw(shape);
	}

	void setColor(sf::Color c){
		shape.setFillColor(c);
	}
};

class DynamicRect {
private:
	sf::RectangleShape shape;

	b2BodyDef bodyDef;
	b2Body* body;
	b2PolygonShape b2Shape;

	std::array<bool, 4> command = {false, false, false, false};
	Vec2f speed;
	float maxSpeed = 50;

	void update() {
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
		body->SetLinearVelocity(b2Vec2(speed.x, speed.y));
	}
public:

	DynamicRect(int x, int y, int w, int h, b2World &world) {

		shape.setSize(sf::Vector2f(2 * w, 2 * h));
		shape.setOrigin(w, h);
		shape.setPosition(sf::Vector2f(x, y));
		shape.setFillColor(sf::Color(255, 0, 0));


		bodyDef.type = b2_dynamicBody;
		bodyDef.position.Set(x, y);
		body = world.CreateBody(&bodyDef);

		b2Shape.SetAsBox(w, h);

		b2FixtureDef fixtureDef;
		fixtureDef.shape = &b2Shape;
		fixtureDef.density = 1.0f;
		fixtureDef.friction = 0;
		body->CreateFixture(&fixtureDef);
	}

	void draw(sf::RenderWindow *window){
		b2Vec2 position = body->GetPosition();
		shape.setPosition(sf::Vector2f(position.x, position.y));

		float32 angle = body->GetAngle() * (180.0f/b2_pi);
		shape.setRotation(angle);

		window->draw(shape);
	}

	void setColor(sf::Color c){
		shape.setFillColor(c);
	}

	void keyPress(directions d) {
		command[d] = true;
		update();
	}

	void keyReleased(directions d) {
		command[d] = false;
		update();
	}
};

int main(int argc, char** argv) {
	B2_NOT_USED(argc);
	B2_NOT_USED(argv);

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	unsigned int windowWidth = 600, windowHeight = 600, width = 440, height = 440, widthOff =
			(windowWidth - width) / 2, heightOff = (windowHeight - height) / 2;

	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "BlobEngine test", sf::Style::Close,
							settings);
	window.setFramerateLimit(60);

	b2Vec2 gravity(0.0f, 0.0f);
	b2World world(gravity);

	StaticRect ground(55, 100, 100, 10, world);

	StaticCircle plot(200, 200, 10, world);

	DynamicRect player(0, 0, 10, 10, world);

	// This is our little game loop.
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

		world.Step(1.f/60.f, 8, 3);

		ground.draw(&window);
		plot.draw(&window);
		player.draw(&window);

		window.display();
	}

	// When the world destructor is called, all bodies and joints are freed. This can
	// create orphaned pointers, so be careful about your world management.

	return 0;
}
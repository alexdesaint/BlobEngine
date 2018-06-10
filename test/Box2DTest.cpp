#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

int main(int argc, char **argv) {
	B2_NOT_USED(argc);
	B2_NOT_USED(argv);

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(600, 600), "BlobEngine test", sf::Style::Close, settings);
	window.setFramerateLimit(60);

	b2Vec2 gravity(0.0f, 10.0f);// Define the gravity vector.
	

	b2World world(gravity);// Construct a world object
	
	// Define the ground body.
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f, 500);

	sf::RectangleShape ground;
	ground.setPosition(0, 500);

	b2Body *groundBody = world.CreateBody(&groundBodyDef);

	b2PolygonShape groundBox;// Define the ground box shape.

	groundBox.SetAsBox(50.0f, 10.0f);// The extents are the half-widths of the box.
	ground.setSize(sf::Vector2f(100, 20));
	ground.setOrigin(ground.getSize().x/2, ground.getSize().y/2);

	// Add the ground fixture to the ground body.
	groundBody->CreateFixture(&groundBox, 0.0f);

	/***********************************************************************************************************/

	// Define the dynamic body. We set its position and call the body factory.
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(20, 4.0f);
	b2Body *body = world.CreateBody(&bodyDef);

	sf::RectangleShape bodyShape(sf::Vector2f(bodyDef.position.x, bodyDef.position.y));
	bodyShape.setSize(sf::Vector2f(20, 20));
	bodyShape.setOrigin(bodyShape.getSize().x/2, bodyShape.getSize().y/2);

	// Define another box shape for our dynamic body.
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(10, 10);
	
	// Define the dynamic body fixture.
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	
	// Set the box density to be non-zero, so it will be dynamic.
	fixtureDef.density = 1.0f;
	
	// Override the default friction.
	fixtureDef.friction = 0.3f;
	
	// Add the shape to the body.
	body->CreateFixture(&fixtureDef);
	
	// Prepare for simulation. Typically we use a time step of 1/60 of a
	// second (60Hz) and 10 iterations. This provides a high quality simulation
	// in most game scenarios.
	float32 timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;
	
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
						case sf::Keyboard::Q :
							body->ApplyForce({-10000, 0}, body->GetLocalCenter(), true);
							break;
						case sf::Keyboard::Right :
						case sf::Keyboard::D :
							body->ApplyForce({10000, 0}, {0, 0}, true);
							break;
						case sf::Keyboard::Up :
						case sf::Keyboard::Z :
							break;
						case sf::Keyboard::Down :
						case sf::Keyboard::S :
							body->ApplyAngularImpulse(100, true);
							break;
						default:
							break;
					}
					break;
			}
		}

		world.Step(timeStep, velocityIterations, positionIterations);
		
		b2Vec2 position = body->GetPosition();

		bodyShape.setPosition(position.x, position.y);
		bodyShape.setRotation(body->GetAngle() * 57.295779513082320876798154814105f);

		window.draw(ground);
		window.draw(bodyShape);

		window.display();
	}
	
	// When the world destructor is called, all bodies and joints are freed. This can
	// create orphaned pointers, so be careful about your world management.
	
	return 0;
}

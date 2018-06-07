#include <SFML/Graphics.hpp>
#include <BlobEngine/Geometrie.hpp>

using namespace BlobEngine;

/// A manifold point is a contact point belonging to a contact
/// manifold. It holds details related to the geometry and dynamics
/// of the contact points.
/// The local point usage depends on the manifold type:
/// -e_circles: the local center of circleB
/// -e_faceA: the local center of cirlceB or the clip point of polygonB
/// -e_faceB: the clip point of polygonA
/// This structure is stored across time steps, so we keep it small.
/// Note: the impulses are used for internal caching and may not
/// provide reliable contact forces, especially for high speed collisions.
struct b2ManifoldPoint {
	Vec2f localPoint;        ///< usage depends on manifold type
	float normalImpulse;    ///< the non-penetration impulse
	float tangentImpulse;    ///< the friction impulse
	b2ContactID id;            ///< uniquely identifies a contact point between two shapes
};

/// A manifold for two touching convex shapes.
/// Box2D supports multiple types of contact:
/// - clip point versus plane with radius
/// - point versus point with radius (circles)
/// The local point usage depends on the manifold type:
/// -e_circles: the local center of circleA
/// -e_faceA: the center of faceA
/// -e_faceB: the center of faceB
/// Similarly the local normal usage:
/// -e_circles: not used
/// -e_faceA: the normal on polygonA
/// -e_faceB: the normal on polygonB
/// We store contacts in this way so that position correction can
/// account for movement, which is critical for continuous physics.
/// All contact scenarios must be expressed in one of these types.
/// This structure is stored across time steps, so we keep it small.
struct b2Manifold {
	enum Type {
		e_circles,
		e_faceA,
		e_faceB
	};

	b2ManifoldPoint points[2];    ///< the points of contact
	Vec2f localNormal;                                ///< not use for Type::e_points
	Vec2f localPoint;                                ///< usage depends on manifold type
	Type type;
	int32_t pointCount;                                ///< the number of manifold points
};

void b2CollideCircles(
		b2Manifold *manifold,
		const b2CircleShape *circleA, const b2Transform &xfA,
		const b2CircleShape *circleB, const b2Transform &xfB) {
	manifold->pointCount = 0;

	Vec2f pA = b2Mul(xfA, circleA->m_p);
	Vec2f pB = b2Mul(xfB, circleB->m_p);

	Vec2f d = pB - pA;
	float distSqr = b2Dot(d, d);
	float rA = circleA->m_radius, rB = circleB->m_radius;
	float radius = rA + rB;
	if (distSqr > radius * radius) {
		return;
	}

	manifold->type = b2Manifold::e_circles;
	manifold->localPoint = circleA->m_p;
	manifold->localNormal.reset();
	manifold->pointCount = 1;

	manifold->points[0].localPoint = circleB->m_p;
	manifold->points[0].id.key = 0;
}

int main(int argc, char **argv) {

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(600, 600), "BlobEngine test", sf::Style::Close, settings);
	window.setFramerateLimit(60);


	sf::RectangleShape ground;
	ground.setPosition(0, 500);

	ground.setSize(sf::Vector2f(100, 20));
	ground.setOrigin(ground.getSize().x/2, ground.getSize().y/2);

	sf::RectangleShape bodyShape(sf::Vector2f(10, 10));
	bodyShape.setSize(sf::Vector2f(20, 20));
	bodyShape.setOrigin(bodyShape.getSize().x/2, bodyShape.getSize().y/2);

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
							break;
						case sf::Keyboard::Right :
						case sf::Keyboard::D :
							break;
						case sf::Keyboard::Up :
						case sf::Keyboard::Z :
							break;
						case sf::Keyboard::Down :
						case sf::Keyboard::S :
							break;
						default:
							break;
					}
					break;
			}
		}

		//bodyShape.setPosition(position.x, position.y);
		//bodyShape.setRotation(body->GetAngle() * 57.295779513082320876798154814105f);

		window.draw(ground);
		window.draw(bodyShape);

		window.display();
	}

	// When the world destructor is called, all bodies and joints are freed. This can
	// create orphaned pointers, so be careful about your world management.

	return 0;
}

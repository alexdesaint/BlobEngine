#include <SFML/Graphics.hpp>
#include <BlobEngine/Geometrie.hpp>
#include <cmath>

using namespace BlobEngine;

class TransMat {
public:
	float x, y, s, c;
	
	Vec2f operator*(Vec2f v) {
		return {
				(c * v.x - s * v.y) + x,
				(s * v.x + c * v.y) + y
		};
	}

private:
};

bool CollideCircles(
		Circle circleA, TransMat &xfA,
		Circle circleB, TransMat &xfB) {
	
	Vec2f pA = xfA * circleA.position;
	Vec2f pB = xfB * circleB.position;

	Vec2f d = pB - pA;
	float distSqr = d.scalaire(d);
	float rA = circleA.rayon, rB = circleB.rayon;
	float radius = rA + rB;
	
	return distSqr <= radius * radius;
}

struct b2RayCastOutput {
	Vec2f normal;
	float fraction;
};

struct b2RayCastInput {
	Vec2f p1, p2;
	float maxFraction;
};

bool
RayCast(b2RayCastOutput *output, const b2RayCastInput &input, const TransMat &transform, Vec2f p, float rayon) const {
	
	Vec2f position = Vec2f(transform.x, transform.y) +
					 Vec2f(transform.c * p.x - transform.s * p.y, transform.s * p.x + transform.c * p.y);
	Vec2f s = input.p1 - position;
	float b = s.scalaire(s) - rayon * rayon;
	
	// Solve quadratic equation.
	Vec2f r = input.p2 - input.p1;
	float c = s.scalaire(r);
	float rr = r.scalaire(r);
	float sigma = c * c - rr * b;
	
	// Check for negative discriminant and short segment.
	if (sigma < 0.0f || rr < FLT_EPSILON) {
		return false;
	}
	
	// Find the point of intersection of the line with the circle.
	float a = -(c + sqrt(sigma));
	
	// Is the intersection point on the segment?
	if (0.0f <= a && a <= input.maxFraction * rr) {
		a /= rr;
		output->fraction = a;
		output->normal = (s + r * a).getNormal();
		return true;
	}
	
	return false;
}

int main(int argc, char **argv) {

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(600, 600), "BlobEngine test", sf::Style::Close, settings);
	window.setFramerateLimit(60);
	
	Circle circle1({20, 20}, 10), circle2({20, 60}, 10);
	sf::CircleShape circleShape1, circleShape2;
	
	circleShape1.setRadius(circle1.rayon);
	circleShape2.setRadius(circle2.rayon);
	circleShape1.setPosition(circle1.position.x, circle1.position.y);
	circleShape2.setPosition(circle2.position.x, circle2.position.y);
	circleShape1.setOrigin(circle1.rayon, circle1.rayon);
	circleShape2.setOrigin(circle1.rayon, circle1.rayon);
	
	TransMat transMat1 = {0, 0, 0, 1}, transMat2 = {0, 0, 0, 1};
	
	bool left = false;
	
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
				case sf::Event::KeyReleased :
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
				default:
					break;
			}
		}
		
		if (left) {
			transMat1.x = sf::Mouse::getPosition(window).x - circle1.position.x;
			transMat1.y = sf::Mouse::getPosition(window).y - circle1.position.y;
		}
		
		if (CollideCircles(circle1, transMat1, circle2, transMat2))
			circleShape1.setFillColor(sf::Color::Red);
		else
			circleShape1.setFillColor(sf::Color::Green);
		
		circleShape1.setRadius(circle1.rayon);
		circleShape2.setRadius(circle2.rayon);
		circleShape1.setPosition(circle1.position.x, circle1.position.y);
		circleShape2.setPosition(circle2.position.x, circle2.position.y);
		circleShape1.setOrigin(circle1.rayon, circle1.rayon);
		circleShape2.setOrigin(circle1.rayon, circle1.rayon);
		
		window.draw(circleShape1);
		window.draw(circleShape2);

		window.display();
	}

	return 0;
}

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../src/CollisionClass.hpp"

using namespace Geometrie;
using namespace Physics;

class CircleObject{
private:
public:
	Circle circle;
	sf::CircleShape circleShape;
	Vec2f move;

	explicit CircleObject(int x, int y, int r, int mx, int my) {
		move.x = mx;
		move.y = my;

		circle.position.x = x;
		circle.position.y = y;
		circle.rayon = r;

		circleShape.setRadius(r);
		circleShape.setOrigin(circle.rayon / 2, circle.rayon / 2);
		circleShape.setPosition(circle.position.x, circle.position.y);
		circleShape.setFillColor(sf::Color::Green);
	}

	void draw(sf::RenderWindow *window){
		window->draw(circleShape);
	}

	Circle getCircle(){
		return circle;
	}

	Vec2f getMove(){
		return move;
	}
};

class CircleTarget{
private:
public:
	Circle circle;
	sf::CircleShape circleShape;

	explicit CircleTarget(int x, int y, int r) {
		circle.position.x = x;
		circle.position.y = y;
		circle.rayon = r;

		circleShape.setRadius(r);
		circleShape.setOrigin(circle.rayon / 2, circle.rayon / 2);
		circleShape.setPosition(circle.position.x, circle.position.y);
		circleShape.setFillColor(sf::Color::Red);
	}

	void draw(sf::RenderWindow *window){
		window->draw(circleShape);
	}

	Circle getCircle(){
		return circle;
	}
};

int main() {

	sf::RenderWindow window(sf::VideoMode(400, 400), "BlobEngine test");

	CircleObject object(10, 10,10, 20, 20);
	CircleTarget target(40, 40,10);

	Collision c(object.getCircle(), target.getCircle(), object.getMove());

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		object.draw(&window);
		target.draw(&window);
		window.display();
	}

	return 0;
}
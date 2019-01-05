#ifndef BOMBERMAN_EXPLOSION_HPP
#define BOMBERMAN_EXPLOSION_HPP

#include <SFML/Graphics.hpp>

#include <BomberBlob/DynamicCircle.hpp>

class Explosion : DynamicCircle{
private:
	sf::CircleShape shape;
	sf::RectangleShape rectShape;
	sf::Texture texture;
	sf::Clock clock;
	b2Vec2 positionInitial;
	float maxSpeed = 2000000, distanceMax = 200, rayon;
	bool arrived = false;
	UserData userData = {EXPLOSION, this};

	bool update();

public:
	explicit Explosion(b2Vec2 positionInitial, b2Vec2 dirrection, float distanceMax, b2World *world);

	bool draw(sf::RenderWindow *window);
};


#endif //BOMBERMAN_EXPLOSION_HPP

#ifndef BOMBERMAN_BOMB_HPP
#define BOMBERMAN_BOMB_HPP

#include <BomberBlob/StaticCircle.hpp>
#include <BomberBlob/UserData.hpp>

#include <SFML/Graphics.hpp>

class Bomb : StaticCircle{
private:
	sf::CircleShape shape;
	sf::Texture texture;
	sf::Clock clock;
	float timeDelay = 2;
	bool destroyed = false, playerOnBomb = true, bombAlone = false;

	UserData userData = {BOMB, this};

	b2Vec2 position;

	bool update();

public:
	explicit Bomb(b2Vec2 p, b2World *world);

	bool draw(sf::RenderWindow *window);

	b2Vec2 getPosition(){
		return position;
	}

	void hit() {
		destroyed = true;
	}

	bool bombNotFree() {
		if(bombAlone)
			return false;
		playerOnBomb = true;
		return playerOnBomb;
	}
};


#endif //BOMBERMAN_BOMB_HPP

#ifndef BOMBERMAN_BOMBMANAGER_HPP
#define BOMBERMAN_BOMBMANAGER_HPP

#include <list>

#include <SFML/Graphics.hpp>

#include <Box2D/Box2D.h>
#include <BomberBlob/Bomb.hpp>
#include <BomberBlob/Explosion.hpp>

class BombManager{
private:

	b2World *world;
	std::list<Bomb>	bombs;
	std::list<Explosion> explosions;

	float explosionLenght = 100;

public:

	explicit BombManager(b2World *w) : world(w) {}

	void addBomb(b2Vec2 pos){
		bombs.emplace_front(pos, world);
	}

	void draw(sf::RenderWindow *window);
};


#endif //BOMBERMAN_BOMBMANAGER_HPP

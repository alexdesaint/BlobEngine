#include <BomberBlob/BombManager.hpp>

void BombManager::draw(sf::RenderWindow *window) {

	unsigned int bombsToDestroy = 0, explosionsToDestroy = 0;

	auto bombIt = bombs.begin();
	while(bombIt != bombs.end()){
		if(bombIt->draw(window)){
			explosions.emplace_back(bombs.back().getPosition(), b2Vec2(0, 1), 100, world);
			explosions.emplace_back(bombs.back().getPosition(), b2Vec2(1, 0), 100, world);
			explosions.emplace_back(bombs.back().getPosition(), b2Vec2(0, -1), 100, world);
			explosions.emplace_back(bombs.back().getPosition(), b2Vec2(-1, 0), 100, world);


			bombIt = bombs.erase(bombIt);
		}else
			bombIt++;
	}

	auto explosionIt = explosions.begin();
	while(explosionIt != explosions.end()){
		if(explosionIt->draw(window)){
			explosionIt = explosions.erase(explosionIt);
		}else
			explosionIt++;
	}
}

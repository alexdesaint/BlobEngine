#ifndef BOMBERMAN_BOMB_HPP
#define BOMBERMAN_BOMB_HPP

#include <BlobEngine/Collision/CollisionDetector.hpp>
#include <BlobEngine/BlobGL/Form.hpp>

#include <BomberBlob/UserData.hpp>

#include <list>

class Player;

class Bomb : public BlobEngine::RectStatic, public BlobEngine::BlobGL::Cube {
private:
	float timeDelay = 2;
	bool destroyed = false, playerOnBomb = true, bombAlone = false;

	UserData userData = {BOMB, this};

	std::list<Bomb>::iterator elementIt{};

	Player &player;

public:
	explicit Bomb(float x, float y, Player &player);

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

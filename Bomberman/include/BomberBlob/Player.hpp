#ifndef BOMBERMAN_PLAYER_HPP
#define BOMBERMAN_PLAYER_HPP

#include <BlobEngine/Collision/CollisionDetector.hpp>
#include <BlobEngine/BlobGL/Form.hpp>

#include <BomberBlob/UserData.hpp>

#include <array>
#include <list>

#include <BomberBlob/BombManager.hpp>

class Player : public BlobEngine::Collision::RectDynamic, public BlobEngine::BlobGL::Cube {
	friend BombManager;
public:
	enum Actions {
		up = 0,
		down,
		right,
		left,
		putBomb,
		numOfActions
	};
private:
	float maxSpeed = 2.5f, bombPower = 2.f;
	bool alive = true, onBomb = false;

	unsigned int maxBomb = 1, bombPosed = 0;

	std::array<const bool*, Actions::numOfActions> keys;

	std::list<BombManager> &bombs;

	BombManager *lastBomb;
public:

	Player(float x, float y, std::list<BombManager> &bombs);

	void preCollisionUpdate() final;

	void postCollisionUpdate() final;

	Reaction hit(int objectType, const void *objectData) final;

	void setAction(Actions a, const bool *key) {
		keys[a] = key;
	}

	bool isAlive() const {
		return alive;
	}
};


#endif //BOMBERMAN_PLAYER_HPP

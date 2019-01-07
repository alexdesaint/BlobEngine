#ifndef BOMBERMAN_PLAYER_HPP
#define BOMBERMAN_PLAYER_HPP

#include <BlobEngine/Collision/CollisionDetector.hpp>
#include <BlobEngine/BlobGL/Form.hpp>

#include <BomberBlob/UserData.hpp>

#include <array>

#include <BomberBlob/Bomb.hpp>

class Player : public BlobEngine::RectDynamic, public BlobEngine::BlobGL::Cube {
	friend Bomb;
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
	float maxSpeed;
	bool alive = true;

	UserData userData = {PLAYER, this};

	std::array<const bool*, Actions::numOfActions> keys;

	std::list<Bomb> &bombs;
public:

	Player(float x, float y, std::list<Bomb> &bombs);

	void preCollisionUpdate() final;

	void postCollisionUpdate() final;

	Reaction hit(const PhysicalObject &from) final;

	void setAction(Actions a, const bool *key) {
		keys[a] = key;
	}

	//void putBomb() {
	//	bombManager->addBomb(getPositionb2());
	//}

	void hit() {
		alive = false;
	}

	bool isAlive() const {
		return alive;
	}
};


#endif //BOMBERMAN_PLAYER_HPP

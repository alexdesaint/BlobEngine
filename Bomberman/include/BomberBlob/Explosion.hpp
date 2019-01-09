#ifndef BOMBERMAN_EXPLOSION_HPP
#define BOMBERMAN_EXPLOSION_HPP

#include <BlobEngine/Collision/CollisionDetector.hpp>
#include <BlobEngine/BlobGL/Form.hpp>
#include <BlobEngine/Time.hpp>

#include <BomberBlob/UserData.hpp>

class Explosion : public BlobEngine::Collision::RectDynamic, public BlobEngine::BlobGL::Cube {
private:
	BlobEngine::Vec2f positionInitial, dirrection;
	float maxSpeed = 8, distanceMax = 2;
	bool active = true;

public:
	Explosion(BlobEngine::Vec2f positionInitial, BlobEngine::Vec2f dirrection, float distanceMax);

	bool moove() final;

	void postCollisionUpdate() final;

	Reaction hit(int objectType, const void *objectData) final;

	bool isActive() const {
		return active;
	}

};


#endif //BOMBERMAN_EXPLOSION_HPP

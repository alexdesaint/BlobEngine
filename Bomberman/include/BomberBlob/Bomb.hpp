#ifndef BOMBERMAN_BOMB_HPP
#define BOMBERMAN_BOMB_HPP

#include <BlobEngine/Collision/CollisionDetector.hpp>
#include <BlobEngine/BlobGL/Form.hpp>

#include <BomberBlob/UserData.hpp>

class Player;

class Bomb : public BlobEngine::Collision::RectStatic, public BlobEngine::BlobGL::Cube {
private:

	bool destroyed = false;

public:
	explicit Bomb(BlobEngine::Vec2f pos);

	void hit(int objectType, const void *objectData) final;

	bool isDestroyed();
};

#endif //BOMBERMAN_BOMB_HPP

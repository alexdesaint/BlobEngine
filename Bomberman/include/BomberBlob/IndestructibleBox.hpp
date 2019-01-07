#ifndef BOMBERMAN_INDESTRUCTIBLEBOX_HPP
#define BOMBERMAN_INDESTRUCTIBLEBOX_HPP

#include <BlobEngine/Collision/CollisionDetector.hpp>
#include <BlobEngine/BlobGL/Form.hpp>

#include <BomberBlob/UserData.hpp>

class IndestructibleBox : public BlobEngine::RectStatic, public BlobEngine::BlobGL::Cube {
private:
	bool destroyed = false;

	UserData userData = {INDESTRUCTIBLE_BOX, this};

public:
	IndestructibleBox(float x, float y);
};

#endif //BOMBERMAN_INDESTRUCTIBLEBOX_HPP

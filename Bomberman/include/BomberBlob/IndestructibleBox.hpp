#ifndef BOMBERMAN_INDESTRUCTIBLEBOX_HPP
#define BOMBERMAN_INDESTRUCTIBLEBOX_HPP

#include <BlobEngine/Collision/CollisionDetector.hpp>
#include <BlobEngine/BlobGL/Form.hpp>

#include <BomberBlob/UserData.hpp>

class IndestructibleBox : public BlobEngine::Collision::RectStatic, public BlobEngine::BlobGL::Cube {
private:
	bool destroyed = false;

public:
	IndestructibleBox(float x, float y);
};

#endif //BOMBERMAN_INDESTRUCTIBLEBOX_HPP

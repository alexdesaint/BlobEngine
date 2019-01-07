#ifndef BOMBERMAN_BOX_HPP
#define BOMBERMAN_BOX_HPP

#include <BlobEngine/Collision/CollisionDetector.hpp>
#include <BlobEngine/BlobGL/Form.hpp>

#include <BomberBlob/UserData.hpp>

class Box : public BlobEngine::RectStatic, public BlobEngine::BlobGL::Cube {
private:
	bool destroyed = false;

	UserData userData = {BOX, this};

public:
	explicit Box(float x, float y);

	void hit() {
		destroyed = true;
	}
};


#endif //BOMBERMAN_BOX_HPP

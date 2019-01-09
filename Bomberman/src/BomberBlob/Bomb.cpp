#include <BomberBlob/Bomb.hpp>

#include <BomberBlob/Player.hpp>

Bomb::Bomb(BlobEngine::Vec2f pos) : RectStatic(BOMB, this) {
	position = pos;
	size = {0.4f, 0.4f};

	setPosition(pos.x, pos.y, 0.2f);
	setScale(0.4f, 0.4f, 0.4f);

	loadBMPtexture("data/Bomb.bmp");
}

bool Bomb::isDestroyed() {
	return destroyed;
}

void Bomb::hit(int objectType, const void *objectData) {
	if(objectType == EXPLOSION) {
		destroyed = true;
	}
}
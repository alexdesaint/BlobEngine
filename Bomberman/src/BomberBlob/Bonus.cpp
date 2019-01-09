#include <BomberBlob/Bonus.hpp>

#include <random>
#include <iostream>

std::random_device rd;
std::mt19937 mt(rd());
std::uniform_real_distribution<float> dist(0, 5);

Bonus::Bonus(BlobEngine::Vec2f pos) : RectStatic(EXTRABOMB, this) {
	position = pos;
	size = {0.4f, 0.4f};

	setPosition(pos.x, pos.y, 0.2f);
	setScale(0.4f, 0.4f, 0.4f);

	float val = dist(mt);

	if (val < 1) {
		setObjectType(EXTRAPOWER);
		loadBMPtexture("data/ExtraPower.bmp");
	} else if (val < 2) {
		setObjectType(EXTRASPEED);
		loadBMPtexture("data/ExtraSpeed.bmp");
	} else if(val < 3) {
		loadBMPtexture("data/ExtraBomb.bmp");
	} else
		destroyed = true;
	setTextureScale(4);
}

bool Bonus::update() {
	return destroyed;
}

void Bonus::hit(int objectType, const void *objectData) {
	if (objectType == PLAYER) {
		destroyed = true;
	}
}


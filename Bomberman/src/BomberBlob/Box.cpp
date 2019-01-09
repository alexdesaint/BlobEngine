#include <BomberBlob/Box.hpp>

Box::Box(float x, float y) : RectStatic(BOX, this) {
	position = {x, y};
	size = {0.8f, 0.8f};

	setPosition(x, y, 0.4f);
	setScale(0.8f, 0.8f, 0.8f);

	loadBMPtexture("data/box.bmp");
	setTextureScale(4);
}

void Box::hit(int objectType, const void *objectData) {
	if(objectType == EXPLOSION)
		destroyed = true;
}

#include <BomberBlob/IndestructibleBox.hpp>

IndestructibleBox::IndestructibleBox(float x, float y) : RectStatic(INDESTRUCTIBLE_BOX, this) {
	position = {x, y};
	size = {1, 1};

	setPosition(x, y, 0.5f);

	loadBMPtexture("data/IndestructibleBox.bmp");
	setTextureScale(4);
}

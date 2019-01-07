#include <BomberBlob/IndestructibleBox.hpp>

IndestructibleBox::IndestructibleBox(float x, float y) : RectStatic(0) {
	position = {x, y};
	size = {1, 1};

	setPosition(x, y, 0.5f);

	loadBMPtexture("data/IndestructibleBox2.bmp");
	setTextureScale(4);
}

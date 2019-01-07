#include <BomberBlob/Box.hpp>

Box::Box(float x, float y) : RectStatic(0) {
	position = {x, y};
	size = {1, 1};

	setPosition(x, y, 0.5f);

	loadBMPtexture("data/box.bmp");
	setTextureScale(4);
}

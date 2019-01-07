#include <BomberBlob/Bomb.hpp>

#include <BomberBlob/Player.hpp>

//bool Bomb::update() {
//	return (clock.getElapsedTime().asSeconds() > timeDelay) || destroyed;
//}

Bomb::Bomb(float x, float y, Player &player) : RectStatic(0), player(player) {
	position = {x, y};
	size = {0.4f, 0.4f};

	setPosition(x, y, 0.2f);
	setScale(0.4f, 0.4f, 0.4f);

	loadBMPtexture("data/Bomb.bmp");

	disableCollision();

	elementIt = player.bombs.begin();
}

//bool Bomb::draw(RenderWindow *window) {
//	if(!bombAlone && !playerOnBomb)
//		bombAlone = true;
//	playerOnBomb = false;
//	bool r = update();
//	window->draw(shape);
//	return r;
//}

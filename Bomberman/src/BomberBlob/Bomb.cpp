#include <BomberBlob/Bomb.hpp>

using namespace sf;

bool Bomb::update() {
	return (clock.getElapsedTime().asSeconds() > timeDelay) || destroyed;
}

Bomb::Bomb(b2Vec2 p, b2World *world) : StaticCircle( p.x, p.y, 9, &userData, world){
	position = p;

	shape.setRadius(9);
	shape.setOrigin(9, 9);
	shape.setPosition(sf::Vector2f(position.x, position.y));

	clock.restart();

	Image image;
	image.loadFromFile("../data/Bomb.bmp");
	image.createMaskFromColor(sf::Color(0, 255, 0), 0);

	texture.loadFromImage(image);

	shape.setTexture(&texture);
}

bool Bomb::draw(RenderWindow *window) {
	if(!bombAlone && !playerOnBomb)
		bombAlone = true;
	playerOnBomb = false;
	bool r = update();
	window->draw(shape);
	return r;
}

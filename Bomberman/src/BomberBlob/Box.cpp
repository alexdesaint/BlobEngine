#include <BomberBlob/Box.hpp>

using namespace sf;

Box::Box(int x, int y, b2World &world) : StaticRect(x, y, 20, 20, &userData, world){

	shape.setSize(Vector2f(20, 20));
	shape.setOrigin(10, 10);
	shape.setPosition(Vector2f(x, y));
	//shape.setFillColor(Color(255, 150, 0));
	texture.loadFromFile("../data/Box.bmp");
	shape.setTexture(&texture);
}

bool Box::draw(sf::RenderWindow *window) {
	if(!destroyed)
		window->draw(shape);
	return destroyed;
}

#include <BomberBlob/IndestructibleBox.hpp>

IndestructibleBox::IndestructibleBox(int x, int y, b2World &world) : StaticRect(x, y, 20, 20, &userData, world) {
	shape.setSize(sf::Vector2f(20, 20));
	shape.setOrigin(10, 10);
	shape.setPosition(sf::Vector2f(x, y));
	//shape.setFillColor(sf::Color::Blue);
	texture.loadFromFile("../data/IndestructibleBox.bmp");
	shape.setTexture(&texture);
}

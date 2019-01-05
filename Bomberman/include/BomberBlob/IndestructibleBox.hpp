#ifndef BOMBERMAN_INDESTRUCTIBLEBOX_HPP
#define BOMBERMAN_INDESTRUCTIBLEBOX_HPP

#include <SFML/Graphics.hpp>

#include <BomberBlob/StaticRect.hpp>

class IndestructibleBox : StaticRect{
private:
	sf::RectangleShape shape;
	sf::Texture texture;

	UserData userData = {INDESTRUCTIBLE_BOX, this};

public:
	explicit IndestructibleBox(int x, int y, b2World &world);

	void draw(sf::RenderWindow *window) {
		window->draw(shape);
	}
};


#endif //BOMBERMAN_INDESTRUCTIBLEBOX_HPP

#ifndef BOMBERMAN_BOX_HPP
#define BOMBERMAN_BOX_HPP

#include <SFML/Graphics.hpp>

#include <BomberBlob/StaticRect.hpp>
#include <BomberBlob/UserData.hpp>

class Box : StaticRect {
private:
	sf::RectangleShape shape;
	sf::Texture texture;
	bool destroyed = false;

	UserData userData = {BOX, this};

public:
	explicit Box(int x, int y,  b2World &world);

	bool draw(sf::RenderWindow *window);

	void hit() {
		destroyed = true;
	}
};


#endif //BOMBERMAN_BOX_HPP

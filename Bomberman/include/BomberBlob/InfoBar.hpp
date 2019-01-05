#ifndef BOMBERMAN_INFOBAR_HPP
#define BOMBERMAN_INFOBAR_HPP

#include <array>

#include <SFML/Graphics.hpp>

#include <BomberBlob/Player.hpp>

class InfoBar {
private:
	sf::RectangleShape shape;
	sf::Font font;

	sf::Texture ExtraPower;
	sf::Texture ExtraLife;
	sf::Texture ExtraBomb;

	std::array<Player*, 4> players;

	sf::Text createText(const sf::String &str, unsigned int size, int x , int y);

public:
	InfoBar();

	void setPlayer(unsigned int num, Player* player);

	void draw(sf::RenderWindow *window);
};

#endif //BOMBERMAN_INFOBAR_HPP

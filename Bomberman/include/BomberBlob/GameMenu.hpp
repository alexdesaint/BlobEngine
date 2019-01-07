#ifndef BOMBERMAN_GAMEMENU_HPP
#define BOMBERMAN_GAMEMENU_HPP

#include <SFML/Graphics.hpp>

class GameMenu {
private:
	sf::Font font;
	sf::RenderWindow &window;

	sf::Text createText(const sf::String &str, unsigned int size, int x, int y);
public:
	explicit GameMenu(sf::RenderWindow &window);
};


#endif //BOMBERMAN_GAMEMENU_HPP

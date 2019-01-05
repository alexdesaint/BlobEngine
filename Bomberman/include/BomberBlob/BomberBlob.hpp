#ifndef BOMBERMAN_BOMBERMAN_HPP
#define BOMBERMAN_BOMBERMAN_HPP

#include <SFML/Graphics.hpp>

class BomberBlob {
private:
	sf::Clock clock;
	int64_t frameTime, imputTime, drawTime, box2dTime, count = 0;

public:
	explicit BomberBlob(sf::RenderWindow &window);
};

#endif //BOMBERMAN_BOMBERMAN_HPP

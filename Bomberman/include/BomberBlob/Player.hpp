#ifndef BOMBERMAN_PLAYER_HPP
#define BOMBERMAN_PLAYER_HPP

#include <SFML/Graphics.hpp>

#include <BomberBlob/DynamicCircle.hpp>
#include <BomberBlob/UserData.hpp>
#include <BomberBlob/directions.hpp>
#include <BomberBlob/BombManager.hpp>

class Player : DynamicCircle {
private:
	float maxSpeed;
	sf::CircleShape shape;
	sf::Clock clock;
	bool alive = true;

	float rayon = 10;

	UserData userData = {PLAYER, this};
	std::array<bool, 4> command = {false, false, false, false};

	BombManager *bombManager;

	void update();
public:

	explicit Player(BombManager *bm, b2World &world);

	void draw(sf::RenderWindow *window);

	void keyPress(directions d) {
		command[d] = true;
	}

	void keyReleased(directions d) {
		command[d] = false;
	}

	void putBomb() {
		bombManager->addBomb(getPositionb2());
	}

	void hit() {
		alive = false;
	}

	bool isAlive() const {
		return alive;
	}
};


#endif //BOMBERMAN_PLAYER_HPP

//
// Created by Patapouf on 23/09/2018.
//

#include <BomberBlob/Player.hpp>

void Player::update() {
	float TimeFlow = clock.restart().asSeconds();
	b2Vec2 speed;

	if (command[directions::LEFT]) {
		speed.x -= 1;
	}
	if (command[directions::RIGHT]) {
		speed.x += 1;
	}
	if (command[directions::UP]) {
		speed.y -= 1;
	}
	if (command[directions::DOWN]) {
		speed.y += 1;
	}

	if (speed.x != 0 || speed.y != 0) {
		speed.Normalize();
		speed *= maxSpeed;
	}

	setSpeed(speed);
}

Player::Player(BombManager *bm, b2World &world) : DynamicCircle(30, 30, 10, &userData, world) {
	bombManager = bm;

	shape.setRadius(rayon);
	shape.setOrigin(10, 10);
	shape.setPosition(getPosition());
	maxSpeed = 200;
}

void Player::draw(sf::RenderWindow *window) {
	update();

	shape.setPosition(getPosition());
	shape.setRotation(getRotation());

	window->draw(shape);
}

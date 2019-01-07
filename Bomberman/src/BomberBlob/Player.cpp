#include <BomberBlob/Player.hpp>

using namespace BlobEngine;

Player::Player(float x, float y, std::list<Bomb> &bombs) : RectDynamic(0), bombs(bombs) {
	position = {x, y};
	size = {0.8f, 0.8f};

	setPosition(x, y, 0.7f);
	setScale(0.8f, 0.8f, 1.4f);

	setColor(255, 255, 255);

	maxSpeed = 2.5;
}

void Player::preCollisionUpdate() {
	Vec2f Acceleration;

	if (*keys[Actions::up]) {
		Acceleration.x -= 1;
	}
	if (*keys[Actions::down]) {
		Acceleration.x += 1;
	}
	if (*keys[Actions::left]) {
		Acceleration.y -= 1;
	}
	if (*keys[Actions::right]) {
		Acceleration.y += 1;
	}

	if (!Acceleration.isNull()) {
		speed = Acceleration.setLength(maxSpeed);
	} else
		speed.reset();

	if(*keys[Actions::putBomb]) {
		bombs.emplace_front(position.x, position.y, *this);
	}
}

void Player::postCollisionUpdate() {
	setPosition(position.x, position.y, 0.7f);
}

Reaction Player::hit(const PhysicalObject &from) {
	return Reaction::BOUNCE;
}

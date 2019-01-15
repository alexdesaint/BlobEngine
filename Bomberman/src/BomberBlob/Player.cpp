#include <BomberBlob/Player.hpp>

using namespace BlobEngine;

Player::Player(float x, float y, std::list<BombManager> &bombs) : RectDynamic(PLAYER, this), bombs(bombs) {
	position = {x, y};
	size = {0.8f, 0.8f};

	setPosition(x, y, 0.4f);
	setScale(0.8f, 0.8f, 0.8f);

	setColor(255, 255, 255);
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

	if (*keys[Actions::putBomb] && !onBomb && bombPosed < maxBomb) {
		bombs.emplace_front(position, *this);
		lastBomb = &bombs.front();
		onBomb = true;
		bombPosed++;
	}
}

void Player::postCollisionUpdate() {
	setPosition(position.x, position.y, 0.4f);

	if (onBomb) {
		Bomb *bomb = lastBomb->getBomb();
		if (bomb == nullptr || !bomb->overlap(*this)) {
			onBomb = false;
		}
	}
}

Reaction Player::hit(const int objectType, const void *objectData) {
	if (onBomb && objectType == BOMB && objectData == lastBomb->getBomb()) {
		return Reaction::IGNORE;
	}
	if (objectType == EXTRABOMB) {
		maxBomb++;
	} else if (objectType == EXTRASPEED) {
		maxSpeed += 1;
	} else if (objectType == EXTRAPOWER) {
		bombPower++;
	} else if (objectType == EXPLOSION) {
		alive = false;
		return Reaction::IGNORE;
	}

	return Reaction::STOP;
}

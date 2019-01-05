#ifndef BOMBERMAN_DYNAMICCIRCLE_HPP
#define BOMBERMAN_DYNAMICCIRCLE_HPP

#include <Box2D/Box2D.h>
#include <SFML/Window.hpp>

#include <BomberBlob/UserData.hpp>


#define B2RESCALE 10

class DynamicCircle {
private:
	b2BodyDef b2BodyDef;
	b2Body* b2Body;
	b2CircleShape b2Shape;
	b2World *world;

protected:

	DynamicCircle(float x, float y, float r, UserData* userData, b2World &w);

	DynamicCircle(float x, float y, float r, UserData* userData, b2World *w);

	~DynamicCircle() {
		world->DestroyBody(b2Body);
	}

	void setSpeed(b2Vec2 speed) {
		b2Body->SetLinearVelocity(b2Vec2(speed.x / B2RESCALE, speed.y / B2RESCALE));
	}

	sf::Vector2f getPosition() {
		b2Vec2 v = b2Body->GetPosition();
		return {v.x * B2RESCALE, v.y * B2RESCALE};
	}

	b2Vec2 getPositionb2() {
		return {b2Body->GetPosition().x * B2RESCALE, b2Body->GetPosition().y * B2RESCALE};
	}

	float getRotation() {
		return b2Body->GetAngle() * (180.0f/b2_pi);
	}
};


#endif //BOMBERMAN_DYNAMICCIRCLE_HPP

#ifndef BOMBERMAN_STATICCIRCLE_HPP
#define BOMBERMAN_STATICCIRCLE_HPP

#include <Box2D/Box2D.h>

#include <BomberBlob/UserData.hpp>

#define B2RESCALE 10

class StaticCircle {
private:
	b2BodyDef b2BodyDef;
	b2Body* b2Body;
	b2CircleShape b2Shape;
	b2World *world;

protected:
	StaticCircle(float x, float y, float r, UserData* userData, b2World &w);

	StaticCircle(float x, float y, float r, UserData* userData, b2World *w);

	~StaticCircle();
};


#endif //BOMBERMAN_STATICCIRCLE_HPP

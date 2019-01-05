#ifndef BOMBERMAN_STATICRECT_HPP
#define BOMBERMAN_STATICRECT_HPP

#include <Box2D/Box2D.h>

#include <BomberBlob/UserData.hpp>

#define B2RESCALE 10

class StaticRect {
private:
	b2BodyDef b2BodyDef;
	b2Body* b2Body;
	b2PolygonShape b2Shape;
	b2World *world;

protected:
	StaticRect(float x, float y, float w, float h, UserData* userData, b2World &wor);

	StaticRect(float x, float y, float w, float h, UserData* userData, b2World *wor);

	~StaticRect();
};

#endif //BOMBERMAN_STATICRECT_HPP

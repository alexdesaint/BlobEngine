#include <BomberBlob/StaticCircle.hpp>

StaticCircle::StaticCircle(float x, float y, float r, UserData *userData, b2World &w) : world(&w) {
	x /= B2RESCALE;
	y /= B2RESCALE;
	r /= B2RESCALE;

	b2BodyDef.position.Set(x, y);
	b2BodyDef.userData = userData;
	b2Body = world->CreateBody(&b2BodyDef);
	b2Shape.m_radius = r;
	b2Body->CreateFixture(&b2Shape, 0.0f);
}

StaticCircle::StaticCircle(float x, float y, float r, UserData *userData, b2World *w) : world(w) {
	x /= B2RESCALE;
	y /= B2RESCALE;
	r /= B2RESCALE;

	b2BodyDef.position.Set(x, y);
	b2BodyDef.userData = userData;
	b2Body = world->CreateBody(&b2BodyDef);
	b2Shape.m_radius = r;
	b2Body->CreateFixture(&b2Shape, 0.0f);
}

StaticCircle::~StaticCircle() {
	world->DestroyBody(b2Body);
}

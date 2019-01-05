#include <BomberBlob/DynamicCircle.hpp>

DynamicCircle::DynamicCircle(float x, float y, float r, UserData *userData, b2World &w) : world(&w) {
	x /= B2RESCALE;
	y /= B2RESCALE;
	r /= B2RESCALE;

	b2BodyDef.type = b2_dynamicBody;
	b2BodyDef.userData = userData;
	b2BodyDef.position.Set(x, y);
	b2Body = w.CreateBody(&b2BodyDef);

	b2Shape.m_radius = r;

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &b2Shape;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0;
	b2Body->CreateFixture(&fixtureDef);
}

DynamicCircle::DynamicCircle(float x, float y, float r, UserData *userData, b2World *w) : world(w) {
	x /= B2RESCALE;
	y /= B2RESCALE;
	r /= B2RESCALE;

	b2BodyDef.type = b2_dynamicBody;
	b2BodyDef.userData = userData;
	b2BodyDef.position.Set(x, y);
	b2Body = w->CreateBody(&b2BodyDef);

	b2Shape.m_radius = r;

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &b2Shape;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0;
	b2Body->CreateFixture(&fixtureDef);
}

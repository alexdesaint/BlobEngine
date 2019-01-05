//
// Created by Patapouf on 23/09/2018.
//

#include <BomberBlob/StaticRect.hpp>

StaticRect::StaticRect(float x, float y, float w, float h, UserData *userData, b2World &wor) : world(&wor) {
	x /= B2RESCALE;
	y /= B2RESCALE;
	w /= B2RESCALE;
	h /= B2RESCALE;

	b2BodyDef.position.Set(x, y);
	b2BodyDef.userData = userData;
	b2Body = world->CreateBody(&b2BodyDef);
	b2Shape.SetAsBox(w/2, h/2);
	b2Body->CreateFixture(&b2Shape, 0.0f);
}

StaticRect::StaticRect(float x, float y, float w, float h, UserData *userData, b2World *wor) : world(wor) {
	x /= B2RESCALE;
	y /= B2RESCALE;
	w /= B2RESCALE;
	h /= B2RESCALE;

	b2BodyDef.position.Set(x, y);
	b2BodyDef.userData = userData;
	b2Body = world->CreateBody(&b2BodyDef);
	b2Shape.SetAsBox(w/2, h/2);
	b2Body->CreateFixture(&b2Shape, 0.0f);
}

StaticRect::~StaticRect() {
	world->DestroyBody(b2Body);
}

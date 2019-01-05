//
// Created by Patapouf on 23/09/2018.
//

#include <BomberBlob/ContactListener.hpp>
#include <BomberBlob/Player.hpp>
#include <BomberBlob/Box.hpp>

void ContactListener::PreSolve(b2Contact *contact, const b2Manifold *oldManifold) {
	b2Body *b1 = contact->GetFixtureA()->GetBody();
	b2Body *b2 = contact->GetFixtureB()->GetBody();

	auto ud1 = static_cast<UserData*>(b1->GetUserData());
	auto ud2 = static_cast<UserData*>(b2->GetUserData());

	if(ud1 != nullptr && ud2 != nullptr){
		if(ud1->materialIndex == EXPLOSION && ud2->materialIndex == EXPLOSION) {
			contact->SetEnabled(false);
		} else if(ud1->materialIndex == EXPLOSION && ud2->materialIndex == PLAYER) {
			contact->SetEnabled(false);
			static_cast<Player*>(ud2->object)->hit();
		} else if(ud1->materialIndex == PLAYER && ud2->materialIndex == EXPLOSION) {
			contact->SetEnabled(false);
			static_cast<Player*>(ud1->object)->hit();
		} else if(ud1->materialIndex == PLAYER && ud2->materialIndex == BOMB) {
			if(static_cast<Bomb*>(ud2->object)->bombNotFree())
				contact->SetEnabled(false);
		} else if(ud1->materialIndex == BOMB && ud2->materialIndex == PLAYER) {
			if(static_cast<Bomb*>(ud1->object)->bombNotFree())
				contact->SetEnabled(false);
		} else if(ud1->materialIndex == BOMB && ud2->materialIndex == EXPLOSION) {
			contact->SetEnabled(false);
			static_cast<Bomb*>(ud1->object)->hit();
		} else if(ud1->materialIndex == EXPLOSION && ud2->materialIndex == BOMB) {
			contact->SetEnabled(false);
			static_cast<Bomb*>(ud2->object)->hit();
		}
	}
}

void ContactListener::BeginContact(b2Contact *contact) {
	b2Body *b1 = contact->GetFixtureA()->GetBody();
	b2Body *b2 = contact->GetFixtureB()->GetBody();

	auto ud1 = static_cast<UserData*>(b1->GetUserData());
	auto ud2 = static_cast<UserData*>(b2->GetUserData());

	if(ud1 != nullptr && ud2 != nullptr){
		if(ud1->materialIndex == EXPLOSION && ud2->materialIndex == BOX) {
			b1->SetLinearVelocity(b2Vec2());
			static_cast<Box*>(ud2->object)->hit();
		} else if(ud1->materialIndex == BOX && ud2->materialIndex == EXPLOSION) {
			b2->SetLinearVelocity(b2Vec2());
			static_cast<Box*>(ud1->object)->hit();
		} else if(ud1->materialIndex == EXPLOSION && ud2->materialIndex == INDESTRUCTIBLE_BOX) {
			b1->SetLinearVelocity(b2Vec2());
		} else if(ud1->materialIndex == INDESTRUCTIBLE_BOX && ud2->materialIndex == EXPLOSION) {
			b2->SetLinearVelocity(b2Vec2());
		}
	}
}

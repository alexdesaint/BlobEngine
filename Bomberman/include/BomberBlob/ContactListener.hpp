#ifndef BOMBERMAN_CONTACTLISTENER_HPP
#define BOMBERMAN_CONTACTLISTENER_HPP

#include <Box2D/Box2D.h>

#include <BomberBlob/UserData.hpp>

class ContactListener : public b2ContactListener {

public:
	//to IGNORE -- 1
	void PreSolve(b2Contact* contact, const b2Manifold* oldManifold) final;
	//to STOP -- 2
	void BeginContact(b2Contact* contact) final;
};


#endif //BOMBERMAN_CONTACTLISTENER_HPP

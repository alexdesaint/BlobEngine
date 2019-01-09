#include <BomberBlob/Explosion.hpp>

Explosion::Explosion(BlobEngine::Vec2f positionInitial, BlobEngine::Vec2f dirrection, float distanceMax) :
		RectDynamic(EXPLOSION, this),
		distanceMax(distanceMax),
		positionInitial(positionInitial),
		dirrection(dirrection) {

	dirrection = dirrection.getNormal();
	speed = dirrection * maxSpeed;

	position = positionInitial;
	size = {0.4f, 0.4f};

	setPosition(position.x, position.y, 0.2f);
	setScale(0.4f, 0.4f, 0.4f);

	loadBMPtexture("data/Explosion.bmp");
}

void Explosion::postCollisionUpdate() {
	setPosition(position.x, position.y, 0.4f);
}

Reaction Explosion::hit(int objectType, const void *objectData) {
	if(objectType == INDESTRUCTIBLE_BOX || objectType == BOX || objectType == BOMB) {
		active = false;
		return Reaction::STOP;
	}

	return IGNORE;
}

bool Explosion::moove() {
	if((positionInitial - position).length2() > distanceMax * distanceMax){
		active = false;
		return false;
	}

	return true;
}

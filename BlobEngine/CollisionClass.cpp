#include <list>

#include "Geometrie.hpp"
#include "CollisionClass.hpp"

namespace BlobEngine {

//PhysicalObject

	CollisionDetector* PhysicalObject::collisionDetector;

//CircleStatic

	std::list<CircleStatic*> CircleStatic::elements;

//CircleDynamic

	std::list<CircleDynamic*> CircleDynamic::elements;

//LineStatic

	std::list<LineStatic*> LineStatic::elements;

//CollisionDetector

	float CollisionDetector::getElapsedTime() {
		static std::chrono::high_resolution_clock::time_point lastFrameTime;

		std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> diff = now - lastFrameTime;

		lastFrameTime = now;

		return diff.count();
	}

	bool CollisionDetector::collision(CircleStatic circle1, CircleStatic circle2) {
		return Line(circle1.mainCircle.position, circle2.mainCircle.position).Length() <=
			   (circle1.mainCircle.rayon + circle2.mainCircle.rayon);
	}

	bool CollisionDetector::checkCollision(CircleDynamic *object) {

		Vec2f frameMove = object->speed * timeFlow;

		std::list<Collision> collisionList{};

		bool hit = false;
		for (CircleDynamic *target : CircleDynamic::elements) {
			if (target != object) {
				Collision c(object->mainCircle, target->mainCircle, frameMove, target);

				if (c.hitTarget()) {
					collisionList.emplace_back(c);
				}
			}
		}

		for (CircleStatic *target : CircleStatic::elements) {
			Collision c(object->mainCircle, target->mainCircle, frameMove, target);

			if (c.hitTarget()) {
				collisionList.emplace_back(c);
			}
		}

		for (LineStatic *target : LineStatic::elements) {
			for (Line line : target->lines) {
				Collision c(object->mainCircle, line, frameMove, target);

				if (c.hitTarget()) {
					collisionList.emplace_back(c);
				}
			}
		}

		if(collisionList.size() > 1){
			collisionList.sort(Collision::isCloserObstacle);
		}

		if(!collisionList.empty()){
			hit = true;
			collisionList.front().target->hit(*object);

			switch (object->hit(*collisionList.front().target)){
				case BOUNCE:
					frameMove = collisionList.front().getBounce(&object->speed);
					break;
				case STOP:
					frameMove = collisionList.front().getStop(&object->speed);
					break;
				case ROLL:
					frameMove = collisionList.front().getRoll(&object->speed);
					break;
				case IGNORE:
					break;
			}
		}

		object->mainCircle.position = object->mainCircle.position + frameMove;

		return hit;
	}
}
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

	bool CircleDynamic::CheckCollision() {
		return collisionDetector->checkCollision(this);
	}

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

		bool hit = false;
		for (CircleDynamic *target : CircleDynamic::elements) {
			if (target != object) {
				Collision c(object->mainCircle, target->mainCircle, frameMove);

				if (c.hitTarget()) {
					hit = true;
					target->hit(*object);

					switch (object->hit(*target)){
						case BOUNCE:break;
						case STOP:
							frameMove = {0, 0};
							object->speed = {0, 0};
							break;
						case ROLL:
							frameMove = c.getRoll(&object->speed);
							break;
						case IGNORE:
							break;
					}
				}
			}
		}

		for (CircleStatic *target : CircleStatic::elements) {
			Collision c(object->mainCircle, target->mainCircle, frameMove);

			if (c.hitTarget()) {
				hit = true;
				target->hit(*object);

				switch (object->hit(*target)){
					case BOUNCE:break;
					case STOP:
						frameMove = {0, 0};
						object->speed = {0, 0};
						break;
					case ROLL:
						frameMove = c.getRoll(&object->speed);
						break;
					case IGNORE:
						break;
				}
			}
		}

		for (LineStatic *target : LineStatic::elements) {
			for (Line line : target->lines) {
				Collision c(object->mainCircle, line, frameMove);

				if (c.hitTarget()) {
					hit = true;
					target->hit(*object);

					switch (object->hit(*target)){
						case BOUNCE:break;
						case STOP:
							frameMove = {0, 0};
							object->speed = {0, 0};
							break;
						case ROLL:
							frameMove = c.getRoll(&object->speed);
							break;
						case IGNORE:
							break;
					}
				}
			}
		}

		object->mainCircle.position = object->mainCircle.position + frameMove;

		return hit;
	}
}
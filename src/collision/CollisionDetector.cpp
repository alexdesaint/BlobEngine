#include <list>

#include <BlobEngine/Geometrie.hpp>
#include <BlobEngine/Hit.hpp>
#include <BlobEngine/CollisionDetector.hpp>


namespace BlobEngine {

//PhysicalObject

//CircleStatic

	void CircleStatic::enableCollision() {
		CollisionDetector::circleStaticList.push_front(this);
		elementIt = CollisionDetector::circleStaticList.begin();
	}

	void CircleStatic::disableCollision() {
		CollisionDetector::circleStaticList.erase(elementIt);
	}

//CircleDynamic

	void CircleDynamic::enableCollision() {
		CollisionDetector::circleDynamicList.push_front(this);
		elementIt = CollisionDetector::circleDynamicList.begin();
	}

	void CircleDynamic::disableCollision() {
		CollisionDetector::circleDynamicList.erase(elementIt);
	}

//LineStatic

	void LineStatic::enableCollision() {
		CollisionDetector::lineStaticList.push_front(this);
		elementIt = CollisionDetector::lineStaticList.begin();
	}

	void LineStatic::disableCollision() {
		CollisionDetector::lineStaticList.erase(elementIt);
	}

//CollisionDetector

	thread_local std::deque<CircleStatic*> CollisionDetector::circleStaticList{};
	thread_local std::deque<CircleDynamic*> CollisionDetector::circleDynamicList{};
	thread_local std::deque<LineStatic*> CollisionDetector::lineStaticList{};

	float CollisionDetector::getElapsedTime() {
		static std::chrono::high_resolution_clock::time_point lastFrameTime;

		std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> diff = now - lastFrameTime;

		lastFrameTime = now;

		return diff.count();
	}

	void CollisionDetector::checkCollision(CircleDynamic *object) {

		Vec2f frameMove = object->speed * timeFlow;
		Circle nextCircle = object->mainCircle;
		bool hit;
		unsigned int count = 0;
		do {

			Hit lastHit;
			PhysicalObject *lastHitTarget = nullptr;

			for (CircleDynamic *target : circleDynamicList) {
				if (target != object) {
					Hit c(nextCircle, target->mainCircle, frameMove);

					if (c.hitTarget()) {
						if(lastHitTarget == nullptr){
							lastHit = c;
							lastHitTarget = target;
						} else if(c.isCloserObstacle(lastHit)) {
							lastHit = c;
							lastHitTarget = target;
						}
					}
				}
			}

			for (CircleStatic *target : circleStaticList) {
				Hit c(nextCircle, target->mainCircle, frameMove);

				if (c.hitTarget()) {
					if(lastHitTarget == nullptr){
						lastHit = c;
						lastHitTarget = target;
					} else if(c.isCloserObstacle(lastHit)) {
						lastHit = c;
						lastHitTarget = target;
					}
				}
			}

			for (LineStatic *target : lineStaticList) {
				for (Line line : target->lines) {
					Hit c(nextCircle, line, frameMove);

					if (c.hitTarget()) {
						if(lastHitTarget == nullptr){
							lastHit = c;
							lastHitTarget = target;
						} else if(c.isCloserObstacle(lastHit)) {
							lastHit = c;
							lastHitTarget = target;
						}
					}
				}
			}

			if (lastHitTarget != nullptr) {
				hit = true;

				object->mainCircle.position = object->mainCircle.position + lastHit.getHitPoint();

				lastHitTarget->hit(*object);

				switch (object->hit(*lastHitTarget)) {
					case BOUNCE:
						frameMove = lastHit.getBounce(&object->speed);
						break;
					case STOP:
						frameMove.reset();
						object->speed.reset();
						break;
					case ROLL:
						frameMove = lastHit.getRoll(&object->speed);
						break;
					case IGNORE:
						frameMove = frameMove - lastHit.getHitPoint();
						break;
				}
			} else {
				object->mainCircle.position = object->mainCircle.position + frameMove;
				hit = false;
			}

			count++;
		}while(hit && !frameMove.isNull() && count < 50);
	}
}
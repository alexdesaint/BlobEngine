#include <list>
#include <chrono>

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

	PhysicalObject *CollisionDetector::getClosetObject(Circle object, Vec2f frameMove, Hit &hit) {

		PhysicalObject *lastHitTarget = nullptr;

		for (CircleDynamic *target : circleDynamicList) {
			Hit c(object, target->mainCircle, frameMove);

			if (c.hitTarget()) {
				if (lastHitTarget == nullptr) {
					hit = c;
					lastHitTarget = target;
				} else if (c.isCloserObstacle(hit)) {
					hit = c;
					lastHitTarget = target;
				}
			}
		}

		for (CircleStatic *target : circleStaticList) {
			Hit c(object, target->mainCircle, frameMove);

			if (c.hitTarget()) {
				if (lastHitTarget == nullptr) {
					hit = c;
					lastHitTarget = target;
				} else if (c.isCloserObstacle(hit)) {
					hit = c;
					lastHitTarget = target;
				}
			}
		}

		for (LineStatic *target : lineStaticList) {
			for (Line line : target->lines) {
				Hit c(object, line, frameMove);

				if (c.hitTarget()) {
					if (lastHitTarget == nullptr) {
						hit = c;
						lastHitTarget = target;
					} else if (c.isCloserObstacle(hit)) {
						hit = c;
						lastHitTarget = target;
					}
				}
			}
		}

		return lastHitTarget;
	}

	void CollisionDetector::checkCollision(CircleDynamic &object) {
		
		object.disableCollision();
		
		Vec2f frameMove = object.speed * timeFlow;
		Circle nextCircle = object.mainCircle;
		Hit hit;
		PhysicalObject *target;

		do {
			target = getClosetObject(nextCircle, frameMove, hit);

			if (target != nullptr) {
				target->hit(object);
				
				frameMove = hit.getReactionVec(object.hit(*target), object.speed);
				
				object.mainCircle.position = object.mainCircle.position + hit.getVecToTarget();
				
			} else {
				object.mainCircle.position = object.mainCircle.position + frameMove;
			}

		} while (target != nullptr && !object.speed.isNull());
		
		object.enableCollision();
	}
}
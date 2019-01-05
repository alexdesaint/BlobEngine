#include <list>
#include <chrono>
#include <math.h>

#include <BlobEngine/Collision/CollisionDetector.hpp>

namespace BlobEngine {

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


	//RectStatic

	void RectStatic::enableCollision() {
		CollisionDetector::rectStaticList.push_front(this);
		elementIt = CollisionDetector::rectStaticList.begin();
	}

	void RectStatic::disableCollision() {
		CollisionDetector::rectStaticList.erase(elementIt);
	}

	//RectDynamic

	void RectDynamic::enableCollision() {
		CollisionDetector::rectDynamicList.push_front(this);
		elementIt = CollisionDetector::rectDynamicList.begin();
	}

	void RectDynamic::disableCollision() {
		CollisionDetector::rectDynamicList.erase(elementIt);
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

	std::deque<CircleStatic *> CollisionDetector::circleStaticList{};
	std::deque<CircleDynamic *> CollisionDetector::circleDynamicList{};
	std::deque<RectStatic *> CollisionDetector::rectStaticList{};
	std::deque<RectDynamic *> CollisionDetector::rectDynamicList{};
	std::deque<LineStatic *> CollisionDetector::lineStaticList{};

	float getElapsedTime() {
		static std::chrono::high_resolution_clock::time_point lastFrameTime;

		std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> diff = now - lastFrameTime;

		lastFrameTime = now;

		return diff.count();
	}
/*
	PhysicalObject *CollisionDetector::getClosetObject(Circle &object, Vec2f frameMove, Hit &hit) {

		PhysicalObject *lastHitTarget;

		lastHitTarget = nullptr;

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
			if (target->lines.size() > 1) {
				int count = 0;
				Point2f lastPoint = target->lines.back();

				for (Point2f point : target->lines) {
					Hit c(object, point, frameMove);

					if (c.hitTarget()) {
						if (lastHitTarget == nullptr) {
							hit = c;
							lastHitTarget = target;
						} else if (c.isCloserObstacle(hit)) {
							hit = c;
							lastHitTarget = target;
						}
					}

					Line line(point, lastPoint);

					Hit cl(object, line, frameMove);

					if (cl.hitTarget()) {

						if (lastHitTarget == nullptr) {
							hit = cl;
							lastHitTarget = target;
						} else if (cl.isCloserObstacle(hit)) {
							hit = cl;
							lastHitTarget = target;
						}
					}

					lastPoint = point;
					count++;
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

		//Error managment :
		unsigned int count = 0;
		std::deque<Point2f> trajectoryComputed{};
		Circle originCircle = object.mainCircle;
		Vec2f originSpeed = object.speed;

		do {
			target = getClosetObject(nextCircle, frameMove, hit);

			if (target != nullptr) {
				target->hit(object);

				frameMove = hit.getReactionVec(object.hit(*target), object.speed);

				object.mainCircle.position += hit.getVecToTarget();

				trajectoryComputed.emplace_back(object.mainCircle.position);

			} else {
				object.mainCircle.position = object.mainCircle.position + frameMove;
			}

			//Error managment :
			count++;

			if (count > 50) {
				throw CollisionDetectorException("infinite collision compute",
												 circleStaticList,
												 circleDynamicList,
												 lineStaticList,
												 originCircle,
												 originSpeed,
												 trajectoryComputed);
			}

		} while (target != nullptr && !object.speed.isNull());

		object.enableCollision();
	}
*/
	void CollisionDetector::checkCollision(RectDynamic &object) {
		object.preCollisionUpdate();

		if (object.speed.isNull())
			return;

		object.disableCollision();

		Vec2f frameMove = object.speed * timeFlow;

		double numOfStep = ceil(frameMove.length());

		Vec2f stepMove = frameMove / numOfStep;

		for (unsigned int i = 0; i < numOfStep; i++) {
			Point2f old(object.position);

			object.position.x = object.position.x + stepMove.x;

			for (RectStatic *rect : rectStaticList) {
				if (rect->overlap(object) || object.overlap(*rect))
					object.position = old;
			}
			old = object.position;

			object.position.y = object.position.y + stepMove.y;
			for (RectStatic *rect : rectStaticList) {
				if (rect->overlap(object) || object.overlap(*rect))
					object.position = old;
			}
		}

		object.enableCollision();

		object.postCollisionUpdate();
	}

	void CollisionDetector::update() {

		timeFlow = getElapsedTime();
/*
		for (CircleDynamic *object : circleDynamicList) {
			if (!object->speed.isNull())
				checkCollision(*object);
		}
*/
		for (RectDynamic *object : rectDynamicList) {
			checkCollision(*object);
		}
	}
}
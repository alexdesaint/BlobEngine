#include <list>

#include <BlobEngine/Geometrie.hpp>
#include <BlobEngine/Hit.hpp>
#include <BlobEngine/CollisionDetector.hpp>


namespace BlobEngine {

//PhysicalObject

//CircleStatic

//CircleDynamic

//LineStatic

//CollisionDetector

	float CollisionDetector::getElapsedTime() {
		static std::chrono::high_resolution_clock::time_point lastFrameTime;

		std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> diff = now - lastFrameTime;

		lastFrameTime = now;

		return diff.count();
	}

	void CollisionDetector::checkCollision(CircleDynamic *object) {

		Vec2f frameMove = object->speed * timeFlow;

		bool hit = false;

		do {
			std::list<Hit> collisionList{};
			PhysicalObject *objectList = nullptr;

			for (CircleDynamic *target : circleDynamicList) {
				if (target != object) {
					Hit c(object->mainCircle, target->mainCircle, frameMove);

					if (c.hitTarget()) {
						collisionList.emplace_back(c);
						objectList = target;
					}
				}
			}

			for (CircleStatic *target : circleStaticList) {
				Hit c(object->mainCircle, target->mainCircle, frameMove);

				if (c.hitTarget()) {
					collisionList.emplace_back(c);
					objectList = target;
				}
			}

			for (LineStatic *target : lineStaticList) {
				for (Line line : target->lines) {
					Hit c(object->mainCircle, line, frameMove);

					if (c.hitTarget()) {
						collisionList.emplace_back(c);
						objectList = target;
					}
				}
			}

			if (collisionList.size() > 1) {
				collisionList.sort(Hit::isCloserObstacle);
			}

			if (!collisionList.empty()) {
				hit = true;

				auto it = collisionList.front();

				objectList->hit(*object);

				object->mainCircle.position = object->mainCircle.position + it.getHitPoint();

				switch (object->hit(*objectList)) {
					case BOUNCE:
						frameMove = it.getBounce(&object->speed);
						break;
					case STOP:
						frameMove.reset();
						object->speed.reset();
						break;
					case ROLL:
						frameMove = it.getRoll(&object->speed);
						break;
					case IGNORE:
						frameMove = frameMove - it.getHitPoint();
						break;
				}
			} else {
				object->mainCircle.position = object->mainCircle.position + frameMove;
				hit = false;
			}
		}while((!hit) && frameMove.isNull());
	}
}
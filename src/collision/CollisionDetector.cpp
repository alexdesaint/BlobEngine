#include <list>
#include <chrono>
#include <math.h>
#include <unordered_set>

//debug
#include <imgui.h>

#include <Blob/Collision/CollisionDetector.hpp>
#include <Blob/GL/Core.hpp>


namespace Blob::Collision {

    uint64_t CollisionDetector::hashCoor(Vec2f pos) {
        return (0xFFFFFFFF & (uint64_t) (uint32_t) (pos.x)) | ((uint64_t) (uint32_t) (pos.y) << 32);
    }

    Vec2i CollisionDetector::unhashCoor(uint64_t pos) {
        uint32_t x = 0xFFFFFFFF & pos;
        uint32_t y = 0xFFFFFFFF & (pos >> 32);
        return {(int32_t) x, (int32_t) y};
    }

    uint64_t CollisionDetector::hashCoor(Vec2i pos) {
        return (0xFFFFFFFF & (uint32_t) pos.x) | ((uint64_t) pos.y << 32);
    }

    void CollisionDetector::addToSpacialHash(std::list<Vec2i> pos, Blob::Collision::Object *o) {
        for (const auto &p : pos) {
            auto hash = CollisionDetector::hashCoor(p);

            auto it = CollisionDetector::spacialHash.find(hash);
            if (it == CollisionDetector::spacialHash.end())
                CollisionDetector::spacialHash[hash] = {o};
            else {
                if (it->second.find(o) == it->second.end())
                    it->second.insert(o);
                else
                    throw Exception("Insertion in Spacial Hash but element already exist");
            }
        }
    }

    void CollisionDetector::removeFromSpacialHash(std::list<Vec2i> pos, Blob::Collision::Object *o) {
        for (const auto &p : pos) {
            auto hash = CollisionDetector::hashCoor(p);
            auto d = CollisionDetector::spacialHash[hash].erase(o);

            if (d != 1)
                throw Exception("Remove in Spacial Hash but no element");

            if (CollisionDetector::spacialHash[hash].empty())
                CollisionDetector::spacialHash.erase(hash);
        }
    }

    //Object
    std::list<Object *> Object::getImtemsHere(Blob::Vec2f pos) {
        auto hash = CollisionDetector::hashCoor(pos);

        auto it = CollisionDetector::spacialHash.find(hash);
        if (it == CollisionDetector::spacialHash.end())
            return std::list<Object *>();
        else
            return std::list<Object *>(CollisionDetector::spacialHash[hash].begin(),
                                       CollisionDetector::spacialHash[hash].end());
    }

    int Object::getObjectType() const {
        return objectType;
    }

    void CircleDynamic::disableCollision() {
        CollisionDetector::circleDynamicList.erase(elementIt);
    }

    //RectStatic
    void RectStatic::enableCollision() {
        if(!enable) {
            enable = true;
            CollisionDetector::addToSpacialHash(rasterize(), this);
        }
    }

    void RectStatic::disableCollision() {
        if(enable) {
            enable = false;
            CollisionDetector::removeFromSpacialHash(rasterize(), this);
        }
    }

    //RectDynamic
    void RectDynamic::enableCollision() {
        if(!enable) {
            enable = true;
            CollisionDetector::rectDynamicList.push_front(this);
            elementIt = CollisionDetector::rectDynamicList.begin();

            CollisionDetector::addToSpacialHash(rasterize(), this);
        }
    }

    void RectDynamic::disableCollision() {
        if(enable) {
            enable = false;
            CollisionDetector::rectDynamicList.erase(elementIt);

            CollisionDetector::removeFromSpacialHash(rasterize(), this);
        }
    }

    //LineStatic
    void LineStatic::enableCollision() {
    }

    void LineStatic::disableCollision() {
    }

    //CollisionDetector
    std::unordered_map<int64_t, std::unordered_set<Object *>> CollisionDetector::spacialHash;

    std::list<CircleDynamic *> CollisionDetector::circleDynamicList{};
    std::list<RectDynamic *> CollisionDetector::rectDynamicList{};

/*
	StaticObject *CollisionDetector::getClosetObject(Circle &object, Vec2f frameMove, Hit &hit) {

		StaticObject *lastHitTarget;

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
		StaticObject *target;

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

    bool
    CollisionDetector::targetOverlap(RectDynamic &object, Rectangle &r, const std::unordered_set<Object *> &targets,
                                     std::unordered_map<Object *, Reaction> &hittedObjects) {
        bool ret = false;

        for (Object *target : targets) {
            if (target->overlap(r)) {
                if (hittedObjects.find(target) == hittedObjects.end()) {
                    target->hit(object.objectType, object);
                    object.hit(target->objectType, *target);
                    hittedObjects[target] = object.reaction;
                }

                if (hittedObjects[target] == STOP) {
                    ret = true;
                }
            }
        }
        return ret;
    }

    void
    CollisionDetector::computeLocalCollision(RectDynamic &object, const std::unordered_set<Object *> &targets,
                                             Vec2f frameMove) {

        auto numOfStep = static_cast<unsigned int>(ceil(frameMove.length() * 100));

        Vec2f stepMove = frameMove / numOfStep;

        Rectangle r({}, object.size);

        std::unordered_map<Object *, Reaction> hittedObjects;

        for (unsigned int i = 0; i < numOfStep; i++) {

            r.position = object.position + Vec2f{stepMove.x, 0};

            if (!targetOverlap(object, r, targets, hittedObjects)) {
                object.position = r.position;

                if (!object.keepMoving()) {
                    break;
                }
            }

            r.position = object.position + Vec2f{0, stepMove.y};

            if (!targetOverlap(object, r, targets, hittedObjects)) {
                object.position = r.position;

                if (!object.keepMoving()) {
                    break;
                }
            }
        }
    }

    using namespace std;

    /**
     * get the list of block between two points
     *
     * @param pos Initial position of the path
     * @param dest Final position of the path
     * @return list of the block position between these two points
     */
    list<int64_t> CollisionDetector::getPath(Vec2i pos, Vec2i dest) {
        list<int64_t> path;
        int i, iMax;
        if (pos.x < dest.x) {
            i = pos.x;
            iMax = dest.x;
        } else {
            i = dest.x;
            iMax = pos.x;
        }

        int jBeg, jMax;
        if (pos.y < dest.y) {
            jBeg = pos.y;
            jMax = dest.y;
        } else {
            jBeg = dest.y;
            jMax = pos.y;
        }

        for (; i <= iMax; i++) {
            for (int j = jBeg; j <= jMax; j++)
                path.emplace_back(hashCoor(Vec2i{i, j}));
        }

        return path;
    }

    void CollisionDetector::checkCollision(Blob::Collision::RectDynamic &object) {
        object.preCollisionUpdate();

		Vec2f frameMove = object.speed * Blob::GL::Core::timeFlow;

        Vec2f oldPos = object.position;

        list<int64_t> path;

        for (auto p : object.getPoints()) {
            auto a = getPath(p.cast<int>(), (p + frameMove).cast<int>());
            path.insert(path.end(), a.begin(), a.end());
        }

        std::unordered_set<Object *> targets;

        for (const auto &p : path) {
            auto search = spacialHash.find(p);
            if (search != spacialHash.end())
                targets.insert(spacialHash[p].begin(), spacialHash[p].end());
        }

        targets.erase(&object);

        removeFromSpacialHash(object.rasterize(), &object);

        if (targets.empty())
            object.position = frameMove + object.position;
        else
            computeLocalCollision(object, targets, frameMove);

        addToSpacialHash(object.rasterize(), &object);

		object.speed = (object.position - oldPos) / Blob::GL::Core::timeFlow;

        object.postCollisionUpdate();
    }

    void CollisionDetector::update() {

        if (!timeStoped) {
            /*
		    for (CircleDynamic *object : circleDynamicList) {
			    if (!object->speed.isNull())
				    checkCollision(*object);
		    }*/

            for (RectDynamic *object : rectDynamicList) {
                checkCollision(*object);
            }
        }
    }

    void CollisionDetector::pause() {
        timeStoped = true;

    }

    void CollisionDetector::unpause() {
        timeStoped = false;
    }
}
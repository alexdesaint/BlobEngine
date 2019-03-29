#include <list>
#include <chrono>
#include <math.h>
#include <unordered_set>

//debug
#include <imgui.h>
#include <sstream>

#include <Blob/Collision/CollisionDetector.hpp>


namespace Blob::Collision {

    int64_t hashCoor(Vec2f pos) {
        return (0xFFFFFFFF & (int32_t) pos.x) | ((int64_t) pos.y << 32);
    }

    int64_t hashCoor(Vec2i pos) {
        return (0xFFFFFFFF & (int32_t) pos.x) | ((int64_t) pos.y << 32);
    }

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

        auto hash = hashCoor(getPosition());

        auto it = CollisionDetector::spacialHash.find(hash);
        if (it == CollisionDetector::spacialHash.end())
            CollisionDetector::spacialHash[hash] = {this};
        else
            it->second.push_back(this);
    }

    void RectStatic::disableCollision() {
        CollisionDetector::rectStaticList.erase(elementIt);

        auto hash = hashCoor(getPosition());
        CollisionDetector::spacialHash[hash].remove(this);
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
    std::unordered_map<int64_t, std::list<Object *>> CollisionDetector::spacialHash;

    std::list<CircleStatic *> CollisionDetector::circleStaticList{};
    std::list<CircleDynamic *> CollisionDetector::circleDynamicList{};
    std::list<RectStatic *> CollisionDetector::rectStaticList{};
    std::list<RectDynamic *> CollisionDetector::rectDynamicList{};
    std::list<LineStatic *> CollisionDetector::lineStaticList{};

    float getElapsedTime() {
        static std::chrono::high_resolution_clock::time_point lastFrameTime;

        std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> diff = now - lastFrameTime;

        lastFrameTime = now;

        return diff.count();
    }

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
    //classic object to object test
    void
    CollisionDetector::computeLocalCollision(RectDynamic &object, const std::list<Object *> &targets, Vec2f frameMove) {

        /*if (object.speed.isNull()) {
            for (RectStatic *rect : rectStaticList) {
                if (rect->overlap(object) || object.overlap(*rect)) {
                    rect->hit(object.objectType, object);
                    object.hit(rect->objectType, *rect);
                }
            }

            object.postCollisionUpdate();
            return;
        }*/

        auto numOfStep = static_cast<unsigned int>(ceil(frameMove.length() * 100));

        Vec2f stepMove = frameMove / numOfStep;

        for (unsigned int i = 0; i < numOfStep; i++) {
            Rectangle r(Vec2f{stepMove.x, 0} + object.getPosition(), object.getSize());

            for (Object *target : targets) {
                if (target != &object) {
                    if (target->overlap(r)) {
                        target->hit(object.objectType, object);
                        object.hit(target->objectType, *target);

                        if (object.reaction != IGNORE) {
                            i = numOfStep;
                            break;
                        }
                    }

                    if (!object.moove()) {
                        i = numOfStep;
                        break;
                    }

                    object.setPosition(r.getPosition());
                } else
                    ImGui::Text("Found Me");
            }
        }

        for (unsigned int i = 0; i < numOfStep; i++) {
            Rectangle r(Vec2f{stepMove.x, 0} + object.getPosition(), object.getSize());

            for (Object *target : targets) {
                if (target != &object) {
                    if (target->overlap(r)) {
                        target->hit(object.objectType, object);
                        object.hit(target->objectType, *target);

                        if (object.reaction != IGNORE) {
                            i = numOfStep;
                            break;
                        }
                    }

                    if (!object.moove()) {
                        i = numOfStep;
                        break;
                    }

                    object.setPosition(r.getPosition());
                } else
                    ImGui::Text("Found Me");
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
    list<int64_t> getPath(Vec2i pos, Vec2i dest) {
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

        Vec2f frameMove = object.speed * timeFlow;

        list<int64_t> path;

        for (auto p : object.getPoints()) {
            ImGui::Text("%.1f, %.1f", p.x, p.y);
            auto a = getPath(p.cast<int>(), (p + frameMove).cast<int>());
            path.insert(path.end(), a.begin(), a.end());
        }

        stringstream s;

        std::list<Object *> targets;

        for (const auto &p : path) {
            s << hex << p << " ";

            auto search = spacialHash.find(p);
            if (search != spacialHash.end())
                targets.insert(targets.end(), spacialHash[p].begin(), spacialHash[p].end());
        }

        if (targets.empty())
            object.setPosition(frameMove + object.getPosition());
        else
            computeLocalCollision(object, targets, frameMove);

        ImGui::Text(s.str().c_str());

        object.postCollisionUpdate();
    }

    void CollisionDetector::update() {

        if (!timeStoped) {
            timeFlow = getElapsedTime();

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
        getElapsedTime();
    }
}
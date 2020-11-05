#include <chrono>
#include <list>
#include <math.h>
#include <unordered_set>

// debug
#include <imgui.h>

#include <Blob/Collision/CollisionDetector.hpp>
#include <Blob/Window.hpp>

namespace Blob::Collision {

using namespace Geometry;

// CollisionDetector

bool CollisionDetector::targetOverlap(DynamicCollider &object, const std::unordered_set<Collider *> &targets,
                                      std::unordered_map<Collider *, Reaction> &hittedObjects) {
    bool ret = false;

    for (Collider *target : targets) {
        if (target->overlap(object)) {
            if (hittedObjects.find(target) == hittedObjects.end()) {
                target->hit(object._objectType_, object);
                object.hit(target->_objectType_, *target);
                hittedObjects[target] = object.reaction;
            }

            if (hittedObjects[target] == STOP)
                ret = true;
        }
    }

    return ret;
}

void CollisionDetector::computeLocalCollision(DynamicCollider &object, const std::unordered_set<Collider *> &targets, Maths::Vec2<> frameMove) {

    auto numOfStep = static_cast<unsigned int>(ceil(frameMove.length() * 100));

    Maths::Vec2<> stepMove = frameMove / numOfStep;

    Rectangle r({}, object.size);

    std::unordered_map<Object *, Reaction> hittedObjects;

    for (unsigned int i = 0; i < numOfStep; i++) {

        r.position = object.position + Maths::Vec2<>{stepMove.x, 0};

        if (!targetOverlap(object, r, targets, hittedObjects)) {
            object.position = r.position;

            if (!object.keepMoving()) {
                break;
            }
        }

        r.position = object.position + Maths::Vec2<>{0, stepMove.y};

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
list<int64_t> CollisionDetector::getPath(Maths::Vec2<int32_t> pos, Maths::Vec2<int32_t> dest) {
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

    union {
        Maths::Vec2<int32_t> vec;
        uint64_t key;
    } vecKey{};

    for (; i <= iMax; i++) {
        for (int j = jBeg; j <= jMax; j++) {
            vecKey.vec = {i, j};
            path.emplace_back(vecKey.key);
        }
    }

    return path;
}

template<typename T>
void CollisionDetector::checkCollision(DynamicCollider<T> &dynamicCollider, const Maths::Vec2<>& frameMove) {
    Collider<T> form{dynamicCollider};
    form.position  += frameMove;

    std::unordered_set<Collider<T> *> colliders;

    if (Collider<T>::targetOverlap(form, colliders))
        dynamicCollider.position += frameMove;
    else
        computeLocalCollision(dynamicCollider, targets, frameMove);
}

void CollisionDetector::update() {
    for (auto *dynamicCollider : DynamicCollider<Rectangle>::colliders) {
        // object.preCollisionUpdate();
        dynamicCollider->disableCollision();

        Maths::Vec2<> frameMove = dynamicCollider->speed * Core::Window::timeFlow;
        Collider<Rectangle> form{*dynamicCollider};
        form.position  += frameMove;


        std::unordered_set<Collider<Rectangle> *> hitTargets;
        if (Collider<Rectangle>::targetOverlap(form, hitTargets)){
            
        }

        dynamicCollider->enableCollision();
        dynamicCollider->postCollisionUpdate();
    }
}
} // namespace Blob::Collision

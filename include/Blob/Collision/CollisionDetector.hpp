#pragma once

#include <Blob/Collision/Reaction.hpp>
#include <Blob/Exception.hpp>
#include <Blob/Geometry/Forms.hpp>

#include <deque>
#include <list>
#include <unordered_map>
#include <unordered_set>

namespace Blob::Collision {

class CollisionDetector;

template<class T, const int layer = 0>
class Collider : public T {
    friend CollisionDetector;

private:
    int _objectType_;
    bool enable = false;

    static std::unordered_map<int64_t, std::unordered_set<Collider<T> *>> spacialHash;

protected:
    union VecKey {
        Maths::Vec2<int32_t> vec{};
        uint64_t key;
    };

    virtual void hit(int objectType, Geometry::Form &object) {}

public:
    explicit Collider(int objectType) : _objectType_(objectType) {}

    void setObjectType(int objectType) { _objectType_ = objectType; }

    [[nodiscard]] int getObjectType() const { return _objectType_; };

    void enableCollision() {
        if (!enable) {
            enable = true;
            std::list<VecKey> pos = T::rasterize();

            for (const auto &p : pos) {
                auto it = spacialHash.find(p.key);
                if (it == spacialHash.end())
                    spacialHash[p.key] = {this};
                else if (it->second.find(this) == it->second.end())
                    it->second.insert(this);
                else
                    throw Core::Exception("Insertion in Spacial Hash but element already exist");
            }
        }
    }

    void disableCollision() {
        if (enable) {
            enable = false;
            std::list<VecKey> pos = T::rasterize();

            for (const auto &p : pos) {
                auto d = spacialHash[p.key].erase(this);

                if (d != 1)
                    throw Core::Exception("Remove in Spacial Hash but no element");

                if (spacialHash[p.key].empty())
                    spacialHash.erase(p.key);
            }
        }
    }

    template<class U>
    static bool targetOverlap(Collider<U> &object, std::unordered_set<Collider<T> *> &hittedObjects) {
        bool ret = false;

        std::list<Collider::VecKey> pos = object.rasterize();

        for (const Collider::VecKey &p : pos) {

            for (Collider<T> *target : spacialHash[p.key]) {
                if (target->overlap(object)) {
                    if (hittedObjects.find(target) == hittedObjects.end()) {
                        hittedObjects.emplace(target);
                    }

                    ret = true;
                }
            }
        }

        return ret;
    }
};

template<class T>
class DynamicCollider : public Collider<T> {
    friend CollisionDetector;

private:
    static std::unordered_set<DynamicCollider<T> *> colliders;

protected:
    void hit(int objectType, Geometry::Form &object) override { speed = 0; } // Bounce ?

    /**
     * This method is called right after the collision is computed
     */
    virtual void postCollisionUpdate() {}

public:
    Maths::Vec2<> speed{};

    explicit DynamicCollider(int objectType) : Collider<T>(objectType) {}
};

class CollisionDetector {
#ifdef TEST
    friend test_class;
#endif
private:
    static bool targetOverlap(DynamicCollider &object, const std::unordered_set<Collider *> &targets,
                              std::unordered_map<Collider *, Reaction> &hittedObjects);

    static void computeLocalCollision(DynamicCollider &object, const std::unordered_set<Collider *> &targets, Maths::Vec2<> frameMove);

    static std::list<int64_t> getPath(Maths::Vec2<int32_t> pos, Maths::Vec2<int32_t> dest);

public:
    // StaticObject *getClosetObject(Circle &object, Vec2<> frameMove, Hit &hit);

    // void checkCollision(CircleDynamic &object);

    template<typename T>
    void checkCollision(DynamicCollider<T> &dynamicCollider, const Maths::Vec2<>& frameMove);

    void update();
};
} // namespace Blob::Collision

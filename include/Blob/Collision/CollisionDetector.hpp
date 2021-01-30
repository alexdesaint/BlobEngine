#pragma once

#include <Blob/Collision/Exception.hpp>
#include <Blob/Collision/Forms.hpp>

#include <deque>
#include <iostream>
#include <list>
#include <unordered_map>
#include <unordered_set>

namespace Blob::Collision {

class PhysicalObject {
    template<typename U>
    friend class FormDatabase;

private:
    bool enable = false;

protected:
    explicit PhysicalObject(const std::type_info &objectType) : objectType(objectType) {}

public:
    const std::type_info &objectType;

    PhysicalObject(const PhysicalObject &) = delete;

    PhysicalObject(PhysicalObject &&) = delete;

    virtual ~PhysicalObject() = default;
};

template<class T>
class Collider : public PhysicalObject {
    template<typename U>
    friend class FormDatabase;

protected:
    T &form;

    Collider(const std::type_info &objectType, T &form) : PhysicalObject(objectType), form(form) {}
};

template<class T>
class DynamicCollider : public Collider<T> {
    template<typename U>
    friend class FormDatabase;

private:
    std::unordered_set<PhysicalObject *> hitting;
    std::unordered_set<PhysicalObject *> hittingClone;

protected:
    const std::unordered_set<PhysicalObject *> &hittingObjects;

    explicit DynamicCollider(const std::type_info &objectType, T &form) : Collider<T>(objectType, form), hittingObjects(hitting) {}

    virtual void hitStart(PhysicalObject *object) {}

    virtual void hitEnd(PhysicalObject *object) {}

    /**
     * This method is called right after the collision is computed
     * @param timeFlow Time in second sins list frame
     */
    virtual void postCollisionUpdate(float timeFlow) {}
};

template<class T>
class FormDatabase {
    template<typename U>
    friend class FormDatabase;

private:
    std::unordered_map<Maths::Vec2<int32_t>, std::unordered_set<Collider<T> *>> spacialHash;
    std::unordered_set<DynamicCollider<T> *> dynamicColliders;
    std::unordered_set<DynamicCollider<T> *> ghostColliders;
    std::unordered_map<Maths::Vec2<int32_t>, std::unordered_set<DynamicCollider<T> *>> dynamicSpacialHash;

protected:
    void enableCollision(Collider<T> &collider) {
        if (!collider.enable)
            collider.enable = true;
        else
            throw Exception("Collider already enabled");

        for (const auto &position : collider.form.rasterize())
            if (!spacialHash[position].insert(&collider).second)
                throw Exception("Insertion in Spacial Hash but element already exist");
    }

    void disableCollision(Collider<T> &collider) {
        if (collider.enable)
            collider.enable = false;
        else
            throw Exception("Collider already disabled");

        for (const auto &position : collider.form.rasterize())
            if (!spacialHash[position].erase(&collider))
                throw Exception("Remove in Spacial Hash but no element");
    }

    void enableCollision(DynamicCollider<T> &collider) {
        if (!collider.enable)
            collider.enable = true;
        else
            throw Exception("Dynamic Collider already enabled");

        dynamicColliders.emplace(&collider);
    }

    void disableCollision(DynamicCollider<T> &collider) {
        if (collider.enable)
            collider.enable = false;
        else
            throw Exception("Dynamic Collider already disabled");

        dynamicColliders.erase(&collider);
    }

    void enableGhostCollision(DynamicCollider<T> &collider) {
        if (!collider.enable)
            collider.enable = true;
        else
            throw Exception("Ghost Collider already enabled");

        ghostColliders.emplace(&collider);
    }

    void disableGhostCollision(DynamicCollider<T> &collider) {
        if (collider.enable)
            collider.enable = false;
        else
            throw Exception("Ghost Collider already disabled");

        ghostColliders.erase(&collider);
    }

    template<class U>
    void targetOverlap(DynamicCollider<U> *collider) {
        std::unordered_set<Collider<T> *> objectsToTest;

        auto rasters = collider->form.rasterize();

        for (const auto &position : rasters) {
            for (Collider<T> *target : spacialHash[position])
                objectsToTest.emplace(target);
            for (DynamicCollider<T> *target : dynamicSpacialHash[position])
                if (target != (void *) collider)
                    objectsToTest.emplace(target);
        }

        for (Collider<T> *t : objectsToTest) {
            if (collider->form.overlap(t->form)) {
                if (collider->hitting.find(t) == collider->hitting.end()) {
                    collider->hitting.emplace(t);
                    collider->hitStart(t);
                } else
                    collider->hittingClone.erase(t);
            }
        }
    }

    template<class U>
    void overlap(FormDatabase<U> &database) {
        for (auto c : database.dynamicColliders)
            targetOverlap(c);
        for (auto c : database.ghostColliders)
            targetOverlap(c);
    }

    void preCollisionUpdate() {
        for (DynamicCollider<T> *t : dynamicColliders)
            for (const auto &position : t->form.rasterize())
                if (!dynamicSpacialHash[position].insert(t).second)
                    throw Exception(std::string("Insertion ") + typeid(t).name() + " in dynamic Spacial Hash but element already exist");
    }

    void postCollisionUpdate(DynamicCollider<T> *dynamicCollider, float timeFlow) {
        for (PhysicalObject *physicalObjects : dynamicCollider->hittingClone) {
            dynamicCollider->hitting.erase(physicalObjects);
            dynamicCollider->hitEnd(physicalObjects);
        }
        dynamicCollider->hittingClone = dynamicCollider->hitting;

        dynamicCollider->postCollisionUpdate(timeFlow);
    }

    void postCollisionUpdate(float timeFlow) {
        dynamicSpacialHash.clear();

        for (auto collider : dynamicColliders)
            postCollisionUpdate(collider, timeFlow);
        for (auto collider : ghostColliders)
            postCollisionUpdate(collider, timeFlow);
    }
};

template<class... Types>
class CollisionDetectorTemplate : public FormDatabase<Types>... {
private:
public:
    using FormDatabase<Types>::enableCollision...;
    using FormDatabase<Types>::enableGhostCollision...;

    using FormDatabase<Types>::disableCollision...;
    using FormDatabase<Types>::disableGhostCollision...;

    template<class T>
    void updateAll() {
        (FormDatabase<T>::template overlap<Types>(*this), ...);
    }

    void update(float timeFlow) {
        (FormDatabase<Types>::preCollisionUpdate(), ...);
        (updateAll<Types>(), ...);
        (FormDatabase<Types>::postCollisionUpdate(timeFlow), ...);
    }
};

typedef CollisionDetectorTemplate<Circle, Rectangle, Point, Line, RasterArea> CollisionDetector;

} // namespace Blob::Collision

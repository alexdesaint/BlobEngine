#pragma once

#include <Blob/Collision/Forms.hpp>
#include <memory>
#include <stdexcept>
#include <unordered_map>

#define HAS_FUNCTION(function, functionType)                                                                           \
    namespace has {                                                                                                    \
    namespace name {                                                                                                   \
    template<typename, typename T>                                                                                     \
    struct function {                                                                                                  \
        static_assert(std::integral_constant<T, false>::value,                                                         \
                      "Second template parameter needs to be of function type.");                                      \
    };                                                                                                                 \
    template<typename C, typename Ret, typename... Args>                                                               \
    struct function<C, Ret(Args...)> {                                                                                 \
    private:                                                                                                           \
        template<typename T>                                                                                           \
        static constexpr auto check(T *) ->                                                                            \
            typename std::is_same<decltype(std::declval<T>().function(std::declval<Args>()...)), Ret>::type;           \
                                                                                                                       \
        template<typename>                                                                                             \
        static constexpr std::false_type check(...);                                                                   \
                                                                                                                       \
        typedef decltype(check<C>(0)) type;                                                                            \
                                                                                                                       \
    public:                                                                                                            \
        static constexpr bool value = type::value;                                                                     \
        static Ret call(C &c, Args... args) { return c.function(args...); }                                            \
    };                                                                                                                 \
    }                                                                                                                  \
    template<class T>                                                                                                  \
    using function = name::function<T, functionType>;                                                                  \
    }

namespace Blob {

template<class FormType>
class Collider {
public:
    template<class... C>
    friend class CollisionDetector;
    template<class ColliderType, class... Colliders>
    friend class ColliderDatabase;

    using Form = FormType;

private:
    static constexpr bool isRaster() { return std::is_same_v<Form, Raster>; }
    static constexpr bool isRasterArea() { return std::is_same_v<Form, RasterArea>; }

    bool privateEnabled = false;

    enum {
        initNone,
        initEnableDynamicCollision,
        initEnableStaticCollision,
        initEnableGhostCollision,
        initRemove
    } initFunction = initNone;
    Form privateForm;
    std::function<void(Form &&)> privateEnableDynamicCollision = [&](Form &&form) {
        privateForm = std::move(form);
        initFunction = initEnableDynamicCollision;
    };
    std::function<void()> privateDisableDynamicCollision = [&] { initFunction = initNone; };
    std::function<void(Form &&)> privateEnableStaticCollision = [&](Form &&form) {
        privateForm = std::move(form);
        initFunction = initEnableStaticCollision;
    };
    std::function<void()> privateDisableStaticCollision = [&] { initFunction = initNone; };
    std::function<void(Form &&)> privateEnableGhostCollision = [&](Form &&form) {
        privateForm = std::move(form);
        initFunction = initEnableGhostCollision;
    };
    std::function<void()> privateDisableGhostCollision = [&] { initFunction = initNone; };
    std::function<void()> privateRemove = [&] { initFunction = initRemove; };

public:
    const bool &enabled{privateEnabled};
    const Form &form{privateForm};

    const std::function<void(Form &&)> &enableDynamicCollision{privateEnableDynamicCollision};
    const std::function<void()> &disableDynamicCollision{privateDisableDynamicCollision};
    const std::function<void(Form &&)> &enableStaticCollision{privateEnableStaticCollision};
    const std::function<void()> &disableStaticCollision{privateDisableStaticCollision};
    const std::function<void(Form &&)> &enableGhostCollision{privateEnableGhostCollision};
    const std::function<void()> &disableGhostCollision{privateDisableGhostCollision};
    const std::function<void()> &remove{privateRemove};

    Collider() = default;
    Collider(const Collider &) = delete;
    Collider(Collider &&) = delete;

protected:
    template<class Collider>
    void hitStart(Collider *object) {}

    template<class Collider>
    void hitEnd(Collider *object) {}

    /**
     * This method is called right before the collision is computed
     * @param currentForm the actual form used for the collision detection
     * @param timeFlow Time in second since list frame
     * @return the form you wish to test the next collision
     */
    virtual Form preCollisionUpdate(Form currentForm, double timeFlow) { return currentForm; }

    /**
     * This method is called right after the collision is computed and return
     * the final position that will be saved in the internal spacial definition.
     * @param currentForm the form return by last postCollisionUpdate
     * @param nextForm the form returned by last preCollisionUpdate
     * @param timeFlow Time in second sins list frame
     * @return the fianl form
     */
    virtual Form postCollisionUpdate(const Form &currentForm, Form nextForm, double timeFlow) { return nextForm; }
};

template<class ColliderType, class... Colliders>
class ColliderDatabase {
protected:
    std::unordered_map<Raster, std::unordered_set<ColliderType *>> spacialHash;

    using AllColliders = std::tuple<std::unordered_set<Colliders *>...>;
    std::unordered_map<ColliderType *, AllColliders> colliders;
    std::unordered_map<ColliderType *, AllColliders> ghostColliders;

    std::vector<std::unique_ptr<ColliderType>> data;

    template<class U>
    std::unordered_set<ColliderType *> overlapRasters(const U &form, const RasterArea &rasters) const {
        std::unordered_set<ColliderType *> collidingObjects;

        for (const Raster &position : rasters) {
            auto colliderIt = spacialHash.find(position);
            if (colliderIt == spacialHash.end())
                continue;
            for (ColliderType *target : colliderIt->second) {
                if constexpr (ColliderType::isRaster() || ColliderType::isRasterArea() || std::is_same_v<U, Raster> ||
                              std::is_same_v<U, RasterArea>)
                    collidingObjects.emplace(target);
                else if (overlap(form, target->form))
                    collidingObjects.emplace(target);
            }
        }
        return collidingObjects;
    }
};

template<class... CollidersType>
class CollisionDetector : public ColliderDatabase<CollidersType, CollidersType...>... {
private:
    template<class Collider>
    using ColliderDatabase = ColliderDatabase<Collider, CollidersType...>;
    using AllColliders = std::tuple<std::unordered_set<CollidersType *>...>;

    template<class ColliderType>
    using isCollider = std::is_base_of<Collider<typename ColliderType::Form>, ColliderType>;

    template<class ColliderType>
    constexpr void staticTest() {
        static_assert(!std::is_const_v<ColliderType>,
                      "Collider is const qualified."
                      "Collider need to be modified by the CollisionDetector.");
        static_assert(std::is_convertible_v<ColliderType *, Collider<typename ColliderType::Form> *>,
                      "Colliders need to have DynamicCollider or StaticCollider as "
                      "accessible parent. ");
        static_assert(isCollider<ColliderType>(),
                      "Colliders need to have DynamicCollider or StaticCollider as "
                      "accessible parent.");

        static_assert((std::is_same_v<ColliderType, CollidersType> || ...),
                      "enableCollision called with type not in the collision detector");
    }

public:
private:
    template<class TestedCollider, class ColliderType, class Form>
    std::unordered_set<TestedCollider *> testColliderDatabase(std::unordered_set<TestedCollider *> &hitting,
                                                              ColliderType *dynamicCollider,
                                                              const Form &form,
                                                              const RasterArea &rasters) const {

        std::unordered_set<TestedCollider *> collidingObjects =
            ColliderDatabase<TestedCollider>::template overlapRasters<Form>(form, rasters);

        for (TestedCollider *collidingObject : collidingObjects)
            if (hitting.erase(collidingObject) == 0)
                dynamicCollider->hitStart(collidingObject);
        for (TestedCollider *oldObject : hitting)
            dynamicCollider->hitEnd(oldObject);

        return collidingObjects;
    }

    template<class ColliderType>
    void updateOneCollider(ColliderType *dynamicCollider, AllColliders &hitting, double timeFlow) {
        auto nextForm = dynamicCollider->preCollisionUpdate(dynamicCollider->form, timeFlow);

        auto rasters = rasterize(nextForm);

        ((std::get<std::unordered_set<CollidersType *>>(hitting) =
              testColliderDatabase<CollidersType>(std::get<std::unordered_set<CollidersType *>>(hitting),
                                                  dynamicCollider,
                                                  nextForm,
                                                  rasters)),
         ...);

        dynamicCollider->privateForm = dynamicCollider->postCollisionUpdate(dynamicCollider->form, nextForm, timeFlow);
    }

    template<class ColliderType>
    void testDynamicColliderDatabase(double timeFlow) {
        for (auto &[dynamicCollider, hitting] : ColliderDatabase<ColliderType>::colliders) {
            for (const auto &position : rasterize(dynamicCollider->form))
                if (ColliderDatabase<ColliderType>::spacialHash[position].erase(dynamicCollider) == 0)
                    throw std::runtime_error(std::string("erase ") + typeid(dynamicCollider).name() +
                                             " in dynamic Spacial Hash but element does not exist");

            updateOneCollider(dynamicCollider, hitting, timeFlow);

            for (const auto &position : rasterize(dynamicCollider->form))
                if (!ColliderDatabase<ColliderType>::spacialHash[position].insert(dynamicCollider).second)
                    throw std::runtime_error(std::string("insert ") + typeid(dynamicCollider).name() +
                                             " in dynamic Spacial Hash but element already exist");
        }
        for (auto &[ghostCollider, hitting] : ColliderDatabase<ColliderType>::ghostColliders)
            updateOneCollider(ghostCollider, hitting, timeFlow);
    }

    template<class ColliderType>
    constexpr void testColliderDatabase(double timeFlow) {
        if constexpr (isCollider<ColliderType>())
            testDynamicColliderDatabase<ColliderType>(timeFlow);
    }

public:
    void update(double timeFlow) { (testColliderDatabase<CollidersType>(timeFlow), ...); }

    template<class ColliderType>
    AllColliders testCollider(const ColliderType &collider) const {
        auto r = rasterize(collider);
        AllColliders allColliders;
        ((std::get<std::unordered_set<CollidersType *>>(allColliders) =
              ColliderDatabase<CollidersType>::overlapRasters(collider, r)),
         ...);
        return allColliders;
    }

    // collider function caller
private:
    template<class Test, class ColliderType, typename... Args>
    void callColliderDatabase(Args... args) {
        if constexpr (Test::value) {
            for (auto &collider : ColliderDatabase<ColliderType>::data)
                Test::call(*collider, args...);
        }
    }

public:
    template<template<typename> class Test, class... Args>
    void callAll(Args... args) {
        (callColliderDatabase<Test<CollidersType>, CollidersType>(args...), ...);
    }

    // data storage
    template<class ColliderType, class... Args>
    ColliderType &emplace(Args... args) {
        staticTest<ColliderType>();
        std::unique_ptr<ColliderType> colliderUniqPtr = std::make_unique<ColliderType>(args...);
        auto collider = colliderUniqPtr.get();

        // Static collision
        collider->privateEnableStaticCollision = [&, collider](typename ColliderType::Form &&form) {
            collider->privateEnabled = true;
            collider->privateForm = std::move(form);
            auto &localHash = ColliderDatabase<ColliderType>::spacialHash;
            for (const auto &position : rasterize(collider->form))
                if (!localHash[position].insert(collider).second)
                    throw std::runtime_error("Insertion in Spacial Hash but element already exist");
        };
        collider->privateDisableStaticCollision = [&, collider] {
            collider->privateEnabled = false;
            auto &localHash = ColliderDatabase<ColliderType>::spacialHash;
            for (const auto &position : rasterize(collider->form))
                if (!localHash[position].erase(collider))
                    throw std::runtime_error("Remove in Spacial Hash but no element");
        };
        if (collider->initFunction == ColliderType::initEnableStaticCollision)
            collider->privateEnableStaticCollision(std::move(collider->privateForm));

        // Dynamic collision
        collider->privateEnableDynamicCollision = [&, collider](typename ColliderType::Form &&form) {
            collider->privateEnabled = true;
            collider->privateForm = std::move(form);
            auto &localHash = ColliderDatabase<ColliderType>::spacialHash;
            for (const auto &position : rasterize(collider->form))
                if (!localHash[position].insert(collider).second)
                    throw std::runtime_error("Insertion in Spacial Hash but element already exist");
            ColliderDatabase<ColliderType>::colliders[collider] = {};
        };
        collider->privateDisableDynamicCollision = [&, collider] {
            collider->privateEnabled = false;
            auto &localHash = ColliderDatabase<ColliderType>::spacialHash;
            for (const auto &position : rasterize(collider->form))
                if (!localHash[position].erase(collider))
                    throw std::runtime_error("Remove in Spacial Hash but no element");
            ColliderDatabase<ColliderType>::colliders.erase(collider);
        };
        if (collider->initFunction == ColliderType::initEnableDynamicCollision)
            collider->privateEnableDynamicCollision(std::move(collider->privateForm));

        // Ghost collision
        collider->privateEnableGhostCollision = [&, collider](typename ColliderType::Form &&form) {
            collider->privateEnabled = true;
            collider->privateForm = std::move(form);
            ColliderDatabase<ColliderType>::ghostColliders[collider] = {};
        };
        collider->privateDisableGhostCollision = [&, collider] {
            collider->privateEnabled = false;
            ColliderDatabase<ColliderType>::ghostColliders.erase(collider);
        };
        if (collider->initFunction == ColliderType::initEnableGhostCollision)
            collider->privateEnableGhostCollision(std::move(collider->privateForm));

        // remove
        collider->privateRemove = [&, collider] {};
        if (collider->initFunction == ColliderType::initRemove)
            collider->privateRemove();

        return *ColliderDatabase<ColliderType>::data.emplace_back(std::move(colliderUniqPtr));
    }
};

} // namespace Blob

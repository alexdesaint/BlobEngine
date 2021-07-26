#pragma once

#include <Blob/Collision/Forms.hpp>
#include <Blob/Core/Exception.hpp>

#include <iostream>
#include <type_traits>
#include <unordered_map>
#include <variant>

#ifdef BLOB_COLLISION_IMGUI
#include <imgui.h>
#include <sstream>
#endif

namespace Blob {

class PhysicalObject {
    template<class... Colliders>
    friend class GeneralCollisionDetector;

private:
    bool enable = false;

protected:
    explicit PhysicalObject(const std::type_info &objectType) :
        objectType(objectType) {}

public:
    const std::type_info &objectType;

    PhysicalObject(const PhysicalObject &) = delete;

    PhysicalObject(PhysicalObject &&) = delete;

    virtual ~PhysicalObject() = default;
};

template<class Form>
class StaticCollider : public PhysicalObject {
public:
    using FormType = Form;
    const Form form;

    StaticCollider(const std::type_info &objectType, Form &&form) :
        PhysicalObject(objectType), form(form) {}
};

template<class Form, class... Colliders>
class DynamicCollider : public PhysicalObject {
    template<class... C>
    friend class GeneralCollisionDetector;

private:
    Form privateForm;

public:
    using OneForm = std::variant<Colliders *...>;
    using FormType = Form;
    const Form &form{privateForm};

protected:
    std::unordered_set<OneForm> hitting;

    const std::unordered_set<OneForm> &hittingObjects{hitting};
    explicit DynamicCollider(const std::type_info &objectType, Form &&form) :
        PhysicalObject(objectType), privateForm(form) {}

    virtual void hitStart(const OneForm &object) {}

    virtual void hitEnd(const OneForm &object) {}

    /**
     * This method is called right before the collision is computed
     * @param currentForm the actual form used for the collision detection
     * @param timeFlow Time in second since list frame
     * @return the form you wish to test the next collision
     */
    virtual Form preCollisionUpdate(Form currentForm, float timeFlow) {
        return currentForm;
    }

    /**
     * This method is called right after the collision is computed and return
     * the final position that will be saved in the internal spacial definition.
     * In this method CollisionDetector::testCollision will never detect itself
     * because it is not in the internal spacial definition yet.
     * @param currentForm Time in second sins list frame
     * @param nextForm Time in second sins list frame
     * @param timeFlow Time in second sins list frame
     * @return the fianl position
     */
    virtual Form postCollisionUpdate(const Form &currentForm,
                                     Form nextForm,
                                     float timeFlow) {
        return nextForm;
    }

public:
    const Form &collider{form};
};

template<class Collier>
class ColliderDatabase {
protected:
    std::unordered_map<Vec2<int32_t>, std::unordered_set<Collier *>>
        spacialHash;

    std::unordered_set<Collier *> colliders;

    template<class U, class... Colliders>
    void
    overlap(std::unordered_set<std::variant<Colliders *...>> &collidingObjects,
            const U &form,
            std::unordered_set<Vec2<int32_t>> rasters) const {
        for (const Vec2<int32_t> &position : rasters) {
            auto positions = spacialHash.find(position);
            if (positions != spacialHash.end())
                for (Collier *target : positions->second)
                    if (form.overlap(target->form))
                        collidingObjects.emplace(target);
        }
    }
};

template<class Collier>
class GhostFormDatabase {
protected:
    std::unordered_set<Collier *> colliders;

public:
    void enableGhostCollision(Collier &collider) {
        if (!collider.enable)
            collider.enable = true;
        else
            throw Exception("Ghost Collider already enabled");

        colliders.emplace(&collider);
    }

    void disableGhostCollision(Collier &collider) {
        if (collider.enable)
            collider.enable = false;
        else
            throw Exception("Ghost Collider already disabled");

        colliders.erase(&collider);
    }
};

template<class... Colliders>
class GeneralCollisionDetector : public ColliderDatabase<Colliders>... {
public:
    template<class Collider>
    using DynamicCollider = DynamicCollider<Collider, Colliders...>;

    using OneCollider = std::variant<Colliders *...>;

    template<class Collider>
    void enableCollision(Collider &collider) {
        static_assert(
            (std::is_same_v<Collider, Colliders> || ...),
            "enableCollision called with type not in the collision detector");

        if (!collider.enable)
            collider.enable = true;
        else
            throw Exception("Collider already enabled");

        auto &localHash = ColliderDatabase<Collider>::spacialHash;

        for (const auto &position : collider.form.rasterize())
            if (!localHash[position].insert(&collider).second)
                throw Exception(
                    "Insertion in Spacial Hash but element already exist");

        if constexpr (std::is_base_of<
                          DynamicCollider<typename Collider::FormType>,
                          Collider>())
            ColliderDatabase<Collider>::colliders.emplace(&collider);
    }

    template<class Collider>
    void disableCollision(Collider &collider) {
        if (collider.enable)
            collider.enable = false;
        else
            throw Exception("Collider already disabled");

        auto &localHash = ColliderDatabase<Collider>::spacialHash;

        for (const auto &position : collider.form.rasterize())
            if (!localHash[position].erase(&collider))
                throw Exception("Remove in Spacial Hash but no element");

        if constexpr (std::is_base_of<
                          DynamicCollider<typename Collider::FormType>,
                          Collider>())
            ColliderDatabase<Collider>::colliders.erase(&collider);
    }

    template<class Form>
    std::unordered_set<OneCollider> testCollision(const Form &form) const {
        auto rasters = form.rasterize();

        std::unordered_set<OneCollider> collidingObjects;

        (ColliderDatabase<Colliders>::template overlap<Form>(collidingObjects,
                                                             form,
                                                             rasters),
         ...);
        return collidingObjects;
    }

private:
    template<class Collider>
    void updateOneForm(DynamicCollider<Collider> *dynamicCollider,
                       float timeFlow) {
        // 1: get the nex position of the collider
        auto nextForm =
            dynamicCollider->preCollisionUpdate(dynamicCollider->form,
                                                timeFlow);

        std::unordered_set<OneCollider> hitedTargets = testCollision(nextForm);

        for (const OneCollider &physicalObjects : hitedTargets)
            if (dynamicCollider->hitting.erase(physicalObjects) == 0)
                dynamicCollider->hitStart(physicalObjects);
        for (const OneCollider &physicalObjects : dynamicCollider->hitting)
            dynamicCollider->hitEnd(physicalObjects);

        dynamicCollider->hitting = std::move(hitedTargets);

        // 3: tell set the new position of the collider
        dynamicCollider->privateForm =
            dynamicCollider->postCollisionUpdate(dynamicCollider->form,
                                                 nextForm,
                                                 timeFlow);
    }

    template<class Collider>
    void testDynamicColliderDatabase(float timeFlow) {
        for (auto dynamicCollider : ColliderDatabase<Collider>::colliders) {
            // Remove the collider from the dynamicSpacialHash so he cannot find
            // himself
            for (const auto &position : dynamicCollider->form.rasterize())
                if (ColliderDatabase<Collider>::spacialHash[position].erase(
                        dynamicCollider) == 0)
                    throw Exception(
                        std::string("erase ") + typeid(dynamicCollider).name() +
                        " in dynamic Spacial Hash but element does not exist");

            updateOneForm(dynamicCollider, timeFlow);

            // set back the new position in the dynamicSpacialHash
            for (const auto &position : dynamicCollider->form.rasterize())
                if (!ColliderDatabase<Collider>::spacialHash[position]
                         .insert(dynamicCollider)
                         .second)
                    throw Exception(
                        std::string("insert ") +
                        typeid(dynamicCollider).name() +
                        " in dynamic Spacial Hash but element already exist");
        }
    }

    template<class Collider>
    void testGhostColliderDatabase(float timeFlow) {
        for (auto ghostCollider : ColliderDatabase<Collider>::colliders)
            updateOneForm(ghostCollider, timeFlow);
    }

    template<class Collider>
    constexpr void testColliderDatabase(float timeFlow) {
        if constexpr (std::is_base_of<
                          DynamicCollider<typename Collider::FormType>,
                          Collider>())
            testDynamicColliderDatabase<Collider>(timeFlow);
    }

public:
    void update(float timeFlow) {
        (testColliderDatabase<Colliders>(timeFlow), ...);
    }
    /*
    #ifdef BLOB_COLLISION_IMGUI
        bool ImGuiDebugWindowVisible = true;

        template<class T>
        void printSingleDynamicDatabse() {
            for (auto dynamicCollider : FormDb<T>::dynamicColliders) {
                ImGui::TableNextColumn();
                ImGui::Text("%llu", dynamicCollider);
                ImGui::TableNextColumn();
                std::stringstream ss;
                ss << dynamicCollider->form;
                ImGui::Text("%s", ss.str().c_str());
            }
        }

        template<class T>
        void printSingleSpacialHash(const Vec2<int32_t> &scanPos) {
            for (auto colliders : FormDb<T>::staticSpacialHash[scanPos]) {
                ImGui::TableNextColumn();
                ImGui::Text("%llu", colliders);
                ImGui::TableNextColumn();
                std::stringstream ss;
                ss << colliders->form;
                ImGui::Text("%s", ss.str().c_str());
            }
            for (auto colliders : FormDb<T>::dynamicSpacialHash[scanPos]) {
                ImGui::TableNextColumn();
                ImGui::Text("%llu", colliders);
                ImGui::TableNextColumn();
                std::stringstream ss;
                ss << colliders->form;
                ImGui::Text("%s", ss.str().c_str());
            }
        }

        constexpr static float zoomIn = 20;

        void draw(const Circle &c, ImDrawList *draw_list, Vec2<> offset) {
            draw_list->AddCircleFilled(offset + c.position * zoomIn,
                                       c.rayon * zoomIn,
                                       ImColor(ImVec4(1.0f, 1.0f, 0.4f, 1.0f)),
                                       10.f);
        }

        void draw(const RasterArea &c, ImDrawList *draw_list, Vec2<> offset) {}

        void draw(const Rectangle &c, ImDrawList *draw_list, Vec2<> offset) {}

        void draw(const Point &c, ImDrawList *draw_list, Vec2<> offset) {}

        void draw(const Line &c, ImDrawList *draw_list, Vec2<> offset) {}

        template<class T>
        void drawSpacialHash(ImDrawList *draw_list, Vec2<> offset) {
            for (const auto &[pos, colliders] : FormDb<T>::staticSpacialHash) {
                if (!colliders.empty())
                    draw_list->AddRect(
                        offset + pos.template cast<float>() * zoomIn,
                        offset + pos.template cast<float>() * zoomIn + zoomIn,
                        ImColor(ImVec4(0.8f, 0.8f, 0.4f, 1.0f)),
                        0.0f,
                        ImDrawFlags_None,
                        1.f);
                for (const auto &c : colliders)
                    draw(c->form, draw_list, offset);
            }
            for (const auto &[pos, colliders] : FormDb<T>::dynamicSpacialHash) {
                if (!colliders.empty())
                    draw_list->AddRect(
                        offset + pos.template cast<float>() * zoomIn,
                        offset + pos.template cast<float>() * zoomIn + zoomIn,
                        ImColor(ImVec4(0.0f, 1.0f, 0.4f, 1.0f)),
                        0.0f,
                        ImDrawFlags_None,
                        1.f);
                for (const auto &c : colliders)
                    draw(c->form, draw_list, offset);
            }
        }

        void ImGuiDebugWindow() {
            ImGui::Begin("CollisionDetector Debug", &ImGuiDebugWindowVisible);
            ImDrawList *draw_list = ImGui::GetWindowDrawList();
            const ImVec2 p = ImGui::GetCursorScreenPos();
            (drawSpacialHash<Types>(draw_list, p), ...);
            ImGui::End();
        }
    #endif
    */
};

// typedef CollisionDetectorTemplate<Circle, Rectangle, Point, Line, RasterArea>
//     CollisionDetector;

using OldCollisionDetector =
    GeneralCollisionDetector<StaticCollider<Circle>,
                             StaticCollider<Rectangle>,
                             StaticCollider<Point>,
                             StaticCollider<Line>,
                             StaticCollider<RasterArea>,
                             DynamicCollider<Circle>,
                             DynamicCollider<Rectangle>,
                             DynamicCollider<Point>,
                             DynamicCollider<Line>,
                             DynamicCollider<RasterArea>
                             //,
                             // GhostCollider<Circle>,
                             // GhostCollider<Rectangle>,
                             // GhostCollider<Point>,
                             // GhostCollider<Line>,
                             // GhostCollider<RasterArea>
                             >;

} // namespace Blob

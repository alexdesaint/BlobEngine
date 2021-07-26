#pragma once

#include <Blob/Collision/Forms.hpp>
#include <Blob/Core/Exception.hpp>

#include <iostream>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <variant>

#ifdef BLOB_COLLISION_IMGUI
#include <imgui.h>
#include <sstream>
#endif

namespace Blob {

template<class Form>
class StaticCollider {
public:
    using FormType = Form;
    const Form form;

    StaticCollider(Form &&form) : form(form) {}
};

template<class Form>
class DynamicCollider {
    template<class... C>
    friend class GeneralCollisionDetector;

private:
    Form privateForm;

public:
    using FormType = Form;
    const Form &form{privateForm};

protected:
    explicit DynamicCollider(Form &&form) : privateForm(form) {}

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

template<class Collider, class... Colliders>
class ColliderDatabase {
protected:
    std::unordered_map<Vec2<int32_t>, std::unordered_set<Collider *>>
        spacialHash;

    using AllColliders = std::tuple<std::unordered_set<Colliders *>...>;
    std::unordered_map<Collider *, AllColliders> colliders;
    std::unordered_map<Collider *, AllColliders> ghostColliders;

    template<class Form>
    void
    overlap(std::unordered_set<std::variant<Colliders *...>> &collidingObjects,
            const Form &form,
            std::unordered_set<Vec2<int32_t>> rasters) const {
        for (const Vec2<int32_t> &position : rasters) {
            auto positions = spacialHash.find(position);
            if (positions != spacialHash.end())
                for (Collider *target : positions->second)
                    if (form.overlap(target->form))
                        collidingObjects.emplace(target);
        }
    }

    template<class U>
    std::unordered_set<Collider *>
    overlap(const U &form, std::unordered_set<Vec2<int32_t>> rasters) const {
        std::unordered_set<Collider *> collidingObjects;
        for (const Vec2<int32_t> &position : rasters) {
            auto positions = spacialHash.find(position);
            if (positions != spacialHash.end())
                for (Collider *target : positions->second)
                    if (form.overlap(target->form))
                        collidingObjects.emplace(target);
        }
        return collidingObjects;
    }
};

template<class... Colliders>
class GeneralCollisionDetector :
    public ColliderDatabase<Colliders, Colliders...>... {
public:
    template<class Collider>
    using ColliderDatabase = ColliderDatabase<Collider, Colliders...>;

    using OneCollider = std::variant<Colliders *...>;
    using AllColliders = std::tuple<std::unordered_set<Colliders *>...>;

    template<class Collider>
    void enableCollision(Collider &collider) {
        static_assert(
            (std::is_same_v<Collider, Colliders> || ...),
            "enableCollision called with type not in the collision detector");
        static_assert(
            (std::is_same_v<Collider, Colliders> || ...),
            "enableCollision called with type not in the collision detector");

        auto &localHash = ColliderDatabase<Collider>::spacialHash;

        for (const auto &position : collider.form.rasterize())
            if (!localHash[position].insert(&collider).second)
                throw Exception(
                    "Insertion in Spacial Hash but element already exist");

        if constexpr (std::is_base_of<
                          DynamicCollider<typename Collider::FormType>,
                          Collider>())
            ColliderDatabase<Collider>::colliders[&collider] = {};
    }

    template<class Collider>
    void disableCollision(Collider &collider) {
        auto &localHash = ColliderDatabase<Collider>::spacialHash;

        for (const auto &position : collider.form.rasterize())
            if (!localHash[position].erase(&collider))
                throw Exception("Remove in Spacial Hash but no element");

        if constexpr (std::is_base_of<
                          DynamicCollider<typename Collider::FormType>,
                          Collider>())
            ColliderDatabase<Collider>::colliders.erase(&collider);
    }

    template<class Collider>
    void enableGhostCollision(Collider &collider) {
        static_assert(
            std::is_base_of<DynamicCollider<typename Collider::FormType>,
                            Collider>(),
            "Only dynamic colliders can be ghost collider");

        ColliderDatabase<Collider>::ghostColliders[&collider] = {};
    }

    template<class Collider>
    void disableGhostCollision(Collider &collider) {
        static_assert(
            std::is_base_of<DynamicCollider<typename Collider::FormType>,
                            Collider>(),
            "Only dynamic colliders can be ghost collider");

        ColliderDatabase<Collider>::ghostColliders.erase(&collider);
    }

private:
    template<class TestedCollider, class Collider, class Form>
    std::unordered_set<TestedCollider *> testColliderDatabase(
        std::unordered_set<TestedCollider *> &hitting,
        Collider *dynamicCollider,
        const Form &form,
        const std::unordered_set<Vec2<int32_t>> &rasters) const {

        std::unordered_set<TestedCollider *> collidingObjects =
            ColliderDatabase<TestedCollider>::template overlap<Form>(form,
                                                                     rasters);

        for (TestedCollider *collidingObject : collidingObjects)
            if (hitting.erase(collidingObject) == 0)
                dynamicCollider->hitStart(collidingObject);
        for (TestedCollider *oldObject : hitting)
            dynamicCollider->hitEnd(oldObject);

        return collidingObjects;
    }

    template<class Collider>
    void updateOneCollider(Collider *dynamicCollider,
                           AllColliders &hitting,
                           float timeFlow) {
        auto nextForm =
            dynamicCollider->preCollisionUpdate(dynamicCollider->form,
                                                timeFlow);

        auto rasters = nextForm.rasterize();

        ((std::get<std::unordered_set<Colliders *>>(hitting) =
              testColliderDatabase<Colliders>(
                  std::get<std::unordered_set<Colliders *>>(hitting),
                  dynamicCollider,
                  nextForm,
                  rasters)),
         ...);

        dynamicCollider->privateForm =
            dynamicCollider->postCollisionUpdate(dynamicCollider->form,
                                                 nextForm,
                                                 timeFlow);
    }

    template<class Collider>
    void testDynamicColliderDatabase(float timeFlow) {
        for (auto &[dynamicCollider, hitting] :
             ColliderDatabase<Collider>::colliders) {
            for (const auto &position : dynamicCollider->form.rasterize())
                if (ColliderDatabase<Collider>::spacialHash[position].erase(
                        dynamicCollider) == 0)
                    throw Exception(
                        std::string("erase ") + typeid(dynamicCollider).name() +
                        " in dynamic Spacial Hash but element does not exist");

            updateOneCollider(dynamicCollider, hitting, timeFlow);

            for (const auto &position : dynamicCollider->form.rasterize())
                if (!ColliderDatabase<Collider>::spacialHash[position]
                         .insert(dynamicCollider)
                         .second)
                    throw Exception(
                        std::string("insert ") +
                        typeid(dynamicCollider).name() +
                        " in dynamic Spacial Hash but element already exist");
        }
        for (auto &[ghostCollider, hitting] :
             ColliderDatabase<Collider>::ghostColliders)
            updateOneCollider(ghostCollider, hitting, timeFlow);
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

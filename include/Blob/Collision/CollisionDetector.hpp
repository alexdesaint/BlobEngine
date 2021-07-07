#pragma once

#include <Blob/Collision/Forms.hpp>
#include <Blob/Core/Exception.hpp>

#include <iostream>
#include <unordered_map>

#ifdef BLOB_COLLISION_IMGUI
#include <imgui.h>
#include <sstream>
#endif

namespace Blob {

class PhysicalObject {
    template<typename U>
    friend class FormDatabase;

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

template<class T>
class StaticCollider : public PhysicalObject {
    template<typename U>
    friend class FormDatabase;

public:
    const T form;

    StaticCollider(const std::type_info &objectType, T &&form) :
        PhysicalObject(objectType), form(form) {}
};

template<class T>
class DynamicCollider : public PhysicalObject {
    template<typename U>
    friend class FormDatabase;
    template<class... Types>
    friend class CollisionDetectorTemplate;

private:
    std::unordered_set<PhysicalObject *> hitting;
    T form;

protected:
    const std::unordered_set<PhysicalObject *> &hittingObjects{hitting};
    explicit DynamicCollider(const std::type_info &objectType, T &&form) :
        PhysicalObject(objectType), form(form) {}

    virtual void hitStart(PhysicalObject *object) {}

    virtual void hitEnd(PhysicalObject *object) {}

    /**
     * This method is called right before the collision is computed
     * @param currentForm the actual form used for the collision detection
     * @param timeFlow Time in second sinse list frame
     * @return the form you wish to test the next collision
     */
    virtual T preCollisionUpdate(T currentForm, float timeFlow) {
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
    virtual T
    postCollisionUpdate(const T &currentForm, T nextForm, float timeFlow) {
        return nextForm;
    }

public:
    const T &collider{form};
};

template<class T>
class FormDatabase {
    template<typename U>
    friend class FormDatabase;

protected:
    std::unordered_map<Vec2<int32_t>, std::unordered_set<StaticCollider<T> *>>
        staticSpacialHash;
    std::unordered_map<Vec2<int32_t>, std::unordered_set<DynamicCollider<T> *>>
        dynamicSpacialHash;
    std::unordered_set<DynamicCollider<T> *> dynamicColliders;
    std::unordered_set<DynamicCollider<T> *> ghostColliders;

protected:
    void enableCollision(StaticCollider<T> &collider) {
        if (!collider.enable)
            collider.enable = true;
        else
            throw Exception("Collider already enabled");

        for (const auto &position : collider.form.rasterize())
            if (!staticSpacialHash[position].insert(&collider).second)
                throw Exception(
                    "Insertion in Spacial Hash but element already exist");
    }

    void disableCollision(StaticCollider<T> &collider) {
        if (collider.enable)
            collider.enable = false;
        else
            throw Exception("Collider already disabled");

        for (const auto &position : collider.form.rasterize())
            if (!staticSpacialHash[position].erase(&collider))
                throw Exception("Remove in Spacial Hash but no element");
    }

    void enableCollision(DynamicCollider<T> &collider) {
        if (!collider.enable)
            collider.enable = true;
        else
            throw Exception("Dynamic Collider already enabled");

        for (const auto &position : collider.form.rasterize())
            if (!dynamicSpacialHash[position].insert(&collider).second)
                throw Exception(
                    "Insertion in Spacial Hash but element already exist");
        dynamicColliders.emplace(&collider);
    }

    void disableCollision(DynamicCollider<T> &collider) {
        if (collider.enable)
            collider.enable = false;
        else
            throw Exception("Dynamic Collider already disabled");

        for (const auto &position : collider.form.rasterize())
            if (!dynamicSpacialHash[position].erase(&collider))
                throw Exception("Remove in Spacial Hash but no element");

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
    void overlap(std::unordered_set<PhysicalObject *> &collidingObjects,
                 const U &form,
                 std::unordered_set<Vec2<int32_t>> rasters) const {
        for (const Vec2<int32_t> &position : rasters) {
            {
                auto positions = staticSpacialHash.find(position);
                if (positions != staticSpacialHash.end())
                    for (StaticCollider<T> *target : positions->second)
                        if (form.overlap(target->form))
                            collidingObjects.emplace(target);
            }
            {
                auto positions = dynamicSpacialHash.find(position);
                if (positions != dynamicSpacialHash.end())
                    for (DynamicCollider<T> *target : positions->second)
                        if (form.overlap(target->form))
                            collidingObjects.emplace(target);
            }
        }
    }
};

template<class... Types>
class CollisionDetectorTemplate : public FormDatabase<Types>... {
private:
    template<class T>
    void updateOneForm(DynamicCollider<T> *dynamicCollider, float timeFlow) {
        // 1: get the nex position of the collider
        auto nextForm =
            dynamicCollider->preCollisionUpdate(dynamicCollider->form,
                                                timeFlow);

        std::unordered_set<PhysicalObject *> hitedTargets =
            testCollision(nextForm);

        for (PhysicalObject *physicalObjects : hitedTargets) {
            if (dynamicCollider->hitting.erase(physicalObjects) == 0)
                dynamicCollider->hitStart(physicalObjects);
        }
        for (PhysicalObject *physicalObjects : dynamicCollider->hitting) {
            dynamicCollider->hitEnd(physicalObjects);
        }
        dynamicCollider->hitting = std::move(hitedTargets);

        // 3: tell set the new position of the collider
        dynamicCollider->form =
            dynamicCollider->postCollisionUpdate(dynamicCollider->form,
                                                 nextForm,
                                                 timeFlow);
    }

    template<class T>
    void updateOneFormDatabase(float timeFlow) {
        for (auto dynamicCollider : FormDatabase<T>::dynamicColliders) {
            // Remove the collider from the dynamicSpacialHash so he cannot find
            // himself
            for (const auto &position : dynamicCollider->form.rasterize())
                if (FormDatabase<T>::dynamicSpacialHash[position].erase(
                        dynamicCollider) == 0)
                    throw Exception(
                        std::string("erase ") + typeid(dynamicCollider).name() +
                        " in dynamic Spacial Hash but element does not exist");

            updateOneForm(dynamicCollider, timeFlow);

            // set back the new position in the dynamicSpacialHash
            for (const auto &position : dynamicCollider->form.rasterize())
                if (!FormDatabase<T>::dynamicSpacialHash[position]
                         .insert(dynamicCollider)
                         .second)
                    throw Exception(
                        std::string("insert ") +
                        typeid(dynamicCollider).name() +
                        " in dynamic Spacial Hash but element already exist");
        }
        for (auto ghostCollider : FormDatabase<T>::ghostColliders)
            updateOneForm(ghostCollider, timeFlow);
    }

public:
    using FormDatabase<Types>::enableCollision...;
    using FormDatabase<Types>::enableGhostCollision...;

    using FormDatabase<Types>::disableCollision...;
    using FormDatabase<Types>::disableGhostCollision...;

    template<class T>
    std::unordered_set<PhysicalObject *> testCollision(const T &form) const {
        auto rasters = form.rasterize();
        std::unordered_set<PhysicalObject *> collidingObjects;
        (FormDatabase<Types>::template overlap<T>(collidingObjects,
                                                  form,
                                                  rasters),
         ...);
        return collidingObjects;
    }

    void update(float timeFlow) {
        (updateOneFormDatabase<Types>(timeFlow), ...);
    }

#ifdef BLOB_COLLISION_IMGUI
    bool ImGuiDebugWindowVisible = true;
    Vec2<int32_t> scanPos;
    Circle testCircle;

    template<class T>
    void printSingleDynamicDatabse() {
        for (auto dynamicCollider : FormDatabase<T>::dynamicColliders) {
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
        for (auto colliders : FormDatabase<T>::staticSpacialHash[scanPos]) {
            ImGui::TableNextColumn();
            ImGui::Text("%llu", colliders);
            ImGui::TableNextColumn();
            std::stringstream ss;
            ss << colliders->form;
            ImGui::Text("%s", ss.str().c_str());
        }
        for (auto colliders : FormDatabase<T>::dynamicSpacialHash[scanPos]) {
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
        for (const auto &[pos, colliders] :
             FormDatabase<T>::staticSpacialHash) {
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
        for (const auto &[pos, colliders] :
             FormDatabase<T>::dynamicSpacialHash) {
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
        ImGui::BeginTable("ImGuiDebugWindow Dynamics", 2);
        (printSingleDynamicDatabse<Types>(), ...);
        ImGui::EndTable();

        ImGui::DragInt2("Scan position", &scanPos.x);
        ImGui::BeginTable("Scan position Table", 2);
        (printSingleSpacialHash<Types>(scanPos), ...);
        ImGui::EndTable();

        ImGui::DragFloat2("test circle pos", &testCircle.position.x);
        ImGui::DragFloat("test circle rayon", &testCircle.rayon);
        auto forms = testCollision(testCircle);
        for (auto f : forms) {
            ImGui::Text("%llu", f);
        }

        ImDrawList *draw_list = ImGui::GetWindowDrawList();
        const ImVec2 p = ImGui::GetCursorScreenPos();
        (drawSpacialHash<Types>(draw_list, p), ...);
        ImGui::End();
    }
#endif
};

typedef CollisionDetectorTemplate<Circle, Rectangle, Point, Line, RasterArea>
    CollisionDetector;

} // namespace Blob

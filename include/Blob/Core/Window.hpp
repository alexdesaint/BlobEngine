#pragma once

// BlobEngine
#include <Blob/Core/Camera.hpp>
#include <Blob/Core/Controls.hpp>
#include <Blob/Core/Mesh.hpp>
#include <Blob/Core/Scene.hpp>
#include <Blob/Core/Shape.hpp>
#include <Blob/GL/Window.hpp>
#include <Blob/GLFW.hpp>
#include <Blob/ImGui.hpp>
#include <Blob/Time.hpp>

// std
#include <chrono>
#include <ostream>

namespace Blob::Core {

class Window : public GLFW::Window, private GL::Window, public Maths::ProjectionTransform {
private:
    ImGui::Context imgui;

    Camera &camera;

    // time counting
    Time::TimePoint lastFrameTime;
    Time::Duration fpsCouner{0};

    void windowResized() final;

    void framebufferResized() final;

    void characterInput(unsigned int c) final;

    Keyboard keyboard;
    bool keyboardUpdated = false;
    void keyboardUpdate(int key, bool pressed) final;

public:
    static float timeFlow;

    explicit Window(Camera &camera, bool fullScreen = false, Maths::Vec2<int> size = {640, 480});

    ~Window();

    void draw(const Primitive &primitive, const Maths::Mat4 &sceneModel = Maths::Mat4()) const;
    void draw(const Mesh &mesh, const Maths::Mat4 &sceneModel = Maths::Mat4()) const;
    void draw(const Shape &shape, const Maths::Mat4 &sceneModel = Maths::Mat4()) const;
    void draw(const Scene &scene, const Maths::Mat4 &sceneModel) const;
    void draw(const Scene &scene) const;

    void setCamera(Camera &camera);

    float display();

    Maths::Vec3<float> getWorldPosition();
};

} // namespace Blob::Core

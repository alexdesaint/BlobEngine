#pragma once

// BlobEngine
#include <Blob/Camera.hpp>
#include <Blob/Controls.hpp>
#include <Blob/GL/Core.hpp>
#include <Blob/GLFW.hpp>
#include <Blob/ImGui.hpp>
#include <Blob/Mesh.hpp>
#include <Blob/Scene.hpp>
#include <Blob/Shape.hpp>

// std
#include <chrono>
#include <ostream>

namespace Blob::Core {

class Window : public GLFW::Window, public GL::Context, public Maths::ProjectionTransform {
private:
    ImGui::Context imgui;

    Camera &camera;

    // time counting
    std::chrono::high_resolution_clock::time_point lastFrameTime;
    std::chrono::duration<float> fpsCouner{0};

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

    void draw(const Mesh &mesh, const Maths::Mat4 &sceneModel = Maths::Mat4()) const;
    void draw(const Shape &shape, const Maths::Mat4 &sceneModel = Maths::Mat4()) const;
    void draw(const Scene &scene) const;

    void setCamera(Camera &camera);

    float display();

    Maths::Vec3<float> getWorldPosition();
};

} // namespace Blob::Core

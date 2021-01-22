#pragma once

// BlobEngine
#include <Blob/Core/Camera.hpp>
#include <Blob/Core/Controls.hpp>
#include <Blob/Core/Mesh.hpp>
#include <Blob/Core/Scene.hpp>
#include <Blob/Core/Shape.hpp>
#include <Blob/GL/FrameBuffer.hpp>
#include <Blob/GL/Window.hpp>
#include <Blob/GLFW.hpp>
#include <Blob/ImGui.hpp>
#include <Blob/Time.hpp>

// std
#include <chrono>
#include <ostream>

namespace Blob::Core {

class Window : private GLFW::Window, private GL::Window, public Maths::ProjectionTransform {
private:
    ImGui::Context imgui;

    Camera *camera;

    // time counting
    Time::TimePoint lastFrameTime;
    Time::Duration fpsCouner{0};

    // GBuffer
    GL::FrameBuffer gFrameBuffer;
    GL::Texture gPosition, gNormal, gAlbedo;

    void windowResized() final;

    void framebufferResized() final;

    void characterInput(unsigned int c) final;

    void keyboardUpdate(int key, bool pressed) final;

    void mouseButtonUpdate(int button, bool pressed) final;
    void cursorPositionUpdate(double xpos, double ypos) final;
    void scrollUpdate(double xoffset, double yoffset) final;

public:
    Keyboard keyboard;
    Mouse mouse;
    static float timeFlow;
    using GLFW::Window::close;
    using GLFW::Window::isOpen;
    using GLFW::Window::totalTimeFlow;
    using GLFW::Window::windowSize;

    explicit Window(Camera &camera, bool fullScreen = false, Maths::Vec2<unsigned int> size = {640, 480});

    ~Window();

    void draw(const Primitive &primitive, const Maths::Mat4 &sceneModel = Maths::Mat4()) const;
    void draw(const Mesh &mesh, const Maths::Mat4 &sceneModel = Maths::Mat4()) const;
    void draw(const Shape &shape, const Maths::Mat4 &sceneModel = Maths::Mat4()) const;
    void drawTransparent(const Mesh &mesh, const Maths::Mat4 &sceneModel = Maths::Mat4()) const;
    void drawTransparent(const Shape &shape, const Maths::Mat4 &sceneModel = Maths::Mat4()) const;
    void draw(const Scene &scene, const Maths::Mat4 &sceneModel) const;
    void draw(const Scene &scene) const;

    void setCamera(Camera &camera);

    void disableMouseCursor();
    void enableMouseCursor();

    float display();

    Maths::Vec3<float> getWorldPosition();
};

} // namespace Blob::Core

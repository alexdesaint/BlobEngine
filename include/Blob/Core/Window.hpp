#pragma once

// BlobEngine
#include <Blob/Core/Camera.hpp>
#include <Blob/Core/Controls.hpp>
#include <Blob/Core/Mesh.hpp>
#include <Blob/Core/Scene.hpp>
#include <Blob/Core/Shape.hpp>
#include <Blob/GL/FrameBuffer.hpp>
#include <Blob/GLFW.hpp>
#include <Blob/GL/Window.hpp>
#include <Blob/Time.hpp>

// std
#include <chrono>
#include <ostream>

namespace Blob::Core {

class Window : private GL::Window {
private:
    //ImGui::Context imgui;

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
    void cursorPositionUpdate(double xpos, double ypos) final ;
    void scrollUpdate(double xoffset, double yoffset) final ;

public:
    Keyboard keyboard;
    Mouse mouse;
    static float timeFlow;
    using GLFW::Window::close;
    using GLFW::Window::isOpen;
    using GLFW::Window::totalTimeFlow;
    using GLFW::Window::windowSize;
    Maths::ProjectionTransform projectionTransform;
    Maths::ProjectionTransform2D projectionTransform2D;

    explicit Window(const Maths::Vec2<unsigned int>& size = {640, 480});
    ~Window();

    void draw(const Primitive2D &primitive, const Maths::ViewTransform2D &camera, const Maths::Mat3 &modelTransform = Maths::Mat3()) const;
    void draw(const Mesh2D &mesh, const Maths::ViewTransform2D &camera, const Maths::Mat3 &modelTransform = Maths::Mat3()) const;
    void draw(const Shape2D &shape, const Maths::ViewTransform2D &camera, const Maths::Mat3 &modelTransform = Maths::Mat3()) const;
    void draw(const Scene2D &scene) const;

    void draw(const Primitive &primitive, const Maths::ViewTransform &camera, const Maths::Mat4 &modelTransform = Maths::Mat4()) const;
    void draw(const Mesh &mesh, const Maths::ViewTransform &camera, const Maths::Mat4 &modelTransform = Maths::Mat4()) const;
    void draw(const Shape &shape, const Maths::ViewTransform &camera, const Maths::Mat4 &modelTransform = Maths::Mat4()) const;
    void drawTransparent(const Mesh &mesh, const Maths::ViewTransform &camera, const Maths::Mat4 &modelTransform = Maths::Mat4()) const;
    void drawTransparent(const Shape &shape, const Maths::ViewTransform &camera, const Maths::Mat4 &modelTransform = Maths::Mat4()) const;
    void draw(const Scene &scene, const Maths::Mat4 &modelTransform) const;
    void draw(const Scene &scene) const;

    void disableMouseCursor();
    void enableMouseCursor();

    float display();

    Maths::Vec3<float> getWorldPosition(const Camera &camera);
};

} // namespace Blob::Core

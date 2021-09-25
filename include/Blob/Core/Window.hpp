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

// std
#include <chrono>
#include <ostream>
#include <ratio>

namespace Blob {

class Window : private GL::Window {
private:
    // ImGui::Context imgui;

    // time counting
    std::chrono::time_point<std::chrono::system_clock> lastFrameTime;
    std::chrono::duration<float, std::milli> fpsCounter{0};

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
    ProjectionTransform projectionTransform;
    ProjectionTransform2D projectionTransform2D;

    explicit Window(const Vec2<unsigned int> &size = {640, 480});
    ~Window();

    void draw(const Primitive2D &primitive,
              const ViewTransform2D &camera,
              const Mat3 &modelTransform = Mat3()) const;
    void draw(const Mesh2D &mesh,
              const ViewTransform2D &camera,
              const Mat3 &modelTransform = Mat3()) const;
    void draw(const Shape2D &shape,
              const ViewTransform2D &camera,
              const Mat3 &modelTransform = Mat3()) const;
    void draw(const Scene2D &scene) const;

    void draw(const Primitive &primitive,
              const ViewTransform &camera,
              const Mat4 &modelTransform = Mat4()) const;
    void draw(const Mesh &mesh,
              const ViewTransform &camera,
              const Mat4 &modelTransform = Mat4()) const;
    void draw(const Shape &shape,
              const ViewTransform &camera,
              const Mat4 &modelTransform = Mat4()) const;
    void drawTransparent(const Mesh &mesh,
                         const ViewTransform &camera,
                         const Mat4 &modelTransform = Mat4()) const;
    void drawTransparent(const Shape &shape,
                         const ViewTransform &camera,
                         const Mat4 &modelTransform = Mat4()) const;
    void draw(const Scene &scene, const Mat4 &modelTransform) const;
    void draw(const Scene &scene, const ViewTransform &camera) const;
    void draw(const Scene &scene) const;

    void disableMouseCursor();
    void enableMouseCursor();

    float display();

    Vec3<float> getMousePositionInWorld(const Camera &camera);
    Vec3<float> getMousePositionInWorld(const Camera &camera, float z);
};

} // namespace Blob

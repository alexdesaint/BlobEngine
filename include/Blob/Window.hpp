#pragma once

// BlobEngine
#include <Blob/Camera.hpp>
#include <Blob/Controls.hpp>
#include <Blob/Mesh.hpp>
#include <Blob/SDL2/Window.hpp>
#include <Blob/Scene.hpp>
#include <Blob/Shape.hpp>

// std
#include <chrono>
#include <ostream>
#include <ratio>

namespace Blob {

class Window : private SDL2::Window {
private:
    // time counting
    std::chrono::time_point<std::chrono::system_clock> lastFrameTime;
    uint32_t m_currFrame;

    void windowResized() final;

    void characterInput(unsigned int c) final;

    void keyboardUpdate(int key, bool pressed) final;

    void mouseButtonUpdate(int button, bool pressed) final;
    void cursorPositionUpdate(double xpos, double ypos) final;
    void scrollUpdate(double xoffset, double yoffset) final;

public:
    Keyboard keyboard;
    Mouse mouse;
    double timeFlow;
    using SDL2::Window::close;
    using SDL2::Window::isOpen;
    using SDL2::Window::totalTimeFlow;
    using SDL2::Window::windowSize;
    ProjectionTransform projectionTransform;
    ProjectionTransform2D projectionTransform2D;

    explicit Window(const Vec2<unsigned int> &size = {640, 480},
                    std::string windowName = "BlobEngine");
    ~Window();

    void draw(const Primitive &primitive,
              const ViewTransform2D &camera,
              const Mat3 &modelTransform = Mat3()) const;
    void draw(const Mesh &mesh,
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

    double display();

    Vec3<float> getMousePositionInWorld(const Camera &camera);
    Vec3<float> getMousePositionInWorld(const Camera &camera, float z);
    std::array<Vec3<>, 4> getCameraCornersInWorld(const Camera &camera,
                                                  float z);
};

} // namespace Blob

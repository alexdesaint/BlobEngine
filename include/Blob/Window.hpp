#pragma once

// BlobEngine
#include <Blob/Camera.hpp>
#include <Blob/Context.hpp>
#include <Blob/Controls.hpp>
#include <Blob/GLFW.hpp>
#include <Blob/ImGuiContext.hpp>
#include <Blob/Mesh.hpp>
#include <Blob/Scene.hpp>
#include <Blob/Shape.hpp>

// std
#include <chrono>
#include <ostream>
#include <ratio>

namespace Blob {

class Window : public GLFW::Window {
public:
    Context context;

private:
    // time counting
    std::chrono::time_point<std::chrono::system_clock> lastFrameTime;
    uint32_t m_currFrame;
    ImGuiContext imGuiContext;
    uint32_t resetFlags = BGFX_RESET_NONE;
    // uint32_t resetFlags = BGFX_RESET_VSYNC;

    void windowResized() final;

    void keyboardUpdate(int key, bool pressed) final;

    void mouseButtonUpdate(MouseKey button, bool pressed) final;
    void cursorPositionUpdate(double xpos, double ypos) final;
    void scrollUpdate(double xoffset, double yoffset) final;

public:
    // Keyboard keyboard;
    // Mouse mouse;
    double timeFlow;
    using GLFW::Window::close;
    using GLFW::Window::isOpen;
    using GLFW::Window::totalTimeFlow;
    using GLFW::Window::windowSize;
    ProjectionTransform projectionTransform;
    ProjectionTransform2D projectionTransform2D;

    explicit Window(const Vec2<unsigned int> &size = {640, 480},
                    std::string windowName = "BlobEngine");

    void draw(const Mesh::Primitive &primitive, const Mat4 &modelTransform = {}) const;
    void draw(const Mesh &mesh, const Mat4 &modelTransform = {}) const;
    void draw(const Shape &shape, const Mat4 &modelTransform = {}) const;
    void drawTransparent(const Mesh &mesh, const Mat4 &modelTransform = {}) const;
    void drawTransparent(const Shape &shape, const Mat4 &modelTransform = {}) const;
    void draw(const Scene &scene, const Mat4 &modelTransform) const;
    void draw(const Scene &scene) const;

    void disableMouseCursor();
    void enableMouseCursor();

    double display(const ViewTransform &camera);

    Vec3<float> getMousePositionInWorld(const Camera &camera);
    Vec3<float> getMousePositionInWorld(const Camera &camera, float z);
    std::array<Vec3<>, 4> getCameraCornersInWorld(const Camera &camera, float z);
};

} // namespace Blob

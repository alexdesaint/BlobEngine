#pragma once

// BlobEngine
#include <Blob/Camera.hpp>
#include <Blob/ProjectionTransform.hpp>
#include <Blob/Renderable.hpp>
#include <Blob/WindowCore.hpp>
#include <Blob/ImGUI.hpp>

// std
#include <chrono>
#include <ostream>

namespace Blob {

class Window : public WindowCore, ProjectionTransform {
private:
    ImGUI imgui;

    Blob::Camera &camera;

    // time counting
    std::chrono::high_resolution_clock::time_point lastFrameTime;
    std::chrono::duration<float> fpsCouner{0};
    static float timeF;

public:
    explicit Window(Blob::Camera &camera, bool fullScreen = false, unsigned int w = 640, unsigned int h = 480);

    ~Window();

    void draw(const Renderable &renderable) const;

    void setCamera(Camera &camera);

    float display();

    std::array<float, 3> getWorldPosition();

    void resize(unsigned int width, unsigned int height) final;
};
} // namespace Blob

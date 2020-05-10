#pragma once

// BlobEngine
#include <Blob/Camera.hpp>
#include <Blob/ImGUI.hpp>
#include <Blob/Mesh.hpp>
#include <Blob/ProjectionTransform.hpp>
#include <Blob/Scene.hpp>
#include <Blob/Shape.hpp>
#include <Blob/WindowCore.hpp>

// std
#include <chrono>
#include <ostream>

namespace Blob {

class Window : public WindowCore, public ProjectionTransform {
private:
    ImGUI imgui;

    Blob::Camera &camera;

    // time counting
    std::chrono::high_resolution_clock::time_point lastFrameTime;
    std::chrono::duration<float> fpsCouner{0};

public:
    static float timeFlow;

    explicit Window(Camera &camera, bool fullScreen = false, unsigned int w = 640, unsigned int h = 480);

    ~Window();

    void draw(const Mesh &mesh, glm::mat4 sceneModel = glm::mat4(1)) const;
    void draw(const Shape &shape, glm::mat4 sceneModel = glm::mat4(1))  const;
    void draw(const Scene &scene) const;

    void setCamera(Camera &camera);

    float display();

    std::array<float, 3> getWorldPosition();

    void resize(unsigned int width, unsigned int height) final;
};

} // namespace Blob

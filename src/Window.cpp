#include <Blob/Window.hpp>

// Blob
#include <Blob/Exception.hpp>
#include <Blob/Shapes.hpp>
#include <imgui.h>
#include <iostream>

namespace Blob::Core {

Window::Window(Camera &camera, bool fullScreen, Maths::Vec2<int> size)
    : GLFW::Window(fullScreen, size, GLmajor, GLminor), camera(camera), GL::Context((void *) getProcAddress, framebufferSize),
      ProjectionTransform(PI / 4, size, 1, 100), imgui(*this, windowSize.cast<float>(), framebufferSize.cast<float>()), keyboard(*keys) {
    imgui.createRender();

    ImGuiIO &io = ImGui::GetIO();
    cursorPosition = (Maths::Vec2<float> *) &io.MousePos;
    mouseButton = &io.MouseDown;
    scrollOffsetW = &io.MouseWheel;
    scrollOffsetH = &io.MouseWheelH;
    keyCtrl = &io.KeyCtrl;
    keyShift = &io.KeyShift;
    keyAlt = &io.KeyAlt;
    keySuper = &io.KeySuper;
    keys = &io.KeysDown;

    new (&keyboard) Keyboard(io.KeysDown);

    Shapes::init();
    lastFrameTime = std::chrono::high_resolution_clock::now();
}

Window::~Window() {
    imgui.draw();
    std::cout << "delete Shapes" << std::endl;
    Shapes::destroy();
}

float Window::timeFlow = 0;

float Window::display() {
    imgui.updateMouseCursor(*this);
    imgui.draw();

    swapBuffers();
    GL::Core::clear();
    updateInputs();

    ImGui::NewFrame();

    if(keyboardUpdated) {
        keyboardUpdated = false;
        for(auto &k : KeyboardEvents::keyUpdates)
            k->keyboardUpdate(keyboard);
    }

    auto now = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> diff = now - lastFrameTime;
    ImGui::GetIO().DeltaTime = diff.count();
    timeFlow = diff.count();
    fpsCouner = fpsCouner + diff;
    lastFrameTime = now;

    return timeFlow;
}

void Window::windowResized() {
    imgui.setWindowSize(windowSize.cast<float>(), framebufferSize.cast<float>());
}

void Window::framebufferResized() {
    setRatio(framebufferSize);
    imgui.setWindowSize(windowSize.cast<float>(), framebufferSize.cast<float>());

    Blob::GL::Core::setViewport(framebufferSize);
}

void Window::characterInput(unsigned int c) {
    imgui.addInputCharacter(c);
}

Maths::Vec3<float> Window::getWorldPosition() {
    Maths::Vec2<float> mousePos = *cursorPosition, size = framebufferSize.cast<float>();
    mousePos.x = mousePos.x / size.x * 2 - 1;
    mousePos.y = 1 - mousePos.y / size.y * 2;

    /*//Look at test
    glm::vec4 posCamera(50, 50, 15, 1);

    ImGui::Text("World pos : %.3f, %.3f, %.3f", posCamera.x, posCamera.y,
    posCamera.z); posCamera = (projectionMatrix * viewMatrix) * posCamera;
    ImGui::Text("camera pos : %.3f, %.3f, %.3f", posCamera.x, posCamera.y,
    posCamera.z); posCamera = posCamera / posCamera.w; ImGui::Text("camera rerange
    : %.3f, %.3f, %.3f", posCamera.x, posCamera.y, (posCamera.z + 1) / 2);
    posCamera = glm::inverse(projectionMatrix * viewMatrix) * posCamera;
    ImGui::Text("inverse : %.3f, %.3f, %.3f", posCamera.x, posCamera.y,
    posCamera.z); posCamera = posCamera / posCamera.w; ImGui::Text("inverse
    rerange : %.3f, %.3f, %.3f", posCamera.x, posCamera.y, posCamera.z);
    //
    */

    float z = GL::Core::readPixel((Maths::Vec2<float>(0, -size.y) + mousePos).cast<int>());

    z = (z * 2) - 1;

    Maths::Vec4<float> pos(mousePos.x, mousePos.y, z);

    pos = (*this * camera).inverse() * pos;
    pos = pos / pos.w;

    return (Maths::Vec3<float>) pos;
}

void Window::setCamera(Camera &camera_) {
    camera = camera_;
}

void Window::draw(const Mesh &mesh, const Maths::Mat4 &sceneModel) const {
    Blob::GL::Core::setShader(mesh.material->shaderProgramPrivate);
    Blob::GL::Core::setVAO(mesh.vertexArrayObject);

    mesh.material->applyMaterial(*this, camera, sceneModel);

    Blob::GL::Core::drawIndex(mesh.renderOptions.indices, mesh.renderOptions.numOfIndices, mesh.renderOptions.indicesType);
}

void Window::draw(const Shape &shape, const Maths::Mat4 &sceneModel) const {
    Maths::Mat4 modelMatrix = sceneModel * shape;

    /*std::cout << "mat :" << std::endl << modelMatrix;

    std::cout << "r :" << std::endl;
    for(Renderable *r : shape.renderables)
            std::cout << std::hex << r << " ";
    std::cout << std::endl;*/
    if (shape.mesh != nullptr)
        draw(*shape.mesh, modelMatrix);

    for (auto r : shape.shapes)
        draw(*r, modelMatrix);
}

void Window::draw(const Scene &scene) const {
    /*std::cout << "mat :" << std::endl << modelMatrix;

    std::cout << "r :" << std::endl;
    for(Shape *r : scene.shapes)
            std::cout << std::hex << r << " ";
    std::cout << std::endl;*/

    for (auto r : scene.shapes)
        draw(*r);
}

void Window::keyboardUpdate(int key, bool pressed) {
    keyboardUpdated = true;
}

} // namespace Blob::Core

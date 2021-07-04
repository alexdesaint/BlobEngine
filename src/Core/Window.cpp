#include "Blob/GLFW.hpp"
#include <Blob/Core/Window.hpp>

#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

// Blob
#include <imgui.h>
#include <iostream>

namespace Blob {

Window::Window(const Vec2<unsigned int> &size) :
    GL::Window(size, GLmajor, GLminor),
    keyboard(*keys),
    mouse(*cursorPosition, *scrollOffsetH, *scrollOffsetW, *mouseButton),
    projectionTransform(PI / 4, framebufferSize, 0.1, 1000),
    projectionTransform2D(framebufferSize.cast<float>()) {

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    io.BackendRendererName = "BlobEngine";
    io.IniFilename = nullptr;
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL((GLFWwindow *) GLFW::Window::window, true);
    ImGui_ImplOpenGL3_Init("#version 450");

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    cursorPosition = (Vec2<float> *) &io.MousePos;
    mouseButton = &io.MouseDown;
    scrollOffsetW = &io.MouseWheel;
    scrollOffsetH = &io.MouseWheelH;
    keyCtrl = &io.KeyCtrl;
    keyShift = &io.KeyShift;
    keyAlt = &io.KeyAlt;
    keySuper = &io.KeySuper;
    keys = &io.KeysDown;

    new (&keyboard) Keyboard(*keys);
    new (&mouse)
        Mouse(*cursorPosition, *scrollOffsetH, *scrollOffsetW, *mouseButton);

    // Deferred Shading
    // gPosition.setRGBA16data(nullptr, framebufferSize);
    // gPosition.applySampler({GL::Sampler::FILTER::NEAREST,
    // GL::Sampler::FILTER::NEAREST}); gFrameBuffer.attachTexture(gPosition,
    // GL::FrameBuffer::COLOR_ATTACHMENT0); gNormal.setRGBA16data(nullptr,
    // framebufferSize); gNormal.applySampler({GL::Sampler::FILTER::NEAREST,
    // GL::Sampler::FILTER::NEAREST}); gFrameBuffer.attachTexture(gPosition,
    // GL::FrameBuffer::COLOR_ATTACHMENT1); gAlbedo.setRGBA16data(nullptr,
    // framebufferSize); gAlbedo.applySampler({GL::Sampler::FILTER::NEAREST,
    // GL::Sampler::FILTER::NEAREST}); gFrameBuffer.attachTexture(gPosition,
    // GL::FrameBuffer::COLOR_ATTACHMENT2);
    // gFrameBuffer.drawBuffer({GL::FrameBuffer::COLOR_ATTACHMENT0,
    // GL::FrameBuffer::COLOR_ATTACHMENT1, GL::FrameBuffer::COLOR_ATTACHMENT2});

    lastFrameTime = std::chrono::high_resolution_clock::now();
}

Window::~Window() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

float Window::timeFlow = 0;

float Window::display() {
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    swapBuffers();
    clear();

    updateInputs();
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    auto now = std::chrono::high_resolution_clock::now();
    Time::Duration diff = now - lastFrameTime;
    ImGui::GetIO().DeltaTime = diff.count();
    timeFlow = diff.count();
    fpsCouner = fpsCouner + diff;
    lastFrameTime = now;

    return timeFlow;
}

void Window::windowResized() {
    // imgui.setWindowSize(windowSize.cast<float>(),
    // framebufferSize.cast<float>());
}

void Window::framebufferResized() {
    projectionTransform.setRatio(framebufferSize);
    projectionTransform2D.setRatio(framebufferSize.cast<float>());
    // imgui.setWindowSize(windowSize.cast<float>(),
    // framebufferSize.cast<float>());

    setViewport(framebufferSize);
}

void Window::characterInput(unsigned int c) {
    // imgui.addInputCharacter(c);
}

Vec3<float> Window::getWorldPosition(const Camera &camera) {

    //
    /*        ImGui::Begin("getWorldPosition");
            Vec4<float> testPos(1, 1, 0, 1);
            ImGui::Text("world :  %f %f %f %f", testPos.x, testPos.y, testPos.z,
       testPos.w); testPos = camera->operator*(testPos); ImGui::Text("Camera :
       %f %f %f %f", testPos.x, testPos.y, testPos.z, testPos.w); testPos =
       operator*(testPos); testPos = testPos / testPos.w; ImGui::Text("window :
       %f %f %f %f", testPos.x, testPos.y, testPos.z, testPos.w); testPos =
       (*camera * *this).inverse() * testPos; ImGui::Text("testPos4 :  %f %f %f
       %f", testPos.x, testPos.y, testPos.z, testPos.w); testPos = testPos /
       testPos.w; ImGui::Text("testPos5 :  %f %f %f %f", testPos.x, testPos.y,
       testPos.z, testPos.w); ImGui::End();*/
    //

    Vec2<float> mousePos = *cursorPosition,
                size = framebufferSize.cast<float>();
    mousePos.y = size.y - mousePos.y;

    Vec4<float> pos(mousePos / size * 2 - 1,
                    readPixel(mousePos.cast<int>()) * 2 - 1);

    //
    /*        ImGui::Begin("getWorldPosition");
            ImGui::Text("Window :  %f %f %f %f", pos.x, pos.y, pos.z, pos.w);*/
    //

    pos = (camera * projectionTransform).inverse() * pos;

    //
    /*        ImGui::Text("World :  %f %f %f %f", pos.x / pos.w, pos.y / pos.w,
       pos.z / pos.w, pos.w); ImGui::End();*/
    //

    return pos / pos.w;
}

void Window::draw(const Primitive2D &primitive,
                  const ViewTransform2D &camera,
                  const Mat3 &model) const {
    setVAO(primitive.vertexArrayObject);

    primitive.material->applyMaterial(projectionTransform2D, camera, model);

    if (primitive.renderOptions->indices != nullptr) {
        if (primitive.renderOptions->instancedCount)
            drawIndexInstanced(primitive.renderOptions->indices,
                               primitive.renderOptions->numOfIndices,
                               primitive.renderOptions->indicesType,
                               primitive.renderOptions->instancedCount);
        else
            drawIndex(primitive.renderOptions->indices,
                      primitive.renderOptions->numOfIndices,
                      primitive.renderOptions->indicesType);
    } else {
        if (primitive.renderOptions->instancedCount)
            drawArraysInstanced(primitive.renderOptions->numOfElements,
                                primitive.renderOptions->elementOffset,
                                primitive.renderOptions->instancedCount);
        else
            drawArrays(primitive.renderOptions->numOfElements,
                       primitive.renderOptions->elementOffset);
    }
}

void Window::draw(const Mesh2D &mesh,
                  const ViewTransform2D &camera,
                  const Mat3 &sceneModel) const {
    for (auto r : mesh.primitives)
        draw(*r, camera, sceneModel);
}

void Window::draw(const Shape2D &shape,
                  const ViewTransform2D &camera,
                  const Mat3 &sceneModel) const {
    Mat3 modelMatrix = shape * sceneModel;

    if (shape.mesh != nullptr)
        draw(*shape.mesh, camera, modelMatrix);

    for (auto r : shape.shapes)
        draw(*r, camera, modelMatrix);
}

void Window::draw(const Scene2D &scene) const {
    for (auto r : scene.shapes)
        draw(*r, scene.camera);
    // for (auto r : scene.shapes)
    //    drawTransparent(*r, scene.camera);
}

void Window::draw(const Primitive &primitive,
                  const ViewTransform &camera,
                  const Mat4 &sceneModel) const {
    setVAO(primitive.vertexArrayObject);

    primitive.material->applyMaterial(projectionTransform, camera, sceneModel);

    if (primitive.renderOptions->indices != nullptr) {
        if (primitive.renderOptions->instancedCount)
            drawIndexInstanced(primitive.renderOptions->indices,
                               primitive.renderOptions->numOfIndices,
                               primitive.renderOptions->indicesType,
                               primitive.renderOptions->instancedCount);
        else
            drawIndex(primitive.renderOptions->indices,
                      primitive.renderOptions->numOfIndices,
                      primitive.renderOptions->indicesType);
    } else {
        if (primitive.renderOptions->instancedCount)
            drawArraysInstanced(primitive.renderOptions->numOfElements,
                                primitive.renderOptions->elementOffset,
                                primitive.renderOptions->instancedCount);
        else
            drawArrays(primitive.renderOptions->numOfElements,
                       primitive.renderOptions->elementOffset);
    }
}

void Window::draw(const Mesh &mesh,
                  const ViewTransform &camera,
                  const Mat4 &sceneModel) const {
    for (auto r : mesh.primitives)
        draw(*r, camera, sceneModel);
}

void Window::draw(const Shape &shape,
                  const ViewTransform &camera,
                  const Mat4 &sceneModel) const {
    Mat4 modelMatrix = shape * sceneModel;

    if (shape.mesh != nullptr)
        draw(*shape.mesh, camera, modelMatrix);

    for (auto r : shape.shapes)
        draw(*r, camera, modelMatrix);
}

void Window::draw(const Scene &scene, const Mat4 &sceneModel) const {
    for (auto r : scene.shapes)
        draw(*r, scene.camera, sceneModel);
    for (auto r : scene.shapes)
        drawTransparent(*r, scene.camera, sceneModel);
}

void Window::draw(const Scene &scene, const ViewTransform &camera) const {
    for (auto r : scene.shapes)
        draw(*r, camera);
    for (auto r : scene.shapes)
        drawTransparent(*r, camera);
}

void Window::draw(const Scene &scene) const {
    for (auto r : scene.shapes)
        draw(*r, scene.camera);
    for (auto r : scene.shapes)
        drawTransparent(*r, scene.camera);
}

void Window::drawTransparent(const Mesh &mesh,
                             const ViewTransform &camera,
                             const Mat4 &sceneModel) const {
    for (auto r : mesh.transparentPrimitives)
        draw(*r, camera, sceneModel);
}

void Window::drawTransparent(const Shape &shape,
                             const ViewTransform &camera,
                             const Mat4 &sceneModel) const {
    Mat4 modelMatrix = shape * sceneModel;

    if (shape.mesh != nullptr)
        drawTransparent(*shape.mesh, camera, modelMatrix);

    for (auto r : shape.shapes)
        drawTransparent(*r, camera, modelMatrix);
}

void Window::keyboardUpdate(int key, bool pressed) {
    for (auto &k : KeyboardEvents::subscribers)
        k->keyboardUpdate(keyboard[key]);
    for (auto &k : KeyboardEvents2::subscribers) {
        auto it = k->callbacks.find(key);
        if (it != k->callbacks.end() && it->second)
            it->second(pressed);
    }
}

void Window::mouseButtonUpdate(int button, bool pressed) {
    for (auto &k : MouseEvents::subscribers)
        k->mouseButtonUpdate(button, pressed);
}

void Window::cursorPositionUpdate(double xpos, double ypos) {
    for (auto &k : MouseEvents::subscribers)
        k->cursorPosUpdate(xpos, ypos);
}

void Window::scrollUpdate(double xoffset, double yoffset) {
    for (auto &k : MouseEvents::subscribers)
        k->scrollUpdate(xoffset, yoffset);
}

void Window::disableMouseCursor() {
    ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_NoMouse;
    setCursorState(CURSOR_DISABLED);
}

void Window::enableMouseCursor() {
    ImGui::GetIO().ConfigFlags &= ~ImGuiConfigFlags_NoMouse;
    setCursorState(CURSOR_NORMAL);
}

} // namespace Blob

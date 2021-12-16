#include "Blob/GLFW.hpp"
#include "Blob/Maths.inl"
#include <Blob/Core/Window.hpp>

#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

// Blob
#include <chrono>
#include <cstddef>
#include <imgui.h>
#include <iostream>

namespace Blob {

Window::Window(const Vec2<unsigned int> &size) :
    GL::Window(size, GLmajor, GLminor),
    keyboard(keys),
    mouse(cursorPosition, scrollOffsetH, scrollOffsetW, mouseButton),
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

    lastFrameTime = std::chrono::high_resolution_clock::now();
}

Window::~Window() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

double Window::display() {
    enableSRGB(false);
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    enableSRGB(true);

    swapBuffers();
    clear();

    updateInputs();
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    std::chrono::time_point<std::chrono::system_clock> now =
        std::chrono::system_clock::now();

    auto diff = std::chrono::duration_cast<std::chrono::duration<double>>(
        now - lastFrameTime);
    timeFlow = diff.count();
    lastFrameTime = now;

    return timeFlow;
}

void Window::windowResized() {}

void Window::framebufferResized() {
    projectionTransform.setRatio(framebufferSize);
    projectionTransform2D.setRatio(framebufferSize.cast<float>());

    setViewport(framebufferSize);
}

void Window::characterInput(unsigned int c) {
    // imgui.addInputCharacter(c);
}

Vec3<float> Window::getMousePositionInWorld(const Camera &camera) {
    /*
        ImGui::Begin("TestWorldPosition");
        Vec4<float> testPos(1, 1, 0, 1);
        ImGui::Text("world :  %f %f %f %f",
                    testPos.x,
                    testPos.y,
                    testPos.z,
                    testPos.w);
        testPos = camera * testPos;
        ImGui::Text("Camera : %f %f %f %f",
                    testPos.x,
                    testPos.y,
                    testPos.z,
                    testPos.w);
        testPos = projectionTransform * testPos;
        testPos = testPos / testPos.w;
        ImGui::Text("window : %f %f %f %f",
                    testPos.x,
                    testPos.y,
                    testPos.z,
                    testPos.w);
        testPos = (camera * projectionTransform).inverse() * testPos;
        ImGui::Text("testPos4 : %f %f %f %f",
                    testPos.x,
                    testPos.y,
                    testPos.z,
                    testPos.w);
        testPos = testPos / testPos.w;
        ImGui::Text("testPos5 : %f %f %f %f",
                    testPos.x,
                    testPos.y,
                    testPos.z,
                    testPos.w);
        ImGui::End();
    */

    auto mousePos = cursorPosition, size = framebufferSize.cast<float>();
    mousePos.y = size.y - mousePos.y;

    Vec4<float> pos(mousePos / size * 2 - 1,
                    readPixel(mousePos.cast<int>()) * 2 - 1);

    //
    // ImGui::Begin("getWorldPosition");
    // ImGui::Text("Window : %f %f %f %f", pos.x, pos.y, pos.z, pos.w);
    //

    pos = (projectionTransform * camera).inverse() * pos;

    //
    // ImGui::Text("World non div : %f %f %f %f", pos.x, pos.y, pos.z, pos.w);
    // ImGui::Text("World : %f %f %f %f",
    //             pos.x / pos.w,
    //             pos.y / pos.w,
    //             pos.z / pos.w,
    //             pos.w / pos.w);
    // ImGui::End();
    //

    return pos / pos.w;
}

Vec3<float> Window::getMousePositionInWorld(const Camera &camera,
                                            float zWorld) {
    auto mousePos = cursorPosition, size = framebufferSize.cast<float>();
    mousePos.y = size.y - mousePos.y;

    Vec4<> screenPos{mousePos / size * 2 - 1, 0, 1};

    const auto MVP = projectionTransform * camera;
    const auto MVPinv = MVP.inverse();

    screenPos.z =
        (MVPinv.a34 - screenPos.x * (MVPinv.a41 * zWorld - MVPinv.a31) -
         screenPos.y * (MVPinv.a42 * zWorld - MVPinv.a32) -
         MVPinv.a44 * zWorld) /
        (MVPinv.a43 * zWorld - MVPinv.a33);

    auto const worldPos = MVPinv * screenPos;

    /*
    ImGui::Begin("getWorldPosition");
    ImGui::Text("MVP :\n%f %f %f %f\n%f %f %f %f\n%f %f %f %f\n%f %f %f %f",
                MVP.a11,
                MVP.a12,
                MVP.a13,
                MVP.a14,
                MVP.a21,
                MVP.a22,
                MVP.a23,
                MVP.a24,
                MVP.a31,
                MVP.a32,
                MVP.a33,
                MVP.a34,
                MVP.a41,
                MVP.a42,
                MVP.a43,
                MVP.a44);
    ImGui::Text("MVPinv :\n%f %f %f %f\n%f %f %f %f\n%f %f %f %f\n%f %f %f %f",
                MVPinv.a11,
                MVPinv.a12,
                MVPinv.a13,
                MVPinv.a14,
                MVPinv.a21,
                MVPinv.a22,
                MVPinv.a23,
                MVPinv.a24,
                MVPinv.a31,
                MVPinv.a32,
                MVPinv.a33,
                MVPinv.a34,
                MVPinv.a41,
                MVPinv.a42,
                MVPinv.a43,
                MVPinv.a44);
    ImGui::Text("screenPos : %f %f %f %f",
                screenPos.x,
                screenPos.y,
                screenPos.z,
                screenPos.w);
    ImGui::Text("worldPos non div : %f %f %f %f",
                worldPos.x,
                worldPos.y,
                worldPos.z,
                worldPos.w);
    ImGui::Text("World : %f %f %f %f",
                worldPos.x / worldPos.w,
                worldPos.y / worldPos.w,
                worldPos.z / worldPos.w,
                worldPos.w / worldPos.w);
    ImGui::End();
    */

    return worldPos / worldPos.w;
}

std::array<Vec3<>, 4> Window::getCameraCornersInWorld(const Camera &camera,
                                                      float zWorld) {
    Vec4<> screenPos[4]{{1, 1, 0, 1},
                        {-1, 1, 0, 1},
                        {-1, -1, 1},
                        {1, -1, 0, 1}};

    const auto MVP = projectionTransform * camera;
    const auto MVPinv = MVP.inverse();

    std::array<Vec3<float>, 4> ret;
    for (size_t i = 0; i < 4; i++) {
        screenPos[i].z =
            (MVPinv.a34 - screenPos[i].x * (MVPinv.a41 * zWorld - MVPinv.a31) -
             screenPos[i].y * (MVPinv.a42 * zWorld - MVPinv.a32) -
             MVPinv.a44 * zWorld) /
            (MVPinv.a43 * zWorld - MVPinv.a33);

        auto worldPos = MVPinv * screenPos[i];
        ret[i] = worldPos / worldPos.w;
    }

    return ret;
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
    // Mat3 modelMatrix = shape * sceneModel;
    Mat3 modelMatrix = sceneModel * shape;

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
    // Mat4 modelMatrix = shape * sceneModel;
    Mat4 modelMatrix = sceneModel * shape;

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
    // Mat4 modelMatrix = shape * sceneModel;
    Mat4 modelMatrix = sceneModel * shape;

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

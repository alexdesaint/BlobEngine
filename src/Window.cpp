#include <Blob/Color.hpp>
#include <Blob/Exception.hpp>
#include <Blob/Maths.hpp>
#include <Blob/Window.hpp>

#include <bgfx/platform.h>

#include <chrono>
#include <cstddef>
#include <imgui.h>
#include <iostream>

namespace Blob {

Window::Window(std::string windowName, float closeRange, float longRange) :
    context(getNativeDisplayType(),
            getNativeWindowHandle(),
            {std::numbers::pi / 4, windowSize, closeRange, longRange, false},
            ProjectionTransform2D{windowSize.cast<float>()}),
    GLFW::Window({}, windowName) {
    // Clear the view rect
    bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, Dracula::Background.code, 1.0f, 0);

    windowResized();

    bgfx::touch(0);

    ImGuiIO &io = ImGui::GetIO();
    io.BackendRendererName = "BlobEngine";
    io.IniFilename = nullptr;
    io.UserData = this;
    io.SetClipboardTextFn = [](void *userData, const char *text) {
        ((Blob::Window *) userData)->setClipboardText(text);
    };
    io.GetClipboardTextFn = [](void *userData) { return ((Blob::Window *) userData)->getClipboardText(); };
    io.ClipboardUserData = nullptr;
    io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
    io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

    ImGui::NewFrame();

    lastFrameTime = std::chrono::system_clock::now();

    Material::initMaterial(context);
    Material::applyMaterialStatic();
}

double Window::display(const ViewTransform &camera) {
    ImGuiIO &io = ImGui::GetIO();
    // if (io.WantSetMousePos)
    //     SDL_WarpMouseInWindow(bd->Window,
    //                           (int) io.MousePos.x,
    //                           (int) io.MousePos.y);
    ImGuiMouseCursor imgui_cursor = ImGui::GetMouseCursor();
    if (io.MouseDrawCursor || imgui_cursor == ImGuiMouseCursor_None) {
        setCursorState(CURSOR_HIDDEN);
    } else {
        setCursorState(CURSOR_NORMAL);

        setMouseCursor((GLFW::MouseCursor) imgui_cursor);
    }

    bgfx::setViewTransform(0, &camera.a11, &context.projectionTransform.a11);

    // render
    ImGui::Render();
    imGuiContext.RenderDrawData(ImGui::GetDrawData());
    m_currFrame = bgfx::frame();

    // new frame
    bgfx::touch(0);
    ImGui::NewFrame();

    // time mesuring
    std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();

    auto diff = std::chrono::duration_cast<std::chrono::duration<double>>(now - lastFrameTime);
    timeFlow = diff.count();
    lastFrameTime = now;
    io.DeltaTime = timeFlow;
    // events

    Material::applyMaterialStatic();
    updateInputs();

    return timeFlow;
}

void Window::windowResized() {
    bgfx::setViewRect(0, 0, 0, windowSize.x, windowSize.y);
    bgfx::reset(windowSize.x, windowSize.y, resetFlags);

    context.projectionTransform.setRatio(windowSize);
    context.projectionTransform2D.setRatio(windowSize.cast<float>());

    ImGui::GetIO().DisplaySize = ImVec2(windowSize.x, windowSize.y);
}

void Window::draw(const Mesh::Primitive &primitive, const Mat4 &model) const {
    bgfx::setIndexBuffer(primitive.renderOptions->indexBufferHandle);
    bgfx::setTransform(&model.a11);
    bgfx::setVertexBuffer(0, primitive.vertexBuffer->vertexBufferHandle);

    primitive.material.applyMaterial();

    if (primitive.renderOptions->instancedCount)
        throw Exception("instancedCount not supported");
    else
        bgfx::setIndexBuffer(primitive.renderOptions->indexBufferHandle);
}

void Window::draw(const Mesh &mesh, const Mat4 &sceneModel) const {
    for (const auto &r : mesh.primitives)
        draw(r, sceneModel);
}

void Window::draw(const Shape &shape, const Mat4 &sceneModel) const {
    Mat4 modelMatrix = sceneModel * shape;

    if (shape.mesh.has_value())
        draw(*shape.mesh, modelMatrix);

    for (const auto &r : shape.shapes)
        draw(r, modelMatrix);
}

void Window::drawTransparent(const Mesh &mesh, const Mat4 &sceneModel) const {
    for (const auto &r : mesh.transparentPrimitives)
        draw(r, sceneModel);
}

void Window::drawTransparent(const Shape &shape, const Mat4 &sceneModel) const {
    // Mat4 modelMatrix = shape * sceneModel;
    Mat4 modelMatrix = sceneModel * shape;

    if (shape.mesh.has_value())
        drawTransparent(*shape.mesh, modelMatrix);

    for (const auto &r : shape.shapes)
        drawTransparent(r, modelMatrix);
}

void Window::keyboardUpdate(Key key, bool pressed) {
    ImGuiKey imGuiKey = imGuiContext.KeycodeToImGuiKey(key);
    ImGui::GetIO().AddKeyEvent(imGuiKey, pressed);
    for (auto &k : context.keyboardEventsSubscribers)
        k->keyUpdate(key, pressed);
}

void Window::mouseButtonUpdate(MouseKey button, bool pressed) {
    int mouse_button = -1;
    if (button == MouseKeys::LEFT)
        mouse_button = 0;
    if (button == MouseKeys::RIGHT)
        mouse_button = 1;
    if (button == MouseKeys::MIDDLE)
        mouse_button = 2;
    if (mouse_button != -1)
        ImGui::GetIO().AddMouseButtonEvent(mouse_button, pressed);

    for (auto &k : context.mouseEventsSubscribers)
        k->mouseButtonUpdate(button, pressed);
}

void Window::cursorPositionUpdate(double xpos, double ypos) {
    ImGui::GetIO().AddMousePosEvent(xpos, ypos);
    Vec2<> screenPos =
        Mat3{
            {1.f / windowSize.x * 2.f, 0.f, -1.f},
            {0.f, -1.f / windowSize.y * 2.f, 1.f},
            {0.f, 0.f, 1.f},
        } *
        Vec2<>(xpos, ypos);

    for (auto &k : context.mouseEventsSubscribers)
        k->cursorPosUpdate(Vec2<>(xpos, ypos), screenPos);
}

void Window::scrollUpdate(double xoffset, double yoffset) {
    ImGui::GetIO().AddMouseWheelEvent(xoffset, yoffset);
    for (auto &k : context.mouseEventsSubscribers)
        k->scrollUpdate(xoffset, yoffset);
}

void Window::disableMouseCursor() { ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_NoMouse; }

void Window::enableMouseCursor() { ImGui::GetIO().ConfigFlags &= ~ImGuiConfigFlags_NoMouse; }

} // namespace Blob

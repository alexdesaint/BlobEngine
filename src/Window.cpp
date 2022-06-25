#include <Blob/Exception.hpp>
#include <Blob/Maths.hpp>
#include <Blob/Window.hpp>

#include <bgfx/platform.h>

// Blob
#include <chrono>
#include <cstddef>
#include <imgui.h>
#include <iostream>

namespace Blob {

Window::Window(const Vec2<unsigned int> &size, std::string windowName) :
    context(getNativeDisplayType(), getNativeWindowHandle()),
    GLFW::Window(size),
    projectionTransform(PI / 4, windowSize, 0.1, 1000, false),
    projectionTransform2D(windowSize.cast<float>()) {
    // Clear the view rect
    bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x443355FF, 1.0f, 0);

    windowResized();

    bgfx::touch(0);

    ImGuiIO &io = ImGui::GetIO();
    io.BackendRendererName = "BlobEngine";
    io.IniFilename = nullptr;
    io.UserData = this;
    io.SetClipboardTextFn = [](void *userData, const char *text) {
        ((Blob::Window *) userData)->setClipboardText(text);
    };
    io.GetClipboardTextFn = [](void *userData) {
        return ((Blob::Window *) userData)->getClipboardText();
    };
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

    bgfx::setViewTransform(0, &camera.a11, &projectionTransform.a11);

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
    // events
    updateInputs();

    Material::applyMaterialStatic();

    return timeFlow;
}

void Window::windowResized() {
    bgfx::setViewRect(0, 0, 0, windowSize.x, windowSize.y);
    bgfx::reset(windowSize.x, windowSize.y, resetFlags);

    projectionTransform.setRatio(windowSize);
    projectionTransform2D.setRatio(windowSize.cast<float>());

    ImGui::GetIO().DisplaySize = ImVec2(windowSize.x, windowSize.y);
}

// void Window::textInput(std::string c) {
//     ImGui::GetIO().AddInputCharactersUTF8(c.c_str());
// }

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

    auto readPixel = [](Vec2<int> pos) { return 0; };

    Vec2<> mousePos, size = windowSize.cast<float>();
    mousePos.y = size.y - mousePos.y;

    Vec4<> pos(mousePos / size * 2 - 1, readPixel(mousePos.cast<int>()) * 2 - 1);

    // ImGui::Begin("getWorldPosition");
    // ImGui::Text("Window : %f %f %f %f", pos.x, pos.y, pos.z, pos.w);

    pos = (projectionTransform * camera).inverse() * pos;

    // ImGui::Text("World non div : %f %f %f %f", pos.x, pos.y, pos.z, pos.w);
    // ImGui::Text("World : %f %f %f %f",
    //             pos.x / pos.w,
    //             pos.y / pos.w,
    //             pos.z / pos.w,
    //             pos.w / pos.w);
    // ImGui::End();

    return pos / pos.w;
}

Vec3<float> Window::getMousePositionInWorld(const Camera &camera, float zWorld) {
    Vec2<> mousePos = cursorPosition, size = windowSize.cast<float>();
    mousePos.y = size.y - mousePos.y;

    Vec4<> screenPos{mousePos / size * 2 - 1, 0, 1};

    const auto MVP = projectionTransform * camera;
    const auto MVPinv = MVP.inverse();

    screenPos.z = (MVPinv.a34 - screenPos.x * (MVPinv.a41 * zWorld - MVPinv.a31)
                   - screenPos.y * (MVPinv.a42 * zWorld - MVPinv.a32) - MVPinv.a44 * zWorld)
                  / (MVPinv.a43 * zWorld - MVPinv.a33);

    auto const worldPos = MVPinv * screenPos;

    /*
    ImGui::Begin("getWorldPosition");
    ImGui::Text("MVP :\n%f %f %f %f\n%f %f %f %f\n%f %f %f %f\n%f %f %f %f",
                MVP.a11, MVP.a12, MVP.a13, MVP.a14,
                MVP.a21, MVP.a22, MVP.a23, MVP.a24,
                MVP.a31, MVP.a32, MVP.a33, MVP.a34,
                MVP.a41, MVP.a42, MVP.a43, MVP.a44);
    ImGui::Text("MVPinv :\n%f %f %f %f\n%f %f %f %f\n%f %f %f %f\n%f %f %f %f",
                MVPinv.a11, MVPinv.a12, MVPinv.a13, MVPinv.a14,
                MVPinv.a21, MVPinv.a22, MVPinv.a23, MVPinv.a24,
                MVPinv.a31, MVPinv.a32, MVPinv.a33, MVPinv.a34,
                MVPinv.a41, MVPinv.a42, MVPinv.a43, MVPinv.a44);
    ImGui::Text("screenPos : %f %f %f %f",
                screenPos.x, screenPos.y, screenPos.z, screenPos.w);
    ImGui::Text("worldPos non div : %f %f %f %f",
                worldPos.x, worldPos.y, worldPos.z, worldPos.w);
    ImGui::Text("World : %f %f %f %f",
                worldPos.x / worldPos.w, worldPos.y / worldPos.w,
                worldPos.z / worldPos.w, worldPos.w / worldPos.w);
    ImGui::End();
    */

    return worldPos / worldPos.w;
}

std::array<Vec3<>, 4> Window::getCameraCornersInWorld(const Camera &camera, float zWorld) {
    Vec4<> screenPos[4]{{1, 1, 0, 1}, {-1, 1, 0, 1}, {-1, -1, 0, 1}, {1, -1, 0, 1}};

    const auto MVP = projectionTransform * camera;
    const auto MVPinv = MVP.inverse();

    std::array<Vec3<float>, 4> ret;
    for (size_t i = 0; i < 4; i++) {
        screenPos[i].z =
            (MVPinv.a34 - screenPos[i].x * (MVPinv.a41 * zWorld - MVPinv.a31)
             - screenPos[i].y * (MVPinv.a42 * zWorld - MVPinv.a32) - MVPinv.a44 * zWorld)
            / (MVPinv.a43 * zWorld - MVPinv.a33);

        auto worldPos = MVPinv * screenPos[i];
        ret[i] = worldPos / worldPos.w;
    }

    return ret;
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
    // Mat4 modelMatrix = shape * sceneModel;
    Mat4 modelMatrix = sceneModel * shape;

    if (shape.mesh.has_value())
        draw(*shape.mesh, modelMatrix);

    for (const auto &r : shape.shapes)
        draw(r, modelMatrix);
}

void Window::draw(const Scene &scene, const Mat4 &sceneModel) const {
    for (const auto &r : scene.shapes)
        draw(*r, sceneModel);
    for (const auto &r : scene.shapes)
        drawTransparent(*r, sceneModel);
}

void Window::draw(const Scene &scene) const {
    for (const auto &r : scene.shapes)
        draw(*r);
    for (const auto &r : scene.shapes)
        drawTransparent(*r);
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
    for (auto &k : KeyboardEvents::subscribers)
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

    for (auto &k : MouseEvents::subscribers)
        k->mouseButtonUpdate(button, pressed);
}

void Window::cursorPositionUpdate(double xpos, double ypos) {
    ImGui::GetIO().AddMousePosEvent(xpos, ypos);
    for (auto &k : MouseEvents::subscribers)
        k->cursorPosUpdate(xpos, ypos);
}

void Window::scrollUpdate(double xoffset, double yoffset) {
    ImGui::GetIO().AddMouseWheelEvent(xoffset, yoffset);
    for (auto &k : MouseEvents::subscribers)
        k->scrollUpdate(xoffset, yoffset);
}

void Window::disableMouseCursor() {
    ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_NoMouse;
}

void Window::enableMouseCursor() {
    ImGui::GetIO().ConfigFlags &= ~ImGuiConfigFlags_NoMouse;
}

} // namespace Blob

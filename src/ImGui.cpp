#include <Blob/Core/Exception.hpp>
#include <Blob/GL/Window.hpp>
#include <Blob/GLFW.hpp>
#include <Blob/ImGui.hpp>
#include <imgui.h>
#include <iostream>

namespace ImGui {

using namespace Blob;

Context::Context(const GLFW::Window &window, const Maths::Vec2<float> &windowSize, const Maths::Vec2<float> &framebufferSize) {
    std::cout << "init ImGui" << std::endl;
    ImGui::CreateContext();

    ImGui::StyleColorsDark();

    ImGuiIO &io = ImGui::GetIO();
    io.BackendRendererName = "BlobEngine"; // We are not upscaling the FrameBuffer
    io.DisplayFramebufferScale = {1, 1};   // getFrameBufferSize() / getSize();

    // Controlls
    // Setup back-end capabilities flags
    io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
    io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

    // Keyboard mapping. ImGui will use those indices to peek into the io->KeysDown[] array.
    io.KeyMap[ImGuiKey_Tab] = GLFW::Keys::TAB;             //
    io.KeyMap[ImGuiKey_LeftArrow] = GLFW::Keys::LEFT;      // GLFW_KEY_LEFT + 1;
    io.KeyMap[ImGuiKey_RightArrow] = GLFW::Keys::RIGHT;    // GLFW_KEY_RIGHT + 1;
    io.KeyMap[ImGuiKey_UpArrow] = GLFW::Keys::UP;          // GLFW_KEY_UP + 1;
    io.KeyMap[ImGuiKey_DownArrow] = GLFW::Keys::DOWN;      // GLFW_KEY_DOWN + 1;
    io.KeyMap[ImGuiKey_PageUp] = GLFW::Keys::PAGE_UP;      // GLFW_KEY_PAGE_UP + 1;
    io.KeyMap[ImGuiKey_PageDown] = GLFW::Keys::PAGE_DOWN;  // GLFW_KEY_PAGE_DOWN + 1;
    io.KeyMap[ImGuiKey_Home] = GLFW::Keys::HOME;           // GLFW_KEY_HOME + 1;
    io.KeyMap[ImGuiKey_End] = GLFW::Keys::END;             // GLFW_KEY_END + 1;
    io.KeyMap[ImGuiKey_Insert] = GLFW::Keys::INSERT;       // GLFW_KEY_INSERT + 1;
    io.KeyMap[ImGuiKey_Delete] = GLFW::Keys::DEL;       // GLFW_KEY_DELETE + 1;
    io.KeyMap[ImGuiKey_Backspace] = GLFW::Keys::BACKSPACE; // GLFW_KEY_BACKSPACE + 1;
    io.KeyMap[ImGuiKey_Space] = GLFW::Keys::SPACE;         // GLFW_KEY_SPACE + 1;
    io.KeyMap[ImGuiKey_Enter] = GLFW::Keys::ENTER;         // GLFW_KEY_ENTER + 1;
    io.KeyMap[ImGuiKey_Escape] = GLFW::Keys::ESCAPE;       // GLFW_KEY_ESCAPE + 1;
    io.KeyMap[ImGuiKey_KeyPadEnter] = GLFW::Keys::NumericKeypadENTER;
    io.KeyMap[ImGuiKey_A] = GLFW::Keys::A; // GLFW_KEY_A + 1;
    io.KeyMap[ImGuiKey_C] = GLFW::Keys::C; // GLFW_KEY_C + 1;
    io.KeyMap[ImGuiKey_V] = GLFW::Keys::V; // GLFW_KEY_V + 1;
    io.KeyMap[ImGuiKey_X] = GLFW::Keys::X; // GLFW_KEY_X + 1;
    io.KeyMap[ImGuiKey_Y] = GLFW::Keys::Y; // GLFW_KEY_Y + 1;
    io.KeyMap[ImGuiKey_Z] = GLFW::Keys::Z; // GLFW_KEY_Z + 1;

    io.SetClipboardTextFn = setClipboardText;
    io.GetClipboardTextFn = getClipboardText;
    io.ClipboardUserData = nullptr; // TODO: set the pointer to GLFW window

    // Utils
    io.IniFilename = nullptr;
    buildFont();

    setWindowSize(windowSize, framebufferSize);
    ImGui::NewFrame();
}

void Context::createRender() {

    shader.addVertexShader(R"=====(
#version 450

layout (location = 0) in vec2 Position;
layout (location = 1) in vec2 TexturePosition;
layout (location = 2) in vec4 Color;

uniform mat4 projection;
out vec2 Frag_UV;
out vec4 Frag_Color;

void main() {
    Frag_UV = TexturePosition;
    Frag_Color = Color;
    gl_Position = projection * vec4(Position.xy, 0, 1);
}
		)=====");
    shader.addFragmentShader(R"=====(
#version 450

layout (location = 0) out vec4 Out_Color;

in vec2 Frag_UV;
in vec4 Frag_Color;
uniform sampler2D Texture;

void main() {
    Out_Color = Frag_Color * texture(Texture, Frag_UV.st);
}
		)=====");
    shader.linkShaders();

    projectionPosition = shader.getUniformLocation("projection");

    vertexArrayObject.setArray<float>(2, shader.getAttribLocation("Position"), (uint32_t) offsetof(ImDrawVert, pos));
    vertexArrayObject.setArray<float>(2, shader.getAttribLocation("TexturePosition"), (uint32_t) offsetof(ImDrawVert, uv));
    vertexArrayObject.setArray<uint8_t>(4, shader.getAttribLocation("Color"), (uint32_t) offsetof(ImDrawVert, col), true);
}

void Context::buildFont() {
    unsigned char *pixels;
    int w, h;
    ImGuiIO &io = ImGui::GetIO();
    io.Fonts->GetTexDataAsRGBA32(&pixels, &w, &h);
    fontTexture.setRGBA32data(pixels, w, h);
    io.Fonts->TexID = (ImTextureID) &fontTexture;
    if (!io.Fonts->IsBuilt())
        throw Core::Exception("imgui Fonts not build");
}

void Context::draw(const Blob::GL::Window &window) {
    ImGui::Render();
    ImDrawData *drawData = ImGui::GetDrawData();

    ImGuiIO &io = ImGui::GetIO();

    GL::VertexBufferObject imguiVBO;

    drawData->ScaleClipRects(io.DisplayFramebufferScale);

    int fb_height = (int) (drawData->DisplaySize.y * io.DisplayFramebufferScale.y);

    unsigned int sizeTot = 0;
    for (int n = 0; n < drawData->CmdListsCount; n++) {
        const ImDrawList *cmd_list = drawData->CmdLists[n];

        sizeTot += cmd_list->VtxBuffer.Size;
    }

    if (sizeTot > 0)
        imguiVBO.setData(nullptr, sizeTot * sizeof(ImDrawVert), true);

    unsigned int offset = 0;

    window.setVAO(vertexArrayObject);
    setShader(shader);
    setScissorTest(true);
    setCullFace(false);
    setDepthTest(false);

    for (int n = 0; n < drawData->CmdListsCount; n++) {
        ImDrawList *cmd_list = drawData->CmdLists[n];
        size_t idx_buffer_offset = 0;

        imguiVBO.setSubData((uint8_t *) cmd_list->VtxBuffer.Data, cmd_list->VtxBuffer.Size * sizeof(ImDrawVert), offset * sizeof(ImDrawVert));

        vertexArrayObject.setBuffer(imguiVBO, sizeof(ImDrawVert), offset * sizeof(ImDrawVert));

        for (int cmd_i = 0; cmd_i < cmd_list->CmdBuffer.Size; cmd_i++) {
            const ImDrawCmd *pcmd = &cmd_list->CmdBuffer[cmd_i];

            setScissor((int) pcmd->ClipRect.x, (int) (fb_height - pcmd->ClipRect.w), (int) (pcmd->ClipRect.z - pcmd->ClipRect.x),
                                 (int) (pcmd->ClipRect.w - pcmd->ClipRect.y));

            setTexture(*((GL::Texture *) pcmd->TextureId));
            setUniform(projectionMatrix, projectionPosition);

            window.drawIndex<unsigned short>(cmd_list->IdxBuffer.Data, cmd_list->IdxBuffer.Size);

            idx_buffer_offset += pcmd->ElemCount;
        }
    }

    setScissorTest(false);
    setCullFace(true);
    setDepthTest(true);
}

void Context::setWindowSize(const Maths::Vec2<float> &windowSize, const Maths::Vec2<float> &framebufferSize) {
    projectionMatrix[0] = 2.0f / framebufferSize.x;
    projectionMatrix[5] = 2.0f / -framebufferSize.y;

    ImGuiIO &io = ImGui::GetIO();
    io.DisplaySize = windowSize.cast<float>();
    if (windowSize.x > 0 && windowSize.y > 0)
        io.DisplayFramebufferScale = ImVec2(framebufferSize.x / windowSize.x, framebufferSize.y / windowSize.y);
}

const char *Context::getClipboardText(void *user_data) {
    return ((GLFW::Window *) user_data)->getClipboardText().c_str();
}

void Context::setClipboardText(void *user_data, const char *text) {
    ((GLFW::Window *) user_data)->setClipboardText(text);
}

void Context::updateMouseCursor(GLFW::Window &window) {
    ImGuiIO &io = ImGui::GetIO();
    if ((io.ConfigFlags & ImGuiConfigFlags_NoMouseCursorChange))
        return;

    ImGuiMouseCursor imgui_cursor = ImGui::GetMouseCursor();
    if (imgui_cursor == ImGuiMouseCursor_None || io.MouseDrawCursor)
        window.hideMouseCursor(true);
    else {
        window.setMouseCursor((GLFW::MouseCursor) imgui_cursor);
        window.hideMouseCursor(false);
    }
}

void Context::addInputCharacter(unsigned short c) {
    ImGuiIO &io = ImGui::GetIO();

    io.AddInputCharacter(c);
}

}; // namespace Blob::Core
#include <Blob/Exception.hpp>
#include <Blob/GL/Core.hpp>
#include <Blob/ImGUI.hpp>
#include <imgui.h>
#include <iostream>

namespace Blob::Core {
ImGUI::ImGUI() {
    std::cout << "init ImGUI" << std::endl;

    ImGui::StyleColorsDark();

    ImGuiIO &io = ImGui::GetIO();
    io.BackendRendererName = "BlobEngine"; // We are not upscaling the FrameBuffer
    io.DisplayFramebufferScale = {1, 1};   // getFrameBufferSize() / getSize();

    io.IniFilename = nullptr;

    buildFont();

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

void ImGUI::buildFont() {
    unsigned char *pixels;
    int w, h;
    ImGuiIO &io = ImGui::GetIO();
    io.Fonts->GetTexDataAsRGBA32(&pixels, &w, &h);
    fontTexture.setRGBA32data(pixels, w, h);
    io.Fonts->TexID = (ImTextureID) &fontTexture;
    if (!io.Fonts->IsBuilt())
        throw Exception("imgui Fonts not build");
}

void ImGUI::draw() {
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

    GL::Core::setVAO(vertexArrayObject);
    GL::Core::setShader(shader);
    GL::Core::setScissorTest(true);
    GL::Core::setCullFace(false);
    GL::Core::setDepthTest(false);

    for (int n = 0; n < drawData->CmdListsCount; n++) {
        ImDrawList *cmd_list = drawData->CmdLists[n];
        size_t idx_buffer_offset = 0;

        imguiVBO.setSubData((uint8_t *) cmd_list->VtxBuffer.Data, cmd_list->VtxBuffer.Size * sizeof(ImDrawVert), offset * sizeof(ImDrawVert));

        vertexArrayObject.setBuffer(imguiVBO, sizeof(ImDrawVert), offset * sizeof(ImDrawVert));

        for (int cmd_i = 0; cmd_i < cmd_list->CmdBuffer.Size; cmd_i++) {
            const ImDrawCmd *pcmd = &cmd_list->CmdBuffer[cmd_i];

            GL::Core::setScissor((int) pcmd->ClipRect.x, (int) (fb_height - pcmd->ClipRect.w), (int) (pcmd->ClipRect.z - pcmd->ClipRect.x),
                                 (int) (pcmd->ClipRect.w - pcmd->ClipRect.y));

            GL::Core::setTexture(*((GL::Texture *) pcmd->TextureId));
            GL::Core::setMat4(projectionMatrix, projectionPosition);

            GL::Core::drawIndex<unsigned short>(cmd_list->IdxBuffer.Data, cmd_list->IdxBuffer.Size);

            idx_buffer_offset += pcmd->ElemCount;
        }
    }

    GL::Core::setScissorTest(false);
    GL::Core::setCullFace(true);
    GL::Core::setDepthTest(true);
}

void ImGUI::setWindowSize(unsigned int width, unsigned int height) {
    ImGui::GetIO().DisplaySize = {(float) width, (float) height};
    projectionMatrix[0] = 2.0f / ((float) width);
    projectionMatrix[5] = 2.0f / -((float) height);
}

}; // namespace Blob

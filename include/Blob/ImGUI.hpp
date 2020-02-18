#pragma once

#include <imgui.h>
#include <Blob/Shapes.hpp>
#include <Blob/Exception.hpp

namespace Blob {
    class ImGUI {
    private:
        Texture fontTexture;
        Renderable model;
        VertexBufferObject vertexBufferObject;
        VertexArrayObject vertexArrayObject;
        float projectionMatrix[16];

    public:
        ImGUI(unsigned int width, unsigned int height) :
                             model(vertexArrayObject, *Shaders::Shader_2D_POSITION_TEXCOORD_0_COLOR_0, fontTexture)
        {
            projectionMatrix[0] = 2.0f / ((float) width);
            projectionMatrix[1] = 0;
            projectionMatrix[2] = 0;
            projectionMatrix[3] = 0;

            projectionMatrix[4] = 0;
            projectionMatrix[5] = 2.0f / -((float) height);
            projectionMatrix[6] = 0;
            projectionMatrix[7] = 0;

            projectionMatrix[8] = 0;
            projectionMatrix[9] = 0;
            projectionMatrix[10] = -1;
            projectionMatrix[11] = 0;

            projectionMatrix[12] = -1;
            projectionMatrix[13] = 1;
            projectionMatrix[14] = 0;
            projectionMatrix[15] = 1;

            ImGuiIO &io = ImGui::GetIO();
            io.BackendRendererName = "BlobEngine";
            // We are not upscaling the FrameBuffer
            io.DisplayFramebufferScale = {1, 1}; // getFrameBufferSize() / getSize();
            io.DisplaySize = {(float) width, (float) height};

            io.IniFilename = nullptr;

            buildFont();

            model.scissorTest = true;
            model.cullFace = false;
            model.depthTest = false;

            vertexArrayObject.setArray(2, "Position", GL_FLOAT, (uint32_t) offsetof(ImDrawVert, pos));
            vertexArrayObject.setArray(2, "TexturePosition", GL_FLOAT, (uint32_t) offsetof(ImDrawVert, uv));
            vertexArrayObject.setArray(4, "Color", GL_UNSIGNED_BYTE, (uint32_t) offsetof(ImDrawVert, col), true);

            ImGui::CreateContext();
            ImGui::StyleColorsDark();
        }

        ~ImGUI() {
            ImGui::DestroyContext();
        }

        void buildFont() {
            unsigned char *pixels;
            int w, h;
            ImGuiIO &io = ImGui::GetIO();
            io.Fonts->GetTexDataAsRGBA32(&pixels, &w, &h);
            fontTexture.setRGBA32data(pixels, w, h);
            io.Fonts->TexID = (ImTextureID) &fontTexture;
            if (!io.Fonts->IsBuilt())
                throw Exception("imgui Fonts not build");
        }
    };
}

#include "imgui.h"
#include "imgui_impl_opengl3.h"
#include <stdio.h>

#include <stdint.h>     // intptr_t

#include <glad/glad.h>

#include <BlobEngine/BlobGL/ShaderProgram.hpp>
#include <BlobEngine/BlobGL/Texture.hpp>
#include <BlobEngine/BlobGL/VertexArrayObject.hpp>

// OpenGL Data
static int          g_AttribLocationTex = 0, g_AttribLocationProjMtx = 0;
static int          g_AttribLocationPosition = 0, g_AttribLocationUV = 0, g_AttribLocationColor = 0;
static unsigned int g_ElementsHandle = 0;

Blob::GL::ShaderProgram *shaderProgram;
Blob::GL::Texture *fontTexture;
Blob::GL::VertexArrayObject *vao;
Blob::GL::VertexBufferObject *vbo;

// Functions
bool    ImGui_ImplOpenGL3_Init(const char* glsl_version)
{
    ImGuiIO& io = ImGui::GetIO();
    io.BackendRendererName = "imgui_impl_opengl3";

    return true;
}

void    ImGui_ImplOpenGL3_Shutdown()
{
	delete shaderProgram;

	delete vbo;
	delete vao;
	if (g_ElementsHandle) glDeleteBuffers(1, &g_ElementsHandle);
	g_ElementsHandle = 0;

	delete fontTexture;
}

void    ImGui_ImplOpenGL3_NewFrame()
{
	shaderProgram = new Blob::GL::ShaderProgram("data/vertex2D.glsl", "data/fragment2D.glsl");

	g_AttribLocationTex = shaderProgram->getUniformLocation("Texture");
	g_AttribLocationProjMtx = shaderProgram->getUniformLocation("projection");
	g_AttribLocationPosition = shaderProgram->getAttribLocation("Position");
	g_AttribLocationUV = shaderProgram->getAttribLocation("TexturePosition");
	g_AttribLocationColor = shaderProgram->getAttribLocation("Color");

	// Create buffers
	vbo = new Blob::GL::VertexBufferObject();
	vao = new Blob::GL::VertexArrayObject();

	glGenBuffers(1, &g_ElementsHandle);

	// Build texture atlas
	ImGuiIO& io = ImGui::GetIO();
	unsigned char* pixels;
	int width, height;
	io.Fonts->GetTexDataAsRGBA32(&pixels, &width, &height);   // Load as RGBA 32-bits (75% of the memory is wasted, but default font is so small) because it is more likely to be compatible with user's existing shaders. If your ImTextureId represent a higher-level concept than just a GL texture id, consider calling GetTexDataAsAlpha8() instead to save on GPU memory.

	fontTexture = new Blob::GL::Texture();

	fontTexture->setRGBA32data(pixels, width, height);

	io.Fonts->TexID = (ImTextureID)(intptr_t)fontTexture->getTextureID();
}

void    ImGui_ImplOpenGL3_RenderDrawData(ImDrawData* draw_data)
{
    // Avoid rendering when minimized, scale coordinates for retina displays (screen coordinates != framebuffer coordinates)
    ImGuiIO& io = ImGui::GetIO();
    int fb_width = (int)(draw_data->DisplaySize.x * io.DisplayFramebufferScale.x);
    int fb_height = (int)(draw_data->DisplaySize.y * io.DisplayFramebufferScale.y);
    if (fb_width <= 0 || fb_height <= 0)
        return;
    draw_data->ScaleClipRects(io.DisplayFramebufferScale);

    //clip
    bool clip_origin_lower_left = true;



    //GLenum last_clip_origin = 0; glGetIntegerv(GL_CLIP_ORIGIN, (GLint*)&last_clip_origin); // Support for GL 4.5's glClipControl(GL_UPPER_LEFT)
    //if (last_clip_origin == GL_UPPER_LEFT)
    //    clip_origin_lower_left = false;

	glClipControl(GL_UPPER_LEFT,  GL_NEGATIVE_ONE_TO_ONE);

    // Setup render state: alpha-blending enabled, no face culling, no depth testing, scissor enabled, polygon fill
    glEnable(GL_BLEND);
    glBlendEquation(GL_FUNC_ADD);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDisable(GL_CULL_FACE);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_SCISSOR_TEST);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    // Setup viewport, orthographic projection matrix
    // Our visible imgui space lies from draw_data->DisplayPos (top left) to draw_data->DisplayPos+data_data->DisplaySize (bottom right). DisplayMin is typically (0,0) for single viewport apps.
    glViewport(0, 0, (GLsizei)fb_width, (GLsizei)fb_height);
    float L = draw_data->DisplayPos.x;
    float R = draw_data->DisplayPos.x + draw_data->DisplaySize.x;
    float T = draw_data->DisplayPos.y;
    float B = draw_data->DisplayPos.y + draw_data->DisplaySize.y;
    const float ortho_projection[4][4] =
    {
        { 2.0f/(R-L),   0.0f,         0.0f,   0.0f },
        { 0.0f,         2.0f/(T-B),   0.0f,   0.0f },
        { 0.0f,         0.0f,        -1.0f,   0.0f },
        { (R+L)/(L-R),  (T+B)/(B-T),  0.0f,   1.0f },
    };
    glUseProgram(shaderProgram->getProgram());
    glUniform1i(g_AttribLocationTex, 0);
    glUniformMatrix4fv(g_AttribLocationProjMtx, 1, GL_FALSE, &ortho_projection[0][0]);
    glBindSampler(0, 0); // We use combined texture/sampler state. Applications using GL 3.3 may set that otherwise.

	vao->setArray(2, g_AttribLocationPosition, GL_FLOAT, (uint32_t)offsetof(ImDrawVert, pos));
	vao->setArray(2, g_AttribLocationUV, GL_FLOAT, (uint32_t)offsetof(ImDrawVert, uv));
	vao->setArray(4, g_AttribLocationColor, GL_UNSIGNED_BYTE, (uint32_t)offsetof(ImDrawVert, col), true);

	glBindVertexArray(vao->getVertexArrayObject());

    // Draw
    ImVec2 pos = draw_data->DisplayPos;

    unsigned int sizeTot = 0;
	for (int n = 0; n < draw_data->CmdListsCount; n++) {
		const ImDrawList *cmd_list = draw_data->CmdLists[n];

		sizeTot += cmd_list->VtxBuffer.Size;
	}

	if(sizeTot > 0)
		vbo->setData(nullptr, sizeTot * sizeof(ImDrawVert), true);

	unsigned int offset = 0;

    for (int n = 0; n < draw_data->CmdListsCount; n++)
    {
        const ImDrawList* cmd_list = draw_data->CmdLists[n];
        const ImDrawIdx* idx_buffer_offset = 0;

        glBindBuffer(GL_ARRAY_BUFFER, vbo->getVertexBufferObject());
		vbo->setSubData((uint8_t*) cmd_list->VtxBuffer.Data, cmd_list->VtxBuffer.Size * sizeof(ImDrawVert), offset * sizeof(ImDrawVert));

		vao->setBuffer(*vbo, sizeof(ImDrawVert), offset * sizeof(ImDrawVert));
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, g_ElementsHandle);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, (GLsizeiptr)cmd_list->IdxBuffer.Size * sizeof(ImDrawIdx), (const GLvoid*)cmd_list->IdxBuffer.Data, GL_STREAM_DRAW);

        for (int cmd_i = 0; cmd_i < cmd_list->CmdBuffer.Size; cmd_i++)
        {
            const ImDrawCmd* pcmd = &cmd_list->CmdBuffer[cmd_i];
            if (pcmd->UserCallback)
            {
                // User callback (registered via ImDrawList::AddCallback)
                pcmd->UserCallback(cmd_list, pcmd);
            }
            else
            {
                ImVec4 clip_rect = ImVec4(pcmd->ClipRect.x - pos.x, pcmd->ClipRect.y - pos.y, pcmd->ClipRect.z - pos.x, pcmd->ClipRect.w - pos.y);
                if (clip_rect.x < fb_width && clip_rect.y < fb_height && clip_rect.z >= 0.0f && clip_rect.w >= 0.0f)
                {
                    // Apply scissor/clipping rectangle
                    if (clip_origin_lower_left)
                        glScissor((int)clip_rect.x, (int)(fb_height - clip_rect.w), (int)(clip_rect.z - clip_rect.x), (int)(clip_rect.w - clip_rect.y));
                    else
                        glScissor((int)pcmd->ClipRect.x, (int)pcmd->ClipRect.y, (int)pcmd->ClipRect.z, (int)pcmd->ClipRect.w); // Support for GL 4.5's glClipControl(GL_UPPER_LEFT)

                    // Bind texture, Draw
                    glBindTexture(GL_TEXTURE_2D, (GLuint)(intptr_t)pcmd->TextureId);
                    glDrawElements(GL_TRIANGLES, (GLsizei)pcmd->ElemCount, GL_UNSIGNED_SHORT, idx_buffer_offset);
                }
            }
            idx_buffer_offset += pcmd->ElemCount;
        }

		offset += cmd_list->VtxBuffer.Size;
    }

	glScissor(0, 0, (GLsizei)fb_width, (GLsizei)fb_height);
}


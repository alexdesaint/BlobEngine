#include <BlobEngine/BlobGL/VertexBufferObject.hpp>
#include <BlobEngine/BlobGL/ShaderProgram.hpp>
#include <BlobEngine/BlobGL/Texture.hpp>
#include <BlobEngine/BlobGL/VertexArrayObject.hpp>
#include <BlobEngine/BlobGL/Renderable.hpp>
#include <BlobEngine/BlobGL/Graphic.hpp>

#include "imgui.h"
#include <stdio.h>

#include <glad/glad.h>  // Initialize with gladLoadGL()
#include <GLFW/glfw3.h>
#ifdef _WIN32
#undef APIENTRY
#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3native.h>   // for glfwGetWin32Window
#endif

static const char* ImGui_ImplGlfw_GetClipboardText(void* user_data)
{
	return glfwGetClipboardString((GLFWwindow*)user_data);
}

static void ImGui_ImplGlfw_SetClipboardText(void* user_data, const char* text)
{
	glfwSetClipboardString((GLFWwindow*)user_data, text);
}
int main(int, char**)
{
	Blob::GL::Graphic graphic(false);
	auto g_Window = (GLFWwindow*)graphic.getWindow();
    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.IniFilename = nullptr;
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;  // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;   // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsClassic();

	// Setup back-end capabilities flags
	io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;         // We can honor GetMouseCursor() values (optional)
	io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;          // We can honor io.WantSetMousePos requests (optional, rarely used)
	io.BackendPlatformName = "imgui_impl_glfw";

	// Keyboard mapping. ImGui will use those indices to peek into the io.KeysDown[] array.
	io.KeyMap[ImGuiKey_Tab] = GLFW_KEY_TAB;
	io.KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT;
	io.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;
	io.KeyMap[ImGuiKey_UpArrow] = GLFW_KEY_UP;
	io.KeyMap[ImGuiKey_DownArrow] = GLFW_KEY_DOWN;
	io.KeyMap[ImGuiKey_PageUp] = GLFW_KEY_PAGE_UP;
	io.KeyMap[ImGuiKey_PageDown] = GLFW_KEY_PAGE_DOWN;
	io.KeyMap[ImGuiKey_Home] = GLFW_KEY_HOME;
	io.KeyMap[ImGuiKey_End] = GLFW_KEY_END;
	io.KeyMap[ImGuiKey_Insert] = GLFW_KEY_INSERT;
	io.KeyMap[ImGuiKey_Delete] = GLFW_KEY_DELETE;
	io.KeyMap[ImGuiKey_Backspace] = GLFW_KEY_BACKSPACE;
	io.KeyMap[ImGuiKey_Space] = GLFW_KEY_SPACE;
	io.KeyMap[ImGuiKey_Enter] = GLFW_KEY_ENTER;
	io.KeyMap[ImGuiKey_Escape] = GLFW_KEY_ESCAPE;
	io.KeyMap[ImGuiKey_A] = GLFW_KEY_A;
	io.KeyMap[ImGuiKey_C] = GLFW_KEY_C;
	io.KeyMap[ImGuiKey_V] = GLFW_KEY_V;
	io.KeyMap[ImGuiKey_X] = GLFW_KEY_X;
	io.KeyMap[ImGuiKey_Y] = GLFW_KEY_Y;
	io.KeyMap[ImGuiKey_Z] = GLFW_KEY_Z;

	bool                 g_MouseJustPressed[5] = { false, false, false, false, false };
	GLFWcursor*          g_MouseCursors[ImGuiMouseCursor_COUNT] = { 0 };

	io.SetClipboardTextFn = ImGui_ImplGlfw_SetClipboardText;
	io.GetClipboardTextFn = ImGui_ImplGlfw_GetClipboardText;
	io.ClipboardUserData = g_Window;

	g_MouseCursors[ImGuiMouseCursor_Arrow] = glfwCreateStandardCursor(GLFW_ARROW_CURSOR);
	g_MouseCursors[ImGuiMouseCursor_TextInput] = glfwCreateStandardCursor(GLFW_IBEAM_CURSOR);
	g_MouseCursors[ImGuiMouseCursor_ResizeAll] = glfwCreateStandardCursor(GLFW_ARROW_CURSOR);   // FIXME: GLFW doesn't have this.
	g_MouseCursors[ImGuiMouseCursor_ResizeNS] = glfwCreateStandardCursor(GLFW_VRESIZE_CURSOR);
	g_MouseCursors[ImGuiMouseCursor_ResizeEW] = glfwCreateStandardCursor(GLFW_HRESIZE_CURSOR);
	g_MouseCursors[ImGuiMouseCursor_ResizeNESW] = glfwCreateStandardCursor(GLFW_ARROW_CURSOR);  // FIXME: GLFW doesn't have this.
	g_MouseCursors[ImGuiMouseCursor_ResizeNWSE] = glfwCreateStandardCursor(GLFW_ARROW_CURSOR);  // FIXME: GLFW doesn't have this.
	g_MouseCursors[ImGuiMouseCursor_Hand] = glfwCreateStandardCursor(GLFW_HAND_CURSOR);

	io.BackendRendererName = "imgui_impl_opengl3";

    bool show_demo_window = false;
    bool show_another_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

	Blob::GL::ShaderProgram shaderProgram("data/vertex2D.glsl", "data/fragment2D.glsl");
	// Build texture atlas
	unsigned char* pixels;
	int width, height;
	io.Fonts->GetTexDataAsRGBA32(&pixels, &width, &height);   // Load as RGBA 32-bits (75% of the memory is wasted, but default font is so small) because it is more likely to be compatible with user's existing shaders. If your ImTextureId represent a higher-level concept than just a GL texture id, consider calling GetTexDataAsAlpha8() instead to save on GPU memory.

	Blob::GL::Texture fontTexture;

	fontTexture.setRGBA32data(pixels, width, height);

	//io.Fonts->TexID = (ImTextureID)(intptr_t)fontTexture.getTextureID();
	io.Fonts->TexID = (ImTextureID)&fontTexture;

	Blob::GL::Renderable imguiRenderable;
	imguiRenderable.setShaderProgram(&shaderProgram);

	Blob::GL::VertexBufferObject vbo;

	imguiRenderable.setArrayVAO(2, "Position", GL_FLOAT, (uint32_t)offsetof(ImDrawVert, pos));
	imguiRenderable.setArrayVAO(2, "TexturePosition", GL_FLOAT, (uint32_t)offsetof(ImDrawVert, uv));
	imguiRenderable.setArrayVAO(4, "Color", GL_UNSIGNED_BYTE, (uint32_t)offsetof(ImDrawVert, col), true);

	double               g_Time = 0.0;
	unsigned int g_ElementsHandle = 0;
	glGenBuffers(1, &g_ElementsHandle);

    while (graphic.isOpen())
    {
        glfwPollEvents();

		ImGuiIO& io = ImGui::GetIO();
		IM_ASSERT(io.Fonts->IsBuilt() && "Font atlas not built! It is generally built by the renderer back-end. Missing call to renderer _NewFrame() function? e.g. ImGui_ImplOpenGL3_NewFrame().");

		// Setup display size (every frame to accommodate for window resizing)
		io.DisplayFramebufferScale = ImVec2(graphic.getFrameBufferSize().x/graphic.getSize().x, graphic.getFrameBufferSize().y/graphic.getSize().y);
		io.DisplaySize = ImVec2(graphic.getSize().x, graphic.getSize().y);

		// Setup time step
		double current_time = glfwGetTime();
		io.DeltaTime = g_Time > 0.0 ? (float)(current_time - g_Time) : (float)(1.0f/60.0f);
		g_Time = current_time;

		// Update buttons
		for (int i = 0; i < IM_ARRAYSIZE(io.MouseDown); i++)
		{
			// If a mouse press event came, always pass it as "mouse held this frame", so we don't miss click-release events that are shorter than 1 frame.
			io.MouseDown[i] = g_MouseJustPressed[i] || glfwGetMouseButton(g_Window, i) != 0;
			g_MouseJustPressed[i] = false;
		}

		// Update mouse position
		const ImVec2 mouse_pos_backup = io.MousePos;
		io.MousePos = ImVec2(-FLT_MAX, -FLT_MAX);

		const bool focused = glfwGetWindowAttrib(g_Window, GLFW_FOCUSED) != 0;

		if (focused)
		{
			if (io.WantSetMousePos)
			{
				glfwSetCursorPos(g_Window, (double)mouse_pos_backup.x, (double)mouse_pos_backup.y);
			}
			else
			{
				double mouse_x, mouse_y;
				glfwGetCursorPos(g_Window, &mouse_x, &mouse_y);
				io.MousePos = ImVec2((float)mouse_x, (float)mouse_y);
			}
		}

		if ((io.ConfigFlags & ImGuiConfigFlags_NoMouseCursorChange) || glfwGetInputMode(g_Window, GLFW_CURSOR) == GLFW_CURSOR_DISABLED) {

		} else {
			ImGuiMouseCursor imgui_cursor = ImGui::GetMouseCursor();
			if (imgui_cursor == ImGuiMouseCursor_None || io.MouseDrawCursor) {
				// Hide OS mouse cursor if imgui is drawing it or if it wants no cursor
				glfwSetInputMode(g_Window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
			} else {
				// Show OS mouse cursor
				// FIXME-PLATFORM: Unfocused windows seems to fail changing the mouse cursor with GLFW 3.2, but 3.3 works here.
				glfwSetCursor(g_Window, g_MouseCursors[imgui_cursor] ? g_MouseCursors[imgui_cursor]
																	 : g_MouseCursors[ImGuiMouseCursor_Arrow]);
				glfwSetInputMode(g_Window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
			}
		}

		// Gamepad navigation mapping
		memset(io.NavInputs, 0, sizeof(io.NavInputs));
		if (io.ConfigFlags & ImGuiConfigFlags_NavEnableGamepad)
		{
			// Update gamepad inputs
			#define MAP_BUTTON(NAV_NO, BUTTON_NO)       { if (buttons_count > BUTTON_NO && buttons[BUTTON_NO] == GLFW_PRESS) io.NavInputs[NAV_NO] = 1.0f; }
			#define MAP_ANALOG(NAV_NO, AXIS_NO, V0, V1) { float v = (axes_count > AXIS_NO) ? axes[AXIS_NO] : V0; v = (v - V0) / (V1 - V0); if (v > 1.0f) v = 1.0f; if (io.NavInputs[NAV_NO] < v) io.NavInputs[NAV_NO] = v; }
			int axes_count = 0, buttons_count = 0;
			const float* axes = glfwGetJoystickAxes(GLFW_JOYSTICK_1, &axes_count);
			const unsigned char* buttons = glfwGetJoystickButtons(GLFW_JOYSTICK_1, &buttons_count);
			MAP_BUTTON(ImGuiNavInput_Activate,   0);     // Cross / A
			MAP_BUTTON(ImGuiNavInput_Cancel,     1);     // Circle / B
			MAP_BUTTON(ImGuiNavInput_Menu,       2);     // Square / X
			MAP_BUTTON(ImGuiNavInput_Input,      3);     // Triangle / Y
			MAP_BUTTON(ImGuiNavInput_DpadLeft,   13);    // D-Pad Left
			MAP_BUTTON(ImGuiNavInput_DpadRight,  11);    // D-Pad Right
			MAP_BUTTON(ImGuiNavInput_DpadUp,     10);    // D-Pad Up
			MAP_BUTTON(ImGuiNavInput_DpadDown,   12);    // D-Pad Down
			MAP_BUTTON(ImGuiNavInput_FocusPrev,  4);     // L1 / LB
			MAP_BUTTON(ImGuiNavInput_FocusNext,  5);     // R1 / RB
			MAP_BUTTON(ImGuiNavInput_TweakSlow,  4);     // L1 / LB
			MAP_BUTTON(ImGuiNavInput_TweakFast,  5);     // R1 / RB
			MAP_ANALOG(ImGuiNavInput_LStickLeft, 0,  -0.3f,  -0.9f);
			MAP_ANALOG(ImGuiNavInput_LStickRight,0,  +0.3f,  +0.9f);
			MAP_ANALOG(ImGuiNavInput_LStickUp,   1,  +0.3f,  +0.9f);
			MAP_ANALOG(ImGuiNavInput_LStickDown, 1,  -0.3f,  -0.9f);
			#undef MAP_BUTTON
			#undef MAP_ANALOG
			if (axes_count > 0 && buttons_count > 0)
				io.BackendFlags |= ImGuiBackendFlags_HasGamepad;
			else
				io.BackendFlags &= ~ImGuiBackendFlags_HasGamepad;
		}

        ImGui::NewFrame();

        if (show_demo_window)
            ImGui::ShowDemoWindow(&show_demo_window);

        {
            static float f = 0.0f;
            static int counter = 0;

            ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

            ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
            ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
            ImGui::Checkbox("Another Window", &show_another_window);

            ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
            ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

            if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
                counter++;
            ImGui::SameLine();
            ImGui::Text("counter = %d", counter);

            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
            ImGui::End();
        }

        if (show_another_window)
        {
            ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
            ImGui::Text("Hello from another window!");
            if (ImGui::Button("Close Me"))
                show_another_window = false;
            ImGui::End();
        }

        ImGui::Render();
        glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        auto draw_data = ImGui::GetDrawData();

		draw_data->ScaleClipRects(io.DisplayFramebufferScale);

		//glClipControl(GL_UPPER_LEFT,  GL_NEGATIVE_ONE_TO_ONE);

		// Setup render state: alpha-blending enabled, no face culling, no depth testing, scissor enabled, polygon fill
		glEnable(GL_BLEND);
		glBlendEquation(GL_FUNC_ADD);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glDisable(GL_CULL_FACE);
		glDisable(GL_DEPTH_TEST);
		glEnable(GL_SCISSOR_TEST);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		// Draw

		unsigned int sizeTot = 0;
		for (int n = 0; n < draw_data->CmdListsCount; n++) {
			const ImDrawList *cmd_list = draw_data->CmdLists[n];

			sizeTot += cmd_list->VtxBuffer.Size;
		}

		if(sizeTot > 0)
			vbo.setData(nullptr, sizeTot * sizeof(ImDrawVert), true);

		unsigned int offset = 0;

		for (int n = 0; n < draw_data->CmdListsCount; n++)
		{
			const ImDrawList* cmd_list = draw_data->CmdLists[n];
			size_t idx_buffer_offset = 0;

			vbo.setSubData((uint8_t*) cmd_list->VtxBuffer.Data, cmd_list->VtxBuffer.Size * sizeof(ImDrawVert), offset * sizeof(ImDrawVert));

			imguiRenderable.setBuffer(vbo, sizeof(ImDrawVert), offset * sizeof(ImDrawVert));

			imguiRenderable.setIndices(cmd_list->IdxBuffer.Data, cmd_list->IdxBuffer.Size, GL_UNSIGNED_SHORT);

			for (int cmd_i = 0; cmd_i < cmd_list->CmdBuffer.Size; cmd_i++)
			{
				const ImDrawCmd* pcmd = &cmd_list->CmdBuffer[cmd_i];

				glScissor((int)pcmd->ClipRect.x, (int)(graphic.getSize().y - pcmd->ClipRect.w), (int)(pcmd->ClipRect.z - pcmd->ClipRect.x), (int)(pcmd->ClipRect.w - pcmd->ClipRect.y));

				imguiRenderable.setTexture(*(Blob::GL::Texture*)pcmd->TextureId);
				graphic.draw(imguiRenderable, pcmd->ElemCount, idx_buffer_offset);

				idx_buffer_offset += pcmd->ElemCount;
			}

			offset += cmd_list->VtxBuffer.Size;
		}

		glScissor(0, 0, graphic.getSize().x, graphic.getSize().y);

        graphic.display();
    }

    // Cleanup
	if (g_ElementsHandle) glDeleteBuffers(1, &g_ElementsHandle);
	g_ElementsHandle = 0;
    ImGui::DestroyContext();

    return 0;
}

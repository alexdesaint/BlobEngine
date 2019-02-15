//blobEngine
#include <BlobEngine/BlobException.hpp>
#include <BlobEngine/BlobGL/Renderable.hpp>
#include <BlobEngine/BlobGL/Graphic.hpp>
#include <BlobEngine/BlobGL/Shapes.hpp>

//std
#include <iostream>

// GLFW
//#include <SFML/Window.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

//glm
#include <glm/gtc/type_ptr.hpp>

//imgui
#include <imgui.h>


static void GLAPIENTRY openglCallbackFunction(
		GLenum source,
		GLenum type,
		GLuint id,
		GLenum severity,
		GLsizei length,
		const GLchar *message,
		const void *userParam
) {
	(void) source;
	(void) type;
	(void) id;
	(void) length;
	(void) userParam;

	switch (severity) {
		case GL_DEBUG_SEVERITY_NOTIFICATION :
			std::cout << "Notification :" << std::endl << message;
			break;
		case GL_DEBUG_SEVERITY_LOW:
			std::cout << "Low severity Error :" << std::endl << message;
			break;
		case GL_DEBUG_SEVERITY_MEDIUM:
			std::cout << "Medium severity Error :" << std::endl << message;
			break;
		case GL_DEBUG_SEVERITY_HIGH:
			std::cout << "High severity Error :" << std::endl << message;
			abort();
		default:
			std::cout << "Unknow Error severity :" << std::endl << message;
			break;
	}
}

namespace Blob::GL {

	//using namespace GL;

	std::array<bool, Key::KeyCount> Graphic::keys;

	void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
		ImGuiIO& io = ImGui::GetIO();
		if (action == GLFW_PRESS)
			io.KeysDown[key] = true;
		else if (action == GLFW_RELEASE)
			io.KeysDown[key] = false;

		// Modifiers are not reliable across systems
		io.KeyCtrl = io.KeysDown[GLFW_KEY_LEFT_CONTROL] || io.KeysDown[GLFW_KEY_RIGHT_CONTROL];
		io.KeyShift = io.KeysDown[GLFW_KEY_LEFT_SHIFT] || io.KeysDown[GLFW_KEY_RIGHT_SHIFT];
		io.KeyAlt = io.KeysDown[GLFW_KEY_LEFT_ALT] || io.KeysDown[GLFW_KEY_RIGHT_ALT];
		io.KeySuper = io.KeysDown[GLFW_KEY_LEFT_SUPER] || io.KeysDown[GLFW_KEY_RIGHT_SUPER];
	}

	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
		//if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
		//	popup_menu();

		ImGuiIO& io = ImGui::GetIO();

		io.MouseDown[button] = action != GLFW_RELEASE;
	}

	GLFWcursor* g_MouseCursors[ImGuiMouseCursor_COUNT] = {nullptr};
	int oldCursor = 0;

	void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)	{
		ImGuiIO& io = ImGui::GetIO();
		io.MousePos = ImVec2((float)xpos, (float)ypos);

		ImGuiMouseCursor imgui_cursor = ImGui::GetMouseCursor();
		if(imgui_cursor != oldCursor) {
			if (imgui_cursor == ImGuiMouseCursor_None) {
				// Hide OS mouse cursor if imgui is drawing it or if it wants no cursor
				glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
			} else {
				// Show OS mouse cursor
				if (g_MouseCursors[imgui_cursor] != nullptr)
					glfwSetCursor(window, g_MouseCursors[imgui_cursor]);
				else
					glfwSetCursor(window, g_MouseCursors[ImGuiMouseCursor_Arrow]);

				glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
			}
		}
		oldCursor = imgui_cursor;
	}

	void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
		ImGuiIO& io = ImGui::GetIO();
		io.MouseWheelH += (float)xoffset;
		io.MouseWheel += (float)yoffset;
	}

	void character_callback(GLFWwindow* window, unsigned int c) {
		ImGuiIO& io = ImGui::GetIO();
		if (c > 0 && c < 0x10000)
			io.AddInputCharacter((unsigned short)c);
	}

	void framebuffer_size_callback(GLFWwindow *window, int w, int h) {
		auto g = (Graphic*) glfwGetWindowUserPointer(window);
		g->resize(w, h);
	}

	static const char* GetClipboardText(void* user_data)
	{
		return glfwGetClipboardString((GLFWwindow*)user_data);
	}

	static void SetClipboardText(void* user_data, const char* text)
	{
		glfwSetClipboardString((GLFWwindow*)user_data, text);
	}

	void Graphic::enableDebugCallBack() {
		// Enable the debug callback

		glEnable(GL_DEBUG_OUTPUT);
		glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
		glDebugMessageCallback(openglCallbackFunction, nullptr);
		glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE);
	}

	Graphic::Graphic(bool fullScreen, unsigned int w, unsigned int h) :
			width(w),
			height(h),
			cameraPosition(0, 0, 2),
			cameraLookAt(0, 0, 0),
			cameraUp(0, 0, 1) {

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);

		glfwWindowHint(GLFW_SAMPLES, 8);

		if (!glfwInit())
			throw BlobException("Can't init glfw");

		if (fullScreen) {
			const GLFWvidmode *mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
			glfwWindowHint(GLFW_RED_BITS, mode->redBits);
			glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
			glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
			glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

			width = mode->width;
			height = mode->height;

			window = glfwCreateWindow(width, height, "My Title", glfwGetPrimaryMonitor(), nullptr);
		} else {
			window = glfwCreateWindow(width, height, "My Title", nullptr, nullptr);
		}

		if (!window) {
			glfwTerminate();
			throw BlobException("Can't open window");
		}

		glfwMakeContextCurrent((GLFWwindow *) window);
		gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
		glfwSwapInterval(1);

		if (!gladLoadGL()) throw BlobException("Can't loadBMP openGL");

		enableDebugCallBack();

		//general settings
		glFrontFace(GL_CW);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); //pour faire des lignes
		glClearColor(0.2, 0.2, 0.2, 1.0);
		glViewport(0, 0, w, h);
		glCullFace(GL_FRONT);
		//alpha
		glEnable(GL_BLEND);
		glBlendEquation(GL_FUNC_ADD);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		ImGui::CreateContext();
		ImGui::StyleColorsDark();
		ImGuiIO& io = ImGui::GetIO();

		//user pointer
		glfwSetWindowUserPointer((GLFWwindow *) window, this);
		glfwSetFramebufferSizeCallback((GLFWwindow *) window, framebuffer_size_callback);

		//callback
		// Setup back-end capabilities flags
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;         // We can honor GetMouseCursor() values (optional)
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;          // We can honor io.WantSetMousePos requests (optional, rarely used)
		io.BackendPlatformName = "BlobEngine";

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
		glfwSetKeyCallback((GLFWwindow *) window, key_callback);
		glfwSetMouseButtonCallback((GLFWwindow *) window, mouse_button_callback);

		g_MouseCursors[ImGuiMouseCursor_Arrow] = glfwCreateStandardCursor(GLFW_ARROW_CURSOR);
		g_MouseCursors[ImGuiMouseCursor_TextInput] = glfwCreateStandardCursor(GLFW_IBEAM_CURSOR);
		g_MouseCursors[ImGuiMouseCursor_ResizeAll] = glfwCreateStandardCursor(GLFW_CROSSHAIR_CURSOR);   // FIXME: GLFW doesn't have this.
		g_MouseCursors[ImGuiMouseCursor_ResizeNS] = glfwCreateStandardCursor(GLFW_VRESIZE_CURSOR);
		g_MouseCursors[ImGuiMouseCursor_ResizeEW] = glfwCreateStandardCursor(GLFW_HRESIZE_CURSOR);
		g_MouseCursors[ImGuiMouseCursor_ResizeNESW] = glfwCreateStandardCursor(GLFW_CROSSHAIR_CURSOR);  // FIXME: GLFW doesn't have this.
		g_MouseCursors[ImGuiMouseCursor_ResizeNWSE] = glfwCreateStandardCursor(GLFW_CROSSHAIR_CURSOR);  // FIXME: GLFW doesn't have this.
		g_MouseCursors[ImGuiMouseCursor_Hand] = glfwCreateStandardCursor(GLFW_HAND_CURSOR);
		glfwSetCursorPosCallback((GLFWwindow *) window, cursor_position_callback);
		glfwSetScrollCallback((GLFWwindow *) window, scroll_callback);
		glfwSetCharCallback((GLFWwindow *) window, character_callback);

		io.SetClipboardTextFn = SetClipboardText;
		io.GetClipboardTextFn = GetClipboardText;

		projectionMatrix = glm::perspective(glm::radians(45.0f), width / (GLfloat) height, 0.1f, 100.0f);
		viewMatrix = glm::lookAt(cameraPosition, cameraLookAt, cameraUp);

		//imgui
		projectionMatrix2D =
		{
				2.0f/(width), 0.0f,         	0.0f,   0.0f,
				0.0f,         2.0f/(-height), 0.0f,   0.0f,
				0.0f,         0.0f,        	-1.0f,  0.0f,
				-1.f,			1.f,  			0.0f,	1.0f,
		};
		io.DisplayFramebufferScale = ImVec2(getFrameBufferSize().x/getSize().x, getFrameBufferSize().y/getSize().y);
		io.DisplaySize = ImVec2(getSize().x, getSize().y);

		io.IniFilename = nullptr;

		imguiFontTexture = new Texture();
		unsigned char* pixels;
		int width, height;
		io.Fonts->GetTexDataAsRGBA32(&pixels, &width, &height);
		imguiFontTexture->setRGBA32data(pixels, width, height);
		io.Fonts->TexID = (ImTextureID)imguiFontTexture;
		if(!io.Fonts->IsBuilt())
			throw BlobException("imgui Fonts not build");

		imguiRenderable = new Renderable();
		imguiRenderable->scissorTest = true;
		imguiRenderable->cullFace = false;

		imguiShaderProgram = new ShaderProgram();
		imguiShaderProgram->addVertexShader(R"=====(
	#version 450

	layout (location = 0) in vec2 Position;
layout (location = 1) in vec2 TexturePosition;
layout (location = 2) in vec4 Color;

uniform mat4 projection;
out vec2 Frag_UV;
out vec4 Frag_Color;

void main()
{
    Frag_UV = TexturePosition;
    Frag_Color = Color;
    gl_Position = projection * vec4(Position.xy, 0, 1);
}
	)=====");
		imguiShaderProgram->addFragmentShader(R"=====(
	#version 450

	layout (location = 0) out vec4 Out_Color;

in vec2 Frag_UV;
in vec4 Frag_Color;
uniform sampler2D Texture;

void main() {
    //Out_Color = vec4(1.f, 1.f, 1.f, 1.f);
    Out_Color = Frag_Color * texture(Texture, Frag_UV.st);
}
	)=====");
		imguiShaderProgram->linkShaders();

		imguiRenderable->setShaderProgram(*imguiShaderProgram);

		imguiRenderable->setArrayVAO(2, "Position", GL_FLOAT, (uint32_t)offsetof(ImDrawVert, pos));
		imguiRenderable->setArrayVAO(2, "TexturePosition", GL_FLOAT, (uint32_t)offsetof(ImDrawVert, uv));
		imguiRenderable->setArrayVAO(4, "Color", GL_UNSIGNED_BYTE, (uint32_t)offsetof(ImDrawVert, col), true);

		//create Froms
		Shapes::init();

		lastFrameTime = std::chrono::high_resolution_clock::now();
	}

	Graphic::~Graphic() {
		Shapes::destroy();
		ImGui::DestroyContext();
		delete imguiShaderProgram;
		delete imguiFontTexture;
		delete imguiRenderable;

		glfwDestroyWindow((GLFWwindow *) window);
		glfwTerminate();
	}

	void Graphic::clear() {
		glDisable(GL_SCISSOR_TEST);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	}

	float Graphic::display() {
		glfwSwapBuffers((GLFWwindow *) window);

		auto now = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> diff = now - lastFrameTime;
		ImGui::GetIO().DeltaTime = diff.count();
		fpsCouner = fpsCouner + diff;
		lastFrameTime = now;

		if (!(++frameCount % 60)) {
			std::string name = "Test : " + std::to_string(60 / fpsCouner.count()) + " FPS";
			fpsCouner = std::chrono::duration<float>::zero();
			glfwSetWindowTitle((GLFWwindow *) window, name.c_str());
		}

		glfwPollEvents();

		return diff.count();
	}

	void Graphic::resize(unsigned int w, unsigned int h) {
		height = h;
		width = w;

		projectionMatrix = glm::perspective(glm::radians(45.0f), width / (GLfloat) height, 0.1f, 100.0f);

		projectionMatrix2D =
				{
						2.0f/(width), 0.0f,         	0.0f,   0.0f,
						0.0f,         2.0f/(-height), 0.0f,   0.0f,
						0.0f,         0.0f,        	-1.0f,  0.0f,
						-1.f,			1.f,  			0.0f,	1.0f,
				};

		glViewport(0, 0, w, h);

		int ww, hh;
		glfwGetWindowSize((GLFWwindow *) window, &ww, &hh);

		if(ww != w || hh != h)
			glfwSetWindowSize((GLFWwindow *) window, w, h);

		//TODO ajouter ImVec2 --> Vec2f
		ImGuiIO& io = ImGui::GetIO();
		io.DisplayFramebufferScale = ImVec2(getFrameBufferSize().x/getSize().x, getFrameBufferSize().y/getSize().y);
		io.DisplaySize = ImVec2(getSize().x, getSize().y);
	}

	std::ostream &operator<<(std::ostream &out, const glm::mat4 &vec) {

		for (int i = 0; i < 4; i++)
			out << vec[i].x << " " << vec[i].y << " " << vec[i].z << " " << vec[i].w << std::endl;
		return out;
	}

	void Graphic::draw(const Renderable &renderable, glm::mat4 shapeModel) {
		if(renderable.shaderProgram == nullptr)
			throw BlobException("Error on Graphic::draw : No shader program set");

		if(renderable.cullFace)
			glEnable(GL_CULL_FACE);
		else
			glDisable(GL_CULL_FACE);

		if(renderable.scissorTest)
			glEnable(GL_SCISSOR_TEST);
		else
			glDisable(GL_SCISSOR_TEST);

		if(renderable.depthTest)
			glEnable(GL_DEPTH_TEST);
		else
			glDisable(GL_DEPTH_TEST);


		glUseProgram(renderable.shaderProgram->getProgram());
		glBindVertexArray(renderable.vao.getVertexArrayObject());

		glUniformMatrix4fv(renderable.shaderProgram->projection, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
		glUniformMatrix4fv(renderable.shaderProgram->view, 1, GL_FALSE, glm::value_ptr(viewMatrix));
		glUniformMatrix4fv(renderable.shaderProgram->model, 1, GL_FALSE, glm::value_ptr(shapeModel * renderable.getModelMatrix()));

		if (renderable.texture != nullptr) {
			glBindTexture(GL_TEXTURE_2D, renderable.texture->texture);
			glUniform1f(renderable.shaderProgram->textureScale, renderable.texture->textureScale);
		}

		if (renderable.indexed)
			glDrawElements(GL_TRIANGLES, renderable.numOfIndices, renderable.indicesType, renderable.indices);
	}

	void Graphic::draw(const Renderable &renderable, int numOfElements, uint64_t elementOffset, glm::mat4 shapeModel) {

		if(renderable.shaderProgram == nullptr)
			throw BlobException("Error on Graphic::draw : No shader program set");

		if(renderable.cullFace)
			glEnable(GL_CULL_FACE);
		else
			glDisable(GL_CULL_FACE);

		if(renderable.scissorTest)
			glEnable(GL_SCISSOR_TEST);
		else
			glDisable(GL_SCISSOR_TEST);

		if(renderable.depthTest)
			glEnable(GL_DEPTH_TEST);
		else
			glDisable(GL_DEPTH_TEST);

		glUseProgram(renderable.shaderProgram->getProgram());
		glBindVertexArray(renderable.vao.getVertexArrayObject());

		glUniformMatrix4fv(renderable.shaderProgram->projection, 1, GL_FALSE, glm::value_ptr(projectionMatrix2D));
		glUniformMatrix4fv(renderable.shaderProgram->view, 1, GL_FALSE, glm::value_ptr(viewMatrix));
		glUniformMatrix4fv(renderable.shaderProgram->model, 1, GL_FALSE, glm::value_ptr(shapeModel * renderable.getModelMatrix()));

		if (renderable.texture != nullptr) {
			glBindTexture(GL_TEXTURE_2D, renderable.texture->texture);
			glUniform1f(renderable.shaderProgram->textureScale, renderable.texture->textureScale);
		}

		if (renderable.indexed)
			glDrawElements(GL_TRIANGLES, numOfElements, renderable.indicesType, &renderable.indices[elementOffset]);
		else
			glDrawArrays(GL_TRIANGLES, elementOffset, numOfElements);
	}

	void Graphic::draw(const Shape &shape, glm::mat4 sceneModel) {
		glm::mat4 modelMatrix = sceneModel * shape.getModelMatrix();

		/*std::cout << "mat :" << std::endl << modelMatrix;

		std::cout << "r :" << std::endl;
		for(Renderable *r : shape.renderables)
			std::cout << std::hex << r << " ";
		std::cout << std::endl;
*/
		for (auto r : shape.shapes)
			draw(*r, modelMatrix);

		for (auto r : shape.renderables)
			draw(*r, modelMatrix);
	}

	void Graphic::draw(const Scene &scene) {
		glm::mat4 modelMatrix = scene.getModelMatrix();
/*
		std::cout << "mat :" << std::endl << modelMatrix;

		std::cout << "r :" << std::endl;
		for(Shape *r : scene.shapes)
			std::cout << std::hex << r << " ";
		std::cout << std::endl;
*/
		for (auto r : scene.shapes)
			draw(*r, modelMatrix);
	}

	void Graphic::drawImGUI() {
		ImGui::Render();
		ImDrawData *drawData = ImGui::GetDrawData();

		ImGuiIO& io = ImGui::GetIO();

		VertexBufferObject imguiVBO;

		drawData->ScaleClipRects(io.DisplayFramebufferScale);

		int fb_height = (int)(drawData->DisplaySize.y * io.DisplayFramebufferScale.y);
		//

		unsigned int sizeTot = 0;
		for (int n = 0; n < drawData->CmdListsCount; n++) {
			const ImDrawList *cmd_list = drawData->CmdLists[n];

			sizeTot += cmd_list->VtxBuffer.Size;
		}

		if(sizeTot > 0)
			imguiVBO.setData(nullptr, sizeTot * sizeof(ImDrawVert), true);

		unsigned int offset = 0;

		for (int n = 0; n < drawData->CmdListsCount; n++) {
			ImDrawList* cmd_list = drawData->CmdLists[n];
			size_t idx_buffer_offset = 0;

			imguiVBO.setSubData((uint8_t*) cmd_list->VtxBuffer.Data, cmd_list->VtxBuffer.Size * sizeof(ImDrawVert), offset * sizeof(ImDrawVert));

			imguiRenderable->setBuffer(imguiVBO, sizeof(ImDrawVert), offset * sizeof(ImDrawVert));

			imguiRenderable->setIndices(cmd_list->IdxBuffer.Data, cmd_list->IdxBuffer.Size, GL_UNSIGNED_SHORT);

			for (int cmd_i = 0; cmd_i < cmd_list->CmdBuffer.Size; cmd_i++) {
				const ImDrawCmd *pcmd = &cmd_list->CmdBuffer[cmd_i];

				glScissor((int)pcmd->ClipRect.x, (int)(fb_height - pcmd->ClipRect.w), (int)(pcmd->ClipRect.z - pcmd->ClipRect.x), (int)(pcmd->ClipRect.w - pcmd->ClipRect.y));

				imguiRenderable->setTexture(*(Texture*)pcmd->TextureId);
				draw(*imguiRenderable, pcmd->ElemCount, idx_buffer_offset);

				idx_buffer_offset += pcmd->ElemCount;
			}
		}
	}

	bool Graphic::isOpen() const {
		return !(glfwWindowShouldClose((GLFWwindow *) window) || quit);
	}

	std::ostream &operator<<(std::ostream &s, const Graphic &a) {
		s << glGetString(GL_VENDOR) << std::endl <<
		  glGetString(GL_RENDERER) << std::endl <<
		  glGetString(GL_VERSION) << std::endl <<
		  glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
		return s;
	}

	void Graphic::setCameraPosition(float x, float y, float z) {
		cameraPosition = glm::vec3(x, y, z);

		viewMatrix = glm::lookAt(cameraPosition, cameraLookAt, cameraUp);
	}

	void Graphic::setCameraLookAt(float x, float y, float z) {
		cameraLookAt = glm::vec3(x, y, z);

		viewMatrix = glm::lookAt(cameraPosition, cameraLookAt, cameraUp);
	}

	void Graphic::setOrthoProjection(float left, float right, float bottom, float top, float zNear, float zFar) {
		projectionMatrix = glm::ortho(left, right, bottom, top, zNear, zFar);
	}

	const std::array<bool, KeyCount> &Graphic::getKeys() {
		return keys;
	}

	void Graphic::close() {
		quit = true;
	}

	Blob::Vec2f Graphic::getFrameBufferSize() {
		int display_w, display_h;
		glfwGetFramebufferSize((GLFWwindow *) window, &display_w, &display_h);
		return {(float)display_w, (float)display_h};
	}

	void *Graphic::getWindow() const {
		return window;
	}

}
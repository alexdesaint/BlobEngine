#ifndef BLOBENGINE_GRAPHIC_HPP
#define BLOBENGINE_GRAPHIC_HPP

#include <BlobEngine/BlobGL/ShaderProgram.hpp>
#include <BlobEngine/BlobGL/VertexArrayObject.hpp>
#include <BlobEngine/BlobGL/Scene.hpp>
#include <BlobEngine/Geometrie.hpp>

#include <glm/mat4x4.hpp>

#include <ostream>
#include <chrono>
#include <array>

namespace Blob::GL {

	enum Key {
		UNKNOWN = -1,
		SPACE = 32,
		APOSTROPHE = 39,
		COMMA = 44,
		MINUS = 45,
		PERIOD = 46,
		SLASH = 47,
		NUM_0 = 48,
		NUM_1 = 49,
		NUM_2 = 50,
		NUM_3 = 51,
		NUM_4 = 52,
		NUM_5 = 53,
		NUM_6 = 54,
		NUM_7 = 55,
		NUM_8 = 56,
		NUM_9 = 57,
		SEMICOLON = 59,
		EQUAL = 61,
		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,
		LEFT_BRACKET = 91,
		BACKSLASH = 92,
		RIGHT_BRACKET = 93,
		GRAVE_ACCENT = 96,
		WORLD_1 = 161,
		WORLD_2 = 162,
		ESCAPE = 256,
		ENTER = 257,
		TAB = 258,
		BACKSPACE = 259,
		INSERT = 260,
		DELETE = 261,
		RIGHT = 262,
		LEFT = 263,
		DOWN = 264,
		UP = 265,
		PAGE_UP = 266,
		PAGE_DOWN = 267,
		HOME = 268,
		END = 269,
		CAPS_LOCK = 280,
		SCROLL_LOCK = 281,
		NUM_LOCK = 282,
		PRINT_SCREEN = 283,
		PAUSE = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,
		KP_0 = 320,
		KP_1 = 321,
		KP_2 = 322,
		KP_3 = 323,
		KP_4 = 324,
		KP_5 = 325,
		KP_6 = 326,
		KP_7 = 327,
		KP_8 = 328,
		KP_9 = 329,
		KP_DECIMAL = 330,
		KP_DIVIDE = 331,
		KP_MULTIPLY = 332,
		KP_SUBTRACT = 333,
		KP_ADD = 334,
		KP_ENTER = 335,
		KP_EQUAL = 336,
		LEFT_SHIFT = 340,
		LEFT_CONTROL = 341,
		LEFT_ALT = 342,
		LEFT_SUPER = 343,
		RIGHT_SHIFT = 344,
		RIGHT_CONTROL = 345,
		RIGHT_ALT = 346,
		RIGHT_SUPER = 347,
		MENU = 348,
		KeyCount
	};

	class Graphic {
		friend void key_callback(void *window, int key, int scancode, int action, int mods);

	private:

		bool quit = false;
		unsigned int frameCount = 0;

		void *window;

		int width, height;

		glm::mat4 projectionMatrix;
		glm::mat4 viewMatrix{1};

		glm::vec3 cameraPosition; // Camera position in World Space
		glm::vec3 cameraLookAt; // and looks at the origin
		glm::vec3 cameraUp;  // Head is up (set to 0,-1,0 to look upside-down)

		static std::array<bool, Key::KeyCount> keys;

		std::chrono::high_resolution_clock::time_point lastFrameTime;
		std::chrono::duration<float> fpsCouner{0};

		void enableDebugCallBack();

	public:
		Graphic(bool fullScreen = true, unsigned int w = 640, unsigned int h = 480);

		~Graphic();

		void clear();

		float display();

		void resize(unsigned int w, unsigned int h);

		Blob::Vec2f getSize() { return {(float)width, (float)height}; }

		void draw(const Renderable &renderable, const ShaderProgram &program, glm::mat4 shapeModel = glm::mat4(1.0));

		void draw(const Shape &shape, const ShaderProgram &program, glm::mat4 sceneModel = glm::mat4(1.0));

		void draw(const Scene &scene, const ShaderProgram &program);

		bool isOpen() const;

		friend std::ostream &operator<<(std::ostream &s, const Graphic &a);

		void setCameraPosition(float x, float y, float z);

		void setCameraLookAt(float x, float y, float z);

		void setOrthoProjection(float left, float right, float bottom, float top, float zNear, float zFar);

		Blob::Vec2f getFrameBufferSize();

		static const std::array<bool, KeyCount> &getKeys();

		void close();
	};
}

#endif //BLOBENGINE_GRAPHIC_HPP
//blobEngine
#include <BlobEngine/BlobException.hpp>
#include <BlobEngine/BlobGL/Renderable.hpp>
#include <BlobEngine/BlobGL/Graphic.hpp>
#include <BlobEngine/BlobGL/Form.hpp>

//std
#include <iostream>
#include <chrono>

// GLFW
//#include <SFML/Window.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

//glm
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>


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

namespace BlobEngine::BlobGL {

	//using namespace BlobGL;

	std::array<bool, Key::KeyCount> Graphic::keys;

	void key_callback(void *window, int key, int scancode, int action, int mods) {
		if (action != 2) {
			Graphic::keys[key] = (bool) action;
		}
	}

	void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
		glViewport(0, 0, width, height);
	}

	void Graphic::enableDebugCallBack() {
		// Enable the debug callback

		glEnable(GL_DEBUG_OUTPUT);
		glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
		glDebugMessageCallback(openglCallbackFunction, nullptr);
		glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE);
	}

	Graphic::Graphic() :
			cameraPosition(0, 0, 2),
			cameraLookAt(0, 0, 0),
			cameraUp(0, 0, 1) {

		//settings.depthBits = 24;
		//settings.stencilBits = 8;
		//settings.antialiasingLevel = 4;

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);

		glfwWindowHint(GLFW_SAMPLES, 8);

		if (!glfwInit())
			throw BlobException("Can't init glfw");

		const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
		glfwWindowHint(GLFW_RED_BITS, mode->redBits);
		glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
		glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
		glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

		width = mode->width;
		height = mode->height;

		window = glfwCreateWindow(mode->width, mode->height, "My Title", glfwGetPrimaryMonitor(), nullptr);

		if (!window) {
			glfwTerminate();
			throw BlobException("Can't open window");
		}

		glfwMakeContextCurrent((GLFWwindow *) window);
		gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
		glfwSwapInterval(1);

		if (!gladLoadGL()) throw BlobException("Can't loadBMPtexture openGL");


		enableDebugCallBack();

		glEnable(GL_CULL_FACE); // cull face
		glCullFace(GL_FRONT);// cull back face
		glFrontFace(GL_CW);// GL_CCW for counter clock-wise
		glEnable(GL_DEPTH_TEST);
		glClearColor(0.2, 0.2, 0.2, 1.0);

		glfwSetFramebufferSizeCallback((GLFWwindow *) window, framebuffer_size_callback);
		glfwSetKeyCallback((GLFWwindow *) window, (GLFWkeyfun) key_callback);

		projectionMatrix = glm::perspective(glm::radians(45.0f), width / (GLfloat) height, 0.1f, 100.0f);
		viewMatrix = glm::lookAt(cameraPosition, cameraLookAt, cameraUp);

		createVBO();

		lastFrameTime = std::chrono::high_resolution_clock::now();
	}

	Graphic::~Graphic() {
		deleteVBO();

		glfwDestroyWindow((GLFWwindow *) window);
		glfwTerminate();
	}

	void Graphic::clear() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	}

	float Graphic::display() {
		glfwSwapBuffers((GLFWwindow *) window);


		auto now = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> diff = now - lastFrameTime;
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

		projectionMatrix = glm::perspective(glm::radians(10.0f), width / (GLfloat) height, 0.1f, 100.0f);

		glfwSetWindowSize((GLFWwindow *) window, w, h);
	}

	std::ostream &operator<<(std::ostream &out, const glm::mat4 &vec) {

		for (int i = 0; i < 4; i++)
			out << vec[i].x << " " << vec[i].y << " " << vec[i].z << " " << vec[i].w << std::endl;
		return out;
	}

	void Graphic::draw(const Renderable &renderable, const ShaderProgram &program, glm::mat4 shapeModel) {
		glUseProgram(program.getProgram());
		glBindVertexArray(renderable.vao.getVertexArrayObject());

		glUniformMatrix4fv(program.projection, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
		glUniformMatrix4fv(program.view, 1, GL_FALSE, glm::value_ptr(viewMatrix));
		glUniformMatrix4fv(program.model, 1, GL_FALSE, glm::value_ptr(shapeModel * renderable.getModelMatrix()));

		if (renderable.texture != nullptr) {
			glBindTexture(GL_TEXTURE_2D, renderable.texture->texture);
			glUniform1f(program.textureScale, renderable.texture->textureScale);
		}

		if (renderable.indexed)
			glDrawElements(GL_TRIANGLES, renderable.numOfIndices, renderable.indicesType, renderable.indices);
		else
			glDrawArrays(GL_TRIANGLES, 0, renderable.vao.getNumberOfElements());
	}

	void Graphic::draw(const Shape &shape, const ShaderProgram &program, glm::mat4 sceneModel) {
		glm::mat4 modelMatrix = sceneModel * shape.getModelMatrix();

		/*std::cout << "mat :" << std::endl << modelMatrix;

		std::cout << "r :" << std::endl;
		for(Renderable *r : shape.renderables)
			std::cout << std::hex << r << " ";
		std::cout << std::endl;
*/
		for (auto r : shape.renderables)
			draw(*r, program, modelMatrix);
	}

	void Graphic::draw(const Scene &scene, const ShaderProgram &program) {
		glm::mat4 modelMatrix = scene.getModelMatrix();
/*
		std::cout << "mat :" << std::endl << modelMatrix;

		std::cout << "r :" << std::endl;
		for(Shape *r : scene.shapes)
			std::cout << std::hex << r << " ";
		std::cout << std::endl;
*/
		for (auto r : scene.shapes)
			draw(*r, program, modelMatrix);
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

}
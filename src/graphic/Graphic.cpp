#include <BlobEngine/Graphic.hpp>

//blobEngine
#include <BlobEngine/BlobException.hpp>
#include <BlobEngine/Shape.hpp>

//std
#include <iostream>
#include <chrono>

// opengl

//glm
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

static void APIENTRY openglCallbackFunction(
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
	(void) severity;
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

namespace BlobEngine {

	using namespace BlobGL;

	void Graphic::enableDebugCallBack() {
		// Enable the debug callback

		glEnable(GL_DEBUG_OUTPUT);
		glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
		glDebugMessageCallback(openglCallbackFunction, nullptr);
		glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE);
	}

	Graphic::Graphic(unsigned int width, unsigned int height) :
			width(width),
			height(height),
			cameraPosition(10, 10, 10),
			cameraLookAt(0, 0, 0),
			cameraUp(0, 1, 0) {

		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

		if (SDL_Init(SDL_INIT_VIDEO))
			throw BlobException(std::string("SDL could not initialize! SDL_Error: ") + SDL_GetError());

		window = SDL_CreateWindow("Hello World!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height,
								  SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

		if (window == nullptr)
			throw BlobException(std::string("Window could not be created! SDL_Error: ") + SDL_GetError());

		glContext = SDL_GL_CreateContext(window);

		if (glContext == nullptr)
			throw BlobException(std::string("OpenGL context could not be created! SDL Error: ") + SDL_GetError());

		if (!gladLoadGL()) throw BlobException("Can't load openGL");

		enableDebugCallBack();

		//test hardware
		std::cout << glGetString(GL_VENDOR) << std::endl <<
				  glGetString(GL_RENDERER) << std::endl <<
				  glGetString(GL_VERSION) << std::endl <<
				  glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;


		/*vboPoints = new VertexBufferObject<glm::vec3>(
				{
						glm::vec3(-1.f, 1.f, 1.f),     // Front-top-left
						glm::vec3(1.f, 1.f, 1.f),      // Front-top-right
						glm::vec3(-1.f, -1.f, 1.f),    // Front-bottom-left
						glm::vec3(1.f, -1.f, 1.f),     // Front-bottom-right

						glm::vec3(1.f, -1.f, -1.f),    // Back-bottom-right
						glm::vec3(1.f, 1.f, 1.f),      // Front-top-right
						glm::vec3(1.f, 1.f, -1.f),     // Back-top-right
						glm::vec3(-1.f, 1.f, 1.f),     // Front-top-left
						glm::vec3(-1.f, 1.f, -1.f),    // Back-top-left
						glm::vec3(-1.f, -1.f, 1.f),    // Front-bottom-left
						glm::vec3(-1.f, -1.f, -1.f),   // Back-bottom-left
						glm::vec3(1.f, -1.f, -1.f),    // Back-bottom-right
						glm::vec3(-1.f, 1.f, -1.f),    // Back-top-left
						glm::vec3(1.f, 1.f, -1.f)      // Back-top-right
				}
				);

		vboColor = new VertexBufferObject<Color>(
				{
						Color(255, 0, 0),
						Color(0, 255, 0),
						Color(0, 0, 255),
						Color(0, 0, 0),

						Color(255, 255, 255),
						Color(0, 255, 0),
						Color(0, 255, 255),
						Color(255, 0, 0),

						Color(255, 255, 0),
						Color(0, 0, 255),
						Color(255, 0, 255),
						Color(255, 255, 255),

						Color(255, 255, 0),
						Color(0, 255, 255)
				}
				);
		*/

		glEnable(GL_CULL_FACE); // cull face
		glCullFace(GL_BACK);// cull back face
		glFrontFace(GL_CW);// GL_CCW for counter clock-wise
		glClearColor(0.2, 0.2, 0.2, 1.0);

		projectionMatrix = glm::perspective(glm::radians(45.0f), width / (GLfloat) height, 0.1f, 100.0f);
		viewMatrix = glm::lookAt(cameraPosition, cameraLookAt, cameraUp);
	}

	Graphic::~Graphic() {
		//Destroy window
		SDL_DestroyWindow(window);

		//Quit SDL subsystems
		SDL_Quit();
	}

	void Graphic::clear() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Graphic::display() {
		SDL_GL_SwapWindow(window);

		while (SDL_PollEvent(&sdlEvent) != 0) {

			if (sdlEvent.type == SDL_QUIT) {
				quit = true;
			}
		}
	}

	void Graphic::resize(unsigned int w, unsigned int h) {
		height = h;
		width = w;

		projectionMatrix = glm::perspective(glm::radians(45.0f), width / (GLfloat) height, 0.1f, 100.0f);
	}

	void Graphic::draw(Shape &shape) {

		glUseProgram(shape.shaderProgram.getProgram());
		glBindVertexArray(shape.vao.getVertexArrayObject());

		glm::mat4 mvp = projectionMatrix * viewMatrix * shape.getModelMatrix();

		glUniformMatrix4fv(shape.mvpLocation, 1, GL_FALSE, glm::value_ptr(mvp));

		glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(shape.points.size()));

	}

	bool Graphic::isOpen() const {
		return !quit;
	}
}
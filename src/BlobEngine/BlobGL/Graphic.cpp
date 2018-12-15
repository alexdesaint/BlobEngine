

//blobEngine
#include <BlobEngine/BlobException.hpp>
#include <BlobEngine/BlobGL/Shape.hpp>
#include <BlobEngine/BlobGL/Graphic.hpp>

//std
#include <iostream>
#include <chrono>

// opengl
#include <glad/glad.h>

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

	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,
							 "Missing file",
							 "File is missing. Please reinstall the program.",
							 nullptr);
}

namespace BlobEngine::BlobGL {

	//using namespace BlobGL;

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
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 4);
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

		if (SDL_GL_SetSwapInterval(-1) == -1)
			SDL_GL_SetSwapInterval(1);

		glEnable(GL_CULL_FACE); // cull face
		glCullFace(GL_FRONT);// cull back face
		glFrontFace(GL_CW);// GL_CCW for counter clock-wise
		glEnable( GL_DEPTH_TEST );
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

		if (!(++frameCount % 60)) {
			static std::chrono::high_resolution_clock::time_point lastFrameTime;
			auto now = std::chrono::high_resolution_clock::now();
			std::chrono::duration<float> diff = now - lastFrameTime;
			lastFrameTime = now;

			std::string name = "Test : " + std::to_string(60 / diff.count()) + " FPS";

			SDL_SetWindowTitle(window, name.c_str());
		}

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

	void Graphic::draw(const ShaderProgram &program, const VertexArrayObject &vao) {

		glUseProgram(program.getProgram());
		glBindVertexArray(vao.getVertexArrayObject());

		glm::mat4 mvp = projectionMatrix * viewMatrix;// * shape.getModelMatrix();

		GLint mvpLocation = glGetUniformLocation(program.getProgram(), "mvp");//TODO : ajouter au shaderProgram

		glUniformMatrix4fv(mvpLocation, 1, GL_FALSE, glm::value_ptr(glm::mat4(1)));

		glDrawArrays(GL_TRIANGLES, 0, 3);
	}

	void Graphic::draw(const Shape &shape, const ShaderProgram &program) {
		glUseProgram(program.getProgram());
		glBindVertexArray(shape.vao.getVertexArrayObject());

		glm::mat4 mvp = projectionMatrix * viewMatrix * shape.getModelMatrix();

		GLint mvpLocation = glGetUniformLocation(program.getProgram(), "mvp");//TODO : ajouter au shaderProgram

		glUniformMatrix4fv(mvpLocation, 1, GL_FALSE, glm::value_ptr(mvp));

		if (shape.indexed)
			glDrawElements(GL_TRIANGLES, shape.numOfIndices, shape.indicesType, shape.indices);
		else
			glDrawArrays(GL_TRIANGLES, 0, shape.vao.getNumberOfElements());
	}

	bool Graphic::isOpen() const {
		return !quit;
	}

	std::ostream &operator<<(std::ostream &s, const Graphic &a) {
		s << glGetString(GL_VENDOR) << std::endl <<
		  glGetString(GL_RENDERER) << std::endl <<
		  glGetString(GL_VERSION) << std::endl <<
		  glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
		return s;
	}
}
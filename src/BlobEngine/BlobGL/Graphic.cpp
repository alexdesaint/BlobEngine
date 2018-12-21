//blobEngine
#include <BlobEngine/BlobException.hpp>
#include <BlobEngine/BlobGL/Renderable.hpp>
#include <BlobEngine/BlobGL/Graphic.hpp>

//std
#include <iostream>
#include <chrono>

// SFML
#include <SFML/Window.hpp>
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
			cameraPosition(0, 0, 2),
			cameraLookAt(0, 0, 0),
			cameraUp(0, 0, 1) {

		sf::ContextSettings settings;
		settings.attributeFlags = sf::ContextSettings::Core;
		settings.depthBits = 24;
		settings.stencilBits = 8;
		settings.antialiasingLevel = 4;
		settings.majorVersion = 4;
		settings.minorVersion = 5;

		window = new sf::Window(sf::VideoMode(800, 600), "OpenGL", sf::Style::Default, settings);
		((sf::Window*)window)->setVerticalSyncEnabled(true);

		((sf::Window*)window)->setActive(true);

		if (!gladLoadGL()) throw BlobException("Can't load openGL");


		enableDebugCallBack();

		glEnable(GL_CULL_FACE); // cull face
		glCullFace(GL_FRONT);// cull back face
		glFrontFace(GL_CW);// GL_CCW for counter clock-wise
		glEnable( GL_DEPTH_TEST );
		glClearColor(0.2, 0.2, 0.2, 1.0);

		projectionMatrix = glm::perspective(glm::radians(45.0f), width / (GLfloat) height, 0.1f, 100.0f);
		viewMatrix = glm::lookAt(cameraPosition, cameraLookAt, cameraUp);
	}

	Graphic::~Graphic() {
		delete ((sf::Window*)window);
	}

	void Graphic::clear() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	}

	void Graphic::display() {
		((sf::Window*)window)->display();

		if (!(++frameCount % 60)) {
			static std::chrono::high_resolution_clock::time_point lastFrameTime;
			auto now = std::chrono::high_resolution_clock::now();
			std::chrono::duration<float> diff = now - lastFrameTime;
			lastFrameTime = now;

			std::string name = "Test : " + std::to_string(60 / diff.count()) + " FPS";

			((sf::Window*)window)->setTitle(name);
		}

		sf::Event event{};
		while (((sf::Window*)window)->pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				// end the program
				quit = true;
			}
			else if (event.type == sf::Event::Resized) {
				// adjust the viewport when the window is resized
				glViewport(0, 0, event.size.width, event.size.height);
			}
		}
	}

	void Graphic::resize(unsigned int w, unsigned int h) {
		height = h;
		width = w;

		projectionMatrix = glm::perspective(glm::radians(45.0f), width / (GLfloat) height, 0.1f, 100.0f);
	}

	std::ostream &operator<< (std::ostream &out, const glm::mat4 &vec) {

		for(int i = 0; i < 4; i++)
			out << vec[i].x << " " << vec[i].y << " "<< vec[i].z << " " << vec[i].w << std::endl;
		return out;
	}

	void Graphic::draw(const Renderable &renderable, const ShaderProgram &program, glm::mat4 shapeModel) {
		glUseProgram(program.getProgram());
		glBindVertexArray(renderable.vao.getVertexArrayObject());

		glUniformMatrix4fv(program.projection, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
		glUniformMatrix4fv(program.view, 1, GL_FALSE, glm::value_ptr(viewMatrix));
		glUniformMatrix4fv(program.model, 1, GL_FALSE, glm::value_ptr(shapeModel * renderable.getModelMatrix()));
		if(renderable.texture != nullptr)
			glBindTexture(GL_TEXTURE_2D, renderable.texture->texture);
			//glBindImageTexture(0, renderable.texture->texture, 0, GL_FALSE, 0,  GL_READ_ONLY, GL_RGB8);

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
		for(auto r : shape.renderables)
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
		for(auto r : scene.shapes)
			draw(*r, program, modelMatrix);
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

	void Graphic::setCameraPosition(float x, float y, float z) {
		cameraPosition = glm::vec3(x, y, z);

		viewMatrix = glm::lookAt(cameraPosition, cameraLookAt, cameraUp);
	}
}
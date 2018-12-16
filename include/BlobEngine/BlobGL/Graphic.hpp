#ifndef BLOBENGINE_GRAPHIC_HPP
#define BLOBENGINE_GRAPHIC_HPP

#include <BlobEngine/BlobGL/ShaderProgram.hpp>
#include <BlobEngine/BlobGL/VertexArrayObject.hpp>
#include <BlobEngine/BlobGL/Shape.hpp>

#include <SDL2/SDL.h>

#include <glm/mat4x4.hpp>

#include <ostream>

namespace BlobEngine::BlobGL {

	class Graphic {
	private:

		bool quit = false;
		unsigned int frameCount = 0;

		SDL_Window *window;
		SDL_GLContext glContext;
		SDL_Event sdlEvent;

		unsigned int width, height;

		glm::mat4 projectionMatrix;
		glm::mat4 viewMatrix{1};

		glm::vec3 cameraPosition; // Camera position in World Space
		glm::vec3 cameraLookAt; // and looks at the origin
		glm::vec3 cameraUp;  // Head is up (set to 0,-1,0 to look upside-down)

		void enableDebugCallBack();

	public:
		Graphic(unsigned int width, unsigned int height);

		~Graphic();

		void clear();

		void display();

		void resize(unsigned int w, unsigned int h);

		void draw(const Renderable &shape, const ShaderProgram &program, glm::mat4 shapeModel = glm::mat4(1.0));

		void draw(const Shape &shape, const ShaderProgram &program);

		bool isOpen() const;

		friend std::ostream& operator<<(std::ostream &s, const Graphic &a);

		void setCameraPosition(float x, float y, float z);
	};
}

#endif //BLOBENGINE_GRAPHIC_HPP
#ifndef BLOBENGINE_GLSCENE_HPP
#define BLOBENGINE_GLSCENE_HPP

#include <BlobEngine/BlobGL/Shape.hpp>

namespace BlobEngine::BlobGL {

	class Graphic;

	class Scene {
		friend Graphic;
	private:
		glm::mat4 translateMatrix = glm::mat4(1.f);
		glm::mat4 rotateMatrix = glm::mat4(1.f);
		glm::mat4 scaleMatrix = glm::mat4(1.f);

		std::list<Shape*> shapes;

	protected:

		void addRenderable(Shape *r);

		size_t getRenderableSize() const;

	public:
		glm::mat4 getModelMatrix() const;

		void setPosition(float x, float y, float z);

		void move(float x, float y, float z);

		void setRotation(float r, float x, float y, float z);

		void rotate(float r, float x, float y, float z);

		void setScale(float x, float y, float z);

		void rescale(float x, float y, float z);
	};
}

#endif //BLOBENGINE_SCENE_HPP

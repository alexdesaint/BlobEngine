#ifndef BLOBENGINE_MOVABLE_HPP
#define BLOBENGINE_MOVABLE_HPP

#include <glm/mat4x4.hpp>

namespace Blob::GL {

	class Graphic;

	class Movable {
	private:
		glm::mat4 translateMatrix = glm::mat4(1.f);
		glm::mat4 rotateMatrix = glm::mat4(1.f);
		glm::mat4 scaleMatrix = glm::mat4(1.f);

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

#endif //BLOBENGINE_MOVABLE_HPP

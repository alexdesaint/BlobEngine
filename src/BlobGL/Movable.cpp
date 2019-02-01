#include <BlobEngine/BlobGL/Movable.hpp>

#include <glm/ext/matrix_transform.inl>
#include <glm/detail/func_trigonometric.inl>

namespace Blob::GL {
	using namespace glm;

	mat4 Movable::getModelMatrix() const {
		return translateMatrix * rotateMatrix * scaleMatrix;
	}

	void Movable::setPosition(float x, float y, float z) {
		translateMatrix = translate(mat4(1.0f), vec3(x, y, z));
	}

	void Movable::move(float x, float y, float z) {
		translateMatrix = translate(translateMatrix, vec3(x, y, z));
	}

	void Movable::setRotation(float r, float x, float y, float z) {
		rotateMatrix = glm::rotate(mat4(1.0f), radians(r), vec3(x, y, z));
	}

	void Movable::rotate(float r, float x, float y, float z) {
		rotateMatrix = glm::rotate(rotateMatrix, radians(r), vec3(x, y, z));
	}

	void Movable::setScale(float x, float y, float z) {
		scaleMatrix = scale(mat4(1.0f), vec3(x, y, z));
	}

	void Movable::rescale(float x, float y, float z) {
		scaleMatrix = scale(scaleMatrix, vec3(x, y, z));
	}
}
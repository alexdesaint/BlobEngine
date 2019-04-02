#include <Blob/GL/Movable.hpp>

#include <glm/gtc/matrix_transform.hpp>

namespace Blob::GL {
	using namespace glm;

	mat4 Movable::getModelMatrix() const {
		return translateMatrix * rotateMatrix * scaleMatrix;
	}

	void Movable::setPosition(float x, float y, float z) {
		translateMatrix = translate(mat4(1.0f), vec3(x, y, z));
	}

    void Movable::setPosition(const Vec2f &xy, float z) {
        translateMatrix = translate(mat4(1.0f), vec3(xy.x, xy.y, z));
    }

	void Movable::move(float x, float y, float z) {
		translateMatrix = translate(translateMatrix, vec3(x, y, z));
	}

	void Movable::setRotation(float r, float x, float y, float z) {
		rotateMatrix = glm::rotate(mat4(1.0f), r, vec3(x, y, z));
	}

	void Movable::rotate(float r, float x, float y, float z) {
		rotateMatrix = glm::rotate(rotateMatrix, r, vec3(x, y, z));
	}

	void Movable::setScale(float xyz) {
		scaleMatrix = scale(mat4(1.0f), vec3(xyz, xyz, xyz));
	}

    void Movable::setScale(float x, float y, float z) {
        scaleMatrix = scale(mat4(1.0f), vec3(x, y, z));
    }

	void Movable::rescale(float xyz) {
		scaleMatrix = scale(scaleMatrix, vec3(xyz, xyz, xyz));
	}
}
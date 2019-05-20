#include <Blob/GL/Movable.hpp>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Blob::GL {
	using namespace glm;

	mat4 Movable::getModelMatrix() const {
        return modelMatrix;
    }

    void Movable::setModelMatrix(const std::array<float, 16> &mat) {
        modelMatrix = glm::make_mat4(mat.data());
    }

	void Movable::setPosition(float x, float y, float z) {
		translateMatrix = translate(mat4(1.0f), vec3(x, y, z));
        modelMatrix = translateMatrix * rotateMatrix * scaleMatrix;
	}

    void Movable::setPosition(const Vec2f &xy, float z) {
        translateMatrix = translate(mat4(1.0f), vec3(xy.x, xy.y, z));
        modelMatrix = translateMatrix * rotateMatrix * scaleMatrix;
    }

	void Movable::move(float x, float y, float z) {
		translateMatrix = translate(translateMatrix, vec3(x, y, z));
        modelMatrix = translateMatrix * rotateMatrix * scaleMatrix;
	}

	void Movable::setRotation(float r, float x, float y, float z) {
		rotateMatrix = glm::rotate(mat4(1.0f), r, vec3(x, y, z));
        modelMatrix = translateMatrix * rotateMatrix * scaleMatrix;
	}

	void Movable::rotate(float r, float x, float y, float z) {
		rotateMatrix = glm::rotate(rotateMatrix, r, vec3(x, y, z));
        modelMatrix = translateMatrix * rotateMatrix * scaleMatrix;
	}

	void Movable::setScale(float xyz) {
		scaleMatrix = scale(mat4(1.0f), vec3(xyz, xyz, xyz));
        modelMatrix = translateMatrix * rotateMatrix * scaleMatrix;
	}

    void Movable::setScale(float x, float y, float z) {
        scaleMatrix = scale(mat4(1.0f), vec3(x, y, z));
        modelMatrix = translateMatrix * rotateMatrix * scaleMatrix;
    }

	void Movable::rescale(float xyz) {
		scaleMatrix = scale(scaleMatrix, vec3(xyz, xyz, xyz));
        modelMatrix = translateMatrix * rotateMatrix * scaleMatrix;
    }

    void Movable::rescale(float x, float y, float z) {
        scaleMatrix = scale(scaleMatrix, vec3(x, y, z));
        modelMatrix = translateMatrix * rotateMatrix * scaleMatrix;
    }
}
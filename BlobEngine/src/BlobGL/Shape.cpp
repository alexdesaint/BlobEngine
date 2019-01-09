#include <BlobEngine/BlobGL/Shape.hpp>

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/ext/matrix_transform.hpp>

namespace BlobEngine::BlobGL {

	void Shape::addRenderable(Renderable *r) {
		renderables.emplace_back(r);
	}

	void Shape::removeRenderable(Renderable *r) {
		renderables.remove(r);
	}

	size_t Shape::getRenderableSize() const {
		return renderables.size();
	}

	using namespace glm;

	glm::mat4 Shape::getModelMatrix() const {
		return translateMatrix * rotateMatrix * scaleMatrix;
	}

	void Shape::setPosition(float x, float y, float z) {
		translateMatrix = translate(mat4(1.0f), vec3(x, y, z));
	}

	void Shape::move(float x, float y, float z) {
		translateMatrix = translate(translateMatrix, vec3(x, y, z));
	}

	void Shape::setRotation(float r, float x, float y, float z) {
		rotateMatrix = glm::rotate(mat4(1.0f), glm::radians(r), vec3(x, y, z));
	}

	void Shape::rotate(float r, float x, float y, float z) {
		rotateMatrix = glm::rotate(rotateMatrix, glm::radians(r), vec3(x, y, z));
	}

	void Shape::setScale(float x, float y, float z) {
		scaleMatrix = scale(mat4(1.0f), vec3(x, y, z));
	}

	void Shape::rescale(float x, float y, float z) {
		scaleMatrix = scale(scaleMatrix, vec3(x, y, z));
	}
}
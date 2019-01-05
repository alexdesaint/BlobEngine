#include <BlobEngine/BlobGL/Scene.hpp>

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/ext/matrix_transform.hpp>

namespace BlobEngine::BlobGL {

	void Scene::addRenderable(Shape *r) {
		shapes.emplace_back(r);
	}

	size_t Scene::getRenderableSize() const {
		return shapes.size();
	}

	using namespace glm;

	glm::mat4 Scene::getModelMatrix() const {
		return translateMatrix * rotateMatrix * scaleMatrix;
	}

	void Scene::setPosition(float x, float y, float z) {
		translateMatrix = translate(mat4(1.0f), vec3(x, y, z));
	}

	void Scene::move(float x, float y, float z) {
		translateMatrix = translate(translateMatrix, vec3(x, y, z));
	}

	void Scene::setRotation(float r, float x, float y, float z) {
		rotateMatrix = glm::rotate(mat4(1.0f), glm::radians(r), vec3(x, y, z));
	}

	void Scene::rotate(float r, float x, float y, float z) {
		rotateMatrix = glm::rotate(rotateMatrix, glm::radians(r), vec3(x, y, z));
	}

	void Scene::setScale(float x, float y, float z) {
		scaleMatrix = scale(mat4(1.0f), vec3(x, y, z));
	}

	void Scene::rescale(float x, float y, float z) {
		scaleMatrix = scale(scaleMatrix, vec3(x, y, z));
	}
}
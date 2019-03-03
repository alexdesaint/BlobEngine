#include <Blob/GL/Scene.hpp>

#include <glm/ext/matrix_transform.hpp>

namespace Blob::GL {

	void Scene::addShape(Shape &r) {
		shapes.emplace_back(&r);
	}

	void Scene::removeShape(Shape &r) {
		shapes.remove(&r);
	}
}
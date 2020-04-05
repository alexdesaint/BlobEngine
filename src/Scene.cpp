#include <Blob/Scene.hpp>

namespace Blob {

	void Scene::addShape(const Shape &r) {
		shapes.emplace_back(&r);
	}

	void Scene::removeShape(const Shape &r) {
		shapes.remove(&r);
	}
}
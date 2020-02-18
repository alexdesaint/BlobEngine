#include <Blob/Scene.hpp>

namespace Blob {

	void Scene::addShape(Shape &r) {
		shapes.emplace_back(&r);
	}

	void Scene::removeShape(Shape &r) {
		shapes.remove(&r);
	}
}
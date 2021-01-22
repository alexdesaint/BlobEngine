#include <Blob/Core/Scene.hpp>

namespace Blob::Core {

void Scene::addShape(const Shape &r) {
    shapes.emplace_back(&r);
}

void Scene::removeShape(const Shape &r) {
    shapes.remove(&r);
}
void Scene::removeAll() {
    shapes.clear();
}
} // namespace Blob::Core
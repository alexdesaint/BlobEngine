#include <Blob/Scene.hpp>
#include <iostream>

namespace Blob {
Scene::Scene(std::list<Shape const *> shapes) : shapes(std::move(shapes)) {}
Scene::Scene(const Camera &camera, std::list<Shape const *> shapes) :
    camera(camera), shapes(std::move(shapes)) {}

void Scene::addShape(const Shape &r) {
    shapes.emplace_back(&r);
}
void Scene::addShape(const Shape *r) {
    shapes.emplace_back(r);
}
void Scene::removeShape(const Shape &r) {
    shapes.remove(&r);
}
void Scene::removeShape(const Shape *r) {
    shapes.remove(r);
}
void Scene::removeAll() {
    shapes.clear();
}

std::ostream &operator<<(std::ostream &os, const Scene &s) {
    os << "Scene :" << std::endl;
    os << "  - num of shapes : " << s.shapes.size() << std::endl;
    for (const auto &shape : s.shapes)
        os << *shape << std::endl;
    return os;
}

} // namespace Blob
#include <Blob/Scene.hpp>
#include <cstddef>
#include <iostream>

namespace Blob {
Scene::Scene(std::vector<Shape const *> shapes) : shapes(std::move(shapes)) {}
Scene::Scene(const Camera &camera, std::vector<Shape const *> shapes) :
    camera(camera), shapes(std::move(shapes)) {}

void Scene::addShape(const Shape &r) {
    shapes.emplace_back(&r);
}
void Scene::addShape(const Shape *r) {
    shapes.emplace_back(r);
}
void Scene::removeShape(const Shape &r) {
    removeShape(&r);
}
void Scene::removeShape(const Shape *r) {
    auto it = std::find(shapes.begin(), shapes.end(), r);
    if (it == shapes.end())
        return;
    *it = shapes.back();
    shapes.pop_back();
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
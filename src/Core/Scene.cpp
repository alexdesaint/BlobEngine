#include <Blob/Core/Scene.hpp>
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
std::unordered_map<const GL::VertexArrayObject *,
                   std::pair<std::vector<Mat4>, std::deque<RenderOptions>>>
Scene::getDrawCallList() const {
    std::unordered_map<const GL::VertexArrayObject *,
                       std::pair<std::vector<Mat4>, std::deque<RenderOptions>>>
        list;
    for (auto shape : shapes)
        shape->getDrawCallList(list);
    return list;
}

std::ostream &operator<<(std::ostream &os, const Scene &s) {
    os << "Scene :" << std::endl;
    os << "  - num of shapes : " << s.shapes.size() << std::endl;
    for (const auto &shape : s.shapes)
        os << *shape << std::endl;
    return os;
}

Scene2D::Scene2D(const Blob::ViewTransform2D &camera) : camera(camera) {}
Scene2D::Scene2D(const Blob::ViewTransform2D &camera,
                 std::list<Shape2D const *> shapes) :
    camera(camera), shapes(std::move(shapes)) {}

void Scene2D::addShape(const Shape2D &r) {
    shapes.emplace_back(&r);
}
void Scene2D::addShape(const Shape2D *r) {
    shapes.emplace_back(r);
}
void Scene2D::removeShape(const Shape2D &r) {
    shapes.remove(&r);
}
void Scene2D::removeShape(const Shape2D *r) {
    shapes.remove(r);
}
void Scene2D::removeAll() {
    shapes.clear();
}

std::ostream &operator<<(std::ostream &os, const Scene2D &s) {
    os << "Scene :" << std::endl;
    os << "  - num of shapes : " << s.shapes.size() << std::endl;
    return os;
}

} // namespace Blob
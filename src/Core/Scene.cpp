#include <Blob/Core/Scene.hpp>

namespace Blob::Core {
Scene::Scene(std::list<Shape const *> shapes) : shapes(std::move(shapes)) {}
Scene::Scene(const Camera &camera, std::list<Shape const *> shapes) : camera(camera), shapes(std::move(shapes)) {}

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

Scene2D::Scene2D(const Blob::Maths::ViewTransform2D &camera) : camera(camera) {}
Scene2D::Scene2D(const Blob::Maths::ViewTransform2D &camera, std::list<Shape2D const *> shapes) : camera(camera), shapes(std::move(shapes)) {}

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

} // namespace Blob::Core
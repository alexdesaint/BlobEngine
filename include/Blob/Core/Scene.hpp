#pragma once

#include <Blob/Core/Camera.hpp>
#include <Blob/Core/Shape.hpp>
#include <utility>

namespace Blob::Core {

class Scene {
    friend Window;

private:
    std::list<Shape const *> shapes;

public:
    Camera camera;
    Scene() = default;

    explicit Scene(std::list<Shape const *> shapes) : shapes(std::move(shapes)) {}

    void addShape(const Shape &r) { shapes.emplace_back(&r); }
    void removeShape(const Shape &r) { shapes.remove(&r); }
    void removeAll() { shapes.clear(); }
};
class Scene2D {
    friend Window;

private:
    std::list<Shape2D const *> shapes;

public:
    const Blob::Maths::ViewTransform2D &camera;
    explicit Scene2D(const Blob::Maths::ViewTransform2D &camera) : camera(camera) {}

    Scene2D(const Blob::Maths::ViewTransform2D &camera, std::list<Shape2D const *> shapes) : camera(camera), shapes(std::move(shapes)) {}

    void addShape(const Shape2D &r) { shapes.emplace_back(&r); }
    void addShape(const Shape2D *r) { shapes.emplace_back(r); }
    void removeShape(const Shape2D &r) { shapes.remove(&r); }
    void removeShape(const Shape2D *r) { shapes.remove(r); }
    void removeAll() { shapes.clear(); }
};
} // namespace Blob::Core

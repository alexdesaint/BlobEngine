#pragma once

#include <Blob/Core/Camera.hpp>
#include <Blob/Core/Shape.hpp>
#include <utility>

namespace Blob::Core {

class Scene {
    friend Window;

private:
    std::list<Shape const *> shapes;
    Camera camera;

public:
    Scene() = default;

    explicit Scene(std::list<Shape const *> shapes) : shapes(std::move(shapes)) {}

    void addShape(const Shape &r);

    void removeShape(const Shape &r);

    void removeAll();
};
} // namespace Blob::Core

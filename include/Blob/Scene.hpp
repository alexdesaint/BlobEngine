#pragma once

#include <Blob/Camera.hpp>
#include <Blob/Shape.hpp>

namespace Blob::Core {

class Scene {
    friend Window;
private:
    std::list<Shape const *> shapes;
    Camera camera;

public:
    void addShape(const Shape &r);

    void removeShape(const Shape &r);
};
} // namespace Blob

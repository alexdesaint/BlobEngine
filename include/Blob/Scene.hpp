#pragma once

#include <Blob/Camera.hpp>
#include <Blob/RenderOptions.hpp>
#include <Blob/Shape.hpp>
#include <ostream>
#include <utility>

namespace Blob {

class Scene {
    friend class Window;

private:
    std::list<Shape const *> shapes;

public:
    Camera camera;
    Scene() = default;

    explicit Scene(std::list<Shape const *> shapes);
    Scene(const Camera &camera, std::list<Shape const *> shapes);

    void addShape(const Shape &r);
    void addShape(const Shape *r);
    void removeShape(const Shape &r);
    void removeShape(const Shape *r);
    void removeAll();

    friend std::ostream &operator<<(std::ostream &, const Scene &);
};

} // namespace Blob

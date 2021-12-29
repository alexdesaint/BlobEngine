#pragma once

#include "Blob/Core/RenderOptions.hpp"
#include <Blob/Core/Camera.hpp>
#include <Blob/Core/Shape.hpp>
#include <ostream>
#include <utility>

namespace Blob {

class Scene {
    friend Window;

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

    std::unordered_map<const GL::VertexArrayObject *,
                       std::pair<std::vector<Mat4>, std::deque<RenderOptions>>>
    getDrawCallList() const;

    friend std::ostream &operator<<(std::ostream &, const Scene &);
};

class Scene2D {
    friend Window;

private:
    std::list<Shape2D const *> shapes;

public:
    const ViewTransform2D &camera;
    explicit Scene2D(const ViewTransform2D &camera);

    Scene2D(const ViewTransform2D &camera, std::list<Shape2D const *> shapes);

    void addShape(const Shape2D &r);
    void addShape(const Shape2D *r);
    void removeShape(const Shape2D &r);
    void removeShape(const Shape2D *r);
    void removeAll();

    friend std::ostream &operator<<(std::ostream &, const Scene2D &);
};
} // namespace Blob

#pragma once

#include <Blob/Mesh.hpp>

namespace Blob {

class Shape : public ModelTransform {
    friend class Window;

private:
    const Mesh *mesh = nullptr;
    std::list<const Shape *> shapes;

public:
    Shape() = default;
    Shape(const Shape &) = delete;
    Shape(Shape &&) = delete;
    explicit Shape(const ModelTransform &args);
    explicit Shape(const Mesh &r);
    Shape(const Mesh &r, const ModelTransform &args);

    void setMesh(Mesh &r);
    void setMesh(Mesh *r);

    void removeMesh();

    void addChild(Shape *r);
    void addChild(Shape &r);

    void removeChild(Shape &r);
    void removeChild(Shape *r);

    friend std::ostream &operator<<(std::ostream &s, const Shape &a);
};

} // namespace Blob

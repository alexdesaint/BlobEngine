#include <Blob/Shape.hpp>
#include <algorithm>

namespace Blob {

Shape::Shape(Mesh &r, float LocationX, float LocationY, float LocationZ, float ScaleX, float ScaleY, float ScaleZ, float RotationX, float RotationY,
             float RotationZ) {
    mesh = &r;
    setPosition(LocationX, LocationY, LocationZ);
    setScale(ScaleX, ScaleY, ScaleZ);
    setRotation(RotationX, 1, 0, 0);
    setRotation(RotationY, 0, 1, 0);
    setRotation(RotationZ, 0, 0, 1);
}

Shape::Shape(float LocationX, float LocationY, float LocationZ, float ScaleX, float ScaleY, float ScaleZ, float RotationX, float RotationY,
             float RotationZ) {
    setPosition(LocationX, LocationY, LocationZ);
    setScale(ScaleX, ScaleY, ScaleZ);
    setRotation(RotationX, 1, 0, 0);
    setRotation(RotationY, 0, 1, 0);
    setRotation(RotationZ, 0, 0, 1);
}

void Shape::setMesh(Mesh &r) {
    mesh = &r;
}

void Shape::setMesh(Mesh *r) {
    mesh = r;
}

void Shape::setChild(Shape *r) {
    shapes.emplace_back(r);
    r->parent = this;
}

void Shape::setChild(Shape &r) {
    shapes.emplace_back(&r);
    r.parent = this;
}

void Shape::removeMesh() {
    mesh = nullptr;
}

void Shape::removeChild(Shape &r) {
    auto it = std::find(shapes.begin(), shapes.end(), &r);
    if (it != shapes.end()) {
        r.parent = nullptr;
        shapes.erase(it);
    }
}

void Shape::removeChild(Shape *r) {
    auto it = std::find(shapes.begin(), shapes.end(), r);
    if (it != shapes.end()) {
        r->parent = nullptr;
        shapes.erase(it);
    }
}

std::ostream &operator<<(std::ostream &s, const Shape &a) {
    s << "Shape : {" << std::endl;

    s << a.mesh << std::endl;

    for (const auto &r : a.shapes)
        s << *r;

    s << "}" << std::endl;
    return s;
}
} // namespace Blob
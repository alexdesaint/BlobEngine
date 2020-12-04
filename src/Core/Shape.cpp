#include <Blob/Core/Shape.hpp>
#include <algorithm>

namespace Blob::Core {

Shape::Shape(Mesh &r) {
    mesh = &r;
}

Shape::Shape(Mesh &r, const Maths::Vec3<float> &location) {
    mesh = &r;
    setPosition(location);
}

Shape::Shape(const Maths::Vec3<float> &location) {
    setPosition(location);
}

Shape::Shape(Mesh &r, const Maths::Vec2<float> &location) {
    mesh = &r;
    setPosition(location);
}

Shape::Shape(const Maths::Vec2<float> &location) {
    setPosition(location);
}

Shape::Shape(Mesh &r, const Maths::Vec3<float> &location, const Maths::Vec3<float> &scale) {
    mesh = &r;
    setPosition(location);
    setScale(scale);
}

Shape::Shape(Mesh &r, const Maths::Vec2<float> &location, const Maths::Vec2<float> &scale) {
    mesh = &r;
    setPosition(location);
    setScale(scale);
}

Shape::Shape(const Maths::Vec3<float> &location, const Maths::Vec3<float> &scale) {
    setPosition(location);
    setScale(scale);
}

Shape::Shape(const Maths::Vec2<float> &location, const Maths::Vec2<float> &scale) {
    setPosition(location);
    setScale(scale);
}

Shape::Shape(Mesh &r, const Maths::Vec3<float> &location, const Maths::Vec3<float> &scale, const Maths::Vec3<float> &rotation) {
    mesh = &r;
    setPosition(location);
    setScale(scale);
    setRotation(rotation.x, {1, 0, 0});
    setRotation(rotation.y, {0, 1, 0});
    setRotation(rotation.z, {0, 0, 1});
}

Shape::Shape(Mesh &r, const Maths::Mat4 &mat) : mesh(&r), Maths::ModelTransform(mat) {}

Shape::Shape(const Maths::Vec3<float> &location, const Maths::Vec3<float> &scale, const Maths::Vec3<float> &rotation) {
    setPosition(location);
    setScale(scale);
    setRotation(rotation.x, {1, 0, 0});
    setRotation(rotation.y, {0, 1, 0});
    setRotation(rotation.z, {0, 0, 1});
}

Shape::Shape(const Maths::Mat4 &mat) : Maths::ModelTransform(mat) {}

void Shape::setMesh(Mesh &r) {
    mesh = &r;
}

void Shape::setMesh(Mesh *r) {
    mesh = r;
}

void Shape::addChild(Shape *r) {
    shapes.emplace_back(r);
    //r->parent = this;
}

void Shape::addChild(Shape &r) {
    shapes.emplace_back(&r);
    //r.parent = this;
}

void Shape::removeMesh() {
    mesh = nullptr;
}

void Shape::removeChild(Shape &r) {
    auto it = std::find(shapes.begin(), shapes.end(), &r);
    if (it != shapes.end()) {
        //r.parent = nullptr;
        shapes.erase(it);
    }
}

void Shape::removeChild(Shape *r) {
    auto it = std::find(shapes.begin(), shapes.end(), r);
    if (it != shapes.end()) {
        //r->parent = nullptr;
        shapes.erase(it);
    }
}

std::ostream &operator<<(std::ostream &s, const Shape &a) {
    s << "Shape : {" << std::endl;

    s << (Maths::ModelTransform) a << std::endl;

    s << a.mesh << std::endl;

    for (const auto &r : a.shapes)
        s << *r;

    s << "}" << std::endl;
    return s;
}
} // namespace Blob::Core

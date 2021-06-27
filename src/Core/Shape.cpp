#include "Blob/Core/Primitive.hpp"
#include <Blob/Core/Shape.hpp>
#include <algorithm>

namespace Blob::Core {
Shape::Shape(const Maths::ModelTransform &args) : Maths::ModelTransform(args) {}

Shape::Shape(const Mesh &r) : mesh(&r) {}

Shape::Shape(const Mesh &r, const Maths::ModelTransform &args) : mesh(&r), Maths::ModelTransform(args) {}

void Shape::setMesh(Mesh &r) {
    mesh = &r;
}
void Shape::setMesh(Mesh *r) {
    mesh = r;
}
void Shape::removeMesh() {
    mesh = nullptr;
}

void Shape::addChild(Shape *r) {
    shapes.emplace_back(r);
}

void Shape::addChild(Shape &r) {
    shapes.emplace_back(&r);
}

void Shape::removeChild(Shape &r) {
    auto it = std::find(shapes.begin(), shapes.end(), &r);
    if (it != shapes.end())
        shapes.erase(it);
}

void Shape::removeChild(Shape *r) {
    auto it = std::find(shapes.begin(), shapes.end(), r);
    if (it != shapes.end())
        shapes.erase(it);
}

void Shape::getDrawCallList(std::unordered_map<const Primitive *, std::vector<Maths::Mat4>> &drawCallList, Maths::Mat4 transform) const {
    Maths::Mat4 modelMatrix = *this * transform;
    for (auto shape : shapes)
        shape->getDrawCallList(drawCallList, modelMatrix);

    if (mesh != nullptr)
        mesh->getDrawCallList(drawCallList, modelMatrix);
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

Shape2D::Shape2D(const Maths::ModelTransform2D &args) : Maths::ModelTransform2D(args) {}

Shape2D::Shape2D(const Mesh2D &r) : mesh(&r) {}

Shape2D::Shape2D(const Mesh2D &r, const Maths::ModelTransform2D &args) : mesh(&r), Maths::ModelTransform2D(args) {}

void Shape2D::setMesh(Mesh2D &r) {
    mesh = &r;
}
void Shape2D::setMesh(Mesh2D *r) {
    mesh = r;
}
void Shape2D::removeMesh() {
    mesh = nullptr;
}

void Shape2D::addChild(Shape2D *r) {
    shapes.emplace_back(r);
}

void Shape2D::addChild(Shape2D &r) {
    shapes.emplace_back(&r);
}

void Shape2D::removeChild(Shape2D &r) {
    auto it = std::find(shapes.begin(), shapes.end(), &r);
    if (it != shapes.end())
        shapes.erase(it);
}

void Shape2D::removeChild(Shape2D *r) {
    auto it = std::find(shapes.begin(), shapes.end(), r);
    if (it != shapes.end())
        shapes.erase(it);
}

std::ostream &operator<<(std::ostream &s, const Shape2D &a) {
    s << "Shape2D : {" << std::endl;

    s << (Maths::ModelTransform2D) a << std::endl;

    s << a.mesh << std::endl;

    for (const auto &r : a.shapes)
        s << *r;

    s << "}" << std::endl;
    return s;
}
} // namespace Blob::Core

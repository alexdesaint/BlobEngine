#include "Blob/Core/Primitive.hpp"
#include <Blob/Core/Shape.hpp>
#include <algorithm>

namespace Blob {
Shape::Shape(const ModelTransform &args) : ModelTransform(args) {}

Shape::Shape(const Mesh &r) : mesh(&r) {}

Shape::Shape(const Mesh &r, const ModelTransform &args) :
    mesh(&r), ModelTransform(args) {}

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

void Shape::getDrawCallList(
    std::unordered_map<const GL::VertexArrayObject *,
                       std::pair<std::vector<Mat4>, std::deque<RenderOptions>>>
        &drawCallList,
    Mat4 transform) const {
    Mat4 modelMatrix = transform * *this;
    for (auto shape : shapes)
        shape->getDrawCallList(drawCallList, modelMatrix);

    if (mesh != nullptr)
        mesh->getDrawCallList(drawCallList, modelMatrix);
}

void Shape::addToDynamicDrawCallList(DynamicDrawCallList &dynamicDrawCallList,
                                     Mat4 transform,
                                     void *id) const {
    Mat4 modelMatrix = transform * *this;
    if (id == nullptr)
        id = (void *) this;
    for (auto shape : shapes)
        shape->addToDynamicDrawCallList(dynamicDrawCallList, modelMatrix, id);

    if (mesh != nullptr)
        mesh->addToDynamicDrawCallList(dynamicDrawCallList, modelMatrix, id);
}

void Shape::removeFromDynamicDrawCallList(
    DynamicDrawCallList &dynamicDrawCallList,
    void *id) const {
    if (id == nullptr)
        id = (void *) this;
    for (auto shape : shapes)
        shape->removeFromDynamicDrawCallList(dynamicDrawCallList, id);

    if (mesh != nullptr)
        mesh->removeFromDynamicDrawCallList(dynamicDrawCallList, id);
}

std::ostream &operator<<(std::ostream &s, const Shape &a) {
    s << "Shape : {" << std::endl;

    s << (ModelTransform) a;

    if (a.mesh != nullptr)
        s << *a.mesh << std::endl;

    // for (const auto &r : a.shapes)
    //    s << *r;

    s << "}";
    return s;
}

Shape2D::Shape2D(const ModelTransform2D &args) : ModelTransform2D(args) {}

Shape2D::Shape2D(const Mesh2D &r) : mesh(&r) {}

Shape2D::Shape2D(const Mesh2D &r, const ModelTransform2D &args) :
    mesh(&r), ModelTransform2D(args) {}

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

    s << (ModelTransform2D) a << std::endl;

    s << a.mesh << std::endl;

    for (const auto &r : a.shapes)
        s << *r;

    s << "}" << std::endl;
    return s;
}
} // namespace Blob

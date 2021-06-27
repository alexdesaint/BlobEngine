#include <Blob/Core/Mesh.hpp>
#include <algorithm>

namespace Blob::Core {

Mesh::Mesh(const Primitive &r) {
    addPrimitive(r);
}

void Mesh::addPrimitive(const Primitive &r) {
    primitives.emplace_back(&r);
}

void Mesh::addPrimitive(const Primitive *r) {
    primitives.emplace_back(r);
}

void Mesh::removePrimitive(const Primitive &r) {
    auto it = std::find(primitives.begin(), primitives.end(), &r);
    if (it != primitives.end()) {
        primitives.erase(it);
    }
}

void Mesh::removePrimitive(const Primitive *r) {
    auto it = std::find(primitives.begin(), primitives.end(), r);
    if (it != primitives.end()) {
        primitives.erase(it);
    }
}

void Mesh::addTransparentPrimitive(const Primitive &r) {
    transparentPrimitives.emplace_back(&r);
}

void Mesh::addTransparentPrimitive(const Primitive *r) {
    transparentPrimitives.emplace_back(r);
}

void Mesh::removeTransparentPrimitive(const Primitive &r) {
    auto it = std::find(transparentPrimitives.begin(), transparentPrimitives.end(), &r);
    if (it != transparentPrimitives.end()) {
        transparentPrimitives.erase(it);
    }
}

void Mesh::removeTransparentPrimitive(const Primitive *r) {
    auto it = std::find(transparentPrimitives.begin(), transparentPrimitives.end(), r);
    if (it != transparentPrimitives.end()) {
        transparentPrimitives.erase(it);
    }
}

void Mesh::getDrawCallList(std::unordered_map<const Primitive *, std::vector<Maths::Mat4>> &drawCallList, Maths::Mat4 transform) const{
    for (auto primitive : primitives)
        drawCallList[primitive].emplace_back(transform);
}

void Mesh2D ::addPrimitive(const Primitive2D &r) {
    primitives.emplace_back(&r);
}

void Mesh2D ::addPrimitive(const Primitive2D *r) {
    primitives.emplace_back(r);
}

void Mesh2D ::removePrimitive(const Primitive2D &r) {
    auto it = std::find(primitives.begin(), primitives.end(), &r);
    if (it != primitives.end()) {
        primitives.erase(it);
    }
}

void Mesh2D ::removePrimitive(const Primitive2D *r) {
    auto it = std::find(primitives.begin(), primitives.end(), r);
    if (it != primitives.end()) {
        primitives.erase(it);
    }
}

void Mesh2D ::addTransparentPrimitive(const Primitive2D &r) {
    transparentPrimitives.emplace_back(&r);
}

void Mesh2D ::addTransparentPrimitive(const Primitive2D *r) {
    transparentPrimitives.emplace_back(r);
}

void Mesh2D ::removeTransparentPrimitive(const Primitive2D &r) {
    auto it = std::find(transparentPrimitives.begin(), transparentPrimitives.end(), &r);
    if (it != transparentPrimitives.end()) {
        transparentPrimitives.erase(it);
    }
}

void Mesh2D ::removeTransparentPrimitive(const Primitive2D *r) {
    auto it = std::find(transparentPrimitives.begin(), transparentPrimitives.end(), r);
    if (it != transparentPrimitives.end()) {
        transparentPrimitives.erase(it);
    }
}
Mesh2D ::Mesh2D(const Primitive2D &r) {
    addPrimitive(r);
}

} // namespace Blob::Core

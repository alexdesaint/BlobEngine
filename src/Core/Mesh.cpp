#include <Blob/Core/Mesh.hpp>
#include <algorithm>

namespace Blob::Core {

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
Mesh::Mesh(const Primitive &r) {
    addPrimitive(r);
}

} // namespace Blob::Core

#include <Blob/Mesh.hpp>
#include <algorithm>

namespace Blob {

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

void Mesh::removeAllPrimitive() {
    primitives.clear();
}

void Mesh::addTransparentPrimitive(const Primitive &r) {
    transparentPrimitives.emplace_back(&r);
}

void Mesh::addTransparentPrimitive(const Primitive *r) {
    transparentPrimitives.emplace_back(r);
}

void Mesh::removeTransparentPrimitive(const Primitive &r) {
    auto it = std::find(transparentPrimitives.begin(),
                        transparentPrimitives.end(),
                        &r);
    if (it != transparentPrimitives.end()) {
        transparentPrimitives.erase(it);
    }
}

void Mesh::removeTransparentPrimitive(const Primitive *r) {
    auto it = std::find(transparentPrimitives.begin(),
                        transparentPrimitives.end(),
                        r);
    if (it != transparentPrimitives.end()) {
        transparentPrimitives.erase(it);
    }
}

std::ostream &operator<<(std::ostream &s, const Mesh &a) {
    s << "Mesh {" << std::endl;
    s << "    primitive size" << a.primitives.size() << std::endl;
    s << "    transparent primitives size" << a.transparentPrimitives.size()
      << std::endl;
    s << "}";
    return s;
}

} // namespace Blob

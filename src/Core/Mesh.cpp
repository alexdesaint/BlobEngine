#include <Blob/Core/Mesh.hpp>
#include <algorithm>

namespace Blob::Core {

void Mesh::addPrimitive(Primitive &r) {
    primitives.emplace_back(&r);
}

void Mesh::addPrimitive(Primitive *r) {
    primitives.emplace_back(r);
}

void Mesh::removePrimitive(Primitive &r) {
    auto it = std::find(primitives.begin(), primitives.end(), &r);
    if (it != primitives.end()) {
        primitives.erase(it);
    }
}

void Mesh::removePrimitive(Primitive *r) {
    auto it = std::find(primitives.begin(), primitives.end(), r);
    if (it != primitives.end()) {
        primitives.erase(it);
    }
}

} // namespace Blob::Core

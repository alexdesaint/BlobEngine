#include <Blob/VertexLayout.hpp>

namespace Blob {

VertexLayout &VertexLayout::add(Type type,
                                size_t outPosition,
                                size_t numValuePerArray,
                                bool normalized) {
    switch (type) {
    case Float:
        vertexLayout.add((bgfx::Attrib::Enum) outPosition,
                         numValuePerArray,
                         bgfx::AttribType::Float,
                         normalized);
        break;
    case Uint8:
        vertexLayout.add((bgfx::Attrib::Enum) outPosition,
                         numValuePerArray,
                         bgfx::AttribType::Uint8,
                         normalized);
        break;
    case Int16:
        vertexLayout.add((bgfx::Attrib::Enum) outPosition,
                         numValuePerArray,
                         bgfx::AttribType::Int16,
                         normalized);
        break;
    }
    return *this;
}

template<>
VertexLayout &VertexLayout::add<float>(size_t outPosition,
                                       size_t numValuePerArray,
                                       bool normalized) {
    vertexLayout.add((bgfx::Attrib::Enum) outPosition,
                     numValuePerArray,
                     bgfx::AttribType::Float,
                     normalized);
    return *this;
}

template<>
VertexLayout &VertexLayout::add<uint8_t>(size_t outPosition,
                                         size_t numValuePerArray,
                                         bool normalized) {
    vertexLayout.add((bgfx::Attrib::Enum) outPosition,
                     numValuePerArray,
                     bgfx::AttribType::Uint8,
                     normalized);
    return *this;
}

template<>
VertexLayout &VertexLayout::add<int16_t>(size_t outPosition,
                                         size_t numValuePerArray,
                                         bool normalized) {
    vertexLayout.add((bgfx::Attrib::Enum) outPosition,
                     numValuePerArray,
                     bgfx::AttribType::Int16,
                     normalized);
    return *this;
}
} // namespace Blob
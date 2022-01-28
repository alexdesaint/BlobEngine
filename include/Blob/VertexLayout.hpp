#pragma once

#include <bgfx/bgfx.h>
#include <cstddef>
#include <tuple>
#include <vector>

namespace Blob {
class VertexLayout {
public:
    enum Type {
        Float,
        Uint8,
        Int16,
    };

    bgfx::VertexLayout vertexLayout;

    VertexLayout() = default;
    VertexLayout(
        const std::vector<std::tuple<Type, size_t, size_t, bool>> &layout) {
        begin();
        for (const auto &element : layout) {
            auto [type, outPosition, numValuePerArray, normalized] = element;
            add(type, outPosition, numValuePerArray, normalized);
        }
        end();
    }

    VertexLayout &begin() {
        vertexLayout.begin();
        return *this;
    }
    VertexLayout &end() {
        vertexLayout.end();
        return *this;
    }

    template<typename T>
    VertexLayout &
    add(size_t outPosition, size_t numValuePerArray, bool normalized = false);

    VertexLayout &add(Type type,
                      size_t outPosition,
                      size_t numValuePerArray,
                      bool normalized = false);
};

template<>
VertexLayout &VertexLayout::add<float>(size_t outPosition,
                                       size_t numValuePerArray,
                                       bool normalized);
template<>
VertexLayout &VertexLayout::add<uint8_t>(size_t outPosition,
                                         size_t numValuePerArray,
                                         bool normalized);
template<>
VertexLayout &VertexLayout::add<int16_t>(size_t outPosition,
                                         size_t numValuePerArray,
                                         bool normalized);
} // namespace Blob

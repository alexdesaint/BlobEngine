#pragma once

#include <Blob/Buffer.hpp>
#include <Blob/VertexLayout.hpp>
#include <bgfx/bgfx.h>
#include <vector>

namespace Blob {
class VertexBuffer {
private:
public:
    bgfx::VertexBufferHandle vertexBufferHandle;

    VertexBuffer(const Buffer &buffer, const VertexLayout &vertexLayout) {
        vertexBufferHandle =
            bgfx::createVertexBuffer(buffer.memory, vertexLayout.vertexLayout);
    }

    ~VertexBuffer() { bgfx::destroy(vertexBufferHandle); }
};
} // namespace Blob

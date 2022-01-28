#pragma once

#include <Blob/Buffer.hpp>
#include <bgfx/bgfx.h>
#include <vector>

namespace Blob {
struct RenderOptions {
    bgfx::IndexBufferHandle indexBufferHandle;

    // Instanced
    int32_t instancedCount = 0;

    RenderOptions() = default;
    RenderOptions(const RenderOptions &) = delete;
    RenderOptions(RenderOptions &&) = delete;

    RenderOptions(const Buffer &buffer) {
        indexBufferHandle = bgfx::createIndexBuffer(buffer.memory);
    }

    ~RenderOptions() { bgfx::destroy(indexBufferHandle); }
};

} // namespace Blob

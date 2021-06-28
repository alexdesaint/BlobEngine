#pragma once

#include <cstddef>
#include <cstdint>
#include <stdint.h>

namespace Blob::Core {
struct RenderOptions {
    // Index options
    const void *indices = nullptr;
    int32_t numOfIndices = 0;
    uint32_t indicesType = 0;

    // direct draw options
    int32_t elementOffset = 0, numOfElements = 0;

    // Instanced
    int32_t instancedCount = 0;

    RenderOptions() = default;
    RenderOptions(const RenderOptions &) = delete;
    RenderOptions(RenderOptions &&) = delete;

    RenderOptions(int32_t size, int32_t offset = 0);

    RenderOptions(const void *indices, int32_t numOfIndices, uint32_t indicesType);

    RenderOptions(const uint8_t *indices, int32_t numOfIndices);
    RenderOptions(const uint16_t *indices, int32_t numOfIndices);
    RenderOptions(const uint32_t *indices, int32_t numOfIndices);

    void setArray(int32_t size, int32_t offset = 0);

    void setIndices(const void *indices, int32_t numOfIndices, uint32_t indicesType);

    void setIndices(const uint8_t *indices, int32_t numOfIndices);
    void setIndices(const uint16_t *indices, int32_t numOfIndices);
    void setIndices(const uint32_t *indices, int32_t numOfIndices);
};

} // namespace Blob::Core

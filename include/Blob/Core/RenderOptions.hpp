#pragma once

#include <cstddef>
#include <cstdint>
#include <stdint.h>

namespace Blob::Core {
class RenderOptions {
    friend class Window;

private:
    // IndicesOptions
    bool indexed = false;

    // Index options
    const void *indices = nullptr;
    int32_t numOfIndices = 0;
    uint32_t indicesType = 0;

    // direct draw options
    int32_t elementOffset = 0, numOfElements = 0;

public:
    // Instanced
    int32_t instancedCount = 0;

    RenderOptions() = default;
    RenderOptions(const RenderOptions &) = delete;
    RenderOptions(RenderOptions &&) = delete;

    RenderOptions(const void *indices, int32_t numOfIndices, uint32_t indicesType);

    template<typename T>
    RenderOptions(const T *indices, int32_t numOfIndices);

    RenderOptions(int32_t size, int32_t offset = 0);

    void setArray(int32_t size, int32_t offset = 0);

    void setIndices(const void *indices, int32_t numOfIndices, uint32_t indicesType);

    template<typename T>
    void setIndices(const T *indices, int32_t numOfIndices);
};

template<>
RenderOptions::RenderOptions(const uint8_t *indices, int32_t numOfIndices);
template<>
RenderOptions::RenderOptions(const uint16_t *indices, int32_t numOfIndices);
template<>
RenderOptions::RenderOptions(const uint32_t *indices, int32_t numOfIndices);

template<>
void RenderOptions::setIndices(const uint8_t *indices, int32_t numOfIndices);
template<>
void RenderOptions::setIndices(const uint16_t *indices, int32_t numOfIndices);
template<>
void RenderOptions::setIndices(const uint32_t *indices, int32_t numOfIndices);

} // namespace Blob::Core

#pragma once

#include <unitypes.h>

namespace Blob::Core {
class RenderOptions {
public:
    // IndicesOptions
    bool indexed = false;

    // Index options
    const void *indices = nullptr;
    int32_t numOfIndices = 0;
    uint32_t indicesType = 0;

    // direct draw options
    int32_t elementOffset = 0, numOfElements = 0;

    void setIndices(const void *indices, int32_t numOfIndices, uint32_t indicesType);

    template<typename T>
    void setIndices(const T *indices, int32_t numOfIndices);
};

template<>
void RenderOptions::setIndices(const uint8_t *indices, int32_t numOfIndices);
template<>
void RenderOptions::setIndices(const uint16_t *indices, int32_t numOfIndices);
template<>
void RenderOptions::setIndices(const uint32_t *indices, int32_t numOfIndices);

} // namespace Blob::Core

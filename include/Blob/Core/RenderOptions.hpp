#pragma once

#include <unitypes.h>

namespace Blob::Core {
class RenderOptions {
public:
    // IndicesOptions
    bool indexed = false;

    // Index options
    void *indices = nullptr;
    int32_t numOfIndices = 0;
    uint32_t indicesType = 0;

    // direct draw options
    int32_t elementOffset = 0, numOfElements = 0;
/*
public:
    template<typename T>
    RenderOptions(T *indices, int32_t numOfIndices);

    explicit RenderOptions(int32_t numOfElements, int32_t elementOffset = 0);
    */
};

} // namespace Blob

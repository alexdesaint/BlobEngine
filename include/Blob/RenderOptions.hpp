#pragma once

#include <Blob/Geometrie.hpp>

namespace Blob {
struct RenderOptions {
    // IndicesOptions
    bool indexed = false;

    // Index options
    unsigned short *indices = nullptr;
    int32_t numOfIndices = 0;
    uint32_t indicesType = 0;

    // direct draw options
    int32_t elementOffset = 0, numOfElements = 0;
};
} // namespace Blob

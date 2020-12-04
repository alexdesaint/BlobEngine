#include <Blob/Core/RenderOptions.hpp>
#include <Blob/GL/Types.hpp>

namespace Blob::Core {

RenderOptions::RenderOptions(int32_t size, int32_t offset) : elementOffset(offset), numOfElements(size), indexed(false) {}

void RenderOptions::setArray(int32_t size, int32_t offset) {
    elementOffset = offset;
    numOfElements = size;
    indexed = false;
}

RenderOptions::RenderOptions(const void *i, int32_t noi, uint32_t it) {
    indices = i;
    indicesType = it;
    numOfIndices = noi;

    indexed = true;
}

void RenderOptions::setIndices(const void *i, int32_t noi, uint32_t it) {
    indices = i;
    indicesType = it;
    numOfIndices = noi;

    indexed = true;
}

template<>
RenderOptions::RenderOptions(const uint8_t *indices, int32_t numOfIndices) {
    setIndices(indices, numOfIndices, GL::getType<uint8_t>());
}

template<>
RenderOptions::RenderOptions(const uint16_t *indices, int32_t numOfIndices) {
    setIndices(indices, numOfIndices, GL::getType<uint16_t>());
}

template<>
RenderOptions::RenderOptions(const uint32_t *indices, int32_t numOfIndices) {
    setIndices(indices, numOfIndices, GL::getType<uint32_t>());
}

template<>
void RenderOptions::setIndices(const uint8_t *indices, int32_t numOfIndices) {
    setIndices(indices, numOfIndices, GL::getType<uint8_t>());
}

template<>
void RenderOptions::setIndices(const uint16_t *indices, int32_t numOfIndices) {
    setIndices(indices, numOfIndices, GL::getType<uint16_t>());
}

template<>
void RenderOptions::setIndices(const uint32_t *indices, int32_t numOfIndices) {
    setIndices(indices, numOfIndices, GL::getType<uint32_t>());
}

} // namespace Blob::Core
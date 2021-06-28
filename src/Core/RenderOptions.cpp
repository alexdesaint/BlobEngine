#include <Blob/Core/RenderOptions.hpp>
#include <Blob/GL/Types.hpp>

namespace Blob::Core {

RenderOptions::RenderOptions(int32_t size, int32_t offset) : elementOffset(offset), numOfElements(size) {}

RenderOptions::RenderOptions(const void *indices, int32_t numOfIndices, uint32_t indicesType) : indices(indices), numOfIndices(numOfIndices), indicesType(indicesType) {}

RenderOptions::RenderOptions(const uint8_t *indices, int32_t numOfIndices) : indices(indices), numOfIndices(numOfIndices), indicesType(GL::getType<uint8_t>()) {}

RenderOptions::RenderOptions(const uint16_t *indices, int32_t numOfIndices) : indices(indices), numOfIndices(numOfIndices), indicesType(GL::getType<uint16_t>()) {}

RenderOptions::RenderOptions(const uint32_t *indices, int32_t numOfIndices) : indices(indices), numOfIndices(numOfIndices), indicesType(GL::getType<uint32_t>()) {}

void RenderOptions::setArray(int32_t size, int32_t offset) {
    indices = nullptr;
    elementOffset = offset;
    numOfElements = size;
}

void RenderOptions::setIndices(const void *i, int32_t noi, uint32_t it) {
    indices = i;
    indicesType = it;
    numOfIndices = noi;
}

void RenderOptions::setIndices(const uint8_t *indices, int32_t numOfIndices) {
    setIndices(indices, numOfIndices, GL::getType<uint8_t>());
}

void RenderOptions::setIndices(const uint16_t *indices, int32_t numOfIndices) {
    setIndices(indices, numOfIndices, GL::getType<uint16_t>());
}

void RenderOptions::setIndices(const uint32_t *indices, int32_t numOfIndices) {
    setIndices(indices, numOfIndices, GL::getType<uint32_t>());
}

} // namespace Blob::Core
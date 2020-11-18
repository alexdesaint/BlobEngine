#include <Blob/Core/RenderOptions.hpp>
#include <Blob/GL/Types.hpp>

namespace Blob::Core {

void RenderOptions::setIndices(const void *i, int32_t noi, uint32_t it) {
    indices = i;
    indicesType = it;
    numOfIndices = noi;

    indexed = true;
}

template<typename T>
void RenderOptions::setIndices(const T *indices, int32_t numOfIndices) {
    setIndices(indices, numOfIndices, GL::getType<T>());
}

template<>
void RenderOptions::setIndices(const uint16_t *indices, int32_t numOfIndices) {
    setIndices(indices, numOfIndices, GL::getType<uint16_t>());
}

} // namespace Blob::Core
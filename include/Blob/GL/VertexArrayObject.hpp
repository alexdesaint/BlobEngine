#pragma once

#include "Blob/Maths.inl"
#include <Blob/GL/VertexBufferObject.hpp>
#include <stdint.h>

namespace Blob::GL {

class VertexArrayObject {
    friend class Window;

private:
    uint32_t vertexArrayObject = 0;

public:
    VertexArrayObject();

    VertexArrayObject(const VertexArrayObject &) = delete;

    VertexArrayObject(VertexArrayObject &&vao) noexcept;

    ~VertexArrayObject();

    void setBuffer(const VertexBufferObject &vbo, int32_t stride, uint32_t dataOffset = 0, uint32_t bufferPosition = 0, uint32_t divisor = 0) const;

    void setIndicesBuffer(const VertexBufferObject &vbo) const;

    void setArray(uint32_t numValuePerArray, uint32_t outPosition, uint32_t dataType, uint32_t relativeOffset, bool normalized = false, uint32_t bufferPosition = 0) const;

    template<typename T>
    void setArray(uint32_t numValuePerArray, uint32_t outPosition, uint32_t relativeOffset, bool normalized = false, uint32_t bufferPosition = 0) const;
};

template<>
void VertexArrayObject::setArray<float>(uint32_t numValuePerArray, uint32_t outPosition, uint32_t relativeOffset, bool normalized, uint32_t bufferPosition) const;

template<>
void VertexArrayObject::setArray<uint8_t>(uint32_t numValuePerArray, uint32_t outPosition, uint32_t relativeOffset, bool normalized, uint32_t bufferPosition) const;

template<>
void VertexArrayObject::setArray<uint16_t>(uint32_t numValuePerArray, uint32_t outPosition, uint32_t relativeOffset, bool normalized, uint32_t bufferPosition) const;

template<>
void VertexArrayObject::setArray<uint32_t>(uint32_t numValuePerArray, uint32_t outPosition, uint32_t relativeOffset, bool normalized, uint32_t bufferPosition) const;

template<>
void VertexArrayObject::setArray<int8_t>(uint32_t numValuePerArray, uint32_t outPosition, uint32_t relativeOffset, bool normalized, uint32_t bufferPosition) const;

template<>
void VertexArrayObject::setArray<int16_t>(uint32_t numValuePerArray, uint32_t outPosition, uint32_t relativeOffset, bool normalized, uint32_t bufferPosition) const;

template<>
void VertexArrayObject::setArray<int32_t>(uint32_t numValuePerArray, uint32_t outPosition, uint32_t relativeOffset, bool normalized, uint32_t bufferPosition) const;
} // namespace Blob::GL

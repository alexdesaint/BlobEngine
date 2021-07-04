#include <Blob/GL/VertexArrayObject.hpp>
#include <glad/glad.h>

namespace Blob::GL {

VertexArrayObject::VertexArrayObject() {
    glCreateVertexArrays(1, &vertexArrayObject);
}

VertexArrayObject::VertexArrayObject(VertexArrayObject &&vbo) noexcept {
    vertexArrayObject = vbo.vertexArrayObject;
    vbo.vertexArrayObject = 0;
}

VertexArrayObject::~VertexArrayObject() {
    glDeleteVertexArrays(1, &vertexArrayObject);
}

void VertexArrayObject::setBuffer(const VertexBufferObject &vbo,
                                  GLsizei stride,
                                  GLuint dataOffset,
                                  GLuint bufferPosition,
                                  GLuint divisor) const {
    glVertexArrayVertexBuffer(vertexArrayObject,
                              bufferPosition,
                              vbo.vertexBufferObject,
                              dataOffset,
                              stride);

    if (divisor != 0)
        glVertexArrayBindingDivisor(vertexArrayObject, bufferPosition, divisor);
}

void VertexArrayObject::setIndicesBuffer(const VertexBufferObject &vbo) const {
    glVertexArrayElementBuffer(vertexArrayObject, vbo.vertexBufferObject);
}

void VertexArrayObject::setArray(GLuint numValuePerArray,
                                 GLuint outPosition,
                                 GLenum dataType,
                                 GLuint relativeOffset,
                                 bool normalized,
                                 GLuint bufferPosition) const {
    glEnableVertexArrayAttrib(vertexArrayObject, outPosition);

    glVertexArrayAttribFormat(vertexArrayObject,
                              outPosition,
                              numValuePerArray,
                              dataType,
                              static_cast<GLboolean>(normalized),
                              relativeOffset);

    glVertexArrayAttribBinding(vertexArrayObject, outPosition, bufferPosition);
}

template<>
void VertexArrayObject::setArray<float>(GLuint numValuePerArray,
                                        GLuint outPosition,
                                        GLuint relativeOffset,
                                        bool normalized,
                                        uint32_t bufferPosition) const {
    setArray(numValuePerArray,
             outPosition,
             GL_FLOAT,
             relativeOffset,
             normalized,
             bufferPosition);
}

template<>
void VertexArrayObject::setArray<uint8_t>(uint32_t numValuePerArray,
                                          uint32_t outPosition,
                                          uint32_t relativeOffset,
                                          bool normalized,
                                          uint32_t bufferPosition) const {
    setArray(numValuePerArray,
             outPosition,
             GL_UNSIGNED_BYTE,
             relativeOffset,
             normalized,
             bufferPosition);
}

template<>
void VertexArrayObject::setArray<uint16_t>(uint32_t numValuePerArray,
                                           uint32_t outPosition,
                                           uint32_t relativeOffset,
                                           bool normalized,
                                           uint32_t bufferPosition) const {
    setArray(numValuePerArray,
             outPosition,
             GL_UNSIGNED_SHORT,
             relativeOffset,
             normalized,
             bufferPosition);
}

template<>
void VertexArrayObject::setArray<uint32_t>(uint32_t numValuePerArray,
                                           uint32_t outPosition,
                                           uint32_t relativeOffset,
                                           bool normalized,
                                           uint32_t bufferPosition) const {
    setArray(numValuePerArray,
             outPosition,
             GL_UNSIGNED_INT,
             relativeOffset,
             normalized,
             bufferPosition);
}

template<>
void VertexArrayObject::setArray<int8_t>(uint32_t numValuePerArray,
                                         uint32_t outPosition,
                                         uint32_t relativeOffset,
                                         bool normalized,
                                         uint32_t bufferPosition) const {
    setArray(numValuePerArray,
             outPosition,
             GL_BYTE,
             relativeOffset,
             normalized,
             bufferPosition);
}

template<>
void VertexArrayObject::setArray<int16_t>(uint32_t numValuePerArray,
                                          uint32_t outPosition,
                                          uint32_t relativeOffset,
                                          bool normalized,
                                          uint32_t bufferPosition) const {
    setArray(numValuePerArray,
             outPosition,
             GL_SHORT,
             relativeOffset,
             normalized,
             bufferPosition);
}

template<>
void VertexArrayObject::setArray<int32_t>(uint32_t numValuePerArray,
                                          uint32_t outPosition,
                                          uint32_t relativeOffset,
                                          bool normalized,
                                          uint32_t bufferPosition) const {
    setArray(numValuePerArray,
             outPosition,
             GL_INT,
             relativeOffset,
             normalized,
             bufferPosition);
}
} // namespace Blob::GL

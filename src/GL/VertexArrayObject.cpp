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

void VertexArrayObject::setBuffer(const VertexBufferObject &vbo, GLsizei stride, GLuint dataOffset, uint32_t pos) const {

    // ajoute le buffer au VAO et donne la taille des vecteurs
    glVertexArrayVertexBuffer(vertexArrayObject, pos, vbo.vertexBufferObject, dataOffset, stride);
}

void VertexArrayObject::setIndicesBuffer(const VertexBufferObject &vbo) const {
    glVertexArrayElementBuffer(vertexArrayObject, vbo.vertexBufferObject);
}

void VertexArrayObject::setArray(GLuint numValuePerArray, GLuint outPosition, GLenum dataType, GLuint relativeOffset, bool normalized, uint32_t pos) const {

    // Enable or disable a generic vertex attribute array
    glEnableVertexArrayAttrib(vertexArrayObject, outPosition);

    // specify the organization of vertex arrays
    glVertexArrayAttribFormat(vertexArrayObject, outPosition, numValuePerArray, dataType, static_cast<GLboolean>(normalized), relativeOffset);

    // associate a vertex attribute and a vertex buffer binding for a vertex array object
    // void glVertexArrayAttribBinding(
    //     name of the vertex array object,
    //     index of the attribute to associate with a vertex buffer,
    //     index of the vertex buffer binding with which to associate the generic vertex attribute
    // );
    glVertexArrayAttribBinding(vertexArrayObject, outPosition, pos);
}

template<>
void VertexArrayObject::setArray<float>(GLuint numValuePerArray, GLuint outPosition, GLuint relativeOffset, bool normalized, uint32_t pos) {

    /// Get the size of the type in template argument
    // auto offset = ((uint32_t)&reinterpret_cast<char const volatile&>((((C*)0)->T)));
    // GLuint numValuePerArray = sizeof(T) / sizeof(array[0]);

    setArray(numValuePerArray, outPosition, GL_FLOAT, relativeOffset, normalized, pos);
}

template<>
void VertexArrayObject::setArray<uint8_t>(uint32_t numValuePerArray, uint32_t outPosition, uint32_t relativeOffset, bool normalized, uint32_t pos) {
    setArray(numValuePerArray, outPosition, GL_UNSIGNED_BYTE, relativeOffset, normalized, pos);
}

template<>
void VertexArrayObject::setArray<uint16_t>(uint32_t numValuePerArray, uint32_t outPosition, uint32_t relativeOffset, bool normalized, uint32_t pos) {
    setArray(numValuePerArray, outPosition, GL_UNSIGNED_SHORT, relativeOffset, normalized, pos);
}

template<>
void VertexArrayObject::setArray<uint32_t>(uint32_t numValuePerArray, uint32_t outPosition, uint32_t relativeOffset, bool normalized, uint32_t pos) {
    setArray(numValuePerArray, outPosition, GL_UNSIGNED_INT, relativeOffset, normalized, pos);
}

template<>
void VertexArrayObject::setArray<int8_t>(uint32_t numValuePerArray, uint32_t outPosition, uint32_t relativeOffset, bool normalized, uint32_t pos) {
    setArray(numValuePerArray, outPosition, GL_BYTE, relativeOffset, normalized, pos);
}

template<>
void VertexArrayObject::setArray<int16_t>(uint32_t numValuePerArray, uint32_t outPosition, uint32_t relativeOffset, bool normalized, uint32_t pos) {
    setArray(numValuePerArray, outPosition, GL_SHORT, relativeOffset, normalized, pos);
}

template<>
void VertexArrayObject::setArray<int32_t>(uint32_t numValuePerArray, uint32_t outPosition, uint32_t relativeOffset, bool normalized, uint32_t pos) {
    setArray(numValuePerArray, outPosition, GL_INT, relativeOffset, normalized, pos);
}
} // namespace Blob::GL

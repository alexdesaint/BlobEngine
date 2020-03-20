#include <Blob/Exception.hpp>
#include <Blob/GL/VertexArrayObject.hpp>
#include <glad/glad.h>

namespace Blob::GL {

VertexArrayObject::VertexArrayObject() {
    glCreateVertexArrays(1, &vertexArrayObject);
}

VertexArrayObject::~VertexArrayObject() {
    glDeleteVertexArrays(1, &vertexArrayObject);
}

GLuint VertexArrayObject::getVertexArrayObject() const {
    return vertexArrayObject;
}

void VertexArrayObject::setBuffer(const VertexBufferObject &vbo, GLsizei stride, GLuint dataOffset, uint32_t pos) {

    // ajoute le buffer au VAO et donne la taille des vecteurs
    glVertexArrayVertexBuffer(vertexArrayObject, pos, vbo.getVertexBufferObject(), dataOffset, stride);
}

void VertexArrayObject::setIndicesBuffer(const VertexBufferObject &vbo) {
    glVertexArrayElementBuffer(vertexArrayObject, vbo.getVertexBufferObject());
}

void VertexArrayObject::setArray(GLuint numValuePerArray, GLuint outPosition, GLenum dataType, GLuint relativeOffset, bool normalized, uint32_t pos) {

    // autorise l'utilisation de cet atribut
    glEnableVertexArrayAttrib(vertexArrayObject, outPosition);

    // définit le format de l'atribut
    glVertexArrayAttribFormat(vertexArrayObject, outPosition, numValuePerArray, dataType, static_cast<GLboolean>(normalized), relativeOffset);

    // lie l'attribu avec le buffer
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

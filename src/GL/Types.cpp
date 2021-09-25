#include <Blob/Core/Exception.hpp>
#include <Blob/GL/Types.hpp>

// GLAD
#include <glad/gl.h>

namespace Blob::GL {

template<>
uint32_t getType<int8_t>() {
    return GL_BYTE;
}

template<>
uint32_t getType<int16_t>() {
    return GL_SHORT;
}

template<>
uint32_t getType<int32_t>() {
    return GL_INT;
}

template<>
uint32_t getType<uint8_t>() {
    return GL_UNSIGNED_BYTE;
}

template<>
uint32_t getType<uint16_t>() {
    return GL_UNSIGNED_SHORT;
}

template<>
uint32_t getType<uint32_t>() {
    return GL_UNSIGNED_INT;
}

template<>
uint32_t getType<float>() {
    return GL_FLOAT;
}

template<>
uint32_t getType<double>() {
    return GL_DOUBLE;
}

size_t getTypeSize(uint32_t type) {
    GLuint typeSize = 0;

    switch (type) {
    case GL_BYTE:
        typeSize = sizeof(GLbyte);
        break;
    case GL_UNSIGNED_BYTE:
        typeSize = sizeof(GLubyte);
        break;
    case GL_SHORT:
        typeSize = sizeof(GLshort);
        break;
    case GL_UNSIGNED_SHORT:
        typeSize = sizeof(GLushort);
        break;
    case GL_INT:
        typeSize = sizeof(GLint);
        break;
    case GL_UNSIGNED_INT:
        typeSize = sizeof(GLuint);
        break;
    case GL_FLOAT:
        typeSize = sizeof(GLfloat);
        break;
    default:
        throw Exception("incorrect Type of data");
    }

    return typeSize;
}

} // namespace Blob::GL
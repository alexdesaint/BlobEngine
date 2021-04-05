#include <Blob/GL/VertexBufferObject.hpp>

#include <glad/glad.h>

namespace Blob::GL {

VertexBufferObject::VertexBufferObject() {
    glCreateBuffers(1, &vertexBufferObject);
}

VertexBufferObject::VertexBufferObject(const uint8_t *data, size_t dataSize) {
    glCreateBuffers(1, &vertexBufferObject);
    setData(data, dataSize);
}

VertexBufferObject::VertexBufferObject(VertexBufferObject &&vbo) noexcept {
    vertexBufferObject = vbo.vertexBufferObject;
    vbo.vertexBufferObject = 0;
    dataSize = vbo.dataSize;
}

VertexBufferObject::~VertexBufferObject() {
    glDeleteBuffers(1, &vertexBufferObject);
}

void VertexBufferObject::setData(const uint8_t *data, size_t ds, bool dynamic) {
    dataSize = ds;

    if (dynamic)
        glNamedBufferStorage(vertexBufferObject, dataSize, data, GL_DYNAMIC_STORAGE_BIT);
    else
        glNamedBufferStorage(vertexBufferObject, dataSize, data, 0);
}

void VertexBufferObject::setSubData(uint8_t *data, size_t dataSize, size_t offset) {
    glNamedBufferSubData(vertexBufferObject, offset, dataSize, data);
}

} // namespace Blob::GL
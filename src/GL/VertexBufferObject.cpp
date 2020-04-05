#include <Blob/GL/VertexBufferObject.hpp>

#include <glad/glad.h>

namespace Blob::GL {

VertexBufferObject::VertexBufferObject() {}

VertexBufferObject::VertexBufferObject(GLubyte *data, GLsizeiptr dataSize) {
    setData(data, dataSize);
}

VertexBufferObject::VertexBufferObject(VertexBufferObject &&vbo) noexcept {
    vertexBufferObject = vbo.vertexBufferObject;
    vbo.vertexBufferObject = -1;
    dataSize = vbo.dataSize;
}

VertexBufferObject::~VertexBufferObject() {
    if (vertexBufferObject != -1)
        glDeleteBuffers(1, &vertexBufferObject);
}

void VertexBufferObject::setData(GLubyte *data, GLsizeiptr ds, bool dynamic) {
    if (vertexBufferObject != -1) {
        glDeleteBuffers(1, &vertexBufferObject);
        glCreateBuffers(1, &vertexBufferObject);
    } else
        glCreateBuffers(1, &vertexBufferObject);

    dataSize = ds;

    if (dynamic)
        glNamedBufferStorage(vertexBufferObject, dataSize, data, GL_DYNAMIC_STORAGE_BIT);
    else
        glNamedBufferStorage(vertexBufferObject, dataSize, data, 0);
}

void VertexBufferObject::setSubData(uint8_t *data, int64_t dataSize, int64_t offset) {
    glNamedBufferSubData(vertexBufferObject, offset, dataSize, data);
}

uint32_t VertexBufferObject::getVertexBufferObject() const {
    return vertexBufferObject;
}
} // namespace Blob::GL
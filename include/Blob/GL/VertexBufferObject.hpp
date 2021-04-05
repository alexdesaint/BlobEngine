#pragma once

#include <cstdint>
#include <vector>

namespace Blob::GL {

class VertexBufferObject {
    friend class VertexArrayObject;

private:
    uint32_t vertexBufferObject = 0;

protected:
    size_t dataSize = 0;

public:
    VertexBufferObject();

    VertexBufferObject(const uint8_t *data, size_t dataSize);

    VertexBufferObject(const VertexBufferObject &) = delete;

    VertexBufferObject(VertexBufferObject &&vbo) noexcept;

    ~VertexBufferObject();

    void setData(const uint8_t *data, size_t dataSize, bool dynamic = false);

    void setSubData(uint8_t *data, size_t dataSize, size_t offset = 0);
};
} // namespace Blob::GL

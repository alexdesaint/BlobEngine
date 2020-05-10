#pragma once

#include <cstdint>
#include <vector>

namespace Blob::GL {

class VertexBufferObject {
private:
    uint32_t vertexBufferObject = 0;

    int64_t dataSize = 0;

public:
    uint32_t getVertexBufferObject() const;

    VertexBufferObject();

    VertexBufferObject(uint8_t *data, int64_t dataSize);

    VertexBufferObject(const VertexBufferObject &) = delete;

    VertexBufferObject(VertexBufferObject &&vbo) noexcept;

    ~VertexBufferObject();

    void setData(uint8_t *data, int64_t dataSize, bool dynamic = false);

    void setSubData(uint8_t *data, int64_t dataSize, int64_t offset = 0);
};
} // namespace Blob::GL

#pragma once

#include <Blob/GL/VertexBufferObject.hpp>
#include <string>
#include <array>

namespace Blob::Core {

class Buffer : public GL::VertexBufferObject {
public:
    Buffer() = default;
    explicit Buffer(const std::string& file);
    explicit Buffer(const uint8_t *data, size_t dataSize) : GL::VertexBufferObject(data, dataSize) {}
};

} // namespace Blob::Core
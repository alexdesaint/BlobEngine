#pragma once

#include <Blob/GL/VertexBufferObject.hpp>
#include <array>
#include <string>

namespace Blob {

class Buffer : public GL::VertexBufferObject {
public:
    Buffer() = default;
    explicit Buffer(const std::string &file);
    Buffer(const uint8_t *data, size_t dataSize) :
        GL::VertexBufferObject(data, dataSize) {}

    template<typename T>
    explicit Buffer(std::vector<T> data) {
        setData(data);
    }

    template<typename T, std::size_t N>
    explicit Buffer(std::array<T, N> data) {
        setData(data);
    }

    template<typename T>
    void setData(std::vector<T> data) {
        GL::VertexBufferObject::setData((const uint8_t *) data.data(),
                                        data.size() * sizeof(T));
    }

    template<typename T, std::size_t N>
    void setData(std::array<T, N> data) {
        GL::VertexBufferObject::setData((const uint8_t *) data.data(),
                                        N * sizeof(T));
    }
};

} // namespace Blob
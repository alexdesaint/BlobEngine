#pragma once

#include <array>
#include <string>
#include <vector>

#include <bgfx/bgfx.h>

namespace Blob {
class Buffer {
private:
public:
    const bgfx::Memory *memory = nullptr;

    Buffer(const std::string &file) { setData(file); }

    template<typename T>
    Buffer(const std::vector<T> &data, bool copy = false) {
        if (copy)
            memory =
                bgfx::copy((const void *) data.data(), sizeof(T) * data.size());
        else
            memory = bgfx::makeRef((const void *) data.data(),
                                   sizeof(T) * data.size());
    }

    template<typename T, size_t S>
    Buffer(const std::array<T, S> &data, bool copy = false) {
        if (copy)
            memory =
                bgfx::copy((const void *) data.data(), sizeof(T) * data.size());
        else
            memory = bgfx::makeRef((const void *) data.data(),
                                   sizeof(T) * data.size());
    }

    template<typename T, size_t S>
    Buffer(const T (&data)[S], bool copy = false) {
        if (copy)
            memory = bgfx::copy((const void *) data, sizeof(data));
        else
            memory = bgfx::makeRef((const void *) data, sizeof(data));
    }

    void setData(const std::string &file);
};
} // namespace Blob

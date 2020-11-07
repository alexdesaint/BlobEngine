#pragma once

#include <iostream>
#include <nlohmann/json.hpp>
#include <Blob/Core/Buffer.hpp>

namespace Blob::glTF2 {

class Buffer : public Core::Buffer {
public:
    std::string uri;   ///< The uri of the buffer.
    size_t byteLength; ///< The total byte length of the buffer view. Required
    std::string name;  ///< The user-defined name of this object.
    // object extensions;///< Dictionary object with extension-specific objects.

    Buffer(const nlohmann::json &j, const std::string &path);

    friend std::ostream &operator<<(std::ostream &s, const Buffer &a);

    std::vector<uint8_t> getData(size_t size, size_t offset) const;
};
} // namespace Blob::glTF2

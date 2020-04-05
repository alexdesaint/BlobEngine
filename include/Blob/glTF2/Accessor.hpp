#pragma once

#include <iostream>
#include <nlohmann/json.hpp>

namespace Blob::glTF2 {

class Accessor {
public:
    enum Type { SCALAR = 1, VEC2 = 2, VEC3 = 3, VEC4 = 4, MAT2 = 4, MAT3 = 9, MAT4 = 16 };

    int bufferView = -1;         ///< The index of the bufferView. (required)
    unsigned int byteOffset = 0; ///< The offset relative to the start of the bufferView in bytes. default: 0
    uint32_t componentType;      ///< The datatype of components in the attribute. (required)
    bool normalized = false;     ///< Specifies whether integer data values should be normalized. default: false
    int count;                   ///< The number of attributes referenced by this accessor. (required)
    Type type;                   ///< Specifies if the attribute is a scalar, vector, or matrix. (required)
    std::vector<float> max;      ///< Maximum value of each component in this attribute.
    std::vector<float> min;      ///< Minimum value of each component in this attribute.
    // Sparse sparse; ///< Sparse storage of attributes that deviate from their initialization value.
    std::string name; ///< The user-defined name of this object.

    explicit Accessor(const nlohmann::json &j);

    [[nodiscard]] uint32_t getSize() const;

    friend std::ostream &operator<<(std::ostream &s, const Accessor &a);
};

void from_json(const nlohmann::json &j, Accessor &a);

} // namespace Blob::glTF2

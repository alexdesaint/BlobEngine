#pragma once

#include <Blob/GL/Texture.hpp>
#include <iostream>
#include <nlohmann/json.hpp>

namespace Blob::glTF2 {
/**
 * Texture sampler properties for filtering and wrapping modes.
 */
class Sampler : public GL::Sampler {
public:
    // int magFilter; ///< Magnification filter.
    // int minFilter; ///< Minification filter.
    // int wrapS; ///< s wrapping mode.
    // int wrapT; ///< t wrapping mode.
    std::string name; ///< The user-defined name of this object.

    Sampler();

    explicit Sampler(const nlohmann::json &j);

    friend std::ostream &operator<<(std::ostream &s, const Sampler &a);
};
} // namespace Blob::glTF2

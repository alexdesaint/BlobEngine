#pragma once

#include <nlohmann/json.hpp>

namespace Blob::glTF2 {
    /**
     * Texture sampler properties for filtering and wrapping modes.
     */
    class Sampler {
    public:
        int magFilter = 9728; ///< Magnification filter.
        int minFilter = 9728; ///< Minification filter.
        int wrapS = 10497; ///< s wrapping mode.
        int wrapT = 10497; ///< t wrapping mode.
        std::string name; ///< The user-defined name of this object.

        explicit Sampler(const nlohmann::json &j);

        friend std::ostream &operator<<(std::ostream &s, const Sampler &a);
    };
}

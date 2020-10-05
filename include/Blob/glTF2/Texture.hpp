#pragma once

#include <iostream>
#include <vector>
#include <nlohmann/json.hpp>
#include <Blob/Core/Texture.hpp>
#include <Blob/glTF2/Image.hpp>
#include <Blob/glTF2/Sampler.hpp>

namespace Blob::glTF2 {
/**
 * A texture and its sampler.
 */
class Texture : public Core::Texture {
public:
    int sampler = -1; ///< The index of the sampler used by this texture. When undefined, a sampler with repeat
    ///< wrapping and auto filtering should be used.

    int source = -1; ///< The index of the image used by this texture. When undefined, it is expected that an
    ///< extension or other mechanism will supply an alternate texture source, otherwise behavior is undefined.

    std::string name; ///< The user-defined name of this object.

    Texture(const nlohmann::json &j, std::vector<Image> &images, std::vector<Sampler> &samplers);

    friend std::ostream &operator<<(std::ostream &s, const Texture &a);
};
} // namespace Blob::glTF2

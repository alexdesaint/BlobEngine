#pragma once

#include <Blob/glTF2/Image.hpp>
#include <Blob/glTF2/Sampler.hpp>
#include <Blob/GL/Texture.hpp>
#include <list>

#include <nlohmann/json.hpp>

namespace Blob::glTF2 {
    /**
     * A texture and its sampler.
     */
    class Texture : public GL::Texture {
    public:
        int sampler = -1; ///< The index of the sampler used by this texture. When undefined, a sampler with repeat
        ///< wrapping and auto filtering should be used.

        int source = -1; ///< The index of the image used by this texture. When undefined, it is expected that an
        ///< extension or other mechanism will supply an alternate texture source, otherwise behavior is undefined.

        std::string name; ///< The user-defined name of this object.

        std::list<Image>::iterator sourceIt;
        std::list<Sampler>::iterator samplerIt;

        Texture(const nlohmann::json &j, std::list<Image> &images, std::list<Sampler> &samplers);

        friend std::ostream &operator<<(std::ostream &s, const Texture &a);
    };
}

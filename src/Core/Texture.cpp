#include <Blob/Core/Texture.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <Blob/Core/Exception.hpp>

namespace Blob::Core {

Texture::Texture(const std::string &path) {
    setImage(path);
}

Texture::Texture(const std::string &path, GL::Sampler sampler) {
    setImage(path);
    applySampler(sampler);
}

void Texture::setImage(const std::string &path) {
    unsigned char *rgb = stbi_load(path.c_str(), &width, &height, &bitPerPixel, 3);

    if (rgb == nullptr)
        throw Blob::Core::Exception("Fail to load Texture : " + path);

    setRGB32data(rgb, width, height);

    stbi_image_free(rgb);
}

} // namespace Blob::Core
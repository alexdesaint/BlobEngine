#include <Blob/Core/Texture.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <Blob/Core/Exception.hpp>

namespace Blob::Core {

Texture::Texture(const std::string &path) {
    setRGBImage(path);
}

Texture::Texture(const std::string &path, GL::Sampler sampler) {
    setRGBImage(path);
    applySampler(sampler);
}

void Texture::setRGBImage(const std::string &path) {
    int bitPerPixel;
    Maths::Vec2<int> s;
    unsigned char *rgb = stbi_load(path.c_str(), &s.x, &s.y, &bitPerPixel, 3);

    if (rgb == nullptr)
        throw Blob::Core::Exception("Fail to load Texture : " + path);

    setRGB8data(rgb, s.cast<unsigned int>());

    stbi_image_free(rgb);
}

void Texture::setRGBAImage(const std::string &path) {
    int bitPerPixel;;
    Maths::Vec2<int> s;
    unsigned char *rgb = stbi_load(path.c_str(), &s.x, &s.y, &bitPerPixel, 4);

    if (rgb == nullptr)
        throw Blob::Core::Exception("Fail to load Texture : " + path);

    setRGBA8data(rgb, s.cast<unsigned int>());

    stbi_image_free(rgb);
}

} // namespace Blob::Core
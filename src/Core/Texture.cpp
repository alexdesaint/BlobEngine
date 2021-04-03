#include <Blob/Core/Texture.hpp>

#include <Blob/Core/Exception.hpp>

namespace Blob::Core {

Texture::Texture(const std::string &path) {
    setImage(path);
}

Texture::Texture(const std::string &path, GL::Sampler sampler) {
    setImage(path);
    applySampler(sampler);
}

Texture::Texture(const Image &image, GL::Sampler sampler) {
    setImage(image);
    applySampler(sampler);
}

Texture::Texture(const Image &image) {
    setImage(image);
}

void Texture::setImage(const std::string &path) {
    Image image(path);

    if(image.channel == Image::Channel::RGB)
        setRGB8data(image.data, image.size.cast<unsigned int>());
    else if(image.channel == Image::Channel::RGBA)
        setRGBA8data(image.data, image.size.cast<unsigned int>());
    else
        throw Blob::Core::Exception("Image format not supported");
}

void Texture::setImage(const Image &image) {
    if(image.channel == Image::Channel::RGB)
        setRGB8data(image.data, image.size.cast<unsigned int>());
    else if(image.channel == Image::Channel::RGBA)
        setRGBA8data(image.data, image.size.cast<unsigned int>());
    else
        throw Blob::Core::Exception("Image format not supported");
}

} // namespace Blob::Core
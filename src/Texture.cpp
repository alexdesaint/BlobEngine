#include <Blob/Texture.hpp>

#include <Blob/Exception.hpp>

namespace Blob {

// Texture::Texture(const std::string &path) {
//     setImage(path);
// }
//
// Texture::Texture(const std::string &path, GL::Sampler sampler) {
//     setImage(path);
//     applySampler(sampler);
// }
//
// Texture::Texture(const Image &image, GL::Sampler sampler) {
//     setImage(image);
//     applySampler(sampler);
// }
//
// Texture::Texture(const Image &image) {
//     setImage(image);
// }
//
// void Texture::setImage(const std::string &path) {
//     Image image(path);
//
//     if (image.channel == Image::Channel::RGB)
//         setRGB8data(image.data, image.size);
//     else if (image.channel == Image::Channel::RGBA)
//         setRGBA8data(image.data, image.size);
//     else
//         throw Blob::Exception("Image format not supported");
// }
//
// void Texture::setImage(const Image &image) {
//     if (image.channel == Image::Channel::RGB)
//         setRGB8data(image.data, image.size);
//     else if (image.channel == Image::Channel::RGBA)
//         setRGBA8data(image.data, image.size);
//     else
//         throw Blob::Exception("Image format not supported");
// }

} // namespace Blob
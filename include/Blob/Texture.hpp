#pragma once

#include <Blob/FilePath.hpp>
#include <Blob/Image.hpp>
#include <memory>

namespace Blob {

class Texture {
public:
    Texture() = default;
    // explicit Texture(const std::string &path);
    // Texture(const std::string &path, GL::Sampler sampler);
    // explicit Texture(const Image &image);
    // Texture(const Image &image, GL::Sampler sampler);
    // void setImage(const std::string &path);
    // void setImage(const Image &image);

    Vec2<size_t> getTextureSize() const { return {}; }
};

} // namespace Blob

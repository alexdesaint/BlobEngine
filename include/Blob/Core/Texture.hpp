#pragma once

#include <Blob/Core/Image.hpp>
#include <Blob/GL/Texture.hpp>

namespace Blob::Core {

class Texture : public GL::Texture {
public:
    Texture() = default;
    explicit Texture(const std::string &path);
    Texture(const std::string &path, GL::Sampler sampler);
    explicit Texture(const Image &image);
    Texture(const Image &image, GL::Sampler sampler);
    void setImage(const std::string &path);
    void setImage(const Image &image);
};

} // namespace Blob::Core
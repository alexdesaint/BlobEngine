#pragma once

#include <Blob/GL/Texture.hpp>

namespace Blob::Core {

class Texture : public GL::Texture {
public:
    Texture() = default;
    explicit Texture(const std::string &path);
    Texture(const std::string &path, GL::Sampler sampler);
    void setRGBImage(const std::string &path);
    void setRGBAImage(const std::string &path);
};

} // namespace Blob::Core
#pragma once

#include <Blob/Maths.inl>
#include <string>

namespace Blob::GL {

class Core;

class Texture {
    friend Core;

private:
    uint32_t texture = 0; // the opengl texture

    int height = 0, width = 0, bitPerPixel = 0; // images data

    bool depth = false, textureLoaded = false;

    void init();

public:
    Texture() = default;

    explicit Texture(const std::string &path, bool nearest = false);

    Texture(const Texture &) = delete;

    Texture(Texture &&vbo) noexcept;

    ~Texture();

    void loadBMP(const std::string &path, bool nearest = false);

    void setImage(const std::string &path);

    void setRGBA32data(uint8_t *pixels, unsigned int width, unsigned int height, bool nearest = false);

    [[nodiscard]] unsigned int getTextureID() const;

    [[nodiscard]] Maths::Vec2<int> getTextureSize() const;
};
} // namespace Blob::GL

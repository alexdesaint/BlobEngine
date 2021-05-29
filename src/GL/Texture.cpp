#include <Blob/GL/Texture.hpp>

#include <glad/glad.h>

namespace Blob::GL {

Texture::~Texture() {
    if (texture != 0)
        glDeleteTextures(1, &texture);
}

Texture::Texture(Texture &&vbo) noexcept {
    texture = vbo.texture;
    vbo.texture = 0;

    size = vbo.size;
}

void Texture::applySampler(const Sampler &sampler) {
    glTextureParameteri(texture, GL_TEXTURE_MIN_FILTER, sampler.minFilter);
    glTextureParameteri(texture, GL_TEXTURE_MAG_FILTER, sampler.magFilter);
    glTextureParameteri(texture, GL_TEXTURE_WRAP_S, sampler.wrapS);
    glTextureParameteri(texture, GL_TEXTURE_WRAP_T, sampler.wrapT);
}

void Texture::setRGB8data(uint8_t *pixels, Maths::Vec2<unsigned int> size) {
    if (texture != 0)
        glDeleteTextures(1, &texture);

    glCreateTextures(GL_TEXTURE_2D, 1, &texture);

    Texture::size = size;

    glTextureStorage2D(texture, 1, GL_RGB8, size.x, size.y);
    if (pixels != nullptr)
        glTextureSubImage2D(texture, 0, 0, 0, size.x, size.y, GL_RGB, GL_UNSIGNED_BYTE, pixels);
}

void Texture::setRGBA8data(uint8_t *pixels, Maths::Vec2<unsigned int> size) {
    if (texture != 0)
        glDeleteTextures(1, &texture);

    glCreateTextures(GL_TEXTURE_2D, 1, &texture);

    Texture::size = size;

    glTextureStorage2D(texture, 1, GL_RGBA8, size.x, size.y);
    if (pixels != nullptr)
        glTextureSubImage2D(texture, 0, 0, 0, size.x, size.y, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
}

void Texture::setRGBA16data(uint8_t *pixels, Maths::Vec2<unsigned int> size) {
    if (texture != 0)
        glDeleteTextures(1, &texture);

    glCreateTextures(GL_TEXTURE_2D, 1, &texture);

    Texture::size = size;

    glTextureStorage2D(texture, 1, GL_RGBA16, size.x, size.y);
    if (pixels != nullptr)
        glTextureSubImage2D(texture, 0, 0, 0, size.x, size.y, GL_RGBA, GL_UNSIGNED_SHORT, pixels);
}

Maths::Vec2<unsigned int> Texture::getTextureSize() const {
    return size;
}

} // namespace Blob::GL

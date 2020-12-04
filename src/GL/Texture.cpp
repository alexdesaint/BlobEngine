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

    height =  vbo.height;
    vbo.height = 0;
    width =  vbo.width;
    vbo.width = 0;
    bitPerPixel =  vbo.bitPerPixel;
    vbo.bitPerPixel = 0;
    depth =  vbo.depth;
    vbo.depth = false;
}

void Texture::applySampler(const Sampler &sampler) {
    glTextureParameteri(texture, GL_TEXTURE_MIN_FILTER, sampler.minFilter);
    glTextureParameteri(texture, GL_TEXTURE_MAG_FILTER, sampler.magFilter);
    glTextureParameteri(texture, GL_TEXTURE_WRAP_S, sampler.wrapS);
    glTextureParameteri(texture, GL_TEXTURE_WRAP_T, sampler.wrapT);
}

void Texture::setRGB32data(uint8_t *pixels, unsigned int width, unsigned int height) {
    if (texture != 0)
        glDeleteTextures(1, &texture);

    glCreateTextures(GL_TEXTURE_2D, 1, &texture);

    this->width = width;
    this->height = height;

    glTextureStorage2D(texture, 1, GL_RGB8, width, height);
    glTextureSubImage2D(texture, 0, 0, 0, width, height, GL_RGB, GL_UNSIGNED_BYTE, pixels);
}

void Texture::setRGBA32data(uint8_t *pixels, unsigned int width, unsigned int height) {
    if (texture != 0)
        glDeleteTextures(1, &texture);

    glCreateTextures(GL_TEXTURE_2D, 1, &texture);

    this->width = width;
    this->height = height;

    glTextureStorage2D(texture, 1, GL_RGBA8, width, height);
    glTextureSubImage2D(texture, 0, 0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
}

unsigned int Texture::getTextureID() const {
    return texture;
}

Maths::Vec2<int> Texture::getTextureSize() const {
    return {width, height};
}

} // namespace Blob::GL

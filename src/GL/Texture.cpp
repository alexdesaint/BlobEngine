#include <Blob/Core/Exception.hpp>
#include <Blob/GL/Texture.hpp>

#include <glad/glad.h>

#define STB_IMAGE_IMPLEMENTATION

#include <stb_image.h>
/// TODO: Move the image loading part in Blob::Texture

namespace Blob::GL {


void Texture::init() {
    if (textureLoaded)
        glDeleteTextures(1, &texture);

    glCreateTextures(GL_TEXTURE_2D, 1, &texture);
    textureLoaded = true;
}

Texture::~Texture() {
    if (textureLoaded)
        glDeleteTextures(1, &texture);
}

Texture::Texture(const std::string &path) {
    loadBMP(path);
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
    textureLoaded =  vbo.textureLoaded;
    vbo.textureLoaded = false;
}

void Texture::applySampler(const Sampler &sampler) {
    glTextureParameteri(texture, GL_TEXTURE_MIN_FILTER, sampler.minFilter);
    glTextureParameteri(texture, GL_TEXTURE_MAG_FILTER, sampler.magFilter);
    glTextureParameteri(texture, GL_TEXTURE_WRAP_S, sampler.wrapS);
    glTextureParameteri(texture, GL_TEXTURE_WRAP_T, sampler.wrapT);
}

void Texture::loadBMP(const std::string &path) {
    init();

    unsigned char *rgb = stbi_load(path.c_str(), &width, &height, &bitPerPixel, 3);

    if (rgb == nullptr)
        throw Blob::Core::Exception("Fail to load Texture : " + path);

    glTextureStorage2D(texture, 1, GL_RGB8, width, height);
    glTextureSubImage2D(texture, 0, 0, 0, width, height, GL_RGB, GL_UNSIGNED_BYTE, rgb);

    stbi_image_free(rgb);
}

void Texture::setRGBA32data(uint8_t *pixels, unsigned int width, unsigned int height) {
    init();

    this->width = width;
    this->height = height;

    glTextureStorage2D(texture, 1, GL_RGBA8, width, height);
    glTextureSubImage2D(texture, 0, 0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, pixels);

    textureLoaded = true;
}

void Texture::setImage(const std::string &path) {
    init();

    unsigned char *rgb = stbi_load(path.c_str(), &width, &height, &bitPerPixel, 3);

    if (rgb == nullptr)
        throw Blob::Core::Exception("Fail to load Texture : " + path);

    glTextureStorage2D(texture, 1, GL_RGB8, width, height);
    glTextureSubImage2D(texture, 0, 0, 0, width, height, GL_RGB, GL_UNSIGNED_BYTE, rgb);

    stbi_image_free(rgb);
}

unsigned int Texture::getTextureID() const {
    return texture;
}

Maths::Vec2<int> Texture::getTextureSize() const {
    return {width, height};
}

} // namespace Blob::GL

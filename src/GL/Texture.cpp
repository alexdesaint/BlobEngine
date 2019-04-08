#include <Blob/GL/Texture.hpp>
#include <Blob/Exception.hpp>

#include <glad/glad.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <vector>

namespace Blob::GL {

    void Texture::init(){
        if (textureLoaded)
            glDeleteTextures(1, &texture);

        glCreateTextures(GL_TEXTURE_2D, 1, &texture);
        textureLoaded = true;
	}

	Texture::Texture(const std::string &path, bool nearest) {
		loadBMP(path, nearest);
	}

	Texture::Texture(uint8_t r, uint8_t g, uint8_t b) {
		setColor(r, g, b);
	}

	Texture::~Texture() {
        if(textureLoaded)
		    glDeleteTextures(1, &texture);
	}

	void Texture::loadBMP(const std::string &path, bool nearest) {
        init();

		unsigned char* rgb = stbi_load(path.c_str(), &width, &height, &bitPerPixel, 3);

		if (rgb == nullptr) {
			throw Exception("Fail to load Texture : " + path);
		}

		glTextureStorage2D(texture, 1, GL_RGB8, width, height);
		glTextureSubImage2D(texture, 0, 0, 0, width, height, GL_RGB, GL_UNSIGNED_BYTE, rgb);
		if (nearest) {
			glTextureParameteri(texture, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTextureParameteri(texture, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		} else {
			glTextureParameteri(texture, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTextureParameteri(texture, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		}

		stbi_image_free( rgb );
	}

	void Texture::setColor(uint8_t r, uint8_t g, uint8_t b) {
        init();

		uint8_t color[3] = {r, g, b};
		this->width = 1;
		this->height = 1;
		glTextureStorage2D(texture, 1, GL_RGB8, 1, 1);
		glTextureSubImage2D(texture, 0, 0, 0, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, color);
		glTextureParameteri(texture, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTextureParameteri(texture, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	}

	void Texture::setRGBA32data(uint8_t *pixels, unsigned int width, unsigned int height, bool nearest) {
        init();

		this->width = width;
		this->height = height;

		glTextureStorage2D(texture, 1, GL_RGBA8, width, height);
		glTextureSubImage2D(texture, 0, 0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
		if (nearest) {
			glTextureParameteri(texture, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTextureParameteri(texture, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		} else {
			glTextureParameteri(texture, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTextureParameteri(texture, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		}

		textureLoaded = true;
	}

	unsigned int Texture::getTextureID() const {
		return texture;
	}

	Vec2f Texture::getTextureSize() const {
		return {(float)width, (float)height};
	}
}
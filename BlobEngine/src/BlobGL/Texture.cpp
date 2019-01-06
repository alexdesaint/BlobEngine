#include <BlobEngine/BlobGL/Texture.hpp>
#include <BlobEngine/BlobException.hpp>

#include <glad/glad.h>
#include <libbmpread/bmpread.h>

#include <vector>

namespace BlobEngine::BlobGL {

	Texture::Texture() {
		glCreateTextures(GL_TEXTURE_2D, 1, &texture);
		//glCreateSamplers(1, &sampler);
	}

	Texture::Texture(const std::string &path) {
		glCreateTextures(GL_TEXTURE_2D, 1, &texture);
		loadBMPtexture(path);
	}

	Texture::Texture(int8_t r, int8_t g, int8_t b) {
		glCreateTextures(GL_TEXTURE_2D, 1, &texture);

		setColor(r, g, b);
	}

	Texture::~Texture() {
		glDeleteTextures(1, &texture);
		//glDeleteSamplers(1, &sampler);
	}

	void Texture::loadBMPtexture(const std::string &path) {
		/*glSamplerParameteri(sampler, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glSamplerParameteri(sampler, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glSamplerParameteri(sampler, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glSamplerParameteri(sampler, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glBindSampler(0, sampler);*/

		bmpread_t bitmap;

		if(!bmpread(path.c_str(), 0, &bitmap)) {
			throw BlobException("Texture not loaded : " + path);
		}

		glTextureStorage2D(texture, 1, GL_RGB8, bitmap.width, bitmap.height);
		glTextureSubImage2D(texture, 0, 0, 0, bitmap.width, bitmap.height, GL_RGB, GL_UNSIGNED_BYTE, bitmap.data);
		glTextureParameteri(texture, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTextureParameteri(texture, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		bmpread_free(&bitmap);
	}

	void Texture::setDepth(unsigned int x, unsigned int y) {
		depth = true;

		glTextureStorage2D(texture, 1,  GL_DEPTH_COMPONENT16, x, y);
		glTextureSubImage2D(texture, 0, 0, 0, x, y, GL_DEPTH_COMPONENT, GL_FLOAT, nullptr);
		glTextureParameteri(texture, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTextureParameteri(texture, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	}

	unsigned int Texture::getTexture() const {
		return texture;
	}

	void Texture::setColor(int8_t r, int8_t g, int8_t b) {
		int8_t color[3] = {r, g, b};

		glTextureStorage2D(texture, 1, GL_RGB8, 1, 1);
		glTextureSubImage2D(texture, 0, 0, 0, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, color);
		glTextureParameteri(texture, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTextureParameteri(texture, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	}
}
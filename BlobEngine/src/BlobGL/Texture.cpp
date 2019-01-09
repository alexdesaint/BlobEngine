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

	Texture::Texture(uint8_t r, uint8_t g, uint8_t b) {
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

		if(textureLoaded)
			reset();
		else
			textureLoaded = true;


		bmpread_t bitmap;

		if(!bmpread(path.c_str(), BMPREAD_TOP_DOWN, &bitmap)) {
			throw BlobException("Fail to load Texture : " + path);
		}

		glTextureStorage2D(texture, 1, GL_RGB8, bitmap.width, bitmap.height);
		glTextureSubImage2D(texture, 0, 0, 0, bitmap.width, bitmap.height, GL_RGB, GL_UNSIGNED_BYTE, bitmap.data);
		glTextureParameteri(texture, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(texture, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		bmpread_free(&bitmap);
	}

	void Texture::setColor(uint8_t r, uint8_t g, uint8_t b) {

		if(textureLoaded)
			reset();
		else
			textureLoaded = true;

		uint8_t color[3] = {r, g, b};

		glTextureStorage2D(texture, 1, GL_RGB8, 1, 1);
		glTextureSubImage2D(texture, 0, 0, 0, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, color);
		glTextureParameteri(texture, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTextureParameteri(texture, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	}

	void Texture::reset() {
		glDeleteTextures(1, &texture);
		glCreateTextures(GL_TEXTURE_2D, 1, &texture);
	}

	unsigned int Texture::getTexture() const {
		return texture;
	}

	void Texture::setTextureScale(float textureScale) {
		Texture::textureScale = textureScale;
	}

	/*void Texture::setDepth(unsigned int x, unsigned int y) {
		depth = true;

		glTextureStorage2D(texture, 1,  GL_DEPTH_COMPONENT16, x, y);
		glTextureSubImage2D(texture, 0, 0, 0, x, y, GL_DEPTH_COMPONENT, GL_FLOAT, nullptr);
		glTextureParameteri(texture, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTextureParameteri(texture, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	}*/
}
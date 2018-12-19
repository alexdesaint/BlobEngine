#include <BlobEngine/BlobGL/Texture.hpp>

#include <glad/glad.h>
#include <SFML/Graphics/Image.hpp>

#include <BlobEngine/BlobException.hpp>
#include <vector>

namespace BlobEngine::BlobGL {

	Texture::Texture() {
		glCreateTextures(GL_TEXTURE_2D, 1, &texture);
		//glCreateSamplers(1, &sampler);
	}

	Texture::~Texture() {
		glDeleteTextures(1, &texture);
		//glDeleteSamplers(1, &sampler);
	}

	void Texture::load(std::string path) {
		/*glSamplerParameteri(sampler, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glSamplerParameteri(sampler, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glSamplerParameteri(sampler, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glSamplerParameteri(sampler, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glBindSampler(0, sampler);*/



		/*std::vector<GLubyte> image = {
				255, 0, 0, 255, 		0, 255, 0, 255, 		0, 0, 255, 255,
				255, 0, 0, 255, 		0, 255, 0, 255, 		0, 0, 255, 255,
				255, 0, 0, 255, 		0, 255, 0, 255, 		0, 0, 255, 255,
		};

		unsigned int width = 3, height = 3;*/

		sf::Image img_data;
		if (!img_data.loadFromFile(path))
			throw BlobException("Texture not loaded");

		glTextureStorage2D(texture, 1, GL_RGBA8, img_data.getSize().x, img_data.getSize().y);
		glTextureSubImage2D(texture, 0, 0, 0, img_data.getSize().x, img_data.getSize().y, GL_RGBA, GL_UNSIGNED_BYTE, img_data.getPixelsPtr());
		glTextureParameteri(texture, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTextureParameteri(texture, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	}
}
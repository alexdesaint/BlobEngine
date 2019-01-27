#ifndef BLOBENGINE_TEXTURE_HPP
#define BLOBENGINE_TEXTURE_HPP

#include <string>

namespace BlobEngine::BlobGL {

	class Graphic;

	class Texture {
		friend Graphic;
	private:

		unsigned int texture;//, sampler;

		float textureScale = 1;

		bool depth = false, textureLoaded = false;

	public:
		Texture();

		Texture(const std::string &path, bool nearest = false);

		Texture(uint8_t r, uint8_t g, uint8_t b);

		void loadBMP(const std::string &path, bool nearest = false);

		void setColor(uint8_t r, uint8_t g, uint8_t b);

		void setRGBA32data(uint8_t *pixels, int width, int height, bool nearest = false);

		unsigned int getTextureID() const;

		void reset();

		void setTextureScale(float textureScale);

		~Texture();
	};
}

#endif

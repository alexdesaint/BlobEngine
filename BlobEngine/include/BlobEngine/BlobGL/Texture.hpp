#ifndef BLOBENGINE_TEXTURE_HPP
#define BLOBENGINE_TEXTURE_HPP

#include <string>

namespace BlobEngine::BlobGL {

	class Graphic;

	class Texture {
		friend Graphic;
	private:

		unsigned int texture;//, sampler;

		bool depth = false, textureLoaded = false;

	public:
		Texture();

		explicit Texture(const std::string &path);

		Texture(uint8_t r, uint8_t g, uint8_t b);

		unsigned int getTexture() const;

		void loadBMPtexture(const std::string &path);

		void setColor(uint8_t r, uint8_t g, uint8_t b);

		//void setDepth(unsigned int x, unsigned int y);

		void reset();

		~Texture();
	};
}

#endif

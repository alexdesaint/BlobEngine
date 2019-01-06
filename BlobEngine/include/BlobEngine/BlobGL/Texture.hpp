#ifndef BLOBENGINE_TEXTURE_HPP
#define BLOBENGINE_TEXTURE_HPP

#include <string>

namespace BlobEngine::BlobGL {

	class Graphic;

	class Texture {
		friend Graphic;
	private:

		unsigned int texture, sampler;

		bool depth = false;

	public:
		Texture();

		explicit Texture(const std::string &path);

		Texture(int8_t r, int8_t g, int8_t b);

		unsigned int getTexture() const;

		void loadBMPtexture(const std::string &path);

		void setColor(int8_t r, int8_t g, int8_t b);

		void setDepth(unsigned int x, unsigned int y);

		~Texture();

	};
}

#endif

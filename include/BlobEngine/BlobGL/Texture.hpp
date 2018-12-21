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

		unsigned int getTexture() const;

		void load(std::string path);

		void setDepth(unsigned int x, unsigned int y);

		~Texture();

	};
}

#endif

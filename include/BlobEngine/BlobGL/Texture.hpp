#ifndef BLOBENGINE_TEXTURE_HPP
#define BLOBENGINE_TEXTURE_HPP

#include <string>

namespace BlobEngine::BlobGL {

	class Graphic;

	class Texture {
		friend Graphic;
	private:

		unsigned int texture, sampler;

	public:
		void load(std::string path);

		Texture();
		~Texture();

	};
}

#endif

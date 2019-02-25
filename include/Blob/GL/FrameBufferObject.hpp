#ifndef BLOBENGINE_FRAMEBUFFEROBJECT_HPP
#define BLOBENGINE_FRAMEBUFFEROBJECT_HPP

#include <Blob/GL/Texture.hpp>

namespace Blob::GL {

	class FrameBufferObject {
	private:
		unsigned int frameBufferObject = 0;

	public:
		FrameBufferObject();

		~FrameBufferObject();

		void addTexture(Texture t);

		unsigned int getFrameBufferObject() const;
	};
}

#endif //BLOBENGINE_FRAMEBUFFEROBJECT_HPP

#ifndef BLOBENGINE_FRAMEBUFFEROBJECT_HPP
#define BLOBENGINE_FRAMEBUFFEROBJECT_HPP

#include <glad/glad.h>
#include "Texture.hpp"

namespace BlobEngine::BlobGL {

	class FrameBufferObject {
	private:
		GLuint frameBufferObject = 0;

	public:
		FrameBufferObject() {
			glGenFramebuffers(1, &frameBufferObject);
		}

		~FrameBufferObject() {
			glDeleteFramebuffers(&frameBufferObject);
		}

		void addTexture(Texture t) {
			glNamedFramebufferTexture(frameBufferObject, GL_DEPTH_ATTACHMENT, t.getTexture(), 0);

			glNamedFramebufferDrawBuffer(frameBufferObject, GL_NONE);
			glNamedFramebufferReadBuffer(frameBufferObject, GL_NONE);
		}
	};
}

#endif //BLOBENGINE_FRAMEBUFFEROBJECT_HPP

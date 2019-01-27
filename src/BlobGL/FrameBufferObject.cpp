#include <BlobEngine/BlobGL/FrameBufferObject.hpp>

#include <glad/glad.h>

namespace BlobEngine::BlobGL {

	FrameBufferObject::FrameBufferObject() {
		glGenFramebuffers(1, &frameBufferObject);
	}

	FrameBufferObject::~FrameBufferObject() {
		glDeleteFramebuffers(1, &frameBufferObject);
	}

	void FrameBufferObject::addTexture(Texture t) {
		glNamedFramebufferTexture(frameBufferObject, GL_DEPTH_ATTACHMENT, t.getTextureID(), 0);

		glNamedFramebufferDrawBuffer(frameBufferObject, GL_NONE);
		glNamedFramebufferReadBuffer(frameBufferObject, GL_NONE);
	}

	GLuint FrameBufferObject::getFrameBufferObject() const {
		return frameBufferObject;
	}
}
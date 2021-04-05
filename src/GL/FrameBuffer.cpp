#include <Blob/GL/FrameBuffer.hpp>

#include <glad/glad.h>

namespace Blob::GL {

FrameBuffer::FrameBuffer() {
    glCreateFramebuffers(1, &frameBufferObject);
}

FrameBuffer::~FrameBuffer() {
    glDeleteFramebuffers(1, &frameBufferObject);
}

const FrameBuffer::Attachment FrameBuffer::NONE = GL_NONE;
const FrameBuffer::Attachment FrameBuffer::COLOR_ATTACHMENT0 = GL_COLOR_ATTACHMENT0;
const FrameBuffer::Attachment FrameBuffer::COLOR_ATTACHMENT1 = GL_COLOR_ATTACHMENT1;
const FrameBuffer::Attachment FrameBuffer::COLOR_ATTACHMENT2 = GL_COLOR_ATTACHMENT2;
const FrameBuffer::Attachment FrameBuffer::COLOR_ATTACHMENT3 = GL_COLOR_ATTACHMENT3;
const FrameBuffer::Attachment FrameBuffer::COLOR_ATTACHMENT4 = GL_COLOR_ATTACHMENT4;
const FrameBuffer::Attachment FrameBuffer::COLOR_ATTACHMENT5 = GL_COLOR_ATTACHMENT5;
const FrameBuffer::Attachment FrameBuffer::COLOR_ATTACHMENT6 = GL_COLOR_ATTACHMENT6;
const FrameBuffer::Attachment FrameBuffer::COLOR_ATTACHMENT7 = GL_COLOR_ATTACHMENT7;
const FrameBuffer::Attachment FrameBuffer::COLOR_ATTACHMENT8 = GL_COLOR_ATTACHMENT8;
const FrameBuffer::Attachment FrameBuffer::COLOR_ATTACHMENT9 = GL_COLOR_ATTACHMENT9;
const FrameBuffer::Attachment FrameBuffer::COLOR_ATTACHMENT10 = GL_COLOR_ATTACHMENT10;
const FrameBuffer::Attachment FrameBuffer::COLOR_ATTACHMENT11 = GL_COLOR_ATTACHMENT11;
const FrameBuffer::Attachment FrameBuffer::COLOR_ATTACHMENT12 = GL_COLOR_ATTACHMENT12;
const FrameBuffer::Attachment FrameBuffer::COLOR_ATTACHMENT13 = GL_COLOR_ATTACHMENT13;
const FrameBuffer::Attachment FrameBuffer::COLOR_ATTACHMENT14 = GL_COLOR_ATTACHMENT14;
const FrameBuffer::Attachment FrameBuffer::COLOR_ATTACHMENT15 = GL_COLOR_ATTACHMENT15;
const FrameBuffer::Attachment FrameBuffer::COLOR_ATTACHMENT16 = GL_COLOR_ATTACHMENT16;
const FrameBuffer::Attachment FrameBuffer::COLOR_ATTACHMENT17 = GL_COLOR_ATTACHMENT17;
const FrameBuffer::Attachment FrameBuffer::COLOR_ATTACHMENT18 = GL_COLOR_ATTACHMENT18;
const FrameBuffer::Attachment FrameBuffer::COLOR_ATTACHMENT19 = GL_COLOR_ATTACHMENT19;
const FrameBuffer::Attachment FrameBuffer::COLOR_ATTACHMENT20 = GL_COLOR_ATTACHMENT20;
const FrameBuffer::Attachment FrameBuffer::COLOR_ATTACHMENT21 = GL_COLOR_ATTACHMENT21;
const FrameBuffer::Attachment FrameBuffer::COLOR_ATTACHMENT22 = GL_COLOR_ATTACHMENT22;
const FrameBuffer::Attachment FrameBuffer::COLOR_ATTACHMENT23 = GL_COLOR_ATTACHMENT23;
const FrameBuffer::Attachment FrameBuffer::COLOR_ATTACHMENT24 = GL_COLOR_ATTACHMENT24;
const FrameBuffer::Attachment FrameBuffer::COLOR_ATTACHMENT25 = GL_COLOR_ATTACHMENT25;
const FrameBuffer::Attachment FrameBuffer::COLOR_ATTACHMENT26 = GL_COLOR_ATTACHMENT26;
const FrameBuffer::Attachment FrameBuffer::COLOR_ATTACHMENT27 = GL_COLOR_ATTACHMENT27;
const FrameBuffer::Attachment FrameBuffer::COLOR_ATTACHMENT28 = GL_COLOR_ATTACHMENT28;
const FrameBuffer::Attachment FrameBuffer::COLOR_ATTACHMENT29 = GL_COLOR_ATTACHMENT29;
const FrameBuffer::Attachment FrameBuffer::COLOR_ATTACHMENT30 = GL_COLOR_ATTACHMENT30;
const FrameBuffer::Attachment FrameBuffer::COLOR_ATTACHMENT31 = GL_COLOR_ATTACHMENT31;
const FrameBuffer::Attachment FrameBuffer::DEPTH_ATTACHMENT = GL_DEPTH_ATTACHMENT;
const FrameBuffer::Attachment FrameBuffer::STENCIL_ATTACHMENT = GL_STENCIL_ATTACHMENT;

void FrameBuffer::attachTexture(const Texture &t, Attachment attachment) const {
    glNamedFramebufferTexture(frameBufferObject, attachment, t.texture, 0);
}

void FrameBuffer::drawBuffer(FrameBuffer::Attachment attachment) const {
    glNamedFramebufferDrawBuffer(frameBufferObject, attachment);
    // GL_NONE
    // GL_FRONT_LEFT
    // GL_FRONT_RIGHT
    // GL_BACK_LEFT
    // GL_BACK_RIGHT
    // GL_FRONT --> defalut
    // GL_BACK
    // GL_LEFT
    // GL_RIGHT
    // GL_FRONT_AND_BACK
    // all GL_COLOR_ATTACHMENT
}

void FrameBuffer::drawBuffer(const std::vector<FrameBuffer::Attachment> &attachments) const {
    glNamedFramebufferDrawBuffers(frameBufferObject, (GLsizei) attachments.size(), attachments.data());
}

void FrameBuffer::readBuffer(FrameBuffer::Attachment attachment) const {
    glNamedFramebufferReadBuffer(frameBufferObject, attachment);
}

void FrameBuffer::bind() const {
    glBindFramebuffer(GL_FRAMEBUFFER, frameBufferObject);
}

} // namespace Blob::GL
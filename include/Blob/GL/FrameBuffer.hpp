#pragma once
#include <Blob/GL/Texture.hpp>

#include <vector>

namespace Blob::GL {

class FrameBuffer {
private:
    unsigned int frameBufferObject = 0;

public:
    FrameBuffer();

    ~FrameBuffer();

    void bind() const;

    typedef unsigned int Attachment;
    static const Attachment NONE;
    static const Attachment COLOR_ATTACHMENT0;
    static const Attachment COLOR_ATTACHMENT1;
    static const Attachment COLOR_ATTACHMENT2;
    static const Attachment COLOR_ATTACHMENT3;
    static const Attachment COLOR_ATTACHMENT4;
    static const Attachment COLOR_ATTACHMENT5;
    static const Attachment COLOR_ATTACHMENT6;
    static const Attachment COLOR_ATTACHMENT7;
    static const Attachment COLOR_ATTACHMENT8;
    static const Attachment COLOR_ATTACHMENT9;
    static const Attachment COLOR_ATTACHMENT10;
    static const Attachment COLOR_ATTACHMENT11;
    static const Attachment COLOR_ATTACHMENT12;
    static const Attachment COLOR_ATTACHMENT13;
    static const Attachment COLOR_ATTACHMENT14;
    static const Attachment COLOR_ATTACHMENT15;
    static const Attachment COLOR_ATTACHMENT16;
    static const Attachment COLOR_ATTACHMENT17;
    static const Attachment COLOR_ATTACHMENT18;
    static const Attachment COLOR_ATTACHMENT19;
    static const Attachment COLOR_ATTACHMENT20;
    static const Attachment COLOR_ATTACHMENT21;
    static const Attachment COLOR_ATTACHMENT22;
    static const Attachment COLOR_ATTACHMENT23;
    static const Attachment COLOR_ATTACHMENT24;
    static const Attachment COLOR_ATTACHMENT25;
    static const Attachment COLOR_ATTACHMENT26;
    static const Attachment COLOR_ATTACHMENT27;
    static const Attachment COLOR_ATTACHMENT28;
    static const Attachment COLOR_ATTACHMENT29;
    static const Attachment COLOR_ATTACHMENT30;
    static const Attachment COLOR_ATTACHMENT31;
    static const Attachment DEPTH_ATTACHMENT;
    static const Attachment STENCIL_ATTACHMENT;

    void attachTexture(const Texture &t, Attachment attachment) const;
    void drawBuffer(Attachment attachment) const;
    void drawBuffer(const std::vector<Attachment> &attachments) const;
    void readBuffer(Attachment attachment) const;
};
} // namespace Blob::GL

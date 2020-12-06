#pragma once

#include <Blob/Maths.inl>
#include <string>

namespace Blob::GL {

struct Sampler {
    enum FILTER {
        NEAREST = 0x2600,
        LINEAR = 0x2601,
        NEAREST_MIPMAP_NEAREST = 0x2700,
        LINEAR_MIPMAP_NEAREST = 0x2701,
        NEAREST_MIPMAP_LINEAR = 0x2702,
        LINEAR_MIPMAP_LINEAR = 0x2703
    };
    enum WRAP { CLAMP_TO_EDGE = 0x812F, CLAMP_TO_BORDER = 0x812D, MIRRORED_REPEAT = 0x8370, REPEAT = 0x2901, MIRROR_CLAMP_TO_EDGE = 0x8743 };

    FILTER magFilter = LINEAR;
    FILTER minFilter = NEAREST_MIPMAP_LINEAR;
    WRAP wrapS = REPEAT;
    WRAP wrapT = REPEAT;

    Sampler() = default;
    Sampler(FILTER magFilter, FILTER minFilter) : magFilter(magFilter), minFilter(minFilter) {}
    Sampler(WRAP wrapS, WRAP wrapT) : wrapS(wrapS), wrapT(wrapT) {}
    Sampler(FILTER magFilter, FILTER minFilter, WRAP wrapS, WRAP wrapT) : magFilter(magFilter), minFilter(minFilter), wrapS(wrapS), wrapT(wrapT) {}
};

class Texture {
    friend class Material;
    friend class FrameBuffer;

private:
    uint32_t texture = 0; // the opengl texture

protected:
    Maths::Vec2<unsigned int> size;

public:
    Texture() = default;

    Texture(const Texture &) = delete;

    Texture(Texture &&vbo) noexcept;

    ~Texture();

    void applySampler(const Sampler &sampler);

    void setRGB8data(uint8_t *pixels, Maths::Vec2<unsigned int> size);

    void setRGBA8data(uint8_t *pixels, Maths::Vec2<unsigned int> size);

    void setRGBA16data(uint8_t *pixels, Maths::Vec2<unsigned int> size);

    [[nodiscard]] Maths::Vec2<unsigned int> getTextureSize() const;
};
} // namespace Blob::GL

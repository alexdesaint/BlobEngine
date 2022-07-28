#pragma once

#include <Blob/Buffer.hpp>
#include <Blob/Maths.hpp>
#include <bgfx/bgfx.h>

namespace Blob {

class Texture {
public:
    bgfx::TextureHandle textureHandle;

    Texture() = default;
    Texture(const Buffer &buffer,
            const Vec2<size_t> &size,
            bgfx::TextureFormat::Enum textureFormat) {
        setImage(buffer, size, textureFormat);
    }
    ~Texture();

    void setImage(const Buffer &buffer,
                  const Vec2<size_t> &size,
                  bgfx::TextureFormat::Enum textureFormat);

    Vec2<size_t> getTextureSize() const { return {}; }
};

} // namespace Blob

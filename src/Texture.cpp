#include <Blob/Texture.hpp>

namespace Blob {

Texture::~Texture() { bgfx::destroy(textureHandle); }

void Texture::setImage(const Buffer &buffer, const Vec2<size_t> &size, bgfx::TextureFormat::Enum textureFormat) {
    textureHandle = bgfx::createTexture2D(size.x, size.y, false, 1, textureFormat, BGFX_TEXTURE_NONE, buffer.memory);
}

} // namespace Blob

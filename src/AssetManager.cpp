#include <Blob/AssetManager.hpp>

namespace Blob {
AssetManager::AssetManager() {
    Shaders::SingleColor::instance.build();
    Shaders::PBRSingleColor::instance.build();
    Shaders::PBRSingleTexture::instance.build();
    Shaders::PBRColorArray::instance.build();
}
} // namespace Blob
#include <Blob/AssetManager.hpp>

namespace Blob {
AssetManager::AssetManager() {
    Shaders::SingleColor::instance.build();
    Shaders::SingleTexture::instance.build();

    Shaders::PerFaceNormal::instance.build();
    Shaders::Deferred::instance.build();

    Shaders::PBRSingleColor::instance.build();
    Shaders::PBRSingleTexture::instance.build();
    Shaders::PBRColorArray::instance.build();
    Shaders::PBRWater::instance.build();
}

AssetManager::~AssetManager() {
    Shaders::SingleColor::instance.destroy();
    Shaders::SingleTexture::instance.destroy();

    Shaders::PerFaceNormal::instance.destroy();
    Shaders::Deferred::instance.destroy();

    Shaders::PBRSingleColor::instance.destroy();
    Shaders::PBRSingleTexture::instance.destroy();
    Shaders::PBRColorArray::instance.destroy();
    Shaders::PBRWater::instance.destroy();
}
} // namespace Blob
#pragma once

#include <Blob/Core/FilePath.hpp>
#include <Blob/Core/Image.hpp>
#include <Blob/GL/Texture.hpp>
#include <memory>

namespace Blob {

class Texture : public GL::Texture {
public:
    Texture() = default;
    explicit Texture(const std::string &path);
    Texture(const std::string &path, GL::Sampler sampler);
    explicit Texture(const Image &image);
    Texture(const Image &image, GL::Sampler sampler);
    void setImage(const std::string &path);
    void setImage(const Image &image);
};

template<FilePath... filepath>
class TextureAsset {
private:
    inline static std::weak_ptr<Texture> instance;

public:
    struct Instance : public std::shared_ptr<Texture> {
        using std::shared_ptr<Texture>::operator=;
        Instance() : std::shared_ptr<Texture>() {
            this->operator=(instance.lock());
            if (!*this) {
                std::string path;
                ((path += std::string(filepath.value)), ...);
                this->operator=(std::make_shared<Texture>(path));
            }
        }
    };

    static auto isInstancied() { return (bool) instance.lock(); }

    static auto getUseCount() { return instance.use_count(); }
};

} // namespace Blob
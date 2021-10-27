#pragma once

#include "Blob/Maths.inl"
#include <Blob/Core/Material.hpp>
#include <Blob/Shaders.hpp>
#include <Blob/Shaders2D.hpp>

namespace Blob::Materials2D {

class SingleColor : public Material2D {
private:
    Blob::Shaders2D::SingleColor::Intance shader =
        Blob::Shaders2D::SingleColor::getInstance();

    void applyMaterial(const ProjectionTransform2D &pt,
                       const ViewTransform2D &vt,
                       const Mat3 &mt) const final;

public:
    Color::RGBA albedo = {1.f, 1.f, 1.f, 1.f};

    SingleColor() = default;
    explicit SingleColor(Color::RGBA albedo) : albedo(albedo) {}
    explicit SingleColor(Color::RGB albedo, float alpha = 1.f) :
        albedo(albedo, alpha) {}
};

class SingleColorSingleTexture : public Material2D {
private:
    Blob::Shaders2D::SingleColorSingleTexture::Intance shader =
        Blob::Shaders2D::SingleColorSingleTexture::getInstance();
    void applyMaterial(const ProjectionTransform2D &pt,
                       const ViewTransform2D &vt,
                       const Mat3 &mt) const final;

public:
    const Texture &texture;
    Color::RGBA albedo = {1.f, 1.f, 1.f, 1.f};
    Vec2<size_t> texturePosition, textureSize;
    explicit SingleColorSingleTexture(const Texture &texture) :
        texture(texture), textureSize(texture.getTextureSize()) {}
    SingleColorSingleTexture(const Texture &texture,
                             Vec2<size_t> texturePosition,
                             Vec2<size_t> textureSize) :
        texture(texture),
        texturePosition(texturePosition),
        textureSize(textureSize) {}
    SingleColorSingleTexture(const Texture &texture,
                             const Color::RGBA &albedo) :
        texture(texture),
        albedo(albedo),
        textureSize(texture.getTextureSize()) {}
    SingleColorSingleTexture(const Texture &texture,
                             Vec2<size_t> texturePosition,
                             Vec2<size_t> textureSize,
                             const Color::RGBA &albedo) :
        texture(texture),
        texturePosition(texturePosition),
        textureSize(textureSize),
        albedo(albedo) {}
};

} // namespace Blob::Materials2D
namespace Blob::Materials {

class SingleColor : public Material {
private:
    Blob::Shaders::SingleColor::Intance shader =
        Blob::Shaders::SingleColor::getInstance();
    void applyMaterial(const ProjectionTransform &pt,
                       const ViewTransform &vt,
                       const Mat4 &mt) const final;

public:
    Color::RGBA albedo = {1.0f, 0.5f, 0.31f};

    SingleColor() = default;
    explicit SingleColor(Color::RGBA albedo) : albedo(albedo) {}
};

class SingleTexture : public Material {
private:
    Blob::Shaders::SingleTexture::Intance shader =
        Blob::Shaders::SingleTexture::getInstance();
    const Texture &texture;

    void applyMaterial(const ProjectionTransform &pt,
                       const ViewTransform &vt,
                       const Mat4 &mt) const final;

public:
    Vec2<> texScale;

    explicit SingleTexture(const Texture &texture,
                           const Vec2<> &texScale = {1.f, 1.f}) :
        texture(texture) {}
};

class PerFaceNormal : public Material {
private:
    Blob::Shaders::PerFaceNormal::Intance shader =
        Blob::Shaders::PerFaceNormal::getInstance();
    void applyMaterial(const ProjectionTransform &pt,
                       const ViewTransform &vt,
                       const Mat4 &mt) const final;

public:
    Color::RGBA albedo = {1.0f, 0.5f, 0.31f};
    float length = 1.f;

    PerFaceNormal() = default;
    explicit PerFaceNormal(Color::RGBA albedo) : albedo(albedo) {}
};

struct Light {
    Vec3<float> position = {0.f, 0.f, 2.0f};
    Color::RGB color = {1.f, 1.f, 1.f};
    float power = 1000.f;
    float radius = 0.1f;
};

class PBR {
public:
    static Light light;

    float metallic = 0;
    float roughness = 0;
    float ao = 1;

    virtual ~PBR() noexcept = default;
};

/// A Material to draw in a single color
class PBRSingleColor : public Material, public PBR {
private:
    Blob::Shaders::PBR::SingleColor::Intance shader =
        Blob::Shaders::PBR::SingleColor::getInstance();
    void applyMaterial(const ProjectionTransform &pt,
                       const ViewTransform &vt,
                       const Mat4 &mt) const final;

public:
    Color::RGBA albedo = {1.0f, 0.5f, 0.31f};

    PBRSingleColor() = default;
    explicit PBRSingleColor(Color::RGBA albedo) : albedo(albedo) {}
};

class PBRSingleColorInstanced : public Material, public PBR {
private:
    Blob::Shaders::PBR::SingleColorInstanced::Intance shader =
        Blob::Shaders::PBR::SingleColorInstanced::getInstance();
    void applyMaterial(const ProjectionTransform &pt,
                       const ViewTransform &vt,
                       const Mat4 &mt) const final;

public:
    Color::RGBA albedo = {1.0f, 0.5f, 0.31f};

    PBRSingleColorInstanced() = default;
    explicit PBRSingleColorInstanced(Color::RGBA albedo) : albedo(albedo) {}
};

class PBRSingleTexture : public Material, public PBR {
private:
    Blob::Shaders::PBR::SingleTexture::Intance shader =
        Blob::Shaders::PBR::SingleTexture::getInstance();
    const Texture &texture;

    void applyMaterial(const ProjectionTransform &pt,
                       const ViewTransform &vt,
                       const Mat4 &mt) const final;

public:
    Vec2<> texScale = {1.f, 1.f};

    explicit PBRSingleTexture(const Texture &texture) : texture(texture) {}
};

class PBRColorArray : public Material, public PBR {
private:
    Blob::Shaders::PBR::ColorArray::Intance shader =
        Blob::Shaders::PBR::ColorArray::getInstance();
    void applyMaterial(const ProjectionTransform &pt,
                       const ViewTransform &vt,
                       const Mat4 &mt) const final;

public:
    PBRColorArray() = default;
};

class PBRWater : public Material, public PBR {
private:
    Blob::Shaders::PBR::Water::Intance shader =
        Blob::Shaders::PBR::Water::getInstance();
    void applyMaterial(const ProjectionTransform &pt,
                       const ViewTransform &vt,
                       const Mat4 &mt) const final;

public:
    Color::RGBA albedo = {0.f, 0.f, 1.f, 0.5f};

    PBRWater() = default;
    explicit PBRWater(const Color::RGBA &albedo) : albedo(albedo) {}
};

} // namespace Blob::Materials
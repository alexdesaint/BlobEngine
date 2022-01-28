#pragma once

#include <Blob/Material.hpp>
#include <Blob/Maths.hpp>

namespace Blob::Materials2D {

using UniformAlbedo = UniformAttribute<Color::RGBA, 3>;
using UniformTextureScale = UniformAttribute<Vec2<>, 4>;

class SingleColor : public Material {
private:
    using MaterialShader = Shader<UniformAlbedo>;
    MaterialShader::Instance shader;

    void applyMaterial() const final;

public:
    Color::RGBA albedo;

    SingleColor(const Color::RGBA &albedo = {1.f, 1.f, 1.f, 1.f});
};

class SingleColorSingleTexture : public Material {
private:
    using MaterialShader = Shader<UniformAlbedo>;
    MaterialShader::Instance shader;
    void applyMaterial() const final;

public:
    const Texture &texture;
    Color::RGBA albedo;

    SingleColorSingleTexture(const Texture &texture,
                             const Color::RGBA &albedo = {1.f, 1.f, 1.f, 1.f});
};

} // namespace Blob::Materials2D
namespace Blob::Materials {

using UniformAlbedo = UniformAttribute<Color::RGBA, 3>;
using UniformTextureScale = UniformAttribute<Vec2<>, 4>;

using UniformMetallic = UniformAttribute<float, 5>;
using UniformRoughness = UniformAttribute<float, 6>;
using UniformAo = UniformAttribute<float, 7>;

using UniformLightPosition = UniformAttribute<Vec3<float>, 8>;
using UniformLightColor = UniformAttribute<Color::RGB, 9>;
using UniformLightRadius = UniformAttribute<float, 10>;
using UniformLightPower = UniformAttribute<float, 11>;

class SingleColor : public Material {
private:
    using MaterialShader = Shader<UniformAlbedo>;
    MaterialShader::Instance shader;
    void applyMaterial() const final;

public:
    Color::RGBA albedo;

    SingleColor(const Color::RGBA &albedo = {1.0f, 0.5f, 0.31f});
};

class SingleTexture : public Material {
private:
    using MaterialShader = Shader<UniformTextureScale>;
    MaterialShader::Instance shader;
    const Texture &texture;

    void applyMaterial() const final;

public:
    Vec2<> texScale;
    Color::RGBA albedo;

    SingleTexture(const Texture &texture,
                  const Vec2<> &texScale = {1.f, 1.f},
                  const Color::RGBA &albedo = {1.0f, 0.5f, 0.31f});
};

class PerFaceNormal : public Material {
private:
    using MaterialShader = Shader<UniformAlbedo, UniformAttribute<float, 4>>;
    MaterialShader::Instance shader;
    void applyMaterial() const final;

public:
    Color::RGBA albedo = {1.0f, 0.5f, 0.31f};
    float length = 1.f;

    explicit PerFaceNormal(const Color::RGBA &albedo) : albedo(albedo) {}
};

struct Light {
    Vec3<float> position = {0.4f, 0.8f, 1.0f};
    Color::RGB color = {1.f, 1.f, 1.f};
    float power = 1.f;
    float radius = 0.1f;
};

class PBR {
public:
    static Light light;

    float metallic = 0;
    float roughness = 0;
    float ao = 0.1;

    virtual ~PBR() noexcept = default;
};

/// A Material to draw in a single color
class PBRSingleColor : public Material, public PBR {
private:
    using MaterialShader = Shader<UniformAlbedo,
                                  UniformMetallic,
                                  UniformRoughness,
                                  UniformAo,
                                  UniformLightPosition,
                                  UniformLightColor,
                                  UniformLightRadius,
                                  UniformLightPower>;
    MaterialShader::Instance shader;
    void applyMaterial() const final;

public:
    Color::RGBA albedo;

    PBRSingleColor(const Color::RGBA &albedo = {1.0f, 0.5f, 0.31f});
};

class PBRSingleColorInstanced : public Material, public PBR {
private:
    using MaterialShader = Shader<UniformAlbedo,
                                  UniformMetallic,
                                  UniformRoughness,
                                  UniformAo,
                                  UniformLightPosition,
                                  UniformLightColor,
                                  UniformLightRadius,
                                  UniformLightPower>;
    MaterialShader::Instance shader;
    void applyMaterial() const final;

public:
    Color::RGBA albedo = {1.0f, 0.5f, 0.31f};

    explicit PBRSingleColorInstanced(const Color::RGBA &albedo) :
        albedo(albedo) {}
};

class PBRSingleTexture : public Material, public PBR {
private:
    using MaterialShader = Shader<UniformTextureScale,
                                  UniformMetallic,
                                  UniformRoughness,
                                  UniformAo,
                                  UniformLightPosition,
                                  UniformLightColor,
                                  UniformLightRadius,
                                  UniformLightPower>;
    MaterialShader::Instance shader;
    const Texture &texture;

    void applyMaterial() const final;

public:
    Vec2<> texScale = {1.f, 1.f};
    Color::RGBA albedo;

    PBRSingleTexture(const Texture &texture,
                     const Vec2<> &texScale = {1.f, 1.f},
                     const Color::RGBA &albedo = {1.0f, 0.5f, 0.31f});
};

class PBRColorArray : public Material, public PBR {
private:
    using MaterialShader = Shader<UniformMetallic,
                                  UniformRoughness,
                                  UniformAo,
                                  UniformLightPosition,
                                  UniformLightColor,
                                  UniformLightRadius,
                                  UniformLightPower>;
    MaterialShader::Instance shader;
    void applyMaterial() const final;

public:
};

class PBRWater : public Material, public PBR {
private:
    using MaterialShader = Shader<UniformAlbedo,
                                  UniformMetallic,
                                  UniformRoughness,
                                  UniformAo,
                                  UniformLightPosition,
                                  UniformLightColor,
                                  UniformLightRadius,
                                  UniformLightPower,
                                  UniformAttribute<float, 11>>;
    MaterialShader::Instance shader;
    void applyMaterial() const final;

public:
    Color::RGBA albedo;

    explicit PBRWater(const Color::RGBA &albedo = {0.f, 0.f, 1.f, 0.5f}) :
        albedo(albedo) {}
};

} // namespace Blob::Materials
#pragma once

#include <Blob/Core/Material.hpp>

namespace Blob::Materials {

class SingleColor : public Core::Material {
private:
    void applyMaterial(const Maths::ProjectionTransform &pt, const Maths::ViewTransform &vt, const Maths::Mat4 &mt) const final;

public:
    Color::RGB albedo = {1.0f, 0.5f, 0.31f};

    SingleColor() = default;
    explicit SingleColor(Color::RGB albedo);
};

class SingleTexture : public Core::Material {
private:
    const Core::Texture *texture;

    void applyMaterial(const Maths::ProjectionTransform &pt, const Maths::ViewTransform &vt, const Maths::Mat4 &mt) const final;

public:
    Maths::Vec2<float> texScale = {1.f, 1.f};

    explicit SingleTexture(const Core::Texture *texture);

    void setTexture1(const Core::Texture *texture);
};

class PerFaceNormal  : public Core::Material {
private:
    void applyMaterial(const Maths::ProjectionTransform &pt, const Maths::ViewTransform &vt, const Maths::Mat4 &mt) const final;

public:
    Color::RGB albedo = {1.0f, 0.5f, 0.31f};
    float length = 1.f;

    PerFaceNormal() = default;
    explicit PerFaceNormal(Color::RGB albedo);
};

struct Light {
    Maths::Vec3<float> position = {0.f, 0.f, 2.0f};
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
class PBRSingleColor : public Core::Material, public PBR {
private:
    void applyMaterial(const Maths::ProjectionTransform &pt, const Maths::ViewTransform &vt, const Maths::Mat4 &mt) const final;

public:
    Color::RGB albedo = {1.0f, 0.5f, 0.31f};

    PBRSingleColor() = default;
    explicit PBRSingleColor(Color::RGB albedo);
};

class PBRSingleTexture : public Core::Material, public PBR {
private:
    const Core::Texture &texture;

    void applyMaterial(const Maths::ProjectionTransform &pt, const Maths::ViewTransform &vt, const Maths::Mat4 &mt) const final;

public:
    Maths::Vec2<float> texScale = {1.f, 1.f};

    explicit PBRSingleTexture(const Core::Texture &texture);
};

class PBRColorArray : public Core::Material, public PBR {
private:
    void applyMaterial(const Maths::ProjectionTransform &pt, const Maths::ViewTransform &vt, const Maths::Mat4 &mt) const final;

public:
    PBRColorArray() = default;
};

class PBRWater : public Core::Material, public PBR {
private:
    void applyMaterial(const Maths::ProjectionTransform &pt, const Maths::ViewTransform &vt, const Maths::Mat4 &mt) const final;

public:
    Color::RGBA albedo = {0.f, 0.f, 1.f, 0.5f};

    PBRWater() = default;
    explicit PBRWater(Color::RGBA albedo);
};

} // namespace Blob::Materials
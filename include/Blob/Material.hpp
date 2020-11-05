#pragma once

#include <Blob/Color.hpp>
#include <Blob/GL/ShaderProgram.hpp>
#include <Blob/GL/Texture.hpp>

namespace Blob::Core {
class Window;
}
namespace Blob::Material {

/// A combinason of shader, color, texture or array to defines the optical properties of an object.
/**
 * Detailed description.
 * - oui
 * - non
 * # Titre
 * > Citation
 * *gras* **pas gras**
 */
class Material {
    friend Blob::Core::Window;

private:
    /// TODO: add Shader Storage Buffer Object for local light sources

    const GL::ShaderProgram &shaderProgramPrivate;

public:
    /// This function will be called before the draw
    /// \param pt oui
    /// \param vt non
    /// \param mt pas toujours
    virtual void applyMaterial(const Maths::ProjectionTransform &pt, const Maths::ViewTransform &vt, const Maths::Mat4 &mt) const = 0;

    /// Constructor
    /// \param shaderProgram yes
    explicit Material(const GL::ShaderProgram &shaderProgram);
};

/*
 * Basic Shaders :
 * Material_POSITION
 * Material_POSITION_NORMAL
 * Material_POSITION_NORMAL_TEXCOORD_0
 * Material_POSITION_NORMAL_COLOR_0
 * Material_POSITION_TEXCOORD_0
 * Material_POSITION_COLOR_0
 */

/// TODO: add simple texture material
/// TODO: remove the DefaultMaterial and set the defaultMaterial to a SingleColorMaterial instance
/// TODO: build material shader from the same const string functions
/// TODO: Create a PBR

class DefaultMaterial : public Material {
private:
    static int model, view, projection;

    void applyMaterial(const Maths::ProjectionTransform &pt, const Maths::ViewTransform &vt, const Maths::Mat4 &mt) const final;

public:
    static GL::ShaderProgram *shaderProgram;

    static DefaultMaterial *defaultMaterial;

    DefaultMaterial();

    static void init();

    static void destroy();
};

struct LightPos {
    int position = -1;
    int color = -1;
};

struct Light {
    Maths::Vec3<float> position = {1.2f, 1.0f, 2.0f};
    Color::RGB color = {1.f, 1.f, 1.f};
};

class PBRMaterial {
public:
    static Light light;
};

/// A Material to draw in a single color
class SingleColorMaterial : public Material, public PBRMaterial {
private:
    static int model, view, projection;

    // texture
    static int albedoPos;
    static int metallicPos;
    static int roughnessPos;
    static int aoPos;

    static int optionsPos;

    static int camPos;

    static LightPos lightPos;

    void applyMaterial(const Maths::ProjectionTransform &pt, const Maths::ViewTransform &vt, const Maths::Mat4 &mt) const final;

public:
    const struct {
        uint32_t Irradiance = 1;
        uint32_t Radiance = 2;
    } Options;

    static GL::ShaderProgram *shaderProgram;

    Color::RGB albedo = {1.0f, 0.5f, 0.31f};
    float metallic = 0;
    float roughness = 0;
    float ao = 1;
    uint32_t options = 0xFFFFFFFF;

    SingleColorMaterial();

    SingleColorMaterial(Color::RGB albedo);

    static void init();

    static void destroy();
};

class SingleTextureMaterial : public Material, public PBRMaterial {
private:
    static int model, view, projection;

    // texture
    static int textureScalePos;
    static int metallicPos;
    static int roughnessPos;
    static int aoPos;

    static int optionsPos;

    static int camPos;

    static LightPos lightPos;

    void applyMaterial(const Maths::ProjectionTransform &pt, const Maths::ViewTransform &vt, const Maths::Mat4 &mt) const final;

public:
    const struct {
        uint32_t Irradiance = 1;
        uint32_t Radiance = 2;
    } Options;

    static GL::ShaderProgram *shaderProgram;

    const Blob::GL::Texture &texture;
    float metallic = 0;
    float roughness = 0;
    float ao = 1;
    uint32_t options = 0xFFFFFFFF;
    Maths::Vec2<float> texScale = {1.f, 1.f};

    explicit SingleTextureMaterial(const Blob::GL::Texture &texture);

    static void init();

    static void destroy();
};
} // namespace Blob::Material

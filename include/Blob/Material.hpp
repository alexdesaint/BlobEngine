#pragma once

#include <Blob/Color.hpp>
#include <Blob/GL/ShaderProgram.hpp>
#include <Blob/GL/Texture.hpp>

#include <Blob/ModelTransform.hpp>
#include <Blob/ProjectionTransform.hpp>
#include <Blob/ViewTransform.hpp>

namespace Blob {

class Window;

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
    friend Window;
private:
    const GL::ShaderProgram &shaderProgramPrivate;

public:
    static Material *defaultMaterial;

    /// This function will be called before the draw
    /// \param pt oui
    /// \param vt non
    /// \param mt pas toujours
    virtual void applyMaterial(const ProjectionTransform &pt, const ViewTransform &vt, const glm::mat4 &mt) const = 0;
    /// Constructor
    /// \param shaderProgram yes
    explicit Material(const GL::ShaderProgram &shaderProgram);
    virtual ~Material() = default;
};

struct LightPos {
    int position = -1;
    int color = -1;
};

struct Light {
    glm::vec3 position = glm::vec3(1.2f, 1.0f, 2.0f);
    Color color = Color(1.f, 1.f, 1.f);
};

class PBRMaterial {
public:
    static Light light;

    float metallic = 0;
    float roughness = 0;
    float ao = 1;

    virtual ~PBRMaterial() = default;
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

    void applyMaterial(const ProjectionTransform &pt, const ViewTransform &vt, const glm::mat4 &mt) const final;

public:
    const struct {
        uint32_t Irradiance = 1;
        uint32_t Radiance = 2;
    } Options;

    static GL::ShaderProgram *shaderProgram;

    Color albedo = Color(1.0f, 0.5f, 0.31f);
    uint32_t options = 0xFFFFFFFF;

    SingleColorMaterial();

    explicit SingleColorMaterial(Color albedo);

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

    void applyMaterial(const ProjectionTransform &pt, const ViewTransform &vt, const glm::mat4 &mt) const final;

public:
    const struct {
        uint32_t Irradiance = 1;
        uint32_t Radiance = 2;
    } Options;

    static GL::ShaderProgram *shaderProgram;

    const Blob::GL::Texture &texture;
    uint32_t options = 0xFFFFFFFF;
    float texScale[2] = {1.f, 1.f};

    explicit SingleTextureMaterial(const Blob::GL::Texture &texture);

    static void init();

    static void destroy();
};

} // namespace Blob

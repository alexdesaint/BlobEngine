#pragma once
#include <Blob/Color.hpp>
#include <Blob/GL/ShaderProgram.hpp>
#include <Blob/GL/Texture.hpp>

#include <Blob/ModelTransform.hpp>
#include <Blob/ProjectionTransform.hpp>
#include <Blob/ViewTransform.hpp>

namespace Blob {

class Window;

/// A combinason of shader, color, texture or array to defines the optical properties of an object
class Material {
    friend Window;

private:
    /// TODO: add Shader Storage Buffer Object for local light sources

    const GL::ShaderProgram &shaderProgramPrivate;
public:
    virtual void applyMaterial(const ProjectionTransform &pt, const ViewTransform &vt, const glm::mat4 &mt) const = 0;

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

class DefaultMaterial : public Material {
private:
    static int model, view, projection;

    void applyMaterial(const ProjectionTransform &pt, const ViewTransform &vt, const glm::mat4 &mt) const final;

public:
    static GL::ShaderProgram *shaderProgram;

    static DefaultMaterial *defaultMaterial;

    // init with entity component system

    DefaultMaterial();
    static void init();
    static void destroy();
};

struct Light{
    int positionPos = -1;
    glm::vec3 position = glm::vec3(1.2f, 1.0f, 2.0f);

    int colorPos = -1;
    Color color = Color(1, 1, 1);
};

/// A Material to draw in a single color
class SingleColorMaterial : public Material {
private:
    static int model, view, projection;

    // texture
    static int albedoPos;
    static int metallicPos;
    static int roughnessPos;
    static int aoPos;

    static int optionsPos;

    static int camPos;

    void applyMaterial(const ProjectionTransform &pt, const ViewTransform &vt, const glm::mat4 &mt) const final;

public:
    const struct {
        uint32_t Irradiance = 1;
        uint32_t Radiance = 2;
    } Options;

    static GL::ShaderProgram *shaderProgram;

    Color albedo = Color(1.0f, 0.5f, 0.31f);
    float metallic = 0;
    float roughness = 0;
    float ao = 1;
    uint32_t options = 0xFFFFFFFF;

    static Light light;

    SingleColorMaterial();
    static void init();
    static void destroy();
};

} // namespace Blob

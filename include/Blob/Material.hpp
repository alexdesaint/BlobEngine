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
    // Color color;
    // GL::Texture *texture_0 = nullptr;
    // Vec2f texture_0Tiling;

    // float diffuseIntensity = 0;

    // static std::unordered_map<std::string, Material> Materials;

protected:
    const GL::ShaderProgram &shaderProgram;
    virtual void applyMaterial(const ProjectionTransform &pt, const ViewTransform &vt, const ModelTransform &mt) const = 0;

    explicit Material(const GL::ShaderProgram &shaderProgram);
};
} // namespace Blob

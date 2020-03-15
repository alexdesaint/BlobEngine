#pragma once
#include <Blob/Color.hpp>
#include <Blob/GL/ShaderProgram.hpp>
#include <Blob/GL/Texture.hpp>

namespace Blob {

class Shaders {
public:
    const GL::ShaderProgram Shader_2D_POSITION_TEXCOORD_0_COLOR_0, Shader_3D_POSITION, Shader_3D_POSITION_NORMAL,
        Shader_3D_POSITION_NORMAL_TEXCOORD_0;

    static void initShaders();
};

/// A combinason of shader, color, texture or array to defines the optical properties of an object
class Material {
private:
    // can be a color or a texture channel...

    Color color;
    // GL::Texture *texture_0 = nullptr;
    // Vec2f texture_0Tiling;

    // float diffuseIntensity = 0;

protected:

    Shader
    const GL::ShaderProgram &shaderProgram = Shader::Shader_3D_POSITION;

    virtual void applyMaterial() {

    }
};

/// A Material to draw in a single color
class MaterialSingleColor : Material {
private:
    Color color;
    void applyMaterial() final {}

public:
    RGBMaterial() {}
};
} // namespace Blob

#pragma once

#include <Blob/Color.hpp>
#include <Blob/Context.hpp>
#include <Blob/Maths.hpp>
#include <Blob/Shader.hpp>
#include <Blob/Texture.hpp>
#include <optional>

namespace Blob {

struct UniformSamplerReference {
    const UniformSampler &uniformSampler;
    const Texture &texture;
};

struct LightPoint {
    Vec4<> positionStrenght;
    Color color;
};

struct Lights {
    Vec4<> SunDirrectionStrenght;
    Color SunColor;
};

struct PBR {
    float metallic;
    float routhness;
    float ao = 0.1;
    float notUsed = 0.0;
};

class Material {
private:
    const Shader &shader;

    struct UniformElements {
        Uniform &color;
        Uniform &pbr;
        Uniform &lightPosRadius;

        UniformElements(Uniform &color, Uniform &pbr, Uniform &lightPosRadius) :
            color(color),
            pbr(pbr),
            lightPosRadius(lightPosRadius) {}
    };
    inline static std::unique_ptr<UniformElements> uniformElements;
    inline static Vec4<> lightPosRadius = {0, 0, 100, 10000};

public:
    std::string name;
    std::optional<Color> color;
    std::optional<PBR> pbr;

    std::vector<UniformSamplerReference> uniformSamplerReferences;

    Material(const Shader &shader) : shader(shader) {}
    Material(const Material &) = default;
    Material(Material &&) = default;

    static void initMaterial(Context &context) {
        auto &color = context.uniforms["u_color"];
        if (!color)
            color = std::make_unique<Uniform>("u_color", UniformVec4);

        auto &pbr = context.uniforms["u_pbr"];
        if (!pbr)
            pbr = std::make_unique<Uniform>("u_pbr", UniformVec4);

        auto &lightPosRadius = context.uniforms["u_lightPosRadius"];
        if (!lightPosRadius)
            lightPosRadius = std::make_unique<Uniform>("u_lightPosRadius", UniformVec4);

        uniformElements = std::make_unique<UniformElements>(*color, *pbr, *lightPosRadius);
    }

    static void applyMaterialStatic() {
        bgfx::setUniform(uniformElements->lightPosRadius.uniformHandle, &lightPosRadius.x);
    }

    void applyMaterial() const {
        bgfx::setState(BGFX_STATE_DEFAULT);
        for (const auto &[uniformHandle, uniformObject] : uniformSamplerReferences)
            bgfx::setTexture(0, uniformHandle.uniformHandle, uniformObject.textureHandle);
        if (color.has_value())
            bgfx::setUniform(uniformElements->color.uniformHandle, &color->R);
        if (pbr.has_value())
            bgfx::setUniform(uniformElements->pbr.uniformHandle, &pbr->metallic);

        bgfx::submit(0, shader.shaderHandle);
    }
};

} // namespace Blob

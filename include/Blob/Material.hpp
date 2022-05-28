#pragma once

#include <Blob/Color.hpp>
#include <Blob/Maths.hpp>
#include <Blob/Shader.hpp>
#include <Blob/Texture.hpp>
#include <memory>
#include <optional>
#include <unordered_map>

namespace Blob {

struct UniformSamplerReference {
    const UniformSampler &uniformSampler;
    const Texture &texture;
};
struct UniformReference {
    const Uniform &uniform;
    const void *data;

    UniformReference(const Uniform &uniform, const void *data) : uniform(uniform), data(data) {}
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

public:
    std::string name;
    Color color;
    std::optional<PBR> pbr;

    std::vector<UniformSamplerReference> uniformSamplerReferences;
    std::vector<UniformReference> uniformReferences;

    Material(const Shader &shader) : shader(shader) {}

    void applyMaterial() const {
        bgfx::setState(BGFX_STATE_DEFAULT);
        for (const auto &[uniformHandle, uniformObject] : uniformSamplerReferences)
            setTexture(0, uniformHandle.uniformHandle, uniformObject.textureHandle);
        for (const auto &[uniformHandle, uniformObject] : uniformReferences)
            bgfx::setUniform(uniformHandle.uniformHandle, uniformObject);
        bgfx::submit(0, shader.shaderHandle);
    }
};

} // namespace Blob

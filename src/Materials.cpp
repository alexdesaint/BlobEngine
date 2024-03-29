#include <Blob/Buffer.hpp>
#include <Blob/Materials.hpp>
#include <Blob/Window.hpp>

#include <bgfx/bgfx.h>
// #include <bgfx/embedded_shader.h>

#include <memory>
#include <shaders/f_colorArray.sc.spv.bin.h>
#include <shaders/f_colorUniform.sc.spv.bin.h>
#include <shaders/v_normal.sc.spv.bin.h>

namespace Blob {

/********************* SingleColor *********************/

Material Materials::singleColor(Context &context, const Color &albedo) {
    std::unique_ptr<Shader> &shader = context.shaders["singleColor"];
    if (!shader)
        shader = std::make_unique<Shader>(Buffer{v_normal_spv}, Buffer{f_colorUniform_spv});

    // const bgfx::EmbeddedShader k_vs = BGFX_EMBEDDED_SHADER(v_normal);

    Material material(*shader);

    material.color = albedo;

    return material;
}

Material Materials::singleTexture(Context &context, const Texture &texture, const Color &albedo) {
    std::unique_ptr<Shader> &shader = context.shaders["singleTexture"];
    if (!shader)
        shader = std::make_unique<Shader>(Buffer{v_normal_spv}, Buffer{f_colorUniform_spv});
    Material material(*shader);

    material.color = albedo;

    return material;
}

Material Materials::perFaceNormal(Context &context, const Color &albedo) {
    std::unique_ptr<Shader> &shader = context.shaders["perFaceNormal"];
    if (!shader)
        shader = std::make_unique<Shader>(Buffer{v_normal_spv}, Buffer{f_colorUniform_spv});
    Material material(*shader);

    material.color = albedo;

    return material;
}

Material Materials::pbrSingleColor(Context &context, const Color &albedo) {
    std::unique_ptr<Shader> &shader = context.shaders["pbrSingleColor"];
    if (!shader)
        shader = std::make_unique<Shader>(Buffer{v_normal_spv}, Buffer{f_colorUniform_spv});
    Material material(*shader);

    material.color = albedo;

    return material;
}

Material Materials::pbrSingleColorInstanced(Context &context, const Color &albedo) {
    std::unique_ptr<Shader> &shader = context.shaders["pbrSingleColorInstanced"];
    if (!shader)
        shader = std::make_unique<Shader>(Buffer{v_normal_spv}, Buffer{f_colorUniform_spv});
    Material material(*shader);

    material.color = albedo;

    return material;
}

Material Materials::pbrColorArray(Context &context) {
    std::unique_ptr<Shader> &shader = context.shaders["pbrColorArray"];
    if (!shader)
        shader = std::make_unique<Shader>(Buffer{v_normal_spv}, Buffer{f_colorUniform_spv});
    Material material(*shader);

    return material;
}

Material Materials::pbrColorArrayInstanced(Context &context) {
    std::unique_ptr<Shader> &shader = context.shaders["pbrColorArrayInstanced"];
    if (!shader)
        shader = std::make_unique<Shader>(Buffer{v_normal_spv}, Buffer{f_colorUniform_spv});
    Material material(*shader);

    return material;
}

Material Materials::pbrSingleTexture(Context &context, const Texture &texture, const Color &albedo) {
    std::unique_ptr<Shader> &shader = context.shaders["pbrSingleTexture"];
    if (!shader)
        shader = std::make_unique<Shader>(Buffer{v_normal_spv}, Buffer{f_colorUniform_spv});
    Material material(*shader);

    material.color = albedo;

    return material;
}

} // namespace Blob

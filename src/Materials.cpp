#include <Blob/Buffer.hpp>
#include <Blob/Materials.hpp>
#include <Blob/Window.hpp>
#include <bgfx/bgfx.h>

#include <memory>
#include <shaders/f_colorArray.h>
#include <shaders/f_colorUniform.h>
#include <shaders/v_normal.h>

namespace Blob {

/********************* SingleColor *********************/

Material Materials::singleColor(Context &context, const Color &albedo) {
    std::unique_ptr<Shader> &shader = context.shaders["singleColor"];
    if (!shader)
        shader = std::make_unique<Shader>(Buffer{v_normal}, Buffer{f_colorUniform});

    Material material(*shader);

    material.color = albedo;

    return material;
}

Material Materials::singleTexture(Context &context, const Texture &texture, const Color &albedo) {
    std::unique_ptr<Shader> &shader = context.shaders["singleTexture"];
    if (!shader)
        shader = std::make_unique<Shader>(Buffer{v_normal}, Buffer{f_colorUniform});
    Material material(*shader);

    material.color = albedo;

    return material;
}

Material Materials::perFaceNormal(Context &context, const Color &albedo) {
    std::unique_ptr<Shader> &shader = context.shaders["perFaceNormal"];
    if (!shader)
        shader = std::make_unique<Shader>(Buffer{v_normal}, Buffer{f_colorUniform});
    Material material(*shader);

    material.color = albedo;

    return material;
}

Material Materials::pbrSingleColor(Context &context, const Color &albedo) {
    std::unique_ptr<Shader> &shader = context.shaders["pbrSingleColor"];
    if (!shader)
        shader = std::make_unique<Shader>(Buffer{v_normal}, Buffer{f_colorUniform});
    Material material(*shader);

    material.color = albedo;

    return material;
}

Material Materials::pbrSingleColorInstanced(Context &context, const Color &albedo) {
    std::unique_ptr<Shader> &shader = context.shaders["pbrSingleColorInstanced"];
    if (!shader)
        shader = std::make_unique<Shader>(Buffer{v_normal}, Buffer{f_colorUniform});
    Material material(*shader);

    material.color = albedo;

    return material;
}

Material Materials::pbrColorArray(Context &context) {
    std::unique_ptr<Shader> &shader = context.shaders["pbrColorArray"];
    if (!shader)
        shader = std::make_unique<Shader>(Buffer{v_normal}, Buffer{f_colorUniform});
    Material material(*shader);

    return material;
}

Material Materials::pbrColorArrayInstanced(Context &context) {
    std::unique_ptr<Shader> &shader = context.shaders["pbrColorArrayInstanced"];
    if (!shader)
        shader = std::make_unique<Shader>(Buffer{v_normal}, Buffer{f_colorUniform});
    Material material(*shader);

    return material;
}

Material
Materials::pbrSingleTexture(Context &context, const Texture &texture, const Color &albedo) {
    std::unique_ptr<Shader> &shader = context.shaders["pbrSingleTexture"];
    if (!shader)
        shader = std::make_unique<Shader>(Buffer{v_normal}, Buffer{f_colorUniform});
    Material material(*shader);

    material.color = albedo;

    return material;
}

} // namespace Blob
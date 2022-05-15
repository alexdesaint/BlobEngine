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

std::unique_ptr<Material> Materials::singleColor(Context &context,
                                                 const Color &albedo) {
    std::unique_ptr<Shader> &shader = context.shaders["singleColor"];
    if (!shader)
        shader =
            std::make_unique<Shader>(Buffer{v_normal}, Buffer{f_colorUniform});

    std::unique_ptr<Material> material = std::make_unique<Material>(*shader);

    material->color = albedo;
    std::unique_ptr<Uniform> &uniformColor = context.uniforms["u_color"];
    if (!uniformColor)
        uniformColor = std::make_unique<Uniform>("u_color", UniformVec4);
    material->uniformReferences.emplace_back(*uniformColor,
                                             (const void *) &material->color.R);

    return material;
}

std::unique_ptr<Material> Materials::singleTexture(Context &context,
                                                   const Texture &texture,
                                                   const Color &albedo) {
    std::unique_ptr<Shader> &shader = context.shaders["singleTexture"];
    if (!shader)
        shader =
            std::make_unique<Shader>(Buffer{v_normal}, Buffer{f_colorUniform});
    std::unique_ptr<Material> material = std::make_unique<Material>(*shader);

    material->color = albedo;
    std::unique_ptr<Uniform> &uniformColor = context.uniforms["u_color"];
    if (!uniformColor)
        uniformColor = std::make_unique<Uniform>("u_color", UniformVec4);
    material->uniformReferences.emplace_back(*uniformColor, &material->color.R);

    return material;
}

std::unique_ptr<Material> Materials::perFaceNormal(Context &context,
                                                   const Color &albedo) {
    std::unique_ptr<Shader> &shader = context.shaders["perFaceNormal"];
    if (!shader)
        shader =
            std::make_unique<Shader>(Buffer{v_normal}, Buffer{f_colorUniform});
    std::unique_ptr<Material> material = std::make_unique<Material>(*shader);

    material->color = albedo;
    std::unique_ptr<Uniform> &uniformColor = context.uniforms["u_color"];
    if (!uniformColor)
        uniformColor = std::make_unique<Uniform>("u_color", UniformVec4);
    material->uniformReferences.emplace_back(*uniformColor, &material->color.R);

    return material;
}

std::unique_ptr<Material> Materials::pbrSingleColor(Context &context,
                                                    const Color &albedo) {
    std::unique_ptr<Shader> &shader = context.shaders["pbrSingleColor"];
    if (!shader)
        shader =
            std::make_unique<Shader>(Buffer{v_normal}, Buffer{f_colorUniform});
    std::unique_ptr<Material> material = std::make_unique<Material>(*shader);

    material->color = albedo;
    std::unique_ptr<Uniform> &uniformColor = context.uniforms["u_color"];
    if (!uniformColor)
        uniformColor = std::make_unique<Uniform>("u_color", UniformVec4);
    material->uniformReferences.emplace_back(*uniformColor, &material->color.R);

    return material;
}

std::unique_ptr<Material>
Materials::pbrSingleColorInstanced(Context &context, const Color &albedo) {
    std::unique_ptr<Shader> &shader =
        context.shaders["pbrSingleColorInstanced"];
    if (!shader)
        shader =
            std::make_unique<Shader>(Buffer{v_normal}, Buffer{f_colorUniform});
    std::unique_ptr<Material> material = std::make_unique<Material>(*shader);

    material->color = albedo;
    std::unique_ptr<Uniform> &uniformColor = context.uniforms["u_color"];
    if (!uniformColor)
        uniformColor = std::make_unique<Uniform>("u_color", UniformVec4);
    material->uniformReferences.emplace_back(*uniformColor, &material->color.R);

    return material;
}

std::unique_ptr<Material> Materials::pbrColorArray(Context &context) {
    std::unique_ptr<Shader> &shader = context.shaders["pbrColorArray"];
    if (!shader)
        shader =
            std::make_unique<Shader>(Buffer{v_normal}, Buffer{f_colorUniform});
    std::unique_ptr<Material> material = std::make_unique<Material>(*shader);
    return material;
}

std::unique_ptr<Material> Materials::pbrColorArrayInstanced(Context &context) {
    std::unique_ptr<Shader> &shader = context.shaders["pbrColorArrayInstanced"];
    if (!shader)
        shader =
            std::make_unique<Shader>(Buffer{v_normal}, Buffer{f_colorUniform});
    std::unique_ptr<Material> material = std::make_unique<Material>(*shader);
    return material;
}

std::unique_ptr<Material> Materials::pbrSingleTexture(Context &context,
                                                      const Texture &texture,
                                                      const Color &albedo) {
    std::unique_ptr<Shader> &shader = context.shaders["pbrSingleTexture"];
    if (!shader)
        shader =
            std::make_unique<Shader>(Buffer{v_normal}, Buffer{f_colorUniform});
    std::unique_ptr<Material> material = std::make_unique<Material>(*shader);

    material->color = albedo;
    std::unique_ptr<Uniform> &uniformColor = context.uniforms["u_color"];
    if (!uniformColor)
        uniformColor = std::make_unique<Uniform>("u_color", UniformVec4);
    material->uniformReferences.emplace_back(*uniformColor, &material->color.R);

    return material;
}

} // namespace Blob
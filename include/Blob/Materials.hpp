#pragma once

#include "Blob/Texture.hpp"
#include <Blob/Context.hpp>
#include <Blob/Material.hpp>
#include <Blob/Maths.hpp>
#include <memory>

namespace Blob {

class Materials {
public:
    static std::unique_ptr<Material>
    singleColor(Context &context, const Color &albedo = {1.0f, 0.5f, 0.3f});

    static std::unique_ptr<Material>
    singleTexture(Context &context,
                  const Texture &texture,
                  const Color &albedo = {1.0f, 0.5f, 0.3f});

    static std::unique_ptr<Material>
    perFaceNormal(Context &context, const Color &albedo = {1.0f, 0.5f, 0.3f});

    static std::unique_ptr<Material>
    pbrSingleColor(Context &context, const Color &albedo = {1.0f, 0.5f, 0.3f});

    static std::unique_ptr<Material>
    pbrSingleColorInstanced(Context &context,
                            const Color &albedo = {1.0f, 0.5f, 0.3f});

    static std::unique_ptr<Material> pbrColorArray(Context &context);

    static std::unique_ptr<Material> pbrColorArrayInstanced(Context &context);

    static std::unique_ptr<Material>
    pbrSingleTexture(Context &context,
                     const Texture &texture,
                     const Color &albedo = {1.0f, 0.5f, 0.3f});
};

} // namespace Blob
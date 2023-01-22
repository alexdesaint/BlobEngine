#pragma once

#include "Blob/Texture.hpp"
#include <Blob/Context.hpp>
#include <Blob/Material.hpp>
#include <Blob/Maths.hpp>

namespace Blob {

class Materials {
public:
    static Material singleColor(Context &context, const Color &albedo = {1.0f, 0.5f, 0.3f});

    static Material singleTexture(Context &context, const Texture &texture, const Color &albedo = {1.0f, 0.5f, 0.3f});

    static Material perFaceNormal(Context &context, const Color &albedo = {1.0f, 0.5f, 0.3f});

    static Material pbrSingleColor(Context &context, const Color &albedo = {1.0f, 0.5f, 0.3f});

    static Material pbrSingleColorInstanced(Context &context, const Color &albedo = {1.0f, 0.5f, 0.3f});

    static Material pbrColorArray(Context &context);

    static Material pbrColorArrayInstanced(Context &context);

    static Material
    pbrSingleTexture(Context &context, const Texture &texture, const Color &albedo = {1.0f, 0.5f, 0.3f});
};

} // namespace Blob
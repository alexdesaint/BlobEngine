#pragma once

#include <Blob/Color.hpp>
#include <Blob/Core/Shader.hpp>
#include <Blob/Core/Texture.hpp>

#include <Blob/Shaders/Frag/PBRcolorArray.hpp>
#include <Blob/Shaders/Frag/PBRsingleColor.hpp>
#include <Blob/Shaders/Frag/PBRsingleTexture.hpp>
#include <Blob/Shaders/Frag/singleColor.hpp>
#include <Blob/Shaders/Frag/singleTexture.hpp>
#include <Blob/Shaders/Geom/normal.hpp>
#include <Blob/Shaders/Geom/water.hpp>
#include <Blob/Shaders/Vert/mainInstanced.hpp>
#include <Blob/Shaders/Vert/mainInstancedColor.hpp>
#include <Blob/Shaders/Vert/mainNonInstanced.hpp>
#include <Blob/Shaders/Vert/normal.hpp>
#include <Blob/Shaders/Vert/water.hpp>

namespace Blob::Shaders {
using UniformModel = UniformAttribute<Mat4, 0>;
using UniformView = UniformAttribute<ViewTransform, 1>;
using UniformProjection = UniformAttribute<ProjectionTransform, 2>;

using UniformAlbedo = UniformAttribute<Color::RGBA, 3>;
using UniformTextureScale = UniformAttribute<Vec2<>, 4>;

using SingleColor = Shader<
    ShaderProgramSpirV<VertexShaderSpirV<mainNonInstanced, "mainNonInstanced">,
                       FragmentShaderSpirV<singleColor, "singleColor">>,
    UniformModel,
    UniformView,
    UniformProjection,
    UniformAlbedo>;

using SingleTexture = Shader<
    ShaderProgramSpirV<VertexShaderSpirV<mainNonInstanced, "mainNonInstanced">,
                       FragmentShaderSpirV<singleTexture, "singleTexture">>,
    UniformModel,
    UniformView,
    UniformProjection,
    UniformTextureScale,
    UniformAttribute<Texture, 0>>;

using PerFaceNormal =
    Shader<ShaderProgramSpirV<VertexShaderSpirV<normal_vert, "main">,
                              GeometryShaderSpirV<normal_geom, "main">,
                              FragmentShaderSpirV<singleColor, "singleColor">>,
           UniformModel,
           UniformView,
           UniformProjection,
           UniformAlbedo,
           UniformAttribute<float, 4>>;

namespace PBR {

using UniformMetallic = UniformAttribute<float, 5>;
using UniformRoughness = UniformAttribute<float, 6>;
using UniformAo = UniformAttribute<float, 7>;

using UniformCameraPosition = UniformAttribute<Vec3<float>, 8>;
using UniformLightPosition = UniformAttribute<Vec3<float>, 9>;
using UniformLightColor = UniformAttribute<Color::RGB, 10>;
using UniformLightRadius = UniformAttribute<float, 11>;
using UniformLightPower = UniformAttribute<float, 12>;

using SingleColor = Shader<
    ShaderProgramSpirV<VertexShaderSpirV<mainNonInstanced, "mainNonInstanced">,
                       FragmentShaderSpirV<PBRsingleColor, "PBRsingleColor">>,
    UniformModel,
    UniformView,
    UniformProjection,
    // UniformMetallic,
    // UniformRoughness,
    // UniformAo,
    // UniformCameraPosition,
    UniformLightPosition,
    // UniformLightColor,
    // UniformLightRadius,
    UniformLightPower,
    UniformAlbedo>;

using SingleColorInstanced = Shader<
    ShaderProgramSpirV<VertexShaderSpirV<mainInstanced, "mainInstanced">,
                       FragmentShaderSpirV<PBRsingleColor, "PBRsingleColor">>,
    UniformView,
    UniformProjection,
    UniformMetallic,
    UniformRoughness,
    UniformAo,
    UniformCameraPosition,
    UniformLightPosition,
    UniformLightColor,
    UniformLightRadius,
    UniformLightPower,
    UniformAlbedo>;

using SingleTexture =
    Shader<ShaderProgramSpirV<
               VertexShaderSpirV<mainNonInstanced, "mainNonInstanced">,
               FragmentShaderSpirV<PBRsingleTexture, "PBRsingleTexture">>,
           UniformModel,
           UniformView,
           UniformProjection,
           UniformMetallic,
           UniformRoughness,
           UniformAo,
           UniformCameraPosition,
           UniformLightPosition,
           UniformLightColor,
           UniformLightRadius,
           UniformLightPower,
           UniformAttribute<Texture, 0>>;

using ColorArray = Shader<
    ShaderProgramSpirV<VertexShaderSpirV<mainNonInstanced, "mainNonInstanced">,
                       FragmentShaderSpirV<PBRcolorArray, "PBRcolorArray">>,
    UniformModel,
    UniformView,
    UniformProjection,
    UniformMetallic,
    UniformRoughness,
    UniformAo,
    UniformCameraPosition,
    UniformLightPosition,
    UniformLightColor,
    UniformLightRadius,
    UniformLightPower>;

using Water =
    Shader<ShaderProgramSpirV<
               VertexShaderSpirV<water_vert, "main">,
               GeometryShaderSpirV<water_geom, "main">,
               FragmentShaderSpirV<PBRsingleTexture, "PBRsingleTexture">>,
           UniformModel,
           UniformView,
           UniformProjection,
           UniformMetallic,
           UniformRoughness,
           UniformAo,
           UniformCameraPosition,
           UniformLightPosition,
           UniformLightColor,
           UniformLightRadius,
           UniformLightPower,
           UniformAttribute<float, 11>>;

} // namespace PBR

} // namespace Blob::Shaders
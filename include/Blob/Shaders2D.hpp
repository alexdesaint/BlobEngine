#pragma once

#include "Blob/Color.hpp"
#include "Blob/Core/Texture.hpp"
#include <Blob/Core/Shader.hpp>

namespace Blob::Shaders2D {

using UniformModel = UniformAttribute<Mat3, 0>;
using UniformView = UniformAttribute<ViewTransform2D, 1>;
using UniformProjection = UniformAttribute<ProjectionTransform2D, 2>;

using SingleColor = Shader<ShaderProgram<VertexShader<R"=====(#version 450
layout(location = 0) in vec2 Position;

layout(location = 0) uniform mat3 model;
layout(location = 1) uniform mat3 view;
layout(location = 2) uniform mat3 projection;

void main() {
    vec3 pos = vec3(Position.xy, 1);
    pos = view * model * pos;
    pos = projection * pos;
    gl_Position = vec4(pos.xy, 0, 1);
})=====">,
                                         FragmentShader<R"=====(#version 450
layout(location=0) out vec4 color;

layout(location = 3) uniform vec4 albedo;

void main() {
    color = albedo;
})=====">>,
                           UniformModel,
                           UniformView,
                           UniformProjection,
                           UniformAttribute<Color::RGBA, 3>>;

using SingleColorSingleTexture =
    Shader<ShaderProgram<VertexShader<R"=====(#version 450
layout(location = 0) in vec2 Position;
layout(location = 3) in vec2 TexturePosition;

layout(location = 0) uniform mat3 model;
layout(location = 1) uniform mat3 view;
layout(location = 2) uniform mat3 projection;

layout(location = 1) out vec2 texCoord;

void main() {
    texCoord = TexturePosition;
    vec3 pos = vec3(Position.xy, 1);
    pos = view * model * pos;
    //pos += vec3(0.5, 0, 1);
    pos = projection * pos;
    gl_Position = vec4(pos.xy, 0, 1);
})=====">,
                         FragmentShader<R"=====(#version 450
layout(location=0) out vec4 color;

layout(location = 1) in vec2 texCoord;

layout(location = 3) uniform vec4 albedo;
uniform sampler2D Texture;

void main() {
    color = albedo * texture(Texture, texCoord.st);
})=====">>,
           UniformModel,
           UniformView,
           UniformProjection,
           UniformAttribute<Color::RGBA, 3>,
           UniformAttribute<Texture, 0>>;

using ColorArraySingleTexture =
    Shader<ShaderProgram<VertexShader<R"=====(#version 450
layout(location = 0) in vec2 Position;
layout(location = 3) in vec2 TexturePosition;
layout(location = 5) in vec4 Color;

layout(location = 0) uniform mat3 model;
layout(location = 1) uniform mat3 view;
layout(location = 2) uniform mat3 projection;

layout(location = 1) out vec2 texCoord;
layout(location = 5) out vec4 color_0;

void main() {
    texCoord = TexturePosition;
    color_0 = Color;
    gl_Position = vec4((projection * view * model * vec3(Position.xy, 1)).xy, 0, 1);
})=====">,
                         FragmentShader<R"=====(#version 450
layout(location=0) out vec4 color;

layout(location = 1) in vec2 texCoord;
layout(location = 5) in vec4 color_0;

uniform sampler2D Texture;

void main() {
    color = color_0 * texture(Texture, texCoord.st);
})=====">>,
           UniformModel,
           UniformView,
           UniformProjection,
           UniformAttribute<Texture, 0>>;

} // namespace Blob::Shaders2D

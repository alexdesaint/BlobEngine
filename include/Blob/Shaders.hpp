#pragma once

#include "Blob/Color.hpp"
#include "Blob/Core/Texture.hpp"
#include "Blob/Shaders.hpp"
#include <Blob/Core/Shader.hpp>
#include <Blob/Maths.inl>
#include <memory>

namespace Blob::Shaders2D {

using UniformModel = Core::UniformAttribute<Maths::Mat3, 0>;
using UniformView = Core::UniformAttribute<Maths::ViewTransform2D, 1>;
using UniformProjection = Core::UniformAttribute<Maths::ProjectionTransform2D, 2>;

using SingleColor = Core::Shader<Core::ShaderProgram<Core::VertexShader<R"=====(#version 450
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
                                                     Core::FragmentShader<R"=====(#version 450
layout(location=0) out vec4 color;

layout(location = 3) uniform vec4 albedo;

void main() {
    color = albedo;
})=====">>,
                                 UniformModel,
                                 UniformView,
                                 UniformProjection,
                                 Core::UniformAttribute<Color::RGBA, 3>>;

using SingleColorSingleTexture = Core::Shader<Core::ShaderProgram<Core::VertexShader<R"=====(#version 450
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
                                                                  Core::FragmentShader<R"=====(#version 450
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
                                              Core::UniformAttribute<Color::RGBA, 3>,
                                              Core::UniformAttribute<Core::Texture, 0>>;

using ColorArraySingleTexture = Core::Shader<Core::ShaderProgram<Core::VertexShader<R"=====(#version 450
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
                                                                 Core::FragmentShader<R"=====(#version 450
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
                                             Core::UniformAttribute<Core::Texture, 0>>;

} // namespace Blob::Shaders2D

namespace Blob::Shaders {
using UniformModel = Core::UniformAttribute<Maths::Mat4, 0>;
using UniformView = Core::UniformAttribute<Maths::ViewTransform, 1>;
using UniformProjection = Core::UniformAttribute<Maths::ProjectionTransform, 2>;

using SingleColor = Core::Shader<Core::ShaderProgram<Core::VertexShader<R"=====(#version 450

layout(location = 0) in vec3 POSITION;

layout(location = 0) uniform mat4 model;
layout(location = 1) uniform mat4 view;
layout(location = 2) uniform mat4 projection;

void main() {
    gl_Position = projection * view * model * vec4(POSITION, 1.0);
})=====">,
                                                     Core::FragmentShader<R"=====(#version 450
layout(location=0) out vec4 color;

layout(location = 3) uniform vec3 albedo;

void main()
{
    color = vec4(albedo, 1.0);
})=====">>,
                                 UniformModel,
                                 UniformView,
                                 UniformProjection,
                                 Core::UniformAttribute<Color::RGB, 3>>;

using SingleColorTransparent = Core::Shader<Core::ShaderProgram<Core::VertexShader<R"=====(
#version 450

layout(location = 0) in vec3 POSITION;

layout(location = 0) uniform mat4 model;
layout(location = 1) uniform mat4 view;
layout(location = 2) uniform mat4 projection;

void main() {
    gl_Position =  projection * view * model * vec4(POSITION, 1.0);
})=====">,
                                                                Core::FragmentShader<R"=====(#version 450
layout(location=0) out vec4 color;

layout(location = 3) uniform vec4 albedo;

void main()
{
    color = albedo;
})=====">>,
                                            UniformModel,
                                            UniformView,
                                            UniformProjection,
                                            Core::UniformAttribute<Color::RGBA, 3>>;

using SingleTexture = Core::Shader<Core::ShaderProgram<Core::VertexShader<R"=====(
#version 450

layout(location = 0) in vec3 POSITION;
layout(location = 3) in vec2 texCoord;

layout(location = 0) uniform mat4 model;
layout(location = 1) uniform mat4 view;
layout(location = 2) uniform mat4 projection;

layout(location = 1) out vec2 texCoord_;

void main() {
    texCoord_ = texCoord;
    gl_Position =  projection * view * model * vec4(POSITION, 1.0);
})=====">,
                                                       Core::FragmentShader<R"=====(#version 450
layout(location=0) out vec4 color;

layout(location = 1) in vec2 texCoord;
uniform sampler2D Texture;
layout(location = 3) uniform vec2 texScale;

void main()
{
    vec3 albedo = texture(Texture, texCoord * texScale).rgb;
    color = vec4(albedo, 1.0);
})=====">>,
                                   UniformModel,
                                   UniformView,
                                   UniformProjection,
                                   Core::UniformAttribute<Maths::Vec2<float>, 3>,
                                   Core::UniformAttribute<Core::Texture, 0>>;

using PerFaceNormal = Core::Shader<Core::ShaderProgram<Core::VertexShader<R"=====(
#version 450

layout(location = 0) in vec3 POSITION;
layout(location = 1) in vec3 NORMAL;

layout(location = 2) out vec3 normal;

void main() {
    normal = NORMAL;
    gl_Position =  vec4(POSITION, 1.0);
})=====">,
                                                       Core::GeometryShader<R"=====(#version 450
layout(triangles) in;
layout(line_strip, max_vertices=2) out;

layout(location = 2) in vec3 NORMAL[];

layout(location = 0) uniform mat4 model;
layout(location = 1) uniform mat4 view;
layout(location = 2) uniform mat4 projection;
layout(location = 4) uniform float length;

void main()
{
    vec4 P = vec4(0);
    vec3 N = vec3(0);

    for(int i=0; i<gl_in.length(); i++) {
        P += gl_in[i].gl_Position;
        N += NORMAL[i];
    }
    P /= gl_in.length();
    N /= gl_in.length();

    gl_Position = projection * view * model * P;
    EmitVertex();

    gl_Position = projection * view * model * (P + vec4(N, 0) * length);
    EmitVertex();

    EndPrimitive();
})=====">,
                                                       Core::FragmentShader<R"=====(#version 450
layout(location=0) out vec4 color;

layout(location = 3) uniform vec3 albedo;

void main()
{
    color = vec4(albedo, 1.0);
})=====">>,
                                   UniformModel,
                                   UniformView,
                                   UniformProjection,
                                   Core::UniformAttribute<Color::RGB, 3>,
                                   Core::UniformAttribute<float, 4>>;

using Deferred = Core::Shader<Core::ShaderProgram<Core::VertexShader<R"=====(#version 450

layout (location = 0) out vec3 gPosition;
layout (location = 1) out vec3 gNormal;
layout (location = 2) out vec4 gAlbedoSpec;

in vec2 TexCoords;
in vec3 FragPos;
in vec3 Normal;

uniform sampler2D texture_diffuse1;
uniform sampler2D texture_specular1;

void main()
{
    // store the fragment position vector in the first gbuffer texture
    gPosition = FragPos;
    // also store the per-fragment normals into the gbuffer
    gNormal = normalize(Normal);
    // and the diffuse per-fragment color
    gAlbedoSpec.rgb = texture(texture_diffuse1, TexCoords).rgb;
    // store specular intensity in gAlbedoSpec's alpha component
    gAlbedoSpec.a = texture(texture_specular1, TexCoords).r;
} )=====">>>;

namespace PBR {

using UniformMetallic = Core::UniformAttribute<float, 3>;
using UniformRoughness = Core::UniformAttribute<float, 4>;
using UniformAo = Core::UniformAttribute<float, 5>;

using UniformCameraPosition = Core::UniformAttribute<Maths::Vec3<float>, 6>;
using UniformLightPosition = Core::UniformAttribute<Maths::Vec3<float>, 7>;
using UniformLightColor = Core::UniformAttribute<Color::RGB, 8>;
using UniformLightRadius = Core::UniformAttribute<float, 9>;
using UniformLightPower = Core::UniformAttribute<float, 10>;

using Vertex = Core::VertexShader<R"=====(#version 450

layout(location = 0) in vec3 POSITION;
layout(location = 1) in vec3 NORMAL;
layout(location = 2) in vec3 TANGENT;
layout(location = 3) in vec2 TEXCOORD_0;
layout(location = 4) in vec2 TEXCOORD_1;
layout(location = 5) in vec3 COLOR_0;
layout(location = 6) in vec3 JOINTS_0;
layout(location = 7) in vec3 WEIGHTS_0;

layout(location = 0) out vec3 position;
layout(location = 1) out vec2 texCoord;
layout(location = 2) out vec3 normal;
layout(location = 3) out vec3 tangent;
layout(location = 4) out vec3 binormal;
layout(location = 5) out vec3 COLOR_0_;

layout(location = 0) uniform mat4 model;
layout(location = 1) uniform mat4 view;
layout(location = 2) uniform mat4 projection;

void main() {
    position = vec3(model * vec4(POSITION, 1.0));
    texCoord = TEXCOORD_0;
    normal = normalize(mat3(transpose(inverse(model))) * NORMAL);
    tangent = TANGENT;
    binormal = cross(NORMAL, TANGENT);
    COLOR_0_ = COLOR_0;

    gl_Position =  projection * view * model * vec4(POSITION, 1.0);
})=====">;

constexpr char PBR_HEAD[] = R"=====(#version 450
layout(location=0) out vec4 color;

const float PI = 3.14159265359;
const float Epsilon = 0.00001;
const vec3 Fdielectric = vec3(0.04);

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 texCoord;
layout(location = 2) in vec3 normal;
layout(location = 3) in vec3 tangent;
layout(location = 4) in vec3 binormal;
)=====";

constexpr char PBR_FUNCTIONS[] =
    R"=====(
// GGX/Towbridge-Reitz normal distribution function.
// Uses Disney's reparametrization of alpha = roughness^2.

float ndfGGX(float cosLh, float roughness)
{
	float alpha   = roughness * roughness;
	float alphaSq = alpha * alpha;

	float denom = (cosLh * cosLh) * (alphaSq - 1.0) + 1.0;
	return alphaSq / (PI * denom * denom);
}

// Single term for separable Schlick-GGX below.
float gaSchlickG1(float cosTheta, float k)
{
	return cosTheta / (cosTheta * (1.0 - k) + k);
}

// Schlick-GGX approximation of geometric attenuation function using Smith's method.
float gaSchlickGGX(float cosLi, float cosLo, float roughness)
{
	float r = roughness + 1.0;
	float k = (r * r) / 8.0; // Epic suggests using this roughness remapping for analytic lights.
	return gaSchlickG1(cosLi, k) * gaSchlickG1(cosLo, k);
}

// Shlick's approximation of the Fresnel factor.
vec3 fresnelSchlick(vec3 F0, float cosTheta)
{
	return F0 + (vec3(1.0) - F0) * pow(1.0 - cosTheta, 5.0);
}

// Light attenuation

float smoothDistanceAtt(float  squaredDistance, float invSqrAttRadius) {
    float  factor = squaredDistance * invSqrAttRadius;
    float  smoothFactor = clamp(1.0f - factor * factor, 0.0, 1.0);
    return  smoothFactor * smoothFactor;
}

float  getDistanceAtt(float lightPower, vec3 unormalizedLightVector) {
	float  sqrDist = dot(unormalizedLightVector , unormalizedLightVector);
	float  attenuation = lightPower / (max(sqrDist , 0.01*0.01));
	return  clamp(attenuation, 0.0, 1.0);
}

float  getDistanceAttRadius(float lightPower, float lightRadius, vec3 unormalizedLightVector) {
	float  sqrDist = dot(unormalizedLightVector , unormalizedLightVector);
	float  attenuation = lightPower / (max(sqrDist , 0.01*0.01));
	attenuation  *=  smoothDistanceAtt(sqrDist, 1.0/(lightRadius * lightRadius));
	return  clamp(attenuation, 0.0, 1.0);
}

// TODO: use
float  getAngleAtt(vec3 normalizedLightVector, vec3 lightDir, float lightAngleScale, float lightAngleOffset) {
	float  cd = dot(lightDir , normalizedLightVector);
	float  attenuation = clamp(cd * lightAngleScale + lightAngleOffset, 0.0, 1.0);
	//  smooth  the  transition
	attenuation  *=  attenuation;
	return  attenuation;
}

float lightAttenuation(float lightPower, vec3 lightPosition, vec3 worldPos, vec3 N) {
	vec3 unnormalizedLightVector = lightPosition  - worldPos;
	vec3 L = normalize(unnormalizedLightVector);
	float att = 1;
	att *= getDistanceAtt(lightPower, unnormalizedLightVector);
	att *= clamp(dot(N, L), 0.0, 1.0);
	//att *=  getAngleAtt(L, lightForward, lightAngleScale, lightAngleOffset);
	return att;
}

// Light attenuation with a limited radius
float lightAttenuationLocale(float lightPower, float lightRadius, vec3 lightPosition, vec3 worldPos, vec3 N) {
	vec3 unnormalizedLightVector = lightPosition  - worldPos;
	vec3 L = normalize(unnormalizedLightVector);
	float att = 1;
	att *= getDistanceAttRadius(lightPower, lightRadius, unnormalizedLightVector);
	att *= clamp(dot(N, L), 0.0, 1.0);
	//att *=  getAngleAtt(L, lightForward, lightAngleScale, lightAngleOffset);
	return att;
}
)=====";

using SingleColor = Core::Shader<Core::ShaderProgram<Vertex, Core::FragmentShader<PBR_HEAD, PBR_FUNCTIONS, R"=====(
// material parameters
layout(location = 3) uniform float metallic;
layout(location = 4) uniform float roughness;
layout(location = 5) uniform float ao;

layout(location = 6) uniform vec3 eyePosition;
layout(location = 7) uniform vec3 lightPosition;
layout(location = 8) uniform vec3 lightColor;
layout(location = 9) uniform float lightRadius;
layout(location = 10) uniform float lightPower;

layout(location = 11) uniform vec3 albedo;

// Main

void main()
{
    vec3 limunance = albedo * lightAttenuation(lightPower, lightPosition, position, normal);
//limunance = albedo;
    color = vec4(limunance, 1.0);
})=====">>,
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
                                 Core::UniformAttribute<Color::RGB, 11>>;

using SingleTransparentColor = Core::Shader<Core::ShaderProgram<Vertex, Core::FragmentShader<PBR_HEAD, PBR_FUNCTIONS, R"=====(
// material parameters
layout(location = 3) uniform float metallic;
layout(location = 4) uniform float roughness;
layout(location = 5) uniform float ao;

layout(location = 6) uniform vec3 eyePosition;
layout(location = 7) uniform vec3 lightPosition;
layout(location = 8) uniform vec3 lightColor;
layout(location = 9) uniform float lightRadius;
layout(location = 10) uniform float lightPower;

layout(location = 11) uniform vec4 albedo;

// Main

void main()
{
    vec3 limunance = albedo.xyz * lightAttenuation(lightPower, lightPosition, position, normal);
    color = vec4(limunance, albedo.w);
})=====">>,
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
                                            Core::UniformAttribute<Color::RGBA, 11>>;

using SingleTexture = Core::Shader<Core::ShaderProgram<Vertex, Core::FragmentShader<PBR_HEAD, PBR_FUNCTIONS, R"=====(
// material parameters
layout(location = 3) uniform float metallic;
layout(location = 4) uniform float roughness;
layout(location = 5) uniform float ao;

layout(location = 6) uniform vec3 eyePosition;
layout(location = 7) uniform vec3 lightPosition;
layout(location = 8) uniform vec3 lightColor;
layout(location = 9) uniform float lightRadius;
layout(location = 10) uniform float lightPower;

layout(location = 11) uniform vec2 texScale;
uniform sampler2D Texture;

void main()
{
    vec3 albedo = texture(Texture, texCoord * texScale).rgb;

    vec3 limunance = albedo * lightAttenuation(lightPower, lightPosition, position, normal);
    color = vec4(limunance, 1.0);
})=====">>,
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
                                   Core::UniformAttribute<Core::Texture, 0>>;

using ColorArray = Core::Shader<Core::ShaderProgram<Vertex, Core::FragmentShader<PBR_HEAD, PBR_FUNCTIONS, R"=====(
// material parameters
layout(location = 3) uniform float metallic;
layout(location = 4) uniform float roughness;
layout(location = 5) uniform float ao;

layout(location = 6) uniform vec3 eyePosition;
layout(location = 7) uniform vec3 lightPosition;
layout(location = 8) uniform vec3 lightColor;
layout(location = 9) uniform float lightRadius;
layout(location = 10) uniform float lightPower;

layout(location = 11) in vec3 COLOR_0;

void main()
{
    vec3 limunance = COLOR_0 * lightAttenuation(lightPower, lightPosition, position, normal);
    color = vec4(limunance, 1.0);
})=====">>,
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

using Water = Core::Shader<Core::ShaderProgram<Core::VertexShader<
                                                   R"=====(
#version 450
#define PI 3.1415926535897932384626433832795

layout(location = 0) in vec3 POSITION;

layout(location = 0) out vec3 position;

layout(location = 12) uniform float timeStep;

void main() {
    vec4 p = vec4(POSITION, 1.0);
    p.z = p.z/5;
    p.z += cos(p.x * PI + timeStep) * sin(p.y * PI + timeStep)/4;
    gl_Position =  p;
})=====">,
                                               Core::GeometryShader<R"=====(
#version 450
layout(triangles) in;
layout(triangle_strip, max_vertices=3) out;

layout(location = 0) uniform mat4 model;
layout(location = 0) out vec3 position;
layout(location = 2) out vec3 normal;

layout(location = 1) uniform mat4 view;
layout(location = 2) uniform mat4 projection;

void main()
{
    vec3 a = ( gl_in[1].gl_Position - gl_in[0].gl_Position ).xyz;
    vec3 b = ( gl_in[2].gl_Position - gl_in[0].gl_Position ).xyz;
    vec3 N = normalize(mat3(transpose(inverse(model))) * cross(b, a));

    for( int i=0; i<gl_in.length( ); ++i )
    {
        position = gl_in[i].gl_Position.xyz;
        gl_Position = projection * view * model * gl_in[i].gl_Position;
        normal = N;
        EmitVertex();
    }

    EndPrimitive();
})=====">,
                                               Core::FragmentShader<PBR_HEAD, PBR_FUNCTIONS, R"=====(
// material parameters
layout(location = 3) uniform vec4 albedo;
layout(location = 4) uniform float metallic;
layout(location = 5) uniform float roughness;
layout(location = 6) uniform float ao;

layout(location = 7) uniform vec3 eyePosition;
layout(location = 8) uniform vec3 lightPosition;
layout(location = 9) uniform vec3 lightColor;
layout(location = 10) uniform float lightRadius;
layout(location = 11) uniform float lightPower;

// Main

void main()
{
    vec3 limunance = albedo.xyz * (lightAttenuation(lightPower, lightPosition, position, -normal)+ao);
//limunance = albedo;
    color = vec4(limunance, albedo.w);
})=====">>,
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
                           Core::UniformAttribute<float, 11>>;

} // namespace PBR

} // namespace Blob::Shaders
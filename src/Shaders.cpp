#include <Blob/Shaders.hpp>

namespace Blob::Shaders {

SingleColor SingleColor::instance;

void SingleColor::build() {
    addVertexShader(R"=====(
#version 450

layout(location = 0) in vec3 POSITION;

layout(location = 0) uniform mat4 model;
layout(location = 1) uniform mat4 view;
layout(location = 2) uniform mat4 projection;

void main() {
    gl_Position =  projection * view * model * vec4(POSITION, 1.0);
})=====");
    addFragmentShader(R"=====(#version 450
layout(location=0) out vec4 color;

layout(location = 3) uniform vec3 albedo;

void main()
{
    color = vec4(albedo, 1.0);
})=====");
    linkShaders();
}

void SingleColor::destroy() {
    GL::Shader::destroy();
}

/********************* PBR code *********************/

static const std::string PBRvertex = R"=====(
#version 450

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
})=====";
static const std::string PBRpixelHead = R"=====(#version 450
layout(location=0) out vec4 color;

const float PI = 3.14159265359;
const float Epsilon = 0.00001;
// Constant normal incidence Fresnel factor for all dielectrics.
const vec3 Fdielectric = vec3(0.04);

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 texCoord;
layout(location = 2) in vec3 normal;
layout(location = 3) in vec3 tangent;
layout(location = 4) in vec3 binormal;
)=====";
static const std::string PBRfunctions = R"=====(
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

PBRSingleColor PBRSingleColor::instance;

void PBRSingleColor::build() {
    addVertexShader(PBRvertex);
    addFragmentShader(PBRpixelHead + PBRfunctions + R"=====(
// material parameters
layout(location = 3) uniform vec3 albedo;
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
    vec3 limunance = albedo * lightAttenuation(lightPower, lightPosition, position, normal);
//limunance = albedo;
    color = vec4(limunance, 1.0);
})=====");
    linkShaders();
}

void PBRSingleColor::destroy() {
    GL::Shader::destroy();
}

PBRSingleTexture PBRSingleTexture::instance;

void PBRSingleTexture::build() {
    addVertexShader(PBRvertex);
    addFragmentShader(PBRpixelHead + PBRfunctions + R"=====(
// material parameters
layout(location = 3) uniform vec2 texScale;
uniform sampler2D Texture;
layout(location = 4) uniform float metallic;
layout(location = 5) uniform float roughness;
layout(location = 6) uniform float ao;

layout(location = 7) uniform vec3 eyePosition;
layout(location = 8) uniform vec3 lightPosition;
layout(location = 9) uniform vec3 lightColor;
layout(location = 10) uniform float lightRadius;
layout(location = 11) uniform float lightPower;


void main()
{
    vec3 albedo = texture(Texture, texCoord * texScale).rgb;

    vec3 limunance = albedo * lightAttenuation(lightPower, lightPosition, position, normal);
//limunance = albedo;
    color = vec4(limunance, 1.0);
})=====");
    linkShaders();
}

void PBRSingleTexture::destroy() {
    GL::Shader::destroy();
}

PBRColorArray PBRColorArray::instance;

void PBRColorArray::build() {
    addVertexShader(PBRvertex);
    addFragmentShader(PBRpixelHead + PBRfunctions + R"=====(
layout(location = 5) in vec3 COLOR_0;
// material parameters
layout(location = 4) uniform float metallic;
layout(location = 5) uniform float roughness;
layout(location = 6) uniform float ao;

layout(location = 7) uniform vec3 eyePosition;
layout(location = 8) uniform vec3 lightPosition;
layout(location = 9) uniform vec3 lightColor;
layout(location = 10) uniform float lightRadius;
layout(location = 11) uniform float lightPower;


void main()
{
    vec3 limunance = COLOR_0 * lightAttenuation(lightPower, lightPosition, position, normal);
limunance = COLOR_0;
    color = vec4(limunance, 1.0);
})=====");
    linkShaders();
}

void PBRColorArray::destroy() {
    GL::Shader::destroy();
}

} // namespace Blob::Shaders
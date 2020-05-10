#include <Blob/Material.hpp>
#include <Blob/Exception.hpp>

#include <Blob/GL/Core.hpp>
#include <iostream>

namespace Blob{

Material::Material(const GL::ShaderProgram &shaderProgram) : shaderProgramPrivate(shaderProgram) {}

using namespace GL;

/********************* DefaultMaterial *********************/

GL::ShaderProgram *DefaultMaterial::shaderProgram;

DefaultMaterial *DefaultMaterial::defaultMaterial;

int DefaultMaterial::model = -1;
int DefaultMaterial::view = -1;
int DefaultMaterial::projection = -1;

void DefaultMaterial::applyMaterial(const ProjectionTransform &pt, const ViewTransform &vt, const glm::mat4 &mt) const {
    Core::setMat4(&pt[0].x, projection);
    Core::setMat4(&vt[0].x, view);
    Core::setMat4(&mt[0].x, model);
}

DefaultMaterial::DefaultMaterial() : Material(*shaderProgram) {}

void DefaultMaterial::init() {
    std::cout << "init DefaultMaterial" << std::endl;
    shaderProgram = new ShaderProgram(R"=====(
#version 450

layout (location = 0) in vec3 POSITION;
layout (location = 1) in vec3 NORMAL;

out vec3 FragPos;
out vec3 FragNormal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    FragPos = vec3(model * vec4(POSITION, 1.0));
    FragNormal = mat3(transpose(inverse(model))) * NORMAL;

    gl_Position = projection * view * vec4(FragPos, 1.0);
}
	)=====", R"=====(
#version 450

out vec4 FragColor;

in vec3 FragNormal;
in vec3 FragPos;

void main()
{
    vec3 lightPos = vec3(4.0, 4.0, 0.0);
    vec3 lightColor = vec3(1.0, 1.0, 1.0);
    vec4 objectColor = vec4(0.8, 0.8, 0.8, 1.0);
    //
    float ambientStrength = 0.2;
    vec3 ambient = ambientStrength * lightColor;

    // diffuse
    vec3 norm = normalize(FragNormal);
    vec3 lightDir = normalize(vec3(1.0, -1.0, 2.0));
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    FragColor = vec4(ambient + diffuse, 1.0) * objectColor;
}
	)=====");

    defaultMaterial = new DefaultMaterial();
}

void DefaultMaterial::destroy() {
    delete defaultMaterial;
    delete shaderProgram;
}

/********************* SingleColorMaterial *********************/

GL::ShaderProgram *SingleColorMaterial::shaderProgram;

int SingleColorMaterial::model = -1;
int SingleColorMaterial::view = -1;
int SingleColorMaterial::projection = -1;

int SingleColorMaterial::albedoPos = -1;
int SingleColorMaterial::metallicPos = -1;
int SingleColorMaterial::roughnessPos = -1;
int SingleColorMaterial::aoPos = -1;
int SingleColorMaterial::camPos = -1;
int SingleColorMaterial::optionsPos = -1;
Light SingleColorMaterial::light;

SingleColorMaterial::SingleColorMaterial() : Material(*shaderProgram) {}

void SingleColorMaterial::applyMaterial(const ProjectionTransform &pt, const ViewTransform &vt, const glm::mat4 &mt) const {
    Blob::GL::Core::setMat4(&pt[0].x, projection);
    Blob::GL::Core::setMat4(&vt[0].x, view);
    Blob::GL::Core::setMat4(&mt[0].x, model);

    Blob::GL::Core::setVec3(&albedo.R, albedoPos);
    Blob::GL::Core::setFloat(metallic, metallicPos);
    Blob::GL::Core::setFloat(roughness, roughnessPos);
    Blob::GL::Core::setFloat(ao, aoPos);
    Blob::GL::Core::setUint(options, optionsPos);

    Blob::GL::Core::setVec3(&light.position.x, light.positionPos);
    Blob::GL::Core::setVec3(&light.color.R, light.colorPos);

    Blob::GL::Core::setVec3(&vt.cameraPosition.x, camPos);
}
void SingleColorMaterial::init() {
    std::cout << "init SingleColorMaterial" << std::endl;
    shaderProgram = new ShaderProgram(R"=====(
#version 450

layout (location = 0) in vec3 POSITION;
layout (location = 1) in vec3 NORMAL;

out vec3 WorldPos;
out vec3 Normal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    WorldPos = vec3(model * vec4(POSITION, 1.0));
    Normal = mat3(transpose(inverse(model))) * NORMAL;

    gl_Position = projection * view * vec4(WorldPos, 1.0);
}
	)=====",
                                          R"=====(
#version 450
out vec4 FragColor;

in vec3 WorldPos;
in vec3 Normal;

// material parameters
uniform vec3 albedo;
uniform float metallic;
uniform float roughness;
uniform float ao;

uniform uint options;

struct OptionsSt
{
    uint Irradiance;
    uint Radiance;
};
const OptionsSt Options = {1, 2};

// lights
uniform vec3 lightPositions;
uniform vec3 lightColors;

uniform vec3 camPos;

const float PI = 3.14159265359;
// ----------------------------------------------------------------------------
float DistributionGGX(vec3 N, vec3 H, float roughness)
{
    float a = roughness*roughness;
    float a2 = a*a;
    float NdotH = max(dot(N, H), 0.0);
    float NdotH2 = NdotH*NdotH;

    float nom   = a2;
    float denom = (NdotH2 * (a2 - 1.0) + 1.0);
    denom = PI * denom * denom;

    return nom / max(denom, 0.001); // prevent divide by zero for roughness=0.0 and NdotH=1.0
}
// ----------------------------------------------------------------------------
float GeometrySchlickGGX(float NdotV, float roughness)
{
    float r = (roughness + 1.0);
    float k = (r*r) / 8.0;

    float nom   = NdotV;
    float denom = NdotV * (1.0 - k) + k;

    return nom / denom;
}
// ----------------------------------------------------------------------------
float GeometrySmith(vec3 N, vec3 V, vec3 L, float roughness)
{
    float NdotV = max(dot(N, V), 0.0);
    float NdotL = max(dot(N, L), 0.0);
    float ggx2 = GeometrySchlickGGX(NdotV, roughness);
    float ggx1 = GeometrySchlickGGX(NdotL, roughness);

    return ggx1 * ggx2;
}
// ----------------------------------------------------------------------------
vec3 fresnelSchlick(float cosTheta, vec3 F0)
{
    return F0 + (1.0 - F0) * pow(1.0 - cosTheta, 5.0);
}

// ----------------------------------------------------------------------------
// basic function to be opti
vec3 EnvRemap(vec3 c)
{
    return pow(2. * c, vec3(2.2));
}
float saturate(float x)
{
    return clamp(x, 0., 1.);
}
vec3 saturate(vec3 x)
{
    return clamp(x, vec3(0.), vec3(1.));
}
// ----------------------------------------------------------------------------
void main()
{
    // Pixel normal
    vec3 N = normalize(Normal);

    // position to camera
    vec3 V = normalize(camPos - WorldPos);

    // calculate reflectance at normal incidence; if dia-electric (like plastic) use F0
    // of 0.04 and if it's a metal, use the albedo color as F0 (metallic workflow)
    vec3 F0 = vec3(0.04);
    F0 = mix(F0, albedo, metallic);

    // L the light dirrection
    //vec3 L = normalize(lightPositions - WorldPos);
    // Fixed Sun light dir
    vec3 L = normalize(lightPositions);

    vec3 H = normalize(V + L);
    float distance = length(lightPositions - WorldPos);
    float attenuation = 1.0 / (distance * distance);
    vec3 radiance = lightColors * attenuation;

    // Cook-Torrance BRDF
    float NDF = DistributionGGX(N, H, roughness);
    float G   = GeometrySmith(N, V, L, roughness);
    vec3 F    = fresnelSchlick(clamp(dot(H, V), 0.0, 1.0), F0);

    vec3 nominator    = NDF * G * F;
    float denominator = 4.0 * max(dot(N, V), 0.0) * max(dot(N, L), 0.0);
    vec3 specular = nominator / max(denominator, 0.001); // prevent divide by zero for NdotV=0.0 or NdotL=0.0

    // kS is equal to Fresnel
    vec3 kS = F;
    // for energy conservation, the diffuse and specular light can't
    // be above 1.0 (unless the surface emits light); to preserve this
    // relationship the diffuse component (kD) should equal 1.0 - kS.
    vec3 kD = vec3(1.0) - kS;
    // multiply kD by the inverse metalness such that only non-metals
    // have diffuse lighting, or a linear blend if partly metal (pure metals
    // have no diffuse light).
    kD *= 1.0 - metallic;

    // scale light by NdotL
    float NdotL = max(dot(N, L), 0.0);

    // add to outgoing radiance Lo
    vec3 Lo = (kD * albedo / PI + specular) * radiance * NdotL;  // note that we already multiplied the BRDF by the Fresnel (kS) so we won't multiply by kS again

    // ambient lighting.
    vec3 ambient = vec3(0);

    if((options & Options.Radiance) != 0)
        ambient += albedo * lightColors * NdotL;
        //ambient += radiance;

    if((options & Options.Irradiance) != 0)
        ambient += albedo * lightColors * pow((dot(N, vec3(0,0,1)) + vec3(1.5))/5, vec3(2.2));
        //ambient += F;

    //vec3 color = ambient + Lo;
    vec3 color = ambient;

    // HDR tonemapping
    //color = color / (color + vec3(1.0));
    // gamma correct
    //color = pow(color, vec3(1.0/2.2));

    FragColor = vec4(color, 1.0);
}
	)=====");
    model = shaderProgram->getUniformLocation("model");
    view = shaderProgram->getUniformLocation("view");
    projection = shaderProgram->getUniformLocation("projection");

    try {
        albedoPos = shaderProgram->getUniformLocation("albedo");
    } catch (Exception) {}
    try {
        metallicPos = shaderProgram->getUniformLocation("metallic");
    } catch (Exception) {}
    try {
        roughnessPos = shaderProgram->getUniformLocation("roughness");
    } catch (Exception) {}
    try {
        aoPos = shaderProgram->getUniformLocation("ao");
    } catch (Exception) {}
    try {
        light.positionPos = shaderProgram->getUniformLocation("lightPositions");
    } catch (Exception) {}
    try {
        light.colorPos = shaderProgram->getUniformLocation("lightColors");
    } catch (Exception) {}
    try {
        camPos = shaderProgram->getUniformLocation("camPos");
    } catch (Exception) {}
    try {
        optionsPos = shaderProgram->getUniformLocation("options");
    } catch (Exception) {}
}

void SingleColorMaterial::destroy() {
    delete shaderProgram;
}
}
#include <Blob/Exception.hpp>
#include <Blob/Material.hpp>

#include <Blob/GL/Core.hpp>
#include <iostream>

namespace Blob {

Material::Material(const GL::ShaderProgram &shaderProgram) : shaderProgramPrivate(shaderProgram) {}

Material *Material::defaultMaterial;

using namespace GL;

/********************* PBR code *********************/

static const std::string PBRvertex = R"=====(
#version 450

layout (location = 0) in vec3 POSITION;
layout (location = 1) in vec3 NORMAL;
layout (location = 2) in vec3 TANGENT;
layout (location = 3) in vec2 TEXCOORD_0;
layout (location = 4) in vec2 TEXCOORD_1;
layout (location = 5) in vec3 COLOR_0;
layout (location = 6) in vec3 JOINTS_0;
layout (location = 7) in vec3 WEIGHTS_0;

out vec3 WorldPos;
out vec3 Normal;
out vec2 TexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
    WorldPos = vec3(model * vec4(POSITION, 1.0));
    Normal = mat3(transpose(inverse(model))) * NORMAL;
    TexCoord = TEXCOORD_0;
    gl_Position = projection * view * vec4(WorldPos, 1.0);
})=====";
static const std::string PBRpixelHead = R"=====(
#version 450
out vec4 FragColor;

in vec3 WorldPos;
in vec3 Normal;
in vec2 TexCoord;
)=====";
static const std::string PBRfunctions = R"=====(
const float PI = 3.14159265359;
// ----------------------------------------------------------------------------
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
})=====";

/********************* PBRMaterial *********************/
Light PBRMaterial::light;
/********************* SingleColorMaterialPBR *********************/

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
LightPos SingleColorMaterial::lightPos;

SingleColorMaterial::SingleColorMaterial() : Material(*shaderProgram) {}

SingleColorMaterial::SingleColorMaterial(Color albedo) : Material(*shaderProgram), albedo(albedo) {}

void SingleColorMaterial::applyMaterial(const ProjectionTransform &pt, const ViewTransform &vt, const glm::mat4 &mt) const {
    Blob::GL::Core::setMat4(&pt[0].x, projection);
    Blob::GL::Core::setMat4(&vt[0].x, view);
    Blob::GL::Core::setMat4(&mt[0].x, model);

    Blob::GL::Core::setVec3(&albedo.R, albedoPos);
    Blob::GL::Core::setFloat(metallic, metallicPos);
    Blob::GL::Core::setFloat(roughness, roughnessPos);
    Blob::GL::Core::setFloat(ao, aoPos);
    Blob::GL::Core::setUint(options, optionsPos);

    Blob::GL::Core::setVec3(&light.position.x, lightPos.position);
    Blob::GL::Core::setVec3(&light.color.R, lightPos.color);

    Blob::GL::Core::setVec3(&vt.cameraPosition.x, camPos);
}

void SingleColorMaterial::init() {
    std::cout << "init SingleColorMaterial" << std::endl;
    shaderProgram = new ShaderProgram(PBRvertex, PBRpixelHead + PBRfunctions +
                                                     R"=====(
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

void main()
{
vec3 N = normalize(Normal);
    vec3 V = normalize(camPos - WorldPos);// position to camera

    // calculate reflectance at normal incidence; if dia-electric (like plastic) use F0
    // of 0.04 and if it's a metal, use the albedo color as F0 (metallic workflow)
    vec3 F0 = vec3(0.04);
    F0 = mix(F0, albedo, metallic);

    // L the light dirrection
    vec3 L = normalize(lightPositions - WorldPos);

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
    vec3 ambient = vec3(0.03) * albedo * ao;

    //if((options & Options.Radiance) != 0)
        //ambient += albedo * lightColors * NdotL;
        //ambient += radiance;

    //if((options & Options.Irradiance) != 0)
        //ambient += albedo * lightColors * pow((dot(N, vec3(0,0,1)) + vec3(1.5))/5, vec3(2.2));
        //ambient += F;

    vec3 color = ambient + Lo;
    //vec3 color = ambient;

    // HDR tonemapping
    color = color / (color + vec3(1.0));
    // gamma correct
    color = pow(color, vec3(1.0/2.2));

    FragColor = vec4(color, 1.0);
})=====");
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
        lightPos.position = shaderProgram->getUniformLocation("lightPositions");
    } catch (Exception) {}
    try {
        lightPos.color = shaderProgram->getUniformLocation("lightColors");
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

/********************* SingleTextureMaterialPBR *********************/

GL::ShaderProgram *SingleTextureMaterial::shaderProgram;

int SingleTextureMaterial::model = -1;
int SingleTextureMaterial::view = -1;
int SingleTextureMaterial::projection = -1;

int SingleTextureMaterial::textureScalePos = -1;
int SingleTextureMaterial::metallicPos = -1;
int SingleTextureMaterial::roughnessPos = -1;
int SingleTextureMaterial::aoPos = -1;
int SingleTextureMaterial::camPos = -1;
int SingleTextureMaterial::optionsPos = -1;
LightPos SingleTextureMaterial::lightPos;

SingleTextureMaterial::SingleTextureMaterial(const Blob::GL::Texture &texture) : Material(*shaderProgram), texture(texture) {}

void SingleTextureMaterial::applyMaterial(const ProjectionTransform &pt, const ViewTransform &vt, const glm::mat4 &mt) const {
    Blob::GL::Core::setMat4(&pt[0].x, projection);
    Blob::GL::Core::setMat4(&vt[0].x, view);
    Blob::GL::Core::setMat4(&mt[0].x, model);

    Blob::GL::Core::setTexture(texture);
    Blob::GL::Core::setVec2(texScale, textureScalePos);

    Blob::GL::Core::setFloat(metallic, metallicPos);
    Blob::GL::Core::setFloat(roughness, roughnessPos);
    Blob::GL::Core::setFloat(ao, aoPos);
    Blob::GL::Core::setUint(options, optionsPos);

    Blob::GL::Core::setVec3(&light.position.x, lightPos.position);
    Blob::GL::Core::setVec3(&light.color.R, lightPos.color);

    Blob::GL::Core::setVec3(&vt.cameraPosition.x, camPos);
}

void SingleTextureMaterial::init() {
    std::cout << "init SingleTextureMaterial" << std::endl;
    shaderProgram = new ShaderProgram(PBRvertex, PBRpixelHead + PBRfunctions +
                                                     R"=====(
// texture
uniform vec2 texScale;
uniform sampler2D Texture;

// material parameters
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

void main()
{
    vec3 albedo = texture(Texture, TexCoord * texScale).rgb;
    //vec3 albedo = vec3(texture(Texture, TexCoord));
    //vec3 albedo = vec3(TexCoord, 0.0f);

    vec3 N = normalize(Normal);
    vec3 V = normalize(camPos - WorldPos);// position to camera

    // calculate reflectance at normal incidence; if dia-electric (like plastic) use F0
    // of 0.04 and if it's a metal, use the albedo color as F0 (metallic workflow)
    vec3 F0 = vec3(0.04);
    F0 = mix(F0, albedo, metallic);

    // L the light dirrection
    vec3 L = normalize(lightPositions - WorldPos);

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
    vec3 ambient = vec3(0.03) * albedo * ao;

    //if((options & Options.Radiance) != 0)
        //ambient += albedo * lightColors * NdotL;
        //ambient += radiance;

    //if((options & Options.Irradiance) != 0)
        //ambient += albedo * lightColors * pow((dot(N, vec3(0,0,1)) + vec3(1.5))/5, vec3(2.2));
        //ambient += F;

    vec3 color = ambient + Lo;
    //vec3 color = ambient;

    // HDR tonemapping
    color = color / (color + vec3(1.0));
    // gamma correct
    color = pow(color, vec3(1.0/2.2));

    FragColor = vec4(color, 1.0);
})=====");
    model = shaderProgram->getUniformLocation("model");
    view = shaderProgram->getUniformLocation("view");
    projection = shaderProgram->getUniformLocation("projection");

    try {
        textureScalePos = shaderProgram->getUniformLocation("texScale");
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
        lightPos.position = shaderProgram->getUniformLocation("lightPositions");
    } catch (Exception) {}
    try {
        lightPos.color = shaderProgram->getUniformLocation("lightColors");
    } catch (Exception) {}
    try {
        camPos = shaderProgram->getUniformLocation("camPos");
    } catch (Exception) {}
    try {
        optionsPos = shaderProgram->getUniformLocation("options");
    } catch (Exception) {}
}

void SingleTextureMaterial::destroy() {
    delete shaderProgram;
}
} // namespace Blob
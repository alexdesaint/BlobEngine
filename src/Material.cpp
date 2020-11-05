#include <Blob/Material.hpp>
#include <Blob/Exception.hpp>

#include <Blob/GL/Core.hpp>
#include <iostream>

namespace Blob::Material {

    Material::Material(const GL::ShaderProgram &shaderProgram) : shaderProgramPrivate(shaderProgram) {}

/********************* DefaultMaterial *********************/

    GL::ShaderProgram *DefaultMaterial::shaderProgram;

    DefaultMaterial *DefaultMaterial::defaultMaterial;

    int DefaultMaterial::model = -1;
    int DefaultMaterial::view = -1;
    int DefaultMaterial::projection = -1;

    void
    DefaultMaterial::applyMaterial(const Maths::ProjectionTransform &pt, const Maths::ViewTransform &vt, const Maths::Mat4 &mt) const {
        GL::Core::setCullFace(false);

        Blob::GL::Core::setUniform(pt, projection);
        Blob::GL::Core::setUniform(vt, view);
        Blob::GL::Core::setUniform(mt, model);

        GL::Core::setCullFace(true);
    }

    DefaultMaterial::DefaultMaterial() : Material(*shaderProgram) {}

    void DefaultMaterial::init() {
        std::cout << "init DefaultMaterial" << std::endl;
        shaderProgram = new GL::ShaderProgram(R"=====(
#version 450

layout(location = 0) in vec3 POSITION;
layout(location = 1) in vec3 NORMAL;

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

in vec3 FragPos;
in vec3 FragNormal;

void main()
{
    vec3 lightPos = vec3(4.0, 4.0, 0.0);
    vec3 lightColor = vec3(1.0, 1.0, 1.0);
    vec4 objectColor = vec4(1, 1, 1, 1.0);
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
        model = shaderProgram->getUniformLocation("model");
        view = shaderProgram->getUniformLocation("view");
        projection = shaderProgram->getUniformLocation("projection");

        defaultMaterial = new DefaultMaterial();
    }

    void DefaultMaterial::destroy() {
        delete defaultMaterial;
        delete shaderProgram;
    }

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
float MathsSchlickGGX(float NdotV, float roughness)
{
    float r = (roughness + 1.0);
    float k = (r*r) / 8.0;

    float nom   = NdotV;
    float denom = NdotV * (1.0 - k) + k;

    return nom / denom;
}
// ----------------------------------------------------------------------------
float MathsSmith(vec3 N, vec3 V, vec3 L, float roughness)
{
    float NdotV = max(dot(N, V), 0.0);
    float NdotL = max(dot(N, L), 0.0);
    float ggx2 = MathsSchlickGGX(NdotV, roughness);
    float ggx1 = MathsSchlickGGX(NdotL, roughness);

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

    SingleColorMaterial::SingleColorMaterial(Color::RGB albedo) : Material(*shaderProgram), albedo(albedo) {}

    void SingleColorMaterial::applyMaterial(const Maths::ProjectionTransform &pt, const Maths::ViewTransform &vt, const Maths::Mat4 &mt) const {
        Blob::GL::Core::setUniform(pt, projection);
        Blob::GL::Core::setUniform(vt, view);
        Blob::GL::Core::setUniform(mt, model);

        Blob::GL::Core::setUniform(albedo, albedoPos);
        Blob::GL::Core::setUniform(metallic, metallicPos);
        Blob::GL::Core::setUniform(roughness, roughnessPos);
        Blob::GL::Core::setUniform(ao, aoPos);
        Blob::GL::Core::setUniform(options, optionsPos);

        Blob::GL::Core::setUniform(light.position, lightPos.position);
        Blob::GL::Core::setUniform(light.color, lightPos.color);

        Blob::GL::Core::setUniform(vt.cameraPosition, camPos);
    }

    void SingleColorMaterial::init() {
        std::cout << "init SingleColorMaterial" << std::endl;
        shaderProgram = new GL::ShaderProgram(PBRvertex, PBRpixelHead + PBRfunctions +
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
    // Pixel normal
    vec3 N = normalize(Normal);

    // position to camera
    vec3 V = normalize(camPos - WorldPos);

    // calculate reflectance at normal incidence; if dia-electric (like plastic) use F0
    // of 0.04 and if it's a metal, use the albedo color as F0 (metallic workflow)
    vec3 F0 = vec3(0.04);
    F0 = mix(F0, albedo, metallic);

    // L the light dirrection
    vec3 L = normalize(lightPositions - WorldPos);
    // Fixed Sun light dir
    // vec3 L = normalize(lightPositions);

    vec3 H = normalize(V + L);
    float distance = length(lightPositions - WorldPos);
    float attenuation = 1.0 / (distance * distance);
    vec3 radiance = lightColors * attenuation;

    // Cook-Torrance BRDF
    float NDF = DistributionGGX(N, H, roughness);
    float G   = MathsSmith(N, V, L, roughness);
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
})=====");
        model = shaderProgram->getUniformLocation("model");
        view = shaderProgram->getUniformLocation("view");
        projection = shaderProgram->getUniformLocation("projection");

        try {
            albedoPos = shaderProgram->getUniformLocation("albedo");
        } catch (Core::Exception) {}
        try {
            metallicPos = shaderProgram->getUniformLocation("metallic");
        } catch (Core::Exception) {}
        try {
            roughnessPos = shaderProgram->getUniformLocation("roughness");
        } catch (Core::Exception) {}
        try {
            aoPos = shaderProgram->getUniformLocation("ao");
        } catch (Core::Exception) {}
        try {
            lightPos.position = shaderProgram->getUniformLocation("lightPositions");
        } catch (Core::Exception) {}
        try {
            lightPos.color = shaderProgram->getUniformLocation("lightColors");
        } catch (Core::Exception) {}
        try {
            camPos = shaderProgram->getUniformLocation("camPos");
        } catch (Core::Exception) {}
        try {
            optionsPos = shaderProgram->getUniformLocation("options");
        } catch (Core::Exception) {}
    }

    void SingleColorMaterial::destroy() {
        delete shaderProgram;
    }

    void addBasicShaders() {

        std::cout << "add Basic Shaders" << std::endl;

        {
            Blob::GL::ShaderProgram &sp = Blob::GL::ShaderProgram::Shaders["POSITION_NORMAL_TEXCOORD_0"];
            sp.addVertexShader(R"=====(
	#version 450

	layout (location = 0) in vec3 POSITION;
	layout (location = 1) in vec3 NORMAL;
	layout (location = 2) in vec2 TEXCOORD_0;

	out vec3 FragPos;
	out vec3 FragNormal;
	out vec2 TexCoord;

	uniform mat4 model;
	uniform mat4 view;
	uniform mat4 projection;

	void main()
	{
		FragPos = vec3(model * vec4(POSITION, 1.0));
		FragNormal = mat3(transpose(inverse(model))) * NORMAL;

		gl_Position = projection * view * vec4(FragPos, 1.0);

		TexCoord = TEXCOORD_0;
	}
	)=====");
            sp.addFragmentShader(R"=====(
	#version 450

	out vec4 FragColor;

	in vec3 FragNormal;
	in vec3 FragPos;
	in vec2 TexCoord;

	uniform sampler2D ourTexture;
	uniform vec2 texScale;

	void main()
	{
		vec3 lightPos = vec3(4.0, 4.0, 0.0);
		vec3 lightColor = vec3(1.0, 1.0, 1.0);
		vec4 objectColor = texture(ourTexture, TexCoord * texScale);
		//
		float ambientStrength = 0.2;
		vec3 ambient = ambientStrength * lightColor;

		// diffuse
		vec3 norm = normalize(FragNormal);
		vec3 lightDir = normalize(vec3(1.0, -1.0, 2.0));
		float diff = max(dot(norm, lightDir), 0.0);
		vec3 diffuse = diff * lightColor;

		FragColor = vec4(ambient + diffuse, 1.0) * objectColor;
	})=====");
            sp.linkShaders();
        }
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

    SingleTextureMaterial::SingleTextureMaterial(const Blob::GL::Texture &texture) : Material(*shaderProgram),
                                                                                     texture(texture) {}

    void SingleTextureMaterial::applyMaterial(const Maths::ProjectionTransform &pt, const Maths::ViewTransform &vt, const Maths::Mat4 &mt) const {
        Blob::GL::Core::setUniform(pt, projection);
        Blob::GL::Core::setUniform(vt, view);
        Blob::GL::Core::setUniform(mt, model);

        Blob::GL::Core::setTexture(texture);
        Blob::GL::Core::setUniform(texScale, textureScalePos);

        Blob::GL::Core::setUniform(metallic, metallicPos);
        Blob::GL::Core::setUniform(roughness, roughnessPos);
        Blob::GL::Core::setUniform(ao, aoPos);
        Blob::GL::Core::setUniform(options, optionsPos);

        Blob::GL::Core::setUniform(light.position, lightPos.position);
        Blob::GL::Core::setUniform(light.color, lightPos.color);

        Blob::GL::Core::setUniform(vt.cameraPosition, camPos);
    }

    void SingleTextureMaterial::init() {
        std::cout << "init SingleTextureMaterial" << std::endl;
        shaderProgram = new GL::ShaderProgram(PBRvertex, PBRpixelHead + PBRfunctions +
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
    vec3 albedo = vec3(texture(Texture, TexCoord * texScale));

    // Pixel normal
    vec3 N = normalize(Normal);

    // position to camera
    vec3 V = normalize(camPos - WorldPos);

    // calculate reflectance at normal incidence; if dia-electric (like plastic) use F0
    // of 0.04 and if it's a metal, use the albedo color as F0 (metallic workflow)
    vec3 F0 = vec3(0.04);
    F0 = mix(F0, albedo, metallic);

    // L the light dirrection
    vec3 L = normalize(lightPositions - WorldPos);
    // Fixed Sun light dir
    // vec3 L = normalize(lightPositions);

    vec3 H = normalize(V + L);
    float distance = length(lightPositions - WorldPos);
    float attenuation = 1.0 / (distance * distance);
    vec3 radiance = lightColors * attenuation;

    // Cook-Torrance BRDF
    float NDF = DistributionGGX(N, H, roughness);
    float G   = MathsSmith(N, V, L, roughness);
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
})=====");
        model = shaderProgram->getUniformLocation("model");
        view = shaderProgram->getUniformLocation("view");
        projection = shaderProgram->getUniformLocation("projection");

        try {
            textureScalePos = shaderProgram->getUniformLocation("texScale");
        } catch (Core::Exception) {}
        try {
            metallicPos = shaderProgram->getUniformLocation("metallic");
        } catch (Core::Exception) {}
        try {
            roughnessPos = shaderProgram->getUniformLocation("roughness");
        } catch (Core::Exception) {}
        try {
            aoPos = shaderProgram->getUniformLocation("ao");
        } catch (Core::Exception) {}
        try {
            lightPos.position = shaderProgram->getUniformLocation("lightPositions");
        } catch (Core::Exception) {}
        try {
            lightPos.color = shaderProgram->getUniformLocation("lightColors");
        } catch (Core::Exception) {}
        try {
            camPos = shaderProgram->getUniformLocation("camPos");
        } catch (Core::Exception) {}
        try {
            optionsPos = shaderProgram->getUniformLocation("options");
        } catch (Core::Exception) {}
    }

    void SingleTextureMaterial::destroy() {
        delete shaderProgram;
    }
}
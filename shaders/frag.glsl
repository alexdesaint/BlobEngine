#version 450

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 texCoord;
layout(location = 2) in vec2 texCoord1;
layout(location = 3) in vec3 normal;
layout(location = 4) in vec3 tangent;
layout(location = 5) in vec3 binormal;
layout(location = 6) in vec3 color;

layout(location = 3) uniform vec4 albedo;
layout(location = 4) uniform vec2 texScale;

layout(location = 5) uniform float metallic;
layout(location = 6) uniform float roughness;
layout(location = 7) uniform float ao;

layout(location = 8) uniform vec3 eyePosition;
layout(location = 9) uniform vec3 lightPosition;
layout(location = 10) uniform vec3 lightColor;
layout(location = 11) uniform float lightRadius;
layout(location = 12) uniform float lightPower;

layout(location = 0) out vec4 outColor;

uniform sampler2D Texture;

void singleColor() {
    outColor = albedo;
}

void singleTexture() {
    outColor = texture(Texture, texCoord * texScale);
}

const float PI = 3.14159265359;
const float Epsilon = 0.00001;
const vec3 Fdielectric = vec3(0.04);

// GGX/Towbridge-Reitz normal distribution function.
// Uses Disney's reparametrization of alpha = roughness^2.

float ndfGGX(float cosLh, float roughness) {
    float alpha = roughness * roughness;
    float alphaSq = alpha * alpha;

    float denom = (cosLh * cosLh) * (alphaSq - 1.0) + 1.0;
    return alphaSq / (PI * denom * denom);
}

// Single term for separable Schlick-GGX below.
float gaSchlickG1(float cosTheta, float k) {
    return cosTheta / (cosTheta * (1.0 - k) + k);
}

// Schlick-GGX approximation of geometric attenuation function using Smith's
// method.
float gaSchlickGGX(float cosLi, float cosLo, float roughness) {
    float r = roughness + 1.0;
    float k = (r * r) / 8.0; // Epic suggests using this roughness remapping for
                             // analytic lights.
    return gaSchlickG1(cosLi, k) * gaSchlickG1(cosLo, k);
}

// Shlick's approximation of the Fresnel factor.
vec3 fresnelSchlick(vec3 F0, float cosTheta) {
    return F0 + (vec3(1.0) - F0) * pow(1.0 - cosTheta, 5.0);
}

// Light attenuation

float smoothDistanceAtt(float squaredDistance, float invSqrAttRadius) {
    float factor = squaredDistance * invSqrAttRadius;
    float smoothFactor = clamp(1.0f - factor * factor, 0.0, 1.0);
    return smoothFactor * smoothFactor;
}

float getDistanceAtt(float lightPower, vec3 unormalizedLightVector) {
    float sqrDist = dot(unormalizedLightVector, unormalizedLightVector);
    float attenuation = lightPower / (max(sqrDist, 0.01 * 0.01));
    return clamp(attenuation, 0.0, 1.0);
}

float getDistanceAttRadius(float lightPower,
                           float lightRadius,
                           vec3 unormalizedLightVector) {
    float sqrDist = dot(unormalizedLightVector, unormalizedLightVector);
    float attenuation = lightPower / (max(sqrDist, 0.01 * 0.01));
    attenuation *=
        smoothDistanceAtt(sqrDist, 1.0 / (lightRadius * lightRadius));
    return clamp(attenuation, 0.0, 1.0);
}

// TODO: use
float getAngleAtt(vec3 normalizedLightVector,
                  vec3 lightDir,
                  float lightAngleScale,
                  float lightAngleOffset) {
    float cd = dot(lightDir, normalizedLightVector);
    float attenuation =
        clamp(cd * lightAngleScale + lightAngleOffset, 0.0, 1.0);
    //  smooth  the  transition
    attenuation *= attenuation;
    return attenuation;
}

float lightAttenuation(float lightPower,
                       vec3 lightPosition,
                       vec3 worldPos,
                       vec3 N) {
    vec3 unnormalizedLightVector = lightPosition - worldPos;
    vec3 L = normalize(unnormalizedLightVector);
    float att = 1;
    att *= getDistanceAtt(lightPower, unnormalizedLightVector);
    att *= clamp(dot(N, L), 0.0, 1.0);
    // att *=  getAngleAtt(L, lightForward, lightAngleScale, lightAngleOffset);
    return att;
}

float sunlight(float lightPower, vec3 lightVector, vec3 N) {
    return lightPower * clamp(dot(N, normalize(lightVector)), 0.0, 1.0);
}

// Light attenuation with a limited radius
float lightAttenuationLocale(float lightPower,
                             float lightRadius,
                             vec3 lightPosition,
                             vec3 worldPos,
                             vec3 N) {
    vec3 unnormalizedLightVector = lightPosition - worldPos;
    vec3 L = normalize(unnormalizedLightVector);
    float att = 1;
    att *=
        getDistanceAttRadius(lightPower, lightRadius, unnormalizedLightVector);
    att *= clamp(dot(N, L), 0.0, 1.0);
    // att *=  getAngleAtt(L, lightForward, lightAngleScale, lightAngleOffset);
    return att;
}

void PBRsingleColor() {
    outColor =
        vec4(albedo.rgb * max(sunlight(lightPower, lightPosition, normal), ao),
             // lightAttenuation(lightPower, lightPosition, position, normal),
             albedo.a);
}

void PBRsingleTexture() {
    outColor = texture(Texture, texCoord * texScale);

    outColor =
        vec4(albedo.rgb *
                 lightAttenuation(lightPower, lightPosition, position, normal),
             albedo.a * outColor.a);
}

void PBRcolorArray() {
    vec3 luminance =
        color * lightAttenuation(lightPower, lightPosition, position, normal);
    outColor = vec4(luminance, 1.0);
}

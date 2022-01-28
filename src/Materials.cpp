#include <Blob/Buffer.hpp>
#include <Blob/Materials.hpp>
#include <Blob/Window.hpp>

#include <shaders/f_colorArray.h>
#include <shaders/v_normal.h>

namespace Blob::Materials2D {

/********************* SingleColor *********************/

SingleColor::SingleColor(const Color::RGBA &albedo) :
    shader(MaterialShader::getInstance(Buffer{v_normal}, Buffer{f_colorArray})),
    albedo(albedo) {}

void SingleColor::applyMaterial() const {
    shader->setAttributes(albedo);
    bgfx::setState(BGFX_STATE_DEFAULT);
    bgfx::submit(0, shader->shaderHandle);
}

/********************* SingleTexture *********************/

SingleColorSingleTexture::SingleColorSingleTexture(const Texture &texture,
                                                   const Color::RGBA &albedo) :
    shader(MaterialShader::getInstance(Buffer{v_normal}, Buffer{f_colorArray})),
    texture(texture),
    albedo(albedo) {}

void SingleColorSingleTexture::applyMaterial() const {
    shader->setAttributes(albedo);
    bgfx::setState(BGFX_STATE_DEFAULT);
    bgfx::submit(0, shader->shaderHandle);
}

} // namespace Blob::Materials2D

namespace Blob::Materials {

/********************* SingleColor *********************/

SingleColor::SingleColor(const Color::RGBA &albedo) :
    shader(MaterialShader::getInstance(Buffer{v_normal}, Buffer{f_colorArray})),
    albedo(albedo) {}

void SingleColor::applyMaterial() const {
    shader->setAttributes(albedo);
    bgfx::setState(BGFX_STATE_DEFAULT);
    bgfx::submit(0, shader->shaderHandle);
}

/********************* SingleTexture *********************/

SingleTexture::SingleTexture(const Texture &texture,
                             const Vec2<> &texScale,
                             const Color::RGBA &albedo) :
    shader(MaterialShader::getInstance(Buffer{v_normal}, Buffer{f_colorArray})),
    texture(texture),
    texScale(texScale),
    albedo(albedo) {}

void SingleTexture::applyMaterial() const {
    shader->setAttributes(texScale);
    bgfx::setState(BGFX_STATE_DEFAULT);
    bgfx::submit(0, shader->shaderHandle);
}

/********************* PerFaceNormal *********************/

void PerFaceNormal::applyMaterial() const {
    shader->setAttributes(albedo, length);
    bgfx::setState(BGFX_STATE_DEFAULT);
    bgfx::submit(0, shader->shaderHandle);
}

/********************* PBR *********************/

Light PBR::light;

/********************* PBRSingleColor *********************/

PBRSingleColor::PBRSingleColor(const Color::RGBA &albedo) :
    shader(MaterialShader::getInstance(Buffer{v_normal}, Buffer{f_colorArray})),
    albedo(albedo) {}

void PBRSingleColor::applyMaterial() const {
    shader->setAttributes(albedo,
                          metallic,
                          roughness,
                          ao,
                          light.position,
                          light.color,
                          light.radius,
                          light.power);
    bgfx::setState(BGFX_STATE_DEFAULT);
    bgfx::submit(0, shader->shaderHandle);
}

/********************* PBRSingleColorInstanced *********************/

void PBRSingleColorInstanced::applyMaterial() const {
    shader->setAttributes(albedo,
                          metallic,
                          roughness,
                          ao,
                          light.position,
                          light.color,
                          light.radius,
                          light.power);
    bgfx::setState(BGFX_STATE_DEFAULT);
    bgfx::submit(0, shader->shaderHandle);
}

/********************* PBRSingleTexture *********************/

PBRSingleTexture::PBRSingleTexture(const Texture &texture,
                                   const Vec2<> &texScale,
                                   const Color::RGBA &albedo) :
    shader(MaterialShader::getInstance(Buffer{v_normal}, Buffer{f_colorArray})),
    texture(texture),
    texScale(texScale),
    albedo(albedo) {}

void PBRSingleTexture::applyMaterial() const {
    shader->setAttributes(texScale,
                          metallic,
                          roughness,
                          ao,
                          light.position,
                          light.color,
                          light.radius,
                          light.power);
    bgfx::setState(BGFX_STATE_DEFAULT);
    bgfx::submit(0, shader->shaderHandle);
}

/********************* PBRColorArray *********************/

void PBRColorArray::applyMaterial() const {
    shader->setAttributes(metallic,
                          roughness,
                          ao,
                          light.position,
                          light.color,
                          light.radius,
                          light.power);
    bgfx::setState(BGFX_STATE_DEFAULT);
    bgfx::submit(0, shader->shaderHandle);
}

/********************* PBRWater *********************/

void PBRWater::applyMaterial() const {
    shader->setAttributes(albedo,
                          metallic,
                          roughness,
                          ao,
                          light.position,
                          light.color,
                          light.radius,
                          light.power,
                          //(float) Window::totalTimeFlow,
                          (float) 0.0);
    bgfx::setState(BGFX_STATE_DEFAULT);
    bgfx::submit(0, shader->shaderHandle);
}

} // namespace Blob::Materials
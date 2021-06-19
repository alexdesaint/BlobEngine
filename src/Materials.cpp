#include "Blob/Maths.inl"
#include "JustOneMoreTime/Texture.hpp"
#include <Blob/Core/Window.hpp>
#include <Blob/Materials.hpp>

namespace Blob::Materials {

void SingleColor2D::applyMaterial(const Maths::ProjectionTransform2D &pt, const Maths::ViewTransform2D &vt, const Maths::Mat3 &mt) const {
    shader->setAttributes(mt, vt, pt, albedo);
}

SingleColor2D::SingleColor2D(Color::RGBA albedo) : albedo(albedo) {}

SingleColor2D::SingleColor2D(Color::RGB albedo, float alpha) : albedo(albedo, alpha) {}

void SingleColorSingleTexture2D::applyMaterial(const Maths::ProjectionTransform2D &pt, const Maths::ViewTransform2D &vt, const Maths::Mat3 &mt) const {
    shader->setAttributes(mt, vt, pt, albedo, texture);
}

SingleColorSingleTexture2D::SingleColorSingleTexture2D(const Core::Texture &texture) : texture(texture) {}
SingleColorSingleTexture2D::SingleColorSingleTexture2D(const Core::Texture &texture, const Color::RGBA &albedo) : texture(texture), albedo(albedo) {}

SingleColor::SingleColor(Color::RGB albedo) : albedo(albedo) {}

void SingleColor::applyMaterial(const Maths::ProjectionTransform &pt, const Maths::ViewTransform &vt, const Maths::Mat4 &mt) const {
    shader->setAttributes(mt, vt, pt, albedo);
}

SingleColorTransparent::SingleColorTransparent(Color::RGBA albedo) : albedo(albedo) {}
SingleColorTransparent::SingleColorTransparent(Color::RGB albedo, float a) : albedo(albedo, a) {}

void SingleColorTransparent::applyMaterial(const Maths::ProjectionTransform &pt, const Maths::ViewTransform &vt, const Maths::Mat4 &mt) const {
    shader->setAttributes(mt, vt, pt, albedo);
}

SingleTexture::SingleTexture(const Core::Texture &texture) : texture(texture) {}

void SingleTexture::applyMaterial(const Maths::ProjectionTransform &pt, const Maths::ViewTransform &vt, const Maths::Mat4 &mt) const {
    shader->setAttributes(mt, vt, pt, texScale, texture);
}

/********************* Utils *********************/

PerFaceNormal::PerFaceNormal(Color::RGB albedo) : albedo(albedo) {}

void PerFaceNormal::applyMaterial(const Maths::ProjectionTransform &pt, const Maths::ViewTransform &vt, const Maths::Mat4 &mt) const {
    shader->setAttributes(mt, vt, pt, albedo, length);
}

/********************* PBR *********************/
Light PBR::light;
/********************* PBRSingleColor *********************/

PBRSingleColor::PBRSingleColor(Color::RGB albedo) : albedo(albedo) {}

void PBRSingleColor::applyMaterial(const Maths::ProjectionTransform &pt, const Maths::ViewTransform &vt, const Maths::Mat4 &mt) const {
    shader->setAttributes(mt, vt, pt, metallic, roughness, ao, vt.cameraPosition, light.position, light.color, light.power, light.radius, albedo);
}

/********************* PBRSingleTexture *********************/
PBRSingleTexture::PBRSingleTexture(const Core::Texture &texture) : texture(texture) {}

void PBRSingleTexture::applyMaterial(const Maths::ProjectionTransform &pt, const Maths::ViewTransform &vt, const Maths::Mat4 &mt) const {
    shader->setAttributes(mt, vt, pt, metallic, roughness, ao, vt.cameraPosition, light.position, light.color, light.power, light.radius, texture);
}

/********************* PBRColorArray *********************/
void PBRColorArray::applyMaterial(const Maths::ProjectionTransform &pt, const Maths::ViewTransform &vt, const Maths::Mat4 &mt) const {
    shader->setAttributes(mt, vt, pt, metallic, roughness, ao, vt.cameraPosition, light.position, light.color, light.power, light.radius);
}

void PBRWater::applyMaterial(const Maths::ProjectionTransform &pt, const Maths::ViewTransform &vt, const Maths::Mat4 &mt) const {
    shader->setAttributes(mt, vt, pt, metallic, roughness, ao, vt.cameraPosition, light.position, light.color, light.power, light.radius, (float) Core::Window::totalTimeFlow);
}

PBRWater::PBRWater(const Color::RGBA &albedo) : albedo(albedo) {}

} // namespace Blob::Materials
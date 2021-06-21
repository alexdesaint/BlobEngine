#include <Blob/Core/Window.hpp>
#include <Blob/Materials.hpp>

namespace Blob::Materials {

void SingleColor2D::applyMaterial(const Maths::ProjectionTransform2D &pt, const Maths::ViewTransform2D &vt, const Maths::Mat3 &mt) const {
    shader->setAttributes(mt, vt, pt, albedo);
}

void SingleColorSingleTexture2D::applyMaterial(const Maths::ProjectionTransform2D &pt, const Maths::ViewTransform2D &vt, const Maths::Mat3 &mt) const {
    shader->setAttributes(mt, vt, pt, albedo, texture);
}

void SingleColor::applyMaterial(const Maths::ProjectionTransform &pt, const Maths::ViewTransform &vt, const Maths::Mat4 &mt) const {
    shader->setAttributes(mt, vt, pt, albedo);
}

void SingleColorTransparent::applyMaterial(const Maths::ProjectionTransform &pt, const Maths::ViewTransform &vt, const Maths::Mat4 &mt) const {
    shader->setAttributes(mt, vt, pt, albedo);
}

void SingleTexture::applyMaterial(const Maths::ProjectionTransform &pt, const Maths::ViewTransform &vt, const Maths::Mat4 &mt) const {
    shader->setAttributes(mt, vt, pt, texScale, texture);
}

/********************* Utils *********************/

void PerFaceNormal::applyMaterial(const Maths::ProjectionTransform &pt, const Maths::ViewTransform &vt, const Maths::Mat4 &mt) const {
    shader->setAttributes(mt, vt, pt, albedo, length);
}

/********************* PBR *********************/
Light PBR::light;
/********************* PBRSingleColor *********************/

void PBRSingleColor::applyMaterial(const Maths::ProjectionTransform &pt, const Maths::ViewTransform &vt, const Maths::Mat4 &mt) const {
    shader->setAttributes(mt, vt, pt, metallic, roughness, ao, vt.cameraPosition, light.position, light.color, light.power, light.radius, albedo);
}

void PBRSingleTransparentColor::applyMaterial(const Maths::ProjectionTransform &pt, const Maths::ViewTransform &vt, const Maths::Mat4 &mt) const {
    shader->setAttributes(mt, vt, pt, metallic, roughness, ao, vt.cameraPosition, light.position, light.color, light.power, light.radius, albedo);
}

/********************* PBRSingleTexture *********************/

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

} // namespace Blob::Materials
#include <Blob/Core/Window.hpp>
#include <Blob/Materials.hpp>

namespace Blob::Materials2D {

void SingleColor::applyMaterial(const ProjectionTransform2D &pt,
                                const ViewTransform2D &vt,
                                const Mat3 &mt) const {
    shader->setAttributes(mt, vt, pt, albedo);
}

void SingleColorSingleTexture::applyMaterial(const ProjectionTransform2D &pt,
                                             const ViewTransform2D &vt,
                                             const Mat3 &mt) const {
    shader->setAttributes(mt, vt, pt, albedo, texture);
}

} // namespace Blob::Materials2D
namespace Blob::Materials {
void SingleColor::applyMaterial(const ProjectionTransform &pt,
                                const ViewTransform &vt,
                                const Mat4 &mt) const {
    shader->setAttributes(mt, vt, pt, albedo);
}

void SingleTexture::applyMaterial(const ProjectionTransform &pt,
                                  const ViewTransform &vt,
                                  const Mat4 &mt) const {
    shader->setAttributes(mt, vt, pt, texScale, texture);
}

/********************* Utils *********************/

void PerFaceNormal::applyMaterial(const ProjectionTransform &pt,
                                  const ViewTransform &vt,
                                  const Mat4 &mt) const {
    shader->setAttributes(mt, vt, pt, albedo, length);
}

/********************* PBR *********************/

Light PBR::light;

/********************* PBRSingleColor *********************/

void PBRSingleColor::applyMaterial(const ProjectionTransform &pt,
                                   const ViewTransform &vt,
                                   const Mat4 &mt) const {
    shader->setAttributes(mt,
                          vt,
                          pt,
                          metallic,
                          roughness,
                          ao,
                          vt.cameraPosition,
                          light.position,
                          light.color,
                          light.radius,
                          light.power,
                          albedo);
}

void PBRSingleColorInstanced::applyMaterial(const ProjectionTransform &pt,
                                            const ViewTransform &vt,
                                            const Mat4 &mt) const {
    shader->setAttributes(vt,
                          pt,
                          metallic,
                          roughness,
                          ao,
                          vt.cameraPosition,
                          light.position,
                          light.color,
                          light.radius,
                          light.power,
                          albedo);
}

/********************* PBRSingleTexture *********************/

void PBRSingleTexture::applyMaterial(const ProjectionTransform &pt,
                                     const ViewTransform &vt,
                                     const Mat4 &mt) const {
    shader->setAttributes(mt,
                          vt,
                          pt,
                          metallic,
                          roughness,
                          ao,
                          vt.cameraPosition,
                          light.position,
                          light.color,
                          light.radius,
                          light.power,
                          texture);
}

/********************* PBRColorArray *********************/
void PBRColorArray::applyMaterial(const ProjectionTransform &pt,
                                  const ViewTransform &vt,
                                  const Mat4 &mt) const {
    shader->setAttributes(mt,
                          vt,
                          pt,
                          metallic,
                          roughness,
                          ao,
                          vt.cameraPosition,
                          light.position,
                          light.color,
                          light.radius,
                          light.power);
}

void PBRWater::applyMaterial(const ProjectionTransform &pt,
                             const ViewTransform &vt,
                             const Mat4 &mt) const {
    shader->setAttributes(mt,
                          vt,
                          pt,
                          metallic,
                          roughness,
                          ao,
                          vt.cameraPosition,
                          light.position,
                          light.color,
                          light.radius,
                          light.power,
                          (float) Window::totalTimeFlow);
}

} // namespace Blob::Materials
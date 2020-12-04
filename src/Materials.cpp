#include <Blob/Core/Window.hpp>
#include <Blob/Materials.hpp>

#include <Blob/Shaders.hpp>

namespace Blob::Materials {

SingleColor::SingleColor(Color::RGB albedo) : albedo(albedo) {}

void SingleColor::applyMaterial(const Maths::ProjectionTransform &pt, const Maths::ViewTransform &vt, const Maths::Mat4 &mt) const {
    setShader(Shaders::SingleColor::instance);

    setUniform(pt, Shaders::SingleColor::projection);
    setUniform(vt, Shaders::SingleColor::view);
    setUniform(mt, Shaders::SingleColor::model);

    setUniform(albedo, Shaders::SingleColor::albedo);
}

SingleTexture::SingleTexture(const Core::Texture *texture) : texture(texture) {}

void SingleTexture::applyMaterial(const Maths::ProjectionTransform &pt, const Maths::ViewTransform &vt, const Maths::Mat4 &mt) const {
    setShader(Shaders::SingleTexture::instance);

    setUniform(pt, Shaders::SingleTexture::projection);
    setUniform(vt, Shaders::SingleTexture::view);
    setUniform(mt, Shaders::SingleTexture::model);

    setUniform(texScale, Shaders::SingleTexture::textureScale);
    setTexture(texture);
}
void SingleTexture::setTexture1(const Core::Texture *texture) {
    SingleTexture::texture = texture;
}

/********************* Utils *********************/

PerFaceNormal::PerFaceNormal(Color::RGB albedo) : albedo(albedo) {}

void PerFaceNormal::applyMaterial(const Maths::ProjectionTransform &pt, const Maths::ViewTransform &vt, const Maths::Mat4 &mt) const {
    setShader(Shaders::PerFaceNormal::instance);

    setUniform(pt, Shaders::PerFaceNormal::projection);
    setUniform(vt, Shaders::PerFaceNormal::view);
    setUniform(mt, Shaders::PerFaceNormal::model);

    setUniform(albedo, Shaders::PerFaceNormal::albedo);
    setUniform(length, Shaders::PerFaceNormal::length);
}

/********************* PBR *********************/
Light PBR::light;
/********************* PBRSingleColor *********************/

PBRSingleColor::PBRSingleColor(Color::RGB albedo) : albedo(albedo) {}

void PBRSingleColor::applyMaterial(const Maths::ProjectionTransform &pt, const Maths::ViewTransform &vt, const Maths::Mat4 &mt) const {
    setShader(Shaders::PBRSingleColor::instance);

    setUniform(pt, Shaders::PBRSingleColor::projection);
    setUniform(vt, Shaders::PBRSingleColor::view);
    setUniform(mt, Shaders::PBRSingleColor::model);

    setUniform(albedo, Shaders::PBRSingleColor::albedo);
    setUniform(metallic, Shaders::PBRSingleColor::metallic);
    setUniform(roughness, Shaders::PBRSingleColor::roughness);
    setUniform(ao, Shaders::PBRSingleColor::ao);

    setUniform(light.position, Shaders::PBRSingleColor::lightPosition);
    setUniform(light.color, Shaders::PBRSingleColor::lightColor);
    setUniform(light.power, Shaders::PBRSingleColor::lightPower);
    setUniform(light.radius, Shaders::PBRSingleColor::lightRadius);

    setUniform(vt.cameraPosition, Shaders::PBRSingleColor::cameraPosition);
}

/********************* PBRSingleTexture *********************/
PBRSingleTexture::PBRSingleTexture(const Core::Texture &texture) : texture(texture) {}

void PBRSingleTexture::applyMaterial(const Maths::ProjectionTransform &pt, const Maths::ViewTransform &vt, const Maths::Mat4 &mt) const {
    setShader(Shaders::PBRSingleTexture::instance);

    setUniform(pt, Shaders::PBRSingleTexture::projection);
    setUniform(vt, Shaders::PBRSingleTexture::view);
    setUniform(mt, Shaders::PBRSingleTexture::model);

    setTexture(texture);
    setUniform(texScale, Shaders::PBRSingleTexture::textureScale);

    setUniform(metallic, Shaders::PBRSingleTexture::metallic);
    setUniform(roughness, Shaders::PBRSingleTexture::roughness);
    setUniform(ao, Shaders::PBRSingleTexture::ao);

    setUniform(light.position, Shaders::PBRSingleTexture::lightPosition);
    setUniform(light.color, Shaders::PBRSingleTexture::lightColor);
    setUniform(light.power, Shaders::PBRSingleTexture::lightPower);
    setUniform(light.radius, Shaders::PBRSingleTexture::lightRadius);

    setUniform(vt.cameraPosition, Shaders::PBRSingleTexture::cameraPosition);
}

/********************* PBRColorArray *********************/
void PBRColorArray::applyMaterial(const Maths::ProjectionTransform &pt, const Maths::ViewTransform &vt, const Maths::Mat4 &mt) const {
    setShader(Shaders::PBRColorArray::instance);

    setUniform(pt, Shaders::PBRColorArray::projection);
    setUniform(vt, Shaders::PBRColorArray::view);
    setUniform(mt, Shaders::PBRColorArray::model);

    setUniform(metallic, Shaders::PBRColorArray::metallic);
    setUniform(roughness, Shaders::PBRColorArray::roughness);
    setUniform(ao, Shaders::PBRColorArray::ao);

    setUniform(light.position, Shaders::PBRColorArray::lightPosition);
    setUniform(light.color, Shaders::PBRColorArray::lightColor);
    setUniform(light.power, Shaders::PBRColorArray::lightPower);
    setUniform(light.radius, Shaders::PBRColorArray::lightRadius);

    setUniform(vt.cameraPosition, Shaders::PBRSingleTexture::cameraPosition);
}

void PBRWater::applyMaterial(const Maths::ProjectionTransform &pt, const Maths::ViewTransform &vt, const Maths::Mat4 &mt) const {
    setShader(Shaders::PBRWater::instance);

    setUniform(pt, Shaders::PBRWater::projection);
    setUniform(vt, Shaders::PBRWater::view);
    setUniform(mt, Shaders::PBRWater::model);

    setUniform(albedo, Shaders::PBRWater::albedo);
    setUniform(metallic, Shaders::PBRWater::metallic);
    setUniform(roughness, Shaders::PBRWater::roughness);
    setUniform(ao, Shaders::PBRWater::ao);

    setUniform(light.position, Shaders::PBRWater::lightPosition);
    setUniform(light.color, Shaders::PBRWater::lightColor);
    setUniform(light.power, Shaders::PBRWater::lightPower);
    setUniform(light.radius, Shaders::PBRWater::lightRadius);
    setUniform((float) Core::Window::totalTimeFlow, Shaders::PBRWater::timeStep);

    setUniform(vt.cameraPosition, Shaders::PBRWater::cameraPosition);
}

PBRWater::PBRWater(Color::RGBA albedo) : albedo(albedo) {}

} // namespace Blob::Materials
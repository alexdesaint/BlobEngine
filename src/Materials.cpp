#include <Blob/Core/Window.hpp>
#include <Blob/Materials.hpp>

#include <Blob/Shaders.hpp>

namespace Blob::Materials {

void SingleColor2D::applyMaterial(const Maths::Mat3 &pt, const Maths::Mat3 &vt, const Maths::Mat3 &mt) const {
    setCullFace(false);
    setDepthTest(false);
    setShader(Shaders::SingleColor2D::instance);

    setUniform(pt, Shaders::SingleColor2D::projection);
    setUniform(vt, Shaders::SingleColor2D::view);
    setUniform(mt, Shaders::SingleColor2D::model);

    setUniform(albedo, Shaders::SingleColor2D::albedo);
}

SingleColor2D::SingleColor2D(Color::RGBA albedo) : albedo(albedo) {}

SingleColor2D::SingleColor2D(Color::RGB albedo, float alpha) : albedo(albedo, alpha) {}

void SingleColorSingleTexture2D::applyMaterial(const Maths::Mat3 &pt, const Maths::Mat3 &vt, const Maths::Mat3 &mt) const {
    setCullFace(false);
    setDepthTest(false);

    setUniform(pt, Shaders::SingleColorSingleTexture2D::projection);
    setUniform(vt, Shaders::SingleColorSingleTexture2D::view);
    setUniform(mt, Shaders::SingleColorSingleTexture2D::model);

    setUniform(albedo, Shaders::SingleColorSingleTexture2D::albedo);
    setTexture(texture);
    setShader(Shaders::SingleColorSingleTexture2D::instance);
}

SingleColorSingleTexture2D::SingleColorSingleTexture2D(const Core::Texture &texture) : texture(&texture) {}
SingleColorSingleTexture2D::SingleColorSingleTexture2D(const Core::Texture &texture, const Color::RGBA &albedo) : texture(&texture), albedo(albedo) {}
void SingleColorSingleTexture2D::setTexture1(const Core::Texture &texture_) {
    texture = &texture_;
}

SingleColor::SingleColor(Color::RGB albedo) : albedo(albedo) {}

void SingleColor::applyMaterial(const Maths::ProjectionTransform &pt, const Maths::ViewTransform &vt, const Maths::Mat4 &mt) const {
    setShader(Shaders::SingleColor::instance);

    setUniform(pt, Shaders::SingleColor::projection);
    setUniform(vt, Shaders::SingleColor::view);
    setUniform(mt, Shaders::SingleColor::model);

    setUniform(albedo, Shaders::SingleColor::albedo);
}

SingleColorTransparent::SingleColorTransparent(Color::RGBA albedo) : albedo(albedo) {}
SingleColorTransparent::SingleColorTransparent(Color::RGB albedo, float a) : albedo(albedo, a) {}

void SingleColorTransparent::applyMaterial(const Maths::ProjectionTransform &pt, const Maths::ViewTransform &vt, const Maths::Mat4 &mt) const {
    setShader(Shaders::SingleColorTransparent::instance);

    setUniform(pt, Shaders::SingleColorTransparent::projection);
    setUniform(vt, Shaders::SingleColorTransparent::view);
    setUniform(mt, Shaders::SingleColorTransparent::model);

    setUniform(albedo, Shaders::SingleColorTransparent::albedo);
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
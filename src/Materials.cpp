#include <Blob/Materials.hpp>

#include <Blob/Shaders.hpp>

namespace Blob::Materials {

SingleColor::SingleColor(Color::RGB albedo) : albedo(albedo) {}

void SingleColor::applyMaterial(const Maths::ProjectionTransform &pt, const Maths::ViewTransform &vt, const Maths::Mat4 &mt) const {
    setCullFace(false);

    setShader(Shaders::SingleColor::instance);

    setUniform(pt, Shaders::SingleColor::projection);
    setUniform(vt, Shaders::SingleColor::view);
    setUniform(mt, Shaders::SingleColor::model);

    setUniform(Color::GreenYellow, Shaders::SingleColor::albedo);
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

} // namespace Blob::Materials
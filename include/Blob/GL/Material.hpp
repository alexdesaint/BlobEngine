#pragma once

#include <Blob/Color.hpp>
#include <Blob/GL/Shader.hpp>
#include <Blob/GL/Texture.hpp>
#include <Blob/Maths.inl>
#include <memory>
#include <ostream>
namespace Blob::GL {

class Material {
public:
    void setCullFace(bool set) const;
    void setScissorTest(bool set) const;

    void setShader(const Shader &shaderProgram) const;
    void setShader(const std::shared_ptr<Shader> &shaderProgram) const;
    void setScissor(int x, int y, int width, int height) const;
    void setDepthTest(bool set) const;
    void setTexture(const Texture &texture) const;
    void setTexture(const Texture *texture) const;

    template<typename T>
    void setUniform(const T &val, int position) const;
};

template<>
void Material::setUniform<>(const int &val, int position) const;

template<>
void Material::setUniform<>(const unsigned int &val, int position) const;

template<>
void Material::setUniform<>(const float &val, int position) const;

template<>
void Material::setUniform<>(const float (&val)[4][4], int position) const;

template<>
void Material::setUniform<>(const float (&val)[16], int position) const;

template<>
void Material::setUniform<>(const Maths::Vec2<float> &val, int position) const;

template<>
void Material::setUniform<>(const Maths::Vec3<float> &val, int position) const;

template<>
void Material::setUniform<>(const Maths::Mat3 &val, int position) const;

template<>
void Material::setUniform<>(const Maths::Mat4 &val, int position) const;

template<>
void Material::setUniform<>(const Maths::ModelTransform &val, int position) const;

template<>
void Material::setUniform<>(const Maths::ViewTransform &val, int position) const;

template<>
void Material::setUniform<>(const Maths::ProjectionTransform &val, int position) const;

template<>
void Material::setUniform<>(const Maths::ModelTransform2D &val, int position) const;

template<>
void Material::setUniform<>(const Maths::ViewTransform2D &val, int position) const;

template<>
void Material::setUniform<>(const Maths::ProjectionTransform2D &val, int position) const;

template<>
void Material::setUniform<>(const Color::RGB &val, int position) const;

template<>
void Material::setUniform<>(const Color::RGBA &val, int position) const;

} // namespace Blob::GL
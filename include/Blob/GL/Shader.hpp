#pragma once

#include <Blob/Color.hpp>
#include <Blob/GL/Shader.hpp>
#include <Blob/GL/ShaderProgram.hpp>
#include <Blob/GL/Texture.hpp>
#include <Blob/Maths.inl>
#include <memory>
#include <ostream>
namespace Blob::GL {

class Shader {
public:
    void setCullFace(bool set) const;
    void setScissorTest(bool set) const;

    void setShaderProgram(const ShaderProgram &shaderProgram) const;
    void setScissor(int x, int y, int width, int height) const;
    void setDepthTest(bool set) const;
    void setTexture(const Texture &texture) const;
    void setTexture(const Texture *texture) const;

    template<typename T>
    void setUniform(const T &val, int position) const;
};

template<>
void Shader::setUniform<>(const int &val, int position) const;

template<>
void Shader::setUniform<>(const unsigned int &val, int position) const;

template<>
void Shader::setUniform<>(const float &val, int position) const;

template<>
void Shader::setUniform<>(const float (&val)[4][4], int position) const;

template<>
void Shader::setUniform<>(const float (&val)[16], int position) const;

template<>
void Shader::setUniform<>(const Vec2<float> &val, int position) const;

template<>
void Shader::setUniform<>(const Vec3<float> &val, int position) const;

template<>
void Shader::setUniform<>(const Mat3 &val, int position) const;

template<>
void Shader::setUniform<>(const Mat4 &val, int position) const;

template<>
void Shader::setUniform<>(const ModelTransform &val, int position) const;

template<>
void Shader::setUniform<>(const ViewTransform &val, int position) const;

template<>
void Shader::setUniform<>(const ProjectionTransform &val, int position) const;

template<>
void Shader::setUniform<>(const ModelTransform2D &val, int position) const;

template<>
void Shader::setUniform<>(const ViewTransform2D &val, int position) const;

template<>
void Shader::setUniform<>(const ProjectionTransform2D &val, int position) const;

template<>
void Shader::setUniform<>(const Color::RGB &val, int position) const;

template<>
void Shader::setUniform<>(const Color::RGBA &val, int position) const;

} // namespace Blob::GL
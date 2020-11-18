// blobEngine
#include <Blob/GL/Material.hpp>

// GLAD
#include <glad/glad.h>

namespace Blob::GL {

void Material::setCullFace(bool set) const {
    if (set)
        glEnable(GL_CULL_FACE);
    else
        glDisable(GL_CULL_FACE);
}

void Material::setScissorTest(bool set) const {
    if (set)
        glEnable(GL_SCISSOR_TEST);
    else
        glDisable(GL_SCISSOR_TEST);
}

void Material::setShader(const Shader &shaderProgram) const {
    glUseProgram(shaderProgram.program);
}

void Material::setScissor(int x, int y, int width, int height) const {
    glScissor(x, y, width, height);
}

void Material::setDepthTest(bool set) const {
    if (set)
        glEnable(GL_DEPTH_TEST);
    else
        glDisable(GL_DEPTH_TEST);
}

void Material::setTexture(const Texture &texture) const {
    glBindTexture(GL_TEXTURE_2D, texture.texture);
}

template<>
void Material::setUniform<>(const float (&val)[4][4], int position) const {
    glUniformMatrix4fv(position, 1, GL_FALSE, &val[0][0]);
}

template<>
void Material::setUniform<>(const float (&val)[16], int position) const {
    glUniformMatrix4fv(position, 1, GL_FALSE, &val[0]);
}

template<>
void Material::setUniform<>(const Maths::Vec2<float> &val, int position) const {
    glUniform2fv(position, 1, &val.x);
}

template<>
void Material::setUniform<>(const Maths::Vec3<float> &val, int position) const {
    glUniform3fv(position, 1, &val.x);
}

template<>
void Material::setUniform<>(const Maths::Mat3 &val, int position) const {
    glUniformMatrix3fv(position, 1, GL_FALSE, &val.a11);
}

template<>
void Material::setUniform<>(const Maths::Mat4 &val, int position) const {
    glUniformMatrix4fv(position, 1, GL_FALSE, &val.a11);
}

template<>
void Material::setUniform<>(const Maths::ModelTransform &val, int position) const {
    glUniformMatrix4fv(position, 1, GL_FALSE, &val.a11);
}

template<>
void Material::setUniform<>(const Maths::ViewTransform &val, int position) const {
    glUniformMatrix4fv(position, 1, GL_FALSE, &val.a11);
}

template<>
void Material::setUniform<>(const Maths::ProjectionTransform &val, int position) const {
    glUniformMatrix4fv(position, 1, GL_FALSE, &val.a11);
}

template<>
void Material::setUniform<>(const Color::RGB &val, int position) const {
    glUniform3fv(position, 1, &val.R);
}

template<>
void Material::setUniform<>(const float &val, int position) const {
    glUniform1f(position, val);
}

template<>
void Material::setUniform<>(const int &val, int position) const {
    glUniform1i(position, val);
}

template<>
void Material::setUniform<>(const unsigned int &val, int position) const {
    glUniform1ui(position, val);
}

} // namespace Blob::GL
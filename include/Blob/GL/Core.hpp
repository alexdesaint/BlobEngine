#pragma once

#include <Blob/Color.hpp>
#include <Blob/Core/RenderOptions.hpp>
#include <Blob/GL/ShaderProgram.hpp>
#include <Blob/GL/Texture.hpp>
#include <Blob/GL/VertexArrayObject.hpp>
#include <Blob/Maths.inl>
#include <ostream>

namespace Blob::GL {

class Context {
public:
    static const int GLmajor = 4;
    static const int GLminor = 5;

    Context(void *glfwGetProcAddress, const Maths::Vec2<int> &size);
    ~Context();
};

class Core {
public:
    // Window
    static void clear();

    // Material
    static void setCullFace(bool set);
    static void setScissorTest(bool set);

    static void setScissor(int x, int y, int width, int height);
    static void setDepthTest(bool set);
    static void setViewport(const Maths::Vec2<int> &framebufferSize);
    static void setShader(const ShaderProgram &shaderProgram);
    static void setVAO(const VertexArrayObject &vao);
    static void setTexture(const Texture &texture);
    /*
        static void setMat4(const float *matrix, int position);
        static void setVec2(const float *matrix, int position);
        static void setVec3(const float *matrix, int position);
        static void setVec4(const float *matrix, int position);
        static void setFloat(float val, int position);
        static void setUint(int32_t val, int position);
        */

    template<typename T>
    static void setUniform(const T &val, int position);

    static void drawIndex(const void *indices, int32_t numOfIndices, uint32_t indicesType);
    template<typename T>
    static void drawIndex(const void *indices, int32_t numOfIndices);

    static float readPixel(Maths::Vec2<int> pos);

    template<typename T>
    static uint32_t getType();

    friend std::ostream &operator<<(std::ostream &s, const Core &a);
};

template<>
void Core::drawIndex<uint8_t>(const void *indices, int32_t numOfIndices);

template<>
void Core::drawIndex<uint16_t>(const void *indices, int32_t numOfIndices);

template<>
void Core::drawIndex<uint32_t>(const void *indices, int32_t numOfIndices);

template<>
uint32_t Core::getType<int8_t>();
template<>
uint32_t Core::getType<int16_t>();
template<>
uint32_t Core::getType<int32_t>();
template<>
uint32_t Core::getType<uint8_t>();
template<>
uint32_t Core::getType<uint16_t>();
template<>
uint32_t Core::getType<uint32_t>();
template<>
uint32_t Core::getType<float>();

template<>
void Core::setUniform<>(const int &val, int position);

template<>
void Core::setUniform<>(const unsigned int &val, int position);

template<>
void Core::setUniform<>(const float &val, int position);

template<>
void Core::setUniform<>(const float (&val)[4][4], int position);

template<>
void Core::setUniform<>(const float (&val)[16], int position);

template<>
void Core::setUniform<>(const Maths::Vec2<float> &val, int position);

template<>
void Core::setUniform<>(const Maths::Vec3<float> &val, int position);

template<>
void Core::setUniform<>(const Maths::Mat3 &val, int position);

template<>
void Core::setUniform<>(const Maths::Mat4 &val, int position);

template<>
void Core::setUniform<>(const Maths::ModelTransform &val, int position);

template<>
void Core::setUniform<>(const Maths::ViewTransform &val, int position);

template<>
void Core::setUniform<>(const Maths::ProjectionTransform &val, int position);

template<>
void Core::setUniform<>(const Color::RGB &c, int position);

} // namespace Blob::GL

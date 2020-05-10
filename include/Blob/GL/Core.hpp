#pragma once

#include <Blob/GL/ShaderProgram.hpp>
#include <Blob/GL/Texture.hpp>
#include <Blob/GL/VertexArrayObject.hpp>
#include <Blob/RenderOptions.hpp>
#include <ostream>

namespace Blob::GL {

class Core {
public:
    static void init(void *glfwGetProcAddress, unsigned int width, unsigned int height);

    static const int GLmajor = 4;
    static const int GLminor = 5;

    static void clear();

    static void setCullFace(bool set);

    static void setScissorTest(bool set);

    static void setScissor(int x, int y, int width, int height);
    static void setDepthTest(bool set);
    static void setViewport(unsigned int width, unsigned int height);
    static void setShader(const ShaderProgram &shaderProgram);
    static void setVAO(const VertexArrayObject &vao);
    static void setTexture(const Texture &texture);
    static void setMat4(const float *matrix, int position);
    static void setVec4(const float *matrix, int position);
    static void setVec3(const float *matrix, int position);
    static void setFloat(float val, int position);
    static void setUint(int32_t val, int position);

    static void drawIndex(const void *indices, int32_t numOfIndices, uint32_t indicesType);
    template<typename T>
    static void drawIndex(const void *indices, int32_t numOfIndices);

    static float readPixel(Blob::Vec2f pos);

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

template<> uint32_t Core::getType<int8_t>();
template<> uint32_t Core::getType<int16_t>();
template<> uint32_t Core::getType<int32_t>();
template<> uint32_t Core::getType<uint8_t>();
template<> uint32_t Core::getType<uint16_t>();
template<> uint32_t Core::getType<uint32_t>();
template<> uint32_t Core::getType<float>();

} // namespace Blob::GL

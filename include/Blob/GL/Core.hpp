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

    static void drawIndex(const void *indices, int32_t numOfIndices, uint32_t indicesType);
    template<typename T>
    static void drawIndex(const void *indices, int32_t numOfIndices);

    static float readPixel(Blob::Vec2f pos);

    /*static void draw(const RenderOptions &renderOptions, const ShaderProgram &shaderProgram, const VertexArrayObject &vertexArrayObject,
                     const Texture &texture, const float *projection, const float *view, const float *model);

    static void draw(const RenderOptions &renderOptions, const ShaderProgram &shaderProgram, const VertexArrayObject &vertexArrayObject,
                     const float *projection, const float *view, const float *model);*/

    friend std::ostream &operator<<(std::ostream &s, const Core &a);
};

template<>
void Core::drawIndex<uint8_t>(const void *indices, int32_t numOfIndices);

template<>
void Core::drawIndex<uint16_t>(const void *indices, int32_t numOfIndices);

template<>
void Core::drawIndex<uint32_t>(const void *indices, int32_t numOfIndices);

} // namespace Blob::GL

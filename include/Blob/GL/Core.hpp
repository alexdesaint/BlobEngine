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

    static void draw(const RenderOptions &renderOptions, const ShaderProgram &shaderProgram, const VertexArrayObject &vertexArrayObject,
                     const Texture &texture, const float *projection, const float *view, const float *model);

    static void draw(const RenderOptions &renderOptions, const ShaderProgram &shaderProgram, const VertexArrayObject &vertexArrayObject,
                     const float *projection, const float *view, const float *model);

    friend std::ostream &operator<<(std::ostream &s, const Core &a);

    static void setlViewport(unsigned int width, unsigned int height);

    static float readPixel(Blob::Vec2f pos);
};
} // namespace Blob::GL

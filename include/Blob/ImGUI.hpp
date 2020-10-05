#pragma once

#include <Blob/GL/Texture.hpp>
#include <Blob/GL/VertexArrayObject.hpp>
#include <Blob/GL/ShaderProgram.hpp>

namespace Blob::Core {
class ImGUI {
private:
    GL::Texture fontTexture;
    GL::VertexBufferObject vertexBufferObject;
    GL::VertexArrayObject vertexArrayObject;
    float projectionMatrix[16] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, -1, 0, -1, 1, 0, 1};
    float id[16] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
    GL::ShaderProgram shader;

    int projectionPosition = -1;

    void buildFont();

public:
    ImGUI();

    void draw();

    void setWindowSize(unsigned int width, unsigned int height);
};
} // namespace Blob
#pragma once

#include <Blob/GL/Material.hpp>
#include <Blob/GL/Shader.hpp>
#include <Blob/GL/Texture.hpp>
#include <Blob/GL/VertexArrayObject.hpp>
#include <Blob/GL/Window.hpp>

namespace ImGui {
class Context : private Blob::GL::Material {
private:
    Blob::GL::Texture fontTexture;
    Blob::GL::VertexBufferObject vertexBufferObject;
    Blob::GL::VertexArrayObject vertexArrayObject;
    float projectionMatrix[16] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, -1, 0, -1, 1, 0, 1};
    float id[16] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
    Blob::GL::Shader shader;

    int projectionPosition = -1;

    void buildFont();

    static const char *getClipboardText(void *user_data);

    static void setClipboardText(void *user_data, const char *text);

public:
    Context(const Blob::GLFW::Window &window, const Blob::Maths::Vec2<float> &windowSize, const Blob::Maths::Vec2<float> &framebufferSize);

    void createRender();

    void draw(const Blob::GL::Window &window);

    void setWindowSize(const Blob::Maths::Vec2<float>& windowSize, const Blob::Maths::Vec2<float>& framebufferSize);

    void addInputCharacter(unsigned short c);

    void updateMouseCursor(Blob::GLFW::Window &window);
};
} // namespace Blob
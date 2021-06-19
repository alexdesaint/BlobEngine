#pragma once

#include "Blob/Maths.inl"
#include <Blob/GL/Shader.hpp>
#include <Blob/GL/Texture.hpp>
#include <Blob/GL/VertexArrayObject.hpp>
#include <Blob/GL/Window.hpp>
#include <Blob/Shaders.hpp>

namespace ImGui {
class Context : private Blob::GL::Shader {
private:
    Blob::Shaders2D::ColorArraySingleTexture::Intance shader = Blob::Shaders2D::ColorArraySingleTexture::getInstance();
    Blob::Core::Texture fontTexture;
    Blob::GL::VertexBufferObject vertexBufferObject;
    Blob::GL::VertexArrayObject vertexArrayObject;

    Blob::Maths::ProjectionTransform2D projectionTransform;
    Blob::Maths::ModelTransform2D modelTransform;
    Blob::Maths::ViewTransform2D viewTransform;

    void buildFont();

    static const char *getClipboardText(void *user_data);

    static void setClipboardText(void *user_data, const char *text);

public:
    Context(const Blob::GLFW::Window &window, const Blob::Maths::Vec2<float> &windowSize, const Blob::Maths::Vec2<float> &framebufferSize);

    void createRender();

    void draw(const Blob::GL::Window &window);

    void setWindowSize(const Blob::Maths::Vec2<float> &windowSize, const Blob::Maths::Vec2<float> &framebufferSize);

    void addInputCharacter(unsigned short c);

    void disableMouseCursor();
    void enableMouseCursor();
    void enableGamepad();
    void disableGamepad();

    void updateMouseCursor(Blob::GLFW::Window &window);
};
} // namespace ImGui
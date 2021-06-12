#pragma once

#include "Blob/Core/Shader.hpp"
#include <Blob/GL/Material.hpp>
#include <Blob/GL/Shader.hpp>
#include <Blob/GL/Texture.hpp>
#include <Blob/GL/VertexArrayObject.hpp>
#include <Blob/GL/Window.hpp>
#include <memory>

namespace ImGui {
class Context : private Blob::GL::Material {
private:
    std::shared_ptr<Blob::Core::Shader> shader;
    Blob::GL::Texture fontTexture;
    Blob::GL::VertexBufferObject vertexBufferObject;
    Blob::GL::VertexArrayObject vertexArrayObject;

    Blob::Maths::Mat3 projectionTransform;
    Blob::Maths::Mat3 modelTransform;
    Blob::Maths::Mat3 viewTransform;

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
#include <Blob/GLFW.hpp>

#include <Blob/GL/Window.hpp>
#include <Blob/GL/Shader.hpp>
#include <Blob/GL/Material.hpp>

#include <Blob/Core/Exception.hpp>
#include <iostream>

using namespace Blob;
using namespace GLFW;

static const struct {
    float x, y;
    float r, g, b;
} vertices[4] = {{-0.5f, -0.5f, 1.f, 1.f, 0.f}, {0.5f, -0.5f, 0.f, 1.f, 1.f}, {-0.5f, 0.5f, 1.f, 0.f, 1.f}, {0.5f, 0.5f, 0.f, 0.f, 1.f}};

static const char *vertex_shader_text = R"=====(
#version 450

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

attribute vec3 vCol;
attribute vec2 vPos;

varying vec3 color;

void main() {
    gl_Position = projection * view * model * vec4(vPos, 0.0, 1.0);
    color = vCol;
}
)=====";

static const char *fragment_shader_text = R"=====(
#version 450

varying vec3 color;
out vec4 FragColor;
void main()  {
    FragColor = vec4(color, 1.0);
}
)=====";
int main() {
    int width = 680, height = 480;
    Window window(false, {width, height}, GL::Window::GLmajor, GL::Window::GLminor);
    auto glContext = GL::Window((void *) Window::getProcAddress, {width, height});

    try {
        GL::VertexBufferObject vbo((uint8_t *) vertices, sizeof(vertices));

        GL::Shader sp;
        sp.addVertexShader(vertex_shader_text);
        sp.addFragmentShader(fragment_shader_text);
        sp.linkShaders();

        GL::Material material;

        GL::VertexArrayObject vao;
        vao.setBuffer(vbo, sizeof(vertices[0]));
        vao.setArray<float>(2, sp.getAttribLocation("vPos"), 0);
        vao.setArray<float>(3, sp.getAttribLocation("vCol"), sizeof(float) * 2);

        Maths::ProjectionTransform pt(PI / 4, {width, height}, 0.1, 10);
        Maths::ViewTransform vt;
        Maths::ModelTransform mt;

        int model = sp.getUniformLocation("model");
        int view = sp.getUniformLocation("view");
        int projection = sp.getUniformLocation("projection");

        unsigned short indices[] = {0, 1, 2, 3, 2, 1};

        while (window.isOpen()) {
            auto fbs = window.getFrameBufferSize();

            if (fbs != Maths::Vec2<int>(width, height)) {
                width = fbs.x;
                height = fbs.y;
                glContext.setViewport({width, height});
            }

            pt.setRatio({width, height});

            glContext.setViewport({width, height});

            glContext.clear();

            float mod = fmod((float) Window::getTime(), 1);
            mt.setRotation((float) Window::getTime(), {0, 0, 1});
            // mt.setPosition({0, mod, 0});
            // mt.setScale({2, 1, 1});
            material.setShader(sp);
            glContext.setVAO(vao);
            material.setUniform(pt, projection);
            material.setUniform(vt, view);
            material.setUniform(mt, model);
            glContext.drawIndex<unsigned short>(indices, 6);

            window.swapBuffers();
            Window::updateInputs();
        }

    } catch (Blob::Core::Exception &ex) { std::cout << ex.what(); }
}

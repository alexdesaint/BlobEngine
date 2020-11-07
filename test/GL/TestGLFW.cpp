#include <Blob/GLFW.hpp>

#include <Blob/GL/Core.hpp>

#include <Blob/Exception.hpp>
#include <Blob/Geometry/ModelTransform.hpp>
#include <Blob/Geometry/ProjectionTransform.hpp>
#include <Blob/Geometry/ViewTransform.hpp>
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
    Window window(false, {width, height}, GL::Context::GLmajor, GL::Context::GLminor);
    auto glContext = GL::Context((void *) Window::getProcAddress, {width, height});

    try {
        GL::VertexBufferObject vbo((uint8_t *) vertices, sizeof(vertices));

        GL::ShaderProgram sp;
        sp.addVertexShader(vertex_shader_text);
        sp.addFragmentShader(fragment_shader_text);
        sp.linkShaders();

        GL::VertexArrayObject vao;
        vao.setBuffer(vbo, sizeof(vertices[0]));
        vao.setArray<float>(2, sp.getAttribLocation("vPos"), 0);
        vao.setArray<float>(3, sp.getAttribLocation("vCol"), sizeof(float) * 2);

        Geometry::ProjectionTransform pt(PI / 4, {width, height}, 0.1, 10);
        Geometry::ViewTransform vt;
        Geometry::ModelTransform mt;

        int model = sp.getUniformLocation("model");
        int view = sp.getUniformLocation("view");
        int projection = sp.getUniformLocation("projection");

        unsigned short indices[] = {0, 1, 2, 3, 2, 1};

        while (window.isOpen()) {
            auto fbs = window.getFrameBufferSize();

            if (fbs != Maths::Vec2<int>(width, height)) {
                width = fbs.x;
                height = fbs.y;
                GL::Core::setViewport({width, height});
            }

            pt.setRatio({width, height});

            GL::Core::setViewport({width, height});

            GL::Core::clear();

            float mod = fmod((float) Window::getTime(), 1);
            mt.setRotation((float) Window::getTime(), {0, 0, 1});
            // mt.setPosition({0, mod, 0});
            // mt.setScale({2, 1, 1});
            Blob::GL::Core::setShader(sp);
            Blob::GL::Core::setVAO(vao);
            Blob::GL::Core::setUniform((Maths::Mat4) pt, projection);
            Blob::GL::Core::setUniform((Maths::Mat4) vt, view);
            Blob::GL::Core::setUniform((Maths::Mat4) mt, model);
            Blob::GL::Core::drawIndex<unsigned short>(indices, 6);

            window.swapBuffers();
            Window::updateInputs();
        }

    } catch (Blob::Core::Exception &ex) { std::cout << ex.what(); }
}

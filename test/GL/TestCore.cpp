#include "Blob/GL/ShaderProgram.hpp"
#include <glad/gl.h>

#include <Blob/GL/Shader.hpp>
#include <Blob/GL/VertexBufferObject.hpp>
#include <Blob/GL/Window.hpp>
#include <cstdio>
#include <cstdlib>

#include <iostream>

using namespace Blob;

static const struct {
    float x, y;
    float r, g, b;
} vertices[4] = {{-0.5f, -0.5f, 1.f, 1.f, 0.f},
                 {0.5f, -0.5f, 0.f, 1.f, 1.f},
                 {-0.5f, 0.5f, 1.f, 0.f, 1.f},
                 {0.5f, 0.5f, 0.f, 0.f, 1.f}};

static const char *vertex_shader_text = R"=====(
#version 110

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

static const char *fragment_shader_text =
    "#version 110\n"
    "varying vec3 color;\n"
    "void main()\n"
    "{\n"
    "    gl_FragColor = vec4(color, 1.0);\n"
    "}\n";

int main() {
    unsigned int width = 640, height = 480;

    GL::Window window{{width, height}};
    GL::Shader shader;

    GL::VertexBufferObject vbo((uint8_t *) vertices, sizeof(vertices));

    GL::ShaderProgram sp;
    sp.addVertexShader(vertex_shader_text);
    sp.addFragmentShader(fragment_shader_text);
    sp.linkShaders();

    GL::VertexArrayObject vao;
    vao.setBuffer(vbo, sizeof(vertices[0]));
    vao.setArray(2, sp.getAttribLocation("vPos"), GL_FLOAT, 0);
    vao.setArray(3, sp.getAttribLocation("vCol"), GL_FLOAT, sizeof(float) * 2);

    ProjectionTransform pt(PI / 4, {width, height}, 0.1, 10);
    ViewTransform vt;
    ModelTransform mt;

    int model = sp.getUniformLocation("model");
    int view = sp.getUniformLocation("view");
    int projection = sp.getUniformLocation("projection");

    // unsigned short indices[] = {2, 1, 0, 1, 2, 3};
    unsigned short indices[] = {0, 1, 2, 3, 2, 1};

    while (window.isOpen()) {

        pt.setRatio({width, height});

        window.setViewport({width, height});

        window.clear();

        mt.setRotation(window.totalTimeFlow, {0, 0, 1});

        shader.setShaderProgram(sp);
        window.setVAO(vao);
        shader.setUniform(pt, projection);
        shader.setUniform(vt, view);
        shader.setUniform(mt, model);
        window.drawIndex(indices, 6, GL_UNSIGNED_SHORT);

        window.swapBuffers();
        window.updateInputs();
    }
}

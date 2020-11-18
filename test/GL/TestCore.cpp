#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <Blob/GL/Shader.hpp>
#include <Blob/GL/VertexBufferObject.hpp>
#include <Blob/GL/Window.hpp>
#include <Blob/GL/Material.hpp>
#include <cstdio>
#include <cstdlib>

#include <iostream>

using namespace Blob;
using namespace Blob::GL;

static const struct {
    float x, y;
    float r, g, b;
} vertices[4] = {{-0.5f, -0.5f, 1.f, 1.f, 0.f}, {0.5f, -0.5f, 0.f, 1.f, 1.f}, {-0.5f, 0.5f, 1.f, 0.f, 1.f}, {0.5f, 0.5f, 0.f, 0.f, 1.f}};

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

static const char *fragment_shader_text = "#version 110\n"
                                          "varying vec3 color;\n"
                                          "void main()\n"
                                          "{\n"
                                          "    gl_FragColor = vec4(color, 1.0);\n"
                                          "}\n";

static void error_callback(int error, const char *description) {
    fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int main() {
    int width = 640, height = 480;

    glfwSetErrorCallback(error_callback);

    if (!glfwInit())
        exit(EXIT_FAILURE);

    GLFWwindow *glfWwindow = glfwCreateWindow(width, height, "Test Blob GL", NULL, NULL);
    if (!glfWwindow) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwSetKeyCallback(glfWwindow, key_callback);

    glfwMakeContextCurrent(glfWwindow);

    Window window{(void *) glfwGetProcAddress, {width, height}};
    Material material;

    glfwSwapInterval(1);

    GL::VertexBufferObject vbo((uint8_t *) vertices, sizeof(vertices));

    GL::Shader sp;
    sp.addVertexShader(vertex_shader_text);
    sp.addFragmentShader(fragment_shader_text);
    sp.linkShaders();

    GL::VertexArrayObject vao;
    vao.setBuffer(vbo, sizeof(vertices[0]));
    vao.setArray(2, sp.getAttribLocation("vPos"), GL_FLOAT, 0);
    vao.setArray(3, sp.getAttribLocation("vCol"), GL_FLOAT, sizeof(float) * 2);

    Maths::ProjectionTransform pt(PI / 4, {width, height}, 0.1, 10);
    Maths::ViewTransform vt;
    Maths::ModelTransform mt;

    int model = sp.getUniformLocation("model");
    int view = sp.getUniformLocation("view");
    int projection = sp.getUniformLocation("projection");

    // unsigned short indices[] = {2, 1, 0, 1, 2, 3};
    unsigned short indices[] = {0, 1, 2, 3, 2, 1};

    while (!glfwWindowShouldClose(glfWwindow)) {

        glfwGetFramebufferSize(glfWwindow, &width, &height);

        pt.setRatio({width, height});

        window.setViewport({width, height});

        window.clear();

        mt.setRotation((float) glfwGetTime(), {0, 0, 1});

        material.setShader(sp);
        window.setVAO(vao);
        material.setUniform(pt, projection);
        material.setUniform(vt, view);
        material.setUniform(mt, model);
        window.drawIndex(indices, 6, GL_UNSIGNED_SHORT);

        glfwSwapBuffers(glfWwindow);
        glfwPollEvents();
    }

    glfwDestroyWindow(glfWwindow);

    glfwTerminate();
    exit(EXIT_SUCCESS);
}

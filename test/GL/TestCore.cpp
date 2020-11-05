#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <Blob/GL/Core.hpp>
#include <Blob/GL/ShaderProgram.hpp>
#include <Blob/GL/VertexBufferObject.hpp>
#include <cstdio>
#include <cstdlib>

#include <Blob/Geometry/ModelTransform.hpp>
#include <Blob/Geometry/ProjectionTransform.hpp>
#include <Blob/Geometry/ViewTransform.hpp>
#include <iostream>

using namespace Blob;

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

    GLFWwindow *window = glfwCreateWindow(width, height, "Test Blob Core", NULL, NULL);
    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwSetKeyCallback(window, key_callback);

    glfwMakeContextCurrent(window);

    GL::Context((void *) glfwGetProcAddress, width, height);

    glfwSwapInterval(1);

    GL::VertexBufferObject vbo((uint8_t *) vertices, sizeof(vertices));

    GL::ShaderProgram sp;
    sp.addVertexShader(vertex_shader_text);
    sp.addFragmentShader(fragment_shader_text);
    sp.linkShaders();

    GL::VertexArrayObject vao;
    vao.setBuffer(vbo, sizeof(vertices[0]));
    vao.setArray(2, sp.getAttribLocation("vPos"), GL_FLOAT, 0);
    vao.setArray(3, sp.getAttribLocation("vCol"), GL_FLOAT, sizeof(float) * 2);

    Geometry::ProjectionTransform pt(PI / 4, width, height, 0.1, 10);
    Geometry::ViewTransform vt;
    Geometry::ModelTransform mt;

    int model = sp.getUniformLocation("model");
    int view = sp.getUniformLocation("view");
    int projection = sp.getUniformLocation("projection");

    // unsigned short indices[] = {2, 1, 0, 1, 2, 3};
    unsigned short indices[] = {0, 1, 2, 3, 2, 1};

    while (!glfwWindowShouldClose(window)) {

        glfwGetFramebufferSize(window, &width, &height);

        pt.setRatio(width, height);

        GL::Core::setViewport(width, height);

        GL::Core::clear();

        mt.setRotation((float) glfwGetTime(), {0, 0, 1});

        GL::Core::setShader(sp);
        GL::Core::setVAO(vao);
        Blob::GL::Core::setUniform((Geometry::Mat4) pt, projection);
        Blob::GL::Core::setUniform((Geometry::Mat4) vt, view);
        Blob::GL::Core::setUniform((Geometry::Mat4) mt, model);
        GL::Core::drawIndex(indices, 6, GL_UNSIGNED_SHORT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);

    glfwTerminate();
    exit(EXIT_SUCCESS);
}

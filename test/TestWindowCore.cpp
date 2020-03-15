#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <Blob/GL/Core.hpp>
#include <Blob/GL/ShaderProgram.hpp>
#include <Blob/GL/VertexBufferObject.hpp>
#include <cstdio>
#include <cstdlib>
#include <glm/ext.hpp>

// TRANSFORM INVOCATION !!!
#include <Blob/ModelTransform.hpp>
#include <Blob/ProjectionTransform.hpp>
#include <Blob/ViewTransform.hpp>
#include <Blob/Window.hpp>
#include <iostream>

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
    Blob::Camera camera;

    Blob::Window window(camera);

    //int width = 640, height = 480;

    //glfwSetErrorCallback(error_callback);

    //if (!glfwInit())
    //    exit(EXIT_FAILURE);

    //GLFWwindow *window = glfwCreateWindow(width, height, "Test Blob Core", NULL, NULL);
    //if (!window) {
        //glfwTerminate();
        //exit(EXIT_FAILURE);
    //}

    //glfwSetKeyCallback(window, key_callback);

    //glfwMakeContextCurrent(window);

    //if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {}

    //Blob::GL::Core::init((void *) glfwGetProcAddress, width, height);

    //glfwSwapInterval(1);

    Blob::GL::VertexBufferObject vbo((uint8_t *) vertices, sizeof(vertices));

    Blob::GL::ShaderProgram sp;
    sp.addVertexShader(vertex_shader_text);
    sp.addFragmentShader(fragment_shader_text);
    sp.linkShaders();

    Blob::GL::VertexArrayObject vao;
    vao.setBuffer(vbo, sizeof(vertices[0]));
    vao.setArray(2, sp.getAttribLocation("vPos"), GL_FLOAT, 0);
    vao.setArray(3, sp.getAttribLocation("vCol"), GL_FLOAT, sizeof(float) * 2);

    //Blob::ProjectionTransform pt(PI / 4, width, height, 0.1, 10);
    //Blob::ViewTransform vt;
    Blob::ModelTransform mt;

    Blob::RenderOptions ro;
    ro.indexed = true;
    unsigned short indices[] = {2, 1, 0, 1, 2, 3};
    ro.indices = indices;
    ro.numOfIndices = 6;
    ro.indicesType = GL_UNSIGNED_SHORT;

    Blob::Renderable renderable(vao, sp, )

    while (window.isOpen()) {
        //glm::mat4 m(1), p, v(1);

        //glfwGetFramebufferSize(window, &width, &height);

        //pt.setRatio(width, height);

        //Blob::GL::Core::setlViewport(width, height);

        //Blob::GL::Core::clear();

        mt.setRotation((float) glfwGetTime(), 0, 0, 1);
        //p = glm::ortho(-1.f, 1.f, 1.f, -1.f, -10.f, 10.f);
        //Blob::GL::Core::draw(ro, sp, vao, glm::value_ptr(p), glm::value_ptr(v), mt.model);
        window.draw(ro, sp, vao, pt.projectionPtr, vt.transform, mt.model);

        window.display();
    }

    return 0;
}

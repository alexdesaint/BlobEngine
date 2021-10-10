#include "Blob/GL/ShaderProgram.hpp"
#include <glad/gl.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <Blob/GL/Shader.hpp>
#include <Blob/Maths.inl>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace Blob;

static const struct Vertice {
    float x, y;
    float r, g, b;
} vertices[3] = {{-0.6f, -0.4f, 1.f, 0.f, 0.f},
                 {0.6f, -0.4f, 0.f, 1.f, 0.f},
                 {0.f, 0.6f, 0.f, 0.f, 1.f}};

static std::string vertex_shader_text = R"=====(#version 110
attribute vec2 Position;
attribute vec3 Color;
attribute vec2 TexturePosition;

uniform mat4 MVP;

varying vec3 color;
void main()
{
    gl_Position = MVP * vec4(Position, 0.0, 1.0);
    color = Color;
})=====";

static std::string fragment_shader_text = R"=====(#version 110
varying vec3 color;
void main()
{
    gl_FragColor = vec4(color, 1.0);
})=====";

static void error_callback(int error, const char *description) {
    fprintf(stderr, "Error: %s\n", description);
}

static void
key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void GLAPIENTRY openglCallbackFunction(GLenum source,
                                       GLenum type,
                                       GLuint id,
                                       GLenum severity,
                                       GLsizei length,
                                       const GLchar *message,
                                       const void *userParam) {
    std::cout << message << std::endl;
}

int main() {
    GLFWwindow *window;
    GLuint vertex_buffer;
    GLint mvp_location, vpos_location, vcol_location;

    glfwSetErrorCallback(error_callback);

    if (!glfwInit())
        exit(EXIT_FAILURE);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwSetKeyCallback(window, key_callback);

    glfwMakeContextCurrent(window);
    if (!gladLoadGL((GLADloadfunc) glfwGetProcAddress))
        throw std::runtime_error("Fail to load openGL");

    // Enable the debug callback
    glEnable(GL_DEBUG_OUTPUT);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    glDebugMessageCallback(openglCallbackFunction, nullptr);
    glDebugMessageControl(GL_DONT_CARE,
                          GL_DONT_CARE,
                          GL_DONT_CARE,
                          0,
                          nullptr,
                          GL_TRUE);

    glfwSwapInterval(1);

    glGenBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    GL::ShaderProgram sp;

    sp.addShader(GL::ShaderProgram::Types::Vertex, vertex_shader_text);
    sp.addShader(GL::ShaderProgram::Types::Fragment, fragment_shader_text);
    sp.linkShaders();

    if (sp.isValid())
        std::cout << "Valid !!!" << std::endl;
    else {
        std::cout << "Not valid..." << std::endl;
        glfwDestroyWindow(window);
        glfwTerminate();
        exit(EXIT_SUCCESS);
    }

    // loc
    mvp_location = sp.getUniformLocation("MVP");
    vpos_location = sp.getAttribLocation("Position");
    vcol_location = sp.getAttribLocation("Color");

    glEnableVertexAttribArray(vpos_location);
    glVertexAttribPointer(vpos_location,
                          2,
                          GL_FLOAT,
                          GL_FALSE,
                          sizeof(Vertice),
                          (void *) 0);
    glEnableVertexAttribArray(vcol_location);
    glVertexAttribPointer(vcol_location,
                          3,
                          GL_FLOAT,
                          GL_FALSE,
                          sizeof(Vertice),
                          (void *) (sizeof(float) * 2));

    glUseProgram(sp.program);
    while (!glfwWindowShouldClose(window)) {
        int width, height;

        ProjectionTransform p;

        glfwGetFramebufferSize(window, &width, &height);

        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);

        ModelTransform m;
        m.rotate((float) glfwGetTime(), {0, 0, 1});

        p.setOrthoProjection(2);

        Mat4 mvp = m * p;
        glUniformMatrix4fv(mvp_location, 1, GL_FALSE, &mvp.a11);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);

    glfwTerminate();
    exit(EXIT_SUCCESS);
}

#include "Blob/GL/ShaderProgram.hpp"
#include <Blob/GL/Texture.hpp>
#include <glad/glad.h>
#include <stdint.h>
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
    float uvx, uxy;
    float r, g, b;
} vertices[] = {{-0.6f, -0.4f, 0.f, 0., 1.f, 1.f, 1.f},
                {0.6f, -0.4f, 1.f, 0.f, 1.f, 1.f, 1.f},
                {-0.6f, 0.4f, 0.f, 1.f, 1.f, 1.f, 1.f},
                {0.6f, 0.4f, 1.f, 1.f, 1.f, 1.f, 1.f},
                {-0.6f, 0.4f, 0.f, 1.f, 1.f, 1.f, 1.f},
                {0.6f, -0.4f, 1.f, 0.f, 1.f, 1.f, 1.f}};

static const struct Pixel {
    uint8_t r, g, b, a;
} image[] = {{255, 0, 0}, {0, 255, 0}, {0, 0, 255}, {255, 255, 0}};

static std::string vertex_shader_text = R"=====(#version 400
attribute vec2 Position;
attribute vec3 Color;
attribute vec2 TexturePosition;

uniform mat4 MVP;

varying vec3 color;
varying vec2 texCoord;
void main()
{
    gl_Position = MVP * vec4(Position, 0.0, 1.0);
    color = Color;
    texCoord = TexturePosition;
})=====";

static std::string fragment_shader_text = R"=====(#version 400
varying vec3 color;
varying vec2 texCoord;
uniform sampler2D Texture;
void main()
{
    gl_FragColor = vec4(color, 1.0) * texture(Texture, texCoord.st);
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
    GLint model_location = 0, view_location = 1, projection_location = 2,
          position_location = 0, texturePosition_location = 3,
          color_location = 5;

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
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {}

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

    Blob::GL::ShaderProgram sp;

    sp.addVertexShader(vertex_shader_text);
    sp.addFragmentShader(fragment_shader_text);
    sp.linkShaders();

    if (sp.isValid())
        std::cout << "Valid !!!" << std::endl;
    else {
        std::cout << "Not valid..." << std::endl;
        glfwDestroyWindow(window);
        glfwTerminate();
        exit(EXIT_SUCCESS);
    }

    GL::Texture texture;
    GL::Sampler sample(GL::Sampler::NEAREST, GL::Sampler::NEAREST);

    texture.setRGBA8data((uint8_t *) image, Vec2<unsigned int>{2, 2});
    texture.applySampler(sample);

    model_location = sp.getUniformLocation("MVP");
    position_location = sp.getAttribLocation("Position");
    color_location = sp.getAttribLocation("Color");
    texturePosition_location = sp.getAttribLocation("TexturePosition");

    glEnableVertexAttribArray(position_location);
    glVertexAttribPointer(position_location,
                          2,
                          GL_FLOAT,
                          GL_FALSE,
                          sizeof(Vertice),
                          (void *) offsetof(Vertice, x));
    glEnableVertexAttribArray(texturePosition_location);
    glVertexAttribPointer(texturePosition_location,
                          2,
                          GL_FLOAT,
                          GL_FALSE,
                          sizeof(Vertice),
                          (void *) offsetof(Vertice, uvx));
    glEnableVertexAttribArray(color_location);
    glVertexAttribPointer(color_location,
                          3,
                          GL_FLOAT,
                          GL_FALSE,
                          sizeof(Vertice),
                          (void *) offsetof(Vertice, r));

    glBindTexture(GL_TEXTURE_2D, texture.texture);
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

        Mat4 mvp = p * m;
        glUniformMatrix4fv(model_location, 1, GL_FALSE, &mvp.a11);
        glDrawArrays(GL_TRIANGLES, 0, 6);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);

    glfwTerminate();
    exit(EXIT_SUCCESS);
}

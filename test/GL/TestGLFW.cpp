#include "Blob/GL/ShaderProgram.hpp"
#include <Blob/GLFW.hpp>
#include <glad/gl.h>

#include <Blob/GL/Shader.hpp>
#include <Blob/Maths.inl>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stdexcept>

using namespace Blob;

static const struct {
    float x, y;
    float r, g, b;
} vertices[3] = {{-0.6f, -0.4f, 1.f, 0.f, 0.f},
                 {0.6f, -0.4f, 0.f, 1.f, 0.f},
                 {0.f, 0.6f, 0.f, 0.f, 1.f}};

static std::string vertex_shader_text =
    "#version 110\n"
    "uniform mat4 MVP;"
    "attribute vec3 vCol;"
    "attribute vec2 vPos;"
    "varying vec3 color;"
    "void main()"
    "{"
    "    gl_Position = MVP * vec4(vPos, 0.0, 1.0);"
    "    color = vCol;"
    "}";

static std::string fragment_shader_text = "#version 110\n"
                                          "varying vec3 color;"
                                          "void main()"
                                          "{"
                                          "    gl_FragColor = vec4(color, 1.0);"
                                          "}";

int main() {
    GLFW::Window window({400, 400}, 3, 0);

    if (!gladLoadGL((GLADloadfunc) GLFW::Window::getProcAddress))
        throw std::runtime_error("Fail to load openGL");
    GLuint vertex_buffer;
    GLint mvp_location, vpos_location, vcol_location;

    glGenBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    Blob::GL::ShaderProgram sp;

    sp.addVertexShader(vertex_shader_text);
    sp.addFragmentShader(fragment_shader_text);
    sp.linkShaders();

    if (sp.isValid())
        std::cout << "Valid !!!" << std::endl;
    else
        std::cout << "Not valid..." << std::endl;

    // loc
    mvp_location =
        sp.getUniformLocation("MVP"); // glGetUniformLocation(program, "MVP");
    vpos_location =
        sp.getAttribLocation("vPos"); // glGetAttribLocation(program, "vPos");
    vcol_location =
        sp.getAttribLocation("vCol"); // glGetAttribLocation(program, "vCol");

    glEnableVertexAttribArray(vpos_location);
    glVertexAttribPointer(vpos_location,
                          2,
                          GL_FLOAT,
                          GL_FALSE,
                          sizeof(vertices[0]),
                          (void *) 0);
    glEnableVertexAttribArray(vcol_location);
    glVertexAttribPointer(vcol_location,
                          3,
                          GL_FLOAT,
                          GL_FALSE,
                          sizeof(vertices[0]),
                          (void *) (sizeof(float) * 2));

    while (window.isOpen()) {
        ProjectionTransform p;

        glViewport(0, 0, window.framebufferSize.x, window.framebufferSize.y);
        glClear(GL_COLOR_BUFFER_BIT);

        ModelTransform m;
        m.rotate((float) window.totalTimeFlow, {0, 0, 1});

        p.setOrthoProjection(2);

        Mat4 mvp = m * p;
        glUseProgram(sp.program);
        glUniformMatrix4fv(mvp_location, 1, GL_FALSE, &mvp.a11);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        window.swapBuffers();
        GLFW::Window::updateInputs();
    }
}

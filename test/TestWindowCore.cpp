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


class SimpleMaterial : public Blob::Material {
private:
    int model = shaderProgram.getUniformLocation("model");
    int view = shaderProgram.getUniformLocation("view");
    int projection = shaderProgram.getUniformLocation("projection");

    void applyMaterial(const Blob::ProjectionTransform &pt, const Blob::ViewTransform &vt, const glm::mat4 &mt) const final {
        Blob::GL::Core::setMat4(&pt[0].x, projection);
        Blob::GL::Core::setMat4(&vt[0].x, view);
        Blob::GL::Core::setMat4(&mt[0].x, model);
    }

public:
    explicit SimpleMaterial(const Blob::GL::ShaderProgram &sp) : Material(sp) {

    }
};

int main() {
    Blob::Camera camera;

    Blob::Window window(camera);

    Blob::GL::VertexBufferObject vbo((uint8_t *) vertices, sizeof(vertices));

    Blob::GL::ShaderProgram sp;
    sp.addVertexShader(vertex_shader_text);
    sp.addFragmentShader(fragment_shader_text);
    sp.linkShaders();

    Blob::GL::VertexArrayObject vao;
    vao.setBuffer(vbo, sizeof(vertices[0]));
    vao.setArray(2, sp.getAttribLocation("vPos"), GL_FLOAT, 0);
    vao.setArray(3, sp.getAttribLocation("vCol"), GL_FLOAT, sizeof(float) * 2);

    Blob::RenderOptions ro;
    ro.indexed = true;
    unsigned short indices[] = {2, 1, 0, 1, 2, 3};
    ro.indices = indices;
    ro.numOfIndices = 6;
    ro.indicesType = GL_UNSIGNED_SHORT;

    SimpleMaterial material(sp);

    Blob::Mesh renderable(vao, material);
    renderable.renderOptions = ro;

    Blob::Shape shape(renderable);

    while (window.isOpen()) {

        shape.setRotation((float) glfwGetTime(), 0, 0, 1);
        window.draw(shape);

        window.display();
    }

    return 0;
}

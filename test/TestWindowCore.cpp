#include "Blob/Core/Shader.hpp"
#include "Blob/Maths.inl"
#include <Blob/GL/Shader.hpp>
#include <Blob/GL/VertexBufferObject.hpp>
#include <Blob/GL/Window.hpp>

#include <Blob/Core/Exception.hpp>
#include <Blob/Core/Window.hpp>
#include <iostream>

using namespace Blob;

static const struct {
    float x, y;
    float r, g, b;
} vertices[4] = {{-0.5f, -0.5f, 1.f, 1.f, 0.f},
                 {0.5f, -0.5f, 0.f, 1.f, 1.f},
                 {-0.5f, 0.5f, 1.f, 0.f, 1.f},
                 {0.5f, 0.5f, 0.f, 0.f, 1.f}};

using SimpleShader = Shader<ShaderProgram<VertexShader<
                                              R"=====(
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
)=====">,
                                          FragmentShader<
                                              R"=====(
#version 450

varying vec3 color;
out vec4 FragColor;
void main()  {
    FragColor = vec4(color, 1.0);
}
)=====">>,
                            UniformAttribute<Mat4, 0>,
                            UniformAttribute<ViewTransform, 1>,
                            UniformAttribute<ProjectionTransform, 2>>;

class SimpleMaterial : public Material {
public:
    SimpleShader::Intance shader = SimpleShader::getInstance();

    void applyMaterial(const ProjectionTransform &pt,
                       const ViewTransform &vt,
                       const Mat4 &mt) const final {
        shader->setAttributes(mt, vt, pt);
    }
};

int main() {
    Camera camera;

    Window window;

    SimpleMaterial material;

    try {
        GL::VertexBufferObject vbo((uint8_t *) vertices, sizeof(vertices));

        GL::VertexArrayObject vao;
        vao.setBuffer(vbo, sizeof(vertices[0]));
        vao.setArray<float>(
            2,
            material.shader->shaderProgram.getAttribLocation("vPos"),
            0);
        vao.setArray<float>(
            3,
            material.shader->shaderProgram.getAttribLocation("vCol"),
            sizeof(float) * 2);

        unsigned short indices[] = {0, 1, 2, 3, 2, 1};

        RenderOptions ro;
        ro.setIndices(indices, 6);
        Primitive primitive(&vao, &material, &ro);
        Mesh mesh;
        mesh.addPrimitive(primitive);
        Shape shape(mesh);

        while (window.isOpen()) {

            shape.setRotation((float) Window::timeFlow, {0, 0, 1});
            window.draw(shape, camera);

            window.display();
        }

    } catch (Exception &ex) { std::cout << ex.what(); }

    return 0;
}

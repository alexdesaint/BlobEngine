#include <Blob/GL/Core.hpp>
#include <Blob/GL/ShaderProgram.hpp>
#include <Blob/GL/VertexBufferObject.hpp>

#include <Blob/Exception.hpp>
#include <Blob/Geometry/ProjectionTransform.hpp>
#include <Blob/Geometry/ViewTransform.hpp>
#include <Blob/Window.hpp>
#include <iostream>

using namespace Blob;

static const struct {
    float x, y;
    float r, g, b;
} vertices[4] = {{-0.5f, -0.5f, 1.f, 1.f, 0.f}, {0.5f, -0.5f, 0.f, 1.f, 1.f}, {-0.5f, 0.5f, 1.f, 0.f, 1.f}, {0.5f, 0.5f, 0.f, 0.f, 1.f}};

static const std::string vertex_shader_text = R"=====(
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

static const std::string fragment_shader_text = R"=====(
#version 450

varying vec3 color;
out vec4 FragColor;
void main()  {
    FragColor = vec4(color, 1.0);
}
)=====";

class SimpleMaterial : public Material::Material {
private:
    void applyMaterial(const Geometry::ProjectionTransform &pt, const Geometry::ViewTransform &vt, const Geometry::Mat4 &mt) const final {
        GL::Core::setUniform((Geometry::Mat4) pt, projection);
        GL::Core::setUniform((Geometry::Mat4) vt, view);
        GL::Core::setUniform(mt, model);
    }

public:
    static int model;
    static int view;
    static int projection;

    explicit SimpleMaterial(const GL::ShaderProgram &sp) : Material(sp) {}
};

int SimpleMaterial::model;
int SimpleMaterial::view;
int SimpleMaterial::projection;

int main() {
    Core::Camera camera;

    Core::Window window(camera);

    try {
        GL::VertexBufferObject vbo((uint8_t *) vertices, sizeof(vertices));

        GL::ShaderProgram sp;
        sp.addVertexShader(vertex_shader_text);
        sp.addFragmentShader(fragment_shader_text);
        sp.linkShaders();

        SimpleMaterial::model = sp.getUniformLocation("model");
        SimpleMaterial::view = sp.getUniformLocation("view");
        SimpleMaterial::projection = sp.getUniformLocation("projection");

        GL::VertexArrayObject vao;
        vao.setBuffer(vbo, sizeof(vertices[0]));
        vao.setArray<float>(2, sp.getAttribLocation("vPos"), 0);
        vao.setArray<float>(3, sp.getAttribLocation("vCol"), sizeof(float) * 2);

        unsigned short indices[] = {0, 1, 2, 3, 2, 1};
        SimpleMaterial material(sp);

        Core::Mesh renderable(vao, material);
        renderable.setIndices(indices, 6);

        Core::Shape shape(renderable);

        while (window.isOpen()) {

            shape.setRotation((float) Core::Window::getTime(), {0, 0, 1});
            window.draw(shape);

            window.display();
        }

    } catch (Core::Exception &ex) { std::cout << ex.what(); }

    return 0;
}

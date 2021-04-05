#include <Blob/GL/Shader.hpp>
#include <Blob/GL/VertexBufferObject.hpp>
#include <Blob/GL/Window.hpp>

#include <Blob/Core/Exception.hpp>
#include <Blob/Core/Window.hpp>
#include <iostream>

using namespace Blob;
using namespace Blob::Core;
using namespace Blob::Maths;

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

class SimpleMaterial : public Core::Material {
private:
    void applyMaterial(const ProjectionTransform &pt, const ViewTransform &vt, const Mat4 &mt) const final {
        setShader(sp);
        setUniform(pt, projection);
        setUniform(vt, view);
        setUniform(mt, model);
    }
    const GL::Shader &sp;

public:
    static int model;
    static int view;
    static int projection;

    explicit SimpleMaterial(const GL::Shader &sp)
        : sp(sp) {}
};

int SimpleMaterial::model;
int SimpleMaterial::view;
int SimpleMaterial::projection;

int main() {
    Core::Camera camera;

    Core::Window window;

    try {
        GL::VertexBufferObject vbo((uint8_t *) vertices, sizeof(vertices));

        GL::Shader sp;
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

        RenderOptions ro;
        ro.setIndices(indices, 6);
        Core::Primitive primitive(&vao, &material, &ro);
        Core::Mesh mesh;
        mesh.addPrimitive(primitive);
        Core::Shape shape(mesh);

        while (window.isOpen()) {

            shape.setRotation((float) Core::Window::timeFlow, {0, 0, 1});
            window.draw(shape, camera);

            window.display();
        }

    } catch (Core::Exception &ex) { std::cout << ex.what(); }

    return 0;
}

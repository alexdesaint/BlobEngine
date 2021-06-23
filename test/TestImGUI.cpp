#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <Blob/GL/Shader.hpp>
#include <Blob/GL/VertexBufferObject.hpp>
#include <Blob/GL/Window.hpp>
#include <cstdio>
#include <cstdlib>

#include <Blob/Core/Window.hpp>
#include <imgui.h>
#include <iostream>

using namespace Blob;
using namespace Blob::Core;
using namespace Blob::Maths;

static const struct {
    float x, y;
    float r, g, b;
} vertices[4] = {{-0.5f, -0.5f, 1.f, 1.f, 0.f}, {0.5f, -0.5f, 0.f, 1.f, 1.f}, {-0.5f, 0.5f, 1.f, 0.f, 1.f}, {0.5f, 0.5f, 0.f, 0.f, 1.f}};

using SimpleShader = Core::Shader<Core::ShaderProgram<Core::VertexShader<
                                                          R"=====(
#version 450

layout(location = 0) uniform mat4 model;
layout(location = 1) uniform mat4 view;
layout(location = 2) uniform mat4 projection;

layout(location = 0) in vec3 vCol;
layout(location = 1) in vec2 vPos;

layout(location = 0) out vec3 color;

void main() {
    gl_Position = projection * view * model * vec4(vPos, 0.0, 1.0);
    color = vCol;
}
)=====">,
                                                      Core::FragmentShader<
                                                          R"=====(
#version 450

layout(location = 0) in vec3 color;

out vec4 FragColor;
void main()  {
    FragColor = vec4(color, 1.0);
}
)=====">>,
                                  Core::UniformAttribute<Maths::Mat4, 0>,
                                  Core::UniformAttribute<Maths::ViewTransform, 1>,
                                  Core::UniformAttribute<Maths::ProjectionTransform, 2>>;

class SimpleMaterial : public Core::Material {
public:
    SimpleShader::Intance shader = SimpleShader::getInstance();

    void applyMaterial(const Maths::ProjectionTransform &pt, const Maths::ViewTransform &vt, const Maths::Mat4 &mt) const final { shader->setAttributes(mt, vt, pt); }
};

int main() {
    Core::Camera camera;

    Core::Window window;

    SimpleMaterial material;

    Blob::GL::VertexBufferObject vbo((uint8_t *) vertices, sizeof(vertices));

    Blob::GL::VertexArrayObject vao;
    vao.setBuffer(vbo, sizeof(vertices[0]));
    vao.setArray(2, material.shader->shaderProgram.getAttribLocation("vPos"), GL_FLOAT, 0);
    vao.setArray(3, material.shader->shaderProgram.getAttribLocation("vCol"), GL_FLOAT, sizeof(float) * 2);

    Core::RenderOptions ro;
    //     ro.indexed = true;
    unsigned short indices[] = {2, 1, 0, 1, 2, 3};
    ro.setIndices(indices, 6);

    Core::Primitive primitive(&vao, &material, &ro);

    bool show_demo_window = true;
    bool show_another_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    while (window.isOpen()) {

        // renderable.setRotation((float) glfwGetTime(), 0, 0, 1);
        window.draw(primitive, camera);
        // ImGui::NewFrame();

        if (show_demo_window)
            ImGui::ShowDemoWindow(&show_demo_window);

        // 2. Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
        {
            static float f = 0.0f;
            static int counter = 0;

            ImGui::Begin("Hello, world!"); // Create a window called "Hello, world!" and append into it.

            ImGui::Text("This is some useful text.");          // Display some text (you can use a format strings too)
            ImGui::Checkbox("Demo Window", &show_demo_window); // Edit bools storing our window open/close state
            ImGui::Checkbox("Another Window", &show_another_window);

            ImGui::SliderFloat("float", &f, 0.0f, 1.0f);              // Edit 1 float using a slider from 0.0f to 1.0f
            ImGui::ColorEdit3("clear color", (float *) &clear_color); // Edit 3 floats representing a color
            ImGui::ColorPicker3("another color", (float *) &clear_color);

            if (ImGui::Button("Button")) // Buttons return true when clicked (most widgets return true when edited/activated)
                counter++;
            ImGui::SameLine();
            ImGui::Text("counter = %d", counter);

            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
            ImGui::End();
        }

        // 3. Show another simple window.
        if (show_another_window) {
            ImGui::Begin("Another Window", &show_another_window); // Pass a pointer to our bool variable (the window will have a closing button
            // that will clear the bool when clicked)
            ImGui::Text("Hello from another window!");
            if (ImGui::Button("Close Me"))
                show_another_window = false;
            ImGui::End();
        }

        window.display();
    }

    return 0;
}

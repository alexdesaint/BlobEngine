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
#include <imgui.h>

static const struct {
    float x, y;
    float r, g, b;
} vertices[4] = {{-0.5f, -0.5f, 1.f, 1.f, 0.f}, {0.5f, -0.5f, 0.f, 1.f, 1.f}, {-0.5f, 0.5f, 1.f, 0.f, 1.f}, {0.5f, 0.5f, 0.f, 0.f, 1.f}};

static const char *vertex_shader_text = R"=====(
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

static const char *fragment_shader_text = "#version 450\n"
                                          "varying vec3 color;\n"
                                          "void main()\n"
                                          "{\n"
                                          "    gl_FragColor = vec4(color, 1.0);\n"
                                          "}\n";


class SimpleMaterial : public Blob::Material {
private:
    void applyMaterial(const Blob::ProjectionTransform &pt, const Blob::ViewTransform &vt, const glm::mat4 &mt) const final {
        Blob::GL::Core::setMat4(&pt[0].x, projection);
        Blob::GL::Core::setMat4(&vt[0].x, view);
        Blob::GL::Core::setMat4(&mt[0].x, model);
    }

public:
    static int model;
    static int view;
    static int projection;

    explicit SimpleMaterial(const Blob::GL::ShaderProgram &sp) : Material(sp) {

    }
};

int SimpleMaterial::model;
int SimpleMaterial::view;
int SimpleMaterial::projection;

int main() {
    Blob::Camera camera;

    Blob::Window window(camera);

    Blob::GL::VertexBufferObject vbo((uint8_t *) vertices, sizeof(vertices));

    Blob::GL::ShaderProgram sp;
    sp.addVertexShader(vertex_shader_text);
    sp.addFragmentShader(fragment_shader_text);
    sp.linkShaders();

    SimpleMaterial::model = sp.getUniformLocation("model");
    SimpleMaterial::view = sp.getUniformLocation("view");
    SimpleMaterial::projection = sp.getUniformLocation("projection");

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

    bool show_demo_window = true;
    bool show_another_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    while (window.isOpen()) {

        //renderable.setRotation((float) glfwGetTime(), 0, 0, 1);
        window.draw(renderable);
        //ImGui::NewFrame();

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

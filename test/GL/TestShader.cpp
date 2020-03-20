#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <Blob/GL/ShaderProgram.hpp>
#include <cstdio>
#include <cstdlib>
#include <glm/ext.hpp>
#include <iostream>

static const struct {
    float x, y;
    float r, g, b;
} vertices[3] = {{-0.6f, -0.4f, 1.f, 0.f, 0.f}, {0.6f, -0.4f, 0.f, 1.f, 0.f}, {0.f, 0.6f, 0.f, 0.f, 1.f}};

static std::string vertex_shader_text = "#version 110\n"
                                        "uniform mat4 MVP;\n"
                                        "attribute vec3 vCol;\n"
                                        "attribute vec2 vPos;\n"
                                        "varying vec3 color;\n"
                                        "void main()\n"
                                        "{\n"
                                        "    gl_Position = MVP * vec4(vPos, 0.0, 1.0);\n"
                                        "    color = vCol;\n"
                                        "}\n";

static std::string fragment_shader_text = "#version 110\n"
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
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {}
    glfwSwapInterval(1);

    // NOTE: OpenGL error checks have been omitted for brevity

    glGenBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

   /* auto data = Blob::GL::ShaderProgram::Shaders.emplace(std::piecewise_construct, std::make_tuple("basicShader"), std::make_tuple());
    if(!data.second)
        std::cout << "failed to insert" << std::endl;
    Blob::GL::ShaderProgram &e = data.first->second;

    if(e.isValid())
        std::cout << "Valid !!!" << std::endl;
    else
        std::cout << "Not valid..." << std::endl;

    auto nodeHandler = Blob::GL::ShaderProgram::Shaders.extract("basicShader");
    nodeHandler.key() = "basicShader2";
    auto data2 = Blob::GL::ShaderProgram::Shaders.insert(std::move(nodeHandler));

    if(e.isValid())
        std::cout << "Valid !!!" << std::endl;
    else
        std::cout << "Not valid..." << std::endl;

    Blob::GL::ShaderProgram &spp = Blob::GL::ShaderProgram::Shaders["QUoi?"];

    if(spp.isValid())
        std::cout << "Valid !!!" << std::endl;
    else
        std::cout << "Not valid..." << std::endl;
*/
    Blob::GL::ShaderProgram &sp = Blob::GL::ShaderProgram::Shaders["basicShader2"];


    sp.addVertexShader(vertex_shader_text);
    sp.addFragmentShader(fragment_shader_text);
    sp.linkShaders();

    if(sp.isValid())
        std::cout << "Valid !!!" << std::endl;
    else
        std::cout << "Not valid..." << std::endl;

    // loc
    mvp_location = sp.getUniformLocation("MVP");  // glGetUniformLocation(program, "MVP");
    vpos_location = sp.getAttribLocation("vPos"); // glGetAttribLocation(program, "vPos");
    vcol_location = sp.getAttribLocation("vCol"); // glGetAttribLocation(program, "vCol");

    glEnableVertexAttribArray(vpos_location);
    glVertexAttribPointer(vpos_location, 2, GL_FLOAT, GL_FALSE, sizeof(vertices[0]), (void *) 0);
    glEnableVertexAttribArray(vcol_location);
    glVertexAttribPointer(vcol_location, 3, GL_FLOAT, GL_FALSE, sizeof(vertices[0]), (void *) (sizeof(float) * 2));

    while (!glfwWindowShouldClose(window)) {
        float ratio;
        int width, height;

        glm::mat4 m(1), p;

        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float) height;

        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);

        m = glm::rotate(m, (float) glfwGetTime(), glm::vec3(0, 0, 1));

        p = glm::ortho(-1.f, 1.f, 1.f, -1.f, -ratio, ratio);

        glUseProgram(sp.getProgram());
        glUniformMatrix4fv(mvp_location, 1, GL_FALSE, glm::value_ptr(m * p));
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    Blob::GL::ShaderProgram::Shaders.clear();

    glfwDestroyWindow(window);

    glfwTerminate();
    exit(EXIT_SUCCESS);
}

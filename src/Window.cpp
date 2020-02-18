#include <Blob/Window.hpp>

// GLFW
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Blob
#include <Blob/Exception.hpp>
#include <iostream>
#include <glm/gtc/type_ptr.inl>
#include <Blob/Shapes.hpp>

namespace Blob::GL {

    Window::Window(bool fullScreen, unsigned int w, unsigned int h) :
        ProjectionTransform(PI / 4, w/(float)h, 1, 100)
    {
        ///// Core init

        glfwSetErrorCallback(GLFWErrorCallback);

        static const int GLmajor = 4;
        static const int GLminor = 5;

        if (!glfwInit())
            throw Exception("Can't init glfw");

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GLmajor);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GLminor);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        glfwWindowHint(GLFW_SAMPLES, 8);

        if (fullScreen) {
            const GLFWvidmode *mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
            glfwWindowHint(GLFW_RED_BITS, mode->redBits);
            glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
            glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
            glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

            width = mode->width;
            height = mode->height;

            window = glfwCreateWindow(width, height, "My Title", glfwGetPrimaryMonitor(), nullptr);
        } else {
            window = glfwCreateWindow(width, height, "My Title", nullptr, nullptr);
        }

        if (!window) {
            glfwTerminate();
            throw Exception("Can't open window");
        }

        glfwMakeContextCurrent((GLFWwindow *) window);
        glfwSwapInterval(1);

        if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) throw Exception("Fail to load openGL");

        if (GLmajor != GLVersion.major || GLminor > GLVersion.minor)
            throw Exception("Fail to load the right version of OpenGL. Loaded version : " +
                            std::to_string(GLVersion.major) + "." + std::to_string(GLVersion.minor) +
                            " instead of " + std::to_string(GLmajor) + "\n" + std::to_string(GLminor) +
                            ". System version : " + (char *) glGetString(GL_VERSION));

        enableDebugCallBack();

        //general settings
        glFrontFace(GL_CW);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); //pour faire des lignes
        glClearColor(0.2, 0.2, 0.2, 1.0);
        glViewport(0, 0, w, h);
        glCullFace(GL_FRONT);
        //alpha
        glEnable(GL_BLEND);
        glBlendEquation(GL_FUNC_ADD);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        //user pointer
        glfwSetWindowUserPointer((GLFWwindow *) window, this);
        glfwSetFramebufferSizeCallback(
                (GLFWwindow *) window,
                (GLFWframebuffersizefun) framebuffer_size_callback
        );
        ////////////////
        lastFrameTime = std::chrono::high_resolution_clock::now();
        Controls::init(window);
        Shapes::init();
    }

    std::ostream &operator<<(std::ostream &s, const Window &a) {
        s << glGetString(GL_VENDOR) << std::endl <<
          glGetString(GL_RENDERER) << std::endl <<
          glGetString(GL_VERSION) << std::endl <<
          glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
        return s;
    }

    void Window::framebuffer_size_callback(void *window, int w, int h) {
        auto g = (Window *) glfwGetWindowUserPointer((GLFWwindow *) window);
        g->resize(w, h);
    }

    void Window::GLFWErrorCallback(int error, const char *description) {
        std::cout << "GLFW Error " << error << " : " << description;
    }

    void Window::draw(const Renderable &renderable, glm::mat4 shapeModel) {

        if (renderable.cullFace)
            glEnable(GL_CULL_FACE);
        else
            glDisable(GL_CULL_FACE);

        if (renderable.scissorTest)
            glEnable(GL_SCISSOR_TEST);
        else
            glDisable(GL_SCISSOR_TEST);

        if (renderable.depthTest)
            glEnable(GL_DEPTH_TEST);
        else
            glDisable(GL_DEPTH_TEST);


        glUseProgram(renderable.shaderProgram.getProgram());
        glBindVertexArray(renderable.vertexArrayObject.getVertexArrayObject());

        glUniformMatrix4fv(renderable.shaderProgram.projection, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
        glUniformMatrix4fv(renderable.shaderProgram.view, 1, GL_FALSE, glm::value_ptr(viewMatrix));
        glUniformMatrix4fv(renderable.shaderProgram.model, 1, GL_FALSE,
                           glm::value_ptr(shapeModel * renderable.getModelMatrix()));


        glBindTexture(GL_TEXTURE_2D, renderable.texture.texture);
        glUniform2f(renderable.shaderProgram.textureScale, renderable.textureScale.x, renderable.textureScale.y);


        if (renderable.indexed)
            glDrawElements(GL_TRIANGLES, renderable.numOfIndices, renderable.indicesType, renderable.indices);
        else
            glDrawArrays(GL_TRIANGLES, 0, 3);
    }

    void Window::draw(const Renderable &renderable, int numOfElements, uint64_t elementOffset, glm::mat4 shapeModel) {

        // specific settings
        // TODO: aptimize this
        if (renderable.cullFace)
            glEnable(GL_CULL_FACE);
        else
            glDisable(GL_CULL_FACE);

        if (renderable.scissorTest)
            glEnable(GL_SCISSOR_TEST);
        else
            glDisable(GL_SCISSOR_TEST);

        if (renderable.depthTest)
            glEnable(GL_DEPTH_TEST);
        else
            glDisable(GL_DEPTH_TEST);

        // shader program
        glUseProgram(renderable.shaderProgram.getProgram());
        glBindVertexArray(renderable.vertexArrayObject.getVertexArrayObject());

        // MVP matrix
        glUniformMatrix4fv(renderable.shaderProgram.projection, 1, GL_FALSE, glm::value_ptr(projectionMatrix2D));
        glUniformMatrix4fv(renderable.shaderProgram.view, 1, GL_FALSE, glm::value_ptr(viewMatrix));
        glUniformMatrix4fv(renderable.shaderProgram.model, 1, GL_FALSE,
                           glm::value_ptr(shapeModel * renderable.getModelMatrix()));

        // TODO: add RGB color

        // Texture
        glBindTexture(GL_TEXTURE_2D, renderable.texture.texture);
        glUniform2f(renderable.shaderProgram.textureScale, renderable.textureScale.x, renderable.textureScale.y);

        // Draw
        if (renderable.indexed)
            glDrawElements(GL_TRIANGLES, numOfElements, renderable.indicesType, &renderable.indices[elementOffset]);
        else
            glDrawArrays(GL_TRIANGLES, elementOffset, numOfElements);
    }

    bool Window::isOpen() const {
        return !(glfwWindowShouldClose((GLFWwindow *) window) || quit);
    }

    void GLAPIENTRY openglCallbackFunction(
            GLenum source,
            GLenum type,
            GLuint id,
            GLenum severity,
            GLsizei length,
            const GLchar *message,
            const void *userParam
    ) {
        (void) source;
        (void) type;
        (void) id;
        (void) length;
        (void) userParam;

        switch (severity) {
            case GL_DEBUG_SEVERITY_NOTIFICATION :
                std::cout << "Notification :" << std::endl << message << std::endl;
                break;
            case GL_DEBUG_SEVERITY_LOW:
                std::cout << "Low severity Error :" << std::endl << message;
                break;
            case GL_DEBUG_SEVERITY_MEDIUM:
                std::cout << "Medium severity Error :" << std::endl << message;
                break;
            case GL_DEBUG_SEVERITY_HIGH:
                std::cout << "High severity Error :" << std::endl << message << std::endl;
                abort();
            default:
                std::cout << "Unknow Error severity :" << std::endl << message;
                break;
        }
    }

    void Window::enableDebugCallBack() {
        // Enable the debug callback

        glEnable(GL_DEBUG_OUTPUT);
        glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
        glDebugMessageCallback(openglCallbackFunction, nullptr);
        glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE);
    }

    Window::~Window() {
        Shapes::destroy();
        glfwDestroyWindow((GLFWwindow *) window);
        glfwTerminate();
    }

    void Window::setTitle(const std::string &name) {
        glfwSetWindowTitle((GLFWwindow *) window, name.c_str());
    }

    float Window::timeF = 0;
    const float &Window::timeFlow = timeF;

    void Window::clear() {
        glDisable(GL_SCISSOR_TEST);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    }

    float Window::display() {
        glfwSwapBuffers((GLFWwindow *) window);

        auto now = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> diff = now - lastFrameTime;
        ImGui::GetIO().DeltaTime = diff.count();
        fpsCouner = fpsCouner + diff;
        lastFrameTime = now;

        Controls::update();

        timeF = diff.count();
        return timeF;
    }

    void Window::resize(unsigned int w, unsigned int h) {
        height = h;
        width = w;

        projectionMatrix = glm::perspective(cameraAngle, width / (GLfloat) height, cameraRange.x, cameraRange.y);

        projectionMatrix2D = {
                2.0f / (width), 0.0f, 0.0f, 0.0f,
                0.0f, 2.0f / (-height), 0.0f, 0.0f,
                0.0f, 0.0f, -1.0f, 0.0f,
                -1.f, 1.f, 0.0f, 1.0f,
        };

        glViewport(0, 0, w, h);

        int ww, hh;
        glfwGetWindowSize((GLFWwindow *) window, &ww, &hh);

        if (ww != w || hh != h)
            glfwSetWindowSize((GLFWwindow *) window, w, h);

        ImGuiIO &io = ImGui::GetIO();
        io.DisplayFramebufferScale = getFrameBufferSize() / getSize();
        io.DisplaySize = getSize();
    }

    std::array<float, 3> Window::getWorldPosition() {
        ImGuiIO &io = ImGui::GetIO();

        Vec2f mousePos = io.MousePos;
        mousePos = mousePos / getSize() * 2;
        mousePos.x = mousePos.x - 1;
        mousePos.y = 1 - mousePos.y;

        /*//Look at test
        glm::vec4 posCamera(50, 50, 15, 1);

        ImGui::Text("World pos : %.3f, %.3f, %.3f", posCamera.x, posCamera.y, posCamera.z);
        posCamera = (projectionMatrix * viewMatrix) * posCamera;
        ImGui::Text("camera pos : %.3f, %.3f, %.3f", posCamera.x, posCamera.y, posCamera.z);
        posCamera = posCamera / posCamera.w;
        ImGui::Text("camera rerange : %.3f, %.3f, %.3f", posCamera.x, posCamera.y, (posCamera.z + 1) / 2);
        posCamera = glm::inverse(projectionMatrix * viewMatrix) * posCamera;
        ImGui::Text("inverse : %.3f, %.3f, %.3f", posCamera.x, posCamera.y, posCamera.z);
        posCamera = posCamera / posCamera.w;
        ImGui::Text("inverse rerange : %.3f, %.3f, %.3f", posCamera.x, posCamera.y, posCamera.z);
        //
        */

        float z;

        glReadPixels((int) io.MousePos.x, height - (int) io.MousePos.y, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &z);

        z = (z * 2) - 1;

        glm::vec4 pos(mousePos.x, mousePos.y, z, 1);

        pos = glm::inverse(projectionMatrix * viewMatrix) * pos;
        pos = pos / pos.w;

        return {pos.x, pos.y, pos.z};
    }

    Blob::Vec2f Window::getFrameBufferSize() {
        int display_w, display_h;
        glfwGetFramebufferSize((GLFWwindow *) window, &display_w, &display_h);
        return {(float) display_w, (float) display_h};
    }

    void Window::close() {
        quit = true;
    }
}

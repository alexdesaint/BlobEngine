#include <Blob/WindowCore.hpp>

// GLFW an OpenGL
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Blob
#include <Blob/Controls.hpp>
#include <Blob/Exception.hpp>
#include <Blob/GL/Core.hpp>

// std
#include <Blob/Shapes.hpp>
#include <iostream>

namespace Blob {
WindowCore::WindowCore(bool fullScreen, unsigned int width, unsigned int height) : width(width), height(height), fullScreen(fullScreen) {
    // The OpenGL window build
    std::cout << "init Window" << std::endl;
    glfwSetErrorCallback(GLFWErrorCallback);

    if (!glfwInit())
        throw Exception("Can't init glfw");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, Blob::GL::Core::GLmajor);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, Blob::GL::Core::GLminor);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);

    glfwWindowHint(GLFW_SAMPLES, 8);

    // TODO: update this
    if (fullScreen) {
        const GLFWvidmode *mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
        glfwWindowHint(GLFW_RED_BITS, mode->redBits);
        glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
        glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
        glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

        this->width = mode->width;
        this->height = mode->height;

        window = glfwCreateWindow(static_cast<int>(this->width), static_cast<int>(this->height), "My Title", glfwGetPrimaryMonitor(), nullptr);
    } else {
        window = glfwCreateWindow(static_cast<int>(width), static_cast<int>(height), "My Title", nullptr, nullptr);
    }

    if (!window) {
        glfwTerminate();
        throw Blob::Exception("Can't create window");
    }

    glfwSetWindowUserPointer((GLFWwindow *) window, this);
    glfwSetFramebufferSizeCallback((GLFWwindow *) window, (GLFWframebuffersizefun) framebuffer_size_callback);
    glfwMakeContextCurrent((GLFWwindow *) window);
    glfwSwapInterval(1);
    GL::Core::init((void *) glfwGetProcAddress, this->width, this->height);
    Controls::init(window);
}

void WindowCore::framebuffer_size_callback(void *window, int w, int h) {
    auto g = (WindowCore *) glfwGetWindowUserPointer((GLFWwindow *) window);
    g->resize(w, h);
}

void WindowCore::GLFWErrorCallback(int error, const char *description) {
    std::cout << "GLFW Error " << error << " : " << description;
}

bool WindowCore::isOpen() const {
    return !(glfwWindowShouldClose((GLFWwindow *) window) || quit);
}

WindowCore::~WindowCore() {
    std::cout << "delete Window" << std::endl;
    glfwDestroyWindow((GLFWwindow *) window);
    glfwTerminate();
}

void WindowCore::setTitle(const std::string &name) {
    glfwSetWindowTitle((GLFWwindow *) window, name.c_str());
}

Blob::Vec2f WindowCore::getFrameBufferSize() {
    int display_w, display_h;
    glfwGetFramebufferSize((GLFWwindow *) window, &display_w, &display_h);
    return {(float) display_w, (float) display_h};
}

void WindowCore::close() {
    quit = true;
}

void WindowCore::resize(unsigned int w, unsigned int h) {
    int ww, hh;
    glfwGetWindowSize((GLFWwindow *) window, &ww, &hh);

    width = ww;
    height = hh;

    if (ww != w || hh != h)
        glfwSetWindowSize((GLFWwindow *) window, w, h);
}

void WindowCore::swapBuffers() {
    glfwSwapBuffers((GLFWwindow *) window);
}
} // namespace Blob
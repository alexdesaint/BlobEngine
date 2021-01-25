// blobEngine
#include <Blob/Core/Exception.hpp>
#include <Blob/GL/Window.hpp>

// GLAD
#include <glad/glad.h>

// std
#include <iostream>

namespace Blob::GL {

void GLAPIENTRY openglCallbackFunction(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message,
                                       const void *userParam) {
    (void) source;
    (void) type;
    (void) id;
    (void) length;
    (void) userParam;

    std::string errorName;

    switch (type) {
    case GL_NO_ERROR:
        errorName = "OpenGL NO_ERROR";
        break;
    case GL_INVALID_ENUM:
        errorName = "OpenGL INVALID_ENUM";
        break;
    case GL_INVALID_VALUE:
        errorName = "OpenGL INVALID_VALUE";
        break;
    case GL_INVALID_OPERATION:
        errorName = "OpenGL INVALID_OPERATION";
        break;
    case GL_INVALID_FRAMEBUFFER_OPERATION:
        errorName = "OpenGL INVALID_FRAMEBUFFER_OPERATION";
        break;
    case GL_OUT_OF_MEMORY:
        errorName = "OpenGL OUT_OF_MEMORY";
        break;
    case GL_STACK_UNDERFLOW:
        errorName = "OpenGL STACK_UNDERFLOW";
        break;
    case GL_STACK_OVERFLOW:
        errorName = "OpenGL STACK_OVERFLOW";
        break;
    case GL_DEBUG_TYPE_ERROR:
        errorName = "OpenGL DEBUG_TYPE_ERROR";
        break;
    case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
        errorName = "OpenGL DEBUG_TYPE_DEPRECATED_BEHAVIOR";
        break;
    case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
        errorName = "OpenGL DEBUG_TYPE_UNDEFINED_BEHAVIOR";
        break;
    case GL_DEBUG_TYPE_PORTABILITY:
        errorName = "OpenGL DEBUG_TYPE_PORTABILITY";
        break;
    case GL_DEBUG_TYPE_PERFORMANCE:
        errorName = "OpenGL DEBUG_TYPE_PERFORMANCE";
        break;
    case GL_DEBUG_TYPE_OTHER:
        errorName = "OpenGL DEBUG_TYPE_OTHER";
        break;
    default:
        errorName = "OpenGL Unknown Error Type (" + std::to_string(type) + ")";
        break;
    }

    switch (severity) {
    case GL_DEBUG_SEVERITY_NOTIFICATION:
        // std::cout << errorName << " (Notification) : " << std::endl << "    " << message << std::endl;
        break;
    case GL_DEBUG_SEVERITY_LOW:
        std::cout << errorName << " (Low severity Error) : " << std::endl << message << std::endl;
        break;
    case GL_DEBUG_SEVERITY_MEDIUM:
        std::cout << errorName << " (Medium severity Error) : " << std::endl << message << std::endl;
        break;
    case GL_DEBUG_SEVERITY_HIGH:
        throw Blob::Core::Exception(errorName + " (High severity Error) : " + "\n" + message);
    default:
        std::cout << errorName << " (Unknow severity Error) : " << std::endl << message << std::endl;
        break;
    }
}

Window::Window(const Maths::Vec2<unsigned int> &windowSize, int GLmajor, int GLminor) : GLFW::Window(windowSize, GLmajor, GLminor){
    //std::cout << "init OpenGL" << std::endl;
    if (!gladLoadGLLoader((GLADloadproc) GLFW::Window::getProcAddress))
        throw Blob::Core::Exception("Fail to load openGL");

    if (GLmajor != GLVersion.major || GLminor > GLVersion.minor)
        throw Blob::Core::Exception("Fail to load the right version of OpenGL. Loaded version : " + std::to_string(GLVersion.major) + "." +
                                    std::to_string(GLVersion.minor) + " instead of " + std::to_string(GLmajor) + "\n" + std::to_string(GLminor) +
                                    ". System version : " + (char *) glGetString(GL_VERSION));

    std::cout << "init OpenGL " << GLVersion.major << "." << GLVersion.minor << std::endl;
    // Enable the debug callback
    glEnable(GL_DEBUG_OUTPUT);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    glDebugMessageCallback(openglCallbackFunction, nullptr);
    glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE);

    // general settings

    // cull
    glEnable(GL_CULL_FACE);
    //    glCullFace(GL_FRONT);
    //    glFrontFace(GL_CCW);

    glDisable(GL_SCISSOR_TEST);

    // The default : depth
    //    glClipControl(GL_LOWER_LEFT, GL_NEGATIVE_ONE_TO_ONE);
    //    glClearDepth(1.0f);
    //    glDepthFunc(GL_LESS);
    //    glEnable(GL_DEPTH_CLAMP);

    glEnable(GL_DEPTH_TEST);

    // glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // pour faire des lignes
    glClearColor(0.27, 0.27, 0.27, 1.0);
    glViewport(0, 0, windowSize.x, windowSize.y);

    // alpha
    glEnable(GL_BLEND);
    glBlendEquation(GL_FUNC_ADD);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}
Window::~Window() {
    std::cout << "destroy OpenGL" << std::endl;
}

std::ostream &operator<<(std::ostream &s, const Window &a) {
    s << glGetString(GL_VENDOR) << std::endl
      << glGetString(GL_RENDERER) << std::endl
      << glGetString(GL_VERSION) << std::endl
      << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
    return s;
}

void Window::clear() const {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void Window::setViewport(const Maths::Vec2<unsigned int> &framebufferSize) const {
    glViewport(0, 0, framebufferSize.x, framebufferSize.y);
}

float Window::readPixel(const Maths::Vec2<int> &pos) const {
    float z;

    glReadPixels(pos.x, pos.y, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &z);

    return z;
}

void Window::setVAO(const VertexArrayObject &vao) const {
    glBindVertexArray(vao.vertexArrayObject);
}

void Window::setVAO(const VertexArrayObject *vao) const {
    glBindVertexArray(vao->vertexArrayObject);
}

void Window::drawArrays(int32_t count, uint32_t offset) const {
    glDrawArrays(GL_TRIANGLES, offset, count);
}

void Window::drawIndex(const void *indices, int32_t numOfIndices, uint32_t indicesType) const {
    glDrawElements(GL_TRIANGLES, numOfIndices, indicesType, indices);
}

template<>
void Window::drawIndex<uint8_t>(const void *indices, int32_t numOfIndices) const {
    glDrawElements(GL_TRIANGLES, numOfIndices, GL_UNSIGNED_BYTE, indices);
}

template<>
void Window::drawIndex<uint16_t>(const void *indices, int32_t numOfIndices) const {
    glDrawElements(GL_TRIANGLES, numOfIndices, GL_UNSIGNED_SHORT, indices);
}

template<>
void Window::drawIndex<uint32_t>(const void *indices, int32_t numOfIndices) const {
    glDrawElements(GL_TRIANGLES, numOfIndices, GL_UNSIGNED_INT, indices);
}

} // namespace Blob::GL

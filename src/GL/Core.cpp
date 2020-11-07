// blobEngine
#include <Blob/Exception.hpp>
#include <Blob/GL/Core.hpp>

// GLAD
#include <glad/glad.h>

// std
#include <iostream>

namespace Blob::GL {

// TODO: ?????????????
/*
std::ostream &operator<<(std::ostream &out, const glm::mat4 &vec) {

        for (int i = 0; i < 4; i++)
                out << vec[i].x << " " << vec[i].y << " " << vec[i].z << " " << vec[i].w << std::endl;
        return out;
}
*/

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
        errorName = "GL_NO_ERROR";
        break;
    case GL_INVALID_ENUM:
        errorName = "GL_INVALID_ENUM";
        break;
    case GL_INVALID_VALUE:
        errorName = "GL_INVALID_VALUE";
        break;
    case GL_INVALID_OPERATION:
        errorName = "GL_INVALID_OPERATION";
        break;
    case GL_INVALID_FRAMEBUFFER_OPERATION:
        errorName = "GL_INVALID_FRAMEBUFFER_OPERATION";
        break;
    case GL_OUT_OF_MEMORY:
        errorName = "GL_OUT_OF_MEMORY";
        break;
    case GL_STACK_UNDERFLOW:
        errorName = "GL_STACK_UNDERFLOW";
        break;
    case GL_STACK_OVERFLOW:
        errorName = "GL_STACK_OVERFLOW";
        break;
    }

    std::cout << "OpenGL ";

    switch (severity) {
    case GL_DEBUG_SEVERITY_NOTIFICATION:
        std::cout << "Notification : " << errorName << std::endl << "    " << message << std::endl;
        break;
    case GL_DEBUG_SEVERITY_LOW:
        std::cout << "Low severity Error : " << errorName << std::endl << message << std::endl;
        break;
    case GL_DEBUG_SEVERITY_MEDIUM:
        std::cout << "Medium severity Error : " << errorName << std::endl << message << std::endl;
        break;
    case GL_DEBUG_SEVERITY_HIGH:
        throw Blob::Core::Exception("OpenGL High severity Error : " + errorName + "\n" + message);
    default:
        std::cout << "Unknow Error severity : " << errorName << std::endl << message << std::endl;
        break;
    }
}

Context::Context(void *glfwGetProcAddress, const Maths::Vec2<int> &size) {
    std::cout << "init OpenGL" << std::endl;
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
        throw Blob::Core::Exception("Fail to load openGL");

    if (GLmajor != GLVersion.major || GLminor > GLVersion.minor)
        throw Blob::Core::Exception("Fail to load the right version of OpenGL. Loaded version : " + std::to_string(GLVersion.major) + "." +
                                    std::to_string(GLVersion.minor) + " instead of " + std::to_string(GLmajor) + "\n" + std::to_string(GLminor) +
                                    ". System version : " + (char *) glGetString(GL_VERSION));

    // Enable the debug callback
    glEnable(GL_DEBUG_OUTPUT);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    glDebugMessageCallback(openglCallbackFunction, nullptr);
    glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE);

    // general settings

    // cull
    glFrontFace(GL_CCW);
    // glCullFace(GL_FRONT);
    glEnable(GL_CULL_FACE);

    glDisable(GL_SCISSOR_TEST);

    glEnable(GL_DEPTH_TEST);

    // glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // pour faire des lignes
    glClearColor(0.2, 0.2, 0.2, 1.0);
    glViewport(0, 0, size.x, size.y);

    // alpha
    glEnable(GL_BLEND);
    glBlendEquation(GL_FUNC_ADD);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}
Context::~Context() {
    std::cout << "destroy OpenGL" << std::endl;
}

std::ostream &operator<<(std::ostream &s, const Core &a) {
    s << glGetString(GL_VENDOR) << std::endl
      << glGetString(GL_RENDERER) << std::endl
      << glGetString(GL_VERSION) << std::endl
      << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
    return s;
}

void Core::clear() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void Core::setViewport(const Maths::Vec2<int> &framebufferSize) {
    glViewport(0, 0, framebufferSize.x, framebufferSize.y);
}

float Core::readPixel(Maths::Vec2<int> pos) {
    float z;

    glReadPixels(pos.x, pos.y, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &z);

    return z;
}

void Core::setCullFace(bool set) {
    if (set)
        glEnable(GL_CULL_FACE);
    else
        glDisable(GL_CULL_FACE);
}

void Core::setScissorTest(bool set) {
    if (set)
        glEnable(GL_SCISSOR_TEST);
    else
        glDisable(GL_SCISSOR_TEST);
}

void Core::setScissor(int x, int y, int width, int height) {
    glScissor(x, y, width, height);
}

void Core::setDepthTest(bool set) {
    if (set)
        glEnable(GL_DEPTH_TEST);
    else
        glDisable(GL_DEPTH_TEST);
}

void Core::setShader(const ShaderProgram &shaderProgram) {
    glUseProgram(shaderProgram.program);
}

void Core::setVAO(const VertexArrayObject &vao) {
    glBindVertexArray(vao.getVertexArrayObject());
}

void Core::setTexture(const Texture &texture) {
    glBindTexture(GL_TEXTURE_2D, texture.texture);
}

template<>
void Core::setUniform<>(const float (&val)[4][4], int position) {
    glUniformMatrix4fv(position, 1, GL_FALSE, &val[0][0]);
}

template<>
void Core::setUniform<>(const float (&val)[16], int position) {
    glUniformMatrix4fv(position, 1, GL_FALSE, &val[0]);
}

template<>
void Core::setUniform<>(const Maths::Vec2<float> &val, int position) {
    glUniform2fv(position, 1, &val.x);
}

template<>
void Core::setUniform<>(const Maths::Vec3<float> &val, int position) {
    glUniform3fv(position, 1, &val.x);
}

template<>
void Core::setUniform<>(const Maths::Mat3 &val, int position) {
    glUniformMatrix3fv(position, 1, GL_FALSE, &val.a11);
}

template<>
void Core::setUniform<>(const Maths::Mat4 &val, int position) {
    glUniformMatrix4fv(position, 1, GL_FALSE, &val.a11);
}

template<>
void Core::setUniform<>(const Maths::ModelTransform &val, int position) {
    glUniformMatrix4fv(position, 1, GL_FALSE, &val.a11);
}

template<>
void Core::setUniform<>(const Maths::ViewTransform &val, int position) {
    glUniformMatrix4fv(position, 1, GL_FALSE, &val.a11);
}

template<>
void Core::setUniform<>(const Maths::ProjectionTransform &val, int position) {
    glUniformMatrix4fv(position, 1, GL_FALSE, &val.a11);
}

template<>
void Core::setUniform<>(const Color::RGB &c, int position) {
    glUniform3fv(position, 1, &c.R);
}

template<>
void Core::setUniform<>(const float &val, int position) {
    glUniform1f(position, val);
}

template<>
void Core::setUniform<>(const int &val, int position) {
    glUniform1i(position, val);
}

template<>
void Core::setUniform<>(const unsigned int &val, int position) {
    glUniform1ui(position, val);
}

void Core::drawIndex(const void *indices, int32_t numOfIndices, uint32_t indicesType) {
    glDrawElements(GL_TRIANGLES, numOfIndices, indicesType, indices);
}

template<>
void Core::drawIndex<uint8_t>(const void *indices, int32_t numOfIndices) {
    Core::drawIndex(indices, numOfIndices, GL_UNSIGNED_BYTE);
}

template<>
void Core::drawIndex<uint16_t>(const void *indices, int32_t numOfIndices) {
    Core::drawIndex(indices, numOfIndices, GL_UNSIGNED_SHORT);
}

template<>
void Core::drawIndex<uint32_t>(const void *indices, int32_t numOfIndices) {
    Core::drawIndex(indices, numOfIndices, GL_UNSIGNED_INT);
}

template<>
uint32_t Core::getType<int8_t>() {
    return GL_BYTE;
}

template<>
uint32_t Core::getType<int16_t>() {
    return GL_SHORT;
}

template<>
uint32_t Core::getType<int32_t>() {
    return GL_INT;
}

template<>
uint32_t Core::getType<uint8_t>() {
    return GL_UNSIGNED_BYTE;
}

template<>
uint32_t Core::getType<uint16_t>() {
    return GL_UNSIGNED_SHORT;
}

template<>
uint32_t Core::getType<uint32_t>() {
    return GL_UNSIGNED_INT;
}

template<>
uint32_t Core::getType<float>() {
    return GL_FLOAT;
}

} // namespace Blob::GL

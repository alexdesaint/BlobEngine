// blobEngine
#include <Blob/Exception.hpp>
#include <Blob/GL/Core.hpp>

// GLAD
#include <glad/glad.h>

// std
#include <iostream>

using namespace Blob;

namespace Blob::GL {

// TODO: ?????????????
/*
std::ostream &operator<<(std::ostream &out, const glm::mat4 &vec) {

        for (int i = 0; i < 4; i++)
                out << vec[i].x << " " << vec[i].y << " " << vec[i].z << " " << vec[i].w << std::endl;
        return out;
}
*/

    void GLAPIENTRY openglCallbackFunction(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length,
                                           const GLchar *message,
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
                std::cout << "High severity Error : " << errorName << std::endl << message << std::endl;
                abort();
            default:
                std::cout << "Unknow Error severity : " << errorName << std::endl << message << std::endl;
                break;
        }
    }

    void Core::init(void *glfwGetProcAddress, unsigned int width, unsigned int height) {
        std::cout << "init Core" << std::endl;
        if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
            throw Exception("Fail to load openGL");

        if (GLmajor != GLVersion.major || GLminor > GLVersion.minor)
            throw Exception(
                    "Fail to load the right version of OpenGL. Loaded version : " + std::to_string(GLVersion.major) +
                    "." +
                    std::to_string(GLVersion.minor) + " instead of " + std::to_string(GLmajor) + "\n" +
                    std::to_string(GLminor) +
                    ". System version : " + (char *) glGetString(GL_VERSION));

        // Enable the debug callback
        glEnable(GL_DEBUG_OUTPUT);
        glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
        glDebugMessageCallback(openglCallbackFunction, nullptr);
        glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE);

        // general settings

        // cull
        glFrontFace(GL_CCW);
        //glCullFace(GL_FRONT);
        glEnable(GL_CULL_FACE);

        glDisable(GL_SCISSOR_TEST);

        glEnable(GL_DEPTH_TEST);

        // glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // pour faire des lignes
        glClearColor(0.2, 0.2, 0.2, 1.0);
        glViewport(0, 0, width, height);

        // alpha
        glEnable(GL_BLEND);
        glBlendEquation(GL_FUNC_ADD);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
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

    void Core::setViewport(unsigned int width, unsigned int height) {
        glViewport(0, 0, width, height);
    }

    float Core::readPixel(Blob::Vec2f pos) {
        float z;

        glReadPixels((int) pos.x, (int) pos.y, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &z);

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

    void Core::setMat4(const float *matrix, int position) {
        glUniformMatrix4fv(position, 1, GL_FALSE, matrix);
    }

    void Core::setVec2(const float *matrix, int position) {
        glUniform2fv(position, 1, matrix);
    }

    void Core::setVec3(const float *matrix, int position) {
        glUniform3fv(position, 1, matrix);
    }

    void Core::setVec4(const float *matrix, int position) {
        glUniform4fv(position, 1, matrix);
    }

    void Core::setFloat(float val, int position) {
        glUniform1f(position, val);
    }

    void Core::setUint(int32_t val, int position) {
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
    uint32_t Core::getType<int8_t>() { return GL_BYTE; }

    template<>
    uint32_t Core::getType<int16_t>() { return GL_SHORT; }

    template<>
    uint32_t Core::getType<int32_t>() { return GL_INT; }

    template<>
    uint32_t Core::getType<uint8_t>() { return GL_UNSIGNED_BYTE; }

    template<>
    uint32_t Core::getType<uint16_t>() { return GL_UNSIGNED_SHORT; }

    template<>
    uint32_t Core::getType<uint32_t>() { return GL_UNSIGNED_INT; }

    template<>
    uint32_t Core::getType<float>() { return GL_FLOAT; }

} // namespace Blob::GL

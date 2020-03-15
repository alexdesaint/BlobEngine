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

void Graphic::draw(const Shape &shape, glm::mat4 sceneModel) {
        glm::mat4 modelMatrix = sceneModel * shape.getModelMatrix();

        /*std::cout << "mat :" << std::endl << modelMatrix;

        std::cout << "r :" << std::endl;
        for(Renderable *r : shape.renderables)
                std::cout << std::hex << r << " ";
        std::cout << std::endl;

        for (auto r : shape.shapes)
                draw(*r, modelMatrix);

        for (auto r : shape.renderables)
                draw(*r, modelMatrix);
}

void Graphic::draw(const Scene &scene) {
        glm::mat4 modelMatrix = scene.getModelMatrix();

        std::cout << "mat :" << std::endl << modelMatrix;

        std::cout << "r :" << std::endl;
        for(Shape *r : scene.shapes)
                std::cout << std::hex << r << " ";
        std::cout << std::endl;

        for (auto r : scene.shapes)
                draw(*r, modelMatrix);
}
*/

void GLAPIENTRY openglCallbackFunction(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message,
                                       const void *userParam) {
    (void) source;
    (void) type;
    (void) id;
    (void) length;
    (void) userParam;

    switch (severity) {
    case GL_DEBUG_SEVERITY_NOTIFICATION:
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

void Core::init(void *glfwGetProcAddress, unsigned int width, unsigned int height) {
    std::cout << "init Core" << std::endl;
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
        throw Exception("Fail to load openGL");

    if (GLmajor != GLVersion.major || GLminor > GLVersion.minor)
        throw Exception("Fail to load the right version of OpenGL. Loaded version : " + std::to_string(GLVersion.major) + "." +
                        std::to_string(GLVersion.minor) + " instead of " + std::to_string(GLmajor) + "\n" + std::to_string(GLminor) +
                        ". System version : " + (char *) glGetString(GL_VERSION));

    // Enable the debug callback
    glEnable(GL_DEBUG_OUTPUT);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    glDebugMessageCallback(openglCallbackFunction, nullptr);
    glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE);

    // general settings
    glFrontFace(GL_CW);
    //glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // pour faire des lignes
    glClearColor(0.2, 0.2, 0.2, 1.0);
    glViewport(0, 0, width, height);
    glCullFace(GL_FRONT);

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

void Core::draw(const RenderOptions &renderOptions, const ShaderProgram &shaderProgram, const VertexArrayObject &vertexArrayObject,
                const Texture &texture, const float *projection, const float *view, const float *model) {

    if (renderOptions.cullFace)
        glEnable(GL_CULL_FACE);
    else
        glDisable(GL_CULL_FACE);

    if (renderOptions.scissorTest)
        glEnable(GL_SCISSOR_TEST);
    else
        glDisable(GL_SCISSOR_TEST);

    if (renderOptions.depthTest)
        glEnable(GL_DEPTH_TEST);
    else
        glDisable(GL_DEPTH_TEST);

    glUseProgram(shaderProgram.getProgram());
    glBindVertexArray(vertexArrayObject.getVertexArrayObject());

    glUniformMatrix4fv(shaderProgram.projection, 1, GL_FALSE, projection);
    glUniformMatrix4fv(shaderProgram.view, 1, GL_FALSE, view);
    glUniformMatrix4fv(shaderProgram.model, 1, GL_FALSE, model);

    glBindTexture(GL_TEXTURE_2D, texture.texture);
    glUniform2f(shaderProgram.textureScale, renderOptions.textureScale.x, renderOptions.textureScale.y);

    if (renderOptions.indexed)
        glDrawElements(GL_TRIANGLES, renderOptions.numOfIndices, renderOptions.indicesType, renderOptions.indices);
    else
        glDrawArrays(GL_TRIANGLES, renderOptions.elementOffset, renderOptions.numOfElements);
}

void Core::draw(const RenderOptions &renderOptions, const ShaderProgram &shaderProgram, const VertexArrayObject &vertexArrayObject,
                const float *projection, const float *view, const float *model) {

    if (renderOptions.cullFace)
        glEnable(GL_CULL_FACE);
    else
        glDisable(GL_CULL_FACE);

    if (renderOptions.scissorTest)
        glEnable(GL_SCISSOR_TEST);
    else
        glDisable(GL_SCISSOR_TEST);

    if (renderOptions.depthTest)
        glEnable(GL_DEPTH_TEST);
    else
        glDisable(GL_DEPTH_TEST);

    glUseProgram(shaderProgram.getProgram());
    glBindVertexArray(vertexArrayObject.getVertexArrayObject());

    glUniformMatrix4fv(shaderProgram.projection, 1, GL_FALSE, projection);
    glUniformMatrix4fv(shaderProgram.view, 1, GL_FALSE, view);
    glUniformMatrix4fv(shaderProgram.model, 1, GL_FALSE, model);

    if (renderOptions.indexed)
        glDrawElements(GL_TRIANGLES, renderOptions.numOfIndices, renderOptions.indicesType, renderOptions.indices);
    else
        glDrawArrays(GL_TRIANGLES, renderOptions.elementOffset, renderOptions.numOfElements);
}

void Core::clear() {
    glDisable(GL_SCISSOR_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void Core::setlViewport(unsigned int width, unsigned int height) {
    glViewport(0, 0, width, height);
}

float Core::readPixel(Blob::Vec2f pos) {
    float z;

    glReadPixels((int) pos.x, (int) pos.y, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &z);

    return z;
}
} // namespace Blob::GL

#include <iostream>
#include <vector>

#include <Blob/Exception.hpp>
#include <Blob/GL/ShaderProgram.hpp>
#include <Blob/Reader/FileReader.hpp>

#include <glad/glad.h>

std::unordered_map<std::string, Blob::GL::ShaderProgram> Blob::GL::ShaderProgram::Shaders;

Blob::GL::ShaderProgram::ShaderProgram() {
    // Get a program object.
    program = glCreateProgram();
}

Blob::GL::ShaderProgram::ShaderProgram(const std::string &pathVertex, const std::string &pathFragment) {
    program = glCreateProgram();

    addVertexShader(pathVertex);

    addFragmentShader(pathFragment);

    linkShaders();
}

/*Blob::GL::ShaderProgram::ShaderProgram(Blob::GL::ShaderProgram &&shaderProgram) noexcept {
    program = shaderProgram.program;

    vertexShader = shaderProgram.vertexShader;
    fragmentShader = shaderProgram.fragmentShader;

    model = shaderProgram.model;
    view = shaderProgram.view;
    projection = shaderProgram.projection;
    textureScale = shaderProgram.textureScale;

    shaderProgram.program = 0;
    shaderProgram.vertexShader = 0;
    shaderProgram.fragmentShader = 0;
}*/

Blob::GL::ShaderProgram::~ShaderProgram() {
    if (program != 0)
        glDeleteProgram(program);

    if (vertexShader != 0)
        glDeleteShader(vertexShader);

    if (fragmentShader != 0)
        glDeleteShader(fragmentShader);
}

/// TODO: Simplify this
void Blob::GL::ShaderProgram::addVertexShader(const std::string &src) {

    // Create an empty vertex shader handle
    vertexShader = glCreateShader(GL_VERTEX_SHADER);

    // Send the vertex shader source code to GL
    // Note that std::string's .c_str is NULL character terminated.
    const GLchar *source = src.c_str();

    glShaderSource(vertexShader, 1, &source, nullptr);

    // Compile the vertex shader
    glCompileShader(vertexShader);

    GLint isCompiled = 0;
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &isCompiled);
    if (isCompiled == GL_FALSE) {
        GLint maxLength = 0;
        glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &maxLength);

        // The maxLength includes the NULL character
        std::vector<GLchar> infoLog(maxLength);
        glGetShaderInfoLog(vertexShader, maxLength, &maxLength, &infoLog[0]);

        // We don't need the shader anymore.
        glDeleteShader(vertexShader);

        // Use the infoLog as you see fit.

        // In this simple program, we'll just leave

        throw Exception(infoLog.data());
    }

    GLint maxLength = 0;

    glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &maxLength);

    if (maxLength != 0) {
        std::vector<GLchar> infoLog(maxLength);
        glGetShaderInfoLog(vertexShader, maxLength, &maxLength, &infoLog[0]);

        std::cout << "Shader compilation warning for shader :" << std::endl << source << std::endl << infoLog.data();
    }
}

void Blob::GL::ShaderProgram::addFragmentShader(const std::string &src) {
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    // Send the vertex shader source code to GL
    // Note that std::string's .c_str is NULL character terminated.
    const GLchar *source = src.c_str();
    glShaderSource(fragmentShader, 1, &source, 0);

    // Compile the vertex shader
    glCompileShader(fragmentShader);

    GLint isCompiled = 0;
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &isCompiled);
    if (isCompiled == GL_FALSE) {
        GLint maxLength = 0;
        glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);

        // The maxLength includes the NULL character
        std::vector<GLchar> infoLog(maxLength);
        glGetShaderInfoLog(fragmentShader, maxLength, &maxLength, &infoLog[0]);

        // We don't need the shader anymore.
        glDeleteShader(fragmentShader);

        // Use the infoLog as you see fit.

        // In this simple program, we'll just leave

        throw Exception(infoLog.data());
    }

    GLint maxLength = 0;

    glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);

    if (maxLength != 0) {
        std::vector<GLchar> infoLog(maxLength);
        glGetShaderInfoLog(fragmentShader, maxLength, &maxLength, &infoLog[0]);

        std::cout << "Shader compilation warning for shader :" << std::endl << source << std::endl << infoLog.data();
    }
}

void Blob::GL::ShaderProgram::linkShaders() {
    // Vertex and fragment shaders are successfully compiled.
    // Now time to link them together into a program.

    // Attach our shaders to our program
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);

    GLint maxLength = 0;
    glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);
    if (maxLength != 0) {
        std::vector<GLchar> infoLog(maxLength);
        glGetShaderInfoLog(fragmentShader, maxLength, &maxLength, &infoLog[0]);

        std::cout << "Shader compilation warning for shader :" << std::endl << infoLog.data();
    }

    // Link our program
    glLinkProgram(program);

    // Note the different functions here: glGetProgram* instead of glGetShader*.
    GLint isLinked = 0;
    glGetProgramiv(program, GL_LINK_STATUS, &isLinked);
    if (isLinked == GL_FALSE) {
        linked = false;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

        std::vector<GLchar> infoLog(maxLength);
        glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);

        throw Exception(infoLog.data());
    }

    linked = true;

    maxLength = 0;

    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

    if (maxLength != 0) {
        std::vector<GLchar> infoLog(maxLength);
        glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);

        std::cout << "Shader linking warning :" << std::endl << infoLog.data();
    }

    // Always detach shaders after a successful link.
    glDetachShader(program, vertexShader);
    glDetachShader(program, fragmentShader);

    /*
    model = glGetUniformLocation(program, "model");
    view = glGetUniformLocation(program, "view");
    projection = glGetUniformLocation(program, "projection");
    textureScale = glGetUniformLocation(program, "texScale");
    */
}

GLuint Blob::GL::ShaderProgram::getProgram() const {
    return program;
}

void Blob::GL::ShaderProgram::addFragmentShaderFile(const std::string &path) {
    Reader::FileReader f(path);
    addFragmentShader(f.toString());
}

void Blob::GL::ShaderProgram::addVertexShaderFile(const std::string &path) {
    Reader::FileReader f(path);
    addVertexShader(f.toString());
}

uint32_t Blob::GL::ShaderProgram::getUniformLocation(const char *name) const {
    int r = glGetUniformLocation(program, name);
    if (r < 0)
        throw Exception(std::string("ShaderProgram error : Unknown UniformLocation name ") + name);
    return static_cast<uint32_t>(r);
}

uint32_t Blob::GL::ShaderProgram::getAttribLocation(const char *name) const {
    int r = glGetAttribLocation(program, name);
    if (r < 0)
        throw Exception(std::string("ShaderProgram error : Unknown Attrib Location name ") + name);
    return static_cast<uint32_t>(r);
}

#include <iostream>

#include <Blob/Core/Exception.hpp>
#include <Blob/GL/Shader.hpp>

#include <glad/glad.h>
#include <vector>

namespace Blob::GL {

const ShaderProgram::Type ShaderProgram::Types::Vertex = GL_VERTEX_SHADER;
const ShaderProgram::Type ShaderProgram::Types::TessellationControl =
    0;                                                          // FIXME
const ShaderProgram::Type ShaderProgram::Types::Evaluation = 1; // FIXME
const ShaderProgram::Type ShaderProgram::Types::Geometry = GL_GEOMETRY_SHADER;
const ShaderProgram::Type ShaderProgram::Types::Fragment = GL_FRAGMENT_SHADER;
const ShaderProgram::Type ShaderProgram::Types::Compute = 2; // FIXME

void ShaderProgram::destroy() {
    if (program != 0)
        glDeleteProgram(program);

    for (auto &[type, shader] : shaders) {
        glDeleteShader(shader);
        shader = 0;
    }
}

void ShaderProgram::addShader(Type type, const std::string &src) {
    shaders[type] = glCreateShader(type);
    std::cout << "Shader " << shaders[type] << std::endl;
    std::cout << src << std::endl;
    try {
        const GLchar *source = src.c_str();

        glShaderSource(shaders[type], 1, &source, nullptr);

        glCompileShader(shaders[type]);
    } catch (Blob::Exception &exception) {
        std::cout << exception.what() << std::endl;
        std::cout << src << std::endl;
        glDeleteShader(shaders[type]);
        shaders[type] = 0;
    }
}

void ShaderProgram::addVertexShader(const std::string &src) {
    addShader(Types::Vertex, src);
}

void ShaderProgram::addGeometryShader(const std::string &src) {
    addShader(Types::Geometry, src);
}

void ShaderProgram::addFragmentShader(const std::string &src) {
    addShader(Types::Fragment, src);
}

void ShaderProgram::linkShaders() {
    try {
        program = glCreateProgram();
        std::cout << "Program " << program << "(";
        for (auto &[type, shader] : shaders) {
            std::cout << " " << shader;
            glAttachShader(program, shader);
        }
        std::cout << ") " << std::endl;

        glLinkProgram(program);

        for (auto &[type, shader] : shaders)
            glDetachShader(program, shader);

        GLint linked;
        glGetProgramiv(program, GL_LINK_STATUS, &linked);
        if (!linked) {
            GLint maxLength = 0;
            glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

            std::vector<GLchar> infoLog(maxLength);
            glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);

            std::cout << "Shader linking Error" << std::endl;
            std::cout << infoLog.data() << std::endl;

            glDeleteProgram(program);
            program = 0;
        }
    } catch (Blob::Exception &exception) {
        std::cout << exception.what() << std::endl;
        for (auto &[type, shader] : shaders)
            glDetachShader(program, shader);
        glDeleteProgram(program);
        program = 0;
        return;
    }
}

int32_t ShaderProgram::getUniformLocation(const char *name) const {
    return glGetUniformLocation(program, name);
}

int32_t ShaderProgram::getAttribLocation(const char *name) const {
    return glGetAttribLocation(program, name);
}

} // namespace Blob::GL
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <sstream>

#include <Blob/Core/Exception.hpp>
#include <Blob/GL/Shader.hpp>

#include <glad/gl.h>
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
    try {
        const GLchar *source = src.c_str();

        glShaderSource(shaders[type], 1, &source, nullptr);

        glCompileShader(shaders[type]);
    } catch (Blob::Exception &exception) {
        std::cout << "Shader " << shaders[type] << std::endl;
        std::istringstream f(src);
        std::string line;
        size_t lineNumber = 1;
        while (std::getline(f, line)) {
            std::printf("%4lu| ", lineNumber);
            std::cout << line << std::endl;
            lineNumber++;
        }
        std::cout << exception.what() << std::endl;
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
        for (auto &[type, shader] : shaders) {
            if (shader == 0) {
                std::cout << "Program " << program
                          << " have uncompiled shader, this program will not "
                             "get linked"
                          << std::endl;
                return;
            }
            glAttachShader(program, shader);
        }

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
        std::cout << "Shader linking Exception" << std::endl;
        std::cout << exception.what() << std::endl;
        for (auto &[type, shader] : shaders)
            glDetachShader(program, shader);
        glDeleteProgram(program);
        program = 0;
    }
}

int32_t ShaderProgram::getUniformLocation(const char *name) const {
    return glGetUniformLocation(program, name);
}

int32_t ShaderProgram::getAttribLocation(const char *name) const {
    return glGetAttribLocation(program, name);
}

} // namespace Blob::GL
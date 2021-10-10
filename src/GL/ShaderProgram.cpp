#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <sstream>

#include <Blob/Core/Exception.hpp>
#include <Blob/GL/Shader.hpp>

#include <glad/gl.h>
#include <vector>

namespace Blob::GL {

const ShaderProgram::Type ShaderProgram::Types::Vertex = GL_VERTEX_SHADER;
const ShaderProgram::Type ShaderProgram::Types::Tessellation =
    GL_TESS_CONTROL_SHADER;
const ShaderProgram::Type ShaderProgram::Types::Evaluation =
    GL_TESS_EVALUATION_SHADER;
const ShaderProgram::Type ShaderProgram::Types::Geometry = GL_GEOMETRY_SHADER;
const ShaderProgram::Type ShaderProgram::Types::Fragment = GL_FRAGMENT_SHADER;
const ShaderProgram::Type ShaderProgram::Types::Compute = GL_COMPUTE_SHADER;

void ShaderProgram::destroy() {
    if (program != 0)
        glDeleteProgram(program);

    for (auto &[type, shader] : shaders) {
        glDeleteShader(shader);
        shader = 0;
    }
}

void ShaderProgram::addShader(Type type, const std::string &src) {
    if (shaders[type] != 0)
        glDeleteShader(shaders[type]);
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

void ShaderProgram::addSpirV(Type type,
                             const std::vector<uint8_t> &src,
                             const std::string &entryPointName) {
    if (shaders[type] != 0)
        glDeleteShader(shaders[type]);
    shaders[type] = glCreateShader(type);

    try {
        glShaderBinary(1,
                       &shaders[type],
                       GL_SHADER_BINARY_FORMAT_SPIR_V,
                       src.data(),
                       src.size());

        glSpecializeShader(shaders[type],
                           entryPointName.c_str(),
                           0,
                           nullptr,
                           nullptr);
    } catch (Blob::Exception &exception) {
        std::cout << "Shader " << shaders[type] << std::endl;
        std::cout << exception.what() << std::endl;
        glDeleteShader(shaders[type]);
        shaders[type] = 0;
    }
}

void ShaderProgram::addSpirV(Type type,
                             const std::vector<uint32_t> &src,
                             const std::string &entryPointName) {
    if (shaders[type] != 0)
        glDeleteShader(shaders[type]);
    shaders[type] = glCreateShader(type);

    try {
        glShaderBinary(1,
                       &shaders[type],
                       GL_SHADER_BINARY_FORMAT_SPIR_V,
                       src.data(),
                       src.size() * 4);

        glSpecializeShader(shaders[type],
                           entryPointName.c_str(),
                           0,
                           nullptr,
                           nullptr);
    } catch (Blob::Exception &exception) {
        std::cout << "Shader " << shaders[type] << std::endl;
        std::cout << exception.what() << std::endl;
        glDeleteShader(shaders[type]);
        shaders[type] = 0;
    }
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
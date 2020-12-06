#include <iostream>

#include <Blob/Core/Exception.hpp>
#include <Blob/GL/Shader.hpp>

#include <glad/glad.h>
#include <vector>

namespace Blob::GL {

void Shader::destroy() const {
    if (program != 0)
        glDeleteProgram(program);

    if (vertexShader != 0)
        glDeleteShader(vertexShader);

    if (fragmentShader != 0)
        glDeleteShader(fragmentShader);
}

void Shader::addVertexShader(const std::string &src) {
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    try {
        const GLchar *source = src.c_str();

        glShaderSource(vertexShader, 1, &source, nullptr);

        glCompileShader(vertexShader);
    } catch (Blob::Core::Exception &exception) {
        std::cout << exception.what() << std::endl;
        std::cout << src << std::endl;
        glDeleteShader(vertexShader);
        vertexShader = 0;
        return;
    }
}

void Shader::addGeometryShader(const std::string &src) {
    geometryShader = glCreateShader(GL_GEOMETRY_SHADER);
    try {
        const GLchar *source = src.c_str();

        glShaderSource(geometryShader, 1, &source, nullptr);

        glCompileShader(geometryShader);
    } catch (Blob::Core::Exception &exception) {
        std::cout << exception.what() << std::endl;
        std::cout << src << std::endl;
        glDeleteShader(geometryShader);
        geometryShader = 0;
        return;
    }
}

void Shader::addFragmentShader(const std::string &src) {
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    try {
        const GLchar *source = src.c_str();
        glShaderSource(fragmentShader, 1, &source, nullptr);

        glCompileShader(fragmentShader);
    } catch (Blob::Core::Exception &exception) {
        std::cout << exception.what() << std::endl;
        std::cout << src << std::endl;
        glDeleteShader(fragmentShader);
        fragmentShader = 0;
        return;
    }
}

void Shader::linkShaders() {
    try {
        program = glCreateProgram();
        if (vertexShader != 0)
            glAttachShader(program, vertexShader);
        if (geometryShader != 0)
            glAttachShader(program, geometryShader);
        if (fragmentShader != 0)
            glAttachShader(program, fragmentShader);

        glLinkProgram(program);

        if (vertexShader != 0)
            glDetachShader(program, vertexShader);
        if (geometryShader != 0)
            glDetachShader(program, geometryShader);
        if (fragmentShader != 0)
            glDetachShader(program, fragmentShader);

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
    } catch (Blob::Core::Exception &exception) {
        std::cout << exception.what() << std::endl;
        if (vertexShader != 0)
            glDetachShader(program, vertexShader);
        if (geometryShader != 0)
            glDetachShader(program, geometryShader);
        if (fragmentShader != 0)
            glDetachShader(program, fragmentShader);
        glDeleteProgram(program);
        program = 0;
        return;
    }
}

int32_t Shader::getUniformLocation(const char *name) const {
    return glGetUniformLocation(program, name);
}

int32_t Shader::getAttribLocation(const char *name) const {
    return glGetAttribLocation(program, name);
}

} // namespace Blob::GL
#pragma once

#include <string>
#include <unordered_map>

namespace Blob::GL {

class ShaderProgram {
    friend class Shader;

public:
    typedef unsigned int Type;

    struct Types {
        static const Type Vertex;
        static const Type TessellationControl;
        static const Type Evaluation;
        static const Type Geometry;
        static const Type Fragment;
        static const Type Compute;
    };

    unsigned int program = 0;
    std::unordered_map<Type, unsigned int> shaders;

    ShaderProgram() noexcept = default;
    ShaderProgram(const ShaderProgram &) = delete;
    // ShaderProgram(ShaderProgram &&shaderProgram) noexcept;
    ShaderProgram(ShaderProgram &&shaderProgram) = delete;

    void destroy();

    void addShader(Type type, const std::string &src);

    void addVertexShader(const std::string &src);

    void addGeometryShader(const std::string &src);

    void addFragmentShader(const std::string &src);

    void linkShaders();

    int32_t getUniformLocation(const char *name) const;

    int32_t getAttribLocation(const char *name) const;

    [[nodiscard]] bool isValid() const { return program != 0; }
};

} // namespace Blob::GL

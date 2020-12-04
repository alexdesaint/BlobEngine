#pragma once

#include <string>
#include <unordered_map>

namespace Blob::GL {

class Material;

/// this program is created only once ans is used by multiple different materials
class Shader {
    friend Material;

public:
    unsigned int program = 0;

    unsigned int vertexShader = 0, fragmentShader = 0, geometryShader = 0;

    Shader() noexcept = default;
    Shader(const Shader &) = delete; /// Copy constructors
    // ShaderProgram(ShaderProgram &&shaderProgram) noexcept; /// Move constructors
    Shader(Shader &&shaderProgram) = delete; /// Move constructors

    void destroy() const;

    void addVertexShader(const std::string &src);

    void addGeometryShader(const std::string &src);

    void addFragmentShader(const std::string &src);

    void linkShaders();

    int32_t getUniformLocation(const char *name) const;

    int32_t getAttribLocation(const char *name) const;

    [[nodiscard]] bool isValid() const { return program != 0; }
};

} // namespace Blob::GL

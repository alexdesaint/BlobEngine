#pragma once

#include <string>
#include <unordered_map>

namespace Blob::GL {

class Core;

/// this program is created only once ans is used by multiple different materials
class ShaderProgram {
    friend Core;

private:
    unsigned int program = 0;

    unsigned int vertexShader = 0, fragmentShader = 0;

    bool linked = false;

    /// TODO: replace with a u_map
    //int model, view, projection, textureScale;

public:
    static std::unordered_map<std::string, ShaderProgram> Shaders;

    ShaderProgram();
    ShaderProgram(const std::string &pathVertex, const std::string &pathFragment);
    ShaderProgram(const ShaderProgram &) = delete; /// Copy constructors
    //ShaderProgram(ShaderProgram &&shaderProgram) noexcept; /// Move constructors
    ShaderProgram(ShaderProgram &&shaderProgram) = delete; /// Move constructors

    ~ShaderProgram();

    void addVertexShader(const std::string &src);

    void addVertexShaderFile(const std::string &path);

    void addFragmentShader(const std::string &src);

    void addFragmentShaderFile(const std::string &path);

    void linkShaders();

    [[nodiscard]] unsigned int getProgram() const;

    /// TODO: Set as private for the map creation
    uint32_t getUniformLocation(const char *name) const;

    uint32_t getAttribLocation(const char *name) const;

    [[nodiscard]] bool isValid() const { return linked; }
};

} // namespace Blob::GL

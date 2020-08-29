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
public:

    enum AttributeLocation {
        POSITION = 0,
        NORMAL = 1,
        TANGENT = 2,
        TEXCOORD_0 = 3,
        TEXCOORD_1 = 4,
        COLOR_0 = 5,
        JOINTS_0 = 6,
        WEIGHTS_0 = 7
    };

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

    uint32_t getUniformLocation(const char *name) const;

    uint32_t getAttribLocation(const char *name) const;

    [[nodiscard]] bool isValid() const { return linked; }
};

} // namespace Blob::GL

#pragma once

#include <string>
#include <unordered_map>
#include <vector>

namespace Blob::GL {

class ShaderProgram {
    friend class Shader;

public:
    typedef unsigned int Type;

    struct Types {
        static const Type Vertex;
        static const Type Tessellation;
        static const Type Evaluation;
        static const Type Geometry;
        static const Type Fragment;
        static const Type Compute;
    };

    unsigned int program = 0;
    std::unordered_map<Type, unsigned int> shaders;

    ShaderProgram() noexcept = default;
    ShaderProgram(const ShaderProgram &) = delete;
    ShaderProgram(ShaderProgram &&shaderProgram) = delete;
    void destroy();

    void addShader(Type type, const std::string &src);

    void addSpirV(Type type,
                  const std::vector<uint8_t> &src,
                  const std::string &entryPointName = "main");

    void addSpirV(Type type,
                  const std::vector<uint32_t> &src,
                  const std::string &entryPointName = "main");

    void linkShaders();

    int32_t getUniformLocation(const char *name) const;

    int32_t getAttribLocation(const char *name) const;

    bool isValid() const { return program != 0; }
};

} // namespace Blob::GL

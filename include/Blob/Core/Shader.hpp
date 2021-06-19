#pragma once

#include "Blob/Core/Shader.hpp"
#include <Blob/Core/Asset.hpp>
#include <Blob/Core/Texture.hpp>
#include <Blob/GL/Shader.hpp>
#include <Blob/GL/ShaderProgram.hpp>
#include <stddef.h>
#include <string>
#include <iostream>

namespace Blob::Core {

template<size_t N>
struct StringLiteral {
    constexpr StringLiteral(const char (&str)[N]) { std::copy_n(str, N, value); }

    static const size_t size = N;
    char value[N];
};

template<StringLiteral lit, GL::ShaderProgram::Type TYPE>
struct ShaderCode {
    static std::string getCode() { return std::string(lit.value); }
    inline static const GL::ShaderProgram::Type type = TYPE;
};

template<StringLiteral lit>
struct VertexShader {
    static std::string getCode() { return std::string(lit.value); }
    inline static const GL::ShaderProgram::Type type = GL::ShaderProgram::Types::Vertex;
};
template<StringLiteral lit>
struct TessellationControlShader {
    static std::string getCode() { return std::string(lit.value); }
    inline static const GL::ShaderProgram::Type type = GL::ShaderProgram::Types::TessellationControl;
};
template<StringLiteral lit>
struct EvaluationShader {
    static std::string getCode() { return std::string(lit.value); }
    inline static const GL::ShaderProgram::Type type = GL::ShaderProgram::Types::Evaluation;
};
template<StringLiteral lit>
struct GeometryShader {
    static std::string getCode() { return std::string(lit.value); }
    inline static const GL::ShaderProgram::Type type = GL::ShaderProgram::Types::Geometry;
};
template<StringLiteral lit>
struct FragmentShader {
    static std::string getCode() { return std::string(lit.value); }
    inline static const GL::ShaderProgram::Type type = GL::ShaderProgram::Types::Fragment;
};
template<StringLiteral lit>
struct ComputeShader {
    static std::string getCode() { return std::string(lit.value); }
    inline static const GL::ShaderProgram::Type type = GL::ShaderProgram::Types::Compute;
};

template<class... SHADER_CODE>
struct ShaderProgram : public GL::ShaderProgram {
    ShaderProgram() {
        (addShader(SHADER_CODE::type, SHADER_CODE::getCode()),...);
        linkShaders();
    }
};

template<class T, size_t POSITION>
class UniformAttribute {
public:
    using Type = T;
    static const size_t position = POSITION;
};

template<class SHADER_PROGRAM, class... UNIFORM_ATTRIBUTES>
class Shader : public GL::Shader, public Core::Asset<Shader<SHADER_PROGRAM, UNIFORM_ATTRIBUTES...>> {
private:
    friend Core::Asset<Shader<SHADER_PROGRAM, UNIFORM_ATTRIBUTES...>>;
    Shader() {}
    const SHADER_PROGRAM shaderProgram;

public:
    void setUniform(const Texture &texture, int position) const { 
        GL::Shader::setTexture(texture); 
    }

    using GL::Shader::setUniform;

    void setAttributes(const typename UNIFORM_ATTRIBUTES::Type &...UNIFORM_ATTRIBUTES_Type) {
        setShaderProgram(shaderProgram);
        (setUniform(UNIFORM_ATTRIBUTES_Type, UNIFORM_ATTRIBUTES::position), ...);
    }
};

} // namespace Blob::Core
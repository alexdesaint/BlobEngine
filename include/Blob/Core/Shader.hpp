#pragma once

#include "Blob/Core/Shader.hpp"
#include <Blob/Core/Asset.hpp>
#include <Blob/Core/Texture.hpp>
#include <Blob/GL/Shader.hpp>
#include <Blob/GL/ShaderProgram.hpp>
#include <iostream>
#include <iterator>
#include <stddef.h>
#include <string>

namespace Blob {

template<size_t N>
struct GlslCode {
    constexpr GlslCode(const char (&str)[N]) { std::copy_n(str, N, value); }

    static const size_t size = N;
    char value[N];
};

template<size_t N>
struct EntryName {
    constexpr EntryName(const char (&str)[N]) { std::copy_n(str, N, value); }

    static const size_t size = N;
    char value[N];
};

template<size_t N>
struct SpirVCode {
    constexpr SpirVCode(const uint32_t (&data)[N]) {
        std::copy_n(data, N, value);
    }

    static const size_t size = N;
    uint32_t value[N];
};

template<GL::ShaderProgram::Type TYPE, GlslCode... lit>
struct ShaderCode {
    static std::string getCode() {
        std::string ret;
        ((ret += std::string(lit.value)), ...);
        return ret;
    }

    static const GL::ShaderProgram::Type type = TYPE;
};

template<GL::ShaderProgram::Type TYPE, SpirVCode spirVCode, EntryName entryName>
struct ShaderCodeSpirV {
    static std::vector<uint32_t> getCode() {
        return {std::begin(spirVCode.value), std::end(spirVCode.value)};
    }

    static std::string getEntryName() { return {entryName.value}; }

    static const GL::ShaderProgram::Type type = TYPE;
};

template<GlslCode... lit>
struct VertexShader {
    static std::string getCode() {
        std::string ret;
        ((ret += std::string(lit.value)), ...);
        return ret;
    }

    inline static const auto type = GL::ShaderProgram::Types::Vertex;
};

template<SpirVCode spirVCode, EntryName entryName>
struct VertexShaderSpirV {
    static std::vector<uint32_t> getCode() {
        return {std::begin(spirVCode.value), std::end(spirVCode.value)};
    }

    static std::string getEntryName() { return {entryName.value}; }

    inline static const auto type = GL::ShaderProgram::Types::Vertex;
};

template<GlslCode... lit>
struct TessellationShader {
    static std::string getCode() {
        std::string ret;
        ((ret += std::string(lit.value)), ...);
        return ret;
    }

    inline static const auto type = GL::ShaderProgram::Types::Tessellation;
};

template<SpirVCode spirVCode, EntryName entryName>
struct TessellationShaderSpirV {
    static std::vector<uint32_t> getCode() {
        return {std::begin(spirVCode.value), std::end(spirVCode.value)};
    }

    static std::string getEntryName() { return {entryName.value}; }

    inline static const auto type = GL::ShaderProgram::Types::Tessellation;
};

template<GlslCode... lit>
struct EvaluationShader {
    static std::string getCode() {
        std::string ret;
        ((ret += std::string(lit.value)), ...);
        return ret;
    }

    inline static const auto type = GL::ShaderProgram::Types::Evaluation;
};

template<SpirVCode spirVCode, EntryName entryName>
struct EvaluationShaderSpirV {
    static std::vector<uint32_t> getCode() {
        return {std::begin(spirVCode.value), std::end(spirVCode.value)};
    }

    static std::string getEntryName() { return {entryName.value}; }

    inline static const auto type = GL::ShaderProgram::Types::Evaluation;
};

template<GlslCode... lit>
struct GeometryShader {
    static std::string getCode() {
        std::string ret;
        ((ret += std::string(lit.value)), ...);
        return ret;
    }

    inline static const auto type = GL::ShaderProgram::Types::Geometry;
};

template<SpirVCode spirVCode, EntryName entryName>
struct GeometryShaderSpirV {
    static std::vector<uint32_t> getCode() {
        return {std::begin(spirVCode.value), std::end(spirVCode.value)};
    }

    static std::string getEntryName() { return {entryName.value}; }

    inline static const auto type = GL::ShaderProgram::Types::Geometry;
};

template<GlslCode... lit>
struct FragmentShader {
    static std::string getCode() {
        std::string ret;
        ((ret += std::string(lit.value)), ...);
        return ret;
    }

    inline static const auto type = GL::ShaderProgram::Types::Fragment;
};

template<SpirVCode spirVCode, EntryName entryName>
struct FragmentShaderSpirV {
    static std::vector<uint32_t> getCode() {
        return {std::begin(spirVCode.value), std::end(spirVCode.value)};
    }

    static std::string getEntryName() { return {entryName.value}; }

    inline static const auto type = GL::ShaderProgram::Types::Fragment;
};

template<GlslCode... lit>
struct ComputeShader {
    static std::string getCode() {
        std::string ret;
        ((ret += std::string(lit.value)), ...);
        return ret;
    }

    inline static const auto type = GL::ShaderProgram::Types::Compute;
};

template<SpirVCode spirVCode, EntryName entryName>
struct ComputeShaderSpirV {
    static std::vector<uint32_t> getCode() {
        return {std::begin(spirVCode.value), std::end(spirVCode.value)};
    }

    static std::string getEntryName() { return {entryName.value}; }

    inline static const auto type = GL::ShaderProgram::Types::Compute;
};

template<class... SHADER_CODE>
struct ShaderProgram : public GL::ShaderProgram {
    ShaderProgram() {
        (addShader(SHADER_CODE::type, SHADER_CODE::getCode()), ...);
        linkShaders();
    }
};

template<class... SHADER_CODE>
struct ShaderProgramSpirV : public GL::ShaderProgram {
    ShaderProgramSpirV() {
        (addSpirV(SHADER_CODE::type,
                  SHADER_CODE::getCode(),
                  SHADER_CODE::getEntryName()),
         ...);
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
class Shader :
    public GL::Shader,
    public Asset<Shader<SHADER_PROGRAM, UNIFORM_ATTRIBUTES...>> {
private:
    friend Asset<Shader<SHADER_PROGRAM, UNIFORM_ATTRIBUTES...>>;
    Shader() {}

public:
    const SHADER_PROGRAM shaderProgram;

    void setUniform(const Texture &texture, int position) const {
        GL::Shader::setTexture(texture);
    }

    using GL::Shader::setUniform;

    void setAttributes(
        const typename UNIFORM_ATTRIBUTES::Type &...UNIFORM_ATTRIBUTES_Type) {
        setShaderProgram(shaderProgram);
        (setUniform(UNIFORM_ATTRIBUTES_Type, UNIFORM_ATTRIBUTES::position),
         ...);
    }
};

} // namespace Blob
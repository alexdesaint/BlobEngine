#pragma once

#include <Blob/Buffer.hpp>
#include <Blob/Exception.hpp>
#include <Blob/Shader.hpp>
#include <Blob/Texture.hpp>
#include <bgfx/bgfx.h>
#include <iostream>
#include <iterator>
#include <stddef.h>
#include <string>

namespace Blob {

enum UniformType {
    UniformVec4 = bgfx::UniformType::Vec4,
    UniformMat3 = bgfx::UniformType::Mat3,
    UniformMat4 = bgfx::UniformType::Mat4
};

class Uniform {
private:
public:
    Uniform(const std::string &name, UniformType uniformType) {
        uniformHandle = bgfx::createUniform(name.c_str(), (bgfx::UniformType::Enum) uniformType);
    }

    bgfx::UniformHandle uniformHandle;
    ~Uniform() { bgfx::destroy(uniformHandle); }
};

class UniformSampler {
private:
public:
    UniformSampler(const std::string &name) {
        uniformHandle = bgfx::createUniform(name.c_str(), bgfx::UniformType::Sampler);
    }

    bgfx::UniformHandle uniformHandle;
    ~UniformSampler() { bgfx::destroy(uniformHandle); }
};

class Shader {
private:
    bgfx::ShaderHandle vsh;
    bgfx::ShaderHandle fsh;

public:
    bgfx::ProgramHandle shaderHandle;

    Shader(const Buffer &vertex, const Buffer &fragment) {
        vsh = bgfx::createShader(vertex.memory);
        fsh = bgfx::createShader(fragment.memory);

        shaderHandle = bgfx::createProgram(vsh, fsh, true);

        if (!bgfx::isValid(shaderHandle))
            throw Exception("involid shader");
    }

    ~Shader() { bgfx::destroy(shaderHandle); }
};

} // namespace Blob

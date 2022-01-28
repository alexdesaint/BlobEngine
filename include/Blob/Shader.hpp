#pragma once

#include <Blob/Asset.hpp>
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

template<class T, size_t POSITION>
class UniformAttribute {
public:
    using Type = T;
    static const size_t position = POSITION;
};

template<class... UNIFORM_ATTRIBUTES>
class Shader : public Asset<Shader<UNIFORM_ATTRIBUTES...>> {
private:
    friend Asset<Shader<UNIFORM_ATTRIBUTES...>>;

    Shader(const Buffer &vertex, const Buffer &fragment) {
        vsh = bgfx::createShader(vertex.memory);
        fsh = bgfx::createShader(fragment.memory);

        shaderHandle = bgfx::createProgram(vsh, fsh, true);

        if (!bgfx::isValid(shaderHandle))
            throw Exception("involid shader");
    }

public:
    bgfx::ProgramHandle shaderHandle;
    bgfx::ShaderHandle vsh;
    bgfx::ShaderHandle fsh;

    ~Shader() { bgfx::destroy(shaderHandle); }

    void setUniform(const Texture &texture, int position) const {
        // GL::Shader::setTexture(texture);
    }

    void setAttributes(
        const typename UNIFORM_ATTRIBUTES::Type &...UNIFORM_ATTRIBUTES_Type) {
        // setShaderProgram(shaderProgram);
        //(setUniform(UNIFORM_ATTRIBUTES_Type, UNIFORM_ATTRIBUTES::position),
        //  ...);
    }
};

} // namespace Blob

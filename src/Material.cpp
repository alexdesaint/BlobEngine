#include <Blob/Material.hpp>
#include <Blob/Exception.hpp>

namespace Blob{

Material::Material(const GL::ShaderProgram &shaderProgram) : shaderProgram(shaderProgram) {
    if(!shaderProgram.isValid())
        throw Exception("Invalid shader");
}

}
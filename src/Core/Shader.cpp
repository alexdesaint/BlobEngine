#include <Blob/Core/Shader.hpp>
#include <Blob/Reader/FileReader.hpp>

namespace Blob::Core {

void Shader::addFragmentShaderFile(const std::string &path) {
    Reader::FileReader f(path);
    addFragmentShader(f.toString());
}

void Shader::addVertexShaderFile(const std::string &path) {
    Reader::FileReader f(path);
    addVertexShader(f.toString());
}
} // namespace Blob::Core
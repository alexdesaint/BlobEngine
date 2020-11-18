#pragma once

#include <Blob/GL/Shader.hpp>

namespace Blob::Core {

class Shader : public GL::Shader {
    friend class Window;
public:
    enum AttributeLocation { POSITION = 0, NORMAL = 1, TANGENT = 2, TEXCOORD_0 = 3, TEXCOORD_1 = 4, COLOR_0 = 5, JOINTS_0 = 6, WEIGHTS_0 = 7 };

    void addVertexShaderFile(const std::string &path);

    void addFragmentShaderFile(const std::string &path);
};

} // namespace Blob::Core
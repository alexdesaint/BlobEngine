#pragma once

#include <string>
#include <vector>

#include <Blob/GL/ShaderProgram.hpp>
#include <Blob/GL/VertexArrayObject.hpp>
#include <Blob/Material.hpp>

#include <Blob/RenderOptions.hpp>

namespace Blob {

class Mesh {
    friend class Window;
private:
    const Material &material;

    const GL::VertexArrayObject &vertexArrayObject;

public:
    RenderOptions renderOptions;

    Mesh ( const Mesh & mesh);
    Mesh ( Mesh && ) = delete;
    Mesh(GL::VertexArrayObject &vertexArrayObject, const Material &material);

    void setIndices(unsigned short *indices, int32_t numOfIndices, uint32_t indicesType);
};
} // namespace Blob

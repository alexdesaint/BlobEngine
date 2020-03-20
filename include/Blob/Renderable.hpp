#pragma once

#include <string>
#include <vector>

#include <Blob/GL/ShaderProgram.hpp>
#include <Blob/GL/VertexArrayObject.hpp>
#include <Blob/Material.hpp>

#include <Blob/RenderOptions.hpp>

namespace Blob {

class Renderable : public ModelTransform { // TODO: rename as "Mesh", make fully a pubic object
    friend class Window;

private:
    const Material &material;

    GL::VertexArrayObject &vertexArrayObject;

public:
    RenderOptions renderOptions;

    Renderable(GL::VertexArrayObject &vertexArrayObject, const Material &material);

    void setVertexArrayObject(GL::VertexArrayObject &vertexArrayObject);

    void setIndices(unsigned short *indices, int32_t numOfIndices, uint32_t indicesType);
};
} // namespace Blob

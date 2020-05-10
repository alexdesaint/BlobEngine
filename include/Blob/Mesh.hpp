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
    Material const *material = DefaultMaterial::defaultMaterial;
    GL::VertexArrayObject &vertexArrayObject;

public:
    RenderOptions renderOptions;

    explicit Mesh(GL::VertexArrayObject &vertexArrayObject);
    Mesh(GL::VertexArrayObject &vertexArrayObject, const Material &material);

    void setIndices(void *indices, int32_t numOfIndices, uint32_t indicesType);

    template<typename T>
    void setIndices(T *indices, int32_t numOfIndices);

    void setMaterial(Material &material);
};

template<> void Mesh::setIndices<>(uint8_t *indices, int32_t numOfIndices);
template<> void Mesh::setIndices<>(uint16_t *indices, int32_t numOfIndices);
template<> void Mesh::setIndices<>(uint32_t *indices, int32_t numOfIndices);

} // namespace Blob

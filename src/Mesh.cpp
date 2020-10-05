#include <Blob/Mesh.hpp>
#include <Blob/GL/Core.hpp>
using namespace std;

namespace Blob::Core {

//using namespace GL;

Mesh::Mesh(GL::VertexArrayObject &vertexArrayObject) : vertexArrayObject(vertexArrayObject) {}

Mesh::Mesh(GL::VertexArrayObject &vertexArrayObject, const Material::Material &material) : material(&material), vertexArrayObject(vertexArrayObject) {}

void Mesh::setIndices(void *i, int32_t noi, uint32_t it) {
    renderOptions.indices = i;
    renderOptions.indicesType = it;
    renderOptions.numOfIndices = noi;

    renderOptions.indexed = true;
}

template<> void Mesh::setIndices<>(uint8_t *indices, int32_t numOfIndices) {
    setIndices(indices, numOfIndices, GL::Core::getType<uint8_t>());
}

template<> void Mesh::setIndices<>(uint16_t *indices, int32_t numOfIndices) {
    setIndices(indices, numOfIndices, GL::Core::getType<uint16_t>());
}

template<> void Mesh::setIndices<>(uint32_t *indices, int32_t numOfIndices) {
    setIndices(indices, numOfIndices, GL::Core::getType<uint32_t>());
}

void Mesh::setMaterial(Material::Material &material) {
    Mesh::material = &material;
}
} // namespace Blob

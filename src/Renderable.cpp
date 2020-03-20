#include <Blob/Renderable.hpp>

#include <Blob/Exception.hpp>
#include <Blob/Reader/FileReader.hpp>

#include <glad/glad.h>

using namespace std;

namespace Blob {

using namespace GL;

Renderable::Renderable(VertexArrayObject &vertexArrayObject, const Material &material) : vertexArrayObject(vertexArrayObject), material(material) {}

void Renderable::setVertexArrayObject(VertexArrayObject &vertexArrayObject) {
    Renderable::vertexArrayObject = vertexArrayObject;
}

void Renderable::setIndices(unsigned short *i, int32_t noi, uint32_t it) {
    renderOptions.indices = i;
    renderOptions.indicesType = it;
    renderOptions.numOfIndices = noi;

    renderOptions.indexed = true;
}
} // namespace Blob

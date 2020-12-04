#include <Blob/Core/Primitive.hpp>

namespace Blob::Core {

void Primitive::setMaterial(const Material *material) {
    Primitive::material = material;
}

void Primitive::setVertexArrayObject(const GL::VertexArrayObject *vertexArrayObject) {
    Primitive::vertexArrayObject = vertexArrayObject;
}

void Primitive::setRenderOptions(const RenderOptions *renderOptions) {
    Primitive::renderOptions = renderOptions;
}
}
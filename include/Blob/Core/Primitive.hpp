#pragma once

#include <Blob/Core/Material.hpp>
#include <Blob/Core/RenderOptions.hpp>
#include <Blob/GL/VertexArrayObject.hpp>

namespace Blob::Core {

class Primitive {
    friend class Window;
private:
    const Material &material;
    const GL::VertexArrayObject &vertexArrayObject;
    const RenderOptions &renderOptions;

public:
    Primitive(const GL::VertexArrayObject &vertexArrayObject, const Material &material, const RenderOptions &renderOptions) : material(material), vertexArrayObject(vertexArrayObject), renderOptions(renderOptions) {}
};

} // namespace Blob::Core
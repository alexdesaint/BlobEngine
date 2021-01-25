#pragma once

#include <Blob/Core/Material.hpp>
#include <Blob/Core/RenderOptions.hpp>
#include <Blob/GL/VertexArrayObject.hpp>

namespace Blob::Core {

class Primitive {
    friend class Window;

private:
    const Material *material = nullptr;
    const GL::VertexArrayObject *vertexArrayObject = nullptr;
    const RenderOptions *renderOptions = nullptr;

public:
    Primitive(const GL::VertexArrayObject *vertexArrayObject, const Material *material, const RenderOptions *renderOptions) :
        material(material), vertexArrayObject(vertexArrayObject), renderOptions(renderOptions) {}
    Primitive() = delete;
    Primitive(const Primitive &) = delete;
    Primitive(Primitive &&) = delete;

    void setMaterial(const Material *material);
    void setVertexArrayObject(const GL::VertexArrayObject *vertexArrayObject);
    void setRenderOptions(const RenderOptions *renderOptions);
};

} // namespace Blob::Core
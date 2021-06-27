#pragma once

#include <Blob/Core/Material.hpp>
#include <Blob/Core/RenderOptions.hpp>
#include <Blob/GL/VertexArrayObject.hpp>

namespace Blob::Core {

class Primitive {
    friend class Window;

private:
public:
    Material *material = nullptr;
    GL::VertexArrayObject *vertexArrayObject = nullptr;
    RenderOptions *renderOptions = nullptr;

    Primitive() = default;
    Primitive(GL::VertexArrayObject *vertexArrayObject, Material *material, RenderOptions *renderOptions) :
        material(material), vertexArrayObject(vertexArrayObject), renderOptions(renderOptions) {}
    Primitive(const Primitive &) = default;
    Primitive(Primitive &&) = delete;

    void setMaterial(Material *material) { Primitive::material = material; }

    void setVertexArrayObject(GL::VertexArrayObject *vertexArrayObject) { Primitive::vertexArrayObject = vertexArrayObject; }

    void setRenderOptions(RenderOptions *renderOptions) { Primitive::renderOptions = renderOptions; }
};

class Primitive2D {
    friend class Window;

private:
    const Material2D *material = nullptr;
    const GL::VertexArrayObject *vertexArrayObject = nullptr;
    const RenderOptions *renderOptions = nullptr;

public:
    Primitive2D(const GL::VertexArrayObject *vertexArrayObject, const Material2D *material, const RenderOptions *renderOptions) :
        material(material), vertexArrayObject(vertexArrayObject), renderOptions(renderOptions) {}
    Primitive2D() = delete;
    Primitive2D(const Primitive2D &) = delete;
    Primitive2D(Primitive2D &&) = delete;

    void setMaterial(const Material2D *material) { Primitive2D::material = material; }

    void setVertexArrayObject(const GL::VertexArrayObject *vertexArrayObject) { Primitive2D::vertexArrayObject = vertexArrayObject; }

    void setRenderOptions(const RenderOptions *renderOptions) { Primitive2D::renderOptions = renderOptions; }
};

} // namespace Blob::Core
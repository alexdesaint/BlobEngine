#pragma once

#include <Blob/Core/Material.hpp>
#include <Blob/Core/RenderOptions.hpp>
#include <Blob/GL/VertexArrayObject.hpp>

namespace Blob {

struct Primitive {
    const Material *material = nullptr;
    GL::VertexArrayObject *vertexArrayObject = nullptr;
    RenderOptions *renderOptions = nullptr;

    Primitive() = default;
    Primitive(const Primitive &) = delete;
    Primitive(Primitive &&) = delete;
    Primitive(GL::VertexArrayObject *vertexArrayObject,
              const Material *material,
              RenderOptions *renderOptions) :
        material(material),
        vertexArrayObject(vertexArrayObject),
        renderOptions(renderOptions) {}
};

struct Primitive2D {
    const Material2D *material = nullptr;
    GL::VertexArrayObject *vertexArrayObject = nullptr;
    RenderOptions *renderOptions = nullptr;

    Primitive2D() = default;
    Primitive2D(const Primitive2D &) = delete;
    Primitive2D(Primitive2D &&) = delete;
    Primitive2D(GL::VertexArrayObject *vertexArrayObject,
                const Material2D *material,
                RenderOptions *renderOptions) :
        material(material),
        vertexArrayObject(vertexArrayObject),
        renderOptions(renderOptions) {}
};

} // namespace Blob
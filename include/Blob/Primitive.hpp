#pragma once

#include <Blob/Material.hpp>
#include <Blob/RenderOptions.hpp>
#include <Blob/VertexBuffer.hpp>

namespace Blob {

struct Primitive {
    const Material *material = nullptr;
    VertexBuffer *vertexBuffer = nullptr;
    RenderOptions *renderOptions = nullptr;

    Primitive() = default;
    Primitive(const Primitive &) = delete;
    Primitive(Primitive &&) = delete;
    Primitive(VertexBuffer *vertexBuffer,
              const Material *material,
              RenderOptions *renderOptions) :
        material(material),
        vertexBuffer(vertexBuffer),
        renderOptions(renderOptions) {}
};

} // namespace Blob

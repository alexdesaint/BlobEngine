#pragma once

#include <Blob/Material.hpp>
#include <Blob/RenderOptions.hpp>
#include <Blob/VertexBuffer.hpp>
#include <memory>

namespace Blob {

struct Primitive {
    std::unique_ptr<Material> material;
    VertexBuffer *vertexBuffer = nullptr;
    RenderOptions *renderOptions = nullptr;

    Primitive() = default;
    Primitive(const Primitive &) = delete;
    Primitive(Primitive &&) = delete;
};

} // namespace Blob

#pragma once

#include <Blob/Material.hpp>
#include <Blob/RenderOptions.hpp>
#include <Blob/VertexBuffer.hpp>
#include <memory>

namespace Blob {

struct Mesh {
    struct Primitive {
        Material material;
        VertexBuffer *vertexBuffer;
        RenderOptions *renderOptions;

        Primitive() = delete;
        Primitive(const Primitive &) = default;
        Primitive(Primitive &&) = default;
        Primitive(Material &&material, VertexBuffer *vertexBuffer, RenderOptions *renderOptions) :
            material(std::move(material)),
            vertexBuffer(vertexBuffer),
            renderOptions(renderOptions) {}
    };

    std::vector<Primitive> primitives;
    std::vector<Primitive> transparentPrimitives;

    Mesh() = default;
    Mesh(const Mesh &) = default;
    Mesh(Mesh &&) = default;
    Mesh(Material &&material, VertexBuffer *vertexBuffer, RenderOptions *renderOptions) :
        primitives({Primitive{std::move(material), vertexBuffer, renderOptions}}) {}
    explicit Mesh(std::vector<Primitive> &&primitives,
                  std::vector<Primitive> &&transparentPrimitives = {}) :
        primitives(std::move(primitives)),
        transparentPrimitives(std::move(transparentPrimitives)) {}

    friend std::ostream &operator<<(std::ostream &s, const Mesh &a) {
        s << "Mesh {" << std::endl;
        s << "    primitive size" << a.primitives.size() << std::endl;
        s << "    transparent primitives size" << a.transparentPrimitives.size() << std::endl;
        s << "}";
        return s;
    }

    Mesh &operator=(const Mesh &) = default;
    Mesh &operator=(Mesh &&) = default;
};

} // namespace Blob

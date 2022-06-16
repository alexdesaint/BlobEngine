#pragma once

#include <Blob/Mesh.hpp>
#include <list>

namespace Blob {

struct Shape : public ModelTransform {
    std::optional<Mesh> mesh;
    std::vector<Shape> shapes;

    Shape() = default;
    Shape(const Shape &) = default;
    Shape(Shape &&) = default;
    Shape(std::vector<Shape> &&shapes, ModelTransform &&modelTransform = {});
    Shape(Mesh &&r, std::vector<Shape> &&shapes = {}, ModelTransform &&modelTransform = {});

    friend std::ostream &operator<<(std::ostream &s, const Shape &a);
};

} // namespace Blob

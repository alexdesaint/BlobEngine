#include <Blob/Shape.hpp>
#include <algorithm>

namespace Blob {

Shape::Shape(std::vector<Shape> &&shapes, ModelTransform &&modelTransform) :
    shapes(std::move(shapes)), ModelTransform(modelTransform) {}

Shape::Shape(Mesh &&mesh, std::vector<Shape> &&shapes, ModelTransform &&modelTransform) :
    mesh(std::move(mesh)), shapes(std::move(shapes)), ModelTransform(modelTransform) {}

std::ostream &operator<<(std::ostream &s, const Shape &a) {
    s << "Shape : {" << std::endl;

    s << (ModelTransform) a;

    if (a.mesh.has_value())
        s << *a.mesh << std::endl;

    // for (const auto &r : a.shapes)
    //    s << *r;

    s << "}";
    return s;
}

} // namespace Blob

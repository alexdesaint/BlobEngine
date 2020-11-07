#include <Blob/Geometry/Forms.hpp>

namespace Blob::Geometry {

bool Point::overlap(const Rectangle &rectangle) const {
    auto diff = rectangle.size / 2;

    return (rectangle.position.x + diff.x <= x) &&
           (rectangle.position.x - diff.x >= x) &&
           (rectangle.position.y + diff.y <= y) &&
           (rectangle.position.y - diff.y >= y);
}

bool Point::overlap(const Circle &circle) const {
    return operator-(circle.position).length2() <= circle.rayon * circle.rayon;
}

} // namespace Blob::Maths
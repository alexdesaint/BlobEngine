#include <Blob/Collision/Forms.hpp>

namespace Blob {

bool Point::overlap(const Rectangle &rectangle) const {
    auto diff = rectangle.size / 2;

    return (rectangle.position.x - diff.x <= x) &&
           (rectangle.position.x + diff.x >= x) &&
           (rectangle.position.y - diff.y <= y) &&
           (rectangle.position.y + diff.y >= y);
}

bool Point::overlap(const Circle &circle) const {
    return operator-(circle.position).length2() <= circle.rayon * circle.rayon;
}

bool Point::overlap(const Polygon &polygon) const {
    return polygon.overlap(*this);
}

std::unordered_set<Vec2<int32_t>> Point::rasterize() const {
    std::unordered_set<Vec2<int32_t>> points;
    points.emplace(cast<int32_t>());
    return points;
}

} // namespace Blob

#include <Blob/Geometry/Forms.hpp>

namespace Blob::Geometry {
bool Rectangle::overlapBigger(const Rectangle &r) const {

    float xdiff = size.x / 2;
    float ydiff = size.y / 2;
    float rxdiff = r.size.x / 2;
    float rydiff = r.size.y / 2;

    return ((position.x - xdiff <= r.position.x + rxdiff) && (position.x - xdiff >= r.position.x - rxdiff) &&
            (position.y - ydiff <= r.position.y + rydiff) && (position.y - ydiff >= r.position.y - rydiff)) ||
           ((position.x + xdiff <= r.position.x + rxdiff) && (position.x + xdiff >= r.position.x - rxdiff) &&
            (position.y - ydiff <= r.position.y + rydiff) && (position.y - ydiff >= r.position.y - rydiff)) ||
           ((position.x - xdiff <= r.position.x + rxdiff) && (position.x - xdiff >= r.position.x - rxdiff) &&
            (position.y + ydiff <= r.position.y + rydiff) && (position.y + ydiff >= r.position.y - rydiff)) ||
           ((position.x + xdiff <= r.position.x + rxdiff) && (position.x + xdiff >= r.position.x - rxdiff) &&
            (position.y + ydiff <= r.position.y + rydiff) && (position.y + ydiff >= r.position.y - rydiff));
}

std::list<Maths::Vec2<int32_t>> Rectangle::rasterize() const {
    std::list<Maths::Vec2<int32_t>> points;
    auto startx = (int64_t) (position.x - size.x / 2);
    auto endx = (int64_t) (position.x + size.x / 2);
    auto starty = (int64_t) (position.y - size.y / 2);
    auto endy = (int64_t) (position.y + size.y / 2);

    for (int i = startx; i <= endx; i++) {
        for (int j = starty; j <= endy; j++)
            points.emplace_back(i, j);
    }

    return points;
}

std::array<Maths::Vec2<>, 4> Rectangle::getPoints() const {
    return {position + size / 2.0, position - size / 2, position + size.rotate() / 2, position - size.rotate() / 2};
}

bool Rectangle::overlap(const Rectangle &rectangle) const {
    return rectangle.overlapBigger(*this) || overlapBigger(rectangle);
}

bool Rectangle::overlap(const Circle &circle) const {
    return circle.overlap(*this);
}

bool Rectangle::overlap(const Line &line) const {
    return line.overlap(*this);
}

bool Rectangle::overlap(const Point &point) const {
    return point.overlap(*this);
}

} // namespace Blob::Maths

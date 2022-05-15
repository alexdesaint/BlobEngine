#include <Blob/Collision/Forms.hpp>
#include <cmath>

namespace Blob {

Polygon::Polygon(std::vector<Point> &&points) : points(points) {}
Polygon::Polygon(const std::vector<Point> &points) : points(points) {}

bool Polygon::overlap(const Rectangle &rectangle) const {
    return true;
}

bool Polygon::overlap(const Circle &circle) const {
    return true;
}

bool Polygon::overlap(const Line &line) const {
    return true;
}

bool Polygon::overlap(const Point &point) const {
    bool collision = false;

    size_t next = 0;
    for (size_t current = 0; current < points.size(); current++) {
        next = current == points.size() - 1 ? current + 1 : 0;

        auto vc = points[current], vn = points[next];

        if (((vc.y >= point.y && vn.y < point.y) ||
             (vc.y < point.y && vn.y >= point.y)) &&
            (point.x < (vn.x - vc.x) * (point.y - vc.y) / (vn.y - vc.y) + vc.x))
            collision = !collision;
    }
    return collision;
}

bool Polygon::overlap(const Polygon &polygon) const {
    return true;
}

std::unordered_set<Vec2<int32_t>> Polygon::rasterize() const {
    if (points.empty())
        return {};
    if (points.size() == 1)
        return {points.front().cast<int>()};

    std::unordered_set<Vec2<int32_t>> ret;

    Vec2<> min = points.front(), max = points.front();

    for (const auto &point : points) {
        if (point.x < min.x)
            min.x = point.x;
        if (point.x > max.x)
            max.x = point.x;
        if (point.y < min.y)
            min.y = point.y;
        if (point.y > max.y)
            max.y = point.y;
    }

    for (int x = std::floor(min.x); x <= std::ceil(max.x); x++)
        for (int y = std::floor(min.y); y <= std::ceil(max.y); y++)
            ret.emplace(x, y);

    return ret;
}

std::ostream &operator<<(std::ostream &os, const Polygon &p) {
    os << "Polygon: {";
    for (const auto point : p.points)
        os << (Vec2<>) point;
    return os << "}";
}
} // namespace Blob

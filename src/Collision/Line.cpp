#include <Blob/Collision/Forms.hpp>

#include <cmath>

namespace Blob {

Point Line::closestPointTo(Point point) const {
    double A1 = positionB.y - positionA.y;
    double B1 = positionA.x - positionB.x;

    double C1 = A1 * positionA.x + B1 * positionA.y;
    double C2 = -B1 * point.x + A1 * point.y;

    double det = A1 * A1 - -B1 * B1;

    if (det != 0) {
        return {static_cast<float>((A1 * C1 - B1 * C2) / det),
                static_cast<float>((A1 * C2 - -B1 * C1) / det)};
    } else {
        return point;
    }
}

Point Line::getIntersectionPoint(Line B) const {
    double A1 = positionA.x - positionB.x;

    double B1 = B.positionA.x - B.positionB.x;

    double A2 = positionA.y - positionB.y;

    double B2 = B.positionA.y - B.positionB.y;

    double det = A1 * B2 - A2 * B1;

    if (det == 0)
        return {};

    double C1 = positionB.y * positionA.x - positionB.x * positionA.y;

    double C2 = B.positionB.y * B.positionA.x - B.positionB.x * B.positionA.y;

    return {static_cast<float>((C1 * B1 - A1 * C2) / det),
            static_cast<float>((C1 * B2 - A2 * C2) / det)};
}

bool Line::overlap(const Rectangle &rectangle) const {
    Point p1{rectangle.position.operator+
             ({rectangle.size.x / 2, rectangle.size.y / 2})};
    Point p2{rectangle.position.operator+
             ({-rectangle.size.x / 2, rectangle.size.y / 2})};
    Point p3{rectangle.position.operator+
             ({-rectangle.size.x / 2, -rectangle.size.y / 2})};
    Point p4{rectangle.position.operator+
             ({rectangle.size.x / 2, -rectangle.size.y / 2})};

    if (rectangle.overlap(positionA) || rectangle.overlap(positionB) ||
        overlap(Line(p1, p2)) || overlap(Line(p2, p3)) ||
        overlap(Line(p3, p4)) || overlap(Line(p4, p1)))
        return true;
    return false;
}

bool Line::overlap(const Circle &circle) const {
    return circle.overlap(*this);
}

bool Line::overlap(const Line &line) const {
    auto x1 = positionA.x;
    auto y1 = positionA.y;
    auto x2 = positionB.x;
    auto y2 = positionB.y;
    auto x3 = line.positionA.x;
    auto y3 = line.positionA.y;
    auto x4 = line.positionB.x;
    auto y4 = line.positionB.y;

    // calculate the distance to intersection point
    float uA = ((x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3)) /
               ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));
    float uB = ((x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3)) /
               ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));

    if (uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1)
        return true;
    return false;
}

bool Line::overlap(const Point &point) const {
    return false;
}

std::unordered_set<Vec2<int32_t>> Line::rasterize() const {
    std::unordered_set<Vec2<int32_t>> points;
    int64_t startx, endx, starty, endy;
    if (positionA.x < positionB.x) {
        startx = (int64_t) (positionA.x);
        endx = (int64_t) (positionB.x);
    } else {
        startx = (int64_t) (positionB.x);
        endx = (int64_t) (positionA.x);
    }
    if (positionA.y < positionB.y) {
        starty = (int64_t) (positionA.y);
        endy = (int64_t) (positionB.y);
    } else {
        starty = (int64_t) (positionB.y);
        endy = (int64_t) (positionA.y);
    }

    for (int i = startx; i <= endx; i++)
        for (int j = starty; j <= endy; j++)
            points.emplace(Vec2{i, j});

    return points;
}

} // namespace Blob

#include <Blob/Geometry/Forms.hpp>

#include <cmath>

namespace Blob::Geometry {

Point Line::closestPointTo(Point point) const {
    Point pointB{position + vector};

    double A1 = pointB.y - position.y;
    double B1 = position.x - pointB.x;

    double C1 = A1 * position.x + B1 * position.y;
    double C2 = -B1 * point.x + A1 * point.y;

    double det = A1 * A1 - -B1 * B1;

    if (det != 0) {
        return {static_cast<float>((A1 * C1 - B1 * C2) / det), static_cast<float>((A1 * C2 - -B1 * C1) / det)};
    } else {
        return point;
    }
}

Point Line::getIntersectionPoint(Line B) const {
    Point pointB{position + vector};
    Point BpointB{B.position + B.vector};

    double A1 = position.x - pointB.x;

    double B1 = B.position.x - BpointB.x;

    double A2 = position.y - pointB.y;

    double B2 = B.position.y - BpointB.y;

    double det = A1 * B2 - A2 * B1;

    if (det == 0)
        return {};

    double C1 = pointB.y * position.x - pointB.x * position.y;

    double C2 = BpointB.y * B.position.x - BpointB.x * B.position.y;

    return {static_cast<float>((C1 * B1 - A1 * C2) / det), static_cast<float>((C1 * B2 - A2 * C2) / det)};
}

bool Line::overlap(const Rectangle &rectangle) const {
    return false;
}

bool Line::overlap(const Circle &circle) const {
    return circle.overlap(*this);
}

bool Line::overlap(const Line &line) const {
    return false;
}

bool Line::overlap(const Point &point) const {
    return false;
}
} // namespace Blob
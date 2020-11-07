#include <Blob/Geometry/Forms.hpp>

namespace Blob::Geometry {

bool Circle::overlap(const Rectangle &rectangle) const {
    auto rx = rectangle.position.x - rectangle.size.x / 2.f;
    auto ry = rectangle.position.y - rectangle.size.y / 2.f;
    auto rw = rectangle.position.x + rectangle.size.x / 2.f;
    auto rh = rectangle.position.y + rectangle.size.y / 2.f;

    auto test = position;

    if (position.x < rx)
        test.x = rx;
    else if (position.x > rw)
        test.x = rw;

    if (position.y < ry)
        test.y = ry;
    else if (position.y > rh)
        test.y = rh;

    return (position - test).length2() <= rayon * rayon;
}

bool Circle::overlap(const Circle &circle) const {
    return (position - circle.position).length2() <= circle.rayon * circle.rayon + rayon * rayon;
}

bool Circle::overlap(const Line &line) const {
    Point b{line.position + line.vector};
    if (overlap(line.position) || overlap(b))
        return true;

    auto cp = line.closestPointTo(position);

    if ((line.position.x > cp.x && b.x > cp.x) || (line.position.x < cp.x && b.x < cp.x) ||
        (line.position.y > cp.y && b.y > cp.y) || (line.position.y < cp.y && b.y < cp.y))
        return false; // cp is ont on the line

    return (position - cp).length2() <= rayon * rayon;
}

bool Circle::overlap(const Point &point) const {
    return (position - point).length2() <= rayon * rayon;
}

} // namespace Blob::Maths
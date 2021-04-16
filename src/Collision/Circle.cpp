#include <Blob/Collision/Forms.hpp>

namespace Blob::Collision {

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
    return (position - circle.position).length2() <= (circle.rayon  + rayon) * (circle.rayon  + rayon);
}

bool Circle::overlap(const Line &line) const {
    if (overlap(line.positionA) || overlap(line.positionB))
        return true;

    auto cp = line.closestPointTo(position);

    if ((line.positionA.x > cp.x && line.positionB.x > cp.x) || (line.positionA.x < cp.x && line.positionB.x < cp.x) ||
        (line.positionA.y > cp.y && line.positionB.y > cp.y) || (line.positionA.y < cp.y && line.positionB.y < cp.y))
        return false; // cp is ont on the line

    return (position - cp).length() <= rayon;
}

bool Circle::overlap(const Point &point) const {
    return (position - point).length2() <= rayon * rayon;
}

std::unordered_set<Maths::Vec2<int32_t>> Circle::rasterize() const {
    std::unordered_set<Maths::Vec2<int32_t>> points;
    auto startx = (int32_t) (position.x - rayon);
    auto endx = (int32_t) (position.x + rayon);
    auto starty = (int32_t) (position.y - rayon);
    auto endy = (int32_t) (position.y + rayon);

    for (int i = startx; i <= endx; i++)
        for (int j = starty; j <= endy; j++)
            points.emplace(Maths::Vec2{i, j});

    return points;
}

} // namespace Blob::Maths

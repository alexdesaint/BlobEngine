#include <Blob/Collision/Forms.hpp>

namespace Blob {
std::unordered_set<Vec2<int32_t>> Rectangle::rasterize() const {
    std::unordered_set<Vec2<int32_t>> points;
    auto startx = (int64_t) (position.x - size.x / 2);
    auto endx = (int64_t) (position.x + size.x / 2);
    auto starty = (int64_t) (position.y - size.y / 2);
    auto endy = (int64_t) (position.y + size.y / 2);

    for (int i = startx; i <= endx; i++)
        for (int j = starty; j <= endy; j++)
            points.emplace(Vec2{i, j});

    return points;
}

std::array<Vec2<>, 4> Rectangle::getPoints() const {
    return {position.operator+({size.x / 2, size.y / 2}),
            position.operator+({-size.x / 2, size.y / 2}),
            position.operator+({-size.x / 2, -size.y / 2}),
            position.operator+({size.x / 2, -size.y / 2})};
}

bool Rectangle::overlap(const Rectangle &rectangle) const {
    Vec2<> AB{position, rectangle.position};
    Vec2<> totalSize{size + rectangle.size};
    if (std::abs(AB.x) > std::abs(totalSize.x / 2) ||
        std::abs(AB.y) > std::abs(totalSize.y / 2))
        return false;
    return true;
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

CollisionResolution Rectangle::resolve(const Rectangle &rectangle,
                                       Vec2<> D) const {
    Vec2<> A = position, B = rectangle.position;
    Vec2<> AB{A, B};
    Vec2<> totalSize{size + rectangle.size};
    Vec2<> AD(A, D);

    if (std::abs(AB.x) > std::abs(AD.x) + totalSize.x / 2 ||
        std::abs(AB.y) > std::abs(AD.y) + totalSize.y / 2)
        return {};

    float slope = (A.y - D.y) / (A.x - D.x);

    CollisionResolution res;
    if (AD.x > 0)
        res.bounce.x = res.shift.x = res.collisionPoint.x =
            B.x - totalSize.x / 2;
    else
        res.bounce.x = res.shift.x = res.collisionPoint.x =
            B.x + totalSize.x / 2;

    res.bounce.y = res.shift.y = D.y;
    res.collisionPoint.y = res.collisionPoint.x * slope + (A.y - A.x * slope);
    res.bounce.x -= D.x - res.bounce.x;
    if (std::abs(res.collisionPoint.y - B.y) <= totalSize.y / 2) {
        if (AD.dot({A, res.collisionPoint}) > 0 || overlap(rectangle))
            res.collision = true;
        return res;
    }

    if (AD.y > 0)
        res.bounce.y = res.shift.y = res.collisionPoint.y =
            B.y - totalSize.y / 2;
    else
        res.bounce.y = res.shift.y = res.collisionPoint.y =
            B.y + totalSize.y / 2;

    res.bounce.x = res.shift.x = D.x;
    res.collisionPoint.x = (res.collisionPoint.y - (A.y - A.x * slope)) / slope;
    res.bounce.y -= D.y - res.bounce.y;
    if (std::abs(res.collisionPoint.x - B.x) <= totalSize.x / 2) {
        if (AD.dot({A, res.collisionPoint}) > 0 || overlap(rectangle))
            res.collision = true;
        return res;
    }

    return res;
}

CollisionResolution Rectangle::resolve(const Point &point, Vec2<> D) const {
    return resolve(Rectangle{point, {}}, D);
}

} // namespace Blob

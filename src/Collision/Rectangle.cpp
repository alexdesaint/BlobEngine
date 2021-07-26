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
    Vec2<> totalSize{(size + rectangle.size) / 2};
    Vec2<> AD(A, D);

    if (std::abs(AB.x) > std::abs(AD.x) + totalSize.x ||
        std::abs(AB.y) > std::abs(AD.y) + totalSize.y)
        return {};

    float slope = (A.y - D.y) / (A.x - D.x);

    CollisionResolution res;
    res.collisionPoint.x = (AD.x > 0) ? B.x - totalSize.x : B.x + totalSize.x;
    res.collisionPoint.y = res.collisionPoint.x * slope + (A.y - A.x * slope);

    if (std::abs(res.collisionPoint.y - B.y) <= totalSize.y) {
        if (AD.dot({A, res.collisionPoint}) > 0 || overlap(rectangle))
            res.collision = true;
        res.shift.x = res.collisionPoint.x;
        res.bounce.y = res.shift.y = D.y;
        res.bounce.x = res.shift.x * 2 - D.x;
        return res;
    }

    res.collisionPoint.y = (AD.y > 0) ? B.y - totalSize.y : B.y + totalSize.y;
    res.collisionPoint.x = (res.collisionPoint.y - A.y + A.x * slope) / slope;

    if (std::abs(res.collisionPoint.x - B.x) <= totalSize.x) {
        if (AD.dot({A, res.collisionPoint}) > 0 || overlap(rectangle))
            res.collision = true;
        res.shift.y = res.collisionPoint.y;
        res.bounce.x = res.shift.x = D.x;
        res.bounce.y = res.shift.y * 2 - D.y;
        return res;
    }

    return res;
}

CollisionResolution Rectangle::resolve(const Point &point, Vec2<> D) const {
    return resolve(Rectangle{point, {}}, D);
}

CollisionResolution Rectangle::resolve(const Circle &circle, Vec2<> D) const {
    Vec2<> A = position, B = circle.position;
    Vec2<> AD(A, D);
    auto res = circle.resolve(*this, B - AD);

    res.collisionPoint = A - Vec2(B, res.collisionPoint);
    res.shift = A - Vec2(B, res.shift);
    res.bounce = A - Vec2(B, res.bounce);

    return res;
}

} // namespace Blob

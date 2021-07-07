#include <Blob/Collision/Forms.hpp>
#include <vcruntime.h>

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
    auto r1x = position.x - size.x / 2;
    auto r1y = position.y - size.y / 2;
    auto r2x = rectangle.position.x - rectangle.size.x / 2;
    auto r2y = rectangle.position.y - rectangle.size.y / 2;
    auto r1w = size.x;
    auto r1h = size.y;
    auto r2w = rectangle.size.x;
    auto r2h = rectangle.size.y;

    if (r1x + r1w >= r2x && // r1 right edge past r2 left
        r1x <= r2x + r2w && // r1 left edge past r2 right
        r1y + r1h >= r2y && // r1 top edge past r2 bottom
        r1y <= r2y + r2h) { // r1 bottom edge past r2 top
        return true;
    }
    return false;

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
                                       Vec2<> destination) const {

    Vec2<> AB{position, rectangle.position};
    Vec2<> totalSize{size + rectangle.size};
    Vec2<> D = destination;
    Vec2<> AD(position, D);

    if (std::abs(AB.x) > std::abs(AD.x) + totalSize.x / 2 ||
        std::abs(AB.y) > std::abs(AD.y) + totalSize.y / 2)
        return {};

    float x1 = rectangle.position.x + totalSize.x / 2;
    float x2 = rectangle.position.x - totalSize.x / 2;
    float y1 = rectangle.position.y + totalSize.y / 2;
    float y2 = rectangle.position.y - totalSize.y / 2;

    float slope = (position.y - destination.y) / (position.x - destination.x);

    CollisionResolution res;
    if (AD.x > 0) {
        if (D.x > x2)
            res.collisionPoint.x = x2;
    } else {
        if (D.x < x1)
            res.collisionPoint.x = x1;
    }
    res.collisionPoint.y =
        res.collisionPoint.x * slope + (position.y - position.x * slope);
    if (std::abs(res.collisionPoint.y - rectangle.position.y) <
        totalSize.y / 2) {
        res.collision = true;
        return res;
    }
    if (AD.y > 0) {
        if (D.y > y2) {
            res.collisionPoint.y = y2;
        }
    } else {
        if (D.y < y1) {
            res.collisionPoint.y = y1;
        }
    }
    res.collisionPoint.x =
        (res.collisionPoint.y - (position.y - position.x * slope)) / slope;
    if (std::abs(res.collisionPoint.x - rectangle.position.x) <
        totalSize.x / 2) {
        res.collision = true;
        return res;
    }

    return res;
}

} // namespace Blob

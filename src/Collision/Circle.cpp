#include <Blob/Collision/Forms.hpp>

namespace Blob {

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
    return (position - circle.position).length2() <=
           (circle.rayon + rayon) * (circle.rayon + rayon);
}

bool Circle::overlap(const Line &line) const {
    if (overlap(line.positionA) || overlap(line.positionB))
        return true;

    auto cp = line.closestPointTo(position);

    if ((line.positionA.x > cp.x && line.positionB.x > cp.x) ||
        (line.positionA.x < cp.x && line.positionB.x < cp.x) ||
        (line.positionA.y > cp.y && line.positionB.y > cp.y) ||
        (line.positionA.y < cp.y && line.positionB.y < cp.y))
        return false; // cp is ont on the line

    return (position - cp).length() <= rayon;
}

bool Circle::overlap(const Point &point) const {
    return (position - point).length2() <= rayon * rayon;
}

std::unordered_set<Vec2<int32_t>> Circle::rasterize() const {
    std::unordered_set<Vec2<int32_t>> points;
    auto startx = (int32_t) (position.x - rayon);
    auto endx = (int32_t) (position.x + rayon);
    auto starty = (int32_t) (position.y - rayon);
    auto endy = (int32_t) (position.y + rayon);

    for (int i = startx; i <= endx; i++)
        for (int j = starty; j <= endy; j++)
            points.emplace(Vec2{i, j});

    return points;
}

bool getIntersection(const Circle &circle,
                     const Vec2<> &A,
                     const Vec2<> &AD,
                     Vec2<> &point) {
    float dr = AD.length2();
    const Vec2<> &B = circle.position;
    const float determinant = (A - B).cross(A + AD - B);
    const float delta =
        circle.rayon * circle.rayon * dr - determinant * determinant;
    if (delta <= 0)
        return false;

    point = (AD.rotate() * determinant - AD * std::sqrt(delta)) / dr + B;
    return true;
}

CollisionResolution Circle::resolve(const Circle &circle, Vec2<> dest) const {
    float rayonAB = rayon + circle.rayon;

    const auto &A = position, B = circle.position;
    const float ABlength = Vec2<>(A, B).length();
    const Vec2<> AD(A, dest);

    if (AD.length() <= ABlength - rayonAB)
        return {};

    CollisionResolution res{};
    if (!getIntersection({B, rayonAB}, A, AD, res.collisionPoint))
        return {};

    const Vec2<> AF{A, res.collisionPoint};

    if (AD.dot(AF) > 0 || ABlength < rayonAB)
        res.collision = true;

    res.normal = Vec2<>(res.collisionPoint, B).normalize();

    const Vec2<> FD{res.collisionPoint, dest};
    res.bounce = res.collisionPoint - res.normal * 2 * res.normal.dot(FD) + FD;
    const Vec2<> u = res.normal.rotate();
    res.shift = res.collisionPoint + u * u.dot(FD);
    return res;
}

CollisionResolution Circle::resolve(const Point &point, Vec2<> D) const {
    return resolve(Circle{point, 0}, D);
}

CollisionResolution Circle::resolve(const Line &line, Vec2<> D) const {
    const auto &A = position;

    const Vec2 C = line.closestPointTo(A);

    Vec2 CA(C, A), AD(A, D);

    if (rayon + AD.length() >= CA.length() && CA.length() >= 3 * rayon / 4 &&
        CA.dot(AD) < 0) {
        CollisionResolution res{};

        res.normal = CA.normalize();

        Vec2 G = A - res.normal * rayon;
        Vec2 G2 = G + AD;

        Vec2 I = line.getIntersection(Line(G, G2));

        Vec2 M = (line.positionA + line.positionB) / 2;

        if (Vec2(M, I).length() <= (line.length() / 2)) {
            res.collisionPoint = I + res.normal * rayon;

            Vec2 AF(A, res.collisionPoint);

            if (AF.length2() < AD.length2()) {
                res.collision = true;

                const Vec2<> FD{res.collisionPoint, D};
                res.bounce = res.collisionPoint -
                             res.normal * 2 * res.normal.dot(FD) + FD;
                const Vec2<> u = res.normal.rotate();
                res.shift = res.collisionPoint + u * u.dot(FD);
                return res;
            }
        }
    }
    auto r1 = resolve(line.positionA, D);
    auto r2 = resolve(line.positionB, D);
    if (r1.collision && r2.collision) {
        if (Vec2(A, r1.collisionPoint).length2() >
            Vec2(A, r2.collisionPoint).length2())
            return r2;
        else
            return r1;
    } else if (r1.collision)
        return r1;
    else if (r2.collision)
        return r2;

    return {};
}

CollisionResolution Circle::resolve(const Rectangle &rectangle,
                                    Vec2<> D) const {
    Vec2<> A = position, B = rectangle.position;
    Vec2<> AB{A, B};
    Vec2<> totalSize{rectangle.size / 2 + rayon};
    Vec2<> AD(A, D);

    if (std::abs(AB.x) > std::abs(AD.x) + totalSize.x ||
        std::abs(AB.y) > std::abs(AD.y) + totalSize.y)
        return {};

    float slope = (A.y - D.y) / (A.x - D.x);

    CollisionResolution res;
    res.collisionPoint.x = (AD.x > 0) ? B.x - totalSize.x : B.x + totalSize.x;
    res.collisionPoint.y = res.collisionPoint.x * slope + (A.y - A.x * slope);

    if (std::abs(res.collisionPoint.y - B.y) <= rectangle.size.y / 2) {
        if (AD.dot({A, res.collisionPoint}) > 0 || overlap(rectangle))
            res.collision = true;
        res.shift.x = res.collisionPoint.x;
        res.bounce.y = res.shift.y = D.y;
        res.bounce.x = res.shift.x * 2 - D.x;
        return res;
    } else if (std::abs(res.collisionPoint.y - B.y) <= totalSize.y) {
        res = resolve(
            Vec2{(res.collisionPoint.x < B.x) ? B.x - rectangle.size.x / 2
                                              : B.x + rectangle.size.x / 2,
                 (res.collisionPoint.y < B.y) ? B.y - rectangle.size.y / 2
                                              : B.y + rectangle.size.y / 2},
            D);

        if (!res.collision)
            res.collision = overlap(rectangle);

        return res;
    }

    res.collisionPoint.y = (AD.y > 0) ? B.y - totalSize.y : B.y + totalSize.y;
    res.collisionPoint.x = (res.collisionPoint.y - A.y + A.x * slope) / slope;

    if (std::abs(res.collisionPoint.x - B.x) <= rectangle.size.x / 2) {
        if (AD.dot({A, res.collisionPoint}) > 0 || overlap(rectangle))
            res.collision = true;
        res.shift.y = res.collisionPoint.y;
        res.bounce.x = res.shift.x = D.x;
        res.bounce.y = res.shift.y * 2 - D.y;
        return res;
    } else if (std::abs(res.collisionPoint.x - B.x) <= totalSize.x) {
        res = resolve(
            Vec2{(res.collisionPoint.x < B.x) ? B.x - rectangle.size.x / 2
                                              : B.x + rectangle.size.x / 2,
                 (res.collisionPoint.y < B.y) ? B.y - rectangle.size.y / 2
                                              : B.y + rectangle.size.y / 2},
            D);

        if (!res.collision)
            res.collision = overlap(rectangle);

        return res;
    }

    return res;
}
} // namespace Blob

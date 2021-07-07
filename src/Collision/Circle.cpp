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

CollisionResolution Circle::resolve(const Circle &circle,
                                    Vec2<> destination) const {
    float rayonA = rayon, rayonB = circle.rayon;
    float rayonAB = rayonA + rayonB;

    Vec2<> A = position, B = circle.position, D = destination;
    Vec2<> vecAB(A, B);
    Vec2<> vecAD(A, D);

    // si la distance qui les sépare est plus longue que le vecteur vitesse
    if (vecAD.length() <= vecAB.length() - rayonAB)
        return {};

    float dr = vecAD.x * vecAD.x + vecAD.y * vecAD.y;

    Vec2<> p1 = A - B;
    Vec2<> p2 = D - B;
    float determinant = p1.x * p2.y - p2.x * p1.y;

    // callcul de l'éxisance des point d'intersections
    float delta = rayonAB * rayonAB * dr - determinant * determinant;

    if (delta > 0) {
        Vec2<> i1, i2;

        i1.x = (determinant * vecAD.y +
                (vecAD.y < 0 ? -1 : 1) * vecAD.x * std::sqrt(delta)) /
               dr;
        i2.x = (determinant * vecAD.y -
                (vecAD.y < 0 ? -1 : 1) * vecAD.x * std::sqrt(delta)) /
               dr;

        i1.y = (-determinant * vecAD.x + std::abs(vecAD.y) * std::sqrt(delta)) /
               dr;
        i2.y = (-determinant * vecAD.x - std::abs(vecAD.y) * std::sqrt(delta)) /
               dr;

        i1 = i1 + B;
        i2 = i2 + B;

        if (Vec2(A, i1).length2() < Vec2(A, i2).length2()) {
            if (vecAD.dot({A, i1}) > 0 || vecAB.length2() < rayonAB * rayonAB) {
                CollisionResolution res{};
                res.collision = true;
                res.collisionPoint = i1;
                res.normal = Vec2<>(res.collisionPoint, B).normalize();
                return res;
            }
        } else {
            if (vecAD.dot({A, i2}) > 0 || vecAB.length2() < rayonAB * rayonAB) {
                CollisionResolution res{};
                res.collision = true;
                res.collisionPoint = i2;
                res.normal = Vec2<>(res.collisionPoint, B).normalize();
                return res;
            }
        }
    }

    return {};
}

CollisionResolution Circle::resolve(const Line &target,
                                    Vec2<> destination) const {
    Vec2 C = target.closestPointTo(position);

    Vec2 vecCA(C, position), frameMove(position, destination);

    if (rayon + frameMove.length() >= vecCA.length() &&
        vecCA.length() >= 3 * rayon / 4) {

        if (vecCA.dot(frameMove) < 0) {
            CollisionResolution res{};

            res.normal = vecCA.normalize();

            Vec2 G = position - res.normal * rayon;
            Vec2 G2 = G + frameMove;

            Vec2 I = target.getIntersectionPoint(Line(G, G2));

            Vec2 M = (target.positionA + target.positionB) / 2;

            if (Vec2(M, I).length() <= (target.length() / 2)) {

                res.collisionPoint = I + res.normal * rayon;

                Vec2 vecAF(position, res.collisionPoint);

                if (vecAF.length2() < frameMove.length2()) {
                    res.collision = true;
                    return res;
                }
            }
        }
    }
    return {};
}

} // namespace Blob

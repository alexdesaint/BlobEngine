#pragma once

#include <Blob/Maths.inl>

#include <array>
#include <cmath>
#include <cstdint>
#include <ostream>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

namespace Blob {

class Circle;
class Line;
class Rectangle;
class Point;

struct CollisionResolution {
    bool collision = false;
    Vec2<> collisionPoint, normal, bounce, shift;
};

class Raster : public Vec2<int32_t> {
public:
    constexpr static bool overlap(const Rectangle &rectangle) { return true; }

    constexpr static bool overlap(const Circle &circle) { return true; }

    constexpr static bool overlap(const Line &line) { return true; }

    constexpr static bool overlap(const Point &point) { return true; }

    constexpr static bool overlap(const Raster &rasterArea) { return true; }

    std::unordered_set<Vec2<int32_t>> rasterize() const { return {*this}; };

    friend std::ostream &operator<<(std::ostream &os, const Raster &p) {
        return os << "RasterArea: " << (const Vec2<int32_t> &) p;
    }
};

class Point : public Vec2<> {
public:
    using Vec2<>::Vec2;
    using Vec2<>::operator=;

    Point() = default;

    Point(const Point &v) = default;

    Point(const Vec2<> &v) : Vec2<>(v) {}

    bool overlap(const Rectangle &rectangle) const;

    constexpr static bool overlap(const Line &line) { return false; }

    constexpr static bool overlap(const Point &point) { return false; }

    bool overlap(const Circle &circle) const;

    constexpr static bool overlap(const Raster &rasterArea) { return true; }

    std::unordered_set<Vec2<int32_t>> rasterize() const;

    friend std::ostream &operator<<(std::ostream &os, const Point &p) {
        return os << "Point: " << (Vec2<>) p;
    }
};

class Circle {
public:
    Point position;
    float rayon;

    Circle() = default;

    Circle(const Point &position, float rayon) :
        rayon(rayon), position(position) {}

    Circle(const Vec2<> &position, float rayon) :
        rayon(rayon), position(position) {}

    bool overlap(const Rectangle &rectangle) const;

    bool overlap(const Circle &circle) const;

    bool overlap(const Line &line) const;

    bool overlap(const Point &point) const;

    CollisionResolution resolve(const Circle &circle, Vec2<> destination) const;

    CollisionResolution resolve(const Line &line, Vec2<> destination) const;

    CollisionResolution resolve(const Point &point, Vec2<> destination) const;

    CollisionResolution resolve(const Rectangle &rectangle,
                                Vec2<> destination) const;

    constexpr static bool overlap(const Raster &rasterArea) { return true; }

    std::unordered_set<Vec2<int32_t>> rasterize() const;

    friend std::ostream &operator<<(std::ostream &os, const Circle &p) {
        return os << "Circle: {position: " << (Vec2<>) p.position
                  << ", rayon: " << p.rayon << "}";
    }
};

class Line {
public:
    Point positionA;
    Point positionB;

    Line(Vec2<> &a, Vec2<> &b) : positionA(a), positionB(b) {}

    double length2() const { return Vec2<>{positionA, positionB}.length2(); }

    double length() const { return Vec2<>{positionA, positionB}.length(); }

    //        double getOrientation() const { return
    //        vector.getOrientation(); }

    Point closestPointTo(Point point) const;

    Point getIntersection(Line B) const;

    bool overlap(const Rectangle &rectangle) const;

    bool overlap(const Circle &circle) const;

    bool overlap(const Line &line) const;

    bool overlap(const Point &point) const;

    constexpr static bool overlap(const Raster &rasterArea) { return true; }

    std::unordered_set<Vec2<int32_t>> rasterize() const;

    //        double getGradient() const { return vector.y /
    //        vector.x; }

    //        double getConstant() const { return position.y -
    //        vector.y / vector.x * position.x; }

    friend std::ostream &operator<<(std::ostream &os, const Line &p) {
        return os << "Line: {positionA: " << (Vec2<>) p.positionA
                  << ", positionB: " << (Vec2<>) p.positionB << "}";
    }
};

class Rectangle {
public:
    Point position, size;

    Rectangle(const Vec2<> &position, const Vec2<> &size) :
        position(position), size(size) {}

    std::array<Vec2<>, 4> getPoints() const;

    bool overlap(const Rectangle &rectangle) const;

    bool overlap(const Circle &circle) const;

    bool overlap(const Line &line) const;

    bool overlap(const Point &point) const;

    constexpr static bool overlap(const Raster &rasterArea) { return true; }

    CollisionResolution resolve(const Rectangle &rectangle,
                                Vec2<> destination) const;

    CollisionResolution resolve(const Point &point, Vec2<> destination) const;

    CollisionResolution resolve(const Circle &circle, Vec2<> destination) const;

    std::unordered_set<Vec2<int32_t>> rasterize() const;

    friend std::ostream &operator<<(std::ostream &os, const Rectangle &p) {
        return os << "Rectangle: {position: " << (Vec2<>) p.position
                  << ", size: " << (Vec2<>) p.size << "}";
    }
};

} // namespace Blob

#pragma once

#include <Blob/Maths.inl>

#include <array>
#include <cmath>
#include <ostream>
#include <unordered_set>
#include <utility>
#include <vector>

template<>
struct std::hash<Blob::Maths::Vec2<int32_t>> {
    inline std::size_t operator()(const Blob::Maths::Vec2<int32_t> &k) const { return *reinterpret_cast<const std::size_t *>(&k); }
};

namespace Blob::Collision {

class Circle;
class Line;
class Rectangle;
class RasterArea;

class Point : public Maths::Vec2<float> {
public:
    using Maths::Vec2<>::Vec2;
    using Maths::Vec2<>::operator=;

    Point() = default;

    Point(const Point &v) = default;

    explicit Point(const Maths::Vec2<float> &v) : Maths::Vec2<float>(v) {}

    [[nodiscard]] bool overlap(const Rectangle &rectangle) const;

    [[nodiscard]] static bool overlap(const Line &rectangle) { return false; }

    [[nodiscard]] static bool overlap(const Point &rectangle) { return false; }

    [[nodiscard]] bool overlap(const Circle &circle) const;

    [[nodiscard]] static bool overlap(const RasterArea &rasterArea) { return true; }

    [[nodiscard]] std::unordered_set<Maths::Vec2<int32_t>> rasterize() const;
};

class Circle {
public:
    double rayon = 0;
    Point position;

    Circle(const Point &position, double rayon) : rayon(rayon), position(position) {}

    Circle(const Maths::Vec2<float> &position, double rayon) : rayon(rayon), position(position) {}

    [[nodiscard]] bool overlap(const Rectangle &rectangle) const;

    [[nodiscard]] bool overlap(const Circle &circle) const;

    [[nodiscard]] bool overlap(const Line &line) const;

    [[nodiscard]] bool overlap(const Point &point) const;

    [[nodiscard]] static bool overlap(const RasterArea &rasterArea) { return true; }

    [[nodiscard]] std::unordered_set<Maths::Vec2<int32_t>> rasterize() const;
};

class Line {
public:
    Point positionA;
    Point positionB;

    Line(Point &a, Point &b) : positionA(a), positionB(b) {}

    //        [[nodiscard]] double Length2() const { return vector.length2(); }

    //        [[nodiscard]] double Length() const { return vector.length(); }

    //        [[nodiscard]] double getOrientation() const { return vector.getOrientation(); }

    [[nodiscard]] Point closestPointTo(Point point) const;

    [[nodiscard]] Point getIntersectionPoint(Line B) const;

    [[nodiscard]] bool overlap(const Rectangle &rectangle) const;

    [[nodiscard]] bool overlap(const Circle &circle) const;

    [[nodiscard]] bool overlap(const Line &line) const;

    [[nodiscard]] bool overlap(const Point &point) const;

    [[nodiscard]] static bool overlap(const RasterArea &rasterArea) { return true; }

    [[nodiscard]] std::unordered_set<Maths::Vec2<int32_t>> rasterize() const;

    //        [[nodiscard]] double getGradient() const { return vector.y / vector.x; }

    //        [[nodiscard]] double getConstant() const { return position.y - vector.y / vector.x * position.x; }
};

class Rectangle {
public:
    Point position, size;

    Rectangle(const Maths::Vec2<float> &position, const Maths::Vec2<float> &size) : position(position), size(size) {}

    [[nodiscard]] std::array<Maths::Vec2<>, 4> getPoints() const;

    [[nodiscard]] bool overlap(const Rectangle &rectangle) const;

    [[nodiscard]] bool overlap(const Circle &circle) const;

    [[nodiscard]] bool overlap(const Line &line) const;

    [[nodiscard]] bool overlap(const Point &point) const;

    [[nodiscard]] static bool overlap(const RasterArea &rasterArea) { return true; }

    [[nodiscard]] std::unordered_set<Maths::Vec2<int32_t>> rasterize() const;
};

class RasterArea {
public:
    std::unordered_set<Maths::Vec2<int32_t>> area;

    RasterArea() = default;
    explicit RasterArea(std::unordered_set<Maths::Vec2<int32_t>> area) : area(std::move(area)) {}

    RasterArea(const Maths::Vec2<int32_t> &start, const Maths::Vec2<int32_t> &end) { setArea(start, end); }
    RasterArea(const Maths::Vec2<int32_t> &center, int32_t sizeX, int32_t sizeY) { setArea(center, sizeX, sizeY); }

    void setArea(const Maths::Vec2<int32_t> &start, const Maths::Vec2<int32_t> &end) {
        area.clear();
        int startX, endX, startY, endY;
        if (start.x < end.x) {
            startX = start.x;
            endX = end.x;
        } else {
            startX = end.x;
            endX = start.x;
        }
        if (start.y < end.y) {
            startY = start.y;
            endY = end.y;
        } else {
            startY = end.y;
            endY = start.y;
        }

        for (int i = startX; i <= endX; i++)
            for (int j = startY; j <= endY; j++)
                area.emplace(Maths::Vec2{i, j});
    }

    void setArea(const Maths::Vec2<int32_t> &center, int32_t sizeX, int32_t sizeY) {
        Maths::Vec2<int32_t> size(sizeX, sizeY), size2(size/2);
        setArea(center - size2, center + size - size2 - 1);
    }

    [[nodiscard]] static bool overlap(const Rectangle &rectangle) { return true; }

    [[nodiscard]] static bool overlap(const Circle &circle) { return true; }

    [[nodiscard]] static bool overlap(const Line &line) { return true; }

    [[nodiscard]] static bool overlap(const Point &point) { return true; }

    [[nodiscard]] static bool overlap(const RasterArea &rasterArea) { return true; }

    [[nodiscard]] std::unordered_set<Maths::Vec2<int32_t>> rasterize() const { return area; };
};

} // namespace Blob::Geometry

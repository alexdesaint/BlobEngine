#pragma once

#include <Blob/Maths.inl>

#include <array>
#include <cmath>
#include <ostream>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

template<>
struct std::hash<Blob::Vec2<int32_t>> {
    inline std::size_t operator()(const Blob::Vec2<int32_t> &k) const {
        return *reinterpret_cast<const std::size_t *>(&k);
    }
};

namespace Blob {

class Circle;
class Line;
class Rectangle;
class RasterArea;

class Point : public Vec2<float> {
public:
    using Vec2<>::Vec2;
    using Vec2<>::operator=;

    Point() = default;

    Point(const Point &v) = default;

    Point(const Vec2<float> &v) : Vec2<float>(v) {}

    [[nodiscard]] bool overlap(const Rectangle &rectangle) const;

    [[nodiscard]] static bool overlap(const Line &rectangle) { return false; }

    [[nodiscard]] static bool overlap(const Point &rectangle) { return false; }

    [[nodiscard]] bool overlap(const Circle &circle) const;

    [[nodiscard]] static bool overlap(const RasterArea &rasterArea) {
        return true;
    }

    [[nodiscard]] std::unordered_set<Vec2<int32_t>> rasterize() const;

    friend std::ostream &operator<<(std::ostream &os, const Point &p) {
        return os << "Point: " << (Vec2<float>) p;
    }
};

class Circle {
public:
    float rayon = 0;
    Point position;

    Circle() = default;

    Circle(const Point &position, float rayon) :
        rayon(rayon), position(position) {}

    Circle(const Vec2<float> &position, float rayon) :
        rayon(rayon), position(position) {}

    [[nodiscard]] bool overlap(const Rectangle &rectangle) const;

    [[nodiscard]] bool overlap(const Circle &circle) const;

    [[nodiscard]] bool overlap(const Line &line) const;

    [[nodiscard]] bool overlap(const Point &point) const;

    [[nodiscard]] static bool overlap(const RasterArea &rasterArea) {
        return true;
    }

    [[nodiscard]] std::unordered_set<Vec2<int32_t>> rasterize() const;

    friend std::ostream &operator<<(std::ostream &os, const Circle &p) {
        return os << "Circle: {position: " << (Vec2<float>) p.position
                  << ", rayon: " << p.rayon << "}";
    }
};

class Line {
public:
    Point positionA;
    Point positionB;

    Line(Point &a, Point &b) : positionA(a), positionB(b) {}

    //        [[nodiscard]] double Length2() const { return vector.length2(); }

    //        [[nodiscard]] double Length() const { return vector.length(); }

    //        [[nodiscard]] double getOrientation() const { return
    //        vector.getOrientation(); }

    [[nodiscard]] Point closestPointTo(Point point) const;

    [[nodiscard]] Point getIntersectionPoint(Line B) const;

    [[nodiscard]] bool overlap(const Rectangle &rectangle) const;

    [[nodiscard]] bool overlap(const Circle &circle) const;

    [[nodiscard]] bool overlap(const Line &line) const;

    [[nodiscard]] bool overlap(const Point &point) const;

    [[nodiscard]] static bool overlap(const RasterArea &rasterArea) {
        return true;
    }

    [[nodiscard]] std::unordered_set<Vec2<int32_t>> rasterize() const;

    //        [[nodiscard]] double getGradient() const { return vector.y /
    //        vector.x; }

    //        [[nodiscard]] double getConstant() const { return position.y -
    //        vector.y / vector.x * position.x; }

    friend std::ostream &operator<<(std::ostream &os, const Line &p) {
        return os << "Line: {positionA: " << (Vec2<float>) p.positionA
                  << ", positionB: " << (Vec2<float>) p.positionB << "}";
    }
};

class Rectangle {
public:
    Point position, size;

    Rectangle(const Vec2<float> &position, const Vec2<float> &size) :
        position(position), size(size) {}

    [[nodiscard]] std::array<Vec2<>, 4> getPoints() const;

    [[nodiscard]] bool overlap(const Rectangle &rectangle) const;

    [[nodiscard]] bool overlap(const Circle &circle) const;

    [[nodiscard]] bool overlap(const Line &line) const;

    [[nodiscard]] bool overlap(const Point &point) const;

    [[nodiscard]] static bool overlap(const RasterArea &rasterArea) {
        return true;
    }

    [[nodiscard]] std::unordered_set<Vec2<int32_t>> rasterize() const;

    friend std::ostream &operator<<(std::ostream &os, const Rectangle &p) {
        return os << "Rectangle: {position: " << (Vec2<float>) p.position
                  << ", size: " << (Vec2<float>) p.size << "}";
    }
};

class RasterArea {
public:
    std::unordered_set<Vec2<int32_t>> area;

    RasterArea() = default;
    explicit RasterArea(std::unordered_set<Vec2<int32_t>> area) :
        area(std::move(area)) {}

    RasterArea(const Vec2<int32_t> &start, const Vec2<int32_t> &end) {
        setArea(start, end);
    }
    RasterArea(const Vec2<int32_t> &center, int32_t sizeX, int32_t sizeY) {
        setArea(center, sizeX, sizeY);
    }

    void setArea(const Vec2<int32_t> &start, const Vec2<int32_t> &end) {
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
                area.emplace(Vec2{i, j});
    }

    void setArea(const Vec2<int32_t> &center, int32_t sizeX, int32_t sizeY) {
        Vec2<int32_t> size(sizeX, sizeY), size2(size / 2);
        setArea(center - size2, center + size - size2 - 1);
    }

    [[nodiscard]] static bool overlap(const Rectangle &rectangle) {
        return true;
    }

    [[nodiscard]] static bool overlap(const Circle &circle) { return true; }

    [[nodiscard]] static bool overlap(const Line &line) { return true; }

    [[nodiscard]] static bool overlap(const Point &point) { return true; }

    [[nodiscard]] static bool overlap(const RasterArea &rasterArea) {
        return true;
    }

    [[nodiscard]] std::unordered_set<Vec2<int32_t>> rasterize() const {
        return area;
    };

    friend std::ostream &operator<<(std::ostream &os, const RasterArea &p) {
        return os << "RasterArea: ";
    }
};

} // namespace Blob

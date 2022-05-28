#pragma once
#include <Blob/Maths.hpp>
#include <unordered_set>
#include <vector>

namespace Blob {

using Raster = Vec2<int>;
using RasterArea = std::unordered_set<Raster>;
RasterArea getRasterArea(const Raster &start, const Raster &end);
std::ostream &operator<<(std::ostream &os, const RasterArea &p);

using Point = Vec2<>;
using Polygon = std::vector<Point>;
struct Segment {
    Point p1, p2;
    Segment() = default;
    Segment(const Point &p1, const Point &p2) : p1(p1), p2(p2) {}
};
struct Box {
    Point p1, p2;
    Box() = default;
    Box(const Point &p1, const Point &p2) : p1(p1), p2(p2) {}
    Box(const Point &center, const float &sizeX, const float &sizeY) :
        p1(center - Point{sizeX, sizeY} / 2), p2(center + Point{sizeX, sizeY} / 2) {}
};

Raster toRaster(const Point &point);

template<class Shape>
RasterArea rasterize(const Shape &shape);

template<class Shape>
Box envelope(const Shape &shape);

template<class Shape1, class Shape2>
bool overlap(const Shape1 &shape1, const Shape2 &shape2);

} // namespace Blob

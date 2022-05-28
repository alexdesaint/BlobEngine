#include <Blob/Collision/Forms.hpp>

#include <boost/geometry.hpp>
#include <boost/geometry/algorithms/detail/disjoint/interface.hpp>
#include <boost/geometry/algorithms/detail/envelope/interface.hpp>
#include <boost/geometry/geometries/polygon.hpp>
#include <boost/geometry/geometries/register/box.hpp>
#include <boost/geometry/geometries/register/multi_polygon.hpp>
#include <boost/geometry/geometries/register/point.hpp>
#include <boost/geometry/geometries/register/ring.hpp>
#include <boost/geometry/geometries/register/segment.hpp>

BOOST_GEOMETRY_REGISTER_POINT_2D(Blob::Point, float, boost::geometry::cs::cartesian, x, y)
BOOST_GEOMETRY_REGISTER_BOX_2D_4VALUES(Blob::Box, Blob::Point, p1.x, p1.y, p2.x, p2.y)
BOOST_GEOMETRY_REGISTER_SEGMENT_2D_4VALUES(Blob::Segment, Blob::Point, p1.x, p1.y, p2.x, p2.y)
BOOST_GEOMETRY_REGISTER_RING(Blob::Polygon)

namespace Blob {

RasterArea getRasterArea(const Raster &start, const Raster &end) {
    RasterArea rasters;
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
            rasters.emplace(Raster{i, j});

    return rasters;
}

std::ostream &operator<<(std::ostream &os, const RasterArea &p) {
    os << "{";
    for (const auto &q : p)
        os << "{" << q.x << ", " << q.y << "}";
    return os << "}";
}

Raster toRaster(const Point &point) {
    return {static_cast<int>(std::floor(point.x)), static_cast<int>(std::floor(point.y))};
}

template<class Shape>
Box envelope(const Shape &shape) {
    Box box;
    boost::geometry::envelope(shape, box);
    return box;
}
template Box envelope(const Point &shape);
template Box envelope(const Box &shape);
template Box envelope(const Segment &shape);
template Box envelope(const Polygon &shape);

template<class Shape>
RasterArea rasterize(const Shape &shape) {
    Box box;
    boost::geometry::envelope(shape, box);
    return getRasterArea(toRaster(box.p1), toRaster(box.p2));
}

template RasterArea rasterize(const Box &shape);
template RasterArea rasterize(const Segment &shape);
template RasterArea rasterize(const Polygon &shape);

template<>
RasterArea rasterize(const Point &shape) {
    return {toRaster(shape)};
}
template<>
RasterArea rasterize(const Raster &shape) {
    return {shape};
}
template<>
RasterArea rasterize(const RasterArea &shape) {
    return shape;
}

template<class Shape1, class Shape2>
bool overlap(const Shape1 &shape1, const Shape2 &shape2) {
    return !boost::geometry::disjoint(shape1, shape2);
}

template bool overlap(const Point &shape1, const Point &shape2);
template bool overlap(const Point &shape1, const Segment &shape2);
template bool overlap(const Point &shape1, const Box &shape2);

template bool overlap(const Segment &shape1, const Point &shape2);
template bool overlap(const Segment &shape1, const Segment &shape2);
template bool overlap(const Segment &shape1, const Box &shape2);

template bool overlap(const Box &shape1, const Point &shape2);
template bool overlap(const Box &shape1, const Segment &shape2);
template bool overlap(const Box &shape1, const Box &shape2);

} // namespace Blob

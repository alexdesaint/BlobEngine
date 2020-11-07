#pragma once

#include <Blob/Maths.inl>

#include <array>
#include <cmath>
#include <list> // TODO: remove this
#include <ostream>
#define PI 3.141592653589793238462643383279502884L

namespace Blob::Geometry {

class Rectangle;
class Circle;
class Line;

class Point : public Maths::Vec2<float> {
public:
    using Maths::Vec2<>::Vec2;
    using Maths::Vec2<>::operator=;

    Point() = default;

    explicit Point(const Maths::Vec2<float> &v) : Maths::Vec2<float>(v) {}

    [[nodiscard]] bool overlap(const Rectangle &rectangle) const;

    [[nodiscard]] bool overlap(const Circle &circle) const;
};

class Form {
protected:

public:
    Point position;

    Form() = default;

    explicit Form(const Maths::Vec2<float> &v) : position(v) {}

    [[nodiscard]] virtual bool overlap(const Rectangle &rectangle) const = 0;
    [[nodiscard]] virtual bool overlap(const Circle &circle) const = 0;
    [[nodiscard]] virtual bool overlap(const Line &line) const = 0;
    [[nodiscard]] virtual bool overlap(const Point &point) const = 0;

    [[nodiscard]] virtual std::list<Maths::Vec2<int32_t>> rasterize() const = 0;
};

class Circle : virtual public Form {
public:
    double rayon = 0;

    Circle() : rayon(0) {}

    Circle(Point &position, double rayon) : rayon(rayon) {}

    [[nodiscard]] bool overlap(const Rectangle &rectangle) const final;
    [[nodiscard]] bool overlap(const Circle &circle) const final;
    [[nodiscard]] bool overlap(const Line &line) const final;
    [[nodiscard]] bool overlap(const Point &point) const final;

    [[nodiscard]] std::list<Maths::Vec2<int32_t>> rasterize() const final;
};

class Line : virtual public Form {
public:
    Maths::Vec2<float> vector;

    Line() : vector() {}

    Line(Point &a, Point &b) : Form(a), vector(b - a) {}

    [[nodiscard]] double Length2() const { return vector.length2(); }

    [[nodiscard]] double Length() const { return vector.length(); }

    [[nodiscard]] double getOrientation() const { return vector.getOrientation(); }

    [[nodiscard]] Point closestPointTo(Point point) const;

    [[nodiscard]] Point getIntersectionPoint(Line B) const;

    [[nodiscard]] bool overlap(const Rectangle &rectangle) const final;
    [[nodiscard]] bool overlap(const Circle &circle) const final;
    [[nodiscard]] bool overlap(const Line &line) const final;
    [[nodiscard]] bool overlap(const Point &point) const final;

    [[nodiscard]] std::list<Maths::Vec2<int32_t>> rasterize() const final;

    [[nodiscard]] double getGradient() const { return vector.y / vector.x; }

    [[nodiscard]] double getConstant() const { return position.y - vector.y / vector.x * position.x; }
};

class Rectangle : virtual public Form {
public:
    /// The center of the rectangle
    Point position;

    /// full size of the sides
    Maths::Vec2<> size;

    Rectangle() : position(), size() {}

    Rectangle(const Maths::Vec2<> &position, const Maths::Vec2<> &size) : position(position), size(size) {}

    [[nodiscard]] std::array<Maths::Vec2<>, 4> getPoints() const;

    [[nodiscard]] bool overlapBigger(const Rectangle &r) const;

    [[nodiscard]] bool overlap(const Rectangle &rectangle) const final;
    [[nodiscard]] bool overlap(const Circle &circle) const final;
    [[nodiscard]] bool overlap(const Line &line) const final;
    [[nodiscard]] bool overlap(const Point &point) const final;

    [[nodiscard]] std::list<Maths::Vec2<int32_t>> rasterize() const final;
};
}; // namespace Blob::Geometry

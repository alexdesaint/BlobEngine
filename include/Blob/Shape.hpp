#pragma once

#include <Blob/Mesh.hpp>
#include <list>

namespace Blob::Core {

class Shape : public Maths::ModelTransform {
    friend Window;

private:
    Mesh *mesh = nullptr;
    std::list<Shape *> shapes;
    Shape *parent = nullptr;

public:
    Shape() = default;

    explicit Shape(Mesh &r);

    Shape(Mesh &r, const Maths::Vec3<float> &Location);

    Shape(Mesh &r, const Maths::Vec2<float> &Location);

    Shape(Mesh &r, const Maths::Vec3<float> &Location, const Maths::Vec3<float> &Scale);

    Shape(Mesh &r, const Maths::Vec2<float> &Location, const Maths::Vec2<float> &Scale);

    Shape(Mesh &r, const Maths::Vec3<float> &Location, const Maths::Vec3<float> &Scale, const Maths::Vec3<float> &Rotation);

    explicit Shape(const Maths::Vec3<float> &Location);

    explicit Shape(const Maths::Vec2<float> &Location);

    Shape(const Maths::Vec3<float> &Location, const Maths::Vec3<float> &Scale);

    Shape(const Maths::Vec2<float> &Location, const Maths::Vec2<float> &Scale);

    Shape(const Maths::Vec3<float> &Location, const Maths::Vec3<float> &Scale, const Maths::Vec3<float> &Rotation);

    void setMesh(Mesh &r);
    void setMesh(Mesh *r);

    void setChild(Shape &r);
    void setChild(Shape *r);

    void removeMesh();

    void removeChild(Shape &r);
    void removeChild(Shape *r);

    friend std::ostream &operator<<(std::ostream &s, const Shape &a);
};
} // namespace Blob::Core

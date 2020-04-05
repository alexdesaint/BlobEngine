#pragma once

#include <Blob/Mesh.hpp>
#include <list>

namespace Blob {

class Shape : public ModelTransform {
    friend Window;

private:
    Mesh *mesh = nullptr;
    std::list<Shape *> shapes;
    Shape *parent = nullptr;

public:
    Shape(Mesh &r, float LocationX = 0.f, float LocationY = 0.f, float LocationZ = 0.f, float ScaleX = 1.f, float ScaleY = 1.f, float ScaleZ = 1.f,
          float RotationX = 0.f, float RotationY = 0.f, float RotationZ = 0.f);
    Shape(float LocationX = 0.f, float LocationY = 0.f, float LocationZ = 0.f, float ScaleX = 1.f, float ScaleY = 1.f, float ScaleZ = 1.f,
          float RotationX = 0.f, float RotationY = 0.f, float RotationZ = 0.f);

    void setMesh(Mesh &r);
    void setMesh(Mesh *r);

    void setChild(Shape &r);
    void setChild(Shape *r);

    void removeMesh();

    void removeChild(Shape &r);
    void removeChild(Shape *r);

    friend std::ostream &operator<<(std::ostream &s, const Shape &a);
};
} // namespace Blob

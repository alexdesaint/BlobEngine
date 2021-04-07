#pragma once

#include <Blob/Core/Mesh.hpp>
#include <list>

namespace Blob::Core {

template<class Transform, class Mesh>
class ShapeBase : public Transform {
    friend Window;

private:
    const Mesh *mesh = nullptr;
    std::list<ShapeBase *> shapes;

public:
    ShapeBase() = default;
    ShapeBase(const ShapeBase &) = delete;
    ShapeBase(ShapeBase &&) = delete;

    //template<typename... Args>
    explicit ShapeBase(const Transform& args) : Transform(args) {}

    //template<typename... Args>
    explicit ShapeBase(const Mesh &r) : mesh(&r) {}

    //template<typename... Args>
    explicit ShapeBase(const Mesh &r, const Transform& args) : mesh(&r), Transform(args) {}

    void setMesh(Mesh &r) { mesh = &r; }
    void setMesh(Mesh *r) { mesh = r; }
    void removeMesh() { mesh = nullptr; }

    void addChild(ShapeBase *r) {
        shapes.emplace_back(r);
    }

    void addChild(ShapeBase &r) {
        shapes.emplace_back(&r);
    }

    void removeChild(ShapeBase &r) {
        auto it = std::find(shapes.begin(), shapes.end(), &r);
        if (it != shapes.end())
            shapes.erase(it);
    }

    void removeChild(ShapeBase *r) {
        auto it = std::find(shapes.begin(), shapes.end(), r);
        if (it != shapes.end())
            shapes.erase(it);
    }

    friend std::ostream &operator<<(std::ostream &s, const ShapeBase<Transform, Mesh> &a) {
        s << "Shape : {" << std::endl;

        s << (Maths::ModelTransform) a << std::endl;

        s << a.mesh << std::endl;

        for (const auto &r : a.shapes)
            s << *r;

        s << "}" << std::endl;
        return s;
    }
};

//template class ShapeBase<Maths::ModelTransform>;

typedef ShapeBase<Maths::ModelTransform, Mesh> Shape;
typedef ShapeBase<Maths::ModelTransform2D, Mesh2D> Shape2D;

} // namespace Blob::Core

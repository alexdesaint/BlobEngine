#pragma once

#include <list>
#include <unordered_map>

#include <Blob/Core/Primitive.hpp>

namespace Blob {

class Mesh {
    friend class Window;

private:
    std::list<const Primitive *> primitives;
    std::list<const Primitive *> transparentPrimitives;

public:
    Mesh() = default;
    Mesh(const Mesh &) = delete;
    Mesh(Mesh &&) = delete;
    explicit Mesh(const Primitive &r);

    void addPrimitive(const Primitive &r);
    void addPrimitive(const Primitive *r);

    void removePrimitive(const Primitive &r);
    void removePrimitive(const Primitive *r);

    void addTransparentPrimitive(const Primitive &r);
    void addTransparentPrimitive(const Primitive *r);

    void removeTransparentPrimitive(const Primitive &r);
    void removeTransparentPrimitive(const Primitive *r);

    void getDrawCallList(
        std::unordered_map<const Primitive *, std::vector<Mat4>> &drawCallList,
        Mat4 transform = Mat4()) const;
};

class Mesh2D {
    friend class Window;

private:
    std::list<const Primitive2D *> primitives;
    std::list<const Primitive2D *> transparentPrimitives;

public:
    Mesh2D() = default;
    Mesh2D(const Mesh &) = delete;
    Mesh2D(Mesh2D &&) = delete;
    explicit Mesh2D(const Primitive2D &r);

    void addPrimitive(const Primitive2D &r);
    void addPrimitive(const Primitive2D *r);

    void removePrimitive(const Primitive2D &r);
    void removePrimitive(const Primitive2D *r);

    void addTransparentPrimitive(const Primitive2D &r);
    void addTransparentPrimitive(const Primitive2D *r);

    void removeTransparentPrimitive(const Primitive2D &r);
    void removeTransparentPrimitive(const Primitive2D *r);
};
} // namespace Blob

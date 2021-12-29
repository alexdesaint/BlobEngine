#pragma once

#include <list>
#include <unordered_map>

#include <Blob/Core/DynamicDrawCallList.hpp>
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
    void removeAllPrimitive();

    void addTransparentPrimitive(const Primitive &r);
    void addTransparentPrimitive(const Primitive *r);

    void removeTransparentPrimitive(const Primitive &r);
    void removeTransparentPrimitive(const Primitive *r);

    void getDrawCallList(
        std::unordered_map<const GL::VertexArrayObject *,
                           std::pair<std::vector<Mat4>,
                                     std::deque<RenderOptions>>> &drawCallList,
        Mat4 transform = {}) const;

    void addToDynamicDrawCallList(DynamicDrawCallList &dynamicDrawCallList,
                                  Mat4 transform = {},
                                  void *id = nullptr) const;
    void removeFromDynamicDrawCallList(DynamicDrawCallList &dynamicDrawCallList,
                                       void *id = nullptr) const;

    friend std::ostream &operator<<(std::ostream &s, const Mesh &a);
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

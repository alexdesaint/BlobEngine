#pragma once

#include <Blob/Core/Mesh.hpp>

namespace Blob {

class Shape : public ModelTransform {
    friend Window;

private:
    const Mesh *mesh = nullptr;
    std::list<const Shape *> shapes;

public:
    Shape() = default;
    Shape(const Shape &) = delete;
    Shape(Shape &&) = delete;
    explicit Shape(const ModelTransform &args);
    explicit Shape(const Mesh &r);
    Shape(const Mesh &r, const ModelTransform &args);

    void setMesh(Mesh &r);
    void setMesh(Mesh *r);

    void removeMesh();

    void addChild(Shape *r);
    void addChild(Shape &r);

    void removeChild(Shape &r);
    void removeChild(Shape *r);

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

    friend std::ostream &operator<<(std::ostream &s, const Shape &a);
};

class Shape2D : public ModelTransform2D {
    friend Window;

private:
    const Mesh2D *mesh = nullptr;
    std::list<Shape2D *> shapes;

public:
    Shape2D() = default;
    Shape2D(const Shape2D &) = delete;
    Shape2D(Shape2D &&) = delete;
    explicit Shape2D(const ModelTransform2D &args);
    explicit Shape2D(const Mesh2D &r);
    Shape2D(const Mesh2D &r, const ModelTransform2D &args);

    void setMesh(Mesh2D &r);
    void setMesh(Mesh2D *r);

    void removeMesh();

    void addChild(Shape2D *r);
    void addChild(Shape2D &r);

    void removeChild(Shape2D &r);
    void removeChild(Shape2D *r);

    friend std::ostream &operator<<(std::ostream &s, const Shape2D &a);
};

} // namespace Blob

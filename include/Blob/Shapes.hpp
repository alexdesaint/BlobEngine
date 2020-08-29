#pragma once

#include <Blob/Exception.hpp>
#include <Blob/Mesh.hpp>
#include <Blob/Shapes.hpp>

#include <iostream>

namespace Blob::Shapes {

void init();

void destroy();

class Cube : public Mesh {
public:
    explicit Cube(const Material &material);
};

class Plane : public Mesh {
public:
    explicit Plane(const Material &material);
};

class OctagonalPrism : public Mesh {
public:
    explicit OctagonalPrism(const Material &material);
};
} // namespace Blob::Shapes

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
    explicit Cube(const Material &singleColorMaterial);
};

class Plane : public Mesh {
public:
    explicit Plane(const Material &singleColorMaterial);
};

class OctagonalPrism : public Mesh {
public:
    explicit OctagonalPrism(const Material &singleColorMaterial);
};
} // namespace Blob::Shapes

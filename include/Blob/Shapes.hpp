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
    explicit Cube(const SingleColorMaterial &singleColorMaterial);
};

class Plane : public Mesh {
public:
    explicit Plane(const SingleColorMaterial &singleColorMaterial);
};

class OctagonalPrism : public Mesh {
public:
    explicit OctagonalPrism(const SingleColorMaterial &singleColorMaterial);
};
} // namespace Blob::Shapes

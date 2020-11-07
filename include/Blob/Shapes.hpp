#pragma once

#include <Blob/Exception.hpp>
#include <Blob/Mesh.hpp>
#include <Blob/Shapes.hpp>

#include <iostream>

namespace Blob::Shapes {

void init();

void destroy();

class Cube : public Core::Mesh {
public:
    explicit Cube(const Material::Material &material);
};

class Plane : public Core::Mesh {
public:
    explicit Plane(const Material::Material &material);
};

class OctagonalPrism : public Core::Mesh {
public:
    explicit OctagonalPrism(const Material::Material &material);
};
} // namespace Blob::Shapes

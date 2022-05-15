#pragma once
#include <Blob/Mesh.hpp>
#include <Blob/Context.hpp>
namespace blenderTest::Meshes {
struct Cube : public Blob::Mesh {
    Blob::Primitive ArrayColor;
    Cube(Blob::Context &context);
};
struct Cylinder : public Blob::Mesh {
    Blob::Primitive PinkMaterial;
    Cylinder(Blob::Context &context);
};
struct Sphere : public Blob::Mesh {
    Blob::Primitive Blue;
    Sphere(Blob::Context &context);
};
}

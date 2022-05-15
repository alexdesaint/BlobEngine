#pragma once
#include <Blob/Shape.hpp>
#include <blenderTest/Meshes.hpp>
namespace blenderTest::Shapes {
struct Sphere : public Blob::Shape {
    Meshes::Sphere mesh_Sphere;
    Sphere(Blob::Context &context): mesh_Sphere(context), Blob::Shape(mesh_Sphere, Blob::ModelTransform{{1.0, 0.0, 0.0, 0.0}, {0.0, 1.0, 0.0, -3.0}, {0.0, 0.0, 1.0, 0.0}, {0.0, 0.0, 0.0, 1.0}}){}
};
}

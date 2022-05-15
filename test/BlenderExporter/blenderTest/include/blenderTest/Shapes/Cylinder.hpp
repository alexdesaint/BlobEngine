#pragma once
#include <Blob/Shape.hpp>
#include <blenderTest/Meshes.hpp>
namespace blenderTest::Shapes {
struct Cylinder : public Blob::Shape {
    Meshes::Cylinder mesh_Cylinder;
    Cylinder(Blob::Context &context): mesh_Cylinder(context), Blob::Shape(mesh_Cylinder, Blob::ModelTransform{{1.0, 0.0, 0.0, 0.0}, {0.0, 1.0, 0.0, 3.0}, {0.0, 0.0, 1.0, 0.0}, {0.0, 0.0, 0.0, 1.0}}){}
};
}

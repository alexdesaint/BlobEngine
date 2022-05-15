#pragma once
#include <Blob/Shape.hpp>
#include <blenderTest/Meshes.hpp>
namespace blenderTest::Shapes {
struct Cube : public Blob::Shape {
    Meshes::Cube mesh_Cube;
    Cube(Blob::Context &context): mesh_Cube(context), Blob::Shape(mesh_Cube, Blob::ModelTransform{{1.0, 0.0, 0.0, 0.0}, {0.0, 1.0, 0.0, 0.0}, {0.0, 0.0, 1.0, 0.0}, {0.0, 0.0, 0.0, 1.0}}){}
};
}

#pragma once
#include <blenderTest/Meshes/Cube.hpp>
#include <blenderTest/Meshes/Cylinder.hpp>
#include <blenderTest/Meshes/Sphere.hpp>
namespace blenderTest::Meshes {

struct BlenderProperties {
    std::string_view name;
    Blob::Mesh (*get)(Blob::Context &);

    constexpr BlenderProperties(std::string_view name,
                               Blob::Mesh (*get)(Blob::Context &)) :
        name(name), get(get) {}
};
constexpr std::array<BlenderProperties, 3> getAllMeshes(){
    return {
        BlenderProperties{Cube::name, &Cube::get},
        BlenderProperties{Cylinder::name, &Cylinder::get},
        BlenderProperties{Sphere::name, &Sphere::get},
    };
}
}

#pragma once
#include <blenderTest/Meshes/Cube.hpp>
#include <blenderTest/Meshes/Cylinder.hpp>
#include <blenderTest/Meshes/Sphere.hpp>
namespace blenderTest::Meshes {

struct BlenderPropertie {
    std::string_view name;
    Blob::Mesh (*get)(Blob::Context &);

    constexpr BlenderPropertie(std::string_view name,
                               Blob::Mesh (*get)(Blob::Context &)) :
        name(name), get(get) {}
};
constexpr std::array<BlenderPropertie, 3> getAllMeshes(){
    return {
        BlenderPropertie{Cube::name, &Cube::get},
        BlenderPropertie{Cylinder::name, &Cylinder::get},
        BlenderPropertie{Sphere::name, &Sphere::get},
    };
}
}

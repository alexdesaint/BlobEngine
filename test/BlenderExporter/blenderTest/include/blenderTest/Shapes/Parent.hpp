#pragma once
#include <Blob/Shape.hpp>
#include <blenderTest/Meshes.hpp>
#include <blenderTest/Shapes/Cube.hpp>
#include <blenderTest/Shapes/Cylinder.hpp>
#include <blenderTest/Shapes/Sphere.hpp>
namespace blenderTest::Shapes {
struct Parent {
    constexpr static std::string_view name{"Parent"};
    constexpr static std::string_view getStringProperties(std::string_view key)    {
        if (key == "prop") return "test 1";
        return "";
    }
    static Blob::Shape get(Blob::Context &context)    {
        return {
            {
                Shapes::Cube::get(context),
                Shapes::Cylinder::get(context),
                Shapes::Sphere::get(context),
            },
            {
                {1.0, 0.0, 0.0, 0.0},
                {0.0, 1.0, 0.0, 0.0},
                {0.0, 0.0, 1.0, 0.0},
                {0.0, 0.0, 0.0, 1.0},
            },
        };
    }
};
}

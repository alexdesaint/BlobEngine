#pragma once
#include <Blob/Shape.hpp>
#include <blenderTest/Meshes.hpp>
namespace blenderTest::Shapes {
struct Cylinder {
    constexpr static std::string_view name{"Cylinder"};
    constexpr static std::string_view getStringProperties(std::string_view key)    {
        return "";
    }
    static Blob::Shape get(Blob::Context &context)    {
        return {
            Meshes::Cylinder::get(context),
            {
            },
            {
                {1.0, 0.0, 0.0, 0.0},
                {0.0, 1.0, 0.0, 3.0},
                {0.0, 0.0, 1.0, 0.0},
                {0.0, 0.0, 0.0, 1.0},
            },
        };
    }
};
}

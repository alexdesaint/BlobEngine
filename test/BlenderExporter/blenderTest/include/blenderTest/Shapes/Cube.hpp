#pragma once
#include <Blob/Shape.hpp>
#include <blenderTest/Meshes.hpp>
namespace blenderTest::Shapes {
struct Cube {
    constexpr static std::string_view name{"Cube"};
    constexpr static std::string_view getStringProperties(std::string_view key)    {
        return "";
    }
    static Blob::Shape get(Blob::Context &context)    {
        return {
            Meshes::Cube::get(context),
            {
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

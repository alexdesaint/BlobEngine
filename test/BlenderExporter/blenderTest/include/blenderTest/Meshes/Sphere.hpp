#pragma once
#include <Blob/Mesh.hpp>
#include <Blob/Context.hpp>
namespace blenderTest::Meshes {
struct Sphere {
    constexpr static std::string_view name{"Sphere"};
    constexpr static std::string_view getStringProperties(std::string_view key)    {
        return "";
    }
    static Blob::Mesh get(Blob::Context &context);
};
}

#pragma once
#include <Blob/Mesh.hpp>
#include <Blob/Context.hpp>
namespace blenderTest::Meshes {
struct Cylinder {
    constexpr static std::string_view name{"Cylinder"};
    constexpr static std::string_view getStringProperties(std::string_view key)    {
        if (key == "test 2") return "oui";
        return "";
    }
    static Blob::Mesh get(Blob::Context &context);
};
}

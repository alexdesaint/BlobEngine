#include <Blob/Buffer.hpp>
#include <Blob/Context.hpp>
#include <Blob/Exception.hpp>
#include <Blob/Materials.hpp>
#include <Blob/OrbitCamera.hpp>
#include <Blob/Window.hpp>
#include <blenderTest/Meshes.hpp>
#include <blenderTest/Shapes/Parent.hpp>
#include <cassert>
#include <imgui.h>

// blender -b test/BlenderExporter/blenderTest.blend -P BlobBlender.py

constexpr blenderTest::Meshes::BlenderProperties func() {
    auto prop = blenderTest::Meshes::getAllMeshes();

    for (const auto &blenderProperties : prop)
        if (blenderProperties.name == "Cylinder")
            return blenderProperties;

    return blenderTest::Meshes::BlenderProperties{"ERROR", nullptr};
}

static_assert(func().name != "ERROR", "Error could not find the mesh");

int main() {
    static constexpr auto size = func();
    std::cout << size.name << std::endl;
    Blob::Window window;
    Blob::Context &context = window.context;

    auto parent = blenderTest::Shapes::Parent::get(context);

    Blob::OrbitCamera camera{window.context, {}, 5};
    camera.sensibility = 200;

    while (window.isOpen) {
        ImGui::ShowDemoWindow();
        window.draw(parent);

        window.display(camera);
    }
}

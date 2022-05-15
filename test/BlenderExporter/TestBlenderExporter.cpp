#include <Blob/Buffer.hpp>
#include <Blob/Context.hpp>
#include <Blob/Exception.hpp>
#include <Blob/Materials.hpp>
#include <Blob/OrbitCamera.hpp>
#include <Blob/Window.hpp>
#include <blenderTest/Shapes/Cube.hpp>
#include <blenderTest/Shapes/Cylinder.hpp>
#include <blenderTest/Shapes/Sphere.hpp>
#include <imgui.h>

// blender -b libs/BlobEngine/test/BlenderExporter/blenderTest.blend -P
// libs/BlobEngine/BlobBlender.py

int main() {
    Blob::Window window;
    Blob::Context &context = window.context;

    blenderTest::Shapes::Cube cube{context};
    blenderTest::Shapes::Cylinder cylinder{context};
    blenderTest::Shapes::Sphere sphere{context};

    Blob::OrbitCamera camera{{}, 5};
    camera.sensibility = 200;

    while (window.isOpen) {
        ImGui::ShowDemoWindow();
        window.draw(cube);
        window.draw(cylinder);
        window.draw(sphere);

        window.display(camera);
    }
}

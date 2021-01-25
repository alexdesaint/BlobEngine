#include <Blob/AssetManager.hpp>
#include <Blob/Core/Exception.hpp>
#include <Blob/Core/Window.hpp>
#include <Blob/Time.hpp>
#include <imgui.h>
#include <iostream>

using namespace std;
using namespace Blob;
using namespace Core;

int main() {
    try {

        Camera camera;

        Window window(camera, false);
        AssetManager assetManager;

        Materials::PBRSingleColor blue, orange, white;
        blue.albedo = Color::DeepSkyBlue;
        orange.albedo = Color::Coral;
        white.albedo = Color::White;

        Shapes::Cube cubeOrange(orange), cubeBlue(blue), cubeDm(orange);
        Shapes::OctagonalPrism opOrange(orange), opBlue(blue);
        Shapes::Plane p(white);

        std::vector<Shape> shapes = {
            Shape(cubeOrange, {4, 0}),       Shape(cubeBlue, {4, 4, 0}),   Shape(opOrange, {0, 4, 0}),  Shape(opBlue, {-4, 4, 0}),
            Shape(cubeDm, {-4, 0, 0}),       Shape(cubeBlue, {-4, -4, 0}), Shape(opOrange, {0, -4, 0}), Shape(opBlue, {4, -4, 0}),

            Shape(p, {0, 0, -1}, {5, 5, 5}),
        };

        camera.setPosition({10, 0, 10});

        Time::TimePoint start = Time::now();
        while (window.isOpen()) {
            Time::Duration flow = start - Time::now();

            ImGui::Begin("Hello, world!");
            ImGui::Text("Material");
            ImGui::ColorEdit3("albedo", &orange.albedo.R);
            ImGui::SliderFloat("metallic", &orange.metallic, 0.0f, 1.0f);
            ImGui::SliderFloat("roughness", &orange.roughness, 0.0f, 1.0f);
            ImGui::SliderFloat("ao", &orange.ao, 0.0f, 1.f);

            ImGui::Text("Light");
            ImGui::ColorEdit3("Light color", &Materials::PBR::light.color.R);
            ImGui::SliderFloat("Light power", &Materials::PBR::light.power, 1.0f, 1000.f);
            ImGui::SliderFloat("Light radius", &Materials::PBR::light.radius, 0.1f, 10.0f);
            ImGui::SliderFloat3("Light Position", &Materials::PBR::light.position.x, -1.0f, 1.0f);
            ImGui::End();

            for (const auto &s : shapes)
                window.draw(s);

            window.display();
        }

    } catch (Exception &exception) { cout << exception.what() << std::endl; }

    return 0;
}

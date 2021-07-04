#include <Blob/Core/Exception.hpp>
#include <Blob/Core/Window.hpp>
#include <Blob/Materials.hpp>
#include <Blob/Shapes.hpp>
#include <Blob/Time.hpp>
#include <imgui.h>
#include <iostream>

using namespace std;
using namespace Blob;

int main() {
    try {

        Window window;

        Materials::PBRSingleColor blue, orange, white;
        blue.albedo = Color::DeepSkyBlue;
        orange.albedo = Color::Coral;
        white.albedo = Color::White;

        Scene scene;
        Shapes::Cube cubeOrange(orange), cubeBlue(blue), cubeDm(orange);
        scene.addShape(cubeOrange);
        cubeOrange.setPosition({4, 4});
        scene.addShape(cubeBlue);
        cubeBlue.setPosition({4, 0});
        scene.addShape(cubeDm);
        cubeDm.setPosition({4, -4});
        Shapes::OctagonalPrism opOrange(orange), opBlue(blue), opDm(orange);
        scene.addShape(opOrange);
        opOrange.setPosition({-4, 4});
        scene.addShape(opBlue);
        opBlue.setPosition({-4, 0});
        scene.addShape(opDm);
        opDm.setPosition({-4, -4});

        Shapes::Plane p(white);
        p.setPosition({0, 0, -1});
        p.setScale({5, 5, 5});
        scene.addShape(p);

        scene.camera.setPosition({10, 0, 10});

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
            ImGui::SliderFloat("Light power",
                               &Materials::PBR::light.power,
                               1.0f,
                               1000.f);
            ImGui::SliderFloat("Light radius",
                               &Materials::PBR::light.radius,
                               0.1f,
                               10.0f);
            ImGui::SliderFloat3("Light Position",
                                &Materials::PBR::light.position.x,
                                -1.0f,
                                1.0f);
            ImGui::End();

            window.draw(scene);

            window.display();
        }

    } catch (Exception &exception) { cout << exception.what() << std::endl; }

    return 0;
}

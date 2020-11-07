#include <Blob/Shapes.hpp>

#include <Blob/Camera.hpp>
#include <Blob/Exception.hpp>
#include <Blob/Time.hpp>
#include <Blob/Window.hpp>
#include <imgui.h>
#include <iostream>

/* Rename this TestMaterials
 * add Texture test
 *
 * with normal and w/ normal
 */

using namespace std;
using namespace Blob;
using namespace Shapes;
using namespace Core;
using namespace Material;

int main(int argc, char *argv[]) {
    try {

        Camera camera;

        Window window(camera, false);

        SingleColorMaterial blue, orange;
        blue.albedo = Color::DeepSkyBlue;
        orange.albedo = Color::Coral;

        Cube cubeOrange(orange), cubeBlue(blue), cubeDm;
        OctagonalPrism opOrange(orange), opBlue(blue);
        Plane p(blue);

        Shape s(cubeOrange, {4, 0});

        std::vector<Shape> shapes = {
            Shape(cubeOrange, {4, 0}),
            Shape(cubeBlue, {4, 4, 0}),
            Shape(opOrange, {0, 4, 0}),
            Shape(opBlue, {-4, 4, 0}),
            Shape(cubeDm, {-4, 0, 0}),
            Shape(cubeBlue, {-4, -4, 0}),
            Shape(opOrange, {0, -4, 0}),
            Shape(opBlue, {4, -4, 0}),

            Shape(p, {0, 0, -1}, {10, 10, 10}),
        };

        camera.setPosition({10, 0, 10});

        Time::TimePoint start = Time::now();
        while (window.isOpen()) {
            Time::Duration flow = start - Time::now();
            float angle = flow.count();

            ImGui::Begin("Hello, world!");
            ImGui::Text("Material");
            ImGui::ColorEdit3("albedo", &orange.albedo.R);
            ImGui::SliderFloat("metallic", &orange.metallic, 0.0f, 1.0f);
            ImGui::SliderFloat("roughness", &orange.roughness, 0.0f, 1.0f);
            ImGui::SliderFloat("ao", &orange.ao, 0.0f, 1.f);

            bool opt = (orange.options & orange.Options.Irradiance) != 0;
            if (ImGui::Checkbox("Irradiance", &opt)) {
                if (opt)
                    orange.options |= orange.Options.Irradiance;
                else
                    orange.options &= ~orange.Options.Irradiance;
            }

            opt = (orange.options & orange.Options.Radiance) != 0;
            if (ImGui::Checkbox("Radiance", &opt)) {
                if (opt)
                    orange.options |= orange.Options.Radiance;
                else
                    orange.options &= ~orange.Options.Radiance;
            }

            ImGui::Text("Light");
            ImGui::ColorEdit3("Light color", &SingleColorMaterial::light.color.R);
            ImGui::SliderFloat("Light Position X", &SingleColorMaterial::light.position.x, -1.0f, 1.0f);
            ImGui::SliderFloat("Light Position Y", &SingleColorMaterial::light.position.y, -1.0f, 1.0f);
            ImGui::SliderFloat("Light Position Z", &SingleColorMaterial::light.position.z, -1.0f, 1.0f);
            ImGui::End();

            for (const auto &s : shapes)
                window.draw(s);

            window.display();
        }

    } catch (Exception &exception) { cout << exception.what() << std::endl; }

    return 0;
}

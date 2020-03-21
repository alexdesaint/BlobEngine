//#include <Blob/Core.hpp>
#include <Blob/Shapes.hpp>

#include <Blob/Camera.hpp>
#include <Blob/Exception.hpp>
#include <Blob/Time.hpp>
#include <Blob/Window.hpp>
#include <imgui.h>
#include <iostream>

using namespace std;
using namespace Blob;
using namespace Blob::Shapes;
using namespace GL;

int main(int argc, char *argv[]) {
    try {

        Camera camera;

        Window window(camera, false);
        Cube c1, c2;

        c1.singleColorMaterial.ambient = Color::White;

        // c2.singleColorMaterial.ambient = Color::Coral;

        // c2.setPosition(0.f, -2.f, 0.f);
        // c2.setScale(4, 1, 1);

        // list<Cube> cubeList;

        // cubeList.emplace_back();

        // Plane p;

        // p.move(0, 2, 0);
        // p.setScale(2, 2, 2);
        // p.singleColorMaterial.ambient = Color::White;

        // OctagonalPrism op;

        camera.setPosition(-3, -3, -3);

        Time::TimePoint start = Time::now();

        float cameraX = -3, cameraY = -3, cameraZ = -3;
        while (window.isOpen()) {
            Time::Duration flow = start - Time::now();
            float angle = flow.count();

            ImGui::Begin("Hello, world!");
            ImGui::Text("Material");
            ImGui::ColorEdit3("Material ambient", &c2.singleColorMaterial.ambient.R);
            ImGui::ColorEdit3("Material diffuse", &c2.singleColorMaterial.diffuse.R);
            ImGui::ColorEdit3("Material specular", &c2.singleColorMaterial.specular.R);
            ImGui::SliderFloat("Material shininess", &c2.singleColorMaterial.shininess, 0.0f, 128.0f);
            ImGui::Text("Light");
            ImGui::ColorEdit3("Light ambient", &Blob::Shapes::SingleColorMaterial::light.ambient.R);
            ImGui::ColorEdit3("Light diffuse", &Blob::Shapes::SingleColorMaterial::light.diffuse.R);
            ImGui::ColorEdit3("Light specular", &Blob::Shapes::SingleColorMaterial::light.specular.R);
            ImGui::SliderFloat("Light Position X", &Blob::Shapes::SingleColorMaterial::light.position.x, -3.0f, 3.0f);
            ImGui::SliderFloat("Light Position Y", &Blob::Shapes::SingleColorMaterial::light.position.y, -3.0f, 3.0f);
            ImGui::SliderFloat("Light Position Z", &Blob::Shapes::SingleColorMaterial::light.position.z, -3.0f, 3.0f);
            ImGui::Text("Camera");
            if(
            ImGui::SliderFloat("Camera Position X", &cameraX, -3.0f, 3.0f) ||
            ImGui::SliderFloat("Camera Position Y", &cameraY, -3.0f, 3.0f) ||
            ImGui::SliderFloat("Camera Position Z", &cameraZ, -3.0f, 3.0f))
                camera.setPosition(cameraX, cameraY, cameraZ);
            ImGui::End();
            c1.setPosition(Blob::Shapes::SingleColorMaterial::light.position.x, Blob::Shapes::SingleColorMaterial::light.position.y,
                           Blob::Shapes::SingleColorMaterial::light.position.z);
            c2.setRotation(angle, 0.f, 0.f, 1.f);

            window.draw(c1);
            window.draw(c2);

            // window.draw(p);

            // op.setRotation(angle, 0.f, 0.f, 1.f);
            // window.draw(op);

            window.display();
        }

    } catch (Exception &exception) { cout << exception.what() << std::endl; }

    return 0;
}

#include <Blob/GL/Core.hpp>
#include <Blob/Shapes.hpp>

#include <Blob/Exception.hpp>
#include <Blob/Time.hpp>
#include <iostream>

#include <glad/glad.h>
#include <imgui.h>

using namespace std;
using namespace Blob;
using namespace Blob::GL;

int main(int argc, char *argv[]) {

    try {
        Core graphic(false);

        Texture t("data/cube.bmp"), white(255, 255, 255);

        graphic.setCameraPosition(5, 0, 5);

        Time::TimePoint start = Time::now();

        // Demo window init
        bool show_demo_window = true;
        bool show_another_window = false;
        ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

        while (graphic.isOpen()) {
            graphic.clear();

            Time::Duration flow = start - Time::now();
            float angle = flow.count();

            {
                auto view = registry.view<Movable>();
                for (auto en : view) {
                    auto &vel = view.get<Movable>(en);

                    vel.setRotation(angle, 0.f, 0.f, 1.f);
                }
            }

            {
                auto view = registry.view<Renderable>();
                for (auto en : view) {
                    auto &vel = view.get<Renderable>(en);

                    graphic.draw(vel);
                }
            }

            // imgui /////////////////////////////////////

            ImGui::NewFrame();

            if (show_demo_window)
                ImGui::ShowDemoWindow(&show_demo_window);

            // 2. Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
            {
                static float f = 0.0f;
                static int counter = 0;

                ImGui::Begin("Hello, world!"); // Create a window called "Hello, world!" and append into it.

                ImGui::Text("This is some useful text.");          // Display some text (you can use a format strings too)
                ImGui::Checkbox("Demo Window", &show_demo_window); // Edit bools storing our window open/close state
                ImGui::Checkbox("Another Window", &show_another_window);

                ImGui::SliderFloat("float", &f, 0.0f, 1.0f);              // Edit 1 float using a slider from 0.0f to 1.0f
                ImGui::ColorEdit3("clear color", (float *) &clear_color); // Edit 3 floats representing a color

                if (ImGui::Button("Button")) // Buttons return true when clicked (most widgets return true when edited/activated)
                    counter++;
                ImGui::SameLine();
                ImGui::Text("counter = %d", counter);

                ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
                ImGui::End();
            }

            // 3. Show another simple window.
            if (show_another_window) {
                ImGui::Begin("Another Window", &show_another_window); // Pass a pointer to our bool variable (the window will have a closing button
                                                                      // that will clear the bool when clicked)
                ImGui::Text("Hello from another window!");
                if (ImGui::Button("Close Me"))
                    show_another_window = false;
                ImGui::End();
            }

            graphic.drawImGUI();
            graphic.display();
        }

    } catch (Exception &exception) { cout << exception.what() << std::endl; }

    return 0;
}

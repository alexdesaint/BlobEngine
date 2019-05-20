#include <Blob/GL/Graphic.hpp>
#include <Blob/GL/Shapes.hpp>

#include <Blob/Time.hpp>
#include <Blob/Exception.hpp>
#include <iostream>

#include <imgui.h>
#include <glad/glad.h>

using namespace std;
using namespace Blob;
using namespace Blob::GL;
using namespace Blob::GL::Shapes;

int main(int argc, char *argv[]) {

	try {
		Graphic graphic(false);

		Cube c1, c2;

        Texture t("data/cube.bmp"), white(255, 255, 255);
		
		c1.setPosition(-5.f, 0.f, 0.f);

        c1.setTexture(t);
		c2.setPosition(0.f, -2.f, 0.f);
		c2.setScale(4, 1, 1);

		list<Cube> cubeList;

		cubeList.emplace_back();

		Plane p;

		p.move(0, 2, 0);
		p.setScale(2, 2, 2);
        p.setTexture(white);

		OctagonalPrism op;

		graphic.setCameraPosition(5, 0, 5);

		Time::TimePoint start = Time::now();

		//Demo window init
		bool show_demo_window = true;
		bool show_another_window = false;
		ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

		while (graphic.isOpen()) {
			graphic.clear();

			Time::Duration flow = start - Time::now();
			float angle = flow.count();

            c1.setRotation(angle, 0.f, 0.f, 1.f);

			graphic.draw(c1);
			graphic.draw(c2);

			graphic.draw(p);

			//graphic.draw(text);

            op.setRotation(angle, 0.f, 0.f, 1.f);
			graphic.draw(op);

			//imgui /////////////////////////////////////

			ImGui::NewFrame();

			if (show_demo_window)
				ImGui::ShowDemoWindow(&show_demo_window);

			// 2. Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
			{
				static float f = 0.0f;
				static int counter = 0;

				ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

				ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
				ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
				ImGui::Checkbox("Another Window", &show_another_window);

				ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
				ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

				if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
					counter++;
				ImGui::SameLine();
				ImGui::Text("counter = %d", counter);

				ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
				ImGui::End();
			}

			// 3. Show another simple window.
			if (show_another_window)
			{
				ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
				ImGui::Text("Hello from another window!");
				if (ImGui::Button("Close Me"))
					show_another_window = false;
				ImGui::End();
			}

			graphic.drawImGUI();
			graphic.display();
		}

	} catch (Exception &exception) {
		cout << exception.what() << std::endl;
	}

	return 0;
}

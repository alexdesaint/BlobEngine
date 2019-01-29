#include <BlobEngine/BlobGL/Graphic.hpp>
#include <BlobEngine/BlobGL/Form.hpp>
#include <BlobEngine/BlobGL/Text.hpp>

#include <BlobEngine/Time.hpp>
#include <BlobEngine/BlobException.hpp>
#include <iostream>

#include <imgui.h>

using namespace std;
using namespace Blob;
using namespace Blob::GL;

int main(int argc, char *argv[]) {

	ImGui::CreateContext();
	ImGui::StyleColorsDark();

	try {
		Graphic graphic(false);
		ShaderProgram shaderProgram("data/vertex.glsl", "data/fragment.glsl");
		ShaderProgram shaderProgram2D("data/vertex2D.glsl", "data/fragment2D.glsl");

		Texture fontTexture;
		ImGuiIO& io = ImGui::GetIO();

		if(!io.Fonts->IsBuilt())
			cout << "Font not Build" << endl;

		unsigned char* pixels;
		int width, height;
		io.Fonts->GetTexDataAsRGBA32(&pixels, &width, &height);
		fontTexture.setRGBA32data(pixels, width, height);

		io.Fonts->TexID = (ImTextureID)(intptr_t)fontTexture.getTextureID();

		io.DisplaySize = ImVec2(graphic.getSize().x, graphic.getSize().y);
		io.DisplayFramebufferScale = ImVec2(graphic.getFrameBufferSize().x, graphic.getFrameBufferSize().y);

		Cube c1, c2;

		c1.setPosition(-5.f, 0.f, 0.f);

		c1.loadBMP("data/cube.bmp");
		c2.setPosition(0.f, -2.f, 0.f);
		c2.setScale(4, 1, 1);
		//c2.setColor(100, 0, 0);

		list<Cube> cubeList;

		cubeList.emplace_back();

		Plane p;

		p.move(0, 2, 0);
		p.setScale(2, 2, 2);
		p.setColor(255, 255, 255);

		OctagonalPrism op;

		graphic.setCameraPosition(5, 0, 5);

		Time::TimePoint start = Time::now();

		Text::Text text("BLOBENGINE, alexandredlsb@gmail.com");
		text.setScale(0.1, 0.1, 1);
		text.setPosition(-1, 0.9, 0);

		bool show_demo_window = true;

		VertexBufferObject imguiVBO;

		Renderable imguiRenderable;

		while (graphic.isOpen()) {
			graphic.clear();

			Time::Duration flow = start - Time::now();
			float angle = flow.count();

			c1.setRotation(angle * 40, 0.f, 0.f, 1.f);

			graphic.draw(c1, shaderProgram);
			graphic.draw(c2, shaderProgram);

			graphic.draw(p, shaderProgram);

			graphic.draw(text, shaderProgram2D);

			op.setRotation(angle * 40, 0.f, 0.f, 1.f);
			graphic.draw(op, shaderProgram);

			ImGui::NewFrame();
			ImGui::ShowDemoWindow(&show_demo_window);
			ImGui::Render();
			ImDrawData *drawData = ImGui::GetDrawData();

			for (int n = 0; n < drawData->CmdListsCount; n++) {
				ImDrawList* cmd_list = drawData->CmdLists[n];

				imguiVBO.setData((uint8_t*) cmd_list->VtxBuffer.Data, cmd_list->VtxBuffer.Size * sizeof(ImDrawVert));

				imguiRenderable.setBuffer(imguiVBO, sizeof(ImDrawVert));

				for (int cmd_i = 0; cmd_i < cmd_list->CmdBuffer.Size; cmd_i++) {
					const ImDrawCmd *pcmd = &cmd_list->CmdBuffer[cmd_i];
					imguiRenderable.setTexture()
				}
			}

			graphic.display();
		}

	} catch (BlobException &exception) {
		cout << exception.what() << std::endl;
	}

	ImGui::DestroyContext();

	return 0;
}

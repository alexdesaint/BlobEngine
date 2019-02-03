#include <BlobEngine/BlobGL/Graphic.hpp>
#include <BlobEngine/BlobGL/Form.hpp>
#include <BlobEngine/BlobGL/Text.hpp>

#include <BlobEngine/Time.hpp>
#include <BlobEngine/BlobException.hpp>
#include <iostream>

#include <imgui.h>
#include <glad/glad.h>

using namespace std;
using namespace Blob;
using namespace Blob::GL;

int main(int argc, char *argv[]) {

	ImGui::CreateContext();
	ImGui::StyleColorsDark();

	try {
		Graphic graphic(false);
		ShaderProgram shaderProgram("data/vertex.glsl", "data/fragment.glsl");

		//imGUI init
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

		//

		Cube c1(&shaderProgram), c2(&shaderProgram);

		c1.setPosition(-5.f, 0.f, 0.f);

		c1.loadBMP("data/cube.bmp");
		c2.setPosition(0.f, -2.f, 0.f);
		c2.setScale(4, 1, 1);

		list<Cube> cubeList;

		cubeList.emplace_back(&shaderProgram);

		Plane p(&shaderProgram);

		p.move(0, 2, 0);
		p.setScale(2, 2, 2);
		p.setColor(255, 255, 255);

		OctagonalPrism op(&shaderProgram);

		graphic.setCameraPosition(5, 0, 5);

		Time::TimePoint start = Time::now();

		Text::Text text("BLOBENGINE, alexandredlsb@gmail.com");
		text.setScale(0.1, 0.1, 1);
		text.setPosition(-1, 0.9, 0);

		bool show_demo_window = true;

		VertexBufferObject imguiVBO;

		Renderable imguiRenderable;
		imguiRenderable.setShaderProgram(&shaderProgram2D);
		imguiRenderable.setArrayVAO(2, "Position", GL_FLOAT, (uint32_t)offsetof(ImDrawVert, pos));
		imguiRenderable.setArrayVAO(2, "TexturePosition", GL_FLOAT, (uint32_t)offsetof(ImDrawVert, uv));
		imguiRenderable.setArrayVAO(4, "Color", GL_UNSIGNED_BYTE, (uint32_t)offsetof(ImDrawVert, col), true);

		while (graphic.isOpen()) {
			graphic.clear();

			Time::Duration flow = start - Time::now();
			float angle = flow.count();

			c1.setRotation(angle * 40, 0.f, 0.f, 1.f);

			graphic.draw(c1);
			graphic.draw(c2);

			graphic.draw(p);

			//graphic.draw(text);

			op.setRotation(angle * 40, 0.f, 0.f, 1.f);
			graphic.draw(op);

			//imgui draw call

			ImGui::NewFrame();
			{
				static float f = 0.0f;
				static int counter = 0;

				ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

				ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
				ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
				ImGui::Checkbox("Another Window", &show_demo_window);

				ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
				ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

				if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
					counter++;
				ImGui::SameLine();
				ImGui::Text("counter = %d", counter);

				ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
				ImGui::End();
			}

			ImGui::Render();
			ImDrawData *drawData = ImGui::GetDrawData();

			ImVec2 pos = drawData->DisplayPos;

			for (int n = 0; n < drawData->CmdListsCount; n++) {
				ImDrawList* cmd_list = drawData->CmdLists[n];
				const ImDrawIdx* idx_buffer_offset = 0;

				imguiVBO.setData((uint8_t*) cmd_list->VtxBuffer.Data, cmd_list->VtxBuffer.Size * sizeof(ImDrawVert));

				imguiRenderable.setBuffer(imguiVBO, sizeof(ImDrawVert));

				for (int cmd_i = 0; cmd_i < cmd_list->CmdBuffer.Size; cmd_i++) {
					const ImDrawCmd *pcmd = &cmd_list->CmdBuffer[cmd_i];
					ImVec4 clip_rect = ImVec4(pcmd->ClipRect.x - pos.x, pcmd->ClipRect.y - pos.y, pcmd->ClipRect.z - pos.x, pcmd->ClipRect.w - pos.y);

					//glScissor((int)clip_rect.x, (int)(fb_height - clip_rect.w), (int)(clip_rect.z - clip_rect.x), (int)(clip_rect.w - clip_rect.y));

					glBindTexture(GL_TEXTURE_2D, (GLuint)(intptr_t)pcmd->TextureId);
					//glDrawElements(GL_TRIANGLES, (GLsizei)pcmd->ElemCount, GL_UNSIGNED_SHORT, idx_buffer_offset);
					graphic.draw(imguiRenderable);

					idx_buffer_offset += pcmd->ElemCount;
				}
			}
			//

			graphic.display();
		}

	} catch (BlobException &exception) {
		cout << exception.what() << std::endl;
	}

	ImGui::DestroyContext();

	return 0;
}

#include <BlobEngine/BlobGL/Graphic.hpp>
#include <BlobEngine/BlobGL/Renderable.hpp>
#include <BlobEngine/Time.hpp>
#include <BlobEngine/BlobException.hpp>
#include <iostream>

using namespace std;
using namespace BlobEngine::BlobGL;

int main(int argc, char *argv[]) {

	try {

		Graphic graphic(640, 480);

		struct Data {
			float coor[3];
			float norm[3];
			float texCoor[2];
		};

		std::vector<Data> data = {
				// x = devant
				// y = droite
				// z = haut

				// Top face
				{{-1.0, -1.0, 1.0}, {0.0, 0.0, 1.0}, {0.25, 0.0}},		//hg
				{{1.0,  -1.0, 1.0}, {0.0, 0.0, 1.0}, {0.25, 0.25}},		//bg
				{{1.0,  1.0,  1.0}, {0.0, 0.0, 1.0}, {0.5, 0.25}},		//bd
				{{-1.0, 1.0,  1.0}, {0.0, 0.0, 1.0}, {0.5, 0.0}},		//hd

				// Bottom face
				{{-1.0, -1.0, -1.0}, {0.0, 0.0, -1.0}, {0.25, 0.75}},	//bg
				{{-1.0, 1.0,  -1.0}, {0.0, 0.0, -1.0}, {0.5, 0.75}},	//bd
				{{1.0,  1.0,  -1.0}, {0.0, 0.0, -1.0}, {0.5, 0.5}},		//hd
				{{1.0,  -1.0, -1.0}, {0.0, 0.0, -1.0}, {0.25, 0.5}},	//hg

				// Right face
				{{-1.0, 1.0,  -1.0}, {0.0, 1.0, 0.0}, {0.75, 0.5}},		//bd
				{{-1.0, 1.0,  1.0},  {0.0, 1.0, 0.0}, {0.75, 0.25}},	//hd
				{{1.0,  1.0,  1.0},  {0.0, 1.0, 0.0}, {0.5, 0.25}},		//hg
				{{1.0,  1.0,  -1.0}, {0.0, 1.0, 0.0}, {0.5, 0.5}},		//bg

				// Left face
				{{-1.0, -1.0, -1.0}, {0.0, -1.0, 0.0}, {0.0, 0.5}},		//bg
				{{1.0,  -1.0, -1.0}, {0.0, -1.0, 0.0}, {0.25, 0.5}},	//bd
				{{1.0,  -1.0, 1.0},  {0.0, -1.0, 0.0}, {0.25, 0.25}},	//hd
				{{-1.0, -1.0, 1.0},  {0.0, -1.0, 0.0}, {0.0, 0.25}},	//hg

				// Front face
				{{1.0,  -1.0, -1.0}, {1.0, 0.0, 0.0}, {0.25, 0.5}},		//bg
				{{1.0,  1.0,  -1.0}, {1.0, 0.0, 0.0}, {0.5, 0.5}},		//bd
				{{1.0,  1.0,  1.0},  {1.0, 0.0, 0.0}, {0.5, 0.25}},		//hd
				{{1.0,  -1.0, 1.0},  {1.0, 0.0, 0.0}, {0.25, 0.25}},	//hg

				// Back face
				{{-1.0, -1.0, -1.0}, {-1.0, 0.0, 0.0}, {1.0, 0.5}},		//bd
				{{-1.0, -1.0, 1.0},  {-1.0, 0.0, 0.0}, {1.0, 0.25}},	//hd
				{{-1.0, 1.0,  1.0},  {-1.0, 0.0, 0.0}, {0.75, 0.25}},	//hg
				{{-1.0, 1.0,  -1.0}, {-1.0, 0.0, 0.0}, {0.75, 0.5}}		//bg
		};

		VertexBufferObject vbo;

		vbo.setData((GLubyte*)data.data(), sizeof(Data)* data.size());

		const std::vector<GLushort> indices = {
				0, 1, 2, 0, 2, 3,    // front
				4, 5, 6, 4, 6, 7,    // back
				8, 9, 10, 8, 10, 11,   // top
				12, 13, 14, 12, 14, 15,   // bottom
				16, 17, 18, 16, 18, 19,   // right
				20, 21, 22, 20, 22, 23,   // left
		};

		Renderable shape;

		shape.setBuffer(vbo, sizeof(Data));

		shape.setPosition(3, GL_FLOAT, 0, 0);
		shape.setNormal(3, GL_FLOAT, sizeof(Data::coor), 0);
		shape.setTexture(2, GL_FLOAT, sizeof(Data::coor) + sizeof(Data::norm), 0);

		shape.setIndices((GLubyte*)indices.data(), (GLsizei)indices.size(), GL_UNSIGNED_SHORT);

		BlobEngine::BlobGL::Texture t;
		t.load("../data/cube.png");

		shape.setTexture(t);

		BlobEngine::BlobGL::ShaderProgram shaderProgram("../data/vertex.glsl", "../data/fragment.glsl");

		graphic.setCameraPosition(5, 0, 5);

		while (graphic.isOpen()) {
			graphic.clear();

			float angle = BlobEngine::getTime();

			shape.setRotation(angle * 40, 0.f, 0.f, 1.f);
			//shape.rotate(20, 1.f, 0.f, 0.f);
			//shape.setRotation(45, 0.f, 1.f, 0.f);

			//float mod = std::cos(angle) / 2 + 1;
			//shape.setScale(mod, mod, mod);

			graphic.draw(shape, shaderProgram);

			graphic.display();

		}

	} catch (BlobException &exception) {
		cout << exception.what() << std::endl;
	}

	return 0;
}
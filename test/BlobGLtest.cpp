#include <BlobEngine/BlobGL/Graphic.hpp>
#include <BlobEngine/BlobGL/Shape.hpp>
#include <BlobEngine/Time.hpp>
#include <BlobEngine/BlobException.hpp>
#include <iostream>

using namespace std;
using namespace BlobEngine::BlobGL;

int main(int argc, char *argv[]) {

	try {

		Graphic graphic(640, 480);

		const std::vector<glm::vec3> cube_vertices = {
				// Front face
				{-1.0, -1.0, 1.0},
				{1.0,  -1.0, 1.0},
				{1.0,  1.0,  1.0},
				{-1.0, 1.0,  1.0},

				// Back face
				{-1.0, -1.0, -1.0},
				{-1.0, 1.0,  -1.0},
				{1.0,  1.0,  -1.0},
				{1.0,  -1.0, -1.0},

				// Top face
				{-1.0, 1.0,  -1.0},
				{-1.0, 1.0,  1.0},
				{1.0,  1.0,  1.0},
				{1.0,  1.0,  -1.0},

				// Bottom face
				{-1.0, -1.0, -1.0},
				{1.0,  -1.0, -1.0},
				{1.0,  -1.0, 1.0},
				{-1.0, -1.0, 1.0},

				// Right face
				{1.0,  -1.0, -1.0},
				{1.0,  1.0,  -1.0},
				{1.0,  1.0,  1.0},
				{1.0,  -1.0, 1.0},

				// Left face
				{-1.0, -1.0, -1.0},
				{-1.0, -1.0, 1.0},
				{-1.0, 1.0,  1.0},
				{-1.0, 1.0,  -1.0}
		};

		const std::vector<GLushort> indices = {
				0, 1, 2, 0, 2, 3,    // front
				4, 5, 6, 4, 6, 7,    // back
				8, 9, 10, 8, 10, 11,   // top
				12, 13, 14, 12, 14, 15,   // bottom
				16, 17, 18, 16, 18, 19,   // right
				20, 21, 22, 20, 22, 23,   // left
		};

		Shape shape("../data/sphere.obj");
		//Shape shape(cube_vertices, indices);

		BlobEngine::BlobGL::ShaderProgram shaderProgram("../data/vertex.glsl", "../data/fragment.glsl");

		while (graphic.isOpen()) {
			graphic.clear();

			float angle = BlobEngine::getTime();

			shape.setRotation(angle * 40, 0.f, 1.f, 0.f);

			float mod = std::cos(angle) / 2 + 1;
			shape.setScale(mod, mod, mod);
			shape.rotate(angle * 40, 1.f, 0.f, 0.f);
			shape.setPosition(0, 1, 0);
			graphic.draw(shape, shaderProgram);

			shape.setPosition(1, 0, 0);
			graphic.draw(shape, shaderProgram);

			shape.setPosition(0, 0, 1);
			graphic.draw(shape, shaderProgram);

			graphic.display();

		}

	} catch (BlobException &exception) {
		cout << exception.what() << std::endl;
	}

	return 0;
}
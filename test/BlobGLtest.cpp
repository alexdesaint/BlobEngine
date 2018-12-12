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

		cout << graphic;

		Shape shape("../data/sphere.obj");

		BlobEngine::BlobGL::ShaderProgram shaderProgram("../data/vertex.glsl", "../data/fragment.glsl");

		graphic.draw(shape, shaderProgram);
		while (graphic.isOpen()) {
			graphic.clear();

			float angle = BlobEngine::getTime();

			float mod = std::cos(angle) / 2 + 1;

			shape.setScale(mod, mod, mod);
			shape.setRotation(angle * 40, 0.f, 1.f, 0.f);
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
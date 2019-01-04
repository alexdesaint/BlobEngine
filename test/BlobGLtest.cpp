#include <BlobEngine/BlobGL/Graphic.hpp>
#include <BlobEngine/BlobGL/Form.hpp>
#include <BlobEngine/Time.hpp>
#include <BlobEngine/BlobException.hpp>
#include <iostream>
#include <list>

using namespace std;
using namespace BlobEngine::BlobGL;

int main(int argc, char *argv[]) {

	try {

		Graphic graphic(640, 480);
		BlobEngine::BlobGL::ShaderProgram shaderProgram("../data/vertex.glsl", "../data/fragment.glsl");

		Cube c1, c2;

		c1.setPosition(-5.f, 0.f, 0.f);
		c2.setPosition(0.f, -2.f, 0.f);
		c2.setScale(4, 1, 1);

		list<Cube> cubeList;

		cubeList.emplace_back();

		Plane p;

		p.move(0, 2, 0);

		p.setScale(2,2,2);

		OctagonalPrism op;

		graphic.setCameraPosition(5, 0, 5);

		while (graphic.isOpen()) {
			graphic.clear();

			float angle = BlobEngine::getTime();

			c1.setRotation(angle * 40, 0.f, 0.f, 1.f);

			graphic.draw(c1, shaderProgram);
			graphic.draw(c2, shaderProgram);

			graphic.draw(p, shaderProgram);

			op.setRotation(angle * 40, 0.f, 0.f, 1.f);
			graphic.draw(op, shaderProgram);

			graphic.display();

		}

	} catch (BlobException &exception) {
		cout << exception.what() << std::endl;
	}

	return 0;
}

#include <BlobEngine/BlobGL/Graphic.hpp>
#include <BlobEngine/BlobGL/Form.hpp>
#include <BlobEngine/BlobGL/Text.hpp>

#include <BlobEngine/Time.hpp>
#include <BlobEngine/BlobException.hpp>
#include <iostream>

using namespace std;
using namespace BlobEngine;
using namespace BlobEngine::BlobGL;

int main(int argc, char *argv[]) {

	try {
		Graphic graphic(false);
		BlobEngine::BlobGL::ShaderProgram shaderProgram("data/vertex.glsl", "data/fragment.glsl");
		BlobEngine::BlobGL::ShaderProgram shaderProgram2D("data/vertex2D.glsl", "data/fragment2D.glsl");

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

			graphic.display();

		}

	} catch (BlobException &exception) {
		cout << exception.what() << std::endl;
	}

	return 0;
}

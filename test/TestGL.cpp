#include <Blob/GL/Graphic.hpp>
#include <Blob/GL/Shapes.hpp>

#include <Blob/Time.hpp>
#include <Blob/Exception.hpp>
#include <iostream>

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

		while (graphic.isOpen()) {
			graphic.clear();

			Time::Duration flow = start - Time::now();
			float angle = flow.count();

			c1.setRotation(angle, 0.f, 0.f, 1.f);

			graphic.draw(c1);
			graphic.draw(c2);

			graphic.draw(p);

			op.setRotation(angle, 0.f, 0.f, 1.f);
			graphic.draw(op);

			graphic.display();

		}

	} catch (Exception &exception) {
		cout << exception.what() << std::endl;
	}

	return 0;
}

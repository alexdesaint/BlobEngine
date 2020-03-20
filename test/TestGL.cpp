//#include <Blob/Core.hpp>
#include <Blob/Shapes.hpp>

#include <Blob/Camera.hpp>
#include <Blob/Exception.hpp>
#include <Blob/Time.hpp>
#include <Blob/Window.hpp>
#include <iostream>

using namespace std;
using namespace Blob;
using namespace Blob::Shapes;
using namespace GL;

int main(int argc, char *argv[]) {
    try {

        Camera camera;

        Window window(camera, false);
        Cube c1, c2;

        c1.setPosition(-5.f, 0.f, 0.f);
        c1.singleColorMaterial.color = Color::Blue;
        c2.singleColorMaterial.color = Color::Coral;

        c2.setPosition(0.f, -2.f, 0.f);
        c2.setScale(4, 1, 1);

        list<Cube> cubeList;

        cubeList.emplace_back();

        Plane p;

        p.move(0, 2, 0);
        p.setScale(2, 2, 2);
        p.singleColorMaterial.color = Color::White;

        OctagonalPrism op;

        camera.setPosition(5, 0, 5);

        Time::TimePoint start = Time::now();

        while (window.isOpen()) {
            Time::Duration flow = start - Time::now();
            float angle = flow.count();

            c1.setRotation(angle, 0.f, 0.f, 1.f);

            window.draw(c1);
            window.draw(c2);

            window.draw(p);

            op.setRotation(angle, 0.f, 0.f, 1.f);
            window.draw(op);

            window.display();
        }

    } catch (Exception &exception) { cout << exception.what() << std::endl; }

    return 0;
}

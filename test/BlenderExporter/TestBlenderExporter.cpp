#include <Blob/Buffer.hpp>
#include <Blob/Exception.hpp>
#include <Blob/Materials.hpp>
#include <Blob/Window.hpp>
#include <blenderTest/Shapes/Cube.hpp>
#include <memory>

int main() {
    Blob::Window window;

    Blob::Materials::PBRSingleColor singleColor;

    blenderTest::Shapes::Cube cube;

    Blob::Camera camera{{5, 5, 5}, {0, 0, 0}};
    float zAngleNew = 1, xyAngleNew = 1;
    float zAngle = zAngleNew, xyAngle = xyAngleNew, dist = 32;
    auto oldMousePos = window.mouse.position;

    while (window.isOpen) {
        window.draw(cube, camera);

        // if (window.mouse.scrollOffsetH != 0)
        //     dist -= window.mouse.scrollOffsetH;
        // if (window.mouse.buttons[0]) {
        //     auto diff = window.mouse.position - oldMousePos;
        //     zAngleNew = zAngle - diff.y * 0.01f;
        //     xyAngleNew = xyAngle - diff.x * 0.01f;
        // } else {
        //     oldMousePos = window.mouse.position;
        //     zAngle = zAngleNew;
        //     xyAngle = xyAngleNew;
        // }
        // camera.setPosition(
        //     Blob::Vec3{std::cos(xyAngleNew) * std::sin(zAngleNew),
        //                std::sin(xyAngleNew) * std::sin(zAngleNew),
        //                std::cos(zAngleNew)} *
        //     dist);

        window.display();
    }
}

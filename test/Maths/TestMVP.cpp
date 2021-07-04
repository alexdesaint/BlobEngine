#include <Blob/Maths.inl>
#include <iostream>

using namespace Blob;

int main() {
    Vec4<float> c1{0, 0, 0, 1};
    Vec4<float> c2{10, 10, 40, 1};
    Vec4<float> c3{0, 0, 40000, 1};

    /// Camera
    ViewTransform camera;
    //    camera.setPosition({width / 2.f, 0, 1 + height /
    //    std::tan(cameraAngle)});
    // camera.setLookAt({width / 2.f, height * std::tan(cameraAngle / 2.f), 1});
    camera.setCameraUp({0, 0, 1});
    camera.setLookAt({0, 0, 0});
    camera.setPosition({0, 0.0001, 40});

    std::cout << camera;
    std::cout << camera * c1 << std::endl;
    std::cout << camera * c2 << std::endl;
    std::cout << camera * c3 << std::endl;

    /// Projection
    c1 = {-10, -10, 0, 1};
    c2 = {10, 10, 40, 1};
    c3 = {0, 0, 40000, 1};
    ProjectionTransform window;

    float width = 10, height = 10;

    window.setRatio({1, 1});
    window.setAngle(PI / 4);
    window.setOrthoProjection(10);
    window.setRange(40, 100);

    c1 = {0, 0, 0, 1};
    c2 = {10, 10, -40, 1};
    c3 = {-10, -10, -100, 1};

    std::cout << window;
    c1 = window * c1;
    c1 /= c1.w;
    std::cout << "zero " << c1 << std::endl;
    c2 = window * c2;
    c2 /= c2.w;
    std::cout << "close " << c2 << std::endl;
    c3 = window * c3;
    c3 /= c3.w;
    std::cout << "far " << c3 << std::endl;
    return 0;
}
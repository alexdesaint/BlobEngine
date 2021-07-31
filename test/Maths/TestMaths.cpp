#include <Blob/Maths.inl>
#include <iostream>

using namespace Blob;

int main() {
    Vec4<> n1{1, 2, 3, 4};
    Vec4<> n2{5, 6, 7, 8};
    Vec4<> n3{9, 10, 11, 12};
    Vec4<> n4{13, 14, 15, 16};
    std::cout << '{' << n1 << '}' << std::endl;
    std::cout << '{' << n2 << '}' << std::endl;
    std::cout << '{' << n3 << '}' << std::endl;
    std::cout << '{' << n4 << '}' << std::endl;
    std::cout << Mat4{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16}
              << std::endl;
    Mat4 mat{n1, n2, n3, n4};
    std::cout << "mat" << std::endl;
    std::cout << mat << std::endl;

    Mat4 camera{0, -1, 0, 4, 1, 0, 1, -4, -1, -0, 1, -15, 0, 0, 0, 1};
    std::cout << "camera" << std::endl;
    std::cout << camera << std::endl;
    std::cout << camera.inverse() << std::endl;
    std::cout << "mat * camera" << std::endl;
    std::cout << mat * camera << std::endl;
    std::cout << "camera * mat" << std::endl;
    std::cout << camera * mat << std::endl;
}
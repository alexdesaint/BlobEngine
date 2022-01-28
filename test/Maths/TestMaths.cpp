#include <Blob/Maths.hpp>
#include <iostream>

using namespace Blob;

int main() {
    {
        std::cout << "test matrix construction" << std::endl;

        std::cout << Mat4{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16}
                  << std::endl;
        std::cout << Mat4{{1, 2, 3, 4},
                          {5, 6, 7, 8},
                          {9, 10, 11, 12},
                          {13, 14, 15, 16}}
                  << std::endl;
    }
    {
        std::cout << "test matrix multiplication" << std::endl;
        Mat4 m1{
            {4, 0, 0, 0},
            {0, 1, 0, 0},
            {0, 0, 2, 0},
            {0, 0, 0, 1},
        };
        Mat4 m2{
            {1, 0, 0, 1},
            {0, 1, 0, 2},
            {0, 0, 1, 3},
            {0, 0, 0, 1},
        };
        Mat4 m3{
            {0, 1, 0, 0},
            {1, 0, 0, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 1},
        };
        std::cout << "m1 * m2" << std::endl;
        std::cout << m1 * m2 << std::endl;
        std::cout << "m3 * m1 * m2" << std::endl;
        std::cout << m3 * m1 * m2 << std::endl;
        Vec4<> v{3, 2, 1, 1};
        std::cout << "m2 * v" << std::endl;
        std::cout << m2 * v << std::endl;
    }
    {
        std::cout << "test matrix inverse" << std::endl;
        Mat4 m1{
            {0, -1, 0, 4},
            {1, 0, 1, -4},
            {-1, -0, 1, -15},
            {0, 0, 0, 1},
        };
        std::cout << "camera" << std::endl;
        std::cout << m1 << std::endl;
        std::cout << m1.inverse() << std::endl;
    }
}
#include <Blob/VK/Instance.hpp>

#include <Blob/VK/Exception.hpp>

#include <iostream>

using namespace Blob;
using namespace Blob::VK;

int main() {
    try {
        Blob::GLFW::Window window({400, 400});
        Blob::VK::Instance instance(window);

        // std::cout << instance;

    } catch (Exception &e) {
        std::cout << e.what() << std::endl;

        return 1;
    }
    return 0;
}
#include <Blob/VK/Instance.hpp>

#include <Blob/Exception.hpp>

#include <iostream>

using namespace Blob;
using namespace Blob::VK;

int main() {
	try {
		Blob::VK::Instance instance;

		std::cout << instance;

	} catch (Exception &e) {
		std::cout << e.what() << std::endl;

		return 1;
	}
	return 0;
}
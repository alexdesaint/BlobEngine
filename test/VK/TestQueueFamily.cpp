#include <Blob/VK/QueueFamily.hpp>

#include <Blob/Exception.hpp>

#include <iostream>

using namespace Blob;
using namespace Blob::VK;

int main() {
	try {
		Blob::VK::PhysicalDevice physicalDevice;

		std::cout << physicalDevice;

		Blob::VK::QueueFamily queueFamily(physicalDevice);

		std::cout << queueFamily;

	} catch (Exception &e) {
		std::cout << e.what() << std::endl;

		return 1;
	}
	return 0;
}

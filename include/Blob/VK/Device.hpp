#pragma once

//vk
#include <vulkan/vulkan.h>

//std
#include <ostream>
#include <vector>

//Blob
#include <Blob/VK/PhysicalDevice.hpp>

namespace Blob::VK {
	class Device {
	private:
		VkDevice device;
		PhysicalDevice physicalDevice;

	public:
		Device(PhysicalDevice &physicalDevice);
	};
}

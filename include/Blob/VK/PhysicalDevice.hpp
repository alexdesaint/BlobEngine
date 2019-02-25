#pragma once

//vk
#include <vulkan/vulkan.h>

//std
#include <ostream>
#include <vector>

//Blob
#include <Blob/VK/Instance.hpp>

namespace Blob::VK {

	class PhysicalDevice {
	private:
		//Physical device
		VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;

		//Instance
		Instance instance;

		//find devices
		std::vector<VkPhysicalDevice> devices;
		void loadDevices();

		//print
		friend std::ostream& operator<<(std::ostream &os, const PhysicalDevice& p);
	public:
		PhysicalDevice();

		VkPhysicalDevice getPhysicalDevice() const;
	};
}
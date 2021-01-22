#pragma once

// vk
#include <vulkan/vulkan.h>

// std
#include <ostream>
#include <vector>

// Blob
#include <Blob/VK/PhysicalDevice.hpp>

namespace Blob::VK {
class QueueFamily {
private:
    PhysicalDevice &physicalDevice;
    std::vector<VkQueueFamilyProperties> queueFamilies;

    // print
    friend std::ostream &operator<<(std::ostream &os, const QueueFamily &p);

public:
    QueueFamily(PhysicalDevice &physicalDevice);
};
} // namespace Blob::VK

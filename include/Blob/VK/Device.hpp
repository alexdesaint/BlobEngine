#pragma once

#include "Exception.hpp"
#include "Instance.hpp"
#include <Blob/GLFW.hpp>
#include <Blob/VK/PhysicalDevice.hpp>
#include <glad/vulkan.h>
#include <memory>
#include <stdexcept>
#include <vector>

namespace Blob::VK {
class Device {
public:
    VkDevice device = VK_NULL_HANDLE;
    const PhysicalDevice &physicalDevice;

    VkQueue graphicsQueue;
    VkQueue presentQueue;

    explicit Device(PhysicalDevice &physicalDevice);

    ~Device();
};
} // namespace Blob::VK
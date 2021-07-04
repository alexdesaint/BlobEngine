#include <vulkan/vulkan.h>

#include <algorithm>
#include <array>
#include <cstring>
#include <fstream>
#include <functional>
#include <iostream>
#include <set>
#include <stdexcept>
#include <vector>

#include <Blob/VK/Device.hpp>
#include <Blob/VK/Pipeline.hpp>
#include <Blob/VK/Vertex.hpp>
#include <Blob/VK/Window.hpp>
#include <Blob/VK/model.hpp>
#include <Blob/VK/vdeleter.hpp>

namespace Blob::VK {
Device::Device(PhysicalDevice &physicalDevice) :
    physicalDevice(physicalDevice) {
    std::vector<VkDeviceQueueCreateInfo> queueCreateInfos;
    std::set<uint32_t> uniqueQueueFamilies = {physicalDevice.graphicsFamily,
                                              physicalDevice.presentFamily};

    float queuePriority = 1.0f;
    for (uint32_t queueFamily : uniqueQueueFamilies) {
        VkDeviceQueueCreateInfo queueCreateInfo = {};
        queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
        queueCreateInfo.queueFamilyIndex = queueFamily;
        queueCreateInfo.queueCount = 1;
        queueCreateInfo.pQueuePriorities = &queuePriority;
        queueCreateInfos.push_back(queueCreateInfo);
    }

    VkPhysicalDeviceFeatures deviceFeatures = {};

    VkDeviceCreateInfo createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;

    createInfo.pQueueCreateInfos = queueCreateInfos.data();
    createInfo.queueCreateInfoCount = (uint32_t) queueCreateInfos.size();

    createInfo.pEnabledFeatures = &deviceFeatures;

    createInfo.enabledExtensionCount =
        (uint32_t) PhysicalDevice::deviceExtensions.size();
    createInfo.ppEnabledExtensionNames =
        PhysicalDevice::deviceExtensions.data();

    if (enableValidationLayers) {
        createInfo.enabledLayerCount = (uint32_t) validationLayers.size();
        createInfo.ppEnabledLayerNames = validationLayers.data();
    } else {
        createInfo.enabledLayerCount = 0;
    }

    if (vkCreateDevice(physicalDevice.physicalDevice,
                       &createInfo,
                       nullptr,
                       &device) != VK_SUCCESS)
        throw std::runtime_error("failed to create logical device !");

    vkGetDeviceQueue(device, physicalDevice.graphicsFamily, 0, &graphicsQueue);
    vkGetDeviceQueue(device, physicalDevice.presentFamily, 0, &presentQueue);
}

Device::~Device() {
    vkDeviceWaitIdle(device);
    vkDestroyDevice(device, nullptr);
}
} // namespace Blob::VK
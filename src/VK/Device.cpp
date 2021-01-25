#include <vulkan/vulkan.h>

#include <iostream>
#include <stdexcept>
#include <functional>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <array>

#include <Blob/VK/Device.hpp>
#include <Blob/VK/Vertex.hpp>
#include <Blob/VK/Window.hpp>
#include <Blob/VK/model.hpp>
#include <Blob/VK/pipeline.hpp>
#include <Blob/VK/vdeleter.hpp>
namespace Blob::VK {

void PhysicalDevice::findQueueFamilies(const Surface &surface) {
    uint32_t i = 0;
    for (const auto &queueFamily : queueFamilyProperties) {
        if (queueFamily.queueCount > 0 && queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT) {
            graphicsFamily = i;
        }

        VkBool32 presentSupport = (VkBool32) false;
        vkGetPhysicalDeviceSurfaceSupportKHR(physicalDevice, i, surface.surface, &presentSupport);

        if (queueFamily.queueCount > 0 && presentSupport) {
            presentFamily = i;
        }

        if (isComplete()) {
            break;
        }

        i++;
    }
}

bool PhysicalDevice::checkDeviceExtensionSupport() {
    std::set<std::string> requiredExtensions(deviceExtensions.begin(), deviceExtensions.end());

    for (const auto &extension : extensionProperties)
        requiredExtensions.erase(extension.extensionName);

    return requiredExtensions.empty();
}

PhysicalDevice::PhysicalDevice(VkPhysicalDevice physicalDevice) : physicalDevice(physicalDevice) {
    uint32_t extensionCount;
    vkEnumerateDeviceExtensionProperties(physicalDevice, nullptr, &extensionCount, nullptr);

    extensionProperties.resize(extensionCount);
    vkEnumerateDeviceExtensionProperties(physicalDevice, nullptr, &extensionCount, extensionProperties.data());

    uint32_t queueFamilyCount = 0;
    vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &queueFamilyCount, nullptr);

    queueFamilyProperties.resize(queueFamilyCount);
    vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &queueFamilyCount, queueFamilyProperties.data());
}

std::vector<PhysicalDevice> PhysicalDevice::getPhysicalDevices(const Instance &instance) {
    uint32_t deviceCount = 0;
    vkEnumeratePhysicalDevices(instance.instance, &deviceCount, nullptr);

    if (deviceCount == 0)
        throw std::runtime_error("failed to find GPUs with Vulkan support!");

    std::vector<VkPhysicalDevice> devices(deviceCount);
    vkEnumeratePhysicalDevices(instance.instance, &deviceCount, devices.data());

    std::vector<PhysicalDevice> ph;

    for (auto pd : devices)
        ph.emplace_back(pd);

    return ph;
}

bool PhysicalDevice::isDeviceSuitable(const Surface &surface) {
    findQueueFamilies(surface);

    bool extensionsSupported = checkDeviceExtensionSupport();

    bool swapChainAdequate = false;
    if (extensionsSupported) {
        SwapChainSupportDetails swapChainSupport = querySwapChainSupport(surface);
        swapChainAdequate = !swapChainSupport.formats.empty() && !swapChainSupport.presentModes.empty();
    }

    return isComplete() && extensionsSupported && swapChainAdequate;
}

PhysicalDevice PhysicalDevice::pickPhysicalDevice(const Instance &instance, const Surface &surface) {
    auto devices = getPhysicalDevices(instance);

    for (auto &device : devices) {
        if (device.isDeviceSuitable(surface))
            return device;
    }

    throw std::runtime_error("failed to find a suitable GPU!");
}

SwapChainSupportDetails PhysicalDevice::querySwapChainSupport(const Surface &surface) const {
    SwapChainSupportDetails details;

    vkGetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice, surface.surface, &details.capabilities);

    uint32_t formatCount;
    vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, surface.surface, &formatCount, nullptr);

    if (formatCount != 0) {
        details.formats.resize(formatCount);
        vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, surface.surface, &formatCount, details.formats.data());
    }

    uint32_t presentModeCount;
    vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface.surface, &presentModeCount, nullptr);

    if (presentModeCount != 0) {
        details.presentModes.resize(presentModeCount);
        vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface.surface, &presentModeCount, details.presentModes.data());
    }

    return details;
}

Device::Device(PhysicalDevice &physicalDevice) : physicalDevice(physicalDevice) {
    std::vector<VkDeviceQueueCreateInfo> queueCreateInfos;
    std::set<uint32_t> uniqueQueueFamilies = {physicalDevice.graphicsFamily, physicalDevice.presentFamily};

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

    createInfo.enabledExtensionCount = (uint32_t) PhysicalDevice::deviceExtensions.size();
    createInfo.ppEnabledExtensionNames = PhysicalDevice::deviceExtensions.data();

    if (enableValidationLayers) {
        createInfo.enabledLayerCount = (uint32_t) validationLayers.size();
        createInfo.ppEnabledLayerNames = validationLayers.data();
    } else {
        createInfo.enabledLayerCount = 0;
    }

    if (vkCreateDevice(physicalDevice.physicalDevice, &createInfo, nullptr, &device) != VK_SUCCESS)
        throw std::runtime_error("failed to create logical device !");

    vkGetDeviceQueue(device, physicalDevice.graphicsFamily, 0, &graphicsQueue);
    vkGetDeviceQueue(device, physicalDevice.presentFamily, 0, &presentQueue);
}

Device::~Device() {
    vkDeviceWaitIdle(device);
    vkDestroyDevice(device, nullptr);
}
}
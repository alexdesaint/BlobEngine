#include <Blob/VK/PhysicalDevice.hpp>

// std
#include <set>

// glfw
#include <GLFW/glfw3.h>

// Blob
#include <Blob/Core/Exception.hpp>
#include <Blob/VK/Instance.hpp>

namespace Blob::VK {
    /*
void PhysicalDevice::loadDevices() {
    uint32_t deviceCount = 0;
    vkEnumeratePhysicalDevices(instance.instance, &deviceCount, nullptr);

    if (deviceCount == 0) {
        throw Core::Exception("failed to find GPUs with Vulkan support!");
    }

    devices.resize(deviceCount);

    vkEnumeratePhysicalDevices(instance.instance, &deviceCount, devices.data());
}

PhysicalDevice::PhysicalDevice() {
    loadDevices();

    physicalDevice = devices[0];
}

std::ostream &operator<<(std::ostream &os, const PhysicalDevice &p) {
    os << p.instance;

    os << "Physical Device :" << std::endl;

    os << "Available devices:" << std::endl;

    for (const VkPhysicalDevice &device : p.devices) {
        VkPhysicalDeviceProperties deviceProperties;
        vkGetPhysicalDeviceProperties(device, &deviceProperties);
        os << "\t" << deviceProperties.deviceName << std::endl;
    }

    return os;
}

VkPhysicalDevice PhysicalDevice::getPhysicalDevice() const {
    return physicalDevice;
}
*/

    Surface::Surface(const Blob::GLFW::Window &window, const Instance &instance) : instance(instance) {
        if (glfwCreateWindowSurface(instance.instance, (GLFWwindow *) window.window, NULL, &surface))
            throw std::runtime_error("Unable to create Vulkan compatible surface using SDL");
    }

    Surface::~Surface() {
        vkDestroySurfaceKHR(instance.instance, surface, nullptr);
    }

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
} // namespace Blob::VK

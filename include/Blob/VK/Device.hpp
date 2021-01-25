#pragma once

#include "Exception.hpp"
#include <Blob/GLFW.hpp>
#include <memory>
#include <stdexcept>
#include <vector>
#include <vulkan/vulkan.hpp>
namespace Blob::VK {

class Instance {
public:
    VkInstance instance;

    VkDebugReportCallbackEXT debugReportCallbackEXT;

    Instance(const Blob::GLFW::Window &window);

    ~Instance();

    static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objType, uint64_t obj,
                                                        size_t location, int32_t code, const char *layerPrefix, const char *msg, void *userData);

    bool checkValidationLayerSupport();
};

class Surface {
public:
    VkSurfaceKHR surface;

    const Instance &instance;

    Surface(const Blob::GLFW::Window &winow, const Instance &instance);
    ~Surface();
};

struct SwapChainSupportDetails {
    VkSurfaceCapabilitiesKHR capabilities;
    std::vector<VkSurfaceFormatKHR> formats;
    std::vector<VkPresentModeKHR> presentModes;
};

class PhysicalDevice {
public:
    inline static const std::vector<const char *> deviceExtensions = {VK_KHR_SWAPCHAIN_EXTENSION_NAME};

    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;

    uint32_t graphicsFamily = -1;
    uint32_t presentFamily = -1;

    std::vector<VkExtensionProperties> extensionProperties;
    std::vector<VkQueueFamilyProperties> queueFamilyProperties;

    bool isComplete() { return graphicsFamily >= 0 && presentFamily >= 0; }

    void findQueueFamilies(const Surface &surface);

    bool isDeviceSuitable(const Surface &surface);

    explicit PhysicalDevice(VkPhysicalDevice physicalDevice);

    SwapChainSupportDetails querySwapChainSupport(const Surface &surface) const;

    static std::vector<PhysicalDevice> getPhysicalDevices(const Instance &instance);

    static PhysicalDevice pickPhysicalDevice(const Instance &instance, const Surface &surface);

    bool checkDeviceExtensionSupport();

    uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties) const {
        VkPhysicalDeviceMemoryProperties memProperties;
        vkGetPhysicalDeviceMemoryProperties(physicalDevice, &memProperties);

        for (uint32_t i = 0; i < memProperties.memoryTypeCount; i++) {
            if ((typeFilter & (1 << i)) && (memProperties.memoryTypes[i].propertyFlags & properties) == properties) {
                return i;
            }
        }

        throw Blob::VK::Exception(this, "failed to find suitable memory type!");
    }

    VkFormat findSupportedFormat(const std::vector<VkFormat> &candidates, VkImageTiling tiling, VkFormatFeatureFlags features) const {
        for (VkFormat format : candidates) {
            VkFormatProperties props;
            vkGetPhysicalDeviceFormatProperties(physicalDevice, format, &props);

            if (tiling == VK_IMAGE_TILING_LINEAR && (props.linearTilingFeatures & features) == features) {
                return format;
            } else if (tiling == VK_IMAGE_TILING_OPTIMAL && (props.optimalTilingFeatures & features) == features) {
                return format;
            }
        }

        throw Blob::VK::Exception(this, "failed to find supported format!");
    }
};

class Device {
public:
    VkDevice device = VK_NULL_HANDLE;
    const PhysicalDevice &physicalDevice;

    VkQueue graphicsQueue;
    VkQueue presentQueue;

    explicit Device(PhysicalDevice &physicalDevice);

    ~Device();
};
}
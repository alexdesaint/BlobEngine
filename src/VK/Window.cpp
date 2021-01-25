#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>

#include <cstring>
#include <stdexcept>
#include <vector>

#include <Blob/VK/Window.hpp>
#include <Blob/VK/model.hpp>
#include <Blob/VK/pipeline.hpp>

/*********************************************************************************************************************************************************************/
namespace Blob::VK {
Window::Window(unsigned int width, unsigned int height)
    : GLFW::Window({width, height}), instance(*this), surface(*this, instance),
      physicalDevice(PhysicalDevice::pickPhysicalDevice(instance, surface)), device(physicalDevice),
      swapchain(device, surface, VkExtent2D{width, height}), descriptorSetLayout(device),
      pipelineLayout(device, descriptorSetLayout.descriptorSetLayout, VkExtent2D{width, height}),
      renderPass(device, swapchain.swapChainImageFormat,
                 device.physicalDevice.findSupportedFormat({VK_FORMAT_D32_SFLOAT, VK_FORMAT_D32_SFLOAT_S8_UINT, VK_FORMAT_D24_UNORM_S8_UINT},
                                                           VK_IMAGE_TILING_OPTIMAL, VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT)),
      commandPool(device) {}

Window::~Window() {}

////////////////////////////////////////

/*void CoreEngine::WindowResized() {
    //pipe->recreateSwapChain();
}*/

Instance::Instance(const Blob::GLFW::Window &window) {
    if (enableValidationLayers && !checkValidationLayerSupport()) {
        throw std::runtime_error("validation layers requested, but not available!");
    }

    {
        VkApplicationInfo appInfo = {};
        appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        appInfo.pApplicationName = "BlobAttack";
        appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.pEngineName = "BlobEngine";
        appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.apiVersion = VK_API_VERSION_1_0;

        VkInstanceCreateInfo createInfo = {};
        createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        createInfo.pApplicationInfo = &appInfo;

        uint32_t count;
        const char **extensions = glfwGetRequiredInstanceExtensions(&count);

        memset(&createInfo, 0, sizeof(VkInstanceCreateInfo));
        createInfo.enabledExtensionCount = count;
        createInfo.ppEnabledExtensionNames = extensions;

        if (enableValidationLayers) {
            createInfo.enabledLayerCount = (uint32_t) validationLayers.size();
            createInfo.ppEnabledLayerNames = validationLayers.data();
        } else {
            createInfo.enabledLayerCount = 0;
        }

        if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS)
            throw std::runtime_error("failed to create instance!");
    }

    /// setupDebugCallback

    {
        if (!enableValidationLayers)
            return;

        VkDebugReportCallbackCreateInfoEXT createInfo = {};
        createInfo.sType = VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT;
        createInfo.flags = VK_DEBUG_REPORT_ERROR_BIT_EXT | VK_DEBUG_REPORT_WARNING_BIT_EXT;
        createInfo.pfnCallback = debugCallback;

        auto func = (PFN_vkCreateDebugReportCallbackEXT) vkGetInstanceProcAddr(instance, "vkCreateDebugReportCallbackEXT");
        if (func == nullptr)
            throw std::runtime_error("failed to create debug callback function!");
        auto r = func(instance, &createInfo, nullptr, &debugReportCallbackEXT);
        if (r != VK_SUCCESS)
            throw std::runtime_error("failed to set up debug callback!");
    }
}

Surface::Surface(const Blob::GLFW::Window &window, const Instance &instance) : instance(instance) {
    if (glfwCreateWindowSurface(instance.instance, (GLFWwindow *) window.window, NULL, &surface))
        throw std::runtime_error("Unable to create Vulkan compatible surface using SDL");
}

Surface::~Surface() {
    vkDestroySurfaceKHR(instance.instance, surface, nullptr);
}
/*
void CoreEngine::copyImage(VkImage srcImage, VkImage dstImage, uint32_t width,
uint32_t height, const CommandPool &commandPool) { VkCommandBuffer commandBuffer
= commandPool.beginSingleTimeCommands();

    VkImageSubresourceLayers subResource = {};
    subResource.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
    subResource.baseArrayLayer = 0;
    subResource.mipLevel = 0;
    subResource.layerCount = 1;

    VkImageCopy region = {};
    region.srcSubresource = subResource;
    region.dstSubresource = subResource;
    region.srcOffset = {0, 0, 0};
    region.dstOffset = {0, 0, 0};
    region.extent.width = width;
    region.extent.height = height;
    region.extent.depth = 1;

    vkCmdCopyImage(
            commandBuffer,
            srcImage, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
            dstImage, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
            1, &region
    );

    commandPool.endSingleTimeCommands(commandBuffer);
}


}*/

bool Instance::checkValidationLayerSupport() {
    uint32_t layerCount;
    vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

    std::vector<VkLayerProperties> availableLayers(layerCount);
    vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

    for (const char *layerName : validationLayers) {
        bool layerFound = false;

        for (const auto &layerProperties : availableLayers) {
            if (strcmp(layerName, layerProperties.layerName) == 0) {
                layerFound = true;
                break;
            }
        }

        if (!layerFound) {
            return false;
        }
    }

    return true;
}

VKAPI_ATTR VkBool32 VKAPI_CALL Instance::debugCallback(VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objType, uint64_t obj, size_t location,
                                                       int32_t code, const char *layerPrefix, const char *msg, void *userData) {
    // SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Vulkan Error", msg, NULL);
    throw Blob::VK::Exception(msg);
    return VK_FALSE;
}

Instance::~Instance() {
    auto func = (PFN_vkDestroyDebugReportCallbackEXT) vkGetInstanceProcAddr(instance, "vkDestroyDebugReportCallbackEXT");
    if (func != nullptr)
        func(instance, debugReportCallbackEXT, nullptr);

    vkDestroyInstance(instance, nullptr);
}
} // namespace Blob::VK
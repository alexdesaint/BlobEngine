#pragma once

// vk
#include <Blob/GLFW.hpp>
#include <vulkan/vulkan.h>

// std
#include <ostream>
#include <vector>

namespace Blob::VK {
/*
class Instance {
private:
    VkInstance instance;

    // Extentions
    std::vector<VkExtensionProperties> extensions;
    void loadExtentions();

    // validation layers
#ifdef NDEBUG
    const bool enableValidationLayers = false;
#else
    const bool enableValidationLayers = true;
#endif
    const std::vector<const char *> validationLayers =
{"VK_LAYER_LUNARG_standard_validation"}; std::vector<VkLayerProperties> layers;
    void loadLayers();
    bool checkLayerSupport();

    // print
    friend std::ostream &operator<<(std::ostream &os, const Instance &p);

    // Debug callback
    VkDebugUtilsMessengerEXT debugMessenger;
    void setDebugCallback();
    void destroyDebugCallback();
    static VKAPI_ATTR VkBool32 VKAPI_CALL
debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
                                                        VkDebugUtilsMessageTypeFlagsEXT
messageType, const VkDebugUtilsMessengerCallbackDataEXT *pCallbackData, void
*pUserData);

public:
    Instance();
    ~Instance();

    VkInstance getInstance() const;

    const std::vector<VkExtensionProperties> &getExtensions() const;
};
 */

class Instance {
public:
    VkInstance instance;

    VkDebugReportCallbackEXT debugReportCallbackEXT;

    explicit Instance(const Blob::GLFW::Window &window);

    ~Instance();

    static VKAPI_ATTR VkBool32 VKAPI_CALL
    debugCallback(VkDebugReportFlagsEXT flags,
                  VkDebugReportObjectTypeEXT objType,
                  uint64_t obj,
                  size_t location,
                  int32_t code,
                  const char *layerPrefix,
                  const char *msg,
                  void *userData);

    bool checkValidationLayerSupport();
};
} // namespace Blob::VK
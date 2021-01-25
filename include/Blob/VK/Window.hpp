#pragma once

#include "CommandPool.hpp"
#include "DescriptorSetLayout.hpp"
#include "Framebuffer.hpp"
#include "PipelineLayout.hpp"
#include "RenderPass.hpp"
#include "Swapchain.hpp"
#include "vdeleter.hpp"
#include <memory>
#include <string>
// #include "pipeline.h"


namespace Blob::VK {
class model;

#define NDEBUG
#ifdef NDEBUG
const bool enableValidationLayers = true;
#else
const bool enableValidationLayers = true;
#endif

const std::vector<const char *> validationLayers = {
    "VK_LAYER_KHRONOS_validation" // old value is
                                  // "VK_LAYER_LUNARG_standard_validation"
};

class Window : public Blob::GLFW::Window {
    friend class model;

public:
    Instance instance;
    Surface surface;
    PhysicalDevice physicalDevice;
    Device device;
    Swapchain swapchain;
    DescriptorSetLayout descriptorSetLayout;
    PipelineLayout pipelineLayout;
    std::vector<Framebuffer> framebuffers;
    RenderPass renderPass;
    CommandPool commandPool;
    /*
        void WindowResized();

        static bool hasStencilComponent(VkFormat format);

        static void transitionImageLayout(VkImage image, VkFormat format,
       VkImageLayout oldLayout, VkImageLayout newLayout, const CommandPool
       &commandPool);

        static void copyImage(VkImage srcImage, VkImage dstImage, uint32_t width,
       uint32_t height, const CommandPool &commandPool);

        static void createShaderModule(const std::vector<char> &code,
       VDeleter<VkShaderModule> &shaderModule);
    */

    Window(unsigned int width, unsigned int height);
    Window(const Window &) = delete;
    Window(Window &&) = delete;

    ~Window();

    /*  std::vector<Framebuffer> createFramebuffers(unsigned int width, unsigned int height) {
        std::vector<Framebuffer> swapChainFramebuffers;

        for (size_t i = 0; i < swapChainImageViews.size(); i++) {
          swapChainFramebuffers.emplace_back(device, width, height, renderPass.renderPass, {swapChainImageViews[i], depthImageView});
        }

        return swapChainFramebuffers;
      }*/
};
} // namespace Blob::VK
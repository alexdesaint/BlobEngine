#pragma once

// #include "RenderPass.hpp"
// #include "DescriptorSetLayout.hpp"
// #include "Swapchain.hpp"
namespace Blob::VK {

class pipeline {
public:
    //     explicit pipeline(const Device &device);

    //     void drawFrame();

    //     void loadModel();

    //     void recreateSwapChain();

    //     const Device &device;

    //     Swapchain swapchain;
    //     std::vector<VDeleter<VkFramebuffer>> swapChainFramebuffers;

    //     RenderPass renderPass;
    //     DescriptorSetLayout descriptorSetLayout;
    //     VDeleter<VkPipelineLayout> pipelineLayout{device.device,
    //     vkDestroyPipelineLayout}; VDeleter<VkPipeline>
    //     graphicsPipeline{device.device, vkDestroyPipeline};

    //     VDeleter<VkCommandPool> commandPool{device.device,
    //     vkDestroyCommandPool};

    //     VDeleter<VkImage> depthImage{device.device, vkDestroyImage};
    //     VDeleter<VkDeviceMemory> depthImageMemory{device.device,
    //     vkFreeMemory}; VDeleter<VkImageView> depthImageView{device.device,
    //     vkDestroyImageView};

    //     std::vector<VkCommandBuffer> maincommandBuffers;

    //     VDeleter<VkSemaphore> imageAvailableSemaphore{device.device,
    //     vkDestroySemaphore}; VDeleter<VkSemaphore>
    //     renderFinishedSemaphore{device.device, vkDestroySemaphore};

    // private:
    //     void createGraphicsPipeline();

    //     void createDepthResources();

    //     void createFramebuffers();

    //     void createMainCommandBuffers();

    //     void createSemaphores();
};
} // namespace Blob::VK

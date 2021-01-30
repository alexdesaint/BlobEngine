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

} // namespace Blob::VK
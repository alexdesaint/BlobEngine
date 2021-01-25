#ifndef BLOBATTACK_FRAMEBUFFER_HPP
#define BLOBATTACK_FRAMEBUFFER_HPP

#include "Device.hpp"
namespace Blob::VK {

class Framebuffer {
public:
    VkFramebuffer framebuffer = nullptr;
    const Device &device;

    Framebuffer(const Device &device, unsigned int width, unsigned int height, VkRenderPass renderPass, std::array<VkImageView, 2> attachments)
        : device(device) {
        VkFramebufferCreateInfo framebufferInfo = {};
        framebufferInfo.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
        framebufferInfo.renderPass = renderPass;
        framebufferInfo.attachmentCount = (uint32_t) attachments.size();
        framebufferInfo.pAttachments = attachments.data();
        framebufferInfo.width = width;
        framebufferInfo.height = height;
        framebufferInfo.layers = 1;

        if (vkCreateFramebuffer(device.device, &framebufferInfo, nullptr, &framebuffer) != VK_SUCCESS)
            throw Blob::VK::Exception(this, "failed to create framebuffer!");
    }

    ~Framebuffer() { vkDestroyFramebuffer(device.device, framebuffer, nullptr); }
};
}
#endif //BLOBATTACK_FRAMEBUFFER_HPP

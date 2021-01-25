#ifndef BLOBATTACK_IMAGEVIEW_HPP
#define BLOBATTACK_IMAGEVIEW_HPP

#include "Image.hpp"
namespace Blob::VK {

class ImageView {
public:
    VkImageView imageView = nullptr;
    const Device &device;

    ImageView(const Device &device, VkImage image, VkFormat format, VkImageAspectFlags aspectFlags) : device(device) {
        VkImageViewCreateInfo viewInfo = {};
        viewInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
        viewInfo.image = image;
        viewInfo.viewType = VK_IMAGE_VIEW_TYPE_2D;
        viewInfo.format = format;
        viewInfo.subresourceRange.aspectMask = aspectFlags;
        viewInfo.subresourceRange.baseMipLevel = 0;
        viewInfo.subresourceRange.levelCount = 1;
        viewInfo.subresourceRange.baseArrayLayer = 0;
        viewInfo.subresourceRange.layerCount = 1;

        if (vkCreateImageView(device.device, &viewInfo, nullptr, &imageView) != VK_SUCCESS)
            throw std::runtime_error("failed to create texture image view!");
    }

    ~ImageView() { vkDestroyImageView(device.device, imageView, nullptr); }
};
}
#endif //BLOBATTACK_IMAGEVIEW_HPP

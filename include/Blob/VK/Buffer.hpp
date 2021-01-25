#ifndef BLOBATTACK_BUFFER_HPP
#define BLOBATTACK_BUFFER_HPP

#include "CommandPool.hpp"
#include "Device.hpp"
namespace Blob::VK {

class Buffer {
public:
    const Device &device;
    VkBuffer buffer = nullptr;
    VkDeviceMemory deviceMemory;

    Buffer(const Device &device, VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkDeviceMemory bufferMemory)
        : device(device) {
        VkBufferCreateInfo bufferInfo = {};
        bufferInfo.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
        bufferInfo.size = size;
        bufferInfo.usage = usage;
        bufferInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;

        if (vkCreateBuffer(device.device, &bufferInfo, nullptr, &buffer) != VK_SUCCESS) {
            throw std::runtime_error("failed to create buffer!");
        }

        VkMemoryRequirements memRequirements;
        vkGetBufferMemoryRequirements(device.device, buffer, &memRequirements);

        VkMemoryAllocateInfo allocInfo = {};
        allocInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
        allocInfo.allocationSize = memRequirements.size;
        allocInfo.memoryTypeIndex = device.physicalDevice.findMemoryType(memRequirements.memoryTypeBits, properties);

        if (vkAllocateMemory(device.device, &allocInfo, nullptr, &bufferMemory) != VK_SUCCESS) {
            throw std::runtime_error("failed to allocate buffer memory!");
        }

        vkBindBufferMemory(device.device, buffer, bufferMemory, 0);
    }

    void copyBufferFrom(const CommandPool &commandPool, VkQueue queue, VkBuffer srcBuffer, VkDeviceSize size) {
        VkCommandBuffer commandBuffer = commandPool.beginSingleTimeCommands();

        VkBufferCopy copyRegion = {};
        copyRegion.size = size;
        vkCmdCopyBuffer(commandBuffer, srcBuffer, buffer, 1, &copyRegion);

        commandPool.endSingleTimeCommands(commandBuffer);
    }

    ~Buffer() {
        vkDestroyBuffer(device.device, buffer, nullptr);
        vkFreeMemory(device.device, deviceMemory, nullptr);
    }
};
}
#endif // BLOBATTACK_BUFFER_HPP

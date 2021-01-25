#ifndef BLOBATTACK_DEVICEMEMORY_HPP
#define BLOBATTACK_DEVICEMEMORY_HPP

#include "Device.hpp"
namespace Blob::VK {

class DeviceMemory {
public:
    VkDeviceMemory deviceMemory = nullptr;
    const Device &device;

    DeviceMemory(const Device &device) : device(device) {}
};
} // namespace Blob::VK
#endif // BLOBATTACK_DEVICEMEMORY_HPP

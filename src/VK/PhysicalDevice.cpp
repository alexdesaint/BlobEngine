#include <Blob/VK/PhysicalDevice.hpp>

// Blob
#include <Blob/Exception.hpp>
#include <Blob/VK/Instance.hpp>

namespace Blob::VK {
void PhysicalDevice::loadDevices() {
    uint32_t deviceCount = 0;
    vkEnumeratePhysicalDevices(instance.getInstance(), &deviceCount, nullptr);

    if (deviceCount == 0) {
        throw Exception("failed to find GPUs with Vulkan support!");
    }

    devices.resize(deviceCount);

    vkEnumeratePhysicalDevices(instance.getInstance(), &deviceCount, devices.data());
}

PhysicalDevice::PhysicalDevice() {
    loadDevices();

    physicalDevice = devices[0];
}

std::ostream &operator<<(std::ostream &os, const PhysicalDevice &p) {
    os << p.instance;

    os << "Physical Device :" << std::endl;

    os << "Available devices:" << std::endl;

    for (const VkPhysicalDevice &device : p.devices) {
        VkPhysicalDeviceProperties deviceProperties;
        vkGetPhysicalDeviceProperties(device, &deviceProperties);
        os << "\t" << deviceProperties.deviceName << std::endl;
    }

    return os;
}

VkPhysicalDevice PhysicalDevice::getPhysicalDevice() const {
    return physicalDevice;
}
} // namespace Blob::VK

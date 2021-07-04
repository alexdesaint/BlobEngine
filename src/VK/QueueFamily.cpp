#include <Blob/VK/QueueFamily.hpp>

namespace Blob::VK {
QueueFamily::QueueFamily(Blob::VK::PhysicalDevice &physicalDevice) :
    physicalDevice(physicalDevice) {
    uint32_t queueFamilyCount = 0;
    vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice.physicalDevice,
                                             &queueFamilyCount,
                                             nullptr);

    queueFamilies.resize(queueFamilyCount);
    vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice.physicalDevice,
                                             &queueFamilyCount,
                                             queueFamilies.data());
}

std::ostream &operator<<(std::ostream &os, const QueueFamily &p) {
    os << "Queue Family :" << std::endl;

    for (const auto &queueFamilie : p.queueFamilies) {
        os << "\t queueCount : " << queueFamilie.queueCount << std::endl;
        os << "\t queueFlags : " << queueFamilie.queueFlags << std::endl;
        if (queueFamilie.queueFlags & VK_QUEUE_GRAPHICS_BIT)
            os << "\t\t VK_QUEUE_GRAPHICS_BIT" << std::endl;
        if (queueFamilie.queueFlags & VK_QUEUE_COMPUTE_BIT)
            os << "\t\t VK_QUEUE_COMPUTE_BIT" << std::endl;
        if (queueFamilie.queueFlags & VK_QUEUE_TRANSFER_BIT)
            os << "\t\t VK_QUEUE_TRANSFER_BIT" << std::endl;
        if (queueFamilie.queueFlags & VK_QUEUE_SPARSE_BINDING_BIT)
            os << "\t\t VK_QUEUE_SPARSE_BINDING_BIT" << std::endl;
        if (queueFamilie.queueFlags & VK_QUEUE_PROTECTED_BIT)
            os << "\t\t VK_QUEUE_PROTECTED_BIT" << std::endl;
        os << "\t Min image. w : "
           << queueFamilie.minImageTransferGranularity.width
           << ", h : " << queueFamilie.minImageTransferGranularity.height
           << ", d : " << queueFamilie.minImageTransferGranularity.depth
           << std::endl;
        os << "\t timestampValidBits : " << queueFamilie.timestampValidBits
           << std::endl;
    }

    return os;
}
} // namespace Blob::VK

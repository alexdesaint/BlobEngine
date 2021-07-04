#pragma once

#include "Device.hpp"
#include <functional>
namespace Blob::VK {

template<typename T>
class VDeleter {
public:
    VDeleter() : VDeleter([](T, VkAllocationCallbacks *) {}) {}

    VDeleter(std::function<void(T, VkAllocationCallbacks *)> deletef) {
        deleter = [=](T obj) { deletef(obj, nullptr); };
    }

    VDeleter(
        const VDeleter<VkInstance> &instance,
        std::function<void(VkInstance, T, VkAllocationCallbacks *)> deletef) {
        deleter = [&instance, deletef](T obj) {
            deletef(instance, obj, nullptr);
        };
    }

    VDeleter(
        const Device &device,
        std::function<void(VkDevice, T, VkAllocationCallbacks *)> deletef) {
        deleter = [&device, deletef](T obj) {
            deletef(device.device, obj, nullptr);
        };
    }

    VDeleter(
        VkDevice device,
        std::function<void(VkDevice, T, VkAllocationCallbacks *)> deletef) {
        deleter = [device, deletef](T obj) { deletef(device, obj, nullptr); };
    }

    ~VDeleter() { cleanup(); }

    const T *operator&() const { return &object; }

    T *replace() {
        cleanup();
        return &object;
    }

    operator T() const { return object; }

    void operator=(T rhs) {
        if (rhs != object) {
            cleanup();
            object = rhs;
        }
    }

    template<typename V>
    bool operator==(V rhs) {
        return object == T(rhs);
    }

private:
    T object{VK_NULL_HANDLE};
    std::function<void(T)> deleter;

    void cleanup() {
        if (object != VK_NULL_HANDLE) {
            deleter(object);
        }
        object = VK_NULL_HANDLE;
    }
};
} // namespace Blob::VK

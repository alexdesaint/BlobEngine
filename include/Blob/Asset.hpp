#pragma once
#include <memory>

namespace Blob {

template<class T>
class Asset {
private:
    inline static std::weak_ptr<T> instance;

public:
    using Instance = std::shared_ptr<T>;

    template<class... ATTRIBUTES>
    static Instance getInstance(ATTRIBUTES... attributes) {
        auto sharedPointer = instance.lock();
        if (!sharedPointer) {
            sharedPointer = std::shared_ptr<T>(new T{attributes...});
            instance = sharedPointer;
        }
        return sharedPointer;
    }

    static auto isInstancied() { return (bool) instance.lock(); }

    static auto getUseCount() { return instance.use_count(); }

    static size_t getId() { return getInstance().get(); }
};

} // namespace Blob

#include <memory>

namespace Blob::Core {

template<class T>
class Asset {
private:
    inline static std::weak_ptr<T> instance;

public:
    static std::shared_ptr<T> getInstance() {
        auto sharedPointer = instance.lock();
        if (!sharedPointer) {
            sharedPointer = std::shared_ptr<T>(new T);
            instance = sharedPointer;
        }
        return sharedPointer;
    }

    static auto isInstancied() { return (bool) instance.lock(); }

    static auto getUseCount() { return instance.use_count(); }
};

} // namespace Blob::Core
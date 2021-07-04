#include <Blob/Core/Asset.hpp>
#include <iostream>

class TestAsset : public Blob::Asset<TestAsset> {
public:
    TestAsset() { std::cout << "Build" << std::endl; }
    ~TestAsset() { std::cout << "Destroy" << std::endl; }
};

int main() {
    TestAsset test;

    std::cout << "count " << TestAsset::getUseCount() << std::endl;
    std::cout << "isInstancied "
              << (TestAsset::isInstancied() ? "true" : "false") << std::endl;
    {
        auto instance = TestAsset::getInstance();
        auto instance2 = TestAsset::getInstance();
        auto instance3 = TestAsset::getInstance();
        std::cout << "count " << TestAsset::getUseCount() << std::endl;
        std::cout << "isInstancied "
                  << (TestAsset::isInstancied() ? "true" : "false")
                  << std::endl;
    }
    std::cout << "count " << TestAsset::getUseCount() << std::endl;
    std::cout << "isInstancied "
              << (TestAsset::isInstancied() ? "true" : "false") << std::endl;

    return 0;
}
#pragma once

#include <exception>
#include <string>
#include <utility>

namespace Blob {
class Exception : public std::exception {
private:
    const std::string errorMsg;

public:
    // explicit Exception(const char *errorMsg) : errorMsg(errorMsg){}

    explicit Exception(std::string errorMsg) : errorMsg(std::move(errorMsg)) {}

    const char *what() const noexcept override {
        return errorMsg.c_str();
    }
};
} // namespace Blob

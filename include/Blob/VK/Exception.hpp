#pragma once

#include <exception>
#include <string>
#include <utility>
#ifdef __cpp_lib_source_location
#include <source_location>
#endif

namespace Blob::VK {
class Exception : public std::exception {
private:
    const std::string errorMsg;

public:
    explicit Exception(const std::string &errorMsg) : errorMsg(errorMsg) {}
#ifdef __cpp_lib_source_location
    template<class T>
    explicit Exception(T *t, std::string errorMsg, const std::source_location &location = std::source_location::current()) :
        errorMsg(std::string(typeid(t).name()) + location.file_name() + location.line() + location.function_name() + errorMsg) {}
#else
    template<class T>
    explicit Exception(T *t, std::string errorMsg) : errorMsg(std::string("VK::") + typeid(T).name() + " : " + errorMsg) {}
#endif
    [[nodiscard]] const char *what() const noexcept override { return errorMsg.c_str(); }
};
} // namespace Blob::VK
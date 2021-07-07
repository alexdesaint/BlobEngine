#include <algorithm>
#include <cstddef>

namespace Blob {
template<size_t N>
struct FilePath {
    constexpr FilePath(const char (&str)[N]) { std::copy_n(str, N, value); }

    static const size_t size = N;
    char value[N];
};
} // namespace Blob
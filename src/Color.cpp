#include <Blob/Color.hpp>
namespace Blob {

std::ostream &operator<<(std::ostream &out, const Color &vec) {
    out << "(" << vec.R << ", " << vec.G << ", " << vec.B << ", " << vec.A
        << ")" << std::endl;
    return out;
}

} // namespace Blob

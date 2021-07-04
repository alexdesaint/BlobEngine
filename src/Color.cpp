#include <Blob/Color.hpp>
namespace Blob::Color {

std::ostream &operator<<(std::ostream &out, const RGB &vec) {
    out << "(" << vec.R << ", " << vec.G << ", "
        << vec.B /*<< ", " << vec.A*/ << ")" << std::endl;
    return out;
}

std::ostream &operator<<(std::ostream &out, const RGBA &vec) {
    out << "(" << vec.R << ", " << vec.G << ", " << vec.B << ", " << vec.A
        << ")" << std::endl;
    return out;
}

} // namespace Blob::Color
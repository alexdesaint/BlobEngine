#include <Blob/Geometrie.hpp>

namespace Blob::Maths {

bool Circle::overlap(const Rectangle &r) {
    return false;
}

bool Circle::overlap(const Circle &r) {
    return false;
}

bool Circle::overlap(const Line &r) {
    return false;
}

} // namespace Blob::Maths
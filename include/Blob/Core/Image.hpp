#pragma once

#include <Blob/Maths.inl>
#include <string>
#include <Blob/Color.hpp>

namespace Blob::Core {

class Image {
private:
public:
    unsigned char *data;
    Maths::Vec2<size_t> size;
    enum Channel { DFAULT = 0, GREY = 1, GREY_ALPHA = 2, RGB = 3, RGBA = 4 } channel = DFAULT;
    explicit Image(const std::string &path);
    Image(unsigned char *data, const Maths::Vec2<size_t>& size, Channel channel);
    ~Image();

    Color::RGBA getPixel(const Blob::Maths::Vec2<size_t> &position);

    [[nodiscard]] Image getSubImage(const Blob::Maths::Vec2<size_t> &size, const Blob::Maths::Vec2<size_t> &position) const;
};

} // namespace Blob::Core
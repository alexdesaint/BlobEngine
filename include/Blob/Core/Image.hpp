#pragma once

#include <Blob/Color.hpp>
#include <Blob/Maths.inl>
#include <string>

namespace Blob {

class Image {
private:
public:
    unsigned char *data;
    Vec2<size_t> size;
    enum Channel {
        DFAULT = 0,
        GREY = 1,
        GREY_ALPHA = 2,
        RGB = 3,
        RGBA = 4
    } channel = DFAULT;
    explicit Image(const std::string &path);
    Image(unsigned char *data, const Vec2<size_t> &size, Channel channel);
    ~Image();

    Color::RGBA getPixel(const Blob::Vec2<size_t> &position);

    Image getSubImage(const Blob::Vec2<size_t> &size,
                                    const Blob::Vec2<size_t> &position) const;
};

} // namespace Blob
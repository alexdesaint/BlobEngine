#include <Blob/Exception.hpp>
#include <Blob/Image.hpp>

#define STB_IMAGE_IMPLEMENTATION

#include <stb/stb_image.h>

namespace Blob {

Image::Image(const std::string &path) {
    int width, height;
    data = stbi_load(path.c_str(),
                     &width,
                     &height,
                     (int *) &channel,
                     STBI_default);
    size.x = width;
    size.y = height;
    if (data == nullptr)
        throw Blob::Exception(std::string("Loading image failed (") + path +
                              "):" + stbi_failure_reason());
}

Image::Image(unsigned char *data, const Vec2<size_t> &size, Channel channel) :
    data(data), size(size), channel(channel) {}

Image::~Image() {
    stbi_image_free(data);
}

Color Image::getPixel(const Blob::Vec2<size_t> &position) {
    switch (channel) {
    case RGB:
        return Color{data[3 * (position.y * size.x + position.x) + 0],
                     data[3 * (position.y * size.x + position.x) + 1],
                     data[3 * (position.y * size.x + position.x) + 2],
                     1};
    case RGBA:
        return Color{data[4 * (position.y * size.x + position.x) + 0],
                     data[4 * (position.y * size.x + position.x) + 1],
                     data[4 * (position.y * size.x + position.x) + 2],
                     data[4 * (position.y * size.x + position.x) + 3]};
    case GREY:
    case GREY_ALPHA:
    default:
        throw Blob::Exception("Incompatible image channel");
    }
}

void getPixel(const stbi_uc *image,
              size_t imageWidth,
              size_t x,
              size_t y,
              stbi_uc *r,
              stbi_uc *g,
              stbi_uc *b,
              stbi_uc *a) {
    *r = image[4 * (y * imageWidth + x) + 0];
    *g = image[4 * (y * imageWidth + x) + 1];
    *b = image[4 * (y * imageWidth + x) + 2];
    *a = image[4 * (y * imageWidth + x) + 3];
}

Image Image::getSubImage(const Vec2<size_t> &size_,
                         const Vec2<size_t> &position) const {
    auto *newData =
        static_cast<unsigned char *>(malloc(size_.x * size_.y * channel));

    if ((size_.x + position.x > size.x) || (size_.y + position.y > size.y))
        throw Blob::Exception(
            std::string("Image::getSubImage is out of the image: \n") +
            "requested pos : " + std::to_string(position.x) + ", " +
            std::to_string(position.y) + "\n" + "requested size : " +
            std::to_string(size_.x) + ", " + std::to_string(size_.y) + "\n" +
            "current size : " + std::to_string(size.x) + ", " +
            std::to_string(size.y) + "\n");

    for (unsigned int x = 0; x < size_.x; x++)
        for (unsigned int y = 0; y < size_.y; y++)
            for (unsigned int channel_ = 0; channel_ < channel; channel_++)
                newData[channel * (y * size_.x + x) + channel_] =
                    data[channel *
                             ((y + position.y) * size.x + position.x + x) +
                         channel_];

    return Image(newData, size_, channel);
}
} // namespace Blob
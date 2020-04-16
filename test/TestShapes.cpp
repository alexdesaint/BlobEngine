#include <cstdint>
#include <glm/vec3.hpp>
#include <iostream>
#include <vector>

const uint8_t prismeBuffer[] = {
    0xf3, 0x04, 0x35, 0x3f, 0xf3, 0x04, 0x35, 0x3f, 0x00, 0x00, 0x80, 0x3f, 0xf3, 0x04, 0x35, 0x3f, 0xf3, 0x04, 0x35, 0x3f, 0x00, 0x00, 0x80, 0xbf,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x80, 0x3f,
    0x00, 0x00, 0x80, 0x3f, 0x2e, 0xbd, 0x3b, 0xb3, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x80, 0x3f, 0x2e, 0xbd, 0x3b, 0xb3, 0x00, 0x00, 0x80, 0xbf,
    0xf3, 0x04, 0x35, 0x3f, 0xf3, 0x04, 0x35, 0x3f, 0x00, 0x00, 0x80, 0xbf, 0xf3, 0x04, 0x35, 0x3f, 0xf3, 0x04, 0x35, 0x3f, 0x00, 0x00, 0x80, 0x3f,
    0xf3, 0x04, 0x35, 0x3f, 0xf3, 0x04, 0x35, 0xbf, 0x00, 0x00, 0x80, 0x3f, 0xf3, 0x04, 0x35, 0x3f, 0xf3, 0x04, 0x35, 0xbf, 0x00, 0x00, 0x80, 0xbf,
    0x00, 0x00, 0x80, 0x3f, 0x2e, 0xbd, 0x3b, 0xb3, 0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x80, 0x3f, 0x2e, 0xbd, 0x3b, 0xb3, 0x00, 0x00, 0x80, 0x3f,
    0x2e, 0xbd, 0xbb, 0xb3, 0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x80, 0x3f, 0x2e, 0xbd, 0xbb, 0xb3, 0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x80, 0xbf,
    0xf3, 0x04, 0x35, 0x3f, 0xf3, 0x04, 0x35, 0xbf, 0x00, 0x00, 0x80, 0xbf, 0xf3, 0x04, 0x35, 0x3f, 0xf3, 0x04, 0x35, 0xbf, 0x00, 0x00, 0x80, 0x3f,
    0xf5, 0x04, 0x35, 0xbf, 0xf1, 0x04, 0x35, 0xbf, 0x00, 0x00, 0x80, 0x3f, 0xf5, 0x04, 0x35, 0xbf, 0xf1, 0x04, 0x35, 0xbf, 0x00, 0x00, 0x80, 0xbf,
    0x2e, 0xbd, 0xbb, 0xb3, 0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x80, 0xbf, 0x2e, 0xbd, 0xbb, 0xb3, 0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x80, 0x3f,
    0x00, 0x00, 0x80, 0xbf, 0x2e, 0xde, 0x4c, 0x32, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x80, 0xbf, 0x2e, 0xde, 0x4c, 0x32, 0x00, 0x00, 0x80, 0xbf,
    0xf5, 0x04, 0x35, 0xbf, 0xf1, 0x04, 0x35, 0xbf, 0x00, 0x00, 0x80, 0xbf, 0xf5, 0x04, 0x35, 0xbf, 0xf1, 0x04, 0x35, 0xbf, 0x00, 0x00, 0x80, 0x3f,
    0xf3, 0x04, 0x35, 0x3f, 0xf3, 0x04, 0x35, 0x3f, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x80, 0x3f,
    0xf5, 0x04, 0x35, 0xbf, 0xf2, 0x04, 0x35, 0x3f, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x80, 0x3f, 0x2e, 0xbd, 0x3b, 0xb3, 0x00, 0x00, 0x80, 0x3f,
    0x00, 0x00, 0x80, 0xbf, 0x2e, 0xde, 0x4c, 0x32, 0x00, 0x00, 0x80, 0x3f, 0xf5, 0x04, 0x35, 0xbf, 0xf1, 0x04, 0x35, 0xbf, 0x00, 0x00, 0x80, 0x3f,
    0xf3, 0x04, 0x35, 0x3f, 0xf3, 0x04, 0x35, 0xbf, 0x00, 0x00, 0x80, 0x3f, 0x2e, 0xbd, 0xbb, 0xb3, 0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x80, 0x3f,
    0xf5, 0x04, 0x35, 0xbf, 0xf2, 0x04, 0x35, 0x3f, 0x00, 0x00, 0x80, 0x3f, 0xf5, 0x04, 0x35, 0xbf, 0xf2, 0x04, 0x35, 0x3f, 0x00, 0x00, 0x80, 0xbf,
    0x00, 0x00, 0x80, 0xbf, 0x2e, 0xde, 0x4c, 0x32, 0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x80, 0xbf, 0x2e, 0xde, 0x4c, 0x32, 0x00, 0x00, 0x80, 0x3f,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x80, 0xbf,
    0xf5, 0x04, 0x35, 0xbf, 0xf2, 0x04, 0x35, 0x3f, 0x00, 0x00, 0x80, 0xbf, 0xf5, 0x04, 0x35, 0xbf, 0xf2, 0x04, 0x35, 0x3f, 0x00, 0x00, 0x80, 0x3f,
    0xf5, 0x04, 0x35, 0xbf, 0xf2, 0x04, 0x35, 0x3f, 0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x80, 0xbf,
    0xf3, 0x04, 0x35, 0x3f, 0xf3, 0x04, 0x35, 0x3f, 0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x80, 0x3f, 0x2e, 0xbd, 0x3b, 0xb3, 0x00, 0x00, 0x80, 0xbf,
    0x00, 0x00, 0x80, 0xbf, 0x2e, 0xde, 0x4c, 0x32, 0x00, 0x00, 0x80, 0xbf, 0xf5, 0x04, 0x35, 0xbf, 0xf1, 0x04, 0x35, 0xbf, 0x00, 0x00, 0x80, 0xbf,
    0xf3, 0x04, 0x35, 0x3f, 0xf3, 0x04, 0x35, 0xbf, 0x00, 0x00, 0x80, 0xbf, 0x2e, 0xbd, 0xbb, 0xb3, 0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x80, 0xbf,
    0x16, 0xef, 0xc3, 0x3e, 0x5f, 0x83, 0x6c, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x16, 0xef, 0xc3, 0x3e, 0x5f, 0x83, 0x6c, 0x3f, 0x00, 0x00, 0x00, 0x00,
    0x16, 0xef, 0xc3, 0x3e, 0x5f, 0x83, 0x6c, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x16, 0xef, 0xc3, 0x3e, 0x5f, 0x83, 0x6c, 0x3f, 0x00, 0x00, 0x00, 0x00,
    0x5f, 0x83, 0x6c, 0x3f, 0x15, 0xef, 0xc3, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x5f, 0x83, 0x6c, 0x3f, 0x15, 0xef, 0xc3, 0x3e, 0x00, 0x00, 0x00, 0x00,
    0x5f, 0x83, 0x6c, 0x3f, 0x15, 0xef, 0xc3, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x5f, 0x83, 0x6c, 0x3f, 0x15, 0xef, 0xc3, 0x3e, 0x00, 0x00, 0x00, 0x00,
    0x5f, 0x83, 0x6c, 0x3f, 0x17, 0xef, 0xc3, 0xbe, 0x00, 0x00, 0x00, 0x00, 0x5f, 0x83, 0x6c, 0x3f, 0x17, 0xef, 0xc3, 0xbe, 0x00, 0x00, 0x00, 0x00,
    0x5f, 0x83, 0x6c, 0x3f, 0x17, 0xef, 0xc3, 0xbe, 0x00, 0x00, 0x00, 0x00, 0x5f, 0x83, 0x6c, 0x3f, 0x17, 0xef, 0xc3, 0xbe, 0x00, 0x00, 0x00, 0x00,
    0x15, 0xef, 0xc3, 0x3e, 0x5f, 0x83, 0x6c, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x15, 0xef, 0xc3, 0x3e, 0x5f, 0x83, 0x6c, 0xbf, 0x00, 0x00, 0x00, 0x00,
    0x15, 0xef, 0xc3, 0x3e, 0x5f, 0x83, 0x6c, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x15, 0xef, 0xc3, 0x3e, 0x5f, 0x83, 0x6c, 0xbf, 0x00, 0x00, 0x00, 0x00,
    0x19, 0xef, 0xc3, 0xbe, 0x5d, 0x83, 0x6c, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x19, 0xef, 0xc3, 0xbe, 0x5d, 0x83, 0x6c, 0xbf, 0x00, 0x00, 0x00, 0x00,
    0x19, 0xef, 0xc3, 0xbe, 0x5d, 0x83, 0x6c, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x19, 0xef, 0xc3, 0xbe, 0x5d, 0x83, 0x6c, 0xbf, 0x00, 0x00, 0x00, 0x00,
    0x5e, 0x83, 0x6c, 0xbf, 0x12, 0xef, 0xc3, 0xbe, 0x00, 0x00, 0x00, 0x00, 0x5e, 0x83, 0x6c, 0xbf, 0x12, 0xef, 0xc3, 0xbe, 0x00, 0x00, 0x00, 0x00,
    0x5e, 0x83, 0x6c, 0xbf, 0x12, 0xef, 0xc3, 0xbe, 0x00, 0x00, 0x00, 0x00, 0x5e, 0x83, 0x6c, 0xbf, 0x12, 0xef, 0xc3, 0xbe, 0x00, 0x00, 0x00, 0x00,
    0xf3, 0x04, 0xb5, 0x32, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x7f, 0x3f, 0xf3, 0x04, 0xb5, 0x32, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x7f, 0x3f,
    0xf3, 0x04, 0xb5, 0x32, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x7f, 0x3f, 0xf3, 0x04, 0xb5, 0x32, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x7f, 0x3f,
    0xf3, 0x04, 0xb5, 0x32, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x7f, 0x3f, 0xf3, 0x04, 0xb5, 0x32, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x7f, 0x3f,
    0xf3, 0x04, 0xb5, 0x32, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x7f, 0x3f, 0xf3, 0x04, 0xb5, 0x32, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x7f, 0x3f,
    0x5f, 0x83, 0x6c, 0xbf, 0x12, 0xef, 0xc3, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x5f, 0x83, 0x6c, 0xbf, 0x12, 0xef, 0xc3, 0x3e, 0x00, 0x00, 0x00, 0x00,
    0x5f, 0x83, 0x6c, 0xbf, 0x12, 0xef, 0xc3, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x5f, 0x83, 0x6c, 0xbf, 0x12, 0xef, 0xc3, 0x3e, 0x00, 0x00, 0x00, 0x00,
    0x17, 0xef, 0xc3, 0xbe, 0x5f, 0x83, 0x6c, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x17, 0xef, 0xc3, 0xbe, 0x5f, 0x83, 0x6c, 0x3f, 0x00, 0x00, 0x00, 0x00,
    0x17, 0xef, 0xc3, 0xbe, 0x5f, 0x83, 0x6c, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x17, 0xef, 0xc3, 0xbe, 0x5f, 0x83, 0x6c, 0x3f, 0x00, 0x00, 0x00, 0x00,
    0xb6, 0xc3, 0x87, 0x33, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x7f, 0xbf, 0xb6, 0xc3, 0x87, 0x33, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x7f, 0xbf,
    0xb6, 0xc3, 0x87, 0x33, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x7f, 0xbf, 0xb6, 0xc3, 0x87, 0x33, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x7f, 0xbf,
    0xb6, 0xc3, 0x87, 0x33, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x7f, 0xbf, 0xb6, 0xc3, 0x87, 0x33, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x7f, 0xbf,
    0xb6, 0xc3, 0x87, 0x33, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x7f, 0xbf, 0xb6, 0xc3, 0x87, 0x33, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x7f, 0xbf,
    0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x03, 0x00, 0x04, 0x00, 0x05, 0x00, 0x06, 0x00, 0x04, 0x00, 0x06, 0x00, 0x07, 0x00,
    0x08, 0x00, 0x09, 0x00, 0x0a, 0x00, 0x08, 0x00, 0x0a, 0x00, 0x0b, 0x00, 0x0c, 0x00, 0x0d, 0x00, 0x0e, 0x00, 0x0c, 0x00, 0x0e, 0x00, 0x0f, 0x00,
    0x10, 0x00, 0x11, 0x00, 0x12, 0x00, 0x10, 0x00, 0x12, 0x00, 0x13, 0x00, 0x14, 0x00, 0x15, 0x00, 0x16, 0x00, 0x14, 0x00, 0x16, 0x00, 0x17, 0x00,
    0x18, 0x00, 0x19, 0x00, 0x1a, 0x00, 0x1b, 0x00, 0x18, 0x00, 0x1a, 0x00, 0x1b, 0x00, 0x1a, 0x00, 0x1c, 0x00, 0x1b, 0x00, 0x1c, 0x00, 0x1d, 0x00,
    0x1e, 0x00, 0x1b, 0x00, 0x1d, 0x00, 0x1e, 0x00, 0x1d, 0x00, 0x1f, 0x00, 0x20, 0x00, 0x21, 0x00, 0x22, 0x00, 0x20, 0x00, 0x22, 0x00, 0x23, 0x00,
    0x24, 0x00, 0x25, 0x00, 0x26, 0x00, 0x24, 0x00, 0x26, 0x00, 0x27, 0x00, 0x28, 0x00, 0x29, 0x00, 0x2a, 0x00, 0x28, 0x00, 0x2a, 0x00, 0x2b, 0x00,
    0x2c, 0x00, 0x28, 0x00, 0x2b, 0x00, 0x2d, 0x00, 0x2c, 0x00, 0x2b, 0x00, 0x2d, 0x00, 0x2b, 0x00, 0x2e, 0x00, 0x2f, 0x00, 0x2d, 0x00, 0x2e, 0x00};

const uint8_t cubeBuffer[] = {
    0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x80, 0x3f,
    0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x80, 0x3f,
    0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x80, 0xbf,
    0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x80, 0x3f,
    0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x80, 0xbf,
    0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x80, 0x3f,
    0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x80, 0xbf,
    0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x80, 0xbf,
    0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x80, 0xbf,
    0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x80, 0x3f,
    0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x80, 0xbf,
    0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x80, 0x3f,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x80, 0x3f,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x80, 0x3f,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xbf,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xbf,
    0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x03, 0x00, 0x04, 0x00, 0x05, 0x00, 0x06, 0x00, 0x04, 0x00, 0x06, 0x00, 0x07, 0x00,
    0x08, 0x00, 0x09, 0x00, 0x0a, 0x00, 0x08, 0x00, 0x0a, 0x00, 0x0b, 0x00, 0x0c, 0x00, 0x0d, 0x00, 0x0e, 0x00, 0x0c, 0x00, 0x0e, 0x00, 0x0f, 0x00,
    0x10, 0x00, 0x11, 0x00, 0x12, 0x00, 0x10, 0x00, 0x12, 0x00, 0x13, 0x00, 0x14, 0x00, 0x15, 0x00, 0x16, 0x00, 0x14, 0x00, 0x16, 0x00, 0x17, 0x00};
using namespace std;
using namespace glm;
void decode(uint8_t *buffer, const int posNormalLen, const int indicesLen) {
    union {
        float f;
        uint8_t b[4];
    } u;

    std::vector<vec3> pos(posNormalLen);
    std::vector<vec3> normal(posNormalLen);
    uint16_t indices[indicesLen];
    {
        int posIndex = 0;
        int localPosIndex = 0;
        for (int i = 0; i < (posNormalLen * 3 * 4); i += 4) {
            u.b[3] = buffer[3 + i];
            u.b[2] = buffer[2 + i];
            u.b[1] = buffer[1 + i];
            u.b[0] = buffer[0 + i];
            pos[posIndex][localPosIndex] = u.f;
            localPosIndex++;
            if (localPosIndex == 3) {
                localPosIndex = 0;
                posIndex++;
            }
        }
    }
    {
        int posIndex = 0;
        int localPosIndex = 0;
        for (int i = (posNormalLen * 3 * 4); i < (posNormalLen * 3 * 4 * 2); i += 4) {
            u.b[3] = buffer[3 + i];
            u.b[2] = buffer[2 + i];
            u.b[1] = buffer[1 + i];
            u.b[0] = buffer[0 + i];
            normal[posIndex][localPosIndex] = u.f;
            localPosIndex++;
            if (localPosIndex == 3) {
                localPosIndex = 0;

                posIndex++;
            }
        }
    }
    {
        printf("Pos, Normals :\n");
        for (int i = 0; i < posNormalLen; i++) {
            printf("{{%1.1ff, %1.1ff, %1.1ff}, {%1.1ff, %1.1ff, %1.1ff}},\n", pos[i].x, pos[i].y, pos[i].z, normal[i].x, normal[i].y, normal[i].z);
        }
    }
    union {
        uint16_t f;
        uint8_t b[2];
    } v;

    {
        printf("Indices :\n");
        int cursor = 0;
        for (int i = (posNormalLen * 3 * 4 * 2); i < ((posNormalLen * 3 * 4 * 2) + indicesLen * 2); i += 2) {
            v.b[1] = buffer[1 + i];
            v.b[0] = buffer[0 + i];
            indices[cursor] = v.f;
            cout << indices[cursor] << ", ";
            cursor++;
        }
        cout << endl;
    }
}

int main(){
    printf("Cube :\n");
    decode((uint8_t *)cubeBuffer, 24, 36);
    printf("Prisme :\n");
    decode((uint8_t *)prismeBuffer, 48, 84);
}

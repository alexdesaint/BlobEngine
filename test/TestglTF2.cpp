#include "Blob/Maths.inl"
#include <Blob/Core/Exception.hpp>
#include <Blob/Core/Window.hpp>
#include <Blob/Materials.hpp>
#include <Blob/glTF2/SceneManager.hpp>

#include <Blob/Time.hpp>
#include <iostream>

using namespace Blob;

struct Primitives {
    constexpr static const std::array<uint8_t, 2880> data{
        0,   0,   128, 63,  0,   0,   128, 63,  0,   0,   128, 63,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   128, 63,  0,   0,   128, 191,
        0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   128, 63,  0,   0,   32,  63,  0,   0,   0,   63,  0,   0,   128, 191, 0,   0,   128, 63,
        0,   0,   128, 63,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   128, 63,  0,   0,   128, 191, 0,   0,   0,   0,   0,   0,   0,   0,
        0,   0,   128, 63,  0,   0,   96,  63,  0,   0,   0,   63,  0,   0,   128, 191, 0,   0,   128, 191, 0,   0,   128, 63,  0,   0,   0,   0,
        0,   0,   0,   0,   0,   0,   128, 63,  0,   0,   128, 191, 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   128, 63,  0,   0,   96,  63,
        0,   0,   128, 62,  0,   0,   128, 63,  0,   0,   128, 191, 0,   0,   128, 63,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   128, 63,
        0,   0,   128, 191, 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   128, 63,  0,   0,   32,  63,  0,   0,   128, 62,  0,   0,   128, 63,
        0,   0,   128, 191, 0,   0,   128, 191, 0,   0,   0,   0,   0,   0,   128, 191, 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
        0,   0,   128, 63,  0,   0,   128, 63,  0,   0,   192, 62,  0,   0,   128, 62,  0,   0,   128, 63,  0,   0,   128, 191, 0,   0,   128, 63,
        0,   0,   0,   0,   0,   0,   128, 191, 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   128, 63,  0,   0,   128, 63,
        0,   0,   32,  63,  0,   0,   128, 62,  0,   0,   128, 191, 0,   0,   128, 191, 0,   0,   128, 63,  0,   0,   0,   0,   0,   0,   128, 191,
        0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   128, 63,  0,   0,   128, 63,  0,   0,   32,  63,  0,   0,   0,   0,
        0,   0,   128, 191, 0,   0,   128, 191, 0,   0,   128, 191, 0,   0,   0,   0,   0,   0,   128, 191, 0,   0,   0,   0,   0,   0,   0,   0,
        0,   0,   0,   0,   0,   0,   128, 63,  0,   0,   128, 63,  0,   0,   192, 62,  0,   0,   0,   0,   0,   0,   128, 191, 0,   0,   128, 191,
        0,   0,   128, 191, 0,   0,   128, 191, 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   128, 63,
        0,   0,   128, 63,  0,   0,   192, 62,  0,   0,   128, 63,  0,   0,   128, 191, 0,   0,   128, 191, 0,   0,   128, 63,  0,   0,   128, 191,
        0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   128, 63,  0,   0,   128, 63,  0,   0,   32,  63,
        0,   0,   128, 63,  0,   0,   128, 191, 0,   0,   128, 63,  0,   0,   128, 63,  0,   0,   128, 191, 0,   0,   0,   0,   0,   0,   0,   0,
        0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   128, 63,  0,   0,   128, 63,  0,   0,   32,  63,  0,   0,   64,  63,  0,   0,   128, 191,
        0,   0,   128, 63,  0,   0,   128, 191, 0,   0,   128, 191, 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
        0,   0,   128, 63,  0,   0,   128, 63,  0,   0,   192, 62,  0,   0,   64,  63,  0,   0,   128, 191, 0,   0,   128, 63,  0,   0,   128, 191,
        0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   128, 191, 0,   0,   128, 63,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   128, 63,
        0,   0,   0,   62,  0,   0,   0,   63,  0,   0,   128, 63,  0,   0,   128, 63,  0,   0,   128, 191, 0,   0,   0,   0,   0,   0,   0,   0,
        0,   0,   128, 191, 0,   0,   128, 63,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   128, 63,  0,   0,   192, 62,  0,   0,   0,   63,
        0,   0,   128, 63,  0,   0,   128, 191, 0,   0,   128, 191, 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   128, 191, 0,   0,   128, 63,
        0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   128, 63,  0,   0,   192, 62,  0,   0,   128, 62,  0,   0,   128, 191, 0,   0,   128, 191,
        0,   0,   128, 191, 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   128, 191, 0,   0,   128, 63,  0,   0,   0,   0,   0,   0,   0,   0,
        0,   0,   128, 63,  0,   0,   0,   62,  0,   0,   128, 62,  0,   0,   128, 63,  0,   0,   128, 63,  0,   0,   128, 191, 0,   0,   128, 63,
        0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   128, 63,  0,   0,   128, 63,  0,   0,   192, 62,
        0,   0,   0,   63,  0,   0,   128, 63,  0,   0,   128, 63,  0,   0,   128, 63,  0,   0,   128, 63,  0,   0,   0,   0,   0,   0,   0,   0,
        0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   128, 63,  0,   0,   128, 63,  0,   0,   32,  63,  0,   0,   0,   63,  0,   0,   128, 63,
        0,   0,   128, 191, 0,   0,   128, 63,  0,   0,   128, 63,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
        0,   0,   128, 63,  0,   0,   128, 63,  0,   0,   32,  63,  0,   0,   128, 62,  0,   0,   128, 63,  0,   0,   128, 191, 0,   0,   128, 191,
        0,   0,   128, 63,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   128, 63,  0,   0,   128, 63,
        0,   0,   192, 62,  0,   0,   128, 62,  0,   0,   128, 191, 0,   0,   128, 63,  0,   0,   128, 191, 0,   0,   0,   0,   0,   0,   128, 63,
        0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   128, 63,  0,   0,   128, 63,  0,   0,   192, 62,  0,   0,   64,  63,
        0,   0,   128, 191, 0,   0,   128, 63,  0,   0,   128, 63,  0,   0,   0,   0,   0,   0,   128, 63,  0,   0,   0,   0,   0,   0,   0,   0,
        0,   0,   0,   0,   0,   0,   128, 63,  0,   0,   128, 63,  0,   0,   32,  63,  0,   0,   64,  63,  0,   0,   128, 63,  0,   0,   128, 63,
        0,   0,   128, 63,  0,   0,   0,   0,   0,   0,   128, 63,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   128, 63,
        0,   0,   128, 63,  0,   0,   32,  63,  0,   0,   0,   63,  0,   0,   128, 63,  0,   0,   128, 63,  0,   0,   128, 191, 0,   0,   0,   0,
        0,   0,   128, 63,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   128, 63,  0,   0,   128, 63,  0,   0,   192, 62,
        0,   0,   0,   63,  0,   0,   128, 191, 0,   0,   128, 191, 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   128, 63,
        0,   0,   128, 63,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   128, 63,  0,   0,   0,   0,   0,   0,   128, 63,  0,   0,   128, 63,
        0,   0,   128, 191, 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   128, 63,  0,   0,   128, 63,  0,   0,   0,   0,
        0,   0,   0,   0,   0,   0,   128, 63,  0,   0,   128, 63,  0,   0,   128, 63,  0,   0,   128, 63,  0,   0,   128, 63,  0,   0,   0,   0,
        0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   128, 63,  0,   0,   128, 63,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   128, 63,
        0,   0,   128, 63,  0,   0,   0,   0,   0,   0,   128, 191, 0,   0,   128, 63,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
        0,   0,   128, 63,  0,   0,   128, 63,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   128, 63,  0,   0,   0,   0,   0,   0,   0,   0,
        0,   0,   0,   0,   0,   0,   128, 63,  0,   0,   128, 191, 22,  239, 195, 62,  95,  131, 108, 63,  0,   0,   0,   0,   0,   0,   128, 63,
        0,   0,   0,   63,  0,   0,   0,   0,   0,   0,   128, 63,  0,   0,   128, 63,  22,  239, 195, 62,  95,  131, 108, 63,  0,   0,   0,   0,
        0,   0,   128, 63,  0,   0,   0,   0,   243, 4,   53,  63,  243, 4,   53,  63,  0,   0,   128, 63,  22,  239, 195, 62,  95,  131, 108, 63,
        0,   0,   0,   0,   0,   0,   96,  63,  0,   0,   0,   0,   243, 4,   53,  63,  243, 4,   53,  63,  0,   0,   128, 191, 22,  239, 195, 62,
        95,  131, 108, 63,  0,   0,   0,   0,   0,   0,   96,  63,  0,   0,   0,   63,  243, 4,   53,  63,  243, 4,   53,  63,  0,   0,   128, 191,
        95,  131, 108, 63,  21,  239, 195, 62,  0,   0,   0,   0,   0,   0,   96,  63,  0,   0,   0,   63,  243, 4,   53,  63,  243, 4,   53,  63,
        0,   0,   128, 63,  95,  131, 108, 63,  21,  239, 195, 62,  0,   0,   0,   0,   0,   0,   96,  63,  0,   0,   0,   0,   0,   0,   128, 63,
        46,  189, 59,  179, 0,   0,   128, 63,  95,  131, 108, 63,  21,  239, 195, 62,  0,   0,   0,   0,   0,   0,   64,  63,  0,   0,   0,   0,
        0,   0,   128, 63,  46,  189, 59,  179, 0,   0,   128, 191, 95,  131, 108, 63,  21,  239, 195, 62,  0,   0,   0,   0,   0,   0,   64,  63,
        0,   0,   0,   63,  0,   0,   128, 63,  46,  189, 59,  179, 0,   0,   128, 191, 95,  131, 108, 63,  23,  239, 195, 190, 0,   0,   0,   0,
        0,   0,   64,  63,  0,   0,   0,   63,  0,   0,   128, 63,  46,  189, 59,  179, 0,   0,   128, 63,  95,  131, 108, 63,  23,  239, 195, 190,
        0,   0,   0,   0,   0,   0,   64,  63,  0,   0,   0,   0,   243, 4,   53,  63,  243, 4,   53,  191, 0,   0,   128, 63,  95,  131, 108, 63,
        23,  239, 195, 190, 0,   0,   0,   0,   0,   0,   32,  63,  0,   0,   0,   0,   243, 4,   53,  63,  243, 4,   53,  191, 0,   0,   128, 191,
        95,  131, 108, 63,  23,  239, 195, 190, 0,   0,   0,   0,   0,   0,   32,  63,  0,   0,   0,   63,  243, 4,   53,  63,  243, 4,   53,  191,
        0,   0,   128, 191, 21,  239, 195, 62,  95,  131, 108, 191, 0,   0,   0,   0,   0,   0,   32,  63,  0,   0,   0,   63,  243, 4,   53,  63,
        243, 4,   53,  191, 0,   0,   128, 63,  21,  239, 195, 62,  95,  131, 108, 191, 0,   0,   0,   0,   0,   0,   32,  63,  0,   0,   0,   0,
        46,  189, 187, 179, 0,   0,   128, 191, 0,   0,   128, 63,  21,  239, 195, 62,  95,  131, 108, 191, 0,   0,   0,   0,   0,   0,   0,   63,
        0,   0,   0,   0,   46,  189, 187, 179, 0,   0,   128, 191, 0,   0,   128, 191, 21,  239, 195, 62,  95,  131, 108, 191, 0,   0,   0,   0,
        0,   0,   0,   63,  0,   0,   0,   63,  46,  189, 187, 179, 0,   0,   128, 191, 0,   0,   128, 191, 25,  239, 195, 190, 93,  131, 108, 191,
        0,   0,   0,   0,   0,   0,   0,   63,  0,   0,   0,   63,  46,  189, 187, 179, 0,   0,   128, 191, 0,   0,   128, 63,  25,  239, 195, 190,
        93,  131, 108, 191, 0,   0,   0,   0,   0,   0,   0,   63,  0,   0,   0,   0,   245, 4,   53,  191, 241, 4,   53,  191, 0,   0,   128, 63,
        25,  239, 195, 190, 93,  131, 108, 191, 0,   0,   0,   0,   0,   0,   192, 62,  0,   0,   0,   0,   245, 4,   53,  191, 241, 4,   53,  191,
        0,   0,   128, 191, 25,  239, 195, 190, 93,  131, 108, 191, 0,   0,   0,   0,   0,   0,   192, 62,  0,   0,   0,   63,  245, 4,   53,  191,
        241, 4,   53,  191, 0,   0,   128, 191, 94,  131, 108, 191, 18,  239, 195, 190, 0,   0,   0,   0,   0,   0,   192, 62,  0,   0,   0,   63,
        245, 4,   53,  191, 241, 4,   53,  191, 0,   0,   128, 63,  94,  131, 108, 191, 18,  239, 195, 190, 0,   0,   0,   0,   0,   0,   192, 62,
        0,   0,   0,   0,   0,   0,   128, 191, 46,  222, 76,  50,  0,   0,   128, 63,  94,  131, 108, 191, 18,  239, 195, 190, 0,   0,   0,   0,
        0,   0,   128, 62,  0,   0,   0,   0,   0,   0,   128, 191, 46,  222, 76,  50,  0,   0,   128, 191, 94,  131, 108, 191, 18,  239, 195, 190,
        0,   0,   0,   0,   0,   0,   128, 62,  0,   0,   0,   63,  0,   0,   128, 63,  46,  189, 59,  179, 0,   0,   128, 63,  243, 4,   181, 50,
        0,   0,   0,   0,   255, 255, 127, 63,  72,  225, 250, 62,  0,   0,   64,  63,  243, 4,   53,  63,  243, 4,   53,  63,  0,   0,   128, 63,
        243, 4,   181, 50,  0,   0,   0,   0,   255, 255, 127, 63,  168, 227, 214, 62,  44,  142, 20,  63,  0,   0,   0,   0,   0,   0,   128, 63,
        0,   0,   128, 63,  243, 4,   181, 50,  0,   0,   0,   0,   255, 255, 127, 63,  0,   0,   128, 62,  92,  143, 2,   63,  245, 4,   53,  191,
        241, 4,   53,  63,  0,   0,   128, 63,  243, 4,   181, 50,  0,   0,   0,   0,   255, 255, 127, 63,  94,  113, 164, 61,  44,  142, 20,  63,
        0,   0,   128, 191, 46,  222, 76,  50,  0,   0,   128, 63,  243, 4,   181, 50,  0,   0,   0,   0,   255, 255, 127, 63,  16,  215, 35,  60,
        0,   0,   64,  63,  245, 4,   53,  191, 241, 4,   53,  191, 0,   0,   128, 63,  243, 4,   181, 50,  0,   0,   0,   0,   255, 255, 127, 63,
        94,  113, 164, 61,  212, 113, 107, 63,  46,  189, 187, 179, 0,   0,   128, 191, 0,   0,   128, 63,  243, 4,   181, 50,  0,   0,   0,   0,
        255, 255, 127, 63,  255, 255, 127, 62,  164, 112, 125, 63,  243, 4,   53,  63,  243, 4,   53,  191, 0,   0,   128, 63,  243, 4,   181, 50,
        0,   0,   0,   0,   255, 255, 127, 63,  168, 227, 214, 62,  212, 113, 107, 63,  0,   0,   128, 191, 46,  222, 76,  50,  0,   0,   128, 191,
        94,  131, 108, 191, 18,  239, 195, 62,  0,   0,   0,   0,   0,   0,   128, 62,  0,   0,   0,   63,  0,   0,   128, 191, 46,  222, 76,  50,
        0,   0,   128, 63,  94,  131, 108, 191, 18,  239, 195, 62,  0,   0,   0,   0,   0,   0,   128, 62,  0,   0,   0,   0,   245, 4,   53,  191,
        241, 4,   53,  63,  0,   0,   128, 63,  94,  131, 108, 191, 18,  239, 195, 62,  0,   0,   0,   0,   0,   0,   0,   62,  0,   0,   0,   0,
        245, 4,   53,  191, 241, 4,   53,  63,  0,   0,   128, 191, 94,  131, 108, 191, 18,  239, 195, 62,  0,   0,   0,   0,   0,   0,   0,   62,
        0,   0,   0,   63,  245, 4,   53,  191, 241, 4,   53,  63,  0,   0,   128, 191, 24,  239, 195, 190, 93,  131, 108, 63,  0,   0,   0,   0,
        0,   0,   0,   62,  0,   0,   0,   63,  245, 4,   53,  191, 241, 4,   53,  63,  0,   0,   128, 63,  24,  239, 195, 190, 93,  131, 108, 63,
        0,   0,   0,   0,   0,   0,   0,   62,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   128, 63,  0,   0,   128, 63,  24,  239, 195, 190,
        93,  131, 108, 63,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   128, 63,  0,   0,   128, 191,
        24,  239, 195, 190, 93,  131, 108, 63,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   63,  245, 4,   53,  191, 241, 4,   53,  63,
        0,   0,   128, 191, 243, 4,   53,  51,  0,   0,   0,   0,   255, 255, 127, 191, 44,  142, 20,  63,  44,  142, 20,  63,  0,   0,   0,   0,
        0,   0,   128, 63,  0,   0,   128, 191, 243, 4,   53,  51,  0,   0,   0,   0,   255, 255, 127, 191, 0,   0,   64,  63,  92,  143, 2,   63,
        243, 4,   53,  63,  243, 4,   53,  63,  0,   0,   128, 191, 243, 4,   53,  51,  0,   0,   0,   0,   255, 255, 127, 191, 212, 113, 107, 63,
        44,  142, 20,  63,  0,   0,   128, 63,  46,  189, 59,  179, 0,   0,   128, 191, 243, 4,   53,  51,  0,   0,   0,   0,   255, 255, 127, 191,
        164, 112, 125, 63,  0,   0,   64,  63,  243, 4,   53,  63,  243, 4,   53,  191, 0,   0,   128, 191, 243, 4,   53,  51,  0,   0,   0,   0,
        255, 255, 127, 191, 212, 113, 107, 63,  212, 113, 107, 63,  46,  189, 187, 179, 0,   0,   128, 191, 0,   0,   128, 191, 243, 4,   53,  51,
        0,   0,   0,   0,   255, 255, 127, 191, 0,   0,   64,  63,  164, 112, 125, 63,  245, 4,   53,  191, 241, 4,   53,  191, 0,   0,   128, 191,
        243, 4,   53,  51,  0,   0,   0,   0,   255, 255, 127, 191, 44,  142, 20,  63,  212, 113, 107, 63,  0,   0,   128, 191, 46,  222, 76,  50,
        0,   0,   128, 191, 243, 4,   53,  51,  0,   0,   0,   0,   255, 255, 127, 191, 92,  143, 2,   63,  0,   0,   64,  63,
    };
    Blob::Core::Buffer buffer{data.data(), data.size()};
    struct Materials {
        Blob::Materials::SingleColor defaultM;
    } materials;
    struct Mesh0 : public Core::Mesh {
        Blob::GL::VertexArrayObject attribute0;
        Blob::Core::Primitive primitive0;
        std::array<uint8_t, 72> indicesArray0{
            0,  0, 1,  0, 2,  0, 0,  0, 2,  0, 3,  0, 4,  0, 5,  0, 6,  0, 4,  0, 6,  0, 7,  0, 8,  0, 9,  0, 10, 0, 8,  0, 10, 0, 11, 0,
            12, 0, 13, 0, 14, 0, 12, 0, 14, 0, 15, 0, 16, 0, 17, 0, 18, 0, 16, 0, 18, 0, 19, 0, 20, 0, 21, 0, 22, 0, 20, 0, 22, 0, 23, 0,
        };
        Blob::Core::RenderOptions renderOptions;
        Mesh0(const Blob::Core::Buffer &buffer, const Materials &materials)
            : primitive0(&attribute0, &materials.defaultM, &renderOptions) {
            renderOptions.setIndices(indicesArray0.data(), 36, 5123);
            addPrimitive(primitive0);
            attribute0.setBuffer(buffer, 48, 0);
            attribute0.setArray(3, 0, 5126, 0, 0);
            attribute0.setArray(3, 1, 5126, 12, 0);
            attribute0.setArray(4, 2, 5126, 24, 0);
            attribute0.setArray(2, 3, 5126, 40, 0);
        }
    } mesh0;
    struct Mesh1 : public Core::Mesh {
        Blob::GL::VertexArrayObject attribute0;
        Blob::Core::Primitive primitive0;
        std::array<uint8_t, 12> indicesArray0{
            0, 0, 1, 0, 2, 0, 0, 0, 2, 0, 3, 0,
        };
        Blob::Core::RenderOptions renderOptions;
        Mesh1(const Blob::Core::Buffer &buffer, const Materials &materials)
            : primitive0(&attribute0, &materials.defaultM, &renderOptions) {
            renderOptions.setIndices(indicesArray0.data(), 6, 5123);
            addPrimitive(primitive0);
            attribute0.setBuffer(buffer, 48, 1152);
            attribute0.setArray(3, 0, 5126, 0, 0);
            attribute0.setArray(3, 1, 5126, 12, 0);
            attribute0.setArray(4, 2, 5126, 24, 0);
            attribute0.setArray(2, 3, 5126, 40, 0);
        }
    } mesh1;
    struct Mesh2 : public Core::Mesh {
        Blob::GL::VertexArrayObject attribute0;
        Blob::Core::Primitive primitive0;
        std::array<uint8_t, 168> indicesArray0{
            0,  0, 1,  0, 2,  0, 0,  0, 2,  0, 3,  0, 4,  0, 5,  0, 6,  0, 4,  0, 6,  0, 7,  0, 8,  0, 9,  0, 10, 0, 8,  0, 10, 0,
            11, 0, 12, 0, 13, 0, 14, 0, 12, 0, 14, 0, 15, 0, 16, 0, 17, 0, 18, 0, 16, 0, 18, 0, 19, 0, 20, 0, 21, 0, 22, 0, 20, 0,
            22, 0, 23, 0, 24, 0, 25, 0, 26, 0, 26, 0, 27, 0, 28, 0, 28, 0, 29, 0, 30, 0, 30, 0, 31, 0, 24, 0, 24, 0, 26, 0, 28, 0,
            28, 0, 30, 0, 24, 0, 32, 0, 33, 0, 34, 0, 32, 0, 34, 0, 35, 0, 36, 0, 37, 0, 38, 0, 36, 0, 38, 0, 39, 0, 40, 0, 41, 0,
            42, 0, 42, 0, 43, 0, 44, 0, 44, 0, 45, 0, 46, 0, 46, 0, 47, 0, 40, 0, 40, 0, 42, 0, 44, 0, 44, 0, 46, 0, 40, 0,
        };
        Blob::Core::RenderOptions renderOptions;
        Mesh2(const Blob::Core::Buffer &buffer, const Materials &materials)
            : primitive0(&attribute0, &materials.defaultM, &renderOptions) {
            renderOptions.setIndices(indicesArray0.data(), 84, 5123);
            addPrimitive(primitive0);
            attribute0.setBuffer(buffer, 32, 1344);
            attribute0.setArray(3, 0, 5126, 0, 0);
            attribute0.setArray(3, 1, 5126, 12, 0);
            attribute0.setArray(2, 3, 5126, 24, 0);
        }
    } mesh2;
    Blob::Core::Shape shape0{mesh0, Maths::ModelTransform{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1}};
    Blob::Core::Shape shape1{
        Maths::ModelTransform{-0.290865, 0.955171, -0.0551891, 0, -0.771101, -0.199883, 0.604525, 0, 0.566393, 0.218391, 0.794672, 0, 4.07625, 1.00545, 5.90386, 1}};
    Blob::Core::Shape shape2{
        Maths::ModelTransform{0.685921, 0.727676, 0, 0, -0.324014, 0.305421, 0.895396, 0, 0.651558, -0.61417, 0.445271, 0, 7.35889, -6.92579, 4.95831, 1}};
    Blob::Core::Shape shape3{Maths::ModelTransform{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1}};
    Blob::Core::Shape shape4{Maths::ModelTransform{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1}};
    Blob::Core::Scene scene0{{
        &shape0,
        &shape1,
        &shape2,
        &shape3,
        &shape4,
    }};
    Primitives()
        : mesh0(buffer, materials)
        , mesh1(buffer, materials)
        , mesh2(buffer, materials) {}
};

class test : private Core::KeyboardEvents {
private:
    Maths::Vec2<> speed;

    void keyboardUpdate(const Core::Key &keyboard) final {
        static const float maxSpeed = 1;

        speed = Maths::Vec2<>();

        if (keyboard.id == Blob::GLFW::Keys::LEFT)
            speed.y = maxSpeed;
        if (keyboard.id == Blob::GLFW::Keys::RIGHT)
            speed.y = -maxSpeed;
        if (keyboard.id == Blob::GLFW::Keys::UP)
            speed.x = maxSpeed;
        if (keyboard.id == Blob::GLFW::Keys::DOWN)
            speed.x = -maxSpeed;
    }

public:
    test(const std::string &path, const Maths::Vec3<> &pos, float angle) {
        try {
            std::cout << "test : " << path << std::endl;

            Core::Window window;

            glTF2::SceneManager sm(path);

            std::cout << sm;
            std::cout << sm.toCHeader() << std::endl;

            Core::Scene &mainScene = sm.scenes.front();
            mainScene.camera.setPosition(pos);
            mainScene.camera.setLookAt(pos + Maths::Vec3<>(1, 0, 0));
            mainScene.camera.setCameraUp( {0, 1, 0});

            window.projectionTransform.setRange(0.1, 1000);

            float flow = 0;
            while (window.isOpen()) {
                angle -= speed.y * flow;
                mainScene.camera.move({std::cos(angle) * speed.x * flow, 0, std::sin(angle) * speed.x * flow}, angle);
                window.draw(mainScene);

                flow = window.display();
            }

        } catch (Core::Exception &exception) { std::cout << exception.what() << std::endl; }
    }

    template<typename T>
    void templatetest(const Maths::Vec3<> &pos, float angle) {
        try {

            Core::Camera camera(pos, pos + Maths::Vec3<>(1, 0, 0), {0, 1, 0});

            Core::Window window;

            AssetManager a;

            window.projectionTransform.setRange(0.1, 1000);

            T t;

            float flow = 0;
            while (window.isOpen()) {
                angle -= speed.y * flow;
                camera.move({std::cos(angle) * speed.x * flow, 0, std::sin(angle) * speed.x * flow}, angle);
                window.draw(t.shape2, camera);

                flow = window.display();
            }

        } catch (Core::Exception &exception) { std::cout << exception.what() << std::endl; }
    }
};

int main() {
    Materials::PBR::light.position = {5, 5, 5};
    Core::Camera camera({0, 5, 5}, {0, 0, 0}, {0, 1, 0});

    test t("data/models/Primitives.gltf", {0, 0, 10}, 3.14 * (6 / 4.0));
    t.templatetest<Primitives>({0, 0, 10}, 3.14 * (6 / 4.0));

    camera = Core::Camera({0, 0.5, 3}, {0, 0.5, 0}, {0, 1, 0});
    /// Simple models for testing individual features
    //    test("/home/patapouf/gitClone/glTF-Sample-Models/2.0/TriangleWithoutIndices/glTF/TriangleWithoutIndices.gltf", camera);
    //    test("/home/patapouf/gitClone/glTF-Sample-Models/2.0/Triangle/glTF/Triangle.gltf", camera);
    //        test("/home/patapouf/gitClone/glTF-Sample-Models/2.0/AnimatedTriangle/glTF/AnimatedTriangle.gltf", camera);
    //        test("/home/patapouf/gitClone/glTF-Sample-Models/2.0/SimpleMeshes/glTF/SimpleMeshes.gltf", camera);

    // More complex models

    camera = Core::Camera({0, 3, 3}, {0, 0, 0}, {0, 1, 0});
    //    test t("/home/patapouf/gitClone/glTF-Sample-Models/2.0/Box/glTF/Box.gltf", {0, 0, 3}, 3.14 * (6 / 4.0));
    //    t.templatetest<Box>({0, 0, 3}, 3.14 * (6 / 4.0));
    //        test("/home/patapouf/gitClone/glTF-Sample-Models/2.0/BoxInterleaved/glTF/BoxInterleaved.gltf", camera);
    //        test("/home/patapouf/gitClone/glTF-Sample-Models/2.0/BoxTextured/glTF/BoxTextured.gltf", camera);
    //        test("/home/patapouf/gitClone/glTF-Sample-Models/2.0/BoxTexturedNonPowerOfTwo/glTF/BoxTexturedNonPowerOfTwo.gltf", camera);
    //            test("/home/patapouf/gitClone/glTF-Sample-Models/2.0/BoxVertexColors/glTF/BoxVertexColors.gltf", camera);

    //        test("/home/patapouf/gitClone/glTF-Sample-Models/2.0/Duck/glTF/Duck.gltf",
    //        Core::Camera({0, 300, 300}, {0, 70, 0}, {0, 1, 0}));
    //    Materials::PBR::light.position = {10, 10, -10};
    //        test("/home/patapouf/gitClone/glTF-Sample-Models/2.0/CesiumMilkTruck/glTF/CesiumMilkTruck.gltf",
    //             Core::Camera({0, 10, -10}, {0, -2, 0}, {0, -1, 0}));
    //    test("/home/patapouf/gitClone/glTF-Sample-Models/2.0/2CylinderEngine/glTF/2CylinderEngine.gltf",
    //         Core::Camera({0, -1000, -1000}, {0, 70, 0}, {0, 1, 0}));
    //        test("/home/patapouf/gitClone/glTF-Sample-Models/2.0/ReciprocatingSaw/glTF/ReciprocatingSaw.gltf",
    //             Core::Camera({0, -1000, -1000}, {0, 70, 0}, {0, 1, 0}));

    /// Tests
    //    test("/home/patapouf/gitClone/glTF-Sample-Models/2.0/AlphaBlendModeTest/glTF/AlphaBlendModeTest.gltf",
    //         Core::Camera({0, 3, 10}, {0, 0, 0}, {0, 1, 0}));
    //             test("/home/patapouf/gitClone/glTF-Sample-Models/2.0/TextureCoordinateTest/glTF/TextureCoordinateTest.gltf",
    //                  Core::Camera({0, 0.001, 4}, {0, 0, 0}, {0, 1, 0}));
    //                 test("/home/patapouf/gitClone/glTF-Sample-Models/2.0/TextureSettingsTest/glTF/TextureSettingsTest.gltf",
    //                      Core::Camera({0, 0.001, 20}, {0, 0, 0}, {0, 1, 0}));
    //        test("/home/patapouf/gitClone/glTF-Sample-Models/2.0/VertexColorTest/glTF/VertexColorTest.gltf",
    //             Core::Camera({0, 0.001, 5}, {0, 0, 0}, {0, 1, 0}));

    //    test("/home/patapouf/gitClone/glTF-Sample-Models/2.0/Sponza/glTF/Sponza.gltf", Core::Camera({0, 1.5, 0}, {0, 1.5, -1}, {0, 1, 0}));
    //    test("/home/patapouf/gitClone/glTF-Sample-Models/2.0/VC/glTF/VC.gltf", Core::Camera({0, 1.5, 0}, {0, 1.5, -1}, {0, 1, 0}));

    return 0;
}

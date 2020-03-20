#pragma once

#include <cstdint>
#include <ostream>

namespace Blob {
class Color {
public:
    float R = 0, G = 0, B = 0, A = 1.f;

    Color() = default;
    Color(uint32_t RGB) : R(((RGB >> 16) & 0xFF) / 255.f), G(((RGB >> 8) & 0xFF) / 255.f), B((RGB & 0xFF) / 255.f), A(1.f) {}
    Color(float R, float G, float B, float A = 0) : R(R), G(G), B(B), A(A) {}

    friend std::ostream &operator<<(std::ostream &out, const Color &vec);

    const static Color LightPink, Pink, Crimson, LavenderBlush, PaleVioletRed, HotPink, DeepPink, MediumVioletRed, Orchid, Thistle, Plum, Violet,
        Magenta, Fuchsia, DarkMagenta, Purple, MediumOrchid, DarkViolet, DarkOrchid, Indigo, BlueViolet, MediumPurple, MediumSlateBlue, SlateBlue,
        DarkSlateBlue, Lavender, GhostWhite, Blue, MediumBlue, MidnightBlue, DarkBlue, Navy, RoyalBlue, CornflowerBlue, LightSteelBlue,
        LightSlateGray, SlateGray, DodgerBlue, AliceBlue, SteelBlue, LightSkyBlue, SkyBlue, DeepSkyBlue, LightBlue, PowderBlue, CadetBlue, Azure,
        LightCyan, PaleTurquoise, Cyan, Aqua, DarkTurquoise, DarkSlateGray, DarkCyan, Teal, MediumTurquoise, LightSeaGreen, Turquoise, Aquamarine,
        MediumAquamarine, MediumSpringGreen, MintCream, SpringGreen, MediumSeaGreen, SeaGreen, Honeydew, LightGreen, PaleGreen, DarkSeaGreen,
        LimeGreen, Lime, ForestGreen, Green, DarkGreen, Chartreuse, LawnGreen, GreenYellow, DarkOliveGreen, YellowGreen, OliveDrab, Beige,
        LightGoldenrodYellow, Ivory, LightYellow, Yellow, Olive, DarkKhaki, LemonChiffon, PaleGoldenrod, Khaki, Gold, Cornsilk, Goldenrod,
        DarkGoldenrod, FloralWhite, OldLace, Wheat, Moccasin, Orange, PapayaWhip, BlanchedAlmond, NavajoWhite, AntiqueWhite, Tan, BurlyWood, Bisque,
        DarkOrange, Linen, Peru, PeachPuff, SandyBrown, Chocolate, SaddleBrown, Seashell, Sienna, LightSalmon, Coral, OrangeRed, DarkSalmon, Tomato,
        MistyRose, Salmon, Snow, LightCoral, RosyBrown, IndianRed, Red, Brown, FireBrick, DarkRed, Maroon, White, WhiteSmoke, Gainsboro, LightGrey,
        Silver, DarkGray, Gray, DimGray, Black;
};
} // namespace Blob

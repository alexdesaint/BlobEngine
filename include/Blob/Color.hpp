#pragma once

#include <cstdint>
#include <ostream>

namespace Blob::Color {

/// Color with float points representation.
class RGB {
public:
    ///@{
    /// @name Color channels
    float R = 0;
    float G = 0;
    float B = 0;
    // float A = 1.f;
    ///@}

    constexpr RGB() noexcept = default;

    constexpr RGB(uint8_t R, uint8_t G, uint8_t B, uint8_t A = 0) noexcept : R(R / 255.f), G(G / 255.f), B(B / 255.f) {}

    /// Hex Color Code Constructor
    /// \param RGB Hexadecimal color representation
    constexpr explicit RGB(uint32_t RGB) noexcept : R(((RGB >> 16) & 0xFF) / 255.f), G(((RGB >> 8) & 0xFF) / 255.f), B((RGB & 0xFF) / 255.f) {}

    /// Float Color Constructor. Values range is from 0.f to 1.f.
    /// \param R Red channel
    /// \param G Green channel
    /// \param B Blue channel
    constexpr RGB(float R, float G, float B, float A = 0) noexcept : R(R), G(G), B(B) {}

    friend std::ostream &operator<<(std::ostream &out, const RGB &vec);
};

class RGBA {
public:
    ///@{
    /// @name Color channels
    float R = 0;
    float G = 0;
    float B = 0;
    float A = 1.f;
    ///@}

    constexpr RGBA() noexcept = default;

    constexpr RGBA(uint8_t R, uint8_t G, uint8_t B, uint8_t A = 0) noexcept : R(R / 255.f), G(G / 255.f), B(B / 255.f), A(A / 255.f) {}

    /// Float Color Constructor. Values range is from 0.f to 1.f.
    /// \param R Red channel
    /// \param G Green channel
    /// \param B Blue channel
    /// \param A Alpha channel (transparency)
    constexpr RGBA(float R, float G, float B, float A = 0) noexcept : R(R), G(G), B(B), A(A) {}

    operator RGB() { return {R, G, B}; }

    friend std::ostream &operator<<(std::ostream &out, const RGBA &vec);
};
/** @name X11 Colors
 *  Source : http://cng.seas.rochester.edu/CNG/docs/x11color.html
 */
static const RGB LightPink(0xFFB6C1);
static const RGB Pink(0xFFC0CB);
static const RGB Crimson(0xDC143C);
static const RGB LavenderBlush(0xFFF0F5);
static const RGB PaleVioletRed(0xDB7093);
static const RGB HotPink(0xFF69B4);
static const RGB DeepPink(0xFF1493);
static const RGB MediumVioletRed(0xC71585);
static const RGB Orchid(0xDA70D6);
static const RGB Thistle(0xD8BFD8);
static const RGB Plum(0xDDA0DD);
static const RGB Violet(0xEE82EE);
static const RGB Magenta(0xFF00FF);
static const RGB Fuchsia(0xFF00FF);
static const RGB DarkMagenta(0x8B008B);
static const RGB Purple(0x800080);
static const RGB MediumOrchid(0xBA55D3);
static const RGB DarkViolet(0x9400D3);
static const RGB DarkOrchid(0x9932CC);
static const RGB Indigo(0x4B0082);
static const RGB BlueViolet(0x8A2BE2);
static const RGB MediumPurple(0x9370DB);
static const RGB MediumSlateBlue(0x7B68EE);
static const RGB SlateBlue(0x6A5ACD);
static const RGB DarkSlateBlue(0x483D8B);
static const RGB Lavender(0xE6E6FA);
static const RGB GhostWhite(0xF8F8FF);
static const RGB Blue(0x0000FF);
static const RGB MediumBlue(0x0000CD);
static const RGB MidnightBlue(0x191970);
static const RGB DarkBlue(0x00008B);
static const RGB Navy(0x000080);
static const RGB RoyalBlue(0x4169E1);
static const RGB CornflowerBlue(0x6495ED);
static const RGB LightSteelBlue(0xB0C4DE);
static const RGB LightSlateGray(0x778899);
static const RGB SlateGray(0x708090);
static const RGB DodgerBlue(0x1E90FF);
static const RGB AliceBlue(0xF0F8FF);
static const RGB SteelBlue(0x4682B4);
static const RGB LightSkyBlue(0x87CEFA);
static const RGB SkyBlue(0x87CEEB);
static const RGB DeepSkyBlue(0x00BFFF);
static const RGB LightBlue(0xADD8E6);
static const RGB PowderBlue(0xB0E0E6);
static const RGB CadetBlue(0x5F9EA0);
static const RGB Azure(0xF0FFFF);
static const RGB LightCyan(0xE0FFFF);
static const RGB PaleTurquoise(0xAFEEEE);
static const RGB Cyan(0x00FFFF);
static const RGB Aqua(0x00FFFF);
static const RGB DarkTurquoise(0x00CED1);
static const RGB DarkSlateGray(0x2F4F4F);
static const RGB DarkCyan(0x008B8B);
static const RGB Teal(0x008080);
static const RGB MediumTurquoise(0x48D1CC);
static const RGB LightSeaGreen(0x20B2AA);
static const RGB Turquoise(0x40E0D0);
static const RGB Aquamarine(0x7FFFD4);
static const RGB MediumAquamarine(0x66CDAA);
static const RGB MediumSpringGreen(0x00FA9A);
static const RGB MintCream(0xF5FFFA);
static const RGB SpringGreen(0x00FF7F);
static const RGB MediumSeaGreen(0x3CB371);
static const RGB SeaGreen(0x2E8B57);
static const RGB Honeydew(0xF0FFF0);
static const RGB LightGreen(0x90EE90);
static const RGB PaleGreen(0x98FB98);
static const RGB DarkSeaGreen(0x8FBC8F);
static const RGB LimeGreen(0x32CD32);
static const RGB Lime(0x00FF00);
static const RGB ForestGreen(0x228B22);
static const RGB Green(0x008000);
static const RGB DarkGreen(0x006400);
static const RGB Chartreuse(0x7FFF00);
static const RGB LawnGreen(0x7CFC00);
static const RGB GreenYellow(0xADFF2F);
static const RGB DarkOliveGreen(0x556B2F);
static const RGB YellowGreen(0x9ACD32);
static const RGB OliveDrab(0x6B8E23);
static const RGB Beige(0xF5F5DC);
static const RGB LightGoldenrodYellow(0xFAFAD2);
static const RGB Ivory(0xFFFFF0);
static const RGB LightYellow(0xFFFFE0);
static const RGB Yellow(0xFFFF00);
static const RGB Olive(0x808000);
static const RGB DarkKhaki(0xBDB76B);
static const RGB LemonChiffon(0xFFFACD);
static const RGB PaleGoldenrod(0xEEE8AA);
static const RGB Khaki(0xF0E68C);
static const RGB Gold(0xFFD700);
static const RGB Cornsilk(0xFFF8DC);
static const RGB Goldenrod(0xDAA520);
static const RGB DarkGoldenrod(0xB8860B);
static const RGB FloralWhite(0xFFFAF0);
static const RGB OldLace(0xFDF5E6);
static const RGB Wheat(0xF5DEB3);
static const RGB Moccasin(0xFFE4B5);
static const RGB Orange(0xFFA500);
static const RGB PapayaWhip(0xFFEFD5);
static const RGB BlanchedAlmond(0xFFEBCD);
static const RGB NavajoWhite(0xFFDEAD);
static const RGB AntiqueWhite(0xFAEBD7);
static const RGB Tan(0xD2B48C);
static const RGB BurlyWood(0xDEB887);
static const RGB Bisque(0xFFE4C4);
static const RGB DarkOrange(0xFF8C00);
static const RGB Linen(0xFAF0E6);
static const RGB Peru(0xCD853F);
static const RGB PeachPuff(0xFFDAB9);
static const RGB SandyBrown(0xF4A460);
static const RGB Chocolate(0xD2691E);
static const RGB SaddleBrown(0x8B4513);
static const RGB Seashell(0xFFF5EE);
static const RGB Sienna(0xA0522D);
static const RGB LightSalmon(0xFFA07A);
static const RGB Coral(0xFF7F50);
static const RGB OrangeRed(0xFF4500);
static const RGB DarkSalmon(0xE9967A);
static const RGB Tomato(0xFF6347);
static const RGB MistyRose(0xFFE4E1);
static const RGB Salmon(0xFA8072);
static const RGB Snow(0xFFFAFA);
static const RGB LightCoral(0xF08080);
static const RGB RosyBrown(0xBC8F8F);
static const RGB IndianRed(0xCD5C5C);
static const RGB Red(0xFF0000);
static const RGB Brown(0xA52A2A);
static const RGB FireBrick(0xB22222);
static const RGB DarkRed(0x8B0000);
static const RGB Maroon(0x800000);
static const RGB White(0xFFFFFF);
static const RGB WhiteSmoke(0xF5F5F5);
static const RGB Gainsboro(0xDCDCDC);
static const RGB LightGrey(0xD3D3D3);
static const RGB Silver(0xC0C0C0);
static const RGB DarkGray(0xA9A9A9);
static const RGB Gray(0x808080);
static const RGB DimGray(0x696969);
static const RGB Black(0x000000);
} // namespace Blob::Color

#pragma once

#include <cstdint>
#include <ostream>

namespace Blob {

class Color {
public:
    ///@{
    /// @name Color channels
    float R = 0.f;
    float G = 0.f;
    float B = 0.f;
    float A = 1.f;
    ///@}

    constexpr Color() noexcept = default;

    constexpr Color(uint8_t R, uint8_t G, uint8_t B, uint8_t A = 255) noexcept :
        R(R / 255.f), G(G / 255.f), B(B / 255.f), A(A / 255.f) {}

    /// Float Color Constructor. Values range is from 0.f to 1.f.
    /// \param R Red channel
    /// \param G Green channel
    /// \param B Blue channel
    /// \param A Alpha channel (transparency)
    constexpr Color(float R, float G, float B, float A = 1.f) noexcept :
        R(R), G(G), B(B), A(A) {}

    constexpr Color(double R, double G, double B, double A = 1.f) noexcept :
        R(R), G(G), B(B), A(A) {}

    /// Hex Color Code Constructor
    /// \param RGB Hexadecimal color representation
    constexpr explicit Color(uint32_t RGB) noexcept :
        R(((RGB >> 16) & 0xFF) / 255.f),
        G(((RGB >> 8) & 0xFF) / 255.f),
        B((RGB & 0xFF) / 255.f) {}

    friend std::ostream &operator<<(std::ostream &out, const Color &vec);
};

namespace X11 {
/** @name X11 Colors
 *  Source : http://cng.seas.rochester.edu/CNG/docs/x11color.html
 */
static const Color LightPink(0xFFB6C1U);
static const Color Pink(0xFFC0CBU);
static const Color Crimson(0xDC143CU);
static const Color LavenderBlush(0xFFF0F5U);
static const Color PaleVioletRed(0xDB7093U);
static const Color HotPink(0xFF69B4U);
static const Color DeepPink(0xFF1493U);
static const Color MediumVioletRed(0xC71585U);
static const Color Orchid(0xDA70D6U);
static const Color Thistle(0xD8BFD8U);
static const Color Plum(0xDDA0DDU);
static const Color Violet(0xEE82EEU);
static const Color Magenta(0xFF00FFU);
static const Color Fuchsia(0xFF00FFU);
static const Color DarkMagenta(0x8B008BU);
static const Color Purple(0x800080U);
static const Color MediumOrchid(0xBA55D3U);
static const Color DarkViolet(0x9400D3U);
static const Color DarkOrchid(0x9932CCU);
static const Color Indigo(0x4B0082U);
static const Color BlueViolet(0x8A2BE2U);
static const Color MediumPurple(0x9370DBU);
static const Color MediumSlateBlue(0x7B68EEU);
static const Color SlateBlue(0x6A5ACDU);
static const Color DarkSlateBlue(0x483D8BU);
static const Color Lavender(0xE6E6FAU);
static const Color GhostWhite(0xF8F8FFU);
static const Color Blue(0x0000FFU);
static const Color MediumBlue(0x0000CDU);
static const Color MidnightBlue(0x191970U);
static const Color DarkBlue(0x00008BU);
static const Color Navy(0x000080U);
static const Color RoyalBlue(0x4169E1U);
static const Color CornflowerBlue(0x6495EDU);
static const Color LightSteelBlue(0xB0C4DEU);
static const Color LightSlateGray(0x778899U);
static const Color SlateGray(0x708090U);
static const Color DodgerBlue(0x1E90FFU);
static const Color AliceBlue(0xF0F8FFU);
static const Color SteelBlue(0x4682B4U);
static const Color LightSkyBlue(0x87CEFAU);
static const Color SkyBlue(0x87CEEBU);
static const Color DeepSkyBlue(0x00BFFFU);
static const Color LightBlue(0xADD8E6U);
static const Color PowderBlue(0xB0E0E6U);
static const Color CadetBlue(0x5F9EA0U);
static const Color Azure(0xF0FFFFU);
static const Color LightCyan(0xE0FFFFU);
static const Color PaleTurquoise(0xAFEEEEU);
static const Color Cyan(0x00FFFFU);
static const Color Aqua(0x00FFFFU);
static const Color DarkTurquoise(0x00CED1U);
static const Color DarkSlateGray(0x2F4F4FU);
static const Color DarkCyan(0x008B8BU);
static const Color Teal(0x008080U);
static const Color MediumTurquoise(0x48D1CCU);
static const Color LightSeaGreen(0x20B2AAU);
static const Color Turquoise(0x40E0D0U);
static const Color Aquamarine(0x7FFFD4U);
static const Color MediumAquamarine(0x66CDAAU);
static const Color MediumSpringGreen(0x00FA9AU);
static const Color MintCream(0xF5FFFAU);
static const Color SpringGreen(0x00FF7FU);
static const Color MediumSeaGreen(0x3CB371U);
static const Color SeaGreen(0x2E8B57U);
static const Color Honeydew(0xF0FFF0U);
static const Color LightGreen(0x90EE90U);
static const Color PaleGreen(0x98FB98U);
static const Color DarkSeaGreen(0x8FBC8FU);
static const Color LimeGreen(0x32CD32U);
static const Color Lime(0x00FF00U);
static const Color ForestGreen(0x228B22U);
static const Color Green(0x008000U);
static const Color DarkGreen(0x006400U);
static const Color Chartreuse(0x7FFF00U);
static const Color LawnGreen(0x7CFC00U);
static const Color GreenYellow(0xADFF2FU);
static const Color DarkOliveGreen(0x556B2FU);
static const Color YellowGreen(0x9ACD32U);
static const Color OliveDrab(0x6B8E23U);
static const Color Beige(0xF5F5DCU);
static const Color LightGoldenrodYellow(0xFAFAD2U);
static const Color Ivory(0xFFFFF0U);
static const Color LightYellow(0xFFFFE0U);
static const Color Yellow(0xFFFF00U);
static const Color Olive(0x808000U);
static const Color DarkKhaki(0xBDB76BU);
static const Color LemonChiffon(0xFFFACDU);
static const Color PaleGoldenrod(0xEEE8AAU);
static const Color Khaki(0xF0E68CU);
static const Color Gold(0xFFD700U);
static const Color Cornsilk(0xFFF8DCU);
static const Color Goldenrod(0xDAA520U);
static const Color DarkGoldenrod(0xB8860BU);
static const Color FloralWhite(0xFFFAF0U);
static const Color OldLace(0xFDF5E6U);
static const Color Wheat(0xF5DEB3U);
static const Color Moccasin(0xFFE4B5U);
static const Color Orange(0xFFA500U);
static const Color PapayaWhip(0xFFEFD5U);
static const Color BlanchedAlmond(0xFFEBCDU);
static const Color NavajoWhite(0xFFDEADU);
static const Color AntiqueWhite(0xFAEBD7U);
static const Color Tan(0xD2B48CU);
static const Color BurlyWood(0xDEB887U);
static const Color Bisque(0xFFE4C4U);
static const Color DarkOrange(0xFF8C00U);
static const Color Linen(0xFAF0E6U);
static const Color Peru(0xCD853FU);
static const Color PeachPuff(0xFFDAB9U);
static const Color SandyBrown(0xF4A460U);
static const Color Chocolate(0xD2691EU);
static const Color SaddleBrown(0x8B4513U);
static const Color Seashell(0xFFF5EEU);
static const Color Sienna(0xA0522DU);
static const Color LightSalmon(0xFFA07AU);
static const Color Coral(0xFF7F50U);
static const Color OrangeRed(0xFF4500U);
static const Color DarkSalmon(0xE9967AU);
static const Color Tomato(0xFF6347U);
static const Color MistyRose(0xFFE4E1U);
static const Color Salmon(0xFA8072U);
static const Color Snow(0xFFFAFAU);
static const Color LightCoral(0xF08080U);
static const Color RosyBrown(0xBC8F8FU);
static const Color IndianRed(0xCD5C5CU);
static const Color Red(0xFF0000U);
static const Color Brown(0xA52A2AU);
static const Color FireBrick(0xB22222U);
static const Color DarkRed(0x8B0000U);
static const Color Maroon(0x800000U);
static const Color White(0xFFFFFFU);
static const Color WhiteSmoke(0xF5F5F5U);
static const Color Gainsboro(0xDCDCDCU);
static const Color LightGrey(0xD3D3D3U);
static const Color Silver(0xC0C0C0U);
static const Color DarkGray(0xA9A9A9U);
static const Color Gray(0x808080U);
static const Color DimGray(0x696969U);
static const Color Black(0x000000U);
} // namespace X11

} // namespace Blob

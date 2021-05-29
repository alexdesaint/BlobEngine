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

    constexpr RGB(uint8_t R, uint8_t G, uint8_t B) noexcept : R(R / 255.f), G(G / 255.f), B(B / 255.f) {}

    constexpr RGB(float rgb[3]) noexcept : R(rgb[0]), G(rgb[1]), B(rgb[2]) {}

    /// Hex Color Code Constructor
    /// \param RGB Hexadecimal color representation
    constexpr explicit RGB(uint32_t RGB) noexcept : R(((RGB >> 16) & 0xFF) / 255.f), G(((RGB >> 8) & 0xFF) / 255.f), B((RGB & 0xFF) / 255.f) {}

    /// Float Color Constructor. Values range is from 0.f to 1.f.
    /// \param R Red channel
    /// \param G Green channel
    /// \param B Blue channel
    constexpr RGB(float R, float G, float B) noexcept : R(R), G(G), B(B) {}

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

    constexpr RGBA(RGB rgb, float A = 0) noexcept : R(rgb.R), G(rgb.G), B(rgb.B), A(A) {}

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
static const RGB LightPink(0xFFB6C1U);
static const RGB Pink(0xFFC0CBU);
static const RGB Crimson(0xDC143CU);
static const RGB LavenderBlush(0xFFF0F5U);
static const RGB PaleVioletRed(0xDB7093U);
static const RGB HotPink(0xFF69B4U);
static const RGB DeepPink(0xFF1493U);
static const RGB MediumVioletRed(0xC71585U);
static const RGB Orchid(0xDA70D6U);
static const RGB Thistle(0xD8BFD8U);
static const RGB Plum(0xDDA0DDU);
static const RGB Violet(0xEE82EEU);
static const RGB Magenta(0xFF00FFU);
static const RGB Fuchsia(0xFF00FFU);
static const RGB DarkMagenta(0x8B008BU);
static const RGB Purple(0x800080U);
static const RGB MediumOrchid(0xBA55D3U);
static const RGB DarkViolet(0x9400D3U);
static const RGB DarkOrchid(0x9932CCU);
static const RGB Indigo(0x4B0082U);
static const RGB BlueViolet(0x8A2BE2U);
static const RGB MediumPurple(0x9370DBU);
static const RGB MediumSlateBlue(0x7B68EEU);
static const RGB SlateBlue(0x6A5ACDU);
static const RGB DarkSlateBlue(0x483D8BU);
static const RGB Lavender(0xE6E6FAU);
static const RGB GhostWhite(0xF8F8FFU);
static const RGB Blue(0x0000FFU);
static const RGB MediumBlue(0x0000CDU);
static const RGB MidnightBlue(0x191970U);
static const RGB DarkBlue(0x00008BU);
static const RGB Navy(0x000080U);
static const RGB RoyalBlue(0x4169E1U);
static const RGB CornflowerBlue(0x6495EDU);
static const RGB LightSteelBlue(0xB0C4DEU);
static const RGB LightSlateGray(0x778899U);
static const RGB SlateGray(0x708090U);
static const RGB DodgerBlue(0x1E90FFU);
static const RGB AliceBlue(0xF0F8FFU);
static const RGB SteelBlue(0x4682B4U);
static const RGB LightSkyBlue(0x87CEFAU);
static const RGB SkyBlue(0x87CEEBU);
static const RGB DeepSkyBlue(0x00BFFFU);
static const RGB LightBlue(0xADD8E6U);
static const RGB PowderBlue(0xB0E0E6U);
static const RGB CadetBlue(0x5F9EA0U);
static const RGB Azure(0xF0FFFFU);
static const RGB LightCyan(0xE0FFFFU);
static const RGB PaleTurquoise(0xAFEEEEU);
static const RGB Cyan(0x00FFFFU);
static const RGB Aqua(0x00FFFFU);
static const RGB DarkTurquoise(0x00CED1U);
static const RGB DarkSlateGray(0x2F4F4FU);
static const RGB DarkCyan(0x008B8BU);
static const RGB Teal(0x008080U);
static const RGB MediumTurquoise(0x48D1CCU);
static const RGB LightSeaGreen(0x20B2AAU);
static const RGB Turquoise(0x40E0D0U);
static const RGB Aquamarine(0x7FFFD4U);
static const RGB MediumAquamarine(0x66CDAAU);
static const RGB MediumSpringGreen(0x00FA9AU);
static const RGB MintCream(0xF5FFFAU);
static const RGB SpringGreen(0x00FF7FU);
static const RGB MediumSeaGreen(0x3CB371U);
static const RGB SeaGreen(0x2E8B57U);
static const RGB Honeydew(0xF0FFF0U);
static const RGB LightGreen(0x90EE90U);
static const RGB PaleGreen(0x98FB98U);
static const RGB DarkSeaGreen(0x8FBC8FU);
static const RGB LimeGreen(0x32CD32U);
static const RGB Lime(0x00FF00U);
static const RGB ForestGreen(0x228B22U);
static const RGB Green(0x008000U);
static const RGB DarkGreen(0x006400U);
static const RGB Chartreuse(0x7FFF00U);
static const RGB LawnGreen(0x7CFC00U);
static const RGB GreenYellow(0xADFF2FU);
static const RGB DarkOliveGreen(0x556B2FU);
static const RGB YellowGreen(0x9ACD32U);
static const RGB OliveDrab(0x6B8E23U);
static const RGB Beige(0xF5F5DCU);
static const RGB LightGoldenrodYellow(0xFAFAD2U);
static const RGB Ivory(0xFFFFF0U);
static const RGB LightYellow(0xFFFFE0U);
static const RGB Yellow(0xFFFF00U);
static const RGB Olive(0x808000U);
static const RGB DarkKhaki(0xBDB76BU);
static const RGB LemonChiffon(0xFFFACDU);
static const RGB PaleGoldenrod(0xEEE8AAU);
static const RGB Khaki(0xF0E68CU);
static const RGB Gold(0xFFD700U);
static const RGB Cornsilk(0xFFF8DCU);
static const RGB Goldenrod(0xDAA520U);
static const RGB DarkGoldenrod(0xB8860BU);
static const RGB FloralWhite(0xFFFAF0U);
static const RGB OldLace(0xFDF5E6U);
static const RGB Wheat(0xF5DEB3U);
static const RGB Moccasin(0xFFE4B5U);
static const RGB Orange(0xFFA500U);
static const RGB PapayaWhip(0xFFEFD5U);
static const RGB BlanchedAlmond(0xFFEBCDU);
static const RGB NavajoWhite(0xFFDEADU);
static const RGB AntiqueWhite(0xFAEBD7U);
static const RGB Tan(0xD2B48CU);
static const RGB BurlyWood(0xDEB887U);
static const RGB Bisque(0xFFE4C4U);
static const RGB DarkOrange(0xFF8C00U);
static const RGB Linen(0xFAF0E6U);
static const RGB Peru(0xCD853FU);
static const RGB PeachPuff(0xFFDAB9U);
static const RGB SandyBrown(0xF4A460U);
static const RGB Chocolate(0xD2691EU);
static const RGB SaddleBrown(0x8B4513U);
static const RGB Seashell(0xFFF5EEU);
static const RGB Sienna(0xA0522DU);
static const RGB LightSalmon(0xFFA07AU);
static const RGB Coral(0xFF7F50U);
static const RGB OrangeRed(0xFF4500U);
static const RGB DarkSalmon(0xE9967AU);
static const RGB Tomato(0xFF6347U);
static const RGB MistyRose(0xFFE4E1U);
static const RGB Salmon(0xFA8072U);
static const RGB Snow(0xFFFAFAU);
static const RGB LightCoral(0xF08080U);
static const RGB RosyBrown(0xBC8F8FU);
static const RGB IndianRed(0xCD5C5CU);
static const RGB Red(0xFF0000U);
static const RGB Brown(0xA52A2AU);
static const RGB FireBrick(0xB22222U);
static const RGB DarkRed(0x8B0000U);
static const RGB Maroon(0x800000U);
static const RGB White(0xFFFFFFU);
static const RGB WhiteSmoke(0xF5F5F5U);
static const RGB Gainsboro(0xDCDCDCU);
static const RGB LightGrey(0xD3D3D3U);
static const RGB Silver(0xC0C0C0U);
static const RGB DarkGray(0xA9A9A9U);
static const RGB Gray(0x808080U);
static const RGB DimGray(0x696969U);
static const RGB Black(0x000000U);
} // namespace Blob::Color

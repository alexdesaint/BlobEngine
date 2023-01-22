#pragma once

#include <array>
#include <cstdint>
#include <imgui.h>
#include <ostream>

namespace Blob {

union Color {
    struct {
        float R, G, B, A;
    };
    float rgba[4];

    constexpr Color() noexcept : R(0.f), G(0.f), B(0.f), A(1.f){};

    constexpr Color(uint8_t R, uint8_t G, uint8_t B, uint8_t A = 255) noexcept :
        R(R / 255.f),
        G(G / 255.f),
        B(B / 255.f),
        A(A / 255.f) {}

    /// Float Color Constructor. Values range is from 0.f to 1.f.
    /// \param R Red channel
    /// \param G Green channel
    /// \param B Blue channel
    /// \param A Alpha channel (transparency)
    constexpr Color(float R, float G, float B, float A = 1.f) noexcept : R(R), G(G), B(B), A(A) {}

    constexpr Color(double R, double G, double B, double A = 1.f) noexcept : R(R), G(G), B(B), A(A) {}

    /// Hex Color Code Constructor
    /// \param RGB Hexadecimal color representation
    constexpr explicit Color(uint32_t RGB, uint8_t transparency = 0xFF) noexcept :
        R(((RGB >> 16) & 0xFF) / 255.f),
        G(((RGB >> 8) & 0xFF) / 255.f),
        B(((RGB >> 0) & 0xFF) / 255.f),
        A(transparency / 255.f) {}

    friend std::ostream &operator<<(std::ostream &out, const Color &vec);
};

struct NativeColor {
    Color color;
    uint32_t code;
    ImU32 imGuiColor;
    std::string_view name;
    constexpr operator Color() const noexcept { return color; }
    constexpr operator ImU32() const noexcept { return imGuiColor; }

    constexpr NativeColor(uint32_t code, std::string_view name, uint32_t transparency = 0xFF) noexcept :
        color(code, transparency),
        code((code << 8) | transparency),
        imGuiColor(((code >> 16) & 0x000000FF) | ((code << 16) & 0x00FF0000) | (code & 0x0000FF00) |
                   ((transparency << 24) & 0xFF000000)),
        name(name) {}

    constexpr NativeColor withTransparency(float transparency) const {
        return NativeColor(code >> 8, name, transparency * 255);
    }
};

namespace X11 {
/** @name X11 Colors
 *  Source : http://cng.seas.rochester.edu/CNG/docs/x11color.html
 */
static constexpr NativeColor LightPink(0xFFB6C1U, "LightPink");
static constexpr NativeColor Pink(0xFFC0CBU, "Pink");
static constexpr NativeColor Crimson(0xDC143CU, "Crimson");
static constexpr NativeColor LavenderBlush(0xFFF0F5U, "LavenderBlush");
static constexpr NativeColor PaleVioletRed(0xDB7093U, "PaleVioletRed");
static constexpr NativeColor HotPink(0xFF69B4U, "HotPink");
static constexpr NativeColor DeepPink(0xFF1493U, "DeepPink");
static constexpr NativeColor MediumVioletRed(0xC71585U, "MediumVioletRed");
static constexpr NativeColor Orchid(0xDA70D6U, "Orchid");
static constexpr NativeColor Thistle(0xD8BFD8U, "Thistle");
static constexpr NativeColor Plum(0xDDA0DDU, "Plum");
static constexpr NativeColor Violet(0xEE82EEU, "Violet");
static constexpr NativeColor Magenta(0xFF00FFU, "Magenta");
static constexpr NativeColor Fuchsia(0xFF00FFU, "Fuchsia");
static constexpr NativeColor DarkMagenta(0x8B008BU, "DarkMagenta");
static constexpr NativeColor Purple(0x800080U, "Purple");
static constexpr NativeColor MediumOrchid(0xBA55D3U, "MediumOrchid");
static constexpr NativeColor DarkViolet(0x9400D3U, "DarkViolet");
static constexpr NativeColor DarkOrchid(0x9932CCU, "DarkOrchid");
static constexpr NativeColor Indigo(0x4B0082U, "Indigo");
static constexpr NativeColor BlueViolet(0x8A2BE2U, "BlueViolet");
static constexpr NativeColor MediumPurple(0x9370DBU, "MediumPurple");
static constexpr NativeColor MediumSlateBlue(0x7B68EEU, "MediumSlateBlue");
static constexpr NativeColor SlateBlue(0x6A5ACDU, "SlateBlue");
static constexpr NativeColor DarkSlateBlue(0x483D8BU, "DarkSlateBlue");
static constexpr NativeColor Lavender(0xE6E6FAU, "Lavender");
static constexpr NativeColor GhostWhite(0xF8F8FFU, "GhostWhite");
static constexpr NativeColor Blue(0x0000FFU, "Blue");
static constexpr NativeColor MediumBlue(0x0000CDU, "MediumBlue");
static constexpr NativeColor MidnightBlue(0x191970U, "MidnightBlue");
static constexpr NativeColor DarkBlue(0x00008BU, "DarkBlue");
static constexpr NativeColor Navy(0x000080U, "Navy");
static constexpr NativeColor RoyalBlue(0x4169E1U, "RoyalBlue");
static constexpr NativeColor CornflowerBlue(0x6495EDU, "CornflowerBlue");
static constexpr NativeColor LightSteelBlue(0xB0C4DEU, "LightSteelBlue");
static constexpr NativeColor LightSlateGray(0x778899U, "LightSlateGray");
static constexpr NativeColor SlateGray(0x708090U, "SlateGray");
static constexpr NativeColor DodgerBlue(0x1E90FFU, "DodgerBlue");
static constexpr NativeColor AliceBlue(0xF0F8FFU, "AliceBlue");
static constexpr NativeColor SteelBlue(0x4682B4U, "SteelBlue");
static constexpr NativeColor LightSkyBlue(0x87CEFAU, "LightSkyBlue");
static constexpr NativeColor SkyBlue(0x87CEEBU, "SkyBlue");
static constexpr NativeColor DeepSkyBlue(0x00BFFFU, "DeepSkyBlue");
static constexpr NativeColor LightBlue(0xADD8E6U, "LightBlue");
static constexpr NativeColor PowderBlue(0xB0E0E6U, "PowderBlue");
static constexpr NativeColor CadetBlue(0x5F9EA0U, "CadetBlue");
static constexpr NativeColor Azure(0xF0FFFFU, "Azure");
static constexpr NativeColor LightCyan(0xE0FFFFU, "LightCyan");
static constexpr NativeColor PaleTurquoise(0xAFEEEEU, "PaleTurquoise");
static constexpr NativeColor Cyan(0x00FFFFU, "Cyan");
static constexpr NativeColor Aqua(0x00FFFFU, "Aqua");
static constexpr NativeColor DarkTurquoise(0x00CED1U, "DarkTurquoise");
static constexpr NativeColor DarkSlateGray(0x2F4F4FU, "DarkSlateGray");
static constexpr NativeColor DarkCyan(0x008B8BU, "DarkCyan");
static constexpr NativeColor Teal(0x008080U, "Teal");
static constexpr NativeColor MediumTurquoise(0x48D1CCU, "MediumTurquoise");
static constexpr NativeColor LightSeaGreen(0x20B2AAU, "LightSeaGreen");
static constexpr NativeColor Turquoise(0x40E0D0U, "Turquoise");
static constexpr NativeColor Aquamarine(0x7FFFD4U, "Aquamarine");
static constexpr NativeColor MediumAquamarine(0x66CDAAU, "MediumAquamarine");
static constexpr NativeColor MediumSpringGreen(0x00FA9AU, "MediumSpringGreen");
static constexpr NativeColor MintCream(0xF5FFFAU, "MintCream");
static constexpr NativeColor SpringGreen(0x00FF7FU, "SpringGreen");
static constexpr NativeColor MediumSeaGreen(0x3CB371U, "MediumSeaGreen");
static constexpr NativeColor SeaGreen(0x2E8B57U, "SeaGreen");
static constexpr NativeColor Honeydew(0xF0FFF0U, "Honeydew");
static constexpr NativeColor LightGreen(0x90EE90U, "LightGreen");
static constexpr NativeColor PaleGreen(0x98FB98U, "PaleGreen");
static constexpr NativeColor DarkSeaGreen(0x8FBC8FU, "DarkSeaGreen");
static constexpr NativeColor LimeGreen(0x32CD32U, "LimeGreen");
static constexpr NativeColor Lime(0x00FF00U, "Lime");
static constexpr NativeColor ForestGreen(0x228B22U, "ForestGreen");
static constexpr NativeColor Green(0x008000U, "Green");
static constexpr NativeColor DarkGreen(0x006400U, "DarkGreen");
static constexpr NativeColor Chartreuse(0x7FFF00U, "Chartreuse");
static constexpr NativeColor LawnGreen(0x7CFC00U, "LawnGreen");
static constexpr NativeColor GreenYellow(0xADFF2FU, "GreenYellow");
static constexpr NativeColor DarkOliveGreen(0x556B2FU, "DarkOliveGreen");
static constexpr NativeColor YellowGreen(0x9ACD32U, "YellowGreen");
static constexpr NativeColor OliveDrab(0x6B8E23U, "OliveDrab");
static constexpr NativeColor Beige(0xF5F5DCU, "Beige");
static constexpr NativeColor LightGoldenrodYellow(0xFAFAD2U, "LightGoldenrodYellow");
static constexpr NativeColor Ivory(0xFFFFF0U, "Ivory");
static constexpr NativeColor LightYellow(0xFFFFE0U, "LightYellow");
static constexpr NativeColor Yellow(0xFFFF00U, "Yellow");
static constexpr NativeColor Olive(0x808000U, "Olive");
static constexpr NativeColor DarkKhaki(0xBDB76BU, "DarkKhaki");
static constexpr NativeColor LemonChiffon(0xFFFACDU, "LemonChiffon");
static constexpr NativeColor PaleGoldenrod(0xEEE8AAU, "PaleGoldenrod");
static constexpr NativeColor Khaki(0xF0E68CU, "Khaki");
static constexpr NativeColor Gold(0xFFD700U, "Gold");
static constexpr NativeColor Cornsilk(0xFFF8DCU, "Cornsilk");
static constexpr NativeColor Goldenrod(0xDAA520U, "Goldenrod");
static constexpr NativeColor DarkGoldenrod(0xB8860BU, "DarkGoldenrod");
static constexpr NativeColor FloralWhite(0xFFFAF0U, "FloralWhite");
static constexpr NativeColor OldLace(0xFDF5E6U, "OldLace");
static constexpr NativeColor Wheat(0xF5DEB3U, "Wheat");
static constexpr NativeColor Moccasin(0xFFE4B5U, "Moccasin");
static constexpr NativeColor Orange(0xFFA500U, "Orange");
static constexpr NativeColor PapayaWhip(0xFFEFD5U, "PapayaWhip");
static constexpr NativeColor BlanchedAlmond(0xFFEBCDU, "BlanchedAlmond");
static constexpr NativeColor NavajoWhite(0xFFDEADU, "NavajoWhite");
static constexpr NativeColor AntiqueWhite(0xFAEBD7U, "AntiqueWhite");
static constexpr NativeColor Tan(0xD2B48CU, "Tan");
static constexpr NativeColor BurlyWood(0xDEB887U, "BurlyWood");
static constexpr NativeColor Bisque(0xFFE4C4U, "Bisque");
static constexpr NativeColor DarkOrange(0xFF8C00U, "DarkOrange");
static constexpr NativeColor Linen(0xFAF0E6U, "Linen");
static constexpr NativeColor Peru(0xCD853FU, "Peru");
static constexpr NativeColor PeachPuff(0xFFDAB9U, "PeachPuff");
static constexpr NativeColor SandyBrown(0xF4A460U, "SandyBrown");
static constexpr NativeColor Chocolate(0xD2691EU, "Chocolate");
static constexpr NativeColor SaddleBrown(0x8B4513U, "SaddleBrown");
static constexpr NativeColor Seashell(0xFFF5EEU, "Seashell");
static constexpr NativeColor Sienna(0xA0522DU, "Sienna");
static constexpr NativeColor LightSalmon(0xFFA07AU, "LightSalmon");
static constexpr NativeColor Coral(0xFF7F50U, "Coral");
static constexpr NativeColor OrangeRed(0xFF4500U, "OrangeRed");
static constexpr NativeColor DarkSalmon(0xE9967AU, "DarkSalmon");
static constexpr NativeColor Tomato(0xFF6347U, "Tomato");
static constexpr NativeColor MistyRose(0xFFE4E1U, "MistyRose");
static constexpr NativeColor Salmon(0xFA8072U, "Salmon");
static constexpr NativeColor Snow(0xFFFAFAU, "Snow");
static constexpr NativeColor LightCoral(0xF08080U, "LightCoral");
static constexpr NativeColor RosyBrown(0xBC8F8FU, "RosyBrown");
static constexpr NativeColor IndianRed(0xCD5C5CU, "IndianRed");
static constexpr NativeColor Red(0xFF0000U, "Red");
static constexpr NativeColor Brown(0xA52A2AU, "Brown");
static constexpr NativeColor FireBrick(0xB22222U, "FireBrick");
static constexpr NativeColor DarkRed(0x8B0000U, "DarkRed");
static constexpr NativeColor Maroon(0x800000U, "Maroon");
static constexpr NativeColor White(0xFFFFFFU, "White");
static constexpr NativeColor WhiteSmoke(0xF5F5F5U, "WhiteSmoke");
static constexpr NativeColor Gainsboro(0xDCDCDCU, "Gainsboro");
static constexpr NativeColor LightGrey(0xD3D3D3U, "LightGrey");
static constexpr NativeColor Silver(0xC0C0C0U, "Silver");
static constexpr NativeColor DarkGray(0xA9A9A9U, "DarkGray");
static constexpr NativeColor Gray(0x808080U, "Gray");
static constexpr NativeColor DimGray(0x696969U, "DimGray");
static constexpr NativeColor Black(0x000000U, "Black");

constexpr std::array<NativeColor, 140> getAll() {
    return {
        LightPink,
        Pink,
        Crimson,
        LavenderBlush,
        PaleVioletRed,
        HotPink,
        DeepPink,
        MediumVioletRed,
        Orchid,
        Thistle,
        Plum,
        Violet,
        Magenta,
        Fuchsia,
        DarkMagenta,
        Purple,
        MediumOrchid,
        DarkViolet,
        DarkOrchid,
        Indigo,
        BlueViolet,
        MediumPurple,
        MediumSlateBlue,
        SlateBlue,
        DarkSlateBlue,
        Lavender,
        GhostWhite,
        Blue,
        MediumBlue,
        MidnightBlue,
        DarkBlue,
        Navy,
        RoyalBlue,
        CornflowerBlue,
        LightSteelBlue,
        LightSlateGray,
        SlateGray,
        DodgerBlue,
        AliceBlue,
        SteelBlue,
        LightSkyBlue,
        SkyBlue,
        DeepSkyBlue,
        LightBlue,
        PowderBlue,
        CadetBlue,
        Azure,
        LightCyan,
        PaleTurquoise,
        Cyan,
        Aqua,
        DarkTurquoise,
        DarkSlateGray,
        DarkCyan,
        Teal,
        MediumTurquoise,
        LightSeaGreen,
        Turquoise,
        Aquamarine,
        MediumAquamarine,
        MediumSpringGreen,
        MintCream,
        SpringGreen,
        MediumSeaGreen,
        SeaGreen,
        Honeydew,
        LightGreen,
        PaleGreen,
        DarkSeaGreen,
        LimeGreen,
        Lime,
        ForestGreen,
        Green,
        DarkGreen,
        Chartreuse,
        LawnGreen,
        GreenYellow,
        DarkOliveGreen,
        YellowGreen,
        OliveDrab,
        Beige,
        LightGoldenrodYellow,
        Ivory,
        LightYellow,
        Yellow,
        Olive,
        DarkKhaki,
        LemonChiffon,
        PaleGoldenrod,
        Khaki,
        Gold,
        Cornsilk,
        Goldenrod,
        DarkGoldenrod,
        FloralWhite,
        OldLace,
        Wheat,
        Moccasin,
        Orange,
        PapayaWhip,
        BlanchedAlmond,
        NavajoWhite,
        AntiqueWhite,
        Tan,
        BurlyWood,
        Bisque,
        DarkOrange,
        Linen,
        Peru,
        PeachPuff,
        SandyBrown,
        Chocolate,
        SaddleBrown,
        Seashell,
        Sienna,
        LightSalmon,
        Coral,
        OrangeRed,
        DarkSalmon,
        Tomato,
        MistyRose,
        Salmon,
        Snow,
        LightCoral,
        RosyBrown,
        IndianRed,
        Red,
        Brown,
        FireBrick,
        DarkRed,
        Maroon,
        White,
        WhiteSmoke,
        Gainsboro,
        LightGrey,
        Silver,
        DarkGray,
        Gray,
        DimGray,
        Black,
    };
}
} // namespace X11

namespace Dracula {
static constexpr NativeColor Background(0x282a36U, "Background");
static constexpr NativeColor Selection(0x44475aU, "Selection");
static constexpr NativeColor Foreground(0xf8f8f2U, "Foreground");
static constexpr NativeColor Comment(0x6272a4U, "Comment");
static constexpr NativeColor Cyan(0x8be9fdU, "Cyan");
static constexpr NativeColor Green(0x50fa7bU, "Green");
static constexpr NativeColor Orange(0xffb86cU, "Orange");
static constexpr NativeColor Pink(0xff79c6U, "Pink");
static constexpr NativeColor Purple(0xbd93f9U, "Purple");
static constexpr NativeColor Red(0xff5555U, "Red");
static constexpr NativeColor Yellow(0xf1fa8cU, "Yellow");
} // namespace Dracula

} // namespace Blob

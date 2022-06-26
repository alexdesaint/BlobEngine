#pragma once

#include <cstdint>
#include <ostream>
#include <unordered_map>

namespace Blob {

union Color {
    struct {
        float R, G, B, A;
    };
    float rgba[4];

    constexpr Color() noexcept : R(0.f), G(0.f), B(0.f), A(1.f){};

    constexpr Color(uint8_t R, uint8_t G, uint8_t B, uint8_t A = 255) noexcept :
        R(R / 255.f), G(G / 255.f), B(B / 255.f), A(A / 255.f) {}

    /// Float Color Constructor. Values range is from 0.f to 1.f.
    /// \param R Red channel
    /// \param G Green channel
    /// \param B Blue channel
    /// \param A Alpha channel (transparency)
    constexpr Color(float R, float G, float B, float A = 1.f) noexcept : R(R), G(G), B(B), A(A) {}

    constexpr Color(double R, double G, double B, double A = 1.f) noexcept :
        R(R), G(G), B(B), A(A) {}

    /// Hex Color Code Constructor
    /// \param ARGB Hexadecimal color representation
    constexpr explicit Color(uint32_t ARGB) noexcept :
        R(((ARGB >> 16) & 0xFF) / 255.f),
        G(((ARGB >> 8) & 0xFF) / 255.f),
        B(((ARGB >> 0) & 0xFF) / 255.f),
        A(((ARGB >> 24) & 0xFF) / 255.f) {}

    friend std::ostream &operator<<(std::ostream &out, const Color &vec);
};

namespace X11 {
/** @name X11 Colors
 *  Source : http://cng.seas.rochester.edu/CNG/docs/x11color.html
 */
constexpr Color LightPink(0xFFFFB6C1U);
constexpr Color Pink(0xFFFFC0CBU);
constexpr Color Crimson(0xFFDC143CU);
constexpr Color LavenderBlush(0xFFFFF0F5U);
constexpr Color PaleVioletRed(0xFFDB7093U);
constexpr Color HotPink(0xFFFF69B4U);
constexpr Color DeepPink(0xFFFF1493U);
constexpr Color MediumVioletRed(0xFFC71585U);
constexpr Color Orchid(0xFFDA70D6U);
constexpr Color Thistle(0xFFD8BFD8U);
constexpr Color Plum(0xFFDDA0DDU);
constexpr Color Violet(0xFFEE82EEU);
constexpr Color Magenta(0xFFFF00FFU);
constexpr Color Fuchsia(0xFFFF00FFU);
constexpr Color DarkMagenta(0xFF8B008BU);
constexpr Color Purple(0xFF800080U);
constexpr Color MediumOrchid(0xFFBA55D3U);
constexpr Color DarkViolet(0xFF9400D3U);
constexpr Color DarkOrchid(0xFF9932CCU);
constexpr Color Indigo(0xFF4B0082U);
constexpr Color BlueViolet(0xFF8A2BE2U);
constexpr Color MediumPurple(0xFF9370DBU);
constexpr Color MediumSlateBlue(0xFF7B68EEU);
constexpr Color SlateBlue(0xFF6A5ACDU);
constexpr Color DarkSlateBlue(0xFF483D8BU);
constexpr Color Lavender(0xFFE6E6FAU);
constexpr Color GhostWhite(0xFFF8F8FFU);
constexpr Color Blue(0xFF0000FFU);
constexpr Color MediumBlue(0xFF0000CDU);
constexpr Color MidnightBlue(0xFF191970U);
constexpr Color DarkBlue(0xFF00008BU);
constexpr Color Navy(0xFF000080U);
constexpr Color RoyalBlue(0xFF4169E1U);
constexpr Color CornflowerBlue(0xFF6495EDU);
constexpr Color LightSteelBlue(0xFFB0C4DEU);
constexpr Color LightSlateGray(0xFF778899U);
constexpr Color SlateGray(0xFF708090U);
constexpr Color DodgerBlue(0xFF1E90FFU);
constexpr Color AliceBlue(0xFFF0F8FFU);
constexpr Color SteelBlue(0xFF4682B4U);
constexpr Color LightSkyBlue(0xFF87CEFAU);
constexpr Color SkyBlue(0xFF87CEEBU);
constexpr Color DeepSkyBlue(0xFF00BFFFU);
constexpr Color LightBlue(0xFFADD8E6U);
constexpr Color PowderBlue(0xFFB0E0E6U);
constexpr Color CadetBlue(0xFF5F9EA0U);
constexpr Color Azure(0xFFF0FFFFU);
constexpr Color LightCyan(0xFFE0FFFFU);
constexpr Color PaleTurquoise(0xFFAFEEEEU);
constexpr Color Cyan(0xFF00FFFFU);
constexpr Color Aqua(0xFF00FFFFU);
constexpr Color DarkTurquoise(0xFF00CED1U);
constexpr Color DarkSlateGray(0xFF2F4F4FU);
constexpr Color DarkCyan(0xFF008B8BU);
constexpr Color Teal(0xFF008080U);
constexpr Color MediumTurquoise(0xFF48D1CCU);
constexpr Color LightSeaGreen(0xFF20B2AAU);
constexpr Color Turquoise(0xFF40E0D0U);
constexpr Color Aquamarine(0xFF7FFFD4U);
constexpr Color MediumAquamarine(0xFF66CDAAU);
constexpr Color MediumSpringGreen(0xFF00FA9AU);
constexpr Color MintCream(0xFFF5FFFAU);
constexpr Color SpringGreen(0xFF00FF7FU);
constexpr Color MediumSeaGreen(0xFF3CB371U);
constexpr Color SeaGreen(0xFF2E8B57U);
constexpr Color Honeydew(0xFFF0FFF0U);
constexpr Color LightGreen(0xFF90EE90U);
constexpr Color PaleGreen(0xFF98FB98U);
constexpr Color DarkSeaGreen(0xFF8FBC8FU);
constexpr Color LimeGreen(0xFF32CD32U);
constexpr Color Lime(0xFF00FF00U);
constexpr Color ForestGreen(0xFF228B22U);
constexpr Color Green(0xFF008000U);
constexpr Color DarkGreen(0xFF006400U);
constexpr Color Chartreuse(0xFF7FFF00U);
constexpr Color LawnGreen(0xFF7CFC00U);
constexpr Color GreenYellow(0xFFADFF2FU);
constexpr Color DarkOliveGreen(0xFF556B2FU);
constexpr Color YellowGreen(0xFF9ACD32U);
constexpr Color OliveDrab(0xFF6B8E23U);
constexpr Color Beige(0xFFF5F5DCU);
constexpr Color LightGoldenrodYellow(0xFFFAFAD2U);
constexpr Color Ivory(0xFFFFFFF0U);
constexpr Color LightYellow(0xFFFFFFE0U);
constexpr Color Yellow(0xFFFFFF00U);
constexpr Color Olive(0xFF808000U);
constexpr Color DarkKhaki(0xFFBDB76BU);
constexpr Color LemonChiffon(0xFFFFFACDU);
constexpr Color PaleGoldenrod(0xFFEEE8AAU);
constexpr Color Khaki(0xFFF0E68CU);
constexpr Color Gold(0xFFFFD700U);
constexpr Color Cornsilk(0xFFFFF8DCU);
constexpr Color Goldenrod(0xFFDAA520U);
constexpr Color DarkGoldenrod(0xFFB8860BU);
constexpr Color FloralWhite(0xFFFFFAF0U);
constexpr Color OldLace(0xFFFDF5E6U);
constexpr Color Wheat(0xFFF5DEB3U);
constexpr Color Moccasin(0xFFFFE4B5U);
constexpr Color Orange(0xFFFFA500U);
constexpr Color PapayaWhip(0xFFFFEFD5U);
constexpr Color BlanchedAlmond(0xFFFFEBCDU);
constexpr Color NavajoWhite(0xFFFFDEADU);
constexpr Color AntiqueWhite(0xFFFAEBD7U);
constexpr Color Tan(0xFFD2B48CU);
constexpr Color BurlyWood(0xFFDEB887U);
constexpr Color Bisque(0xFFFFE4C4U);
constexpr Color DarkOrange(0xFFFF8C00U);
constexpr Color Linen(0xFFFAF0E6U);
constexpr Color Peru(0xFFCD853FU);
constexpr Color PeachPuff(0xFFFFDAB9U);
constexpr Color SandyBrown(0xFFF4A460U);
constexpr Color Chocolate(0xFFD2691EU);
constexpr Color SaddleBrown(0xFF8B4513U);
constexpr Color Seashell(0xFFFFF5EEU);
constexpr Color Sienna(0xFFA0522DU);
constexpr Color LightSalmon(0xFFFFA07AU);
constexpr Color Coral(0xFFFF7F50U);
constexpr Color OrangeRed(0xFFFF4500U);
constexpr Color DarkSalmon(0xFFE9967AU);
constexpr Color Tomato(0xFFFF6347U);
constexpr Color MistyRose(0xFFFFE4E1U);
constexpr Color Salmon(0xFFFA8072U);
constexpr Color Snow(0xFFFFFAFAU);
constexpr Color LightCoral(0xFFF08080U);
constexpr Color RosyBrown(0xFFBC8F8FU);
constexpr Color IndianRed(0xFFCD5C5CU);
constexpr Color Red(0xFFFF0000U);
constexpr Color Brown(0xFFA52A2AU);
constexpr Color FireBrick(0xFFB22222U);
constexpr Color DarkRed(0xFF8B0000U);
constexpr Color Maroon(0xFF800000U);
constexpr Color White(0xFFFFFFFFU);
constexpr Color WhiteSmoke(0xFFF5F5F5U);
constexpr Color Gainsboro(0xFFDCDCDCU);
constexpr Color LightGrey(0xFFD3D3D3U);
constexpr Color Silver(0xFFC0C0C0U);
constexpr Color DarkGray(0xFFA9A9A9U);
constexpr Color Gray(0xFF808080U);
constexpr Color DimGray(0xFF696969U);
constexpr Color Black(0xFF000000U);

inline std::unordered_map<std::string, Color> getAll() {
    return {
        {"LightPink", LightPink},
        {"Pink", Pink},
        {"Crimson", Crimson},
        {"LavenderBlush", LavenderBlush},
        {"PaleVioletRed", PaleVioletRed},
        {"HotPink", HotPink},
        {"DeepPink", DeepPink},
        {"MediumVioletRed", MediumVioletRed},
        {"Orchid", Orchid},
        {"Thistle", Thistle},
        {"Plum", Plum},
        {"Violet", Violet},
        {"Magenta", Magenta},
        {"Fuchsia", Fuchsia},
        {"DarkMagenta", DarkMagenta},
        {"Purple", Purple},
        {"MediumOrchid", MediumOrchid},
        {"DarkViolet", DarkViolet},
        {"DarkOrchid", DarkOrchid},
        {"Indigo", Indigo},
        {"BlueViolet", BlueViolet},
        {"MediumPurple", MediumPurple},
        {"MediumSlateBlue", MediumSlateBlue},
        {"SlateBlue", SlateBlue},
        {"DarkSlateBlue", DarkSlateBlue},
        {"Lavender", Lavender},
        {"GhostWhite", GhostWhite},
        {"Blue", Blue},
        {"MediumBlue", MediumBlue},
        {"MidnightBlue", MidnightBlue},
        {"DarkBlue", DarkBlue},
        {"Navy", Navy},
        {"RoyalBlue", RoyalBlue},
        {"CornflowerBlue", CornflowerBlue},
        {"LightSteelBlue", LightSteelBlue},
        {"LightSlateGray", LightSlateGray},
        {"SlateGray", SlateGray},
        {"DodgerBlue", DodgerBlue},
        {"AliceBlue", AliceBlue},
        {"SteelBlue", SteelBlue},
        {"LightSkyBlue", LightSkyBlue},
        {"SkyBlue", SkyBlue},
        {"DeepSkyBlue", DeepSkyBlue},
        {"LightBlue", LightBlue},
        {"PowderBlue", PowderBlue},
        {"CadetBlue", CadetBlue},
        {"Azure", Azure},
        {"LightCyan", LightCyan},
        {"PaleTurquoise", PaleTurquoise},
        {"Cyan", Cyan},
        {"Aqua", Aqua},
        {"DarkTurquoise", DarkTurquoise},
        {"DarkSlateGray", DarkSlateGray},
        {"DarkCyan", DarkCyan},
        {"Teal", Teal},
        {"MediumTurquoise", MediumTurquoise},
        {"LightSeaGreen", LightSeaGreen},
        {"Turquoise", Turquoise},
        {"Aquamarine", Aquamarine},
        {"MediumAquamarine", MediumAquamarine},
        {"MediumSpringGreen", MediumSpringGreen},
        {"MintCream", MintCream},
        {"SpringGreen", SpringGreen},
        {"MediumSeaGreen", MediumSeaGreen},
        {"SeaGreen", SeaGreen},
        {"Honeydew", Honeydew},
        {"LightGreen", LightGreen},
        {"PaleGreen", PaleGreen},
        {"DarkSeaGreen", DarkSeaGreen},
        {"LimeGreen", LimeGreen},
        {"Lime", Lime},
        {"ForestGreen", ForestGreen},
        {"Green", Green},
        {"DarkGreen", DarkGreen},
        {"Chartreuse", Chartreuse},
        {"LawnGreen", LawnGreen},
        {"GreenYellow", GreenYellow},
        {"DarkOliveGreen", DarkOliveGreen},
        {"YellowGreen", YellowGreen},
        {"OliveDrab", OliveDrab},
        {"Beige", Beige},
        {"LightGoldenrodYellow", LightGoldenrodYellow},
        {"Ivory", Ivory},
        {"LightYellow", LightYellow},
        {"Yellow", Yellow},
        {"Olive", Olive},
        {"DarkKhaki", DarkKhaki},
        {"LemonChiffon", LemonChiffon},
        {"PaleGoldenrod", PaleGoldenrod},
        {"Khaki", Khaki},
        {"Gold", Gold},
        {"Cornsilk", Cornsilk},
        {"Goldenrod", Goldenrod},
        {"DarkGoldenrod", DarkGoldenrod},
        {"FloralWhite", FloralWhite},
        {"OldLace", OldLace},
        {"Wheat", Wheat},
        {"Moccasin", Moccasin},
        {"Orange", Orange},
        {"PapayaWhip", PapayaWhip},
        {"BlanchedAlmond", BlanchedAlmond},
        {"NavajoWhite", NavajoWhite},
        {"AntiqueWhite", AntiqueWhite},
        {"Tan", Tan},
        {"BurlyWood", BurlyWood},
        {"Bisque", Bisque},
        {"DarkOrange", DarkOrange},
        {"Linen", Linen},
        {"Peru", Peru},
        {"PeachPuff", PeachPuff},
        {"SandyBrown", SandyBrown},
        {"Chocolate", Chocolate},
        {"SaddleBrown", SaddleBrown},
        {"Seashell", Seashell},
        {"Sienna", Sienna},
        {"LightSalmon", LightSalmon},
        {"Coral", Coral},
        {"OrangeRed", OrangeRed},
        {"DarkSalmon", DarkSalmon},
        {"Tomato", Tomato},
        {"MistyRose", MistyRose},
        {"Salmon", Salmon},
        {"Snow", Snow},
        {"LightCoral", LightCoral},
        {"RosyBrown", RosyBrown},
        {"IndianRed", IndianRed},
        {"Red", Red},
        {"Brown", Brown},
        {"FireBrick", FireBrick},
        {"DarkRed", DarkRed},
        {"Maroon", Maroon},
        {"White", White},
        {"WhiteSmoke", WhiteSmoke},
        {"Gainsboro", Gainsboro},
        {"LightGrey", LightGrey},
        {"Silver", Silver},
        {"DarkGray", DarkGray},
        {"Gray", Gray},
        {"DimGray", DimGray},
        {"Black", Black},
    };
}
} // namespace X11

namespace Dracula {
constexpr static const Color Background(0xFF282a36U);
constexpr static const Color Selection(0xFF44475aU);
constexpr static const Color Foreground(0xFFf8f8f2U);
constexpr static const Color Comment(0xFF6272a4U);
constexpr static const Color Cyan(0xFF8be9fdU);
constexpr static const Color Green(0xFF50fa7bU);
constexpr static const Color Orange(0xFFffb86cU);
constexpr static const Color Pink(0xFFff79c6U);
constexpr static const Color Purple(0xFFbd93f9U);
constexpr static const Color Red(0xFFff5555U);
constexpr static const Color Yellow(0xFFf1fa8cU);
} // namespace Dracula

} // namespace Blob

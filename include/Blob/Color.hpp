#pragma once

#include <cstdint>

namespace Blob {
class Color {
private:
    uint8_t R = 0, G = 0, B = 0, A = 0;

public:
    Color() = default;
    Color(uint8_t R, uint8_t G, uint8_t B, uint8_t A = 0) : R(R), G(G), B(B), A(A) {}

    const static Color maroon, darkRed, brown, firebrick, crimson, red, tomato, coral, indianRed, lightCoral, darkSalmon, salmon, lightSalmon,
        orangeRed, darkOrange, orange, gold, darkGoldenRod, goldenRod, paleGoldenRod, darkKhaki, khaki, olive, yellow, yellowGreen, darkOliveGreen,
        oliveDrab, lawnGreen, chartReuse, greenYellow, darkGreen, green, forestGreen, lime, limeGreen, lightGreen, paleGreen, darkSeaGreen,
        mediumSpringGreen, springGreen, seaGreen, mediumAquaMarine, mediumSeaGreen, lightSeaGreen, darkSlateGray, teal, darkCyan, aqua, cyan,
        lightCyan, darkTurquoise, turquoise, mediumTurquoise, paleTurquoise, aquaMarine, powderBlue, cadetBlue, steelBlue, cornFlowerBlue,
        deepSkyBlue, dodgerBlue, lightBlue, skyBlue, lightSkyBlue, midnightBlue, navy, darkBlue, mediumBlue, blue, royalBlue, blueViolet, indigo,
        darkSlateBlue, slateBlue, mediumSlateBlue, mediumPurple, darkMagenta, darkViolet, darkOrchid, mediumOrchid, purple, thistle, plum, violet,
        magenta, orchid, mediumVioletRed, paleVioletRed, deepPink, hotPink, lightPink, pink, antiqueWhite, beige, bisque, blanchedAlmond, wheat,
        cornSilk, lemonChiffon, lightGoldenRodYellow, lightYellow, saddleBrown, sienna, chocolate, peru, sandyBrown, burlyWood, tan, rosyBrown,
        moccasin, navajoWhite, peachPuff, mistyRose, lavenderBlush, linen, oldLace, papayaWhip, seaShell, mintCream, slateGray, lightSlateGray,
        lightSteelBlue, lavender, floralWhite, aliceBlue, ghostWhite, honeydew, ivory, azure, snow, black, dimGrey, grey, darkGrey, silver, lightGrey,
        gainsboro, whiteSmoke, white;
};
} // namespace Blob

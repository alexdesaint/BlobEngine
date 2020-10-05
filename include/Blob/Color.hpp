#pragma once

#include <cstdint>
#include <ostream>

namespace Blob::Material {

/// Color with float points representation.
class Color {
public:
    ///@{
    /// @name Color channels
    float R = 0, G = 0, B = 0, A = 1.f; ///<+ same
    ///@}

    Color() = default;

    Color(uint8_t R, uint8_t G, uint8_t B, uint8_t A = 0) : R(R/255.f), G(G/255.f), B(B/255.f), A(A/255.f) {}
    
    /// Hex Color Code Constructor
    /// \param RGB Hexadecimal color representation
    Color(uint32_t RGB) : R(((RGB >> 16) & 0xFF) / 255.f), G(((RGB >> 8) & 0xFF) / 255.f), B((RGB & 0xFF) / 255.f), A(1.f) {}

    /// Float Color Constructor. Values range is from 0.f to 1.f.
    /// \param R Red channel
    /// \param G Green channel
    /// \param B Blue channel
    /// \param A Alpha channel (transparency)
    Color(float R, float G, float B, float A = 0) : R(R), G(G), B(B), A(A) {}

    friend std::ostream &operator<<(std::ostream &out, const Color &vec);

    /** @name X11 Colors
     *  Source : http://cng.seas.rochester.edu/CNG/docs/x11color.html
     */
    const static Color LightPink;
    const static Color Pink;
    const static Color Crimson;
    const static Color LavenderBlush;
    const static Color PaleVioletRed;
    const static Color HotPink;
    const static Color DeepPink;
    const static Color MediumVioletRed;
    const static Color Orchid;
    const static Color Thistle;
    const static Color Plum;
    const static Color Violet;
    const static Color Magenta;
    const static Color Fuchsia;
    const static Color DarkMagenta;
    const static Color Purple;
    const static Color MediumOrchid;
    const static Color DarkViolet;
    const static Color DarkOrchid;
    const static Color Indigo;
    const static Color BlueViolet;
    const static Color MediumPurple;
    const static Color MediumSlateBlue;
    const static Color SlateBlue;
    const static Color DarkSlateBlue;
    const static Color Lavender;
    const static Color GhostWhite;
    const static Color Blue;
    const static Color MediumBlue;
    const static Color MidnightBlue;
    const static Color DarkBlue;
    const static Color Navy;
    const static Color RoyalBlue;
    const static Color CornflowerBlue;
    const static Color LightSteelBlue;
    const static Color LightSlateGray;
    const static Color SlateGray;
    const static Color DodgerBlue;
    const static Color AliceBlue;
    const static Color SteelBlue;
    const static Color LightSkyBlue;
    const static Color SkyBlue;
    const static Color DeepSkyBlue;
    const static Color LightBlue;
    const static Color PowderBlue;
    const static Color CadetBlue;
    const static Color Azure;
    const static Color LightCyan;
    const static Color PaleTurquoise;
    const static Color Cyan;
    const static Color Aqua;
    const static Color DarkTurquoise;
    const static Color DarkSlateGray;
    const static Color DarkCyan;
    const static Color Teal;
    const static Color MediumTurquoise;
    const static Color LightSeaGreen;
    const static Color Turquoise;
    const static Color Aquamarine;
    const static Color MediumAquamarine;
    const static Color MediumSpringGreen;
    const static Color MintCream;
    const static Color SpringGreen;
    const static Color MediumSeaGreen;
    const static Color SeaGreen;
    const static Color Honeydew;
    const static Color LightGreen;
    const static Color PaleGreen;
    const static Color DarkSeaGreen;
    const static Color LimeGreen;
    const static Color Lime;
    const static Color ForestGreen;
    const static Color Green;
    const static Color DarkGreen;
    const static Color Chartreuse;
    const static Color LawnGreen;
    const static Color GreenYellow;
    const static Color DarkOliveGreen;
    const static Color YellowGreen;
    const static Color OliveDrab;
    const static Color Beige;
    const static Color LightGoldenrodYellow;
    const static Color Ivory;
    const static Color LightYellow;
    const static Color Yellow;
    const static Color Olive;
    const static Color DarkKhaki;
    const static Color LemonChiffon;
    const static Color PaleGoldenrod;
    const static Color Khaki;
    const static Color Gold;
    const static Color Cornsilk;
    const static Color Goldenrod;
    const static Color DarkGoldenrod;
    const static Color FloralWhite;
    const static Color OldLace;
    const static Color Wheat;
    const static Color Moccasin;
    const static Color Orange;
    const static Color PapayaWhip;
    const static Color BlanchedAlmond;
    const static Color NavajoWhite;
    const static Color AntiqueWhite;
    const static Color Tan;
    const static Color BurlyWood;
    const static Color Bisque;
    const static Color DarkOrange;
    const static Color Linen;
    const static Color Peru;
    const static Color PeachPuff;
    const static Color SandyBrown;
    const static Color Chocolate;
    const static Color SaddleBrown;
    const static Color Seashell;
    const static Color Sienna;
    const static Color LightSalmon;
    const static Color Coral;
    const static Color OrangeRed;
    const static Color DarkSalmon;
    const static Color Tomato;
    const static Color MistyRose;
    const static Color Salmon;
    const static Color Snow;
    const static Color LightCoral;
    const static Color RosyBrown;
    const static Color IndianRed;
    const static Color Red;
    const static Color Brown;
    const static Color FireBrick;
    const static Color DarkRed;
    const static Color Maroon;
    const static Color White;
    const static Color WhiteSmoke;
    const static Color Gainsboro;
    const static Color LightGrey;
    const static Color Silver;
    const static Color DarkGray;
    const static Color Gray;
    const static Color DimGray;
    const static Color Black;
};

} // namespace Blob

#pragma once

#include <Blob/Renderable.hpp>
#include <imgui.h>
#include <Blob/Shapes.hpp>
#include <Blob/Exception.hpp>

#include <iostream>

namespace Blob {
	namespace Shapes {

		void init();

		void destroy();

		class Cube : public Renderable {
		public:
			explicit Cube();
		};

		class Plane : public Renderable {
		public:
			explicit Plane();
		};

		class OctagonalPrism : public Renderable {
		public:
			explicit OctagonalPrism();
		};
	}

	struct Shaders {
		static GL::ShaderProgram *Shader_2D_POSITION_TEXCOORD_0_COLOR_0;

		static GL::ShaderProgram *Shader_3D_POSITION;
		static GL::ShaderProgram *Shader_3D_POSITION_NORMAL;
		static GL::ShaderProgram *Shader_3D_POSITION_NORMAL_TEXCOORD_0;
	};

	struct Colors {
		static GL::Texture *maroon,
				*darkRed,
				*brown,
				*firebrick,
				*crimson,
				*red,
				*tomato,
				*coral,
				*indianRed,
				*lightCoral,
				*darkSalmon,
				*salmon,
				*lightSalmon,
				*orangeRed,
				*darkOrange,
				*orange,
				*gold,
				*darkGoldenRod,
				*goldenRod,
				*paleGoldenRod,
				*darkKhaki,
				*khaki,
				*olive,
				*yellow,
				*yellowGreen,
				*darkOliveGreen,
				*oliveDrab,
				*lawnGreen,
				*chartReuse,
				*greenYellow,
				*darkGreen,
				*green,
				*forestGreen,
				*lime,
				*limeGreen,
				*lightGreen,
				*paleGreen,
				*darkSeaGreen,
				*mediumSpringGreen,
				*springGreen,
				*seaGreen,
				*mediumAquaMarine,
				*mediumSeaGreen,
				*lightSeaGreen,
				*darkSlateGray,
				*teal,
				*darkCyan,
				*aqua,
				*cyan,
				*lightCyan,
				*darkTurquoise,
				*turquoise,
				*mediumTurquoise,
				*paleTurquoise,
				*aquaMarine,
				*powderBlue,
				*cadetBlue,
				*steelBlue,
				*cornFlowerBlue,
				*deepSkyBlue,
				*dodgerBlue,
				*lightBlue,
				*skyBlue,
				*lightSkyBlue,
				*midnightBlue,
				*navy,
				*darkBlue,
				*mediumBlue,
				*blue,
				*royalBlue,
				*blueViolet,
				*indigo,
				*darkSlateBlue,
				*slateBlue,
				*mediumSlateBlue,
				*mediumPurple,
				*darkMagenta,
				*darkViolet,
				*darkOrchid,
				*mediumOrchid,
				*purple,
				*thistle,
				*plum,
				*violet,
				*magenta,
				*orchid,
				*mediumVioletRed,
				*paleVioletRed,
				*deepPink,
				*hotPink,
				*lightPink,
				*pink,
				*antiqueWhite,
				*beige,
				*bisque,
				*blanchedAlmond,
				*wheat,
				*cornSilk,
				*lemonChiffon,
				*lightGoldenRodYellow,
				*lightYellow,
				*saddleBrown,
				*sienna,
				*chocolate,
				*peru,
				*sandyBrown,
				*burlyWood,
				*tan,
				*rosyBrown,
				*moccasin,
				*navajoWhite,
				*peachPuff,
				*mistyRose,
				*lavenderBlush,
				*linen,
				*oldLace,
				*papayaWhip,
				*seaShell,
				*mintCream,
				*slateGray,
				*lightSlateGray,
				*lightSteelBlue,
				*lavender,
				*floralWhite,
				*aliceBlue,
				*ghostWhite,
				*honeydew,
				*ivory,
				*azure,
				*snow,
				*black,
				*dimGrey,
				*grey,
				*darkGrey,
				*silver,
				*lightGrey,
				*gainsboro,
				*whiteSmoke,
				*white;
	};

	class ImGUI {
	public:
		static void setWindowSize(unsigned int width, unsigned int height);

		static void draw();
	};
}
}

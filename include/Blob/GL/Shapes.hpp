#ifndef BLOBENGINE_CUBE_HPP
#define BLOBENGINE_CUBE_HPP

#include <Blob/GL/Renderable.hpp>

namespace Blob::GL::Shapes {

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

namespace Blob::GL {
    struct Shaders {
        static ShaderProgram *Shader_2D_POSITION_TEXCOORD_0_COLOR_0;

        static ShaderProgram *Shader_3D_POSITION;
        static ShaderProgram *Shader_3D_POSITION_NORMAL;
        static ShaderProgram *Shader_3D_POSITION_NORMAL_TEXCOORD_0;
    };
}

#endif //BLOBENGINE_CUBE_HPP

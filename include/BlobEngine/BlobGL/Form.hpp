#ifndef BLOBENGINE_CUBE_HPP
#define BLOBENGINE_CUBE_HPP

#include <BlobEngine/BlobGL/Renderable.hpp>

namespace Blob::GL {

	void createVBO();

	void deleteVBO();

	class Cube : public Renderable, public Texture {
	public:
		explicit Cube(ShaderProgram *shaderProgram);
	};

	class Plane : public Renderable, public Texture {
	public:
		explicit Plane(ShaderProgram *shaderProgram);
	};

	class OctagonalPrism : public Renderable, public Texture {
	public:
		explicit OctagonalPrism(ShaderProgram *shaderProgram);
	};

}

#endif //BLOBENGINE_CUBE_HPP

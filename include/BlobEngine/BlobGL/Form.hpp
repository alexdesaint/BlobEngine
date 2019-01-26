#ifndef BLOBENGINE_CUBE_HPP
#define BLOBENGINE_CUBE_HPP

#include <BlobEngine/BlobGL/Renderable.hpp>

namespace BlobEngine::BlobGL {

	void createVBO();

	void deleteVBO();

	class Cube : public Renderable, public Texture {
	public:
		Cube();
	};

	class Plane : public Renderable, public Texture {
	public:
		Plane();
	};

	class OctagonalPrism : public Renderable, public Texture {
	public:
		OctagonalPrism();
	};

}

#endif //BLOBENGINE_CUBE_HPP

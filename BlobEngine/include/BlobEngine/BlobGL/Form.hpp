#ifndef BLOBENGINE_CUBE_HPP
#define BLOBENGINE_CUBE_HPP

#include <BlobEngine/BlobGL/Renderable.hpp>

namespace BlobEngine::BlobGL {

	void createVBO();

	void deleteVBO();

	class Cube : public Renderable {
	private:

		BlobEngine::BlobGL::Texture t;
	public:
		Cube();
	};

	class Plane : public Renderable {
	private:

		BlobEngine::BlobGL::Texture t;
	public:
		Plane();
	};

	class OctagonalPrism : public Renderable {
	private:

		BlobEngine::BlobGL::Texture t;
	public:
		OctagonalPrism();
	};

}

#endif //BLOBENGINE_CUBE_HPP

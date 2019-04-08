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

#endif //BLOBENGINE_CUBE_HPP

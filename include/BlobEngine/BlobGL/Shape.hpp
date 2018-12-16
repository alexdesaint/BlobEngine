#ifndef BLOBENGINE_GLSHAPE_HPP
#define BLOBENGINE_GLSHAPE_HPP

#include <BlobEngine/BlobGL/Renderable.hpp>

#include <list>

namespace BlobEngine::BlobGL {

	class Graphic;

	class Shape {
		friend Graphic;
	private:
		std::list<Renderable*> renderables;

	protected:

		void addRenderable(Renderable *r);

	public:
	};
}

#endif //BLOBENGINE_GLSHAPE_HPP

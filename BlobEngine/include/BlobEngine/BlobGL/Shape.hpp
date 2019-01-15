#ifndef BLOBENGINE_GLSHAPE_HPP
#define BLOBENGINE_GLSHAPE_HPP

#include <BlobEngine/BlobGL/Renderable.hpp>

#include <list>

namespace BlobEngine::BlobGL {

	class Graphic;

	class Shape : public Movable {
		friend Graphic;
	private:

		std::list<Renderable*> renderables;
		std::list<Shape*> shapes;

	protected:

		void addRenderable(Renderable *r);
		void addRenderable(Shape *r);

		void removeRenderable(Renderable *r);
		void removeRenderable(Shape *r);

		//size_t getRenderableSize() const;
	};
}

#endif //BLOBENGINE_GLSHAPE_HPP

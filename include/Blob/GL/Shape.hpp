#ifndef BLOBENGINE_GLSHAPE_HPP
#define BLOBENGINE_GLSHAPE_HPP

#include <Blob/GL/Renderable.hpp>

#include <list>

namespace Blob::GL {

	class Graphic;

	class Shape : public Movable {
		friend Graphic;
	private:

		std::list<Renderable *> renderables;
		std::list<Shape *> shapes;

	public:

		void addRenderable(Renderable &r);

		void addRenderable(Shape &r);

		void removeRenderable(Renderable &r);

		void removeRenderable(Shape &r);
	};
}

#endif //BLOBENGINE_GLSHAPE_HPP

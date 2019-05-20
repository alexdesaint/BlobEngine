#ifndef BLOBENGINE_GLSHAPE_HPP
#define BLOBENGINE_GLSHAPE_HPP

#include <Blob/GL/Renderable.hpp>

#include <list>

namespace Blob::GL {

	class Graphic;

	class Shape : public Movable {
		friend Graphic;
	private:

        std::list<const Renderable *> renderables;
        std::list<const Shape *> shapes;

	public:

        void addRenderable(const Renderable &r);

        void addRenderable(const Renderable *r);

        void addRenderable(const Shape &r);

        void addRenderable(const Shape *r);

		void removeRenderable(Renderable &r);
		void removeRenderable(Renderable *r);

		void removeRenderable(Shape &r);
		void removeRenderable(Shape *r);

        friend std::ostream &operator<<(std::ostream &s, const Shape &a);
	};
}

#endif //BLOBENGINE_GLSHAPE_HPP

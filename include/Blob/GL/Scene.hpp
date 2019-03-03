#ifndef BLOBENGINE_GLSCENE_HPP
#define BLOBENGINE_GLSCENE_HPP

#include <Blob/GL/Shape.hpp>

namespace Blob::GL {

	class Graphic;

	class Scene : public Movable {
		friend Graphic;
	private:
		std::list<Shape *> shapes;

	public:
		void addShape(Shape &r);

		void removeShape(Shape &r);
	};
}

#endif //BLOBENGINE_SCENE_HPP

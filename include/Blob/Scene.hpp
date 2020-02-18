#pragma once

#include <Blob/Shape.hpp>
#include <Blob/Camera.hpp>

namespace Blob {

	class Scene : public Movable {
	private:
		std::list<Shape *> shapes;
		Camera camera;

	public:
		void addShape(Shape &r);

		void removeShape(Shape &r);
	};
}

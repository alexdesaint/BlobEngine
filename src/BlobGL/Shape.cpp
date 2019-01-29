#include <BlobEngine/BlobGL/Shape.hpp>

namespace Blob::GL {

	void Shape::addRenderable(Renderable *r) {
		renderables.emplace_back(r);
	}

	void Shape::addRenderable(Shape *r) {
		shapes.emplace_back(r);
	}

	void Shape::removeRenderable(Renderable *r) {
		renderables.remove(r);
	}

	void Shape::removeRenderable(Shape *r) {
		shapes.remove(r);
	}

	//size_t Shape::getRenderableSize() const {
	//	return renderables.size();
	//}
}
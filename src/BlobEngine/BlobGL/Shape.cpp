#include <BlobEngine/BlobGL/Shape.hpp>

namespace BlobEngine::BlobGL {

	void Shape::addRenderable(Renderable *r) {
		renderables.emplace_back(r);
	}
}
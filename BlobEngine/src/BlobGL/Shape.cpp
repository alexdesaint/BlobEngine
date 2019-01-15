#include <BlobEngine/BlobGL/Shape.hpp>

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/ext/matrix_transform.hpp>

namespace BlobEngine::BlobGL {

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
#include <Blob/GL/Shape.hpp>

namespace Blob::GL {

    void Shape::addRenderable(const Renderable &r) {
		renderables.emplace_back(&r);
	}

    void Shape::addRenderable(const Shape &r) {
		shapes.emplace_back(&r);
	}

	void Shape::removeRenderable(Renderable &r) {
		renderables.remove(&r);
	}

	void Shape::removeRenderable(Shape &r) {
		shapes.remove(&r);
	}

    void Shape::addRenderable(const Renderable *r) {
		renderables.emplace_back(r);
	}

    void Shape::addRenderable(const Shape *r) {
		shapes.emplace_back(r);
	}

	void Shape::removeRenderable(Renderable *r) {
		renderables.remove(r);
	}

	void Shape::removeRenderable(Shape *r) {
		shapes.remove(r);
	}

    std::ostream &operator<<(std::ostream &s, const Shape &a) {
        s << "Shape : {" << std::endl;

        for (const auto &r : a.renderables)
            s << r << std::endl;
        for (const auto &r : a.shapes)
            s << *r;

        s << "}" << std::endl;
        return s;
    }
}
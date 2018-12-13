#include <BlobEngine/glTF2/Shape.hpp>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>
#include <iostream>

using namespace std;

namespace BlobEngine::glTF2 {

	Shape::Shape(int num, Reader::JsonExplorer explorer) {
		explorer.goToBaseNode();

		explorer.goToArrayElement("nodes", num);

		mesh.load(explorer.getInt("mesh"), explorer);
	}

	std::ostream &operator<<(std::ostream &s, const Shape &a) {
		s << "Shape {" << endl;

		s << glm::to_string(a.matrix) << endl;
		s << glm::to_string(a.translation) << endl;
		s << glm::to_string(a.rotation) << endl;
		s << glm::to_string(a.scale) << endl;
		s << a.mesh;

		s << "}" << endl;
		return s;
	}
}
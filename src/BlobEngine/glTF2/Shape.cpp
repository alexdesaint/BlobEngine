#include <BlobEngine/glTF2/Shape.hpp>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>
#include <iostream>

using namespace std;

namespace BlobEngine::glTF2 {

	Shape::Shape(int num, Reader::JsonExplorer explorer, Mesh &meshClass) : meshClass(meshClass) {
		explorer.goToBaseNode();

		explorer.goToArrayElement("nodes", num);

		mesh = explorer.getInt("mesh");

		if(explorer.hasMember("translation") && explorer.getArraySize("translation") == 3) {
			float x = explorer.getArrayInt("translation", 0);
			float y = explorer.getArrayInt("translation", 1);
			float z = explorer.getArrayInt("translation", 2);

			setPosition(x, y, z);
		}
		
		auto v = meshClass.getShape(mesh);
		
		for(auto s : v)
			addRenderable(s);
	}

	std::ostream &operator<<(std::ostream &s, const Shape &a) {
		s << "Shape {" << endl;

		s << "mesh : " << a.mesh << endl;

		s << a.meshClass;

		s << "}" << endl;
		return s;
	}
}
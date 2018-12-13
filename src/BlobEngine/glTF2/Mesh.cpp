#include <BlobEngine/glTF2/Mesh.hpp>

#include <BlobEngine/BlobGL/VertexArrayObject.hpp>
#include <iostream>

using namespace std;

namespace BlobEngine::glTF2 {

	void Mesh::load(int num, Reader::JsonExplorer explorer) {
		//load Json
		explorer.goToBaseNode();

		explorer.goToArrayElement("meshes", num);

		int size = explorer.getArraySize("primitives");

		for (unsigned int i = 0; i < size; i++) {
			primitives.emplace_back(explorer.getArrayObject("primitives", i));
		}
	}

	Mesh::Primitive::Attributes::Attributes(Reader::JsonExplorer explorer) {
		//accessor.load(explorer.getInt("POSITION"), explorer);
	}

	Mesh::Primitive::Primitive(Reader::JsonExplorer explorer) : attributes(explorer.getObject("attributes")) {

	}

	std::ostream &operator<<(std::ostream &s, const Mesh &a) {

		s << "Mesh {" << endl;
		//for (auto p : a.primitives)
		//	s << p;

		s << "}" << endl;
		return s;
	}
}

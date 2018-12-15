#include <BlobEngine/glTF2/Mesh.hpp>

#include <BlobEngine/BlobGL/VertexArrayObject.hpp>
#include <iostream>

using namespace std;

namespace BlobEngine::glTF2 {

	Mesh::Mesh(Reader::JsonExplorer explorer) : accessor(explorer) {
		explorer.goToBaseNode();

		Reader::JsonExplorer dat;

		data.resize((size_t)explorer.getArraySize("meshes"));

		for(int i = 0; i < data.size(); i++) {
			dat = explorer.getArrayObject("meshes", i);

			data[i].primitives.resize((size_t)dat.getArraySize("primitives"));

			Reader::JsonExplorer prim;

			for(int j = 0; j < data[i].primitives.size(); j++) {
				prim = dat.getArrayObject("primitives", i);

				data[i].primitives[j].indices = prim.getInt("indices");

				Reader::JsonExplorer attr;

				attr = prim.getObject("attributes");

				data[i].primitives[j].attributes.position = attr.getInt("POSITION");
			}
		}
	}

	std::ostream &operator<<(std::ostream &s, const Mesh &a) {

		s << "Mesh {" << endl;

		for(const auto &i : a.data) {

			for(const auto &j : i.primitives) {

				s << "indices : " << j.indices << endl;

				s << "POSITION : " << j.attributes.position << endl;
			}
		}

		s << a.accessor;

		s << "}" << endl;
		return s;
	}

	BlobGL::Shape Mesh::getShape(int mesh) {
		int indexPosition = data[mesh].primitives[0].attributes.position;
		int indexIndices = data[mesh].primitives[0].indices;

		return BlobGL::Shape(
				accessor.getData(indexPosition), accessor.getSize(indexPosition), accessor.getType(indexPosition),
				accessor.getData(indexIndices), accessor.getNumOfElements(indexIndices), accessor.getType(indexIndices)
				);
	}
}

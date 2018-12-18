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

			int numOfP = dat.getArraySize("primitives");

			Reader::JsonExplorer prim;

			for(int j = 0; j < numOfP; j++) {
				prim = dat.getArrayObject("primitives", j);

				data[i].primitives.emplace_back(prim, accessor);
			}
		}
	}

	std::ostream &operator<<(std::ostream &s, Mesh &a) {

		s << "Mesh {" << endl;

		s << a.accessor;

		for(auto &i : a.data) {

			for(auto &j : i.primitives) {
				s << j;
			}
		}

		s << "}" << endl;
		return s;
	}

	std::vector<BlobGL::Renderable*> Mesh::getShape(int mesh) {
		std::vector<BlobGL::Renderable*> ret(data[mesh].primitives.size());
		for(int i = 0; i < ret.size(); i++)
			ret[i] = &data[mesh].primitives[i];
		return ret;
	}

	//Primitive

	Mesh::Primitive::Primitive(Reader::JsonExplorer explorer, Accessor &a) {
		if(explorer.hasMember("indices")) {
			int indices = explorer.getInt("indices");
			indexed = true;
			setIndices(a.getData(indices), a.getNumOfVector(indices), a.getType(indices));
		}

		Reader::JsonExplorer attr;

		attr = explorer.getObject("attributes");

		int position = attr.getInt("POSITION");

		setData(
				a.getData(position),
				a.getNumOfVector(position),
				a.getValuePerVector(position),
				a.getType(position)
		);
	}

	std::ostream &operator<<(std::ostream &s, Mesh::Primitive &a) {
		//s << "POSITION : " << a.attributes.position << endl;

		//s << "indices : " << a.indices << endl;

		return s;
	}
}

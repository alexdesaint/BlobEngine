#include <BlobEngine/glTF2/Mesh.hpp>

#include <BlobEngine/BlobGL/VertexArrayObject.hpp>
#include <iostream>

using namespace std;

namespace BlobEngine::glTF2 {

	Mesh::Mesh(Reader::JsonExplorer explorer, BlobGL::VertexBufferObject &vbo) : accessor(explorer), buffer(explorer) {
		explorer.goToBaseNode();

		Reader::JsonExplorer dat;

		primitives.resize((size_t)explorer.getArraySize("meshes"));

		auto b = buffer.getData();

		unsigned int totalPoints = 0;

		for(int i = 0; i < primitives.size(); i++) {
			dat = explorer.getArrayObject("meshes", i);

			primitives[i].resize((size_t)dat.getArraySize("primitives"));

			Reader::JsonExplorer prim;

			for (int j = 0; j < primitives[i].size(); j++) {
				prim = dat.getArrayObject("primitives", j);

				primitives[i][j].setBuffer(vbo, sizeof(Data));

				Reader::JsonExplorer attr = explorer.getObject("attributes");

				totalPoints += attr.getInt("POSITION");
			}
		}

		dataBuffer.resize(totalPoints);

		for(int i = 0; i < primitives.size(); i++) {
			dat = explorer.getArrayObject("meshes", i);

			Reader::JsonExplorer prim;

			for (int j = 0; j < primitives[i].size(); j++) {
				prim = dat.getArrayObject("primitives", j);

				//if(prim.hasMember("indices")) {
				//	int indices = explorer.getInt("indices");
				//	primitives[i][j].setIndices(a.getData(indices), a.getNumOfVector(indices), a.getType(indices));
				//}

				Reader::JsonExplorer attr;

				attr = explorer.getObject("attributes");

				int position = attr.getInt("POSITION");

				GLsizei positionOffset = accessor.getOffset(position);

				GLfloat *positions = (GLfloat *)b[positionOffset];

				//primitives[i][j].setPosition(
				//		a.getData(position),
				//		a.getNumOfVector(position),
				//		a.getValuePerVector(position),
				//		a.getType(position)
				//);

				if(attr.hasMember("NORMAL")) {
					int normal = attr.getInt("NORMAL");

					//primitives[i][j].setNormal(
					//		a.getData(normal),
					//		a.getNumOfVector(normal),
					//		a.getValuePerVector(normal),
					//		a.getType(normal)
					//);
				}
			}
		}
	}

	std::ostream &operator<<(std::ostream &s, Mesh &a) {

		s << "Mesh {" << endl;

		s << a.accessor;

		for(auto &i : a.primitives) {

			for(auto &j : i) {
				//s << j;
			}
		}

		s << "}" << endl;
		return s;
	}

	std::vector<BlobGL::Renderable*> Mesh::getShape(int mesh) {
		std::vector<BlobGL::Renderable*> ret(primitives[mesh].size());
		for(int i = 0; i < ret.size(); i++)
			ret[i] = &primitives[mesh][i];
		return ret;
	}
}

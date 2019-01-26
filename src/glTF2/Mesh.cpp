#include <BlobEngine/glTF2/Mesh.hpp>

#include <iostream>

using namespace std;

namespace BlobEngine::glTF2 {

	Mesh::Mesh(Reader::JsonExplorer explorer) : accessor(explorer), buffer(explorer) {
		explorer.goToBaseNode();
/*
		Reader::JsonExplorer dat;

		primitives.resize((size_t)explorer.getArraySize("meshes"));

		auto b = buffer.getData();

		size_t totalPoints = 0;

		for(int i = 0; i < primitives.size(); i++) {
			dat = explorer.getArrayObject("meshes", i);

			primitives[i].resize((size_t)dat.getArraySize("primitives"));

			Reader::JsonExplorer prim;

			for (int j = 0; j < primitives[i].size(); j++) {
				prim = dat.getArrayObject("primitives", j);

				if(prim.hasMember("indices")) {
					primitives[i][j].indices = prim.getInt("indices");
				}

				Reader::JsonExplorer attr = prim.getObject("attributes");

				primitives[i][j].position = attr.getInt("POSITION");

				totalPoints +=  accessor.getNumOfVector(primitives[i][j].position);;

				if(attr.hasMember("NORMAL")) {
					primitives[i][j].normal = attr.getInt("NORMAL");
				}
			}
		}

		dataBuffer.resize(totalPoints);

		unsigned int dataBufferOffset = 0;

		for(auto &i : primitives) {
			for (auto &j : i) {
				if(j.indices != -1) {
					auto indices = (GLubyte *)&b[accessor.getOffset(j.indices)];

					j.setIndices(indices, accessor.getNumOfVector(j.indices), accessor.getType(j.indices));
				}

				int numOfVector = accessor.getNumOfVector(j.position);
				int positionOffset = accessor.getOffset(j.position);

				auto positions = (GLfloat*)&b[positionOffset];

				for(int k = 0; k < numOfVector; k++) {
					dataBuffer[k + dataBufferOffset].coor[0] = positions[k*3];
					dataBuffer[k + dataBufferOffset].coor[1] = positions[k*3 + 1];
					dataBuffer[k + dataBufferOffset].coor[2] = positions[k*3 + 2];
				}

				//primitives[i][j].setPositionVAO(
				//		a.getData(position),
				//		a.getNumOfVector(position),
				//		a.getValuePerVector(position),
				//		a.getType(position)
				//);

				for(int k = 0; k < numOfVector; k++) {
					dataBuffer[k + dataBufferOffset].texCoor[0] = -1;
					dataBuffer[k + dataBufferOffset].texCoor[1] = -1;
				}

				if(j.normal != -1) {
					int normalOffset = accessor.getOffset(j.normal);

					auto normals = (GLfloat*)&b[normalOffset];

					for(int k = 0; k < numOfVector; k++) {
						dataBuffer[k + dataBufferOffset].normal[0] = normals[k*3];
						dataBuffer[k + dataBufferOffset].normal[1] = normals[k*3 + 1];
						dataBuffer[k + dataBufferOffset].normal[2] = normals[k*3 + 2];
					}


					//primitives[i][j].setNormalVAO(
					//		a.getData(normal),
					//		a.getNumOfVector(normal),
					//		a.getValuePerVector(normal),
					//		a.getType(normal)
					//);
				}

				j.dataBufferOffset = dataBufferOffset;

				dataBufferOffset += numOfVector;
			}
		}
*/
		std::vector<Data> data = {
				// x = devant
				// y = droite
				// z = haut

				// Top face
				{{-1.0, -1.0, 1.0},  {0.0, 0.0, 0},   {-1.0, -1.0}},        //hg
				{{1.0,  -1.0, 1.0},  {0.0, 0.0, 0.0}, {-1.0, -1.0}},        //bg
				{{1.0,  1.0,  1.0},  {0.0, 0.0, 0.0}, {-1.0, -1.0}},        //bd
				{{-1.0, 1.0,  1.0},  {0.0, 0.0, 0.0}, {-1.0, -1.0}},        //hd

				// Bottom face
				{{-1.0, -1.0, -1.0}, {0.0, 0.0, 0.0}, {-1.0, -1.0}},    //bg
				{{-1.0, 1.0,  -1.0}, {0.0, 0.0, 0},   {-1.0, -1.0}},    //bd
				{{1.0,  1.0,  -1.0}, {0.0, 0.0, 0},   {-1.0, -1.0}},        //hd
				{{1.0,  -1.0, -1.0}, {0.0, 0.0, 0},   {-1.0, -1.0}},    //hg

				// Right face
				{{-1.0, 1.0,  -1.0}, {0.0, 0.0, 0.0}, {-1.0, -1.0}},        //bd
				{{-1.0, 1.0,  1.0},  {0.0, 0.0, 0.0}, {-1.0, -1.0}},    //hd
				{{1.0,  1.0,  1.0},  {0.0, 0.0, 0.0}, {-1.0, -1.0}},        //hg
				{{1.0,  1.0,  -1.0}, {0.0, 0.0, 0.0}, {-1.0, -1.0}},        //bg

				// Left face
				{{-1.0, -1.0, -1.0}, {0.0, 0.0, 0.0}, {-1.0, -1.0}},        //bg
				{{1.0,  -1.0, -1.0}, {0.0, 0.0, 0.0}, {-1.0, -1.0}},    //bd
				{{1.0,  -1.0, 1.0},  {0.0, 0.0, 0.0}, {-1.0, -1.0}},    //hd
				{{-1.0, -1.0, 1.0},  {0.0, 0.0, 0.0}, {-1.0, -1.0}},    //hg

				// Front face
				{{1.0,  -1.0, -1.0}, {0.0, 0.0, 0.0}, {-1.0, -1.0}},        //bg
				{{1.0,  1.0,  -1.0}, {0.0, 0.0, 0.0}, {-1.0, -1.0}},        //bd
				{{1.0,  1.0,  1.0},  {0.0, 0.0, 0.0}, {-1.0, -1.0}},        //hd
				{{1.0,  -1.0, 1.0},  {0.0, 0.0, 0.0}, {-1.0, -1.0}},    //hg

				// Back face
				{{-1.0, -1.0, -1.0}, {0.0, 0.0, 0.0}, {-1.0, -1.0}},        //bd
				{{-1.0, -1.0, 1.0},  {0.0, 0.0, 0.0}, {-1.0, -1.0}},    //hd
				{{-1.0, 1.0,  1.0},  {0.0, 0.0, 0.0}, {-1.0, -1.0}},    //hg
				{{-1.0, 1.0,  -1.0}, {0.0, 0.0, 0.0}, {-1.0, -1.0}},    //bg

				// ground
				{{0,    0.0,  0.0},  {0.0, 0.0, 0.0}, {-1.0, -1.0}},    //hg
				{{1.0,  0.0,  0.0},  {0.0, 0.0, 0.0}, {-1.0, -1.0}},    //bg
				{{0.0,  1.0,  0.0},  {0.0, 0.0, 0.0}, {-1.0, -1.0}},    //bd
				{{-4.0, 4.0,  -1.0}, {0.0, 0.0, 0.0}, {-1.0, -1.0}},    //hd

		};

		/*const std::vector<GLushort> cudeIndices = {
				24, 25, 26
		};*/

		const std::vector<GLushort> cudeIndices = {
				0, 1, 2, 0, 2, 3,    // front
				4, 5, 6, 4, 6, 7,    // back
				8, 9, 10, 8, 10, 11,   // top
				12, 13, 14, 12, 14, 15,   // bottom
				16, 17, 18, 16, 18, 19,   // right
				20, 21, 22, 20, 22, 23,   // left
		};

		vbo.setData((GLubyte *) data.data(), sizeof(Data) * data.size());

		//vbo.setData((GLubyte*)dataBuffer.data(), dataBuffer.size() * sizeof(data));

		primitives.resize(1);

		primitives[0].resize(1);

		for (auto &i : primitives) {
			for (auto &j : i) {
				j.setBuffer(vbo, sizeof(Data), j.dataBufferOffset * sizeof(Data));

				j.setPositionVAO(3, GL_FLOAT, 0);
				j.setNormalVAO(3, GL_FLOAT, sizeof(Data::coor));
				j.setTexturePositionVAO(2, GL_FLOAT, sizeof(Data::coor) + sizeof(Data::normal));

				j.setIndices((GLubyte *) cudeIndices.data(), (GLsizei) cudeIndices.size(), GL_UNSIGNED_SHORT);
			}
		}
	}

	std::ostream &operator<<(std::ostream &s, Mesh &a) {

		s << "Mesh {" << endl;

		s << a.accessor;

		for (auto &i : a.primitives) {

			for (auto &j : i) {
				//s << j;
			}
		}

		s << "}" << endl;
		return s;
	}

	std::vector<BlobGL::Renderable *> Mesh::getShape(int mesh) {
		std::vector<BlobGL::Renderable *> ret(primitives[mesh].size());
		for (int i = 0; i < ret.size(); i++)
			ret[i] = &primitives[mesh][i];
		return ret;
	}
}

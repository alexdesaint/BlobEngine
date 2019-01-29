#include <BlobEngine/BlobGL/Renderable.hpp>

#include <BlobEngine/Reader/FileReader.hpp>
#include <BlobEngine/BlobException.hpp>

#include <regex>

#include <glad/glad.h>


using namespace std;

namespace Blob::GL {

	/*void Renderable::loadObjFile(const std::string &file) {
		Reader::FileReader fileReader(file);

		regex regIdentifier(R"((\#|[a-z]+) (.*))");

		unsigned int sizeV = 0, sizeVt = 0, sizeVn = 0, sizeS = 0, sizeG = 0, sizeF = 0;

		while (!fileReader.EOFReached()) {
			string line = fileReader.getLine();

			std::smatch m;
			regex_search(line, m, regIdentifier);

			if (m[1].compare("v") == 0) {
				sizeV++;
			} else if (m[1].compare("vt") == 0) {
				sizeVt++;
			} else if (m[1].compare("vn") == 0) {
				sizeVn++;
			} else if (m[1].compare("s") == 0) {
				sizeS++;
			} else if (m[1].compare("g") == 0) {
				sizeG++;
			} else if (m[1].compare("f") == 0) {
				sizeF++;
			}
		}

		fileReader.restart();

		cout << sizeV << " " << sizeVt << " " << sizeVn << " " << sizeS << " " << sizeG << " " << sizeF << endl;

		regex regVec3(R"((\-?\d+\.\d+?) (\-?\d+\.\d+?) (\-?\d+\.\d+?)$)");
		regex regVec2(R"((\-?\d+\.\d+?) (\-?\d+\.\d+?)$)");
		regex regVec3RGB(R"((\d+)\/(\d+)\/(\d+) (\d+)\/(\d+)\/(\d+) (\d+)\/(\d+)\/(\d+)$)");

		vector<glm::vec3> vecV(sizeV);
		vector<glm::vec2> vecVt(sizeVt);
		vector<glm::vec3> vecVn(sizeVn);

		sizeF *= 3;

		std::vector<glm::vec3> points;
		std::vector<glm::vec2> textCoords;
		std::vector<glm::vec3> normals;

		points.resize(sizeF);
		textCoords.resize(sizeF);
		normals.resize(sizeF);

		unsigned int countV = 0, countVt = 0, countVn = 0, countS = 0, countG = 0, countF = 0;

		while (!fileReader.EOFReached()) {
			string line = fileReader.getLine();

			std::smatch m;
			regex_search(line, m, regIdentifier);

			if (m[1].compare("v") == 0) {
				string str = m[2];
				regex_search(str, m, regVec3);

				float x = stof(m[1]), y = stof(m[2]), z = stof(m[3]);

				//cout << x << ' ' << y << ' ' << z << endl;

				vecV[countV] = glm::vec3(x, y, z);

				countV++;
			} else if (m[1].compare("vt") == 0) {
				string str = m[2];
				regex_search(str, m, regVec2);

				float x = stof(m[1]), y = stof(m[2]);

				//cout << x << ' ' << y << endl;

				vecVt[countVt] = glm::vec2(x, y);

				countVt++;
			} else if (m[1].compare("vn") == 0) {
				string str = m[2];
				regex_search(str, m, regVec3);

				float x = stof(m[1]), y = stof(m[2]), z = stof(m[3]);

				vecVn[countVn] = glm::vec3(x, y, z);

				countVn++;
			} else if (m[1].compare("f") == 0) {
				string str = m[2];
				regex_search(str, m, regVec3RGB);

				int vp[3] = {stoi(m[1]), stoi(m[4]), stoi(m[7])},
						vt[3] = {stoi(m[2]), stoi(m[5]), stoi(m[8])},
						vn[3] = {stoi(m[3]), stoi(m[6]), stoi(m[9])};

				for (int i = 0; i < 3; i++) {
					if ((vp[i] - 1 < 0) || (vp[i] - 1 >= countV))
						throw BlobException("ERROR: invalid vertex position index in face");

					if ((vt[i] - 1 < 0) || (vt[i] - 1 >= countVt))
						throw BlobException("ERROR: invalid texture coord index in face");

					if ((vn[i] - 1 < 0) || (vn[i] - 1 >= countVn))
						throw BlobException("ERROR: invalid vertex normal index in face");

					points[countF] = vecV[vp[i] - 1];
					textCoords[countF] = vecVt[vt[i] - 1];
					normals[countF] = vecVn[vn[i] - 1];

					countF++;
				}
			}
		}

		if (countV != sizeV)
			throw BlobException(".obj parser : Error on reading V");

		if (countVt != sizeVt)
			throw BlobException(".obj parser : Error on reading Vt");

		if (countVn != sizeVn)
			throw BlobException(".obj parser : Error on reading Vn");

		if (countF != sizeF)
			throw BlobException(".obj parser : Error on reading F");

		vboPoints.setPositionVAO(points);

		vao.addBuffer(vboPoints, 3, 0, 0);
	}*/

	/*Renderable::Renderable(const std::vector<glm::vec3> &points, const std::vector<GLushort> &indices) : indices(indices.data()) {
		vboPoints.setPositionVAO(points);
		vao.addBuffer(vboPoints, 3, 0, 0);
		indexed = true;
	}

	Renderable::Renderable(const std::string &file) {

		std::string extention = file.substr(file.find_last_of('.') + 1);

		if (extention == "obj") {
			//loadObjFile(file);
		} else if (extention == "gltf") {
			//loadglTF(file);
		} else {
			throw BlobException(std::string("Cannot open the file extention : *.") + extention);
		}
	}

	*/

	void Renderable::setBuffer(VertexBufferObject &vbo, GLsizei stride, GLuint dataOffset) {
		vao.setBuffer(vbo, stride, dataOffset);
	}

	void Renderable::setTexture(Texture &t) {
		texture = &t;
	}

	GLuint getGlTypeSize(GLenum dataType) {
		GLuint typeSize;

		switch (dataType) {
			case GL_BYTE:
				typeSize = sizeof(GLbyte);
				break;
			case GL_UNSIGNED_BYTE:
				typeSize = sizeof(GLubyte);
				break;
			case GL_SHORT:
				typeSize = sizeof(GLshort);
				break;
			case GL_UNSIGNED_SHORT:
				typeSize = sizeof(GLushort);
				break;
			case GL_INT:
				typeSize = sizeof(GLint);
				break;
			case GL_UNSIGNED_INT:
				typeSize = sizeof(GLuint);
				break;
			case GL_FLOAT:
				typeSize = sizeof(GLfloat);
				break;
			default:
				throw BlobException("incorrect Type of data");
		}

		return typeSize;
	}

	void Renderable::setPositionVAO(GLuint valuePerVector, GLenum dataType, GLuint arrayOffset) {
		vao.setArray(valuePerVector, 0, dataType, arrayOffset);
	}

	void Renderable::setNormalVAO(GLuint valuePerVector, GLenum dataType, GLuint arrayOffset) {
		vao.setArray(valuePerVector, 1, dataType, arrayOffset);
	}

	void Renderable::setTexturePositionVAO(GLuint valuePerVector, GLenum dataType, GLuint arrayOffset) {
		vao.setArray(valuePerVector, 2, dataType, arrayOffset);
	}

	void Renderable::setIndices(GLubyte *i, GLsizei noi, GLenum it) {
		indices = i;
		indicesType = it;
		numOfIndices = noi;

		indexed = true;
	}

	const VertexArrayObject &Renderable::getVao() const {
		return vao;
	}


}
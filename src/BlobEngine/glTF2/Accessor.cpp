#include <BlobEngine/glTF2/Accessor.hpp>

#include <iostream>

using namespace std;

namespace BlobEngine::glTF2 {

	static const size_t NUM_TYPE = 7;

	struct TypeInfo {
		const char *name;
		Accessor::Type type;
	};

	const TypeInfo typeInfos[NUM_TYPE] = {
			{"SCALAR", Accessor::SCALAR},
			{"VEC2",   Accessor::VEC2},
			{"VEC3",   Accessor::VEC3},
			{"VEC4",   Accessor::VEC4},
			{"MAT2",   Accessor::MAT2},
			{"MAT3",   Accessor::MAT3},
			{"MAT4",   Accessor::MAT4}
	};

	static Accessor::Type strToType(const char *str) {
		for (auto typeInfo : typeInfos) {
			if (strcmp(typeInfo.name, str) == 0) {
				return typeInfo.type;
			}
		}
		//TODO throw exeption when getType fail
		return Accessor::SCALAR;
	}

	Accessor::Accessor(Reader::JsonExplorer explorer) : bufferView(explorer) {
		explorer.goToBaseNode();

		Reader::JsonExplorer buff;

		data.resize((size_t) explorer.getArraySize("accessors"));

		for (int i = 0; i < data.size(); i++) {
			buff = explorer.getArrayObject("accessors", i);

			data[i].bufferView = buff.getInt("bufferView");

			data[i].componentType = (GLenum) buff.getInt("componentType");

			data[i].type = strToType(buff.getString("type").c_str());

			data[i].byteOffset = static_cast<unsigned int>(buff.getInt("byteOffset"));

			data[i].count = static_cast<unsigned int>(buff.getInt("count"));
		}
	}

	std::ostream &Accessor::printData(std::ostream &s, int a) {
		if (getType(a) == GL_FLOAT) {
			GLfloat *point = (GLfloat *) (getData(a));

			for (int k = 0; k < getSize(a) / sizeof(GLfloat); k++) {
				s << point[k] << " ";
				if ((k + 1) % 3 == 0)
					s << "| ";
			}
			s << endl;
		} else if (getType(a) == GL_UNSIGNED_SHORT) {

			GLushort *points = (GLushort *) (getData(a));

			for (int k = 0; k < getSize(a) / sizeof(GLushort); k++) {
				s << points[k] << " ";
				if ((k + 1) % 3 == 0)
					s << "| ";
			}
			s << endl;

		}

		return s;
	}

	std::ostream &operator<<(std::ostream &s, Accessor &a) {

		s << "Accessor {" << endl;

		for (int i = 0; i < a.data.size(); i++)
			a.printData(s, i);

		for (const auto &i : a.data) {
			s << "byteOffset : " << i.byteOffset << endl;
			s << "componentType : " << i.componentType << endl;
			s << "count : " << i.count << endl;
			s << "type : " << i.type << endl;
			s << "bufferView : " << i.bufferView << endl;

			s << "max : ";
			for (auto &m : i.max)
				s << m << " ";
			s << endl;

			s << "min : ";
			for (auto &m : i.min)
				s << m << " ";
			s << endl;
		}

		s << "}" << endl;
		return s;
	}

	GLubyte *Accessor::getData(int Accessor) {
		return bufferView.getData(data[Accessor].bufferView, data[Accessor].byteOffset);
	}

	GLenum Accessor::getType(int Accessor) {
		return data[Accessor].componentType;
	}

	GLsizei Accessor::getSize(int Accessor) {
		return bufferView.getSize(data[Accessor].bufferView, data[Accessor].byteOffset);
	}

	GLsizei Accessor::getNumOfVector(int Accessor) {
		return data[Accessor].count;
	}

	GLsizei Accessor::getValuePerVector(int Accessor) {
		return data[Accessor].type;
	}

}


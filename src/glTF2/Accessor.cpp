#include <BlobEngine/glTF2/Accessor.hpp>

#include <iostream>

using namespace std;

namespace Blob::glTF2 {

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

			if (buff.hasMember("byteOffset"))
				data[i].byteOffset = static_cast<unsigned int>(buff.getInt("byteOffset"));

			data[i].count = static_cast<unsigned int>(buff.getInt("count"));
		}
	}

	template<typename T>
	std::ostream &printArray(std::ostream &s, GLubyte *b, int size, int nbOfElements) {
		for (int k = 0; k < size / sizeof(T); k++) {
			s << ((T *) b)[k] << " ";
			if (nbOfElements > 1 && (k + 1) % nbOfElements == 0)
				s << "* ";
		}
		return s << endl;
	}

	std::ostream &operator<<(std::ostream &s, Accessor &a) {

		s << "Accessor {" << endl;

		for (Accessor::Data &d : a.data) {
			s << "{\nbyteOffset : " << d.byteOffset << endl;
			s << "count : " << d.count << endl;

			s << "max : ";
			for (auto &m : d.max)
				s << m << " ";
			s << endl;

			s << "min : ";
			for (auto &m : d.min)
				s << m << " ";
			s << endl;
/*
			auto *points = a.bufferView.getData(d.bufferView, d.byteOffset);
			auto size = a.bufferView.getSize(d.bufferView, d.byteOffset);

			switch(d.componentType){
				case GL_FLOAT :
					s << "componentType : float" << endl;

					printArray<float>(s, points, size, d.type);
					break;
				case GL_UNSIGNED_SHORT :
					s << "componentType : unsigned short" << endl;

					printArray<GLushort>(s, points, size, d.type);
					break;
				default:
					s << "type " << d.componentType << " not implemented" << endl;
					break;
			}*/
			s << "}" << endl;
		}

		s << "}" << endl;
		return s;
	}

	GLsizei Accessor::getOffset(int Accessor) {
		return bufferView.getOffset(data[Accessor].bufferView) + data[Accessor].byteOffset;
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

	GLuint Accessor::getValuePerVector(int Accessor) {
		return data[Accessor].type;
	}

}


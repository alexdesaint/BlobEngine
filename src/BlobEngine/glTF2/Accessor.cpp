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

	static Accessor::Type getType(const char *str) {
		for (auto typeInfo : typeInfos) {
			if (strcmp(typeInfo.name, str) == 0) {
				return typeInfo.type;
			}
		}
		//TODO throw exeption when gatType fail
		return Accessor::SCALAR;
	}

	Accessor::Accessor(Reader::JsonExplorer explorer) {
		explorer.goToBaseNode();

		Reader::JsonExplorer buff;

		data.resize((size_t)explorer.getArraySize("accessors"));

		for(int i = 0; i < data.size(); i++) {
			buff = explorer.getArrayObject("accessors", i);

			data[i].bufferView = buff.getInt("bufferView");

			data[i].componentType = (GLenum)buff.getInt("componentType");

			data[i].type = getType(buff.getString("type").c_str());

			data[i].byteOffset = static_cast<unsigned int>(buff.getInt("byteOffset"));

			data[i].count = static_cast<unsigned int>(buff.getInt("count"));
		}
	}

	std::ostream &operator<<(std::ostream &s, const Accessor &a) {

		s << "Accessor {" << endl;

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
}


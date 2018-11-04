#ifndef BLOBENGINE_ACCESSOR_HPP
#define BLOBENGINE_ACCESSOR_HPP

#include <BlobEngine/BlobGL/VertexArrayObject.hpp>
#include <BlobEngine/BlobGL/BufferView.hpp>

#include <vector>

/*
@startuml
!include "BufferView.hpp"

namespace BlobEngine {
        class Accessor {
                +bufferView : BufferView
                +componentType : ComponentType
                +type : Type
                +{static} getType(const char* str) : int
                -{static} typeInfos : static const TypeInfo
                -{static} NUM_TYPE : static const size_t
                +max : std::vector<float>
                +min : std::vector<float>
                +byteOffset : unsigned int
                +count : unsigned int
                +load(int num, Reader::JsonExplorer explorer) : void
        }

        Accessor o-- BufferView
}


namespace BlobEngine::Accessor {
        class Accessor::TypeInfo {
                +type : Type
                +name : const char*
        }
}

@enduml
*/

namespace BlobEngine::BlobGL {
	class Accessor : public VertexArrayObject {
	public:
		enum Type {
			SCALAR = 1, VEC2 = 2, VEC3 = 3, VEC4 = 4, MAT2 = 4, MAT3 = 9, MAT4 = 16
		};

	private:

		static const size_t NUM_TYPE = 7;

		struct TypeInfo {
			const char *name;
			Type type;
		};

		static const TypeInfo typeInfos[NUM_TYPE];

	public:

		enum ComponentType {
			ComponentType_BYTE = 5120,
			ComponentType_UNSIGNED_BYTE = 5121,
			ComponentType_SHORT = 5122,
			ComponentType_UNSIGNED_SHORT = 5123,
			ComponentType_UNSIGNED_INT = 5125,
			ComponentType_FLOAT = 5126
		};

		static Type getType(const char *str) {
			for (auto typeInfo : typeInfos) {
				if (strcmp(typeInfo.name, str) == 0) {
					return typeInfo.type;
				}
			}
			//TODO throw exeption when gatType fail
			return SCALAR;
		}

		BufferView bufferView;            //!< The ID of the bufferView. (required)
		unsigned int byteOffset;        //!< The offset relative to the start of the bufferView in bytes. (required)
		ComponentType componentType;    //!< The datatype of components in the attribute. (required)
		unsigned int count;                //!< The number of attributes referenced by this accessor. (required)
		Type type;                        //!< Specifies if the attribute is a scalar, vector, or matrix. (required)
		std::vector<float> max;                //!< Maximum value of each component in this attribute.
		std::vector<float> min;                //!< Minimum value of each component in this attribute.

		void load(int num, Reader::JsonExplorer explorer) {

			//Json loading
			explorer.goToBaseNode();

			explorer.goToArrayElement("accessors", num);

			bufferView.load(explorer.getInt("bufferView"), explorer);

			componentType = (ComponentType) explorer.getInt("componentType");

			type = getType(explorer.getString("type").c_str());

			byteOffset = static_cast<unsigned int>(explorer.getInt("byteOffset"));

			count = static_cast<unsigned int>(explorer.getInt("count"));

			//VAO
			addBuffer(bufferView, type, 0, 0);


		}
	};
}
#endif //BLOBENGINE_ACCESSOR_HPP

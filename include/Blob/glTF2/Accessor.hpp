#ifndef BLOBENGINE_ACCESSOR_HPP
#define BLOBENGINE_ACCESSOR_HPP

#include <vector>
#include <Blob/glTF2/BufferView.hpp>
#include <Blob/Reader/JsonExplorer.hpp>

namespace Blob::glTF2 {

	class Accessor {
	public:
		enum Type {
			SCALAR = 1, VEC2 = 2, VEC3 = 3, VEC4 = 4, MAT2 = 4, MAT3 = 9, MAT4 = 16
		};

		struct Data {
			int bufferView;            //!< The ID of the bufferView. (required)
			unsigned int byteOffset = 0;        //!< The offset relative to the start of the bufferView in bytes.
			uint32_t componentType;    //!< The datatype of components in the attribute. (required)
            int count;                //!< The number of attributes referenced by this accessor. (required)
			Type type;                        //!< Specifies if the attribute is a scalar, vector, or matrix. (required)
			std::vector<float> max;                //!< Maximum value of each component in this attribute.
			std::vector<float> min;                //!< Minimum value of each component in this attribute.
		};

		std::vector<Data> data;

		BufferView bufferView;

		explicit Accessor(Reader::JsonExplorer explorer);

		size_t getOffset(int Accessor);

		uint32_t getType(int Accessor);

		size_t getSize(int Accessor);

		size_t getNumOfVector(int Accessor);

		uint32_t getValuePerVector(int Accessor);

		friend std::ostream &operator<<(std::ostream &s, Accessor &a);

		std::ostream &printData(std::ostream &s, int accessor);
	};
}

#endif //BLOBENGINE_ACCESSOR_HPP

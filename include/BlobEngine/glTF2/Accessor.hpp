#ifndef BLOBENGINE_ACCESSOR_HPP
#define BLOBENGINE_ACCESSOR_HPP

#include <glad/glad.h>
#include <vector>
#include <BlobEngine/glTF2/BufferView.hpp>
#include <BlobEngine/Reader/JsonExplorer.hpp>

namespace BlobEngine::glTF2 {

	class Accessor {
	public:
		enum Type {
			SCALAR = 1, VEC2 = 2, VEC3 = 3, VEC4 = 4, MAT2 = 4, MAT3 = 9, MAT4 = 16
		};

		struct Data {
			int bufferView;            //!< The ID of the bufferView. (required)
			unsigned int byteOffset;        //!< The offset relative to the start of the bufferView in bytes. (required)
			GLenum componentType;    //!< The datatype of components in the attribute. (required)
			GLsizei count;                //!< The number of attributes referenced by this accessor. (required)
			Type type;                        //!< Specifies if the attribute is a scalar, vector, or matrix. (required)
			std::vector<float> max;                //!< Maximum value of each component in this attribute.
			std::vector<float> min;                //!< Minimum value of each component in this attribute.
		};

		std::vector<Data> data;

		BufferView bufferView;

		explicit Accessor(Reader::JsonExplorer explorer);

		GLubyte *getData(int Accessor);

		GLenum getType(int Accessor);

		GLsizei getSize(int Accessor);

		GLsizei getNumOfElements(int Accessor);

		GLsizei getValuePerElements(int Accessor);

		friend std::ostream &operator<<(std::ostream &s, Accessor &a);

		std::ostream &printData(std::ostream &s, int accessor);
	};
}

#endif //BLOBENGINE_ACCESSOR_HPP

#ifndef BLOBENGINE_VERTEXARRAY_HPP
#define BLOBENGINE_VERTEXARRAY_HPP

#include <BlobEngine/BlobGL/VertexBufferObject.hpp>


namespace Blob::GL {

	class VertexArrayObject {
	private:

		uint32_t vertexArrayObject;

	public:
		uint32_t getVertexArrayObject() const;

		VertexArrayObject();

		~VertexArrayObject();

		void setBuffer(const VertexBufferObject &vbo, int32_t stride, uint32_t dataOffset = 0);

		void setArray(uint32_t numValuePerArray, uint32_t outPosition, uint32_t dataType, uint32_t arrayOffset, bool normalized = false);
	};
}


#endif //BLOBENGINE_VERTEXARRAY_HPP

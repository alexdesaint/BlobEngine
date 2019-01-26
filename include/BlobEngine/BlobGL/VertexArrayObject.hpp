#ifndef BLOBENGINE_VERTEXARRAY_HPP
#define BLOBENGINE_VERTEXARRAY_HPP

#include <BlobEngine/BlobGL/VertexBufferObject.hpp>


namespace BlobEngine::BlobGL {

	class VertexArrayObject {
	private:

		int32_t numberOfElements;

		uint32_t vertexArrayObject;

	public:
		uint32_t getVertexArrayObject() const;

		int32_t getNumberOfElements() const;

		VertexArrayObject();

		~VertexArrayObject();

		void setBuffer(const VertexBufferObject &vbo, int32_t stride, uint32_t dataOffset = 0);

		void setArray(uint32_t numValuePerArray, uint32_t outPosition, uint32_t dataType, uint32_t arrayOffset);
	};
}


#endif //BLOBENGINE_VERTEXARRAY_HPP

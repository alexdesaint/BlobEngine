#ifndef BLOBENGINE_VERTEXBUFFEROBJECT_HPP
#define BLOBENGINE_VERTEXBUFFEROBJECT_HPP

#include <vector>
#include <cstdint>

namespace Blob::GL {

	class VertexArrayObject;

	class VertexBufferObject {
		friend VertexArrayObject;
	private:
		uint32_t vertexBufferObject;
	public:
		uint32_t getVertexBufferObject() const;

	private:

		int64_t dataSize;

		bool targetSet = false;

	public:
		VertexBufferObject();

		VertexBufferObject(uint8_t *data, int64_t dataSize);

		void setData(uint8_t *data, int64_t dataSize, bool dynamic = false);

		void setSubData(uint8_t *data, int64_t dataSize, int64_t offset = 0);

		~VertexBufferObject();
	};
}

#endif //BLOBENGINE_VERTEXBUFFEROBJECT_HPP

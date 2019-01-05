#ifndef BLOBENGINE_VERTEXBUFFEROBJECT_HPP
#define BLOBENGINE_VERTEXBUFFEROBJECT_HPP

#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include <vector>

namespace BlobEngine::BlobGL {

	class VertexArrayObject;

	class VertexBufferObject {
		friend VertexArrayObject;
	private:
		uint32_t vertexBufferObject;

		int64_t dataSize;

	public:
		VertexBufferObject();

		VertexBufferObject(uint8_t *data, int64_t dataSize);

		void setData(uint8_t *data, int64_t dataSize);

		~VertexBufferObject();
	};
}

#endif //BLOBENGINE_VERTEXBUFFEROBJECT_HPP

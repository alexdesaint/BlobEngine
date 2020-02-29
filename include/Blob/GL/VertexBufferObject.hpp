#pragma once

#include <vector>
#include <cstdint>

namespace Blob::GL {

	class VertexBufferObject {
	private:
        uint32_t vertexBufferObject = -1;

        int64_t dataSize = 0;

		bool targetSet = false;

	public:
        uint32_t getVertexBufferObject() const;

		VertexBufferObject();

		VertexBufferObject(uint8_t *data, int64_t dataSize);

        VertexBufferObject(const VertexBufferObject &) = delete;

        ~VertexBufferObject();

		void setData(uint8_t *data, int64_t dataSize, bool dynamic = false);

		void setSubData(uint8_t *data, int64_t dataSize, int64_t offset = 0);
	};
}

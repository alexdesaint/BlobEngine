#pragma once

#include <vector>
#include <list>
#include <nlohmann/json.hpp>
#include <Blob/glTF2/Buffer.hpp>
#include <Blob/GL/VertexBufferObject.hpp>

namespace Blob::glTF2 {

	//! A view into a buffer generally representing a subset of the buffer.
    class BufferView : public GL::VertexBufferObject {
    public:
		enum Target {
            NotSet = 0,
			BufferViewTarget_ARRAY_BUFFER = 34962,
			BufferViewTarget_ELEMENT_ARRAY_BUFFER = 34963
		};

        size_t buffer; ///< The index of the buffer. required
        size_t byteOffset = 0; ///< The offset into the buffer in bytes. default: 0
        size_t byteLength; ///< The length of the bufferView in bytes. required
        size_t byteStride = 0; ///< The stride, in bytes.
        std::string name; ///< The user-defined name of this object.
        Target target = NotSet; ///< The target that the WebGL buffer should be bound to.

        std::list<Buffer>::iterator bufferIt;

        BufferView(const nlohmann::json &j, std::list<Buffer> &buffers);

		friend std::ostream &operator<<(std::ostream &s, const BufferView &a);
	};
}


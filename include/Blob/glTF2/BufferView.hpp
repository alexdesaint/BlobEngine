#ifndef BLOBENGINE_BUFFERVIEW_HPP
#define BLOBENGINE_BUFFERVIEW_HPP

#include <Blob/Reader/JsonExplorer.hpp>
#include <Blob/glTF2/Buffer.hpp>
#include <vector>

namespace Blob::glTF2 {

	//! A view into a buffer generally representing a subset of the buffer.
	class BufferView {
	private:
		enum Target {
			BufferViewTarget_ARRAY_BUFFER = 34962,
			BufferViewTarget_ELEMENT_ARRAY_BUFFER = 34963
		};

		struct Data {
			int buffer = 0; //! The ID of the buffer. (required)
			size_t byteOffset = 0; //! The offset into the buffer in bytes. (required)
            size_t byteLength = 0; //! The length of the bufferView in bytes. (default: 0)
			Target target = BufferViewTarget_ARRAY_BUFFER; //! The target that the WebGL buffer should be bound to.
		};

		std::vector<Data> data;

	public:
		explicit BufferView(Reader::JsonExplorer explorer);

        size_t getOffset(int BufferView);

        size_t getSize(int BufferView, size_t offset);

		friend std::ostream &operator<<(std::ostream &s, const BufferView &a);
	};
}

#endif //BLOBENGINE_BUFFERVIEW_HPP

#ifndef BLOBENGINE_BUFFERVIEW_HPP
#define BLOBENGINE_BUFFERVIEW_HPP

#include <BlobEngine/BlobGL/VertexBufferObject.hpp>
#include <BlobEngine/BlobGL/Buffer.hpp>

/*
@startuml
!include "Buffer.hpp"

namespace BlobEngine {
        class BufferView {
                +target : Target
                +byteLength : int
                +load(int num, Reader::JsonExplorer explorer) : void
        }
	BufferView o-- Buffer
}

@enduml
*/

namespace BlobEngine::BlobGL {

	//! A view into a buffer generally representing a subset of the buffer.
	class BufferView : public BlobGL::VertexBufferObject {
	public:
		Buffer buffer; //! The ID of the buffer. (required)
		int byteOffset{}; //! The offset into the buffer in bytes. (required)
		int byteLength = 0; //! The length of the bufferView in bytes. (default: 0)

		enum Target {
			BufferViewTarget_ARRAY_BUFFER = 34962,
			BufferViewTarget_ELEMENT_ARRAY_BUFFER = 34963
		};

		Target target = BufferViewTarget_ARRAY_BUFFER; //! The target that the WebGL buffer should be bound to.

		void load(int num, Reader::JsonExplorer explorer) {

			//loading Json Data
			explorer.goToBaseNode();

			explorer.goToArrayElement("bufferViews", num);

			byteOffset = explorer.getInt("byteOffset");

			if (explorer.hasMember("byteLength"))
				byteLength = explorer.getInt("byteLength");

			target = static_cast<Target>(explorer.getInt("target"));

			buffer.load(explorer.getInt("buffer"), explorer);

			// Creating VBO

			setData(buffer.data);

		}
	};
}
#endif //BLOBENGINE_BUFFERVIEW_HPP

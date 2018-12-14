#ifndef BLOBENGINE_BUFFERVIEW_HPP
#define BLOBENGINE_BUFFERVIEW_HPP

#include <BlobEngine/Reader/JsonExplorer.hpp>

#include <glad/glad.h>
#include <vector>
#include "SceneManager.hpp"

namespace BlobEngine::glTF2 {

	//! A view into a buffer generally representing a subset of the buffer.
	class BufferView {
	private:
		enum Target {
			BufferViewTarget_ARRAY_BUFFER = 34962,
			BufferViewTarget_ELEMENT_ARRAY_BUFFER = 34963
		};

		struct Data {
			int buffer = 0; //! The ID of the buffer. (required)
			int byteOffset = 0; //! The offset into the buffer in bytes. (required)
			int byteLength = 0; //! The length of the bufferView in bytes. (default: 0)
			Target target = BufferViewTarget_ARRAY_BUFFER; //! The target that the WebGL buffer should be bound to.
		};

		std::vector<Data> data;

		const SceneManager &sm;
	public:
		explicit BufferView(Reader::JsonExplorer explorer, const SceneManager &sm);

		GLubyte *getData(int BufferView, GLsizei offset);

		friend std::ostream &operator<<(std::ostream &s, const BufferView &a);
	};
}

#endif //BLOBENGINE_BUFFERVIEW_HPP

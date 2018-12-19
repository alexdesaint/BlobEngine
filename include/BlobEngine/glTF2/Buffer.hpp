#ifndef BLOBENGINE_BUFFER_HPP
#define BLOBENGINE_BUFFER_HPP

#include <BlobEngine/Reader/JsonExplorer.hpp>

#include <BlobEngine/BlobGL/VertexBufferObject.hpp>

#include <glad/glad.h>
#include <vector>

namespace BlobEngine::glTF2 {

	class Buffer : public BlobGL::VertexBufferObject {
	private:
		struct Data {
			std::string uri; //!< The uri of the buffer. Can be a filepath, a data uri, etc. (required)
			size_t byteLength = 0; //!< The length of the buffer in bytes. (default: 0)
			std::vector<GLubyte> d;
		};

		std::vector<Data> data;

	public:

		explicit Buffer(Reader::JsonExplorer explorer);

		friend std::ostream &operator<<(std::ostream &s, const Buffer &a);

		const std::vector<Data> &getData() const;
	};
}

#endif //BLOBENGINE_BUFFER_HPP

#ifndef BLOBENGINE_BUFFER_HPP
#define BLOBENGINE_BUFFER_HPP

#include <Blob/Reader/JsonExplorer.hpp>

#include <Blob/GL/VertexBufferObject.hpp>

#include <vector>

namespace Blob::glTF2 {

	class Buffer {
	private:
		struct Data {
			std::string uri; //!< The uri of the buffer. Can be a filepath, a data uri, etc. (required)
			size_t byteLength = 0; //!< The length of the buffer in bytes. (default: 0)
			std::vector<uint8_t> d;
		};

		std::vector<Data> data;

	public:

		explicit Buffer(Reader::JsonExplorer explorer);

		friend std::ostream &operator<<(std::ostream &s, const Buffer &a);

		const std::vector<uint8_t> &getData() const;
	};
}

#endif //BLOBENGINE_BUFFER_HPP

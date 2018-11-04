#ifndef BLOBENGINE_BUFFER_HPP
#define BLOBENGINE_BUFFER_HPP

#include <string>
#include <glad/glad.h>
#include <vector>
#include <BlobEngine/BlobException.hpp>
#include <BlobEngine/Reader/JsonExplorer.hpp>

/*
@startuml

namespace BlobEngine {
        class Buffer {
                +byteLength : size_t
                +uri : std::string
                +data : std::vector<GLubyte>
                +load(int num, Reader::JsonExplorer explorer) : void
        }
}


@enduml
*/

namespace BlobEngine::BlobGL {
	class Buffer {
	public:

		std::string uri; //!< The uri of the buffer. Can be a filepath, a data uri, etc. (required)
		size_t byteLength = 0; //!< The length of the buffer in bytes. (default: 0)

		std::vector <GLubyte> data;

		void load(int num, Reader::JsonExplorer explorer);
	};
}

#endif //BLOBENGINE_BUFFER_HPP

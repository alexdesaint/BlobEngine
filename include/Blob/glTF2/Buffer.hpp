#ifndef BLOBENGINE_BUFFER_HPP
#define BLOBENGINE_BUFFER_HPP

#include <nlohmann/json.hpp>
#include <vector>

namespace Blob::glTF2 {

	class Buffer {
	private:
        std::string uri;    ///< The uri of the buffer.
        size_t byteLength;  ///< The total byte length of the buffer view. Required
        std::string name;   ///< The user-defined name of this object.
        //object extensions;///< Dictionary object with extension-specific objects.

	public:
        Buffer(const nlohmann::json &j, const std::string &path);

        std::vector<uint8_t> getData(size_t byteLength, size_t offset);

		friend std::ostream &operator<<(std::ostream &s, const Buffer &a);
	};
}

#endif //BLOBENGINE_BUFFER_HPP

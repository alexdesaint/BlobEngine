#ifndef BLOBENGINE_ASSET_HPP
#define BLOBENGINE_ASSET_HPP

#include <Blob/Reader/JsonExplorer.hpp>

namespace Blob::glTF2 {

	class Asset {
	private:
		std::string version;

	public:
		explicit Asset(Reader::JsonExplorer j);

		friend std::ostream &operator<<(std::ostream &s, const Asset &a);
	};
}

#endif //BLOBENGINE_ASSET_HPP

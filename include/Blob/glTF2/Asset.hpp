#ifndef BLOBENGINE_ASSET_HPP
#define BLOBENGINE_ASSET_HPP

#include <iostream>
#include <nlohmann/json.hpp>

namespace Blob::glTF2 {

	class Asset {
	private:
		std::string version;

	public:
        void load(const nlohmann::json &j);

		friend std::ostream &operator<<(std::ostream &s, const Asset &a);
	};
}

#endif //BLOBENGINE_ASSET_HPP

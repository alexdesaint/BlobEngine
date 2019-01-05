#include <BlobEngine/glTF2/Asset.hpp>
#include <BlobEngine/BlobException.hpp>

#include <iostream>

using namespace std;

namespace BlobEngine::glTF2 {
	Asset::Asset(Reader::JsonExplorer j) {
		j.goToBaseNode();

		j.goIn("asset");

		version = j.getString("version");

		if (version != "2.0")
			throw BlobException(string("glTF : can't load version ") + version);
	}

	ostream &operator<<(ostream &s, const Asset &a) {
		s << "Asset : " << a.version << endl;
		return s;
	}
}
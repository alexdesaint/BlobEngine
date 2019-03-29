#include <Blob/glTF2/Asset.hpp>
#include <Blob/Exception.hpp>

#include <iostream>

using namespace std;

namespace Blob::glTF2 {
	Asset::Asset(Reader::JsonExplorer j) {
		j.goToBaseNode();

		j.goIn("asset");

		version = j.getString("version");

		if (version != "2.0")
			throw Exception(string("glTF : can't loadBMP version ") + version);
	}

	ostream &operator<<(ostream &s, const Asset &a) {
		s << "Asset : " << a.version << endl;
		return s;
	}
}
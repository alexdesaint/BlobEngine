#include <Blob/glTF2/Asset.hpp>
#include <Blob/Exception.hpp>

using namespace std;

namespace Blob::glTF2 {
    void Asset::load(const nlohmann::json &j) {

        version = j["version"].get<std::string>();

		if (version != "2.0")
            throw Exception(string("glTF : can't this glTF version : ") + version + ". Version needed is 2.0");
	}

	ostream &operator<<(ostream &s, const Asset &a) {
		s << "Asset : " << a.version << endl;
		return s;
	}
}
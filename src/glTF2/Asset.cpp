#include <Blob/Core/Exception.hpp>
#include <Blob/glTF2/Asset.hpp>

using namespace std;

namespace Blob::glTF2 {

ostream &operator<<(ostream &s, const Asset &a) {
    s << "  Asset : " << a.version << endl;
    return s;
}

void from_json(const nlohmann::json &j, Asset &a) {
    j.at("version").get_to(a.version);

    if (a.version != "2.0")
        throw Core::Exception(string("glTF : can't this glTF version : ") + a.version + ". Version needed is 2.0");
}

} // namespace Blob::glTF2
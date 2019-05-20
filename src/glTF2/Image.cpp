#include <Blob/glTF2/Image.hpp>

using namespace std;

namespace Blob::glTF2 {
    Image::Image(const nlohmann::json &j, const std::string &path) {
        if (j.find("uri") != j.end()) {
            j.at("uri").get_to(uri);
            uri = path + uri;
        }

        if (j.find("mimeType") != j.end())
            j.at("mimeType").get_to(mimeType);

        if (j.find("bufferView") != j.end())
            j.at("bufferView").get_to(bufferView);

        if (j.find("name") != j.end())
            j.at("name").get_to(name);
    }

    std::ostream &operator<<(std::ostream &s, const Image &a) {
        s << "  Image {" << endl;

        if (a.uri.empty())
            s << "    bufferView : " << a.bufferView << endl;
        else
            s << "    uri : " << a.uri << endl;

        if (!a.mimeType.empty())
            s << "    mimeType : " << a.mimeType << endl;

        if (!a.name.empty())
            s << "    name : " << a.name << endl;

        s << "  }" << endl;

        return s;
    }
}

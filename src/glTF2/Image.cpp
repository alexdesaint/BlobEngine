#include <Blob/glTF2/BasicFunctions.hpp>
#include <Blob/glTF2/Image.hpp>

using namespace std;

namespace Blob::glTF2 {
Image::Image(const nlohmann::json &j, const std::string &path) {
    if (NotRequired(j, "uri", uri))
        uri = path + uri;
    NotRequired(j, "name", name);
    NotRequired(j, "mimeType", mimeType);
    NotRequired(j, "bufferView", bufferView);
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
} // namespace Blob::glTF2

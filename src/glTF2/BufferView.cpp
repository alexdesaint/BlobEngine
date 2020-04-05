#include <Blob/glTF2/BufferView.hpp>

#include <Blob/glTF2/BasicFunctions.hpp>
#include <iostream>

using namespace std;

namespace Blob::glTF2 {

void from_json(const nlohmann::json &j, BufferView &a) {
    Required(j, "buffer", a.buffer);
    Required(j, "byteLength", a.byteLength);
    NotRequired(j, "byteOffset", a.byteOffset);
    NotRequired(j, "target", a.target);
    NotRequired(j, "byteStride", a.byteStride);
    NotRequired(j, "name", a.name);
}

std::ostream &operator<<(std::ostream &s, const BufferView &i) {
    s << "  BufferView {" << endl;

    s << "    byteOffset : " << i.byteOffset << endl;
    s << "    byteLength : " << i.byteLength << endl;
    s << "    byteStride : " << i.byteStride << endl;
    s << "    buffer : " << i.buffer << endl;
    s << "    target : " << i.target << endl;

    s << "  }" << endl;
    return s;
}
} // namespace Blob::glTF2
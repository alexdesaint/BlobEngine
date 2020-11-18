#include <Blob/glTF2/BufferView.hpp>

#include <Blob/glTF2/BasicFunctions.hpp>
#include <iostream>

using namespace std;

namespace Blob::glTF2 {

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
BufferView::BufferView(const nlohmann::json &j) {
    Required(j, "buffer", buffer);
    Required(j, "byteLength", byteLength);
    NotRequired(j, "byteOffset", byteOffset);
    NotRequired(j, "target", target);
    NotRequired(j, "byteStride", byteStride);
    NotRequired(j, "name", name);
}
} // namespace Blob::glTF2
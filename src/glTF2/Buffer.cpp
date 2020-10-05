#include <Blob/glTF2/BasicFunctions.hpp>
#include <Blob/glTF2/Buffer.hpp>
#include <Blob/Reader/FileReader.hpp>
#include <iostream>

using namespace std;

namespace Blob::glTF2 {

Buffer::Buffer(const nlohmann::json &j, const std::string &path) {
    Required(j, "byteLength", byteLength);
    NotRequired(j, "uri", uri);
    NotRequired(j, "name", name);
    uri = path + uri;

    Reader::FileReader fileReader(uri);
    if (fileReader.getSize() != byteLength)
        throw Core::Exception("GLTF: Wrong buffer description");

    vector<uint8_t> bytes(byteLength);

    for (size_t i = 0; i < byteLength; i++)
        bytes[i] = fileReader.readNextByte();

    setData(bytes.data(), byteLength);
}

ostream &operator<<(ostream &s, const Buffer &a) {
    s << "  Buffer {" << endl;

    s << "    " << a.uri << endl << "    byteLength : " << a.byteLength << endl << "    data : " << endl;

    Reader::FileReader fileReader(a.uri);
    s << fileReader;

    s << "  }" << endl;
    return s;
}
std::vector<uint8_t> Buffer::getData(size_t size, size_t offset) const {
    std::vector<uint8_t> ret(size);

    if (size + offset > byteLength)
        throw Core::Exception("GLTF (getData) : Wrong buffer description");

    Reader::FileReader fileReader(uri);

    fileReader.goTo(offset);

    for (size_t i = 0; i < size; i++)
        ret[i] = fileReader.readNextByte();

    return ret;
}

} // namespace Blob::glTF2

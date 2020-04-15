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
        throw Exception("GLTF: Wrong buffer description");

    vector<uint8_t> bytes(byteLength);

    for (size_t i = 0; i < byteLength; i++)
        bytes[i] = fileReader.readNextByte();

    setData(bytes.data(), byteLength);
}

ostream &operator<<(ostream &s, const Buffer &a) {
    s << "  Buffer {" << endl;

    s << "    " << a.uri << endl << "    byteLength : " << a.byteLength << endl << "    data : " << endl;

//    Reader::FileReader fileReader(a.uri);
//    s << fileReader;

    s << "  }" << endl;
    return s;
}

} // namespace Blob::glTF2

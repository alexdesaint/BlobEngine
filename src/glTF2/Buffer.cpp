#include <Blob/glTF2/Buffer.hpp>

#include <Blob/Exception.hpp>
#include <Blob/Reader/FileReader.hpp>

#include <iostream>

using namespace std;

namespace Blob::glTF2 {

    Buffer::Buffer(const nlohmann::json &j, const std::string &path) {
        if (j.find("uri") != j.end())
            j.at("uri").get_to(uri);

        if (j.find("byteLength") == j.end())
            throw Exception("glTF : Required field \"byteLength\" not found");
        j.at("byteLength").get_to(byteLength);

        if (j.find("name") != j.end())
            j.at("name").get_to(name);

        //j.at("extensions").get_to(p.extensions);

        uri = path + uri;
    }

    ostream &operator<<(ostream &s, const Buffer &a) {
        s << "  Buffer {" << endl;

        s << "    " << a.uri << endl << "    byteLength : " << a.byteLength << endl << "    data : " << endl;
        Reader::FileReader fileReader(a.uri);
        s << fileReader;
        s << "  }" << endl;
		return s;
	}

    std::vector<uint8_t> Buffer::getData(size_t length, size_t offset) {
        Reader::FileReader fileReader(uri);

        if (fileReader.getSize() != byteLength)
            throw Exception("File typeSize don't fit");

        std::vector<uint8_t> bytes(length);

        fileReader.goTo(offset);

        for (int i = 0; i < length; i++)
            bytes[i] = fileReader.readNextByte();

        return bytes;
    }

}
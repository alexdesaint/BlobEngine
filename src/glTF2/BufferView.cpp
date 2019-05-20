#include <Blob/glTF2/BufferView.hpp>

#include <iostream>
#include <Blob/Exception.hpp>

using namespace std;

namespace Blob::glTF2 {

    BufferView::BufferView(const nlohmann::json &j, std::list<Buffer> &buffers) {

        if (j.find("buffer") == j.end())
            throw Exception("glTF : Required field \"buffer\" not found");
        j.at("buffer").get_to(buffer);

        bufferIt = std::next(buffers.begin(), buffer);

        if (j.find("byteOffset") != j.end())
            j.at("byteOffset").get_to(byteOffset);

        if (j.find("byteLength") == j.end())
            throw Exception("glTF : Required field \"byteLength\" not found");
        j.at("byteLength").get_to(byteLength);

        if (j.find("target") != j.end())
            j.at("target").get_to(target);

        if (j.find("byteStride") != j.end())
            j.at("byteStride").get_to(byteStride);

        if (j.find("name") != j.end())
            j.at("name").get_to(name);

        setData(bufferIt->getData(byteLength, byteOffset).data(), byteLength);
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
}
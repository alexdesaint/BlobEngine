#include <BlobEngine/glTF2/Buffer.hpp>

#include <BlobEngine/BlobException.hpp>
#include <BlobEngine/Reader/FileReader.hpp>

#include <iostream>

using namespace std;

namespace BlobEngine::glTF2 {

	Buffer::Buffer(Reader::JsonExplorer explorer) {
		explorer.goToBaseNode();

		Reader::JsonExplorer buff;

		data.resize((size_t)explorer.getArraySize("buffers"));

		for(int i = 0; i < data.size(); i++) {
			buff = explorer.getArrayObject("buffers", i);

			data[i].uri = Reader::FileReader::getFilePath(Reader::JsonExplorer::path) + buff.getString("uri");

			if (buff.hasMember("byteLength"))
				data[i].byteLength = static_cast<size_t>(buff.getInt("byteLength"));

			Reader::FileReader fileReader(data[i].uri);

			if (fileReader.getSize() != data[i].byteLength)
				throw BlobException("File typeSize don't fit");

			data[i].d.resize(data[i].byteLength);

			for (int j = 0; j < data[i].byteLength; j++)
				data[i].d[j] = fileReader.readNextByte();
		}
	}

	std::ostream &operator<<(std::ostream &s, const Buffer &a) {
		s << "Buffer {" << std::endl;
		for (const auto &i : a.data) {
			s << i.uri << endl << "byteLength : " << i.byteLength << endl << "data : ";
			for (const auto &j : i.d)
				s << hex << uppercase << (unsigned int) j << ' ';
			s << endl;
		}
		s << "}" << endl;
		return s;
	}

	GLubyte *Buffer::getData(int buffer, GLsizei offset) {
		return &data[buffer].d[offset];
	}
}
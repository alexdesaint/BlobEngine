#include <BlobEngine/glTF2/BufferView.hpp>

#include <iostream>

using namespace std;

namespace BlobEngine::glTF2 {

	BufferView::BufferView(Reader::JsonExplorer explorer) : buffer(explorer) {
		explorer.goToBaseNode();

		Reader::JsonExplorer buff;

		data.resize((size_t) explorer.getArraySize("bufferViews"));

		for (int i = 0; i < data.size(); i++) {
			buff = explorer.getArrayObject("bufferViews", i);

			data[i].byteOffset = buff.getInt("byteOffset");

			if (buff.hasMember("byteLength"))
				data[i].byteLength = buff.getInt("byteLength");

			data[i].target = static_cast<Target>(buff.getInt("target"));

			data[i].buffer = buff.getInt("buffer");
		}
	}

	std::ostream &operator<<(std::ostream &s, const BufferView &a) {
		s << "BufferView {" << std::endl;
		for (auto i : a.data) {
			s << "byteOffset : " << i.byteOffset << endl;
			s << "byteLength : " << i.byteLength << endl;
			s << "buffer : " << i.buffer << endl;
			s << "target : " << i.target << endl;
		}
		s << "}" << endl;
		return s;
	}

	GLubyte *BufferView::getData(int BufferView, GLsizei offset) {
		return &buffer.getData(data[BufferView].buffer, data[BufferView].byteOffset)[offset];
	}

	GLsizei BufferView::getSize(int BufferView, GLsizei offset) {
		return data[BufferView].byteLength - data[BufferView].byteOffset - offset;
	}
}
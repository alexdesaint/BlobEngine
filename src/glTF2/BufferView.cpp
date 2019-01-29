#include <BlobEngine/glTF2/BufferView.hpp>

#include <iostream>

using namespace std;

namespace Blob::glTF2 {

	BufferView::BufferView(Reader::JsonExplorer explorer) {
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

	GLsizei BufferView::getOffset(int BufferView) {
		return data[BufferView].byteOffset;
	}

	GLsizei BufferView::getSize(int BufferView, GLsizei offset) {
		return data[BufferView].byteLength - offset;
	}
}
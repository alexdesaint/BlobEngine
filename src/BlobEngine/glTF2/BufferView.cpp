#include <BlobEngine/glTF2/BufferView.hpp>

#include <iostream>

using namespace std;

namespace BlobEngine::glTF2 {

	BufferView::BufferView(Reader::JsonExplorer explorer) {
		explorer.goToBaseNode();

		Reader::JsonExplorer buff;

		dataView.resize((size_t)explorer.getArraySize("bufferViews"));

		for(int i = 0; i < dataView.size(); i++) {
			buff = explorer.getArrayObject("bufferViews", i);

			dataView[i].byteOffset = buff.getInt("byteOffset");

			if (buff.hasMember("byteLength"))
				dataView[i].byteLength = buff.getInt("byteLength");

			dataView[i].target = static_cast<Target>(buff.getInt("target"));

			dataView[i].buffer = buff.getInt("buffer");
		}
	}

	std::ostream &operator<<(std::ostream &s, const BufferView &a) {
		s << "BufferView {" << std::endl;
		for (auto i : a.dataView) {
			s << "byteOffset : " << i.byteOffset << endl;
			s << "byteLength : " << i.byteLength << endl;
			s << "buffer : " << i.buffer << endl;
			s << "target : " << i.target << endl;
		}
		s << "}" << endl;
		return s;
	}
}
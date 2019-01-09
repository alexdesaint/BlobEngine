#ifndef BLOBENGINE_TEXT_HPP
#define BLOBENGINE_TEXT_HPP

#include <BlobEngine/BlobGL/Shape.hpp>

namespace BlobEngine::BlobGL::Text {

	void createVBO();

	void deleteVBO();

	class Letter : public Renderable {
	public:
		explicit Letter(char c);
	};

	class Text : public Shape {
	};

}

#endif //BLOBENGINE_CUBE_HPP

#ifndef BLOBENGINE_TEXT_HPP
#define BLOBENGINE_TEXT_HPP

#include <BlobEngine/BlobGL/Shape.hpp>
#include <string>
#include <vector>

namespace BlobEngine::BlobGL::Text {

	void createVBO();

	void deleteVBO();

	class Plane2D : public Renderable, public Texture {
	public:
		Plane2D();
	};

	class Letter : public Renderable {
	public:
		explicit Letter(unsigned char c);
	};

	class Text : public Shape {
	private:
		float width = 0;
		std::vector<Letter> letters;

	public:
		explicit Text(const std::string &text);
	};

}

#endif

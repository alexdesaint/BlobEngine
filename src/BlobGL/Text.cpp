#include <BlobEngine/BlobGL/Text.hpp>

#include <glad/glad.h>

struct Data {
	float coor[2];
	float texCoor[2];
};

const GLushort planeIndices[] = {
		0, 1, 2, 0, 2, 3
};

using namespace Blob::GL;

VertexBufferObject *vbo;
Texture *alphabet;

namespace Blob::GL::Text {

	const size_t numberOfLetter = 32 * 4 - 1;

	float getLetterWidth(unsigned int c) {
		switch (c) {
			case '!':
			case '\'':
			case '.':
			case ':':
			case ';':
			case '|':
			case 'l':
			case 'i':
				return 3.f;
			case '(':
			case ')':
			case '[':
			case ']':
			case 'r':
			case 'j':
			case ',':
				return 4.f;
			case '"':
			case '/':
			case '\\':
			case '0':
			case '1':
			case '<':
			case '=':
			case '>':
			case '^':
			case 'T':
			case 'I':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'k':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 's':
			case 'u':
			case 'v':
			case 'x':
			case 'y':
			case 'z':
			case '{':
			case '}':
				return 5.f;
			default:
				return 6.f;
			case '#':
			case '$':
			case '%':
			case '&':
			case '*':
			case '+':
			case '-':
			case 'W':
			case 'X':
			case 'Y':
			case 'M':
			case 'N':
			case 'O':
			case 'Q':
			case 'm':
			case 'w':
			case '~':
				return 7.f;
			case '@':
				return 8.f;
		}
	}

	void createVBO() {
		Data data[(numberOfLetter + 1) * 4];

		unsigned int i;

		for (i = 0; i < numberOfLetter; i++) {
			float x;
			if (i < 32)
				x = 0;
			else if (i < 64)
				x = 8.f / 32;
			else
				x = 16.f / 32;

			float y = i % 32 * 7.f / 256;
			float w = getLetterWidth(i + 0x20);

			data[i * 4] = {{0.f, 0.f},
						   {x,   y + 7.f / 256}}; //bg
			data[i * 4 + 1] = {{w / 10,     0.f},
							   {x + w / 32, y + 7.f / 256}};    //bd
			data[i * 4 + 2] = {{w / 10,     1.f},
							   {x + w / 32, y}};    //hd
			data[i * 4 + 3] = {{0.f, 1.f},
							   {x,   y}};    //hg
		}

		data[i * 4] = {{0.f, 0.f},
					   {0.f, 1.f}}; //bg
		data[i * 4 + 1] = {{1.f, 0.f},
						   {1.f, 1.f}}; //bd
		data[i * 4 + 2] = {{1.f, 1.f},
						   {1.f, 0.f}}; //hd
		data[i * 4 + 3] = {{0.f, 1.f},
						   {0.F, 0.f}}; //hg

		vbo = new VertexBufferObject((GLubyte *) data, sizeof(data));
		alphabet = new Texture("data/alphabet.bmp", true);
	}

	void deleteVBO() {
		delete vbo;
	}

	Letter::Letter(unsigned char c) {

		c -= 0x20;
		if (c > 0x7e)
			c = 0;

		setBuffer(*vbo, sizeof(Data), c * 4 * sizeof(Data));

		setPositionVAO(2, GL_FLOAT, 0);
		setTexturePositionVAO(2, GL_FLOAT, sizeof(Data::coor));

		setIndices((GLubyte *) planeIndices, (GLsizei) sizeof(planeIndices), GL_UNSIGNED_SHORT);

		setTexture(*alphabet);
	}

	Text::Text(const std::string &text) {
		for (const char &c : text) {
			width += (getLetterWidth((unsigned int) c) - 1) / 10;
		}

		letters.reserve(text.size());

		float position = 0;
		for (const char &c : text) {
			auto i = (unsigned int) c;
			letters.emplace_back(i);
			letters.back().setPosition(-width / 2 + position, 0, 0);
			addRenderable(&letters.back());
			position += (getLetterWidth(i) - 1) / 10;
		}
	}

	Plane2D::Plane2D() {
		setBuffer(*vbo, sizeof(Data), numberOfLetter * 4 * sizeof(Data));

		setPositionVAO(2, GL_FLOAT, 0);
		setTexturePositionVAO(2, GL_FLOAT, sizeof(Data::coor));

		setIndices((GLubyte *) planeIndices, (GLsizei) sizeof(planeIndices), GL_UNSIGNED_SHORT);

		setTexture(*this);
	}
}

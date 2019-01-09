#include <BlobEngine/BlobGL/Text.hpp>

#include <glad/glad.h>

struct Data {
	float coor[2];
	float texCoor[2];
};

const Data data[] = {
		{{0.f, 0.f}, {0,  6.f/256 + 6.f/256}},    //bg
		{{0.5, 0.f}, {5.f/32,  6.f/256 + 6.f/256}},    //bd
		{{0.5, 0.6}, {5.f/32,  0 + 6.f/256}},    //hd
		{{0.f, 0.6}, {0,  0 + 6.f/256}},    //hg
};

const GLushort planeIndices[] = {
		0, 1, 2, 0, 2, 3
};

using namespace BlobEngine::BlobGL;

VertexBufferObject *vbo;
Texture *alphabet;

namespace BlobEngine::BlobGL::Text {

	void createVBO() {
		const Data data[256 * 4];

		for(int i = 0; i < 256; i++) {

		}

		vbo = new VertexBufferObject((GLubyte *) data, sizeof(data));
		alphabet = new Texture("data/alphabet.bmp", true);
	}

	void deleteVBO() {
		delete vbo;
	}

	Letter::Letter(char c) {
		setBuffer(*vbo, sizeof(Data));

		setPositionVAO(2, GL_FLOAT, 0);
		setTexturePositionVAO(2, GL_FLOAT, sizeof(Data::coor));

		setIndices((GLubyte *) planeIndices, (GLsizei) sizeof(planeIndices), GL_UNSIGNED_SHORT);

		setTexture(*alphabet);
	}
}

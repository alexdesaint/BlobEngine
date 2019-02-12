#include <BlobEngine/BlobGL/Form.hpp>
#include <glad/glad.h>

namespace Blob::GL {

	struct Data {
		float coor[3];
		float norm[3];
		float texCoor[2];
	};

	const Data data[] = {
			// x = devant
			// y = droite
			// z = haut

			// CUBE
			// Top face
			{{-0.5f, -0.5f, 0.5f},  {0.f,  0.f,  1.f},  {0.25, 0.f}},        //hg
			{{0.5f,  -0.5f, 0.5f},  {0.f,  0.f,  1.f},  {0.25, 0.25}},        //bg
			{{0.5f,  0.5f,  0.5f},  {0.f,  0.f,  1.f},  {0.5,  0.25}},        //bd
			{{-0.5f, 0.5f,  0.5f},  {0.f,  0.f,  1.f},  {0.5,  0.f}},        //hd

			// Bottom face
			{{-0.5f, -0.5f, -0.5f}, {0.f,  0.f,  -1.f}, {0.25, 0.75}},    //bg
			{{-0.5f, 0.5f,  -0.5f}, {0.f,  0.f,  -1.f}, {0.5,  0.75}},    //bd
			{{0.5f,  0.5f,  -0.5f}, {0.f,  0.f,  -1.f}, {0.5,  0.5}},        //hd
			{{0.5f,  -0.5f, -0.5f}, {0.f,  0.f,  -1.f}, {0.25, 0.5}},    //hg

			// Right face
			{{-0.5f, 0.5f,  -0.5f}, {0.f,  1.f,  0.f},  {0.75, 0.5}},        //bd
			{{-0.5f, 0.5f,  0.5f},  {0.f,  1.f,  0.f},  {0.75, 0.25}},    //hd
			{{0.5f,  0.5f,  0.5f},  {0.f,  1.f,  0.f},  {0.5,  0.25}},        //hg
			{{0.5f,  0.5f,  -0.5f}, {0.f,  1.f,  0.f},  {0.5,  0.5}},        //bg

			// Left face
			{{-0.5f, -0.5f, -0.5f}, {0.f,  -1.f, 0.f},  {0.f,  0.5}},        //bg
			{{0.5f,  -0.5f, -0.5f}, {0.f,  -1.f, 0.f},  {0.25, 0.5}},    //bd
			{{0.5f,  -0.5f, 0.5f},  {0.f,  -1.f, 0.f},  {0.25, 0.25}},    //hd
			{{-0.5f, -0.5f, 0.5f},  {0.f,  -1.f, 0.f},  {0.f,  0.25}},    //hg

			// Front face
			{{0.5f,  -0.5f, -0.5f}, {1.f,  0.f,  0.f},  {0.25, 0.5}},        //bg
			{{0.5f,  0.5f,  -0.5f}, {1.f,  0.f,  0.f},  {0.5,  0.5}},        //bd
			{{0.5f,  0.5f,  0.5f},  {1.f,  0.f,  0.f},  {0.5,  0.25}},        //hd
			{{0.5f,  -0.5f, 0.5f},  {1.f,  0.f,  0.f},  {0.25, 0.25}},    //hg

			// Back face
			{{-0.5f, -0.5f, -0.5f}, {-1.f, 0.f,  0.f},  {1.f,  0.5}},        //bd
			{{-0.5f, -0.5f, 0.5f},  {-1.f, 0.f,  0.f},  {1.f,  0.25}},    //hd
			{{-0.5f, 0.5f,  0.5f},  {-1.f, 0.f,  0.f},  {0.75, 0.25}},    //hg
			{{-0.5f, 0.5f,  -0.5f}, {-1.f, 0.f,  0.f},  {0.75, 0.5}},    //bg

			// PLANE
			{{-0.5f, -0.5f, 0.f},   {0.f,  0.f,  1.f},  {0.f,  0.f}},    //hg
			{{0.5f,  -0.5f, 0.f},   {0.f,  0.f,  1.f},  {0.f,  1.f}},    //bg
			{{0.5f,  0.5f,  0.f},   {0.f,  0.f,  1.f},  {1.f,  1.f}},    //bd
			{{-0.5f, 0.5f,  0.f},   {0.f,  0.f,  1.f},  {1.f,  0.f}},    //hd

			// OCTAGONAL PRISM

			// Top face
			{{0.f,   0.f,   0.5f},  {0.f,  0.f,  1.f},  {0.25, 0.f}},        //centre

			{{-0.2f, -0.5f, 0.5f},  {0.f,  0.f,  1.f},  {0.5,  0.f}},        //8 gh
			{{0.2f,  -0.5f, 0.5f},  {0.f,  0.f,  1.f},  {0.5,  0.f}},        //7 gb
			{{0.5f,  -0.2f, 0.5f},  {0.f,  0.f,  1.f},  {0.5,  0.f}},        //6 bg
			{{0.5f,  0.2f,  0.5f},  {0.f,  0.f,  1.f},  {0.5,  0.f}},        //5 bd
			{{0.2f,  0.5f,  0.5f},  {0.f,  0.f,  1.f},  {0.5,  0.f}},        //4 db
			{{-0.2f, 0.5f,  0.5f},  {0.f,  0.f,  1.f},  {0.5,  0.f}},        //3 dh
			{{-0.5f, 0.2f,  0.5f},  {0.f,  0.f,  1.f},  {0.5,  0.25}},        //2 hd
			{{-0.5f, -0.2f, 0.5f},  {0.f,  0.f,  1.f},  {0.25, 0.25}},        //1 hg

			// Bottom face
			{{0.f,   0.f,   -0.5f}, {0.f,  0.f,  -1.f}, {0.25, 0.f}},        //centre

			{{-0.5f, -0.2f, -0.5f}, {0.f,  0.f,  -1.f}, {0.25, 0.25}},        //1 hg
			{{-0.5f, 0.2f,  -0.5f}, {0.f,  0.f,  -1.f}, {0.5,  0.25}},        //2 hd
			{{-0.2f, 0.5f,  -0.5f}, {0.f,  0.f,  -1.f}, {0.5,  0.f}},        //3 dh
			{{0.2f,  0.5f,  -0.5f}, {0.f,  0.f,  -1.f}, {0.5,  0.f}},        //4 db
			{{0.5f,  0.2f,  -0.5f}, {0.f,  0.f,  -1.f}, {0.5,  0.f}},        //5 bd
			{{0.5f,  -0.2f, -0.5f}, {0.f,  0.f,  -1.f}, {0.5,  0.f}},        //6 bg
			{{0.2f,  -0.5f, -0.5f}, {0.f,  0.f,  -1.f}, {0.5,  0.f}},        //7 gb
			{{-0.2f, -0.5f, -0.5f}, {0.f,  0.f,  -1.f}, {0.5,  0.f}},        //8 gh

			// Front face
			{{0.5f,  -0.2f, 0.5f},  {1.f,  0.f,  0.f},  {0.5,  0.f}},        //6 bg
			{{0.5f,  -0.2f, -0.5f}, {1.f,  0.f,  0.f},  {0.5,  0.f}},        //6 bg
			{{0.5f,  0.2f,  -0.5f}, {1.f,  0.f,  0.f},  {0.5,  0.f}},        //5 bd
			{{0.5f,  0.2f,  0.5f},  {1.f,  0.f,  0.f},  {0.5,  0.f}},        //5 bd

			// Right face
			{{-0.2f, 0.5f,  -0.5f}, {0.f,  1.f,  0.f},  {0.5,  0.f}},        //3 dh
			{{-0.2f, 0.5f,  0.5f},  {0.f,  1.f,  0.f},  {0.5,  0.f}},        //3 dh
			{{0.2f,  0.5f,  0.5f},  {0.f,  1.f,  0.f},  {0.5,  0.f}},        //4 db
			{{0.2f,  0.5f,  -0.5f}, {0.f,  1.f,  0.f},  {0.5,  0.f}},        //4 db

			// Back face
			{{-0.5f, -0.2f, -0.5f}, {-1.f, 0.f,  0.f},  {0.5,  0.f}},        //6 bg
			{{-0.5f, -0.2f, 0.5f},  {-1.f, 0.f,  0.f},  {0.5,  0.f}},        //6 bg
			{{-0.5f, 0.2f,  0.5f},  {-1.f, 0.f,  0.f},  {0.5,  0.f}},        //5 bd
			{{-0.5f, 0.2f,  -0.5f}, {-1.f, 0.f,  0.f},  {0.5,  0.f}},        //5 bd

			// Left face
			{{-0.2f, -0.5f, -0.5f}, {0.f,  -1.f, 0.f},  {0.5,  0.f}},        //3 dh
			{{0.2f,  -0.5f, -0.5f}, {0.f,  -1.f, 0.f},  {0.5,  0.f}},        //4 db
			{{0.2f,  -0.5f, 0.5f},  {0.f,  -1.f, 0.f},  {0.5,  0.f}},        //4 db
			{{-0.2f, -0.5f, 0.5f},  {0.f,  -1.f, 0.f},  {0.5,  0.f}},        //3 dh

	};

	const GLushort cubeIndices[] = {
			0, 1, 2, 0, 2, 3,    // front
			4, 5, 6, 4, 6, 7,    // back
			8, 9, 10, 8, 10, 11,   // top
			12, 13, 14, 12, 14, 15,   // bottom
			16, 17, 18, 16, 18, 19,   // right
			20, 21, 22, 20, 22, 23   // left
	};

	const GLushort planeIndices[] = {
			0, 1, 2, 0, 2, 3
	};

	const GLushort octagonalPrismIndices[] = {
			0, 1, 2, 0, 2, 3, 0, 3, 4, 0, 4, 5, 0, 5, 6, 0, 6, 7, 0, 7, 8, 0, 8, 1, // top
			9, 10, 11, 9, 11, 12, 9, 12, 13, 9, 13, 14, 9, 14, 15, 9, 15, 16, 9, 16, 17, 9, 17, 10, // bottom
			18, 19, 20, 18, 20, 21, // front
			22, 23, 24, 22, 24, 25, // right
			26, 27, 28, 26, 28, 29, // back
			30, 31, 32, 30, 32, 33, // back
	};

	VertexBufferObject *vbo;

	void createVBO() {
		vbo = new VertexBufferObject((GLubyte *) data, sizeof(data));
	}

	void deleteVBO() {
		delete vbo;
	}

	Cube::Cube(ShaderProgram *shaderProgram) : Texture(0, 100, 100) {
		setBuffer(*vbo, sizeof(Data));

		setShaderProgram(shaderProgram);

		setArrayVAO(3, "Position", GL_FLOAT, (uint32_t)offsetof(Data, coor));
		setArrayVAO(3, "Normal", GL_FLOAT, (uint32_t)offsetof(Data, norm));
		setArrayVAO(2, "TexturePosition", GL_FLOAT, (uint32_t)offsetof(Data, texCoor));

		setIndices((unsigned short *) cubeIndices, (GLsizei) sizeof(cubeIndices), GL_UNSIGNED_SHORT);

		setTexture(*this);
	}

	Plane::Plane(ShaderProgram *shaderProgram) : Texture(0, 100, 100) {
		setBuffer(*vbo, sizeof(Data), 4 * 6 * sizeof(Data));

		setShaderProgram(shaderProgram);

		setArrayVAO(3, "Position", GL_FLOAT, (uint32_t)offsetof(Data, coor));
		setArrayVAO(3, "Normal", GL_FLOAT, (uint32_t)offsetof(Data, norm));
		setArrayVAO(2, "TexturePosition", GL_FLOAT, (uint32_t)offsetof(Data, texCoor));

		setIndices((unsigned short *) planeIndices, (GLsizei) sizeof(planeIndices), GL_UNSIGNED_SHORT);

		setTexture(*this);
	}

	OctagonalPrism::OctagonalPrism(ShaderProgram *shaderProgram) : Texture(0, 100, 100) {
		setBuffer(*vbo, sizeof(Data), (4 * 6 + 4) * sizeof(Data));

		setShaderProgram(shaderProgram);

		setArrayVAO(3, "Position", GL_FLOAT, (uint32_t)offsetof(Data, coor));
		setArrayVAO(3, "Normal", GL_FLOAT, (uint32_t)offsetof(Data, norm));
		setArrayVAO(2, "TexturePosition", GL_FLOAT, (uint32_t)offsetof(Data, texCoor));

		setIndices((unsigned short *) octagonalPrismIndices, (GLsizei) sizeof(octagonalPrismIndices), GL_UNSIGNED_SHORT);

		setTexture(*this);
	}
}
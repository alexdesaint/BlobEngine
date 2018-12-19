#include <BlobEngine/BlobGL/ShaderProgram.hpp>
#include <iostream>
#include <SDL2/SDL.h>
#include <vector>

int main() {
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	if (SDL_Init(SDL_INIT_VIDEO))
		return 1;

	auto window = SDL_CreateWindow("Hello World!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 400, 400,
							  SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

	if (window == nullptr)
		return 2;

	auto glContext = SDL_GL_CreateContext(window);

	if (glContext == nullptr)
		return 3;

	if (!gladLoadGL())
		return 4;

	if (SDL_GL_SetSwapInterval(-1) == -1)
		SDL_GL_SetSwapInterval(1);

	glEnable(GL_CULL_FACE); // cull face
	glCullFace(GL_FRONT);// cull back face
	glFrontFace(GL_CW);// GL_CCW for counter clock-wise
	glEnable( GL_DEPTH_TEST );
	glClearColor(0.2, 0.2, 0.2, 1.0);

	GLuint loc_attrib = 0, normal_attrib = 1, texcoord_attrib = 2;

	GLuint array;
	// Generate a name for the array and create it.
	// Note that glGenVertexArrays() won't work here.
	glCreateVertexArrays(1, &array);
	// Instead of binding it, we pass it to the functions below.

	// Enable my attributes
	glEnableVertexArrayAttrib(array, loc_attrib);
	glEnableVertexArrayAttrib(array, normal_attrib);
	glEnableVertexArrayAttrib(array, texcoord_attrib);
	// Set up the formats for my attributes
	glVertexArrayAttribFormat(array, loc_attrib,      3, GL_FLOAT, GL_FALSE, 0);
	glVertexArrayAttribFormat(array, normal_attrib,   3, GL_FLOAT, GL_FALSE, 12);
	glVertexArrayAttribFormat(array, texcoord_attrib, 2, GL_FLOAT, GL_FALSE, 24);
	// Make my attributes all use binding 0
	glVertexArrayAttribBinding(array, loc_attrib,      0);
	glVertexArrayAttribBinding(array, normal_attrib,   0);
	glVertexArrayAttribBinding(array, texcoord_attrib, 0);

	struct Data {
		float coor[3];
		float norm[3];
		float texCoor[2];
	};

	std::vector<Data> data = {
			// Front face
			{{-1.0, -1.0, 1.0}, {0.0, -1.0, 0.0}, {0.0, 0.0}},
			{{1.0,  -1.0, 1.0}, {0.0, -1.0, 0.0}, {0.0, 0.0}},
			{{1.0,  1.0,  1.0}, {0.0, -1.0, 0.0}, {0.0, 0.0}},
			{{-1.0, 1.0,  1.0}, {0.0, -1.0, 0.0}, {0.0, 0.0}},

			// Back face
			{{-1.0, -1.0, -1.0}, {0.0, -1.0, 0.0}, {0.0, 0.0}},
			{{-1.0, 1.0,  -1.0}, {0.0, -1.0, 0.0}, {0.0, 0.0}},
			{{1.0,  1.0,  -1.0}, {0.0, -1.0, 0.0}, {0.0, 0.0}},
			{{1.0,  -1.0, -1.0}, {0.0, -1.0, 0.0}, {0.0, 0.0}},

			// Top face
			{{-1.0, 1.0,  -1.0}, {0.0, -1.0, 0.0}, {0.0, 0.0}},
			{{-1.0, 1.0,  1.0}, {0.0, -1.0, 0.0}, {0.0, 0.0}},
			{{1.0,  1.0,  1.0}, {0.0, -1.0, 0.0}, {0.0, 0.0}},
			{{1.0,  1.0,  -1.0}, {0.0, -1.0, 0.0}, {0.0, 0.0}},

			// Bottom face
			{{-1.0, -1.0, -1.0}, {0.0, -1.0, 0.0}, {0.0, 0.0}},
			{{1.0,  -1.0, -1.0}, {0.0, -1.0, 0.0}, {0.0, 0.0}},
			{{1.0,  -1.0, 1.0}, {0.0, -1.0, 0.0}, {0.0, 0.0}},
			{{-1.0, -1.0, 1.0}, {0.0, -1.0, 0.0}, {0.0, 0.0}},

			// Right face
			{{1.0,  -1.0, -1.0}, {0.0, -1.0, 0.0}, {0.0, 0.0}},
			{{1.0,  1.0,  -1.0}, {0.0, -1.0, 0.0}, {0.0, 0.0}},
			{{1.0,  1.0,  1.0}, {0.0, -1.0, 0.0}, {0.0, 0.0}},
			{{1.0,  -1.0, 1.0}, {0.0, -1.0, 0.0}, {0.0, 0.0}},

			// Left face
			{{-1.0, -1.0, -1.0}, {0.0, -1.0, 0.0}, {0.0, 0.0}},
			{{-1.0, -1.0, 1.0}, {0.0, -1.0, 0.0}, {0.0, 0.0}},
			{{-1.0, 1.0,  1.0}, {0.0, -1.0, 0.0}, {0.0, 0.0}},
			{{-1.0, 1.0,  -1.0}, {0.0, -1.0, 0.0}, {0.0, 0.0}}
	};

	const std::vector<GLushort> indices = {
			0, 1, 2, 0, 2, 3,    // front
			4, 5, 6, 4, 6, 7,    // back
			8, 9, 10, 8, 10, 11,   // top
			12, 13, 14, 12, 14, 15,   // bottom
			16, 17, 18, 16, 18, 19,   // right
			20, 21, 22, 20, 22, 23,   // left
	};

	GLuint buffer;

	glCreateBuffers(1, &buffer);

	glNamedBufferStorage(buffer, sizeof(Data) * data.size(), data.data(), 0);

	// Quickly bind all attributes to use "buffer"
	glVertexArrayVertexBuffer(array, 0, buffer, 0, 32);

	// You still have to bind the array to draw.
	glBindVertexArray(array);

	BlobEngine::BlobGL::ShaderProgram shaderProgram("../data/vertex.glsl", "../data/fragment.glsl");

	SDL_Event sdl_event;
	bool quit = false;
	while (!quit) {

		glUseProgram(shaderProgram.getProgram());
		glBindVertexArray(array);

		//glm::mat4 mvp = projectionMatrix * viewMatrix * shapeModel * shape.getModelMatrix();

		//std::cout << "mat :" << std::endl << viewMatrix;

		//GLint mvpLocation = glGetUniformLocation(program.getProgram(), "mvp");

		//glUniformMatrix4fv(mvpLocation, 1, GL_FALSE, glm::value_ptr(mvp));

		glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_SHORT, indices.data());

		while (SDL_PollEvent(&sdl_event) != 0) {

			if (sdl_event.type == SDL_QUIT) {
				quit = true;
			}
		}
	}

	return 0;
}
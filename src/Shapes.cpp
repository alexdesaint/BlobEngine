#include <Blob/GL/Core.hpp> // TODO: remove this
#include <Blob/Shapes.hpp>
#include <glm/gtc/type_ptr.inl>
#include <imgui.h>
#include <iostream>

using namespace Blob::GL;

namespace Blob::Shapes {

/********************* Shapes *********************/

struct Data {
    float coor[3];
    float norm[3];
};

const Data data[] = {
    // x = devant
    // y = droite
    // z = haut

    // CUBE
    // Top face
    {{1.0f, -1.0f, 1.0f}, {0.0f, -0.0f, 1.0f}},
    {{1.0f, 1.0f, 1.0f}, {0.0f, -0.0f, 1.0f}},
    {{-1.0f, 1.0f, 1.0f}, {0.0f, -0.0f, 1.0f}},
    {{-1.0f, -1.0f, 1.0f}, {0.0f, -0.0f, 1.0f}},
    {{-1.0f, -1.0f, 1.0f}, {0.0f, -1.0f, 0.0f}},
    {{-1.0f, -1.0f, -1.0f}, {0.0f, -1.0f, 0.0f}},
    {{1.0f, -1.0f, -1.0f}, {0.0f, -1.0f, 0.0f}},
    {{1.0f, -1.0f, 1.0f}, {0.0f, -1.0f, 0.0f}},
    {{-1.0f, 1.0f, 1.0f}, {-1.0f, -0.0f, 0.0f}},
    {{-1.0f, 1.0f, -1.0f}, {-1.0f, -0.0f, 0.0f}},
    {{-1.0f, -1.0f, -1.0f}, {-1.0f, -0.0f, 0.0f}},
    {{-1.0f, -1.0f, 1.0f}, {-1.0f, -0.0f, 0.0f}},
    {{-1.0f, -1.0f, -1.0f}, {0.0f, 0.0f, -1.0f}},
    {{-1.0f, 1.0f, -1.0f}, {0.0f, 0.0f, -1.0f}},
    {{1.0f, 1.0f, -1.0f}, {0.0f, 0.0f, -1.0f}},
    {{1.0f, -1.0f, -1.0f}, {0.0f, 0.0f, -1.0f}},
    {{1.0f, -1.0f, 1.0f}, {1.0f, -0.0f, 0.0f}},
    {{1.0f, -1.0f, -1.0f}, {1.0f, -0.0f, 0.0f}},
    {{1.0f, 1.0f, -1.0f}, {1.0f, -0.0f, 0.0f}},
    {{1.0f, 1.0f, 1.0f}, {1.0f, -0.0f, 0.0f}},
    {{1.0f, 1.0f, 1.0f}, {0.0f, 1.0f, 0.0f}},
    {{1.0f, 1.0f, -1.0f}, {0.0f, 1.0f, 0.0f}},
    {{-1.0f, 1.0f, -1.0f}, {0.0f, 1.0f, 0.0f}},
    {{-1.0f, 1.0f, 1.0f}, {0.0f, 1.0f, 0.0f}},

    // PLANE
    {{-0.5f, -0.5f, 0.f}, {0.f, 0.f, 1.f}}, // hg
    {{0.5f, -0.5f, 0.f}, {0.f, 0.f, 1.f}},  // bg
    {{0.5f, 0.5f, 0.f}, {0.f, 0.f, 1.f}},   // bd
    {{-0.5f, 0.5f, 0.f}, {0.f, 0.f, 1.f}},  // hd

    // OCTAGONAL PRISM

    {{0.7f, 0.7f, 1.0f}, {0.4f, 0.9f, 0.0f}},
    {{0.7f, 0.7f, -1.0f}, {0.4f, 0.9f, 0.0f}},
    {{0.0f, 1.0f, -1.0f}, {0.4f, 0.9f, 0.0f}},
    {{0.0f, 1.0f, 1.0f}, {0.4f, 0.9f, 0.0f}},
    {{1.0f, -0.0f, 1.0f}, {0.9f, 0.4f, 0.0f}},
    {{1.0f, -0.0f, -1.0f}, {0.9f, 0.4f, 0.0f}},
    {{0.7f, 0.7f, -1.0f}, {0.9f, 0.4f, 0.0f}},
    {{0.7f, 0.7f, 1.0f}, {0.9f, 0.4f, 0.0f}},
    {{0.7f, -0.7f, 1.0f}, {0.9f, -0.4f, 0.0f}},
    {{0.7f, -0.7f, -1.0f}, {0.9f, -0.4f, 0.0f}},
    {{1.0f, -0.0f, -1.0f}, {0.9f, -0.4f, 0.0f}},
    {{1.0f, -0.0f, 1.0f}, {0.9f, -0.4f, 0.0f}},
    {{-0.0f, -1.0f, 1.0f}, {0.4f, -0.9f, 0.0f}},
    {{-0.0f, -1.0f, -1.0f}, {0.4f, -0.9f, 0.0f}},
    {{0.7f, -0.7f, -1.0f}, {0.4f, -0.9f, 0.0f}},
    {{0.7f, -0.7f, 1.0f}, {0.4f, -0.9f, 0.0f}},
    {{-0.7f, -0.7f, 1.0f}, {-0.4f, -0.9f, 0.0f}},
    {{-0.7f, -0.7f, -1.0f}, {-0.4f, -0.9f, 0.0f}},
    {{-0.0f, -1.0f, -1.0f}, {-0.4f, -0.9f, 0.0f}},
    {{-0.0f, -1.0f, 1.0f}, {-0.4f, -0.9f, 0.0f}},
    {{-1.0f, 0.0f, 1.0f}, {-0.9f, -0.4f, 0.0f}},
    {{-1.0f, 0.0f, -1.0f}, {-0.9f, -0.4f, 0.0f}},
    {{-0.7f, -0.7f, -1.0f}, {-0.9f, -0.4f, 0.0f}},
    {{-0.7f, -0.7f, 1.0f}, {-0.9f, -0.4f, 0.0f}},
    {{0.7f, 0.7f, 1.0f}, {0.0f, 0.0f, 1.0f}},
    {{0.0f, 1.0f, 1.0f}, {0.0f, 0.0f, 1.0f}},
    {{-0.7f, 0.7f, 1.0f}, {0.0f, 0.0f, 1.0f}},
    {{1.0f, -0.0f, 1.0f}, {0.0f, 0.0f, 1.0f}},
    {{-1.0f, 0.0f, 1.0f}, {0.0f, 0.0f, 1.0f}},
    {{-0.7f, -0.7f, 1.0f}, {0.0f, 0.0f, 1.0f}},
    {{0.7f, -0.7f, 1.0f}, {0.0f, 0.0f, 1.0f}},
    {{-0.0f, -1.0f, 1.0f}, {0.0f, 0.0f, 1.0f}},
    {{-0.7f, 0.7f, 1.0f}, {-0.9f, 0.4f, 0.0f}},
    {{-0.7f, 0.7f, -1.0f}, {-0.9f, 0.4f, 0.0f}},
    {{-1.0f, 0.0f, -1.0f}, {-0.9f, 0.4f, 0.0f}},
    {{-1.0f, 0.0f, 1.0f}, {-0.9f, 0.4f, 0.0f}},
    {{0.0f, 1.0f, 1.0f}, {-0.4f, 0.9f, 0.0f}},
    {{0.0f, 1.0f, -1.0f}, {-0.4f, 0.9f, 0.0f}},
    {{-0.7f, 0.7f, -1.0f}, {-0.4f, 0.9f, 0.0f}},
    {{-0.7f, 0.7f, 1.0f}, {-0.4f, 0.9f, 0.0f}},
    {{-0.7f, 0.7f, -1.0f}, {0.0f, 0.0f, -1.0f}},
    {{0.0f, 1.0f, -1.0f}, {0.0f, 0.0f, -1.0f}},
    {{0.7f, 0.7f, -1.0f}, {0.0f, 0.0f, -1.0f}},
    {{1.0f, -0.0f, -1.0f}, {0.0f, 0.0f, -1.0f}},
    {{-1.0f, 0.0f, -1.0f}, {0.0f, 0.0f, -1.0f}},
    {{-0.7f, -0.7f, -1.0f}, {0.0f, 0.0f, -1.0f}},
    {{0.7f, -0.7f, -1.0f}, {0.0f, 0.0f, -1.0f}},
    {{-0.0f, -1.0f, -1.0f}, {0.0f, 0.0f, -1.0f}},
};

uint16_t cubeIndices[] = {0,  1,  2,  0,  2,  3,  4,  5,  6,  4,  6,  7,  8,  9,  10, 8,  10, 11,
                          12, 13, 14, 12, 14, 15, 16, 17, 18, 16, 18, 19, 20, 21, 22, 20, 22, 23};

uint16_t planeIndices[] = {0, 1, 2, 0, 2, 3};

uint16_t octagonalPrismIndices[] = {0,  1,  2,  0,  2,  3,  4,  5,  6,  4,  6,  7,  8,  9,  10, 8,  10, 11, 12, 13, 14, 12, 14, 15, 16, 17, 18, 16,
                                    18, 19, 20, 21, 22, 20, 22, 23, 24, 25, 26, 27, 24, 26, 27, 26, 28, 27, 28, 29, 30, 27, 29, 30, 29, 31, 32, 33,
                                    34, 32, 34, 35, 36, 37, 38, 36, 38, 39, 40, 41, 42, 40, 42, 43, 44, 40, 43, 45, 44, 43, 45, 43, 46, 47, 45, 46};

VertexBufferObject *vbo;
VertexArrayObject *vaoCube;
VertexArrayObject *vaoPlane;
VertexArrayObject *vaoOctagonalPrism;

void addBasicShaders() {

    std::cout << "add Basic Shaders" << std::endl;

    {
        Blob::GL::ShaderProgram &sp = Blob::GL::ShaderProgram::Shaders["POSITION"];
        sp.addVertexShader(R"=====(
	#version 450

	layout (location = 0) in vec3 POSITION;

	uniform mat4 model;
	uniform mat4 view;
	uniform mat4 projection;

	void main()	{
		gl_Position = projection * view * model * vec4(POSITION, 1.0);
	}
	)=====");
        sp.addFragmentShader(R"=====(
	#version 450

	out vec4 FragColor;

	void main()	{
		FragColor = vec4(0.0, 0.4, 0.4, 1.0);
	}
	)=====");
        sp.linkShaders();
    }
    {
        Blob::GL::ShaderProgram &sp = Blob::GL::ShaderProgram::Shaders["POSITION_NORMAL"];
        sp.addVertexShader(R"=====(
	#version 450

	layout (location = 0) in vec3 POSITION;
	layout (location = 1) in vec3 NORMAL;

	out vec3 FragPos;
	out vec3 FragNormal;

	uniform mat4 model;
	uniform mat4 view;
	uniform mat4 projection;

	void main()
	{
		FragPos = vec3(model * vec4(POSITION, 1.0));
		FragNormal = mat3(transpose(inverse(model))) * NORMAL;

		gl_Position = projection * view * vec4(FragPos, 1.0);
	}
	)=====");
        sp.addFragmentShader(R"=====(
	#version 450

	out vec4 FragColor;

	in vec3 FragNormal;
	in vec3 FragPos;
	in vec2 TexCoord;

	uniform sampler2D ourTexture;
	uniform vec2 texScale;

	void main()
	{
		vec3 lightPos = vec3(4.0, 4.0, 0.0);
		vec3 lightColor = vec3(1.0, 1.0, 1.0);
		vec4 objectColor = vec4(0.0, 0.4, 0.4, 1.0);
		//
		float ambientStrength = 0.2;
		vec3 ambient = ambientStrength * lightColor;

		// diffuse
		vec3 norm = normalize(FragNormal);
		vec3 lightDir = normalize(vec3(1.0, -1.0, 2.0));
		float diff = max(dot(norm, lightDir), 0.0);
		vec3 diffuse = diff * lightColor;

		FragColor = vec4(ambient + diffuse, 1.0) * objectColor;
	}
	)=====");
        sp.linkShaders();
    }
    {
        Blob::GL::ShaderProgram &sp = Blob::GL::ShaderProgram::Shaders["POSITION_NORMAL_TEXCOORD_0"];
        sp.addVertexShader(R"=====(
	#version 450

	layout (location = 0) in vec3 POSITION;
	layout (location = 1) in vec3 NORMAL;
	layout (location = 2) in vec2 TEXCOORD_0;

	out vec3 FragPos;
	out vec3 FragNormal;
	out vec2 TexCoord;

	uniform mat4 model;
	uniform mat4 view;
	uniform mat4 projection;

	void main()
	{
		FragPos = vec3(model * vec4(POSITION, 1.0));
		FragNormal = mat3(transpose(inverse(model))) * NORMAL;

		gl_Position = projection * view * vec4(FragPos, 1.0);

		TexCoord = TEXCOORD_0;
	}
	)=====");
        sp.addFragmentShader(R"=====(
	#version 450

	out vec4 FragColor;

	in vec3 FragNormal;
	in vec3 FragPos;
	in vec2 TexCoord;

	uniform sampler2D ourTexture;
	uniform vec2 texScale;

	void main()
	{
		vec3 lightPos = vec3(4.0, 4.0, 0.0);
		vec3 lightColor = vec3(1.0, 1.0, 1.0);
		vec4 objectColor = texture(ourTexture, TexCoord * texScale);
		//
		float ambientStrength = 0.2;
		vec3 ambient = ambientStrength * lightColor;

		// diffuse
		vec3 norm = normalize(FragNormal);
		vec3 lightDir = normalize(vec3(1.0, -1.0, 2.0));
		float diff = max(dot(norm, lightDir), 0.0);
		vec3 diffuse = diff * lightColor;

		FragColor = vec4(ambient + diffuse, 1.0) * objectColor;
	}
	)=====");
        sp.linkShaders();
    }
}

void init() {
    DefaultMaterial::init();
    SingleColorMaterial::init();
    vbo = new VertexBufferObject((uint8_t*) data, sizeof(data));
    vaoCube = new VertexArrayObject();

    vaoCube->setBuffer(*vbo, sizeof(Data));
    vaoCube->setArray<float>(3, ShaderProgram::AttributeLocation::POSITION, (uint32_t) offsetof(Data, coor));
    vaoCube->setArray<float>(3, ShaderProgram::AttributeLocation::NORMAL, (uint32_t) offsetof(Data, norm));

    vaoPlane = new VertexArrayObject();
    vaoPlane->setBuffer(*vbo, sizeof(Data), 4 * 6 * sizeof(Data));
    vaoPlane->setArray<float>(3, ShaderProgram::AttributeLocation::POSITION, (uint32_t) offsetof(Data, coor));
    vaoPlane->setArray<float>(3, ShaderProgram::AttributeLocation::NORMAL, (uint32_t) offsetof(Data, norm));

    vaoOctagonalPrism = new VertexArrayObject();
    vaoOctagonalPrism->setBuffer(*vbo, sizeof(Data), (4 * 6 + 4) * sizeof(Data));
    vaoOctagonalPrism->setArray<float>(3,  ShaderProgram::AttributeLocation::POSITION, (uint32_t) offsetof(Data, coor));
    vaoOctagonalPrism->setArray<float>(3, ShaderProgram::AttributeLocation::NORMAL, (uint32_t) offsetof(Data, norm));
}

void destroy() {
    DefaultMaterial::destroy();
    SingleColorMaterial::destroy();

    delete vbo;
    delete vaoCube;
    delete vaoPlane;
    delete vaoOctagonalPrism;
}

Cube::Cube(const Material &singleColorMaterial) : Mesh(*vaoCube, singleColorMaterial) {
    setIndices(cubeIndices, sizeof(cubeIndices) / sizeof(*cubeIndices));
}

Plane::Plane(const Material &singleColorMaterial) : Mesh(*vaoPlane, singleColorMaterial) {
    setIndices(planeIndices, sizeof(planeIndices) / sizeof(*planeIndices));
}

OctagonalPrism::OctagonalPrism(const Material &singleColorMaterial) : Mesh(*vaoOctagonalPrism, singleColorMaterial) {
    setIndices(octagonalPrismIndices, sizeof(octagonalPrismIndices) / sizeof(*octagonalPrismIndices));
}
} // namespace Blob::Shapes
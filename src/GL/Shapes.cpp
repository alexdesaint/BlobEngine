#include <Blob/GL/Shapes.hpp>
#include <glad/glad.h>

namespace Blob::GL {
    ShaderProgram *Shaders::Shader_2D_POSITION_TEXCOORD_0_COLOR_0;

    ShaderProgram *Shaders::Shader_3D_POSITION;
    ShaderProgram *Shaders::Shader_3D_POSITION_NORMAL;
    ShaderProgram *Shaders::Shader_3D_POSITION_NORMAL_TEXCOORD_0;

    void initShaders() {

        Shaders::Shader_2D_POSITION_TEXCOORD_0_COLOR_0 = new ShaderProgram();
        Shaders::Shader_2D_POSITION_TEXCOORD_0_COLOR_0->addVertexShader(R"=====(
#version 450

layout (location = 0) in vec2 Position;
layout (location = 1) in vec2 TexturePosition;
layout (location = 2) in vec4 Color;

uniform mat4 projection;
out vec2 Frag_UV;
out vec4 Frag_Color;

void main() {
    Frag_UV = TexturePosition;
    Frag_Color = Color;
    gl_Position = projection * vec4(Position.xy, 0, 1);
}
		)=====");
        Shaders::Shader_2D_POSITION_TEXCOORD_0_COLOR_0->addFragmentShader(R"=====(
#version 450

layout (location = 0) out vec4 Out_Color;

in vec2 Frag_UV;
in vec4 Frag_Color;
uniform sampler2D Texture;

void main() {
    Out_Color = Frag_Color * texture(Texture, Frag_UV.st);
}
		)=====");
        Shaders::Shader_2D_POSITION_TEXCOORD_0_COLOR_0->linkShaders();

        Shaders::Shader_3D_POSITION = new ShaderProgram();
        Shaders::Shader_3D_POSITION->addVertexShader(R"=====(
	#version 450

	layout (location = 0) in vec3 POSITION;

	uniform mat4 model;
	uniform mat4 view;
	uniform mat4 projection;

	void main()	{
		gl_Position = projection * view * model * vec4(POSITION, 1.0);
	}
	)=====");
        Shaders::Shader_3D_POSITION->addFragmentShader(R"=====(
	#version 450

	out vec4 FragColor;

	void main()	{
		FragColor = vec4(0.0, 0.4, 0.4, 1.0);
	}
	)=====");
        Shaders::Shader_3D_POSITION->linkShaders();

        Shaders::Shader_3D_POSITION_NORMAL = new ShaderProgram();
        Shaders::Shader_3D_POSITION_NORMAL->addVertexShader(R"=====(
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
        Shaders::Shader_3D_POSITION_NORMAL->addFragmentShader(R"=====(
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
        Shaders::Shader_3D_POSITION_NORMAL->linkShaders();

        Shaders::Shader_3D_POSITION_NORMAL_TEXCOORD_0 = new ShaderProgram();
        Shaders::Shader_3D_POSITION_NORMAL_TEXCOORD_0->addVertexShader(R"=====(
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
        Shaders::Shader_3D_POSITION_NORMAL_TEXCOORD_0->addFragmentShader(R"=====(
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
        Shaders::Shader_3D_POSITION_NORMAL_TEXCOORD_0->linkShaders();
    }

    void destroyShaders() {
        delete Shaders::Shader_2D_POSITION_TEXCOORD_0_COLOR_0;
        delete Shaders::Shader_3D_POSITION;
        delete Shaders::Shader_3D_POSITION_NORMAL;
        delete Shaders::Shader_3D_POSITION_NORMAL_TEXCOORD_0;
    }
}

namespace Blob::GL::Shapes {

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

	GLushort cubeIndices[] = {
			0, 1, 2, 0, 2, 3,    // front
			4, 5, 6, 4, 6, 7,    // back
			8, 9, 10, 8, 10, 11,   // top
			12, 13, 14, 12, 14, 15,   // bottom
			16, 17, 18, 16, 18, 19,   // right
			20, 21, 22, 20, 22, 23   // left
	};

	GLushort planeIndices[] = {
			0, 1, 2, 0, 2, 3
	};

	GLushort octagonalPrismIndices[] = {
			0, 1, 2, 0, 2, 3, 0, 3, 4, 0, 4, 5, 0, 5, 6, 0, 6, 7, 0, 7, 8, 0, 8, 1, // top
			9, 10, 11, 9, 11, 12, 9, 12, 13, 9, 13, 14, 9, 14, 15, 9, 15, 16, 9, 16, 17, 9, 17, 10, // bottom
			18, 19, 20, 18, 20, 21, // front
			22, 23, 24, 22, 24, 25, // right
			26, 27, 28, 26, 28, 29, // back
			30, 31, 32, 30, 32, 33, // back
	};

	VertexBufferObject *vbo;
    Texture *texture;

	void init() {
		vbo = new VertexBufferObject((GLubyte *) data, sizeof(data));
		texture = new Texture(0, 100, 100);
        initShaders();
	}

	void destroy() {
		delete vbo;
		delete texture;
        destroyShaders();
	}

	Cube::Cube() {
		setBuffer(*vbo, sizeof(Data));

        setShaderProgram(*Shaders::Shader_3D_POSITION_NORMAL_TEXCOORD_0);

        setArrayVAO(3, "POSITION", GL_FLOAT, (uint32_t) offsetof(Data, coor));
        setArrayVAO(3, "NORMAL", GL_FLOAT, (uint32_t) offsetof(Data, norm));
        setArrayVAO(2, "TEXCOORD_0", GL_FLOAT, (uint32_t) offsetof(Data, texCoor));

		setIndices(cubeIndices, sizeof(cubeIndices)/sizeof(*cubeIndices), GL_UNSIGNED_SHORT);

		setTexture(*Blob::GL::Shapes::texture);
	}

	Plane::Plane() {
		setBuffer(*vbo, sizeof(Data), 4 * 6 * sizeof(Data));

        setShaderProgram(*Shaders::Shader_3D_POSITION_NORMAL_TEXCOORD_0);

        setArrayVAO(3, "POSITION", GL_FLOAT, (uint32_t) offsetof(Data, coor));
        setArrayVAO(3, "NORMAL", GL_FLOAT, (uint32_t) offsetof(Data, norm));
        setArrayVAO(2, "TEXCOORD_0", GL_FLOAT, (uint32_t) offsetof(Data, texCoor));

		setIndices(planeIndices, sizeof(planeIndices)/sizeof(*planeIndices), GL_UNSIGNED_SHORT);

        setTexture(*Blob::GL::Shapes::texture);
	}

	OctagonalPrism::OctagonalPrism() {
		setBuffer(*vbo, sizeof(Data), (4 * 6 + 4) * sizeof(Data));

        setShaderProgram(*Shaders::Shader_3D_POSITION_NORMAL_TEXCOORD_0);

        setArrayVAO(3, "POSITION", GL_FLOAT, (uint32_t) offsetof(Data, coor));
        setArrayVAO(3, "NORMAL", GL_FLOAT, (uint32_t) offsetof(Data, norm));
        setArrayVAO(2, "TEXCOORD_0", GL_FLOAT, (uint32_t) offsetof(Data, texCoor));

		setIndices(octagonalPrismIndices, sizeof(octagonalPrismIndices)/sizeof(*octagonalPrismIndices), GL_UNSIGNED_SHORT);

        setTexture(*Blob::GL::Shapes::texture);
	}
}
#include <Blob/Shapes.hpp>
#include <glad/glad.h>

namespace Blob {
    using namespace GL;

    ShaderProgram *Shaders::Shader_2D_POSITION_TEXCOORD_0_COLOR_0;

    ShaderProgram *Shaders::Shader_3D_POSITION;
    ShaderProgram *Shaders::Shader_3D_POSITION_NORMAL;
    ShaderProgram *Shaders::Shader_3D_POSITION_NORMAL_TEXCOORD_0;

    Texture *Colors::maroon,
            *Colors::darkRed,
            *Colors::brown,
            *Colors::firebrick,
            *Colors::crimson,
            *Colors::red,
            *Colors::tomato,
            *Colors::coral,
            *Colors::indianRed,
            *Colors::lightCoral,
            *Colors::darkSalmon,
            *Colors::salmon,
            *Colors::lightSalmon,
            *Colors::orangeRed,
            *Colors::darkOrange,
            *Colors::orange,
            *Colors::gold,
            *Colors::darkGoldenRod,
            *Colors::goldenRod,
            *Colors::paleGoldenRod,
            *Colors::darkKhaki,
            *Colors::khaki,
            *Colors::olive,
            *Colors::yellow,
            *Colors::yellowGreen,
            *Colors::darkOliveGreen,
            *Colors::oliveDrab,
            *Colors::lawnGreen,
            *Colors::chartReuse,
            *Colors::greenYellow,
            *Colors::darkGreen,
            *Colors::green,
            *Colors::forestGreen,
            *Colors::lime,
            *Colors::limeGreen,
            *Colors::lightGreen,
            *Colors::paleGreen,
            *Colors::darkSeaGreen,
            *Colors::mediumSpringGreen,
            *Colors::springGreen,
            *Colors::seaGreen,
            *Colors::mediumAquaMarine,
            *Colors::mediumSeaGreen,
            *Colors::lightSeaGreen,
            *Colors::darkSlateGray,
            *Colors::teal,
            *Colors::darkCyan,
            *Colors::aqua,
            *Colors::cyan,
            *Colors::lightCyan,
            *Colors::darkTurquoise,
            *Colors::turquoise,
            *Colors::mediumTurquoise,
            *Colors::paleTurquoise,
            *Colors::aquaMarine,
            *Colors::powderBlue,
            *Colors::cadetBlue,
            *Colors::steelBlue,
            *Colors::cornFlowerBlue,
            *Colors::deepSkyBlue,
            *Colors::dodgerBlue,
            *Colors::lightBlue,
            *Colors::skyBlue,
            *Colors::lightSkyBlue,
            *Colors::midnightBlue,
            *Colors::navy,
            *Colors::darkBlue,
            *Colors::mediumBlue,
            *Colors::blue,
            *Colors::royalBlue,
            *Colors::blueViolet,
            *Colors::indigo,
            *Colors::darkSlateBlue,
            *Colors::slateBlue,
            *Colors::mediumSlateBlue,
            *Colors::mediumPurple,
            *Colors::darkMagenta,
            *Colors::darkViolet,
            *Colors::darkOrchid,
            *Colors::mediumOrchid,
            *Colors::purple,
            *Colors::thistle,
            *Colors::plum,
            *Colors::violet,
            *Colors::magenta,
            *Colors::orchid,
            *Colors::mediumVioletRed,
            *Colors::paleVioletRed,
            *Colors::deepPink,
            *Colors::hotPink,
            *Colors::lightPink,
            *Colors::pink,
            *Colors::antiqueWhite,
            *Colors::beige,
            *Colors::bisque,
            *Colors::blanchedAlmond,
            *Colors::wheat,
            *Colors::cornSilk,
            *Colors::lemonChiffon,
            *Colors::lightGoldenRodYellow,
            *Colors::lightYellow,
            *Colors::saddleBrown,
            *Colors::sienna,
            *Colors::chocolate,
            *Colors::peru,
            *Colors::sandyBrown,
            *Colors::burlyWood,
            *Colors::tan,
            *Colors::rosyBrown,
            *Colors::moccasin,
            *Colors::navajoWhite,
            *Colors::peachPuff,
            *Colors::mistyRose,
            *Colors::lavenderBlush,
            *Colors::linen,
            *Colors::oldLace,
            *Colors::papayaWhip,
            *Colors::seaShell,
            *Colors::mintCream,
            *Colors::slateGray,
            *Colors::lightSlateGray,
            *Colors::lightSteelBlue,
            *Colors::lavender,
            *Colors::floralWhite,
            *Colors::aliceBlue,
            *Colors::ghostWhite,
            *Colors::honeydew,
            *Colors::ivory,
            *Colors::azure,
            *Colors::snow,
            *Colors::black,
            *Colors::dimGrey,
            *Colors::grey,
            *Colors::darkGrey,
            *Colors::silver,
            *Colors::lightGrey,
            *Colors::gainsboro,
            *Colors::whiteSmoke,
            *Colors::white;

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

namespace Blob::Shapes {

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
    VertexArrayObject *vaoCube;
    VertexArrayObject *vaoPlane;
    VertexArrayObject *vaoOctagonalPrism;

    void init() {
        vbo = new VertexBufferObject((GLubyte *) data, sizeof(data));
        vaoCube = new VertexArrayObject();
        vaoCube->setBuffer(*vbo, sizeof(Data));
        vaoCube->setArray(
                3,
                Shaders::Shader_3D_POSITION_NORMAL_TEXCOORD_0->getAttribLocation("POSITION"),
                GL_FLOAT,
                (uint32_t) offsetof(Data, coor)
        );
        vaoCube->setArray(
                3,
                Shaders::Shader_3D_POSITION_NORMAL_TEXCOORD_0->getAttribLocation("NORMAL"),
                GL_FLOAT,
                (uint32_t) offsetof(Data, norm)
        );
        vaoCube->setArray(
                2,
                Shaders::Shader_3D_POSITION_NORMAL_TEXCOORD_0->getAttribLocation("TEXCOORD_0"),
                GL_FLOAT,
                (uint32_t) offsetof(Data, texCoor)
        );

        vaoPlane = new VertexArrayObject();
        vaoPlane->setBuffer(*vbo, sizeof(Data), 4 * 6 * sizeof(Data));
        vaoPlane->setArray(
                3,
                Shaders::Shader_3D_POSITION_NORMAL_TEXCOORD_0->getAttribLocation("POSITION"),
                GL_FLOAT,
                (uint32_t) offsetof(Data, coor)
        );
        vaoPlane->setArray(
                3,
                Shaders::Shader_3D_POSITION_NORMAL_TEXCOORD_0->getAttribLocation("NORMAL"),
                GL_FLOAT,
                (uint32_t) offsetof(Data, norm)
        );
        vaoPlane->setArray(
                2,
                Shaders::Shader_3D_POSITION_NORMAL_TEXCOORD_0->getAttribLocation("TEXCOORD_0"),
                GL_FLOAT,
                (uint32_t) offsetof(Data, texCoor)
        );

        vaoOctagonalPrism = new VertexArrayObject();
        vaoOctagonalPrism->setBuffer(*vbo, sizeof(Data), (4 * 6 + 4) * sizeof(Data));
        vaoOctagonalPrism->setArray(
                3,
                Shaders::Shader_3D_POSITION_NORMAL_TEXCOORD_0->getAttribLocation("POSITION"),
                GL_FLOAT,
                (uint32_t) offsetof(Data, coor)
        );
        vaoOctagonalPrism->setArray(
                3,
                Shaders::Shader_3D_POSITION_NORMAL_TEXCOORD_0->getAttribLocation("NORMAL"),
                GL_FLOAT,
                (uint32_t) offsetof(Data, norm)
        );
        vaoOctagonalPrism->setArray(
                2,
                Shaders::Shader_3D_POSITION_NORMAL_TEXCOORD_0->getAttribLocation("TEXCOORD_0"),
                GL_FLOAT,
                (uint32_t) offsetof(Data, texCoor)
        );

        initShaders();

        Colors::maroon = new Texture(128, 0, 0);
        Colors::darkRed = new Texture(139, 0, 0);
        Colors::brown = new Texture(165, 42, 42);
        Colors::firebrick = new Texture(178, 34, 34);
        Colors::crimson = new Texture(220, 20, 60);
        Colors::red = new Texture(255, 0, 0);
        Colors::tomato = new Texture(255, 99, 71);
        Colors::coral = new Texture(255, 127, 80);
        Colors::indianRed = new Texture(205, 92, 92);
        Colors::lightCoral = new Texture(240, 128, 128);
        Colors::darkSalmon = new Texture(233, 150, 122);
        Colors::salmon = new Texture(250, 128, 114);
        Colors::lightSalmon = new Texture(255, 160, 122);
        Colors::orangeRed = new Texture(255, 69, 0);
        Colors::darkOrange = new Texture(255, 140, 0);
        Colors::orange = new Texture(255, 165, 0);
        Colors::gold = new Texture(255, 215, 0);
        Colors::darkGoldenRod = new Texture(184, 134, 11);
        Colors::goldenRod = new Texture(218, 165, 32);
        Colors::paleGoldenRod = new Texture(238, 232, 170);
        Colors::darkKhaki = new Texture(189, 183, 107);
        Colors::khaki = new Texture(240, 230, 140);
        Colors::olive = new Texture(128, 128, 0);
        Colors::yellow = new Texture(255, 255, 0);
        Colors::yellowGreen = new Texture(154, 205, 50);
        Colors::darkOliveGreen = new Texture(85, 107, 47);
        Colors::oliveDrab = new Texture(107, 142, 35);
        Colors::lawnGreen = new Texture(124, 252, 0);
        Colors::chartReuse = new Texture(127, 255, 0);
        Colors::greenYellow = new Texture(173, 255, 47);
        Colors::darkGreen = new Texture(0, 100, 0);
        Colors::green = new Texture(0, 128, 0);
        Colors::forestGreen = new Texture(34, 139, 34);
        Colors::lime = new Texture(0, 255, 0);
        Colors::limeGreen = new Texture(50, 205, 50);
        Colors::lightGreen = new Texture(144, 238, 144);
        Colors::paleGreen = new Texture(152, 251, 152);
        Colors::darkSeaGreen = new Texture(143, 188, 143);
        Colors::mediumSpringGreen = new Texture(0, 250, 154);
        Colors::springGreen = new Texture(0, 255, 127);
        Colors::seaGreen = new Texture(46, 139, 87);
        Colors::mediumAquaMarine = new Texture(102, 205, 170);
        Colors::mediumSeaGreen = new Texture(60, 179, 113);
        Colors::lightSeaGreen = new Texture(32, 178, 170);
        Colors::darkSlateGray = new Texture(47, 79, 79);
        Colors::teal = new Texture(0, 128, 128);
        Colors::darkCyan = new Texture(0, 139, 139);
        Colors::aqua = new Texture(0, 255, 255);
        Colors::cyan = new Texture(0, 255, 255);
        Colors::lightCyan = new Texture(224, 255, 255);
        Colors::darkTurquoise = new Texture(0, 206, 209);
        Colors::turquoise = new Texture(64, 224, 208);
        Colors::mediumTurquoise = new Texture(72, 209, 204);
        Colors::paleTurquoise = new Texture(175, 238, 238);
        Colors::aquaMarine = new Texture(127, 255, 212);
        Colors::powderBlue = new Texture(176, 224, 230);
        Colors::cadetBlue = new Texture(95, 158, 160);
        Colors::steelBlue = new Texture(70, 130, 180);
        Colors::cornFlowerBlue = new Texture(100, 149, 237);
        Colors::deepSkyBlue = new Texture(0, 191, 255);
        Colors::dodgerBlue = new Texture(30, 144, 255);
        Colors::lightBlue = new Texture(173, 216, 230);
        Colors::skyBlue = new Texture(135, 206, 235);
        Colors::lightSkyBlue = new Texture(135, 206, 250);
        Colors::midnightBlue = new Texture(25, 25, 112);
        Colors::navy = new Texture(0, 0, 128);
        Colors::darkBlue = new Texture(0, 0, 139);
        Colors::mediumBlue = new Texture(0, 0, 205);
        Colors::blue = new Texture(0, 0, 255);
        Colors::royalBlue = new Texture(65, 105, 225);
        Colors::blueViolet = new Texture(138, 43, 226);
        Colors::indigo = new Texture(75, 0, 130);
        Colors::darkSlateBlue = new Texture(72, 61, 139);
        Colors::slateBlue = new Texture(106, 90, 205);
        Colors::mediumSlateBlue = new Texture(123, 104, 238);
        Colors::mediumPurple = new Texture(147, 112, 219);
        Colors::darkMagenta = new Texture(139, 0, 139);
        Colors::darkViolet = new Texture(148, 0, 211);
        Colors::darkOrchid = new Texture(153, 50, 204);
        Colors::mediumOrchid = new Texture(186, 85, 211);
        Colors::purple = new Texture(128, 0, 128);
        Colors::thistle = new Texture(216, 191, 216);
        Colors::plum = new Texture(221, 160, 221);
        Colors::violet = new Texture(238, 130, 238);
        Colors::magenta = new Texture(255, 0, 255);
        Colors::orchid = new Texture(218, 112, 214);
        Colors::mediumVioletRed = new Texture(199, 21, 133);
        Colors::paleVioletRed = new Texture(219, 112, 147);
        Colors::deepPink = new Texture(255, 20, 147);
        Colors::hotPink = new Texture(255, 105, 180);
        Colors::lightPink = new Texture(255, 182, 193);
        Colors::pink = new Texture(255, 192, 203);
        Colors::antiqueWhite = new Texture(250, 235, 215);
        Colors::beige = new Texture(245, 245, 220);
        Colors::bisque = new Texture(255, 228, 196);
        Colors::blanchedAlmond = new Texture(255, 235, 205);
        Colors::wheat = new Texture(245, 222, 179);
        Colors::cornSilk = new Texture(255, 248, 220);
        Colors::lemonChiffon = new Texture(255, 250, 205);
        Colors::lightGoldenRodYellow = new Texture(250, 250, 210);
        Colors::lightYellow = new Texture(255, 255, 224);
        Colors::saddleBrown = new Texture(139, 69, 19);
        Colors::sienna = new Texture(160, 82, 45);
        Colors::chocolate = new Texture(210, 105, 30);
        Colors::peru = new Texture(205, 133, 63);
        Colors::sandyBrown = new Texture(244, 164, 96);
        Colors::burlyWood = new Texture(222, 184, 135);
        Colors::tan = new Texture(210, 180, 140);
        Colors::rosyBrown = new Texture(188, 143, 143);
        Colors::moccasin = new Texture(255, 228, 181);
        Colors::navajoWhite = new Texture(255, 222, 173);
        Colors::peachPuff = new Texture(255, 218, 185);
        Colors::mistyRose = new Texture(255, 228, 225);
        Colors::lavenderBlush = new Texture(255, 240, 245);
        Colors::linen = new Texture(250, 240, 230);
        Colors::oldLace = new Texture(253, 245, 230);
        Colors::papayaWhip = new Texture(255, 239, 213);
        Colors::seaShell = new Texture(255, 245, 238);
        Colors::mintCream = new Texture(245, 255, 250);
        Colors::slateGray = new Texture(112, 128, 144);
        Colors::lightSlateGray = new Texture(119, 136, 153);
        Colors::lightSteelBlue = new Texture(176, 196, 222);
        Colors::lavender = new Texture(230, 230, 250);
        Colors::floralWhite = new Texture(255, 250, 240);
        Colors::aliceBlue = new Texture(240, 248, 255);
        Colors::ghostWhite = new Texture(248, 248, 255);
        Colors::honeydew = new Texture(240, 255, 240);
        Colors::ivory = new Texture(255, 255, 240);
        Colors::azure = new Texture(240, 255, 255);
        Colors::snow = new Texture(255, 250, 250);
        Colors::black = new Texture(0, 0, 0);
        Colors::dimGrey = new Texture(105, 105, 105);
        Colors::grey = new Texture(128, 128, 128);
        Colors::darkGrey = new Texture(169, 169, 169);
        Colors::silver = new Texture(192, 192, 192);
        Colors::lightGrey = new Texture(211, 211, 211);
        Colors::gainsboro = new Texture(220, 220, 220);
        Colors::whiteSmoke = new Texture(245, 245, 245);
        Colors::white = new Texture(255, 255, 255);
    }

    void destroy() {
        delete vbo;
        delete vaoCube;
        delete vaoPlane;
        delete vaoOctagonalPrism;

        destroyShaders();

        delete Colors::maroon;
        delete Colors::darkRed;
        delete Colors::brown;
        delete Colors::firebrick;
        delete Colors::crimson;
        delete Colors::red;
        delete Colors::tomato;
        delete Colors::coral;
        delete Colors::indianRed;
        delete Colors::lightCoral;
        delete Colors::darkSalmon;
        delete Colors::salmon;
        delete Colors::lightSalmon;
        delete Colors::orangeRed;
        delete Colors::darkOrange;
        delete Colors::orange;
        delete Colors::gold;
        delete Colors::darkGoldenRod;
        delete Colors::goldenRod;
        delete Colors::paleGoldenRod;
        delete Colors::darkKhaki;
        delete Colors::khaki;
        delete Colors::olive;
        delete Colors::yellow;
        delete Colors::yellowGreen;
        delete Colors::darkOliveGreen;
        delete Colors::oliveDrab;
        delete Colors::lawnGreen;
        delete Colors::chartReuse;
        delete Colors::greenYellow;
        delete Colors::darkGreen;
        delete Colors::green;
        delete Colors::forestGreen;
        delete Colors::lime;
        delete Colors::limeGreen;
        delete Colors::lightGreen;
        delete Colors::paleGreen;
        delete Colors::darkSeaGreen;
        delete Colors::mediumSpringGreen;
        delete Colors::springGreen;
        delete Colors::seaGreen;
        delete Colors::mediumAquaMarine;
        delete Colors::mediumSeaGreen;
        delete Colors::lightSeaGreen;
        delete Colors::darkSlateGray;
        delete Colors::teal;
        delete Colors::darkCyan;
        delete Colors::aqua;
        delete Colors::cyan;
        delete Colors::lightCyan;
        delete Colors::darkTurquoise;
        delete Colors::turquoise;
        delete Colors::mediumTurquoise;
        delete Colors::paleTurquoise;
        delete Colors::aquaMarine;
        delete Colors::powderBlue;
        delete Colors::cadetBlue;
        delete Colors::steelBlue;
        delete Colors::cornFlowerBlue;
        delete Colors::deepSkyBlue;
        delete Colors::dodgerBlue;
        delete Colors::lightBlue;
        delete Colors::skyBlue;
        delete Colors::lightSkyBlue;
        delete Colors::midnightBlue;
        delete Colors::navy;
        delete Colors::darkBlue;
        delete Colors::mediumBlue;
        delete Colors::blue;
        delete Colors::royalBlue;
        delete Colors::blueViolet;
        delete Colors::indigo;
        delete Colors::darkSlateBlue;
        delete Colors::slateBlue;
        delete Colors::mediumSlateBlue;
        delete Colors::mediumPurple;
        delete Colors::darkMagenta;
        delete Colors::darkViolet;
        delete Colors::darkOrchid;
        delete Colors::mediumOrchid;
        delete Colors::purple;
        delete Colors::thistle;
        delete Colors::plum;
        delete Colors::violet;
        delete Colors::magenta;
        delete Colors::orchid;
        delete Colors::mediumVioletRed;
        delete Colors::paleVioletRed;
        delete Colors::deepPink;
        delete Colors::hotPink;
        delete Colors::lightPink;
        delete Colors::pink;
        delete Colors::antiqueWhite;
        delete Colors::beige;
        delete Colors::bisque;
        delete Colors::blanchedAlmond;
        delete Colors::wheat;
        delete Colors::cornSilk;
        delete Colors::lemonChiffon;
        delete Colors::lightGoldenRodYellow;
        delete Colors::lightYellow;
        delete Colors::saddleBrown;
        delete Colors::sienna;
        delete Colors::chocolate;
        delete Colors::peru;
        delete Colors::sandyBrown;
        delete Colors::burlyWood;
        delete Colors::tan;
        delete Colors::rosyBrown;
        delete Colors::moccasin;
        delete Colors::navajoWhite;
        delete Colors::peachPuff;
        delete Colors::mistyRose;
        delete Colors::lavenderBlush;
        delete Colors::linen;
        delete Colors::oldLace;
        delete Colors::papayaWhip;
        delete Colors::seaShell;
        delete Colors::mintCream;
        delete Colors::slateGray;
        delete Colors::lightSlateGray;
        delete Colors::lightSteelBlue;
        delete Colors::lavender;
        delete Colors::floralWhite;
        delete Colors::aliceBlue;
        delete Colors::ghostWhite;
        delete Colors::honeydew;
        delete Colors::ivory;
        delete Colors::azure;
        delete Colors::snow;
        delete Colors::black;
        delete Colors::dimGrey;
        delete Colors::grey;
        delete Colors::darkGrey;
        delete Colors::silver;
        delete Colors::lightGrey;
        delete Colors::gainsboro;
        delete Colors::whiteSmoke;
        delete Colors::white;
    }

    Cube::Cube() : Renderable(*vaoCube, *Shaders::Shader_3D_POSITION_NORMAL_TEXCOORD_0, *Colors::teal){

        setIndices(cubeIndices, sizeof(cubeIndices) / sizeof(*cubeIndices), GL_UNSIGNED_SHORT);

        setTexture(*Colors::teal);
    }

    Plane::Plane() : Renderable(*vaoCube, *Shaders::Shader_3D_POSITION_NORMAL_TEXCOORD_0, *Colors::teal){

        setIndices(planeIndices, sizeof(planeIndices) / sizeof(*planeIndices), GL_UNSIGNED_SHORT);
    }

    OctagonalPrism::OctagonalPrism() : Renderable(*vaoCube, *Shaders::Shader_3D_POSITION_NORMAL_TEXCOORD_0, *Colors::teal){

        setIndices(octagonalPrismIndices, sizeof(octagonalPrismIndices) / sizeof(*octagonalPrismIndices),
                   GL_UNSIGNED_SHORT);
    }
}
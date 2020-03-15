#include <Blob/Material.hpp>

namespace Blob{
using namespace GL;
void Shaders::initShaders() {
    ShaderProgram *Shaders::Shader_2D_POSITION_TEXCOORD_0_COLOR_0;

    ShaderProgram *Shaders::Shader_3D_POSITION;
    ShaderProgram *Shaders::Shader_3D_POSITION_NORMAL;
    ShaderProgram *Shaders::Shader_3D_POSITION_NORMAL_TEXCOORD_0;

    std::cout << "init Shaders" << std::endl;

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
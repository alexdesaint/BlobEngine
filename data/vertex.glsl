#version 450

layout (location = 0) in vec3 Position;
layout (location = 1) in vec3 Normal;
layout (location = 2) in vec2 TexturePosition;

out vec3 FragPos;
out vec3 FragNormal;
out vec2 TexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    FragPos = vec3(model * vec4(Position, 1.0));
    FragNormal = mat3(transpose(inverse(model))) * Normal;

    gl_Position = projection * view * vec4(FragPos, 1.0);

    TexCoord = TexturePosition;
}

#version 450

/*layout (location = 0) in vec2 aPos;

layout (location = 2) in vec2 aTexCoord;

out vec2 TexCoord;

uniform mat4 model;

void main() {
    TexCoord = aTexCoord;

    gl_Position = model * vec4(aPos.x, aPos.y, 0.0, 1.0);
}*/

layout (location = 0) in vec2 Position;
layout (location = 1) in vec2 TexturePosition;
layout (location = 2) in vec4 Color;

uniform mat4 projection;
out vec2 Frag_UV;
out vec4 Frag_Color;

void main()
{
    Frag_UV = TexturePosition;
    Frag_Color = Color;
    gl_Position = projection * vec4(Position.xy, 0, 1);
}
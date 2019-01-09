#version 450

layout (location = 0) in vec2 aPos;

layout (location = 2) in vec2 aTexCoord;

out vec2 TexCoord;

void main() {
    TexCoord = aTexCoord;

    gl_Position = vec4(aPos.x, aPos.y, 0.0, 1.0);
}
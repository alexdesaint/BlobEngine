#version 450
layout(location = 0) in vec3 POSITION;
layout(location = 1) in vec3 NORMAL;

layout(location = 2) out vec3 normal;

void main() {
    normal = NORMAL;
    gl_Position =  vec4(POSITION, 1.0);
}

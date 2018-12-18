#version 450

layout(location = 0) in vec3 vertex_position;
layout(location = 1) in vec3 aNormal;
uniform mat4 mvp;
out float dist;

void main() {
	gl_Position = mvp * vec4 (vertex_position, 1.0);
	dist = vertex_position.z;//1.0 - (-pos_eye.z / 10.0);
}

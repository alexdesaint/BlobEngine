#version 450

layout(triangles) in;
layout(triangle_strip, max_vertices = 3) out;

layout(location = 0) uniform mat4 model;
layout(location = 0) out vec3 position;
layout(location = 2) out vec3 normal;

layout(location = 1) uniform mat4 view;
layout(location = 2) uniform mat4 projection;

void main() {
    vec3 a = (gl_in[1].gl_Position - gl_in[0].gl_Position).xyz;
    vec3 b = (gl_in[2].gl_Position - gl_in[0].gl_Position).xyz;
    vec3 N = normalize(mat3(transpose(inverse(model))) * cross(b, a));

    for (int i = 0; i < gl_in.length(); ++i) {
        position = gl_in[i].gl_Position.xyz;
        gl_Position = projection * view * model * gl_in[i].gl_Position;
        normal = N;
        EmitVertex();
    }

    EndPrimitive();
}
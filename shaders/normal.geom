#version 450
layout(triangles) in;
layout(line_strip, max_vertices=2) out;

layout(location = 2) in vec3 NORMAL[];

layout(location = 0) uniform mat4 model;
layout(location = 1) uniform mat4 view;
layout(location = 2) uniform mat4 projection;
layout(location = 4) uniform float length;

void main()
{
    vec4 P = vec4(0);
    vec3 N = vec3(0);

    for(int i=0; i<gl_in.length(); i++) {
        P += gl_in[i].gl_Position;
        N += NORMAL[i];
    }
    P /= gl_in.length();
    N /= gl_in.length();

    gl_Position = projection * view * model * P;
    EmitVertex();

    gl_Position = projection * view * model * (P + vec4(N, 0) * length);
    EmitVertex();

    EndPrimitive();
}

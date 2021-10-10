#version 450
#define PI 3.1415926535897932384626433832795

layout(location = 0) in vec3 POSITION;

layout(location = 0) out vec3 position;

layout(location = 12) uniform float timeStep;

void main() {
    vec4 p = vec4(POSITION, 1.0);
    p.z = p.z/5;
    p.z += cos(p.x * PI + timeStep) * sin(p.y * PI + timeStep)/4;
    gl_Position =  p;
}

#version 450
layout(location = 0) in vec3 POSITION;
layout(location = 1) in vec3 NORMAL;
layout(location = 2) in vec3 TANGENT;
layout(location = 3) in vec2 TEXCOORD_0;
layout(location = 4) in vec2 TEXCOORD_1;
layout(location = 5) in vec3 COLOR_0;
layout(location = 6) in vec3 JOINTS_0;
layout(location = 7) in vec3 WEIGHTS_0;

layout(location = 8) in mat4 InstancedModel;
layout(location = 9) in vec3 InstancedColor;

layout(location = 0) out vec3 position;
layout(location = 1) out vec2 texCoord;
layout(location = 2) out vec2 texCoord1;
layout(location = 3) out vec3 normal;
layout(location = 4) out vec3 tangent;
layout(location = 5) out vec3 binormal;
layout(location = 6) out vec3 color;

layout(location = 0) uniform mat4 model;
layout(location = 1) uniform mat4 view;
layout(location = 2) uniform mat4 projection;

void mainNonInstanced() {
    position = vec3(model * vec4(POSITION, 1.0));
    texCoord = TEXCOORD_0;
    texCoord1 = TEXCOORD_1;
    normal = normalize(mat3(transpose(inverse(model))) * NORMAL);
    tangent = TANGENT;
    binormal = cross(NORMAL, TANGENT);
    color = COLOR_0;

    gl_Position = projection * view * model * vec4(POSITION, 1.0);
}

void mainInstanced() {
    position = vec3(InstancedModel * vec4(POSITION, 1.0));
    texCoord = TEXCOORD_0;
    texCoord1 = TEXCOORD_1;
    normal = normalize(mat3(transpose(inverse(InstancedModel))) * NORMAL);
    tangent = TANGENT;
    binormal = cross(NORMAL, TANGENT);
    color = COLOR_0;

    gl_Position = projection * view * InstancedModel * vec4(POSITION, 1.0);
}

void mainInstancedColor() {
    position = vec3(InstancedModel * vec4(POSITION, 1.0));
    texCoord = TEXCOORD_0;
    texCoord1 = TEXCOORD_1;
    normal = normalize(mat3(transpose(inverse(InstancedModel))) * NORMAL);
    tangent = TANGENT;
    binormal = cross(NORMAL, TANGENT);
    color = InstancedColor;

    gl_Position = projection * view * InstancedModel * vec4(POSITION, 1.0);
}

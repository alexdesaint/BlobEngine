#version 450

out vec4 FragColor;

in vec3 FragNormal;
in vec3 FragPos;
in vec2 TexCoord;

uniform sampler2D ourTexture;

void main()
{
    vec3 lightPos = vec3(4.0, 4.0, 0.0);
    vec3 lightColor = vec3(1.0, 1.0, 1.0);
    vec4 objectColor = texture(ourTexture, TexCoord);
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
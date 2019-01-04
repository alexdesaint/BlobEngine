#version 450

out vec4 FragColor;

in vec3 Normal;
in vec3 FragPos;
in vec2 TexCoord;

uniform sampler2D ourTexture;

void main()
{
    vec3 lightPos = vec3(4.0, 4.0, 0.0);
    vec4 lightColor = vec4(1.0, 1.0, 1.0, 1.0);
    vec4 objectColor;
    //if(TexCoord.x == -1.0 && TexCoord.y == -1.0)
    objectColor = vec4(0.0, 0.4, 0.4, 0.5);
    //else
    //    objectColor = texture(ourTexture, TexCoord);


    //
    float ambientStrength = 0.2;
    vec4 ambient = ambientStrength * lightColor;

    // diffuse
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(vec3(1.0, -1.0, 2.0));
    float diff = max(dot(norm, lightDir), 0.0);
    vec4 diffuse = diff * lightColor;

    FragColor = (ambient + diffuse) * objectColor;

}
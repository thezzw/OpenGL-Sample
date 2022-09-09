#version 330 core
out vec4 FragColor;

struct PointLight {
    vec3 Position;
    vec3 Color;
};

#define NR_POINT_LIGHTS 4

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoords;

uniform sampler2D box;
uniform vec3 viewPos;
uniform bool inverse_normals;
uniform PointLight pointLights[NR_POINT_LIGHTS];

vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir);

void main()
{
    vec3 norm = normalize(Normal);
    if(inverse_normals) norm = -norm;
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 result = vec3(0);
    for(int i = 0; i < NR_POINT_LIGHTS; i++)
        result += CalcPointLight(pointLights[i], norm, FragPos, viewDir);

    FragColor = vec4(result, 1.0f);
}

vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
    vec3 lightDir = normalize(light.Position - fragPos);

    float diff = max(dot(normal, lightDir), 0.0);

    vec3 ambient = light.Color * vec3(texture(box, TexCoords));
    vec3 diffuse = light.Color * diff * vec3(texture(box, TexCoords));
    return (ambient + diffuse);
}
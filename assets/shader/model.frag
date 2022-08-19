#version 330 core
#define NR_POINT_LIGHTS 2
struct DirLight 
{
    vec3 direction;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};
struct PointLight {
    vec3 position;

    float constant;
    float linear;
    float quadratic;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

in vec3 FragPos;
in vec2 TexCoords;

uniform sampler2D texture_diffuse1;
uniform sampler2D texture_specular1;
uniform sampler2D texture_normal1;
uniform vec3 viewPos;
uniform DirLight dirLight;
uniform PointLight pointLights[NR_POINT_LIGHTS];

out vec4 FragColor;

vec3 CalcDirLight(DirLight light, vec4 diffuse, vec4 specular, vec4 normal, vec3 viewDir);
vec3 CalcPointLight(PointLight light, vec4 diffuse, vec4 specular, vec4 normal, vec3 fragPos, vec3 viewDir);

void main()
{
    vec3 viewDir = normalize(viewPos - FragPos);

	vec4 diffuse = texture(texture_diffuse1, TexCoords);
	vec4 specular = texture(texture_specular1, TexCoords);
	vec4 normal = vec4(normalize(texture(texture_normal1, TexCoords).rgb * 2.0 - 1.0), 1.0);

    vec3 result = CalcDirLight(dirLight, diffuse, specular, normal, viewDir);
    for(int i = 0; i < NR_POINT_LIGHTS; i++)
        result += CalcPointLight(pointLights[i], diffuse, specular, normal, FragPos, viewDir); 
    
	FragColor = vec4(result, 1.0);
}

vec3 CalcDirLight(DirLight light, vec4 diffuse, vec4 specular, vec4 normal, vec3 viewDir)
{
    vec3 diffuse3 = vec3(diffuse);
    vec3 specular3 = vec3(specular);
    vec3 normal3 = vec3(normal);
    vec3 lightDir = normalize(-light.direction);

    float diff = max(dot(vec3(normal), lightDir), 0.0);
    vec3 reflectDir = reflect(-lightDir, normal3);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 16);

    vec3 ambientResult = light.ambient * diffuse3;
    vec3 diffuseResult = light.diffuse * diff * diffuse3;
    vec3 specularResult = light.specular * spec * specular3;

    return (ambientResult + diffuseResult + specularResult);
}

vec3 CalcPointLight(PointLight light, vec4 diffuse, vec4 specular, vec4 normal, vec3 fragPos, vec3 viewDir)
{
    vec3 diffuse3 = vec3(diffuse);
    vec3 specular3 = vec3(specular);
    vec3 normal3 = vec3(normal);
    vec3 lightDir = normalize(light.position - fragPos);

    float diff = max(dot(normal3, lightDir), 0.0);

    vec3 reflectDir = reflect(-lightDir, normal3);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 16);

    float distance    = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));    

    vec3 ambientResult  = light.ambient  * diffuse3;
    vec3 diffuseResult  = light.diffuse  * diff * diffuse3;
    vec3 specularResult = light.specular * spec * specular3;
    ambientResult  *= attenuation;
    diffuseResult  *= attenuation;
    specularResult *= attenuation;
    return (ambientResult + diffuseResult + specularResult);
}
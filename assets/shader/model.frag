#version 330 core
struct DirLight 
{
    vec3 direction;

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

out vec4 FragColor;

vec3 CalcDirLight(DirLight dirLight, vec4 diffuse, vec4 specular, vec4 normal, vec3 viewDir);

void main()
{
    vec3 viewDir = normalize(viewPos - FragPos);

	vec4 diffuse = texture(texture_diffuse1, TexCoords);
	vec4 specular = texture(texture_specular1, TexCoords);
	vec4 normal = normalize(texture(texture_normal1, TexCoords));

    vec3 result = CalcDirLight(dirLight, diffuse, specular, normal, viewDir);
    
	FragColor = vec4(result, 1.0);
}

vec3 CalcDirLight(DirLight dirLight, vec4 diffuse, vec4 specular, vec4 normal, vec3 viewDir)
{
    vec3 diffuse3 = vec3(diffuse);
    vec3 specular3 = vec3(specular);
    vec3 normal3 = vec3(normal);
    vec3 lightDir = normalize(-dirLight.direction);

    float diff = max(dot(vec3(normal), lightDir), 0.0);
    vec3 reflectDir = reflect(-lightDir, normal3);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 16);

    vec3 ambientResult = dirLight.ambient * diffuse3;
    vec3 diffuseResult = dirLight.diffuse * diff * diffuse3;
    vec3 specularResult = dirLight.specular * spec * specular3;

    return (ambientResult + diffuseResult + specularResult);
}
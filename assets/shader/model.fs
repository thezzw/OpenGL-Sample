#version 330 core
out vec4 FragColor;

in vec2 TexCoords;

uniform sampler2D texture_diffuse1;
uniform sampler2D texture_specular1;
uniform sampler2D texture_normal1;

void main()
{    
	vec4 diffuse = texture(texture_diffuse1, TexCoords);
	vec4 specular = texture(texture_specular1, TexCoords);
	vec4 normal = texture(texture_normal1, TexCoords);
    
	FragColor = diffuse + specular;
}
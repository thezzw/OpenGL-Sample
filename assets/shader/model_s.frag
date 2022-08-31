#version 330 core

in vec2 TexCoords;

uniform sampler2D texture_diffuse1;
uniform sampler2D texture_specular1;
uniform sampler2D texture_normal1;
uniform vec3 color;

out vec4 FragColor;

void main()
{
	vec4 diffuse = texture(texture_diffuse1, TexCoords);
	vec4 specular = texture(texture_specular1, TexCoords);
	vec4 normal = vec4(normalize(texture(texture_normal1, TexCoords).rgb * 2.0 - 1.0), 1.0);
    
	// FragColor = diffuse + specular;
	FragColor = vec4(0.7, 0.3, 0.3, 1.0);
	// FragColor = vec4(vec3(0.20f / (100.1f - (gl_FragCoord.z * 2.0 - 1.0) * (99.9f))), 1.0f);
}
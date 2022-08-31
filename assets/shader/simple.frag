#version 330 core

in vec2 TexCoords;

uniform sampler2D texture1;

out vec4 FragColor;

void main()
{
	vec4 diffuse = texture(texture1, TexCoords);

	// if(diffuse.a < 0.1)
	// 	discard;
    
	FragColor = diffuse;
}
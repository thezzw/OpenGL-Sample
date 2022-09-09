#version 330 core
out vec4 FragColor;

in vec2 TexCoords;

uniform sampler2D screenTexture;

const float offset = 1.0 / 300.0; 
void main()
{
    vec3 col = texture(screenTexture, TexCoords).rgb;

    // Reinhard
    // vec3 mapped = col / (col + vec3(1.0));

    float exposure = 0.1;
    vec3 mapped = vec3(1.0) - exp(-col * exposure);

    FragColor = vec4(mapped, 1.0);
}
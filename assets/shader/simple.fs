#version 330 core
out vec4 FragColor;

in vec2 TexCoord;

uniform sampler2D texture_0;
uniform sampler2D texture_1;

uniform float mixValue;
uniform float sinTimeValue;

void main()
{
    FragColor = mix(texture(texture_0, TexCoord * 0.5f), texture(texture_1, TexCoord * sinTimeValue), mixValue);
}
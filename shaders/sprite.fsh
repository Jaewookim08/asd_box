#version 330 core
out vec4 FragColor;

in vec2 vTexCoord;

uniform sampler2D drawingTexture;
uniform vec4 color;

void main()
{
    FragColor = texture(drawingTexture, vTexCoord) * color;
}
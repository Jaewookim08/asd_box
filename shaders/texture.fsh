#version 330 core
out vec4 FragColor;

in vec2 TexCoord;

uniform sampler2D drawingTexture;
uniform vec4 color;

void main()
{
    FragColor = texture(drawingTexture, TexCoord) * color;
}
#version 330 core
out vec4 FragColor;

in vec2 vTexCoord;
in vec3 vLocalPosition;

uniform sampler2D drawingTexture;
uniform vec4 color;
uniform float uStripeWhiteWidth;
uniform float uStripeBlackWidth;
uniform vec3 uStartPosition;
uniform vec3 uNormalizedStripeDirection;

void main()
{
    vec4 col = texture(drawingTexture, vTexCoord) * color;
    float distance = dot((vLocalPosition - uStartPosition), uNormalizedStripeDirection);
    bool isOnStripeWhite = mod(distance, (uStripeBlackWidth + uStripeWhiteWidth)) < uStripeWhiteWidth;
    col = col * vec4(1, 1, 1, isOnStripeWhite);
    FragColor = col;
}
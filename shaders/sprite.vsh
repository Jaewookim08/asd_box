#version 330 core
layout (location = 0) in vec3 aPosition;
layout (location = 1) in vec2 aTexCoord;

uniform mat4 uProjectionMatrix;
uniform mat4 uModelViewMatrix;

uniform vec2 uSpriteSize;

out vec2 vTexCoord;

void main()
{
    vTexCoord = aTexCoord;

    vec4 eye_pos =  uProjectionMatrix * uModelViewMatrix * vec4(aPosition * vec3(uSpriteSize, 1), 1.0);

    gl_Position = eye_pos;
}
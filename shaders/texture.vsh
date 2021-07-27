#version 330 core
layout (location = 0) in vec3 aPosition;
layout (location = 1) in vec2 aTexCoord;

uniform mat4 uProjectionMatrix;
uniform mat4 uModelViewMatrix;

out vec2 vTexCoord;

void main()
{
    vTexCoord = aTexCoord;

    vec4 eye_pos =  uProjectionMatrix * uModelViewMatrix * vec4(aPosition, 1.0);

    gl_Position = eye_pos;
}
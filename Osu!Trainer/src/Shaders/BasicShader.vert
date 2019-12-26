#version 460 core
layout(location = 0) in vec4 position;

out vec2 vTexCoord;

uniform mat4 proj;
uniform mat4 view;

void main()
{
	gl_Position = proj * view * position;
}
#version 460 core

uniform mat4 proj;
uniform mat4 view;

layout(location = 0) in vec4 vertex;
layout(location = 1) in vec2 value;

out vec2 val;

void main()
{
	gl_Position = proj * view * vertex;
	val = value;
}
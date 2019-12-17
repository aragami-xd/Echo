#version 460 core

uniform mat4 proj;
uniform mat4 view;

layout(location = 0) in vec4 circleVertex;
layout(location = 1) in vec2 circleValue;
layout(location = 2) in vec4 ringVertex;
layout(location = 3) in vec2 ringValue;

out vec2 val;

void main()
{
	val = circleValue;
	gl_Position = proj * view * circleVertex;

	val = ringValue;
	gl_Position = proj * view * ringVertex;
}
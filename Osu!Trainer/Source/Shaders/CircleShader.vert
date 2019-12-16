#version 460 core

uniform mat4 view_matrix;
uniform mat4 proj_matrix;

layout(location = 0) in vec4 vertex;
layout(location = 1) in vec2 value;

out vec2 val;

void main()
{
	// nothing exciting here
	val = value;
	gl_Position = proj_matrix * view_matrix * vertex;
}
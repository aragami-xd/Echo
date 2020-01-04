#version 460 core
layout(location = 0) in vec4 position;

uniform mat4 view = mat4(1.0);
uniform mat4 proj = mat4(1.0);

void main()
{
	gl_Position = proj * view * position;
}
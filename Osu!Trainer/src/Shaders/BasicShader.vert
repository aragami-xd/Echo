#version 460 core
layout(location = 0) in vec4 position;
layout(location = 1) in vec2 texCoord;

out vec2 vTexCoord;

uniform mat4 u_mvp;

void main()
{
	gl_Position = u_mvp * position;
	vTexCoord = texCoord;
}
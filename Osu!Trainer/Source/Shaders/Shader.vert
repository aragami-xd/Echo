#version 460 core
layout(location = 0) in vec4 position;
layout(location = 1) in vec2 texCoord;

out vec2 vTexCoord;

void main()
{
	gl_Position = position;
	vTexCoord = texCoord;
}
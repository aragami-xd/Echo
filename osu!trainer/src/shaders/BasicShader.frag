#version 460 core
layout(location = 0) out vec4 color;

uniform vec4 uColor = vec4(1.0);

void main()
{
	color = uColor;
}
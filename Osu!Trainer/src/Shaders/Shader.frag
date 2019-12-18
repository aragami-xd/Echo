#version 460 core
layout(location = 0) out vec4 color;
in vec2 vTexCoord;

uniform vec4 uColor;
uniform sampler2D vTexture;

void main()
{
	vec4 texColor = texture(vTexture, vTexCoord);
	color = uColor;
}
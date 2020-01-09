#version 460 core
layout(location = 0) out vec4 color;
in vec2 texCoord;

uniform vec4 uColor = vec4(1.0,1.0,1.0,0.0);
uniform sampler2D uTexture;

void main()
{
	color = uColor * texture(uTexture, texCoord);
}
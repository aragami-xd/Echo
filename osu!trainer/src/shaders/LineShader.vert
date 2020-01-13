#version 460 core
layout(location = 0) in vec4 position;
uniform vec2 viewport;

uniform mat4 model = mat4(1.0);
uniform mat4 view = mat4(1.0);
uniform mat4 proj = mat4(1.0);

out vec2 linePos;

void main()
{
	vec4 pos = proj * view * model * position;

	gl_Position = pos;
	linePos = pos.xy;
}
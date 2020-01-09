#version 460 core
layout(location = 0) in vec4 position;
layout(location = 1) in vec2 texPosition;

uniform mat4 model = mat4(1.0);
uniform mat4 view = mat4(1.0);
uniform mat4 proj = mat4(1.0);

out vec2 texCoord;

void main()
{
	gl_Position = proj * view * model * position;
	texCoord = texPosition;
}
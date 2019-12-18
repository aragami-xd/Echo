#version 460 core

layout(location = 0) out vec4 color_output;
in vec2 val;

uniform float borderThickness = 0.05;

void main()
{
	float R1 = 1.0;
	float R2 = R1 - borderThickness;
	vec4 color = vec4(1.0, 1.0, 1.0, 1.0);

	// determine the color filling space
	// if distant is outside of range then that point is not on the circle, so discard that shader
	float dist = sqrt(dot(val, val));
	if (dist >= R1 || dist <= R2)
		{ discard; }
	
	// fxaa
	float sm1 = smoothstep(R1, R1-0.02, dist);
	float sm2 = smoothstep(R2, R2+0.02, dist);
	float alpha = sm1 * sm2 * color.a;

	// color
	color_output = vec4(color.r, color.g, color.b, alpha);
}
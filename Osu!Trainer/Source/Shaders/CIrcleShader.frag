#version 460 core

in vec2 val;

uniform vec4 color;
uniform float R1;
uniform float R2;

void main()
{
	// determine the color filling space
	// if distant is outside of range then that point is not on the circle, so discard that shader
	float dist = sqrt(dot(val, val));
	if (dist > R1 || dist < R2)
		{ discard; }
	
	// fxaa
	float sm1 = smoothstep(R1, R1-0.01, dist);
	float sm2 = smoothstep(R2, R2+0.01, dist);
	float alpha = sm1 * sm2 * color.w;

	// color
	gl_FragColor = vec4(color.r, color.g, color.b, alpha);
}
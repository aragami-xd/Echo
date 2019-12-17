#version 460 core

layout(location = 0) out vec4 color_output;

in vec2 val;

void main()
{
	float circleR1 = 1.0;
	float circleR2 = 0.95;
	float circleR3 = 0.85;
	float ringR1 = 1.0;
	float ringR2 = 0.97;

	vec4 borderColor = vec4(1.0, 1.0, 1.0, 1.0);
	vec4 accentColor = vec4(0.8, 0.9, 1.0, 1.0);

	// distance to the center
	float dist = sqrt(dot(val, val));

	/* determine which color to fill */
	// circle border
	if (dist < circleR1 && dist > circleR2)
	{ 
		float sm1 = smoothstep(circleR1, circleR1-0.02, dist);
		float sm2 = smoothstep(circleR2, circleR2+0.02, dist);
		float alpha = sm1 * sm2 * borderColor.a;
		color_output = vec4(borderColor.r, borderColor.g, borderColor.b, alpha);

	}
	// circle accentColor
	else if (dist > circleR3 && dist < circleR2)
	{
		float sm1 = smoothstep(circleR2, circleR2-0.02, dist);
		float sm2 = smoothstep(circleR3, circleR3+0.02, dist);
		float alpha = sm1 * sm2 * accentColor.a;
		color_output = vec4(accentColor.r, accentColor.g, accentColor.b, alpha);
	}
	// ring
	else if (dist > ringR2 && dist < ringR1)
	{
		float sm1 = smoothstep(ringR1, ringR1-0.02, dist);
		float sm2 = smoothstep(ringR2, ringR2+0.02, dist);
		float alpha = sm1 * sm2 * borderColor.a;
		color_output = vec4(borderColor.r, borderColor.g, borderColor.b, alpha);
	}
	// else, discard
	else
	{
		discard;
	}
}
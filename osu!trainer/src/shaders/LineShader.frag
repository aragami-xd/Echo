#version 460 core
layout(location = 0) out vec4 color;
in vec2 linePos;

uniform vec4 uColor = vec4(1.0);
uniform float blend = 2.0;
uniform float lineThickness = 5.0;

void main()
{
	float alpha = uColor.a;
	float dist = length(linePos - gl_FragCoord.xy);

	vec4 col = vec4(1.0);
	col.r = linePos.x - gl_FragCoord.x;
	col.g = linePos.y - gl_FragCoord.y; 

//	if (dist > lineThickness)
//		discard;
//	else
		alpha *= pow((float(lineThickness - dist) / lineThickness), blend);

	color = vec4(uColor.r, uColor.g, uColor.b, alpha);
//	color = col;
}
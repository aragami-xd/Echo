#pragma once

/* color for opengl vec4 */

// color struct, default to white
struct Color
{
	Color(float r = 1.0f, float g = 1.0f, float b = 1.0f, float a = 1.0f) :
		R(r), G(g), B(b), A(a) {}
	float R;
	float G;
	float B;
	float A;
};

// some predefinied color (mostly bright colors as the game background is dark)
// color pallete from colorhexa.com
#define COLOR_WHITE Color(1.0f, 1.0f, 1.0f, 1.0f)
#define COLOR_LIGHT_BLUE Color(0.68f, 0.85f, 0.9f, 1.0f)
#define COLOR_LIGHT_GREEN Color(0.68f, 1.0f, 0.18f, 1.0f)
#define COLOR_RED Color(1.0f, 0.0f, 0.0f, 0.0f)
#define COLOR_YELLOW Color(1.0f, 1.0f, 0.0f, 0.0f)
#define COLOR_LIGHT_YELLOW (1.0f, 1.0f, 0.88f, 0.0f)

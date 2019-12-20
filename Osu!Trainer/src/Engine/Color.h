#pragma once
#include <glm/glm.hpp>

// color struct, default to white
struct Color
{
	Color(float R = 1.0f, float G = 1.0f, float B = 1.0f, float A = 1.0f) :
		r(R), g(G), b(B), a(A), rgba(R,G,B,A), rgb(R,G,B) 
	{}
	// color options
	glm::vec4 rgba;
	glm::vec3 rgb;
	float r;
	float g;
	float b;
	float a;
};

// some predefinied color (mostly bright colors as the game background is dark)
// color pallete from colorhexa.com
#define COLOR_WHITE Color(1.0f, 1.0f, 1.0f, 1.0f)
#define COLOR_LIGHT_BLUE Color(0.68f, 0.85f, 0.9f, 1.0f)
#define COLOR_LIGHT_GREEN Color(0.68f, 1.0f, 0.18f, 1.0f)
#define COLOR_RED Color(1.0f, 0.0f, 0.0f, 0.0f)
#define COLOR_YELLOW Color(1.0f, 1.0f, 0.0f, 0.0f)
#define COLOR_LIGHT_YELLOW (1.0f, 1.0f, 0.88f, 0.0f)

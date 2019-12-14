#pragma once

#include "../Engine/Color.h"

class CircleRenderer
{
private:
	static void DrawRing(float* ring);
	static void DrawInCircle(float* circle);

public:
	static void DrawCircle(float* circle, float* ring, bool renderRing, Color color);
};

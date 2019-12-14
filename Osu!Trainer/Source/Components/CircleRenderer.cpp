#include "CircleRenderer.h"
#include "../Engine/Attribute.h"
#include <GL/glew.h>

using namespace std;

void CircleRenderer::DrawRing(float* ring)
{
}

void CircleRenderer::DrawInCircle(float* circle)
{
}

void CircleRenderer::DrawCircle(float* circle, float* ring, bool renderRing, Color color)
{
	if (renderRing)
		DrawRing(ring);
	DrawInCircle(circle);
}
#include "CircleRenderer.h"
#include "../Engine/Attribute.h"
#include <GL/glew.h>

using namespace std;

void CircleRenderer::DrawRing(float* ring)
{
	glBegin(GL_LINE_LOOP);
	for (int i = 2; i < ::DotCount + 2; i += 2)
	{
		glVertex2d(ring[i], ring[i + 1]);
	}
	glEnd();
}

void CircleRenderer::DrawInCircle(float* circle)
{
	glBegin(GL_LINE_LOOP);
	for (int i = 2; i < ::DotCount + 2; i += 2)
	{
		glVertex2d(circle[i], circle[i + 1]);
	}
	glEnd();
}

void CircleRenderer::DrawCircle(float* circle, float* ring, bool renderRing)
{
	if (renderRing)
		DrawRing(ring);
	DrawInCircle(circle);
}
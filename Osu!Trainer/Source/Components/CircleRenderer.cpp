#include "CircleRenderer.h"
#include "../Engine/Attribute.h"
#include <iostream>

using namespace std;
constexpr double PI = 3.14;

float CircleRenderer::objectRadius = 0;

CircleRenderer::CircleRenderer(float cx, float cy, float cRad) :
	x(cx), y(cy)
{
	objectRadius = cRad;
	vbl.Push<float>(2);

	// calculate the dots on the circle and the initial ring
	float angle = 0;
	float baseX = 0, baseY = 0;
	for (int i = 0; i <= ::DotCount; i++)
	{
		angle = 2 * PI * i / ::DotCount;
		baseX = objectRadius * cos(angle) * ::HeightDivWidth;
		baseY = objectRadius * sin(angle);

		circleDot.push_back(x + baseX);
		ringDot.push_back(x + baseX * 2);

		circleDot.push_back(y + baseY);
		ringDot.push_back(y + baseY * 2);
	}

	vbCircle = new VertexBuffer(circleDot.data(), sizeof(float) * circleDot.size(), GL_STATIC_DRAW);
	vbRing = new VertexBuffer(ringDot.data(), sizeof(float) * ringDot.size(), GL_STREAM_DRAW);

	vaCircle.AddBuffer(*vbCircle, vbl);
	vaRing.AddBuffer(*vbRing, vbl);

	vaCircle.Unbind();
	vaRing.Unbind();
}


// get the ringDot array at a certain time
float* CircleRenderer::GetRingDot(int time, int beatTime, int animationLength)
{
	// calculate the dots on the ring again, based on the timestamp
	float remaining = (abs((beatTime - time)) / (float)animationLength) + 1;

	float angle = 0;
	for (int i = 0; i < ringDot.size(); i += 2)
	{
		angle = 2 * PI * i / ::DotCount;

		ringDot[i] = x + objectRadius * cos(angle) * ::HeightDivWidth * remaining;
		ringDot[i + 1] = y + objectRadius * sin(angle) * remaining;
	}

	return ringDot.data();
}

void CircleRenderer::DrawCircleDep()
{
	vaCircle.Bind();
	glDrawArrays(GL_LINE_LOOP, 0, ::DotCount);
	vaCircle.Unbind();
}

void CircleRenderer::DrawRingDep(int time, int beatTime, int animationLength)
{
	vbRing->Update(GetRingDot(time, beatTime, animationLength), sizeof(float) * ringDot.size(), GL_STREAM_DRAW);
	vaRing.Bind();
	glDrawArrays(GL_LINE_LOOP, 0, ::DotCount);
	vaRing.Unbind();
}

CircleRenderer::~CircleRenderer()
{
	delete vbCircle;
	delete vbRing;
}
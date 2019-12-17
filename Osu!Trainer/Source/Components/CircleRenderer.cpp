#include "CircleRenderer.h"
#include "../Engine/Attribute.h"
#include <mutex>

using namespace std;
constexpr float PI = 3.1415;

once_flag flag1, flag2, flag3;

float CircleRenderer::radius = 0;
VertexBufferLayout CircleRenderer::vblBuf;
VertexBufferLayout CircleRenderer::vblFrag;

CircleRenderer::CircleRenderer(float cx, float cy, float cRad) :
	x(cx), y(cy)
{
	radius = cRad;
	call_once(flag1, []() { vblBuf.Push<float>(2); });

	/* deprecated buffer functions */
	// calculate the dots on the circle and the initial ring
	float angle = 0;
	float baseX = 0, baseY = 0;
	for (int i = 0; i <= ::DotCount; i++)
	{
		angle = 2 * PI * i / ::DotCount;
		baseX = radius * cos(angle);
		baseY = radius * sin(angle);

		circleDotBuf.push_back(x + baseX);
		ringDotBuf.push_back(x + baseX * 2);

		circleDotBuf.push_back(y + baseY);
		ringDotBuf.push_back(y + baseY * 2);
	}

	// create and bind the buffers
	vbCircleBuf = new VertexBuffer(circleDotBuf.data(), sizeof(float) * circleDotBuf.size(), GL_STATIC_DRAW);
	vbRingBuf = new VertexBuffer(ringDotBuf.data(), sizeof(float) * ringDotBuf.size(), GL_STREAM_DRAW);

	vaCircleBuf.AddBuffer(*vbCircleBuf, vblBuf);
	vaRingBuf.AddBuffer(*vbRingBuf, vblBuf);

	/* fragment shader vertices */
	call_once(flag2, []() { vblFrag.Push<float>(3); });
	call_once(flag3, []() { vblFrag.Push<float>(2); });

	// top, bottom, left, right
	float top = y + radius;
	float bottom = y - radius;
	float left = x - radius;
	float right = x + radius;
	// circle vertices and value array
	circleVerticesFrag.reserve(20);
	circleVerticesFrag = {
		right, bottom, 0, 1.0, -1.0,
		right, top, 0, 1.0, 1.0,
		left, top, 0, -1.0, 1.0,
		left, bottom, 0, -1.0, -1.0,
	};

	// ring vertices and boundaries array
	top += radius;
	bottom -= radius;
	left -= radius;
	right += radius;
	ringVerticesFrag.reserve(20);
	ringVerticesFrag = {
		// x, y, z, lx, ly
		// lx, ly are local fragment shader coordinate system
		right, bottom, 0, 1.0, -1.0,
		right, top, 0, 1.0, 1.0,
		left, top, 0, -1.0, 1.0,
		left, bottom, 0, -1.0, -1.0,
	};

	vbCircleFrag = new VertexBuffer(circleVerticesFrag.data(), sizeof(float) * circleVerticesFrag.size(), GL_STATIC_DRAW);
	vbRingFrag = new VertexBuffer(ringVerticesFrag.data(), sizeof(float) * circleVerticesFrag.size(), GL_STREAM_DRAW);

	vaCircleFrag.AddBuffer(*vbCircleFrag, vblFrag);
	vaRingFrag.AddBuffer(*vbRingFrag, vblFrag);
}

/* buffer drawing functions */
// get the ringDotBuf array at a certain time
float* CircleRenderer::GetRingDotBuf(int time, int beatTime, int animationLength)
{
	// calculate new dots on the ring, based on the timestamp
	float remaining = (abs((beatTime - time)) / (float)animationLength) + 1;

	float angle = 0;
	for (int i = 0; i < ringDotBuf.size(); i += 2)
	{
		angle = 2 * PI * i / ::DotCount;

		ringDotBuf[i] = x + radius * cos(angle) * remaining;
		ringDotBuf[i + 1] = y + radius * sin(angle) * remaining;
	}

	return ringDotBuf.data();
}

void CircleRenderer::DrawCircleBuf()
{
	vaCircleBuf.Bind();
	glDrawArrays(GL_LINE_LOOP, 0, ::DotCount);
}

void CircleRenderer::DrawRingBuf(int time, int beatTime, int animationLength)
{
	vbRingBuf->Update(GetRingDotBuf(time, beatTime, animationLength), sizeof(float) * ringDotBuf.size(), GL_STREAM_DRAW);
	vaRingBuf.Bind();
	glDrawArrays(GL_LINE_LOOP, 0, ::DotCount);
}

/* fragment drawing functions */
// calculate the boundaries of the ring at a certain time
float* CircleRenderer::GetRingVerticesFrag(int time, int beatTime, int animationLength)
{
	// calculate the new boundaries based on the timestamps
	float remaining = (abs((beatTime - time)) / (float)animationLength) + 1;

	float top = y + radius * remaining;
	float bottom = y - radius * remaining;
	float left = x - radius * remaining;
	float right = x + radius * remaining;
	ringVerticesFrag = {
		// x, y, z, lx, ly
		right, bottom, 0, 1.0, -1.0,
		right, top, 0, 1.0, 1.0,
		left, top, 0, -1.0, 1.0,
		left, bottom, 0, -1.0, -1.0,
	};
	return ringVerticesFrag.data();
}

void CircleRenderer::DrawCircleFrag()
{
	vaCircleFrag.Bind();
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
}

void CircleRenderer::DrawRingFrag(int time, int beatTime, int animationLength)
{
	vbRingFrag->Update(GetRingVerticesFrag(time, beatTime, animationLength), sizeof(float) * ringVerticesFrag.size(), GL_STREAM_DRAW);
	vaRingFrag.Bind();
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
}

CircleRenderer::~CircleRenderer()
{
	delete vbCircleBuf;
	delete vbRingBuf;
	delete vbCircleFrag;
	delete vbRingFrag;
}
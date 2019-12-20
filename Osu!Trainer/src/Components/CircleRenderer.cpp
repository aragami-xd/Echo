#include "CircleRenderer.h"
#include <Engine/Color.h>
#include <Engine/Attribute.h>
#include <mutex>

using namespace std;
constexpr float PI = 3.1415;

once_flag flag1, flag2, flag3;

VertexBufferLayout CircleRenderer::vblBuf;
VertexBufferLayout CircleRenderer::vblFrag;

CircleRenderer::CircleRenderer(Object* circle)
{
	object = circle;

	call_once(flag1, []() { vblBuf.Push<float>(2); });

	/* deprecated buffer functions */
	// calculate the dots on the circle and the initial ring
	float angle = 0;
	float baseX = 0, baseY = 0;
	for (int i = 0; i <= object::dotCount; i++)
	{
		angle = 2 * PI * i / object::dotCount;
		baseX = object->GetObjectRadius() * cos(angle);
		baseY = object->GetObjectRadius() * sin(angle);

		circleDotBuf.push_back(object->GetX() + baseX);
		ringDotBuf.push_back(object->GetX() + baseX * 2);

		circleDotBuf.push_back(object->GetY() + baseY);
		ringDotBuf.push_back(object->GetY() + baseY * 2);
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
	float top = object->GetY() + object->GetObjectRadius();
	float bottom = object->GetY() - object->GetObjectRadius();
	float left = object->GetX() - object->GetObjectRadius();
	float right = object->GetX() + object->GetObjectRadius();
	// circle vertices and value array
	circleVerticesFrag.reserve(20);
	circleVerticesFrag = {
		// x, y, z, lx, ly
		right, bottom, 0, 1.0, -1.0,
		right, top, 0, 1.0, 1.0,
		left, top, 0, -1.0, 1.0,
		left, bottom, 0, -1.0, -1.0,
	};

	// ring vertices and boundaries array
	top = object->GetY() - object::ringSizeScaling * object->GetObjectRadius();
	bottom = object->GetY() + object::ringSizeScaling * object->GetObjectRadius();
	left = object->GetX() - object::ringSizeScaling * object->GetObjectRadius();
	right = object->GetX() + object::ringSizeScaling * object->GetObjectRadius();
	ringVerticesFrag.reserve(20);
	ringVerticesFrag = {
		// x, y, z, lx, ly
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
float* CircleRenderer::GetRingDotBuf(int time)
{
	// calculate new dots on the ring, based on the timestamp
	float remaining = (abs((object->GetBeatTime() - time)) / (float)object->GetAnimationLength()) + 1;

	float angle = 0;
	for (int i = 0; i < ringDotBuf.size(); i += 2)
	{
		angle = 2 * PI * i / object::dotCount;

		ringDotBuf[i] = object->GetX() + object->GetObjectRadius() * cos(angle) * remaining;
		ringDotBuf[i + 1] = object->GetY() + object->GetObjectRadius() * sin(angle) * remaining;
	}

	return ringDotBuf.data();
}

// draw circle using buffer
void CircleRenderer::DrawCircleBuf()
{
	vaCircleBuf.Bind();
	glDrawArrays(GL_LINE_LOOP, 0, object::dotCount);
}
// draw approach circle (ring) using buffer
void CircleRenderer::DrawRingBuf(int time)
{
	vbRingBuf->Update(GetRingDotBuf(time), sizeof(float) * ringDotBuf.size(), GL_STREAM_DRAW);
	vaRingBuf.Bind();
	glDrawArrays(GL_LINE_LOOP, 0, object::dotCount);
}
// draw the object using buffer
void CircleRenderer::DrawBuf(int time, Shader* shader)
{
	shader->Bind();

	shader->SetUniform1f("borderThickness", object::circleBorderThickness);
	shader->SetUniformVec4f("color", COLOR_LIGHT_BLUE.rgba);
	DrawCircleBuf();

	shader->SetUniform1f("borderThickness", object::ringBorderThickness);
	shader->SetUniformVec4f("color", COLOR_WHITE.rgba);
	DrawRingBuf(time);
}

/* fragment drawing functions */
// calculate the boundaries of the ring at a certain time
float* CircleRenderer::GetRingVerticesFrag(int time)
{
	// calculate the new boundaries based on the timestamps
	float remaining = (abs((object->GetBeatTime() - time)) / (float)object->GetAnimationLength()) + 0.5;

	float top = object->GetY() - object::ringSizeScaling * object->GetObjectRadius() * remaining;
	float bottom = object->GetY() + object::ringSizeScaling * object->GetObjectRadius() * remaining;
	float left = object->GetX() - object::ringSizeScaling * object->GetObjectRadius() * remaining;
	float right = object->GetX() + object::ringSizeScaling * object->GetObjectRadius() * remaining;

	ringVerticesFrag = {
		// x, y, z, lx, ly
		right, bottom, 0, 1.0, -1.0,
		right, top, 0, 1.0, 1.0,
		left, top, 0, -1.0, 1.0,
		left, bottom, 0, -1.0, -1.0,
	};
	return ringVerticesFrag.data();
}
// draw circle using fragment shader
void CircleRenderer::DrawCircleFrag()
{
	vaCircleFrag.Bind();
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
}
// draw approach circle using fragment shader
void CircleRenderer::DrawRingFrag(int time)
{
	vbRingFrag->Update(GetRingVerticesFrag(time), sizeof(float) * ringVerticesFrag.size(), GL_STREAM_DRAW);
	vaRingFrag.Bind();
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
}
// draw the object
void CircleRenderer::DrawFrag(int time, Shader* shader)
{
	shader->Bind();

	shader->SetUniform1f("borderThickness", object::circleBorderThickness);
	shader->SetUniformVec4f("color", COLOR_LIGHT_BLUE.rgba);
	DrawCircleFrag();

	shader->SetUniform1f("borderThickness", object::ringBorderThickness);
	shader->SetUniformVec4f("color", COLOR_WHITE.rgba);
	DrawRingFrag(time);
}

CircleRenderer::~CircleRenderer()
{
	delete vbCircleBuf;
	delete vbRingBuf;
	delete vbCircleFrag;
	delete vbRingFrag;
}